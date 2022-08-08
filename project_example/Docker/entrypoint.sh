#!/bin/bash

set -e
cd /root/dev_ws
source "/opt/ros/${ROS_DISTRO}/setup.bash"
colcon build --symlink-install
. install/local_setup.bash

exec "$@"