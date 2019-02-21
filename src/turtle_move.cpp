#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

ros::Publisher move_pub;

void pose_CB(const turtlesim::Pose::ConstPtr& msg){
  msg->x;
  msg->y;
  msg->theta;
}

int main(int argc, char **argv){

  ros::init(argc, argv, "turtles");
  ros::NodeHandle n;
  move_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
  ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 1000, pose_CB);

  double a = 1.0;
  double b = 0.5;

  while(ros::ok()){

    geometry_msgs::Twist cmd_vel;

/*    if(theta > 6.2){
    cmd_vel.linear.x = a * -1.0;
    cmd_vel.angular.z = b * -1.0;
    }
    else{
*/      cmd_vel.linear.x = 1.0;
      cmd_vel.angular.z = 0.5;
//    }

    move_pub.publish(cmd_vel);

    ros::spinOnce();
  }

  return 0;
}
