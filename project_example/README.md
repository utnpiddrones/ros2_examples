# Proyecto de ejemplo

## Árbol de directorios
```
project_example
├── Docker
├── my_interface
│   ├── msg
│   └── srv
└── my_package
    ├── include
    └── src
```

* **Docker**: Contiene todos los archivos necesarios para construir el Docker.

* **my_interface**: Paquete usado para generar un mensaje y servicio personalizado.

* **my_package**: Paquete que contiene un subscriptor, un publicador, un cliente, y un servicio.

Este container utiliza el concepto de `volumenes`. Los cambios que haga dentro de las carpetas `my_interface` y `my_package` se actualizan en tiempo real sobre el contenedor, de modo que puede hacer cambios en el código, volver a construir los paquetes con `colcon build`, y ver los cambios en los nodos de ROS2.

## Buildeo de la imagen

Parado sobre el directorio `Docker`
```
$ docker-compose build
```

## Ejecución del container
Ejecutar por única vez al iniciar la computadora:

```
$ xhost +local:root
```

Para iniciar el container:
```
$ docker-compose pull
$ docker-compose run --rm --name ros ros
```

Para ejecutar una nueva terminal:
```
$ docker exec -ti ros /bin/bash
$ cd ~/dev_ws && . install/setup.bash
```

## Archivos launch
Dentro del Docker, pruebe a ejecutar los archivos launch ya creados:
```
$ ros2 launch my_package service_launch.py
$ ros2 launch my_package sub_launch.py
```

