#include <iostream>
#include <ros/ros.h>
#include "../include/ros_driver/qnode.hpp"
#include <QProcess>
#include <QTextStream>
#include <QFile>
#include <vector>
#include <QMessageBox>
#include <QTimer>
#include <QObject>
#include <QThread>
#include <QApplication>
std::vector<int> ID;

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
class CDriver
{
public:
    CDriver(int argc, char** argv);
    CFollowJointTrajectoryAction follow_joint_trajectory;
    CJointPublisher joint_publisher;
    CDownToUp down_to_up_node;
};

class CSpeedControlListen : public QThread {
public:
        CSpeedControlListen(int argc, char** argv );
        virtual ~CSpeedControlListen();
        void Callback1(trajectory_msgs::JointTrajectory  msg);
        robot_msgs::UpToDown msg_up_to_down;
        ros::Subscriber sub_speed_control_listen;
        ros::Publisher   pub_up_to_down;
private:
        int init_argc;
        char** init_argv;
};

CDriver::CDriver(int argc, char **argv) :
    follow_joint_trajectory(argc,argv),
    joint_publisher(argc,argv),
    down_to_up_node(argc,argv)
{}

CSpeedControlListen::CSpeedControlListen(int argc, char** argv ) : init_argc(argc), init_argv(argv) {}
CSpeedControlListen::~CSpeedControlListen() {}
void CSpeedControlListen::Callback1(trajectory_msgs::JointTrajectory  msg)
{
    msg_up_to_down.ID.resize(ID.size());
    msg_up_to_down.SPEED.resize(ID.size());
    msg_up_to_down.MODE = 2;
    for(int i=0; i<ID.size(); i++)
    {
        msg_up_to_down.ID[i] = ID[i];
        msg_up_to_down.SPEED[i] = msg.points[0].velocities[i];
    }
    pub_up_to_down.publish(msg_up_to_down);
}



int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QFile f("/home/null/ws_ythgj_1/src/ID.txt");
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        ROS_ERROR("Can not read ID.txt!");
        return -1;
    }

    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
        std::cout<<lineStr.toInt()<<std::endl;
        ID.push_back(lineStr.toInt());
    }
    f.close();

    for(int i=0; i<ID.size()-1; i++)
    {
        for(int j=i+1; j<ID.size(); j++)
        {
            if(ID[i] == ID[j])
            {
                ROS_ERROR("There is the same ID!");
                return -1;
            }
        }
    }

    ros::init(argc,argv,"ros_driver");
    CDriver driver_node(argc,argv);

    ros::NodeHandle n;
    CSpeedControlListen speed_control_listener(argc,argv);
    speed_control_listener.sub_speed_control_listen = n.subscribe("ur_driver/joint_speed", 100, &CSpeedControlListen::Callback1, &speed_control_listener);
    speed_control_listener.pub_up_to_down = n.advertise<robot_msgs::UpToDown>("up_to_down", 100);

    ros::spin();

    return 0;
}
