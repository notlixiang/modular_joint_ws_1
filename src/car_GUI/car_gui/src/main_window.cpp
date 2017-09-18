#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/car_gui/main_window.hpp"
double max_speed = 1;
double current_speed;
bool key_forward = false;
bool key_back = false;
bool key_left = false;
bool key_right = false;

namespace car_gui {

using namespace Qt;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
    ui.setupUi(this);

	setWindowIcon(QIcon(":/images/icon.png"));
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

    ui.speed_slider->setMinimum(0);
    ui.speed_slider->setMaximum(100);
    ui.speed_slider->setValue(70);
    current_speed = max_speed * 0.7;
    QObject::connect(ui.speed_slider, SIGNAL(valueChanged(int)), this, SLOT(handle_speed_value_changed()));
    QObject::connect(ui.forward_btn, SIGNAL(clicked()), this, SLOT(handle_forward_btn()));
    QObject::connect(ui.back_btn, SIGNAL(clicked()), this, SLOT(handle_back_btn()));
    QObject::connect(ui.left_btn, SIGNAL(clicked()), this, SLOT(handle_left_btn()));
    QObject::connect(ui.right_btn, SIGNAL(clicked()), this, SLOT(handle_right_btn()));

    Timer1 = new QTimer(this);
    QObject::connect(Timer1,SIGNAL(timeout()), this, SLOT(clear_true()) );
    Timer1->start(15);

    qnode.init();
}

MainWindow::~MainWindow() {}

void MainWindow::handle_speed_value_changed()
{
    double i = (double)ui.speed_slider->value();
    current_speed = max_speed * (i/100);
}

void MainWindow::clear_true()
{
    key_forward = false;
    key_back = false;
    key_left = false;
    key_right = false;
}

void MainWindow::handle_forward_btn()
{
    key_forward = true;
}

void MainWindow::handle_back_btn()
{
    key_back = true;
}

void MainWindow::handle_left_btn()
{
    key_left = true;
}

void MainWindow::handle_right_btn()
{
    key_right = true;
}


}

