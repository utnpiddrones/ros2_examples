#!/bin/bash

# Preguntamos qué comando se quiere ejecutar
echo "What to do?"
echo "1. Run turtlesim"
echo "2. Control turtlesim"
echo "3. Open rqt."
echo "4. Open terminal."
echo "q. Exit"

read -p "Select option: " -r -n 1 option
echo ""

case $option in
    1) command="ros2 run turtlesim turtlesim_node";;

    2) command="ros2 run turtlesim turtle_teleop_key";;

    3) command="rqt";;

    4) command="/bin/bash";;

    *) {
        echo "Exiting..."
        exit 0
    };;
esac

# Ejecutamos dentro del contenedor el archivo entrypoint y además el comando seleccionado
docker container exec -ti -u "$(id -un)" ros2_ex_cont /bin/bash -c "
    source /entrypoint.sh; \
    ${command};"
