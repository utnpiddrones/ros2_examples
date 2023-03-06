FROM ros:humble

###############################################################################
#   Dependencias
###############################################################################
RUN apt-get update && apt-get install -y \
    ros-${ROS_DISTRO}-turtlesim \
    ~nros-${ROS_DISTRO}-rqt* \
    python3-colcon-common-extensions \
    git && \
    rm -rf /var/lib/apt/lists/*

###############################################################################
#   Creación del proyecto
###############################################################################

COPY entrypoint.sh /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]
CMD ["/bin/bash"]