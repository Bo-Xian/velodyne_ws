
操作步驟

實體
open 3D Lidar       : $ roslaunch velodyne_pointcloud VLP16_points.launch

使用data set
pub kitti data set  : $ rosrun pub_test_data pub_tset_data.py

open rviz           : $ rosrun rviz rviz -f velodyne

使用Gazebo
open gazebo         :$ roslaunch velodyne_description example.launch
kill gazebo         :$ killall gzserver
                    :$ killall gzclient

運行動態偵測
objects detection   : $ rosrun dynamic_object_detection pointCloud.py
objects detection   : $ rosrun dynamic_object_detection point_pre_processor

################################################################

連接實體VLP-16 網路線設定

手動
地址	：192.168.1.77
網路遮罩：255.255.255.0
通訊閘	：192.168.1.1

################################################################

資料包介紹

velodyne                    :運行實體VLP-16
dynamic_object_detection    :運行動態物件偵測
pub_test_data               :使用kitti data set
velodyne_simulator          :虛擬環境模擬
obstacle_motion             :虛擬障礙物移動
web                         :控制vlp-16移動

################################################################

參考資料

SLAM之鐳射雷達Velodyne vlp-16使用
https://www.itread01.com/content/1547352842.html

velodyne Tutorials
http://wiki.ros.org/velodyne/Tutorials/Getting%20Started%20with%20the%20Velodyne%20VLP16

AI葵 yuotube
https://www.youtube.com/channel/UC7UlsMUu_gIgpqNGB4SqSwQ

Python 调用 C++
https://iqhy.github.io/posts/2020/0228155601/

################################################################

下載 import

pip install pandas

pip install scikit-learn

pip install fuzzy-c-means

pip install cython

python讀中文字
# -*- coding: UTF-8 -*-

