import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/k/Main/Studying/GitHub-Repositories/ROS2-Jazzy-Course/ros2_ws/install/my_py_pkg'
