FROM ros:humble

RUN apt-get update && apt-get install -y \
  ros-${ROS_DISTRO}-turtlesim \
  ~nros-${ROS_DISTRO}-rqt* \
  && rm -rf /var/lib/apt/lists/*

COPY entrypoint.sh /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["/bin/bash"]