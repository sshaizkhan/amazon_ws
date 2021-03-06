//
// Created by Shahwaz Khan on 2/19/21.
//

//// This node detects the edge of the object which is at the closest distance from the origin of the realsense camera.
//// The z-axis emerges from the lens of the camera, the y-axis always points downwards and the x-axis towards right.
//// RIGHT HAND THUMB RULE

#ifndef SRC_PACKAGE_EDGE_DETECTION_H
#define SRC_PACKAGE_EDGE_DETECTION_H

#include "point_cloud_utilities/pcl_utilities.h"
#include "ros/package.h"


typedef pcl::PointCloud<pcl::PointXYZ> PointCloudT;

class PackageTracking{

protected:
    /* data */
    std::string file_path_ = ros::package::getPath("package_tracking") + "/data/data_Omey/";

public:
    PackageTracking();
    ros::NodeHandle nh_;

    std::string file_name;

//  Point cloud tracking members
    ros::Publisher package_cloud_pub_;
    std::vector<double> cam_box_limits_;
    PointCloudT::Ptr box_filtered_cloud_ptr_;

    double tolerance{};
    double ec_tolerance{};
    int minClusterSize{};
    int maxClusterSize{};

//  Camera members

    ros::Subscriber cam_pointcloud_sub_;
    std::string frame_id_;
    PointCloudT::Ptr cam_scene_cloud_ptr_;

//  Callback functions

    void pointCloudInfoCb(const sensor_msgs::PointCloud2& scene_cloud);

//    void pointCloudSaveCb(std::string& file_no_);

    PointCloudT cloud_processing(PointCloudT& cloudIn) const;

//  Class Methods
    void trackEdge();
    void applyBoxFilter();

};
#endif //SRC_PACKAGE_EDGE_DETECTION_H
