#include <node_example/talker.hpp>

namespace node_example {

ExampleTalker::ExampleTalker(ros::NodeHandle nh_in) : nh(nh_in), message("Hello"), a(1), b(2), enable(true) {
    // Set up a dynamic reconfigure server.
    // Do this before parameter server, else some of the parameter server values can be overwritten.
    dynamic_reconfigure::Server<node_example::nodeExampleConfig>::CallbackType cb;
    cb = boost::bind(&ExampleTalker::configCallback, this, _1, _2);
    dr_srv.setCallback(cb);

    // Declare variables that can be modified by launch file or command line.
    double rate = 1.0;

    // Initialize node parameters from launch file or command line. Use a private node handle so that multiple instances
    // of the node can be run simultaneously while using different parameters.
    ros::NodeHandle pnh("~");
    pnh.param("a", a, a);
    pnh.param("b", b, b);
    pnh.param("message", message, message);
    pnh.param("rate", rate, rate);
    pnh.param("enable", enable, enable);

    if(enable) start();

    timer = nh.createTimer(ros::Duration(1.0/rate), &ExampleTalker::timerCallback, this);
}

void ExampleTalker::start(){
    std::string topic = "example";
    pub = nh.advertise<node_example::ExampleData>(topic, 10);
    if(!pub) ROS_INFO("Failed advertising on '%s'", topic.c_str());
    else ROS_INFO("Advertising on '%s'", pub.getTopic().c_str());
        
}

void ExampleTalker::stop(){
    pub.shutdown();
}

void ExampleTalker::timerCallback(const ros::TimerEvent &event __attribute__((unused))){
    if(!enable) return;

    node_example::ExampleData msg;
    msg.message = message;
    msg.a = a;
    msg.b = b;

    pub.publish(msg);
}

void ExampleTalker::configCallback(node_example::nodeExampleConfig &config, uint32_t level __attribute__((unused))){
    message = config.message;
    a = config.a;
    b = config.b;

    if(enable != config.enable){
        enable = config.enable;
        if(enable) start();
        else stop();
    }
}

}