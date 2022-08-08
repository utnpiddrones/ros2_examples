# Primeros pasos

En este tutorial vamos a ejecutar `turtlesim` y `rqt`, según indica el [tutorial de CLI Tools de ROS2](https://docs.ros.org/en/foxy/Tutorials.html).

Para generar la imagen, ejecute:

```
$ docker-compose pull
```

Disclaimer: este contenedor corre una GUI, y para ello es necesario conectar el monitor de su computadora con el contenedor. Los drivers y la forma de conectar los dispositivos varían según el sistema operativo que use. Para este ejemplo y posteriores, se usará GNU Linux con Xhost. Para permitir el uso del periférico (desde la address local, bajo el usuario root), debe correr esta línea cada vez que inicie su computadora:

```
$ xhost +local:root
```

Luego, ya puede ejecutar el contenedor con:

```
$ docker-compose run --rm --name ros ros
```

Ahora, abra otra terminal, y ejecute:
```
$ docker ps

# Verá un output de la siguiente forma:
CONTAINER ID   IMAGE                     COMMAND                  CREATED         STATUS         PORTS     NAMES
14c29e3195a8   ncotti/ros2:first_steps   "/entrypoint.sh /bin…"   5 seconds ago   Up 3 seconds             ros
```

Como puede ver, ahora hay un container ejecutándose de nombre "ros".

Si quiere ejecutar nuevas terminales dentro del mismo container, abra otra terminal y ejecute:

```
$ docker exec -ti ros /bin/bash

# Una vez dentro del container, hay que sourcear el entorno de ROS2
$ source "/opt/ros/${ROS_DISTRO}/setup.bash"
```

## Comandos de turtlebot
```
$ ros2 run turtlesim turtlesim_node
$ ros2 run turtlesim turtle_teleop_key
$ rqt
```
