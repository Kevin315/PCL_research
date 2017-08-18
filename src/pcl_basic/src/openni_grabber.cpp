 #include <pcl/io/openni_grabber.h>
 #include <pcl/visualization/cloud_viewer.h>
 #include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

 class SimpleOpenNIViewer
 {
   public:
     SimpleOpenNIViewer () : viewer ("PCL OpenNI Viewer") {}

     void cloud_cb_ (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr &cloud)
     {
       int i=0;
       if (!viewer.wasStopped())
       {
		   viewer.showCloud (cloud);
		   pcl::io::savePCDFileASCII ("test_pcd.pcd", *cloud);
       std::cerr << "Saved " << cloud->points.size () << " data points to test_pcd.pcd." << std::endl;
       i=i+1;
       std::cout<<i<<endl;
       //for (size_t i = 0; i < cloud.points.size (); ++i)
       //std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl;
     }
     }

     void run ()
     {
       pcl::Grabber* interface = new pcl::OpenNIGrabber();

       boost::function<void (const pcl::PointCloud<pcl::PointXYZ>::ConstPtr&)> f =
         boost::bind (&SimpleOpenNIViewer::cloud_cb_, this, _1);

       interface->registerCallback (f);

       interface->start ();

       while (!viewer.wasStopped())
       {
         boost::this_thread::sleep (boost::posix_time::seconds (1));
       }

       interface->stop ();
     }

     pcl::visualization::CloudViewer viewer;
 };

 int main ()
 {
   SimpleOpenNIViewer v;
   v.run ();
   return 0;
 }
