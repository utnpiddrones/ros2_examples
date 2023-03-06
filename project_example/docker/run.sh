#!/bin/bash

# Obtenemos el usuario actual
uid=$(id -u)
gid=$(id -g)
username=$(id -un)
groupname=$(id -gn)
export uid gid username groupname

docker compose -f docker-compose.yaml run --rm --name ros2_ex_cont ros
