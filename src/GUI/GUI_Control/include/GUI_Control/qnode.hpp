#ifndef GUI_Control_QNODE_HPP_
#define GUI_Control_QNODE_HPP_

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <trajectory_msgs/JointTrajectory.h>
#include <sensor_msgs/JointState.h>
#include "../../../../../devel/include/robot_msgs/UpToDown.h"
#include "../../../../../devel/include/robot_msgs/DownToUp.h"

class CSpeedControl : public QThread {
    Q_OBJECT
public:
        CSpeedControl(int argc, char** argv );
        virtual ~CSpeedControl();
        bool init();
        void run();
Q_SIGNALS:
        void rosShutdown();
private:
        int init_argc;
        char** init_argv;
        ros::Publisher pub_speed_control;
        trajectory_msgs::JointTrajectory speed_states;
};

class CJointListen : public QThread {
    Q_OBJECT
public:
        CJointListen(int argc, char** argv );
        virtual ~CJointListen();
        bool init();
        void run();
Q_SIGNALS:
        void rosShutdown();
private:
        int init_argc;
        char** init_argv;
        ros::Subscriber sub_joint_position;
        ros::Subscriber sub_down_to_up;
};

#endif /* GUI_Control_QNODE_HPP_ */
