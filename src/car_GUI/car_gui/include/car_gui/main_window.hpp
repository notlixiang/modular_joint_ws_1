#ifndef car_gui_MAIN_WINDOW_H
#define car_gui_MAIN_WINDOW_H

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

namespace car_gui {

class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();
        QTimer *Timer1;

public Q_SLOTS:
        void handle_speed_value_changed();
        void clear_true();
        void handle_forward_btn();
        void handle_back_btn();
        void handle_left_btn();
        void handle_right_btn();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}

#endif
