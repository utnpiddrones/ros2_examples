# Ejemplos de ROS2, embedidos en Docker

En este repositorio encontrará ejemplos de proyectos terminados de ROS2, que siguen los lineamientos de su tutorial.

Los archivos están construidos sobre imágenes de Docker, de modo que puedan ser corridos sin necesidad de instalar ROS2 en su computadora.
(Disclaimer: no están probados en Windows ni en MacOS).

Para ejecutar los programas en necesario que [instale Docker](https://docs.docker.com/engine/install/) y también [Docker-compose](https://docs.docker.com/compose/install/). En caso de estar en Linux, es necesario que le [asigne permisos de super usuario](https://docs.docker.com/engine/install/linux-postinstall/).

## Árbol de directorios
```
ros2_examples
├── first_steps
└── project_example
```
* **first_steps**: Imagen de Docker para correr el tutorial de turtlebot.

* **project_example**: Imagen de Docker con un proyecto de prueba, el cual crea el workspace, define las dependencias y construye el paquete.