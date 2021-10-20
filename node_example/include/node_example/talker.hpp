#pragma once

#include <ros/ros.h>
#include <ros/time.h>

#include <dynamic_reconfigure/server.h>
#include <node_example/ExampleData.h>
#include <node_example/nodeExampleConfig.h>

namespace node_example
{
class ExampleTalker {
    public:
    explicit ExampleTalker(ros::NodeHandle nh);

    private:
    void configCallback(node_example::nodeExampleConfig &config, uint32_t level);

    void timerCallback(const ros::TimerEvent &event);

    // Lifecycle control
    void start();
    void stop();

    ros::NodeHandle nh;
    ros::Timer timer;
    ros::Publisher pub;
    dynamic_reconfigure::Server<node_example::nodeExampleConfig> dr_srv;
    
    // Msg contents
    std::string message;
    int a;
    int b;
    bool enable;
};
}