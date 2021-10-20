#include <ros/ros.h>
#include <nav_msgs/Odometry.h>

void counterCallback(const nav_msgs::Odometry::ConstPtr &msg){
    ROS_INFO("Id: %s", msg->child_frame_id);
    ROS_INFO("Header Id: %s", msg->header.frame_id);
    ROS_INFO("Orientation Quat: [%.3f, %.3f, %.3f, %.3f]",
        msg->pose.pose.orientation.w,
        msg->pose.pose.orientation.x,
        msg->pose.pose.orientation.y,
        msg->pose.pose.orientation.z
    );
    ROS_INFO("Position XYZ: [%.3f, %.3f, %.3f]",
        msg->pose.pose.position.x,
        msg->pose.pose.position.y,
        msg->pose.pose.position.z
    );
    ROS_INFO("Twist angular: [%.3f, %.3f, %.3f]",
        msg->twist.twist.angular.x,
        msg->twist.twist.angular.y,
        msg->twist.twist.angular.z
    );
    ROS_INFO("Twist linear: [%.3f, %.3f, %.3f]",
        msg->twist.twist.linear.x,
        msg->twist.twist.linear.y,
        msg->twist.twist.linear.z
    );
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "odom_subscriber");
    ros::NodeHandle nh;
    
    ros::Subscriber sub;
    sub = nh.subscribe<nav_msgs::Odometry>("odom", 1000, counterCallback);

    ros::spin();
    
    return 0;
}