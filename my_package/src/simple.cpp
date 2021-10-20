#include <ros/ros.h>

int main (int argc, char** argv){
    ros::init(argc, argv, "ObiWan");
    ros::NodeHandle nh;
    ros::Rate loop_rate(2);

    while(1) {
        ROS_INFO("Some nerdy star wars quote");
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}