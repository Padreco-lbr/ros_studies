#include <ros/ros.h>
#include <std_msgs/Int32.h>

void counterCallback(const std_msgs::Int32::ConstPtr &msg){
    ROS_INFO("%d", msg->data);    
}

int main(int argc, char* argv[])
{
    ROS_INFO("Starting node...");
    ros::init(argc, argv, "topic_subscriber");
    ros::NodeHandle nh;
    
    ros::Subscriber sub;
    sub = nh.subscribe<std_msgs::Int32>("counter", 1000, counterCallback);
    ROS_INFO("Subscribed to 'counter'");

    ros::spin();
    
    return 0;
}