#include "ros/ros.h"
#include "move_base_msgs/MoveBaseActionResult.h"

bool goal_reached=false;

void chatterCallback(const move_base_msgs::MoveBaseActionResult::ConstPtr& msg)
{
    if (msg->status.text=="Goal reached.")
    {
        goal_reached=true;
    }
    if (goal_reached)
    {
        system("play  ~/catkin_ws/src/rs_robot/rsrobot_navigation/tracks/music.wav");
        goal_reached=false;   
    }
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "play_sound");


  ros::NodeHandle n;


  ros::Subscriber sub = n.subscribe("/move_base/result", 1000, chatterCallback);

    

  ros::spin();

  return 0;
}