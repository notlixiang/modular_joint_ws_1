#ifndef ros_driver_QNODE_HPP_
#define ros_driver_QNODE_HPP_
#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <actionlib/server/simple_action_server.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <vector>
#include <sensor_msgs/JointState.h>
#include "../../../../../devel/include/robot_msgs/DownToUp.h"
#include "../../../../../devel/include/robot_msgs/UpToDown.h"
#include <trajectory_msgs/JointTrajectory.h>
class CFollowJointTrajectoryAction : public QThread {
    Q_OBJECT
public:
        CFollowJointTrajectoryAction(int argc, char** argv );
        ~CFollowJointTrajectoryAction();
        ros::NodeHandle nh_;
        actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> as_;
        control_msgs::FollowJointTrajectoryResult result_;
        void executeCB(const control_msgs::FollowJointTrajectoryGoalConstPtr &goal);
private:
        int init_argc;
        char **init_argv;
        ros::Publisher pub_up_to_down;
        robot_msgs::UpToDown msg_up_to_down;
};
class CJointPublisher : public QThread {
    Q_OBJECT
public:
        CJointPublisher(int argc, char** argv );
        ~CJointPublisher();
        void run();
        ros::Publisher joint_pub;
        sensor_msgs::JointState joint_state;
private:
        int init_argc;
        char **init_argv;
};
class CDownToUp : public QThread {
    Q_OBJECT
public:
        CDownToUp(int argc, char** argv );
        virtual ~CDownToUp();
        bool init();
private:
        int init_argc;
        char** init_argv;
        ros::Subscriber sub_down_to_up;
};
#endif
