#include <QtGui>
#include <QApplication>
#include "../include/GUI_Control/main_window.hpp"

int main(int argc, char **argv) {

    QApplication app(argc, argv);
    Widget w(argc,argv);
    w.setWindowState(Qt::WindowMaximized);
    w.show();
    app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
    int result = app.exec();

	return result;
}
