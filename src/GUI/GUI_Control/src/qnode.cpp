#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/GUI_Control/qnode.hpp"

extern std::vector<float> joint_speed;
extern std::vector<float> joint_value_listen;
extern std::vector<bool>  key_speed_control_left;
extern std::vector<bool>  key_speed_control_right;
extern std::vector<int>   ID;
extern std::vector<float> CURRENT;
extern std::vector<float> TEMPERATURE;
extern int num_of_joints;

// ---------------------------------------------------------------------
// ---------------------------------------------------------------------
// speed_control
// ---------------------------------------------------------------------
CSpeedControl::CSpeedControl(int argc, char** argv ) : init_argc(argc), init_argv(argv) {}
CSpeedControl::~CSpeedControl() {
    if(ros::isStarted()) {
      ros::shutdown();
      ros::waitForShutdown();
    }
    wait();
}

bool CSpeedControl::init() {
    ros::init(init_argc,init_argv,"speed_control");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start();
    ros::NodeHandle n;
    pub_speed_control = n.advertise<trajectory_msgs::JointTrajectory>("ur_driver/joint_speed", 100);
    start();
    return true;
}

void CSpeedControl::run() {
    ros::Rate loop_rate(20);
    while (ros::ok())
    {
        for(int i=0; i<num_of_joints; i++)
        {
            if(key_speed_control_left[i])
            {
                QString str;
                speed_states.joint_names.resize(1);
                str.setNum(i);
                speed_states.joint_names[0] = str.toStdString();
                speed_states.points.resize(1);
                speed_states.points[0].velocities.resize(num_of_joints);
                for(int j=0;j<num_of_joints;j++)
                {
                    if(j!=i)
                        speed_states.points[0].velocities[j] = 0;
                    else
                        speed_states.points[0].velocities[j] = -1*joint_speed[i];
                }
                pub_speed_control.publish(speed_states);
                break;
            }
            else if(key_speed_control_right[i])
            {
                QString str;
                speed_states.joint_names.resize(1);
                str.setNum(i);
                speed_states.joint_names[0] = str.toStdString();
                speed_states.points.resize(1);
                speed_states.points[0].velocities.resize(num_of_joints);
                for(int j=0;j<num_of_joints;j++)
                {
                    if(j!=i)
                        speed_states.points[0].velocities[j] = 0;
                    else
                        speed_states.points[0].velocities[j] = 1*joint_speed[i];
                }
                pub_speed_control.publish(speed_states);
                break;
            }
        }
        loop_rate.sleep();
    }
    Q_EMIT rosShutdown();
}


// -----------------------------------------------------------
// -----------------------------------------------------------
// Joint_Listen and down_to_up Listen
// -----------------------------------------------------------
CJointListen::CJointListen(int argc, char** argv ) : init_argc(argc), init_argv(argv) {
    ros::init(init_argc,init_argv,"gui_joint_listener");
}
CJointListen::~CJointListen() {
    if(ros::isStarted()) {
      ros::shutdown();
      ros::waitForShutdown();
    }
    wait();
}

void Callback1(sensor_msgs::JointState  msg)
{
    for(int i=0;i<msg.position.size();i++)
    {
        joint_value_listen[i] = msg.position[i];
    }
}

void Callback2(robot_msgs::DownToUp msg)
{
    if(msg.TYPE == "CURRENT")
    {
        for(int i=0;i<num_of_joints;i++)
        {
            if(msg.ID == ID[i])
            {
                CURRENT[i] = msg.DATA[0];
            }
        }
    }
    else if(msg.TYPE == "TEMPERATURE")
    {
        for(int i=0;i<num_of_joints;i++)
        {
            if(msg.ID == ID[i])
            {
                TEMPERATURE[i] = msg.DATA[0];
            }
        }
    }
//    else if(msg.TYPE == "ACCELERATION")
//    {
//        for(int i=0;i<ID.size();i++)
//        {
//            if(msg.ID == ID[i])
//            {
//                acceleration[0][i] = msg.DATA[0];
//                acceleration[1][i] = msg.DATA[1];
//                acceleration[2][i] = msg.DATA[2];
//            }
//        }
//    }
//    else if(msg.TYPE == "ANGULAR_SPEED")
//    {
//        for(int i=0;i<ID.size();i++)
//        {
//            if(msg.ID == ID[i])
//            {
//                angular_speed[0][i] = msg.DATA[0];
//                angular_speed[1][i] = msg.DATA[1];
//                angular_speed[2][i] = msg.DATA[2];
//            }
//        }
//    }
//    else if(msg.TYPE == "RPY_ANGLE")
//    {
//        for(int i=0;i<ID.size();i++)
//        {
//            if(msg.ID == ID[i])
//            {
//                rpy_angle[0][i] = msg.DATA[0];
//                rpy_angle[1][i] = msg.DATA[1];
//                rpy_angle[2][i] = msg.DATA[2];
//            }
//        }
//    }
}

bool CJointListen::init() {
    ros::start();
    ros::NodeHandle n;
    sub_joint_position = n.subscribe("joint_states", 1000, Callback1);
    sub_down_to_up = n.subscribe("down_to_up", 1000, Callback2);
    start();
    return true;
}

void CJointListen::run() { ros::spin(); }

