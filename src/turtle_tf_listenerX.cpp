#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_listenerX");

  ros::NodeHandle node;

// Listener
  tf::TransformListener listener;

  ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;
    try{
      listener.lookupTransform("/turtleB", "/turtleA",
                               ros::Time(0), transform);
    }
    catch (tf::TransformException &ex) {
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
      continue;
    }

    ROS_INFO("turtleA is on (%f, %f) to turtleB\n", 
             transform.getOrigin().x(),
	     transform.getOrigin().y());

    rate.sleep();
  }
  return 0;
};
