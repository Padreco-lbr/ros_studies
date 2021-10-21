#include <ros/ros.h>
#include <std_srvs/Empty.h>

bool callback(std_srvs::EmptyRequest &req, std_srvs::EmptyResponse &res)
{
    ROS_INFO_STREAM("Callback called!");
    return true;
}

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "service_server");
    ros::NodeHandle nh;

    auto service = nh.advertiseService("/my_service", callback);
    ROS_INFO("myService is on!");

    ros::spin();

    return 0;
}