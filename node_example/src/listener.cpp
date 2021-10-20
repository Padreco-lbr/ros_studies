#include <node_example/listener.hpp>

namespace node_example {
ExampleListener::ExampleListener(ros::NodeHandle nh){
    std::string topic = "example";
    sub = nh.subscribe(topic, 10, &ExampleListener::messageCallback, this);

    if(sub) ROS_INFO("Subscribed to '%s'", sub.getTopic().c_str());
    else ROS_INFO("Failed subscribing to '%s'", topic.c_str());
}

void ExampleListener::messageCallback(const node_example::ExampleData::ConstPtr &msg){
    ROS_INFO("Message is %s, a + b = %d", msg->message.c_str(), msg->a + msg->b);
}
}