#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include <QFile>
#include <QTextStream>
#include "../include/hardWare_setting/main_window.hpp"
#include "../include/hardWare_setting/main_window.hpp"
#include <QFile>
#include <QTextStream>
std::vector<float> Fixed_ID;                //固定ID
std::vector<int>    CAN_ID;                 //CAN ID

std::vector<float> speed_pid_p;
std::vector<float> speed_pid_i;
std::vector<float> speed_pid_d;
std::vector<float> position_pid_p;
std::vector<float> position_pid_i;
std::vector<float> position_pid_d;

//判断对应按键是否按下
bool key_modify_id      = false;
bool key_debug_speed    = false;
bool key_debug_position = false;
bool key_write_speed    = false;
bool key_write_position = false;
bool key_test_speed     = false;
bool key_test_position  = false;
bool key_test_current   = false;
bool key_data_display   = false;
bool key_test_position2 = false;

int global_index = -1;                      //固定ID的下拉列表选择序号
int CAN_ID_modify;                          //CAN ID修改的值
//速度和位置PID修改的值
float speed_pid_p_modify,speed_pid_i_modify,speed_pid_d_modify,position_pid_p_modify,position_pid_i_modify,position_pid_d_modify;
double speed_draw,position_draw,current_draw;//速度和位置的绘图变量
int draw_time = 0;                          //绘图与时间轴相关的变量
QVector<double> x_draw(6000);               //绘图的x变量
QVector<double> y_draw(6000);               //绘图的y变量
QVector<double> y_current_draw(6000); 
QVector<double> y_speed_draw(6000);
QVector<double> y_position_draw(6000);
QVector<double> x_time_draw(6000);
int time_count = 0;


float A = 1;//0.5;                                //位置控制参数
int   num = 1;
float w = 3.1415926 / 3;

float A_square = 1;
int num_square = 2;


namespace hardWare_setting {
using namespace Qt;
MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
    , down_to_up_listen_node(argc,argv)
    , up_to_down_node(argc,argv)
{
    ui.setupUi(this);
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
	setWindowIcon(QIcon(":/images/icon.png"));
    QObject::connect(&down_to_up_listen_node, SIGNAL(rosShutdown()), this, SLOT(close()));
    QObject::connect(ui.update, SIGNAL(clicked()), this, SLOT(handle_btn_update()));
    QObject::connect(ui.modify_id, SIGNAL(clicked()), this, SLOT(handle_btn_modify_id()));
    QObject::connect(ui.debug_speed, SIGNAL(clicked()), this, SLOT(handle_btn_debug_speed()));
    QObject::connect(ui.debug_position, SIGNAL(clicked()), this, SLOT(handle_btn_debug_position()));
    QObject::connect(ui.write_speed, SIGNAL(clicked()), this, SLOT(handle_btn_write_speed()));
    QObject::connect(ui.write_position, SIGNAL(clicked()), this, SLOT(handle_btn_write_position()));
    QObject::connect(ui.fixed_id, SIGNAL(currentIndexChanged(int)), this, SLOT(handle_combo_changed()));
    QObject::connect(ui.save_id, SIGNAL(clicked()), this, SLOT(handle_btn_save_id()));
    QObject::connect(ui.test_position, SIGNAL(clicked()), this, SLOT(handle_btn_test_position()));
    QObject::connect(ui.test_speed, SIGNAL(clicked()), this, SLOT(handle_btn_test_speed()));
    QObject::connect(ui.test_current, SIGNAL(clicked()), this, SLOT(handle_btn_test_current()));
    QObject::connect(ui.data_display, SIGNAL(clicked()), this, SLOT(handle_btn_data_display()));
    QObject::connect(ui.test_position2, SIGNAL(clicked()), this, SLOT(handle_btn_test_position2()));
    down_to_up_listen_node.init();
    up_to_down_node.init();

    timer1 = new QTimer(this);
    QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(handle_time1_out()));
    timer1->start(5);

    ui.widget->addGraph();
    ui.widget->addGraph();
	ui.widget->addGraph();
    ui.widget->addGraph();
}

MainWindow::~MainWindow() {}
void MainWindow::handle_time1_out()
{
    if(key_test_speed)                                      //速度PID绘图
    {
        y_draw[draw_time] = speed_draw;                 
		y_current_draw[draw_time] = current_draw*0.1;
        x_draw[draw_time] = 5 * draw_time;                  //每隔5ms绘制一个点
		y_position_draw[draw_time] = position_draw;
        draw_time++;
        ui.widget->graph(0)->setData(x_draw, y_draw);
		ui.widget->graph(0)->setPen(QPen(Qt::blue));
		ui.widget->graph(1)->setData(x_draw, y_current_draw);
		ui.widget->graph(1)->setPen(QPen(Qt::red));
        ui.widget->xAxis->setLabel("t/ms");
        //ui.widget->yAxis->setLabel("Speed rad/s");
        ui.widget->xAxis->setRange(0, 5300);                //x轴范围
        ui.widget->yAxis->setRange(-1,1);              //y轴范围
        ui.widget->replot();

			if(draw_time == 980)
			{
				QFile f1("/home/null/data_mj/position.txt");
				QFile f2("/home/null/data_mj/speed.txt");
				QFile f3("/home/null/data_mj/current.txt");
				if(!f1.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				if(!f2.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				if(!f3.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				QTextStream txtOutput1(&f1);
				QTextStream txtOutput3(&f3);
				QTextStream txtOutput2(&f2);
				txtOutput1.setRealNumberPrecision(12);
				txtOutput2.setRealNumberPrecision(12);
				txtOutput3.setRealNumberPrecision(12);
				for(int i=0; i<y_position_draw.size(); i++)
				{
					txtOutput1<<y_position_draw[i]<<endl;
				}
				for(int i=0; i<y_draw.size(); i++)
				{
					txtOutput2<<y_draw[i]<<endl;
				}
				for(int i=0; i<y_current_draw.size(); i++)
				{
					txtOutput3<<y_current_draw[i]<<endl;
				}
				f1.close();
				f2.close();
				f3.close();
			}
    }
    else if(key_test_position)                              //位置PID绘图
    {
        y_position_draw[draw_time] = position_draw;
        y_current_draw[draw_time] = current_draw*0.1;
        y_speed_draw[draw_time] = speed_draw*0.1;
        x_time_draw[draw_time] = 5 * draw_time;
        draw_time++;
        ui.widget->graph(1)->setData(x_time_draw, y_position_draw);
        ui.widget->graph(1)->setPen(QPen(Qt::green));
        ui.widget->graph(2)->setData(x_time_draw, y_speed_draw);
        ui.widget->graph(2)->setPen(QPen(Qt::blue));
        ui.widget->graph(3)->setData(x_time_draw, y_current_draw);
        ui.widget->graph(3)->setPen(QPen(Qt::red));
        ui.widget->replot();
    }
    else if(key_test_position2)
    {
        y_position_draw[draw_time] = position_draw;
        y_current_draw[draw_time] = current_draw*1;
        y_speed_draw[draw_time] = speed_draw*0.05;
        x_time_draw[draw_time] = 5 * draw_time;
        draw_time++;
        ui.widget->graph(1)->setData(x_time_draw, y_position_draw);
        ui.widget->graph(1)->setPen(QPen(Qt::green));
        ui.widget->graph(2)->setData(x_time_draw, y_speed_draw);
        ui.widget->graph(2)->setPen(QPen(Qt::blue));
        ui.widget->graph(3)->setData(x_time_draw, y_current_draw);
        ui.widget->graph(3)->setPen(QPen(Qt::red));
        ui.widget->replot();

			if(draw_time == 2300)
			{
				QFile f1("/home/null/data_mj/position.txt");
				QFile f2("/home/null/data_mj/speed.txt");
				QFile f3("/home/null/data_mj/current.txt");

				if(!f1.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				if(!f2.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				if(!f3.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				QTextStream txtOutput1(&f1);
				QTextStream txtOutput3(&f3);
				QTextStream txtOutput2(&f2);
				txtOutput1.setRealNumberPrecision(12);
				txtOutput2.setRealNumberPrecision(12);
				txtOutput3.setRealNumberPrecision(12);
				for(int i=0; i<y_position_draw.size(); i++)
				{
					txtOutput1<<y_position_draw[i]<<endl;
				}
				for(int i=0; i<y_speed_draw.size(); i++)
				{
					txtOutput2<<y_speed_draw[i]<<endl;
				}
				for(int i=0; i<y_current_draw.size(); i++)
				{
					txtOutput3<<y_current_draw[i]<<endl;
				}
				f1.close();
				f2.close();
				f3.close();
			}
    }
    else if(key_test_current)
    {
        x_draw[draw_time] = 5 * draw_time;
        y_draw[draw_time] = current_draw*1;
		y_speed_draw[draw_time] = speed_draw*1;
        draw_time++;
        ui.widget->graph(0)->setData(x_draw, y_draw);
		ui.widget->graph(0)->setPen(QPen(Qt::red));
		ui.widget->graph(1)->setData(x_draw, y_speed_draw);
        ui.widget->graph(1)->setPen(QPen(Qt::blue));

        ui.widget->xAxis->setLabel("t/ms");
        ui.widget->yAxis->setLabel("Current/A");
        ui.widget->xAxis->setRange(0, 5300);
        ui.widget->yAxis->setRange(-1, 1 );
        ui.widget->replot();
    }
    else if(key_data_display)
    {
        if(draw_time <= 1000)
        {
            x_time_draw[draw_time] = 5 * draw_time;
            y_position_draw[draw_time] = position_draw*1;
            y_current_draw[draw_time] = current_draw*10;
            y_speed_draw[draw_time] = speed_draw*(double)0.05;
            draw_time++;
            ui.widget->graph(0)->setData(x_time_draw, y_position_draw);
            ui.widget->graph(0)->setPen(QPen(Qt::green));
            ui.widget->graph(1)->setData(x_time_draw, y_speed_draw);
            ui.widget->graph(1)->setPen(QPen(Qt::blue));
            ui.widget->graph(2)->setData(x_time_draw, y_current_draw);
            ui.widget->graph(2)->setPen(QPen(Qt::red));
			ui.widget->xAxis->setLabel("t/ms");
        	ui.widget->xAxis->setRange(0, 5300);
        	ui.widget->yAxis->setRange(-1, 1 );
        	ui.widget->replot();
			if(draw_time == 1000)
			{
				QFile f1("/home/null/data_mj/position.txt");
				QFile f2("/home/null/data_mj/speed.txt");

				if(!f1.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				if(!f2.open(QIODevice::WriteOnly | QIODevice::Text))
				{
					std::cout<<"open txt file failed"<<std::endl;
				}
				QTextStream txtOutput1(&f1);

				QTextStream txtOutput2(&f2);
                txtOutput1.setRealNumberPrecision(12);
                txtOutput2.setRealNumberPrecision(12);
				for(int i=0; i<y_position_draw.size(); i++)
				{
					txtOutput1<<y_position_draw[i]<<endl;
				}
				for(int i=0; i<y_speed_draw.size(); i++)
				{
					txtOutput2<<y_speed_draw[i]<<endl;
				}
				f1.close();
				f2.close();
			}
        }
        else
        {
            key_data_display = false;
        }
    }
}

void MainWindow::handle_btn_update()
{
    ui.fixed_id->clear();
    QString str;
    for(int i=0; i<Fixed_ID.size(); i++)
    {
        ui.fixed_id->addItem(str.setNum(Fixed_ID[i]));
    }
}
void MainWindow::handle_btn_modify_id()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        QString str = ui.can_id_desired->text();
        CAN_ID_modify = str.toInt();
        key_modify_id = true;
    }
}
void MainWindow::handle_btn_debug_position()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        QString str = ui.position_p->text();
        position_pid_p_modify = str.toDouble();
        str = ui.position_i->text();
        position_pid_i_modify = str.toDouble();
        str = ui.position_d->text();
        position_pid_d_modify = str.toDouble();
        key_debug_position = true;
    }
}
void MainWindow::handle_btn_debug_speed()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        QString str = ui.speed_p->text();
        speed_pid_p_modify = str.toDouble();
        str = ui.speed_i->text();
        speed_pid_i_modify = str.toDouble();
        str = ui.speed_d->text();
        speed_pid_d_modify = str.toDouble();
        key_debug_speed = true;
    }
}
void MainWindow::handle_btn_test_speed()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        x_draw.clear();
        y_draw.clear();
        x_draw.resize(6000);
        y_draw.resize(6000);
        y_position_draw.clear();
        y_position_draw.resize(6000);
        y_current_draw.clear();
        y_current_draw.resize(6000);
        y_speed_draw.clear();
        y_speed_draw.resize(6000);
        x_time_draw.clear();
        x_time_draw.resize(6000);
        ui.widget->graph(0)->clearData();
        ui.widget->graph(1)->clearData();
        ui.widget->graph(2)->clearData();
        ui.widget->graph(3)->clearData();
        ui.widget->replot();
        draw_time = 0;
        key_test_speed = true;
    }
}
void MainWindow::handle_btn_test_current()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        x_draw.clear();
        y_draw.clear();
        x_draw.resize(6000);
        y_draw.resize(6000);
        y_position_draw.clear();
        y_position_draw.resize(6000);
        y_current_draw.clear();
        y_current_draw.resize(6000);
        y_speed_draw.clear();
        y_speed_draw.resize(6000);
        x_time_draw.clear();
        x_time_draw.resize(6000);
        ui.widget->graph(0)->clearData();
        ui.widget->graph(1)->clearData();
        ui.widget->graph(2)->clearData();
        ui.widget->graph(3)->clearData();
        ui.widget->replot();
        draw_time = 0;
        key_test_current = true;
    }
}
void MainWindow::handle_btn_test_position()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        x_draw.clear();
        y_draw.clear();
        x_draw.resize(12010);
        y_draw.resize(12010);
        y_position_draw.clear();
        y_position_draw.resize(3000);
        y_current_draw.clear();
        y_current_draw.resize(3000);
        y_speed_draw.clear();
        y_speed_draw.resize(3000);
        x_time_draw.clear();
        x_time_draw.resize(3000);
        ui.widget->graph(0)->clearData();
        ui.widget->graph(1)->clearData();
        ui.widget->graph(2)->clearData();
        ui.widget->graph(3)->clearData();
        for(int i=0; i<12000; i++)
        {
            x_draw[i] = i;
            float t = (float)i / 1000;
            y_draw[i] = A*sin(w*t);
        }
        ui.widget->xAxis->setLabel("t/ms");
        ui.widget->graph(0)->setData(x_draw, y_draw);
		ui.widget->graph(0)->setPen(QPen(Qt::black));
        ui.widget->xAxis->setRange(0, 12000);                //x轴范围
        ui.widget->yAxis->setRange(-1.2 * A, 1.2 * A);                   //y轴范围
        ui.widget->replot();
        draw_time = 0;
        key_test_position = true;
    }
}
void MainWindow::handle_btn_test_position2()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        x_draw.clear();
        y_draw.clear();
        x_draw.resize(12010);
        y_draw.resize(12010);
        y_position_draw.clear();
        y_position_draw.resize(5000);
        y_current_draw.clear();
        y_current_draw.resize(5000);
        y_speed_draw.clear();
        y_speed_draw.resize(5000);
        x_time_draw.clear();
        x_time_draw.resize(5000);
        ui.widget->graph(0)->clearData();
        ui.widget->graph(1)->clearData();
        ui.widget->graph(2)->clearData();
        ui.widget->graph(3)->clearData();
        for(int j=0; j<num_square; j++)
        {
            for(int i=j*(12000/num_square); i<j*(12000/num_square)+(6000/num_square); i++)
            {
                x_draw[i] = i;
                y_draw[i] = A_square;
            }
            for(int i=j*(12000/num_square)+(6000/num_square); i<j*(12000/num_square)+2*(6000/num_square); i++)
            {
                x_draw[i] = i;
                y_draw[i] = A_square;
            }
        }
        ui.widget->xAxis->setLabel("t/ms");
        ui.widget->graph(0)->setData(x_draw, y_draw);
		ui.widget->graph(0)->setPen(QPen(Qt::black));
        ui.widget->xAxis->setRange(0, 12000);                            //x轴范围
        ui.widget->yAxis->setRange(-3 * A_square, 3 * A_square);                   //y轴范围
        ui.widget->replot();
        draw_time = 0;
        key_test_position2 = true;
    }
}
void MainWindow::handle_btn_data_display()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        x_draw.clear();
        y_draw.clear();
        y_position_draw.clear();
        y_position_draw.resize(1010);
        y_current_draw.clear();
        y_current_draw.resize(1010);
        y_speed_draw.clear();
        y_speed_draw.resize(1010);
        x_time_draw.clear();
        x_time_draw.resize(1010);
        ui.widget->graph(0)->clearData();
        ui.widget->graph(1)->clearData();
        ui.widget->graph(2)->clearData();
        ui.widget->graph(3)->clearData();
        ui.widget->replot();
        draw_time = 0;
        key_data_display = true;
    }
}
void MainWindow::handle_btn_write_position()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        QString str = ui.position_p->text();
        position_pid_p_modify = str.toDouble();
        str = ui.position_i->text();
        position_pid_i_modify = str.toDouble();
        str = ui.position_d->text();
        position_pid_d_modify = str.toDouble();
        key_write_position = true;
    }
}
void MainWindow::handle_btn_write_speed()
{
    if(global_index == -1)
    {
        QMessageBox::information(this,"Notice","select a Fixed ID first!");
    }
    else
    {
        QString str = ui.speed_p->text();
        speed_pid_p_modify = str.toDouble();
        str = ui.speed_i->text();
        speed_pid_i_modify = str.toDouble();
        str = ui.speed_d->text();
        speed_pid_d_modify = str.toDouble();
        key_write_speed = true;
    }
}
void MainWindow::handle_combo_changed()
{
    QString str;
    int index = ui.fixed_id->currentIndex();
    global_index = index;
    ui.can_id_current->setText(str.setNum(CAN_ID[index]));
    ui.speed_p->setText(str.setNum(speed_pid_p[index]));
    ui.speed_i->setText(str.setNum(speed_pid_i[index]));
    ui.speed_d->setText(str.setNum(speed_pid_d[index]));
    ui.position_p->setText(str.setNum(position_pid_p[index]));
    ui.position_i->setText(str.setNum(position_pid_i[index]));
    ui.position_d->setText(str.setNum(position_pid_d[index]));
}
void MainWindow::handle_btn_save_id()
{
    bool key_write = true;
    int can_id_1,can_id_2;
    if(CAN_ID.size()>1)
    {
        for(int i=0; i<CAN_ID.size()-1; i++)
        {
            can_id_1 = CAN_ID[i];
            for(int j=i+1; j<CAN_ID.size(); j++)
            {
                can_id_2 = CAN_ID[j];
                if(can_id_1 == can_id_2)
                {
                    QMessageBox::critical(this, "ERROR", "There is the same ID!");
                    key_write = false;
                    break;
                }
            }
        }
    }
    if(key_write)
    {
        QFile f("/home/null/ws_ythgj_1/src/ID_List.txt");
        if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
        {
             ROS_ERROR("Open ID_List.txt Failed !");
        }
        QTextStream txtOutput(&f);
        for(int i=0; i<CAN_ID.size(); i++)
        {
            txtOutput << CAN_ID[i] << endl;
            txtOutput << Fixed_ID[i] << endl;
        }
        f.close();
    }
}
}

