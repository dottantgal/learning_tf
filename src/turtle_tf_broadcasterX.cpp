#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <geometry_msgs/Twist.h>

void add_turtleA()
{
// Create frame "turtleA"
  static tf::TransformBroadcaster brA;
  tf::Transform trA;
  trA.setOrigin( tf::Vector3(1.0, 1.0, 0.0) );
  tf::Quaternion qA;
  qA.setRPY(0, 0, 0);
  trA.setRotation(qA);
  brA.sendTransform(tf::StampedTransform(trA, ros::Time::now(), "world", "/turtleA"));
}

void add_turtleB()
{
// Create frame "turtleB"
  static tf::TransformBroadcaster brB;
  tf::Transform trB;
  trB.setOrigin( tf::Vector3(10.0, 10.0, 0.0) );
  tf::Quaternion qB;
  qB.setRPY(0, 0, 0);
  trB.setRotation(qB);
  brB.sendTransform(tf::StampedTransform(trB, ros::Time::now(), "world", "/turtleB"));
}

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcasterX");

  ros::NodeHandle node;

  ros::Rate rate(10.0);
  while (node.ok()){

    add_turtleA();
    add_turtleB();

    rate.sleep();
  }
  return 0;
};
