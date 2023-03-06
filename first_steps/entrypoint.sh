#!/bin/bash

###############################################################################
#   Este es el archivo entrypoint. Será ejecutado cada vez que iniciemos el
#   contenedor. 
###############################################################################

# Create a new user inside the container exactly as the host user
if [ "$(id -u)" -eq 0 ]; then
    set -e
    addgroup --gid "${gid}" "${groupname}" &>/dev/null
    adduser --quiet --gecos "" --home "/home/user" --shell /bin/bash --uid "${uid}" --gid "${gid}" --disabled-password "${username}" &>/dev/null
    usermod -aG sudo "${username}"
    passwd -d "${username}" &>/dev/null
    chgrp -R "${groupname}" /home/user
    su "${username}" -c "./entrypoint.sh $*"
    exit 0
fi

# Pueden probar agregar comandos aquí, y verán como son ejecutados al iniciar.
source "/opt/ros/${ROS_DISTRO}/setup.bash"
exec "$@"
