#include <node_example/talker.hpp>

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "talker_node");
  ros::NodeHandle nh;

  // Create a new node_example::Talker object.
  node_example::ExampleTalker node(nh);
  ROS_INFO("Started talker node loop");

  // Let ROS handle all callbacks.
  ros::spin();

  return 0;
}  // end main()