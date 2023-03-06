#!/bin/bash

# Create a new user inside the container exactly as the host user
if [ "$(id -u)" -eq 0 ]; then
    set -e
    addgroup --gid "${gid}" "${groupname}" &>/dev/null
    adduser --quiet --gecos "" --home "/home/user" --shell /bin/bash --uid "${uid}" --gid "${gid}" --disabled-password "${username}" &>/dev/null
    usermod -aG sudo "${username}"
    passwd -d "${username}" &>/dev/null
    chown -R "${username}:${groupname}" /home/user
    su "${username}" -c "./entrypoint.sh $*"
    exit 0
fi

source "/opt/ros/${ROS_DISTRO}/setup.bash"
cd ~/ros2_ws
colcon build --symlink-install
source install/local_setup.bash

exec "$@"

