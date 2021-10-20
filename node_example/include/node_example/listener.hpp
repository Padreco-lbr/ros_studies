#pragma once

#include <ros/ros.h>
#include <ros/time.h>

#include <node_example/ExampleData.h>

namespace node_example
{
class ExampleListener {
    public:
    ExampleListener(ros::NodeHandle);
    void messageCallback(const node_example::ExampleData::ConstPtr&);

    private:
    ros::Subscriber sub;
};
}