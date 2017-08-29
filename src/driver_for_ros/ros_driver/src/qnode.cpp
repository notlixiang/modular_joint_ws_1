#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/ros_driver/qnode.hpp"
#include <ctime>
#include <numeric>
#include <QString>

std::vector<trajectory_msgs::JointTrajectoryPoint> points;
double joint_value[6]={0,0,0,0,0,0};
extern std::vector<int> ID;
double interval_time = 0.02;

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// FollowJointTrajectoryAction   receive MoveIt result and publish to /up_to_down
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
CFollowJointTrajectoryAction::CFollowJointTrajectoryAction(int argc, char** argv ) : init_argc(argc), init_argv(argv),
    as_(nh_,"follow_joint_trajectory",boost::bind(&CFollowJointTrajectoryAction::executeCB, this, _1), false)
{
    pub_up_to_down = nh_.advertise<robot_msgs::UpToDown>("up_to_down", 100);
    as_.start();
}
CFollowJointTrajectoryAction::~CFollowJointTrajectoryAction() {}
void CFollowJointTrajectoryAction::executeCB(const control_msgs::FollowJointTrajectoryGoalConstPtr &goal)
{
    std::vector<std::vector<double> > position(ID.size());
    std::vector<std::vector<double> > velocity(ID.size());
    std::vector<std::vector<double> > accelation(ID.size());
    double time_now=0;
    points = goal->trajectory.points;
    int points_num = points.size();
    for(int i=0; i<ID.size(); i++)
    {
        position[i].clear();
        velocity[i].clear();
        accelation[i].clear();
    }
    for(int i=0; i<(points_num-1); i++)
    {
        double time2 = ((float)points[i+1].time_from_start.sec) + ((float)points[i+1].time_from_start.nsec)/1000000000;
        double time1 = ((float)points[i].time_from_start.sec) + ((float)points[i].time_from_start.nsec)/1000000000;
        double t_betw_def_pionts = time2 - time1;
        int count = 0;
        for(int j=0; j<ID.size(); j++)
        {
            double a0,a1,a2,a3,a4,a5;
            a0=points[i].positions[j];
            a1=points[i].velocities[j];
            a2=points[i].accelerations[j]/2;
            a3=(20*points[i+1].positions[j]-20*points[i].positions[j]
                        -12*points[i].velocities[j]*(t_betw_def_pionts)-8*points[i+1].velocities[j]*(t_betw_def_pionts)
                        -3*points[i].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts)+points[i+1].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts))/(2*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts));
            a4=(-30*points[i+1].positions[j]+30*points[i].positions[j]
                        +16*points[i].velocities[j]*(t_betw_def_pionts)+14*points[i+1].velocities[j]*(t_betw_def_pionts)
                        +3*points[i].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts)-2*points[i+1].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts))/(2*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts));
            a5=(12*points[i+1].positions[j]-12*points[i].positions[j]
                        -6*points[i].velocities[j]*(t_betw_def_pionts)-6*points[i+1].velocities[j]*(t_betw_def_pionts)
                        -points[i].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts)+points[i+1].accelerations[j]*(t_betw_def_pionts)*(t_betw_def_pionts))/(2*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts)*(t_betw_def_pionts));
            for(double t=(time_now-time1); (t+time_now)<time2; t+=interval_time)
            {
                position[j].push_back(a0 + a1*t +a2*t*t + a3*t*t*t + a4*t*t*t*t + a5*t*t*t*t*t);
                velocity[j].push_back(a1 + 2*a2*t + 3*a3*t*t + 4*a4*t*t*t + 5*a5*t*t*t*t);
                accelation[j].push_back(2*a2 + 6*a3*t + 12*a4*t*t + 20*a5*t*t*t);
                count++;
            }
        }
        time_now += interval_time * count/ID.size();
    }
    for(int i=0; i<ID.size(); i++)
    {
        position[i].push_back(points[points_num-1].positions[i]);
        velocity[i].push_back(points[points_num-1].velocities[i]);
        accelation[i].push_back(points[points_num-1].accelerations[i]);
    }
    int num = position[0].size();
    int y=0;
    msg_up_to_down.ID.resize(ID.size());
    msg_up_to_down.POSITION.resize(ID.size());
    msg_up_to_down.SPEED.resize(ID.size());
    msg_up_to_down.CURRENT.resize(ID.size());
    msg_up_to_down.MODE = 1;
    ros::Rate loop_rate(50);
    while(num>0)
    {
        for(int i=0; i<ID.size(); i++)
        {
            msg_up_to_down.ID[i] = ID[i];
            msg_up_to_down.POSITION[i] = position[i][y];
            msg_up_to_down.SPEED[i] = velocity[i][y];
            msg_up_to_down.CURRENT[i] = accelation[i][y];
        }
        y++;
        num--;
        pub_up_to_down.publish(msg_up_to_down);
        loop_rate.sleep();
    }

    num = position[0].size();
    std::cout<<"下发总点数"<<num<<std::endl;
    as_.setSucceeded(result_);
}


// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// JointPublisher
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
CJointPublisher::CJointPublisher(int argc, char** argv ) : init_argc(argc), init_argv(argv)
{
    ros::NodeHandle n;
    joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 100);
    start();
}
CJointPublisher::~CJointPublisher() {}
void CJointPublisher::run()
{
    ros::Rate loop_rate(30);
           while (ros::ok()) {
                joint_state.header.stamp = ros::Time::now();

                //UR test
/*
                joint_state.name.resize(6);
                joint_state.position.resize(6);
                joint_state.name[0] ="shoulder_pan_joint";
                joint_state.position[0] = joint_value[0];
                joint_state.name[1] ="shoulder_lift_joint";
                joint_state.position[1] = joint_value[1];
                joint_state.name[2] ="elbow_joint";
                joint_state.position[2] = joint_value[2];
                joint_state.name[3] ="wrist_1_joint";
                joint_state.position[3] = joint_value[3];
                joint_state.name[4] ="wrist_2_joint";
                joint_state.position[4] = joint_value[4];
                joint_state.name[5] ="wrist_3_joint";
                joint_state.position[5] = joint_value[5];*/

                // 一体化关节
                
                joint_state.name.resize(ID.size());
                joint_state.position.resize(ID.size());
                QString str;
                for(int i=0;i<ID.size();i++)
                {
                    str = str.setNum(i);
                    joint_state.name[i] = "joint_" + str.toStdString();
                    joint_state.position[i] = joint_value[i];
                }
               
                joint_pub.publish(joint_state);
                loop_rate.sleep();
           }
           ros::shutdown();
}

// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
// DownToUp
// -------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Callback(robot_msgs::DownToUp  msg)
{
    if(msg.TYPE == "POSITION")
    {
        for(int i=0; i<ID.size(); i++)
        {
            if(ID[i] == msg.ID)
            {
                joint_value[i] = msg.DATA[0];
                break;
            }
        }
    }
}

CDownToUp::CDownToUp(int argc, char** argv ) : init_argc(argc), init_argv(argv)
{
    ros::NodeHandle n;
    sub_down_to_up = n.subscribe("down_to_up", 1000, Callback);
}
CDownToUp::~CDownToUp() {}
