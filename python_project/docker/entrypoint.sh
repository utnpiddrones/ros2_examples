#!/bin/bash

set -e
cd /root/dev_ws
source "/opt/ros/${ROS_DISTRO}/setup.bash"

exec "$@"