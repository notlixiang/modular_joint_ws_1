/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *speed_p;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLineEdit *speed_i;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QLineEdit *speed_d;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_14;
    QLineEdit *position_p;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_15;
    QLineEdit *position_i;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_16;
    QLineEdit *position_d;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_17;
    QComboBox *fixed_id;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *can_id_current;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QLineEdit *can_id_desired;
    QPushButton *save_id;
    QCustomPlot *widget;
    QPushButton *test_current;
    QPushButton *data_display;
    QPushButton *write_speed;
    QPushButton *write_position;
    QPushButton *test_speed;
    QPushButton *test_position;
    QPushButton *debug_speed;
    QPushButton *debug_position;
    QPushButton *update;
    QPushButton *modify_id;
    QPushButton *test_position2;
    QMenuBar *menubar;
    QMenu *menu_File;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1208, 608);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(24, 119, 101, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label_7->setFont(font);

        verticalLayout_2->addWidget(label_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        speed_p = new QLineEdit(layoutWidget);
        speed_p->setObjectName(QString::fromUtf8("speed_p"));

        horizontalLayout_4->addWidget(speed_p);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        speed_i = new QLineEdit(layoutWidget);
        speed_i->setObjectName(QString::fromUtf8("speed_i"));

        horizontalLayout_7->addWidget(speed_i);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_8->addWidget(label_13);

        speed_d = new QLineEdit(layoutWidget);
        speed_d->setObjectName(QString::fromUtf8("speed_d"));

        horizontalLayout_8->addWidget(speed_d);


        verticalLayout_2->addLayout(horizontalLayout_8);

        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(141, 119, 101, 121));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_4->addWidget(label_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_9->addWidget(label_14);

        position_p = new QLineEdit(layoutWidget1);
        position_p->setObjectName(QString::fromUtf8("position_p"));

        horizontalLayout_9->addWidget(position_p);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_10->addWidget(label_15);

        position_i = new QLineEdit(layoutWidget1);
        position_i->setObjectName(QString::fromUtf8("position_i"));

        horizontalLayout_10->addWidget(position_i);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_11->addWidget(label_16);

        position_d = new QLineEdit(layoutWidget1);
        position_d->setObjectName(QString::fromUtf8("position_d"));

        horizontalLayout_11->addWidget(position_d);


        verticalLayout_4->addLayout(horizontalLayout_11);

        layoutWidget2 = new QWidget(groupBox_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(23, 10, 221, 96));
        verticalLayout_5 = new QVBoxLayout(layoutWidget2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setFont(font);

        horizontalLayout->addWidget(label_17);

        fixed_id = new QComboBox(layoutWidget2);
        fixed_id->setObjectName(QString::fromUtf8("fixed_id"));

        horizontalLayout->addWidget(fixed_id);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        can_id_current = new QLineEdit(layoutWidget2);
        can_id_current->setObjectName(QString::fromUtf8("can_id_current"));
        can_id_current->setReadOnly(true);

        horizontalLayout_2->addWidget(can_id_current);


        verticalLayout_5->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_3->addWidget(label_6);

        can_id_desired = new QLineEdit(layoutWidget2);
        can_id_desired->setObjectName(QString::fromUtf8("can_id_desired"));

        horizontalLayout_3->addWidget(can_id_desired);


        verticalLayout_5->addLayout(horizontalLayout_3);

        save_id = new QPushButton(groupBox_2);
        save_id->setObjectName(QString::fromUtf8("save_id"));
        save_id->setGeometry(QRect(140, 460, 111, 27));
        widget = new QCustomPlot(groupBox_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(280, 10, 911, 531));
        test_current = new QPushButton(groupBox_2);
        test_current->setObjectName(QString::fromUtf8("test_current"));
        test_current->setGeometry(QRect(20, 420, 111, 27));
        data_display = new QPushButton(groupBox_2);
        data_display->setObjectName(QString::fromUtf8("data_display"));
        data_display->setGeometry(QRect(140, 420, 111, 27));
        write_speed = new QPushButton(groupBox_2);
        write_speed->setObjectName(QString::fromUtf8("write_speed"));
        write_speed->setGeometry(QRect(20, 380, 111, 27));
        write_position = new QPushButton(groupBox_2);
        write_position->setObjectName(QString::fromUtf8("write_position"));
        write_position->setGeometry(QRect(140, 380, 111, 27));
        test_speed = new QPushButton(groupBox_2);
        test_speed->setObjectName(QString::fromUtf8("test_speed"));
        test_speed->setGeometry(QRect(20, 340, 111, 25));
        test_position = new QPushButton(groupBox_2);
        test_position->setObjectName(QString::fromUtf8("test_position"));
        test_position->setGeometry(QRect(140, 340, 111, 27));
        debug_speed = new QPushButton(groupBox_2);
        debug_speed->setObjectName(QString::fromUtf8("debug_speed"));
        debug_speed->setGeometry(QRect(20, 300, 111, 27));
        debug_position = new QPushButton(groupBox_2);
        debug_position->setObjectName(QString::fromUtf8("debug_position"));
        debug_position->setGeometry(QRect(140, 300, 111, 27));
        update = new QPushButton(groupBox_2);
        update->setObjectName(QString::fromUtf8("update"));
        update->setGeometry(QRect(20, 260, 111, 27));
        modify_id = new QPushButton(groupBox_2);
        modify_id->setObjectName(QString::fromUtf8("modify_id"));
        modify_id->setGeometry(QRect(140, 260, 111, 27));
        test_position2 = new QPushButton(groupBox_2);
        test_position2->setObjectName(QString::fromUtf8("test_position2"));
        test_position2->setGeometry(QRect(20, 460, 111, 27));

        hboxLayout->addWidget(groupBox_2);

        MainWindowDesign->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowDesign);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1208, 24));
        menu_File = new QMenu(menubar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindowDesign->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowDesign);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindowDesign->setStatusBar(statusbar);

        menubar->addAction(menu_File->menuAction());
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionAbout);
        menu_File->addAction(actionAbout_Qt);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindowDesign", "Speed_PID", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowDesign", "P", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindowDesign", " I", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindowDesign", "D", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindowDesign", "Position_PID", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindowDesign", "P", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindowDesign", " I", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindowDesign", "D", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindowDesign", "Fixed ID", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowDesign", "CAN ID Current", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowDesign", "CAN ID Desired", 0, QApplication::UnicodeUTF8));
        save_id->setText(QApplication::translate("MainWindowDesign", "Save ID", 0, QApplication::UnicodeUTF8));
        test_current->setText(QApplication::translate("MainWindowDesign", "Current Test", 0, QApplication::UnicodeUTF8));
        data_display->setText(QApplication::translate("MainWindowDesign", "Data Display", 0, QApplication::UnicodeUTF8));
        write_speed->setText(QApplication::translate("MainWindowDesign", "Write Speed", 0, QApplication::UnicodeUTF8));
        write_position->setText(QApplication::translate("MainWindowDesign", "Write Position", 0, QApplication::UnicodeUTF8));
        test_speed->setText(QApplication::translate("MainWindowDesign", "Speed Test", 0, QApplication::UnicodeUTF8));
        test_position->setText(QApplication::translate("MainWindowDesign", "Position Test", 0, QApplication::UnicodeUTF8));
        debug_speed->setText(QApplication::translate("MainWindowDesign", "DeBug Speed", 0, QApplication::UnicodeUTF8));
        debug_position->setText(QApplication::translate("MainWindowDesign", "DeBug Position", 0, QApplication::UnicodeUTF8));
        update->setText(QApplication::translate("MainWindowDesign", "Fixed ID Update", 0, QApplication::UnicodeUTF8));
        modify_id->setText(QApplication::translate("MainWindowDesign", "Modify ID", 0, QApplication::UnicodeUTF8));
        test_position2->setText(QApplication::translate("MainWindowDesign", "Position Test2", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindowDesign", "&App", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
