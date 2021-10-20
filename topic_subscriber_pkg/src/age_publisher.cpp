#include <ros/ros.h>
#include <topic_subscriber_pkg/Age.h>

int main(int argc, char* argv[])
{
    ros::init(argc, argv, "age_publisher");
    ros::NodeHandle nh;
    
    ros::Publisher pub;
    pub = nh.advertise<topic_subscriber_pkg::Age>("robot_age", 10);
    
    topic_subscriber_pkg::Age age;
    age.year = 2021;
    age.month = 10;
    age.day = 19;
    
    ros::Rate loop_rate(1);
    while (ros::ok())
    {
        pub.publish(age);
    
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}