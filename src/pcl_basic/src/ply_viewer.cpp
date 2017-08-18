#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/io/ply_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/vtk_lib_io.h>
#include <pcl/visualization/cloud_viewer.h>

std::string filename; 

int main(int argc, char **argv) {
     pcl::visualization::PCLVisualizer vis;
     filename = "/home/robot/DataBox/household_objects/60ml.ply";
     
    /* 
     //method1
     pcl::PointCloud<pcl::PointXYZ>::Ptr plyCloud_loadPLYFile (new pcl::PointCloud<pcl::PointXYZ>);
     pcl::io::loadPLYFile( filename,  *plyCloud_loadPLYFile);
     vis.addPointCloud( plyCloud_loadPLYFile, "plyCloud_loadPLYFile" );
     std::cout << "TRACE from file " << __FILE__ << " @line " <<__LINE__ << std::endl;
     */

     //method2
     bool val = vis.addModelFromPLYFile( filename,"plyCloud_addModelFromPLYFile");
     std::cout << "val: " << val << std::endl;
     std::cout << "TRACE from file " << __FILE__ << " @line " <<__LINE__ << std::endl;

/*
     //method3
     pcl::PointCloud<pcl::PointXYZRGB>::Ptr plyCloud_loadPolygonFilePLY(new pcl::PointCloud<pcl::PointXYZRGB> ());
     pcl::PolygonMesh triangles;
     pcl::io::loadPolygonFilePLY(filename, triangles);
     pcl::fromPCLPointCloud2(triangles.cloud, *plyCloud_loadPolygonFilePLY);
     vis.addPointCloud( plyCloud_loadPolygonFilePLY,"plyCloud_loadPolygonFilePLY" );
     std::cout << "TRACE from file " << __FILE__ << " @line " <<__LINE__ << std::endl;
*/
     vis.spin();
}
