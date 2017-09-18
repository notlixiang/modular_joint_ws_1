#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/car_gui/qnode.hpp"
extern bool key_forward;
extern bool key_back;
extern bool key_left;
extern bool key_right;
extern double current_speed;

namespace car_gui {

QNode::QNode(int argc, char** argv ) : init_argc(argc), init_argv(argv){}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"car_gui");
	if ( ! ros::master::check() ) {
		return false;
	}
    ros::start();
	ros::NodeHandle n;
    pub_speed_control = n.advertise<robot_msgs::UpToDown>("up_to_down", 100);
	start();
	return true;
}

void QNode::run() {
    ros::Rate loop_rate(20);
    speed_msg.ID.resize(2);
    speed_msg.MODE = 2;
    speed_msg.SPEED.resize(2);
    speed_msg.ID[0] = 127;//left
    speed_msg.ID[1] = 3;  //right
    while ( ros::ok() )
    {
        if(key_forward)
        {
            speed_msg.SPEED[0] = -current_speed;
            speed_msg.SPEED[1] = current_speed;
            pub_speed_control.publish(speed_msg);
        }
        else if(key_back)
        {
            speed_msg.SPEED[0] = current_speed;
            speed_msg.SPEED[1] = -current_speed;
            pub_speed_control.publish(speed_msg);
        }
        else if(key_left)
        {
            speed_msg.SPEED[0] = -current_speed;
            speed_msg.SPEED[1] = -current_speed;
            pub_speed_control.publish(speed_msg);
        }
        else if(key_right)
        {
            speed_msg.SPEED[0] = current_speed;
            speed_msg.SPEED[1] = current_speed;
            pub_speed_control.publish(speed_msg);
        }
		loop_rate.sleep();
	}
	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}

}
