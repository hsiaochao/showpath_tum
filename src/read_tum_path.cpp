#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>
using namespace std;
int main(int argc, char** argv) {
    ros::init(argc, argv, "trajectory_publisher");
    ros::NodeHandle nh;

    ros::Publisher path_pub = nh.advertise<nav_msgs::Path>("trajectory", 10);

  // 从参数服务器获取路径//Get path from parameter server
  std::string file_path;
  if (!nh.getParam("tum_file_path", file_path)) {
    ROS_ERROR("Failed to retrieve 'file_path' parameter");
    return 1;
  }

    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string line;
        nav_msgs::Path path;
        path.header.frame_id = "map"; // 设置参考系//Set frame

        while (std::getline(file, line)) {
            // 解析时间戳和位姿信息//Parsing timestamp and pose information
            double timestamp, x, y, z;
            // ...
std::istringstream iss(line);
       if (!(iss >> timestamp >> x >> y >> z)) {
            ROS_WARN_STREAM("Invalid line format: " << line);
            continue;
        }
            // 创建并填充PoseStamped消息//Create and fill in PoseStamped messages
            geometry_msgs::PoseStamped pose;
            pose.header.stamp = ros::Time(timestamp);
            pose.pose.position.x = x;
            pose.pose.position.y = y;
            pose.pose.position.z = z;
            // ... 设置其他位姿信息// Set other pose information
            //cout<<x<<endl;
            // 将PoseStamped消息添加到Path消息中//Add PoseStamped message to Path message
            path.poses.push_back(pose);

            // 发布Path消息//Publish Path message
            if (path_pub.getNumSubscribers() > 0) {
                path_pub.publish(path);
            }

            ros::spinOnce();
            ros::Duration(0.1).sleep(); // 控制发布频率，每次间隔0.1秒//Control the publishing frequency with a 0.1 second interval between each release
        }

        file.close();
    } else {
        ROS_ERROR("Failed to open file");
    }

    return 0;
}

