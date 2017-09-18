#ifndef car_gui_QNODE_HPP_
#define car_gui_QNODE_HPP_

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include "../../../../../devel/include/robot_msgs/UpToDown.h"

namespace car_gui {

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
        void run();

Q_SIGNALS:
        void rosShutdown();

private:
	int init_argc;
	char** init_argv;
        ros::Publisher pub_speed_control;
        robot_msgs::UpToDown speed_msg;
};
}

#endif
