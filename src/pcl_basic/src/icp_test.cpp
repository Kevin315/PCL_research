#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

using namespace std;
using namespace pcl;

int main (int argc, char** argv)
{
	PointCloud<pcl::PointXYZ>::Ptr cloud_in (new PointCloud<pcl::PointXYZ>);
	PointCloud<pcl::PointXYZ>::Ptr cloud_out (new PointCloud<pcl::PointXYZ>);
	PointCloud<pcl::PointXYZ>::Ptr cloud_test (new PointCloud<pcl::PointXYZ>);

//!!Fill in the Cloud data
	cloud_in->width    = 5;
	cloud_in->height   = 1;
	cloud_in->is_dense = false;
	cloud_in->points.resize (cloud_in->width * cloud_in->height);
	for (size_t i = 0; i < cloud_in->points.size (); ++i)
	{
		cloud_in->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
		cloud_in->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
		cloud_in->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
	}
	cout << "Saved " << cloud_in->points.size () << " data points to input:"<< endl;
	for (size_t i = 0; i < cloud_in->points.size (); ++i) 
	{
		cout << "    " <<cloud_in->points[i].x << " " << cloud_in->points[i].y << " " <<cloud_in->points[i].z << endl;
	}
	*cloud_out = *cloud_in;
	cout << "Size:" << cloud_out->points.size() << endl;
	for (size_t i = 0; i < cloud_in->points.size (); ++i)
	{
		cloud_out->points[i].x = cloud_in->points[i].z + 0.7f;
		cloud_out->points[i].y = cloud_in->points[i].x + 0.7f;
		cloud_out->points[i].z = cloud_in->points[i].y + 0.7f;
	}
	cout << "Transformed " << cloud_in->points.size () << " data points:"<< endl;
	for (size_t i = 0; i < cloud_out->points.size (); ++i)
	{
		cout << "    " << cloud_out->points[i].x << " " <<cloud_out->points[i].y << " " << cloud_out->points[i].z << endl;
	}
	
	cloud_test->width    = 4;
	cloud_test->height   = 1;
	cloud_test->is_dense = false;
	cloud_test->points.resize (cloud_test->width * cloud_test->height);
	for (size_t i = 0; i < cloud_test->points.size (); ++i)
	{
		cloud_test->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
		cloud_test->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
		cloud_test->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
	}
	cout << "Test " << cloud_test->points.size () << " data points:"<< endl;
	for (size_t i = 0; i < cloud_test->points.size (); ++i)
	{
		cout << "    " << cloud_test->points[i].x << " " <<cloud_test->points[i].y << " " << cloud_test->points[i].z << endl;
	}
	
//!!! Implement the ICP alignment and output the result
	IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
	icp.setInputSource(cloud_in);
	//icp.setInputTarget(cloud_out);
	icp.setInputTarget(cloud_test);
	PointCloud<pcl::PointXYZ> Final;
	icp.align(Final);
	cout << "Has converged:" << icp.hasConverged() << " Score: " <<icp.getFitnessScore() << endl;
	cout << icp.getFinalTransformation() <<endl;

	return (0);
}
