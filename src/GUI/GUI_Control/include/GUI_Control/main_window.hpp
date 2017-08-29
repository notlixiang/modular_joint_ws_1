#ifndef GUI_Control_MAIN_WINDOW_H
#define GUI_Control_MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QWidget>
#include <QLineEdit>
#include <QLayout>
#include <QLabel>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <iostream>
#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QMessageBox>
#include <QFont>
#include <QDialog>

class Widget : public QWidget
{
        Q_OBJECT
public:
        Widget(int argc, char** argv, QWidget *parent = 0);
        ~Widget();
        QTreeWidget *tree;                                  //树控件
        std::vector<QTreeWidgetItem *> tree_joints;         //树控件的根--各个关节
        std::vector<QTreeWidgetItem *> joints_T;            //各个关节温度
        std::vector<QTreeWidgetItem *> joints_current;      //各个关节电流

        std::vector<QLabel *> pic_label;                    //指示灯label
        std::vector<QLabel *> joint_name_label;             //单关节控制的关节标签
        std::vector<QPushButton *> button_left;             //单关节控制按钮
        std::vector<QPushButton *> button_right;            //单关节控制按钮
        std::vector<QLineEdit *> lineEdit;                  //单关节控制显示框

        std::vector<QSlider *> speed_slider;                //单关节速度控制滑动条
        std::vector<QLabel *> speed_label;                  //单关节速度显示标签

        std::vector<QLabel *> tempture_label;               //单关节温度显示标签
        std::vector<QLabel *> current_label;                //单关节电流显示标签
        std::vector<QLineEdit *> tempture_lineEdit;         //单关节温度显示栏
        std::vector<QLineEdit *> current_lineEdit;          //单关节电流显示栏
        std::vector<QLabel *> zhan_wei_v;

        std::vector<QHBoxLayout *> middle_1_h_layout;
        std::vector<QHBoxLayout *> middle_2_h_layout;
        std::vector<QHBoxLayout *> middle_3_h_layout;

        QLabel *position_label[6];                          //位姿标签
        QLineEdit *position_lineEdit[6];                    //位姿显示框
        QPushButton *Cartesian_button[6];                   //笛卡尔速度控制按钮
        QHBoxLayout *right_H_layout[10];                    //右侧水平控件

        QTimer *Timer1;
        QTimer *Timer2;
public Q_SLOTS:
        void handle_speed_control_btn();
        void sensorData_update();
        void sliderValueChanged(int value);
        void clear_true();
private:
        CSpeedControl speed_control_qnode;
        CJointListen  joint_listen_node;
};


#endif
