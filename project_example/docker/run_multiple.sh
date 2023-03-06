#!/bin/bash

# Obtenemos el usuario actual
uid=$(id -u)
gid=$(id -g)
username=$(id -un)
groupname=$(id -gn)
export uid gid username groupname

docker compose -f docker-compose-multiple.yaml up
docker compose -f docker-compose-multiple.yaml down