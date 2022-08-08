FROM ros:foxy-ros-base-focal

###############################################################################
#   Dependencias
###############################################################################
RUN apt-get update && apt-get install -y \
      ros-${ROS_DISTRO}-turtlesim \
      ~nros-${ROS_DISTRO}-rqt* && \
    rm -rf /var/lib/apt/lists/*

RUN apt-get update && apt-get install -y \
    python3-colcon-common-extensions \
    git && \
    rm -rf /var/lib/apt/lists/*

###############################################################################
#   Creación del proyecto
###############################################################################
ARG PKG_NAME="my_package"

RUN /bin/bash -c "mkdir -p /root/dev_ws/src; \
    cd /root/dev_ws"

COPY Docker/entrypoint.sh /entrypoint.sh

WORKDIR /root/dev_ws
ENTRYPOINT ["/entrypoint.sh"]
CMD ["/bin/bash"]