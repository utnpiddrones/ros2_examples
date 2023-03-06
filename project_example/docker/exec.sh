#!/bin/bash

# Preguntamos qué comando se quiere ejecutar
echo "What to do?"
echo "1. Subscriber and publisher routine."
echo "2. Services and clients."
echo "3. Parameter example."
echo "4. Change parameter value."
echo "5. Interactive terminal."
echo "q. Exit."

read -p "Select option: " -r -n 1 option
echo ""

case $option in
    1) command="ros2 launch my_package sub_launch.py";;

    2) command="ros2 launch my_package service_launch.py";;

    3) command="ros2 launch my_package parameter_launch.py";;

    4) {
        read -p "New parameter value: " -r
        command="ros2 param set /parameter_node my_parameter $REPLY"
    };;

    5) command="/bin/bash";;

    *) {
        echo "Exiting..."
        exit 0
    };;
esac

# Ejecutamos dentro del contenedor el archivo entrypoint y además el comando seleccionado
docker container exec -ti -u "$(id -un)" ros2_ex_cont /bin/bash -c "
    source /entrypoint.sh; \
    ${command};"
