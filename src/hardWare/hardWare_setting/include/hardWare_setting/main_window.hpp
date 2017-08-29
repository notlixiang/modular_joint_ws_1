#ifndef hardWare_setting_MAIN_WINDOW_H
#define hardWare_setting_MAIN_WINDOW_H
#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include <QTimer>
namespace hardWare_setting {
class MainWindow : public QMainWindow {
Q_OBJECT
public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();
        QTimer *timer1;
public Q_SLOTS:
        void handle_btn_update();
        void handle_btn_modify_id();
        void handle_btn_debug_speed();
        void handle_btn_write_speed();
        void handle_btn_debug_position();
        void handle_btn_write_position();
        void handle_combo_changed();
        void handle_btn_save_id();
        void handle_time1_out();
        void handle_btn_test_speed();
        void handle_btn_test_position();
        void handle_btn_test_position2();
        void handle_btn_test_current();
        void handle_btn_data_display();
private:
	Ui::MainWindowDesign ui;
        CDownToUp_Listen down_to_up_listen_node;
        CUpToDown up_to_down_node;
};
}
#endif
