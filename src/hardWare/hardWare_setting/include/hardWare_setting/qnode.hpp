#ifndef hardWare_setting_QNODE_HPP_
#define hardWare_setting_QNODE_HPP_
#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include "../../../../../devel/include/robot_msgs/DownToUp.h"
#include "../../../../../devel/include/robot_msgs/UpToDown.h"
namespace hardWare_setting {
class CDownToUp_Listen : public QThread {
    Q_OBJECT
public:
        CDownToUp_Listen(int argc, char** argv );
        virtual ~CDownToUp_Listen();
	bool init();
	void run();
Q_SIGNALS:
        void rosShutdown();
private:
	int init_argc;
	char** init_argv;
        ros::Subscriber sub_down_to_up;
};
class CUpToDown : public QThread {
    Q_OBJECT
public:
        CUpToDown(int argc, char** argv );
        virtual ~CUpToDown();
        bool init();
        void run();
Q_SIGNALS:
        void rosShutdown();
private:
        int init_argc;
        char** init_argv;
        ros::Publisher pub_up_to_down;
        robot_msgs::UpToDown msg_up_to_down;
};
}
#endif
