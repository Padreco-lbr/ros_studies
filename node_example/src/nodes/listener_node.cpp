#include <node_example/listener.hpp>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "listener_node");
    ros::NodeHandle nh;

    node_example::ExampleListener node(nh);
    ROS_INFO("Started listener node loop");

    ros::spin();

    return 0;
}