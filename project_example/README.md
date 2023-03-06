# Proyecto de ROS2 de ejemplo usando C++

## Árbol de directorios

```bash
project_example
├── docker
├── my_interface
│   ├── msg
│   └── srv
├── my_package
|    ├── include
|    ├── launch
|    └── src
└── python_package
```

* **docker**: Contiene todos los archivos necesarios para construir la imagen de Docker y ejecutar los containers.

* **my_interface**: Paquete usado para generar un mensaje y servicio personalizado.

* **my_package**: Paquete que contiene un subscriptor, un publicador, un cliente, y un servicio; además de los archivos "launch" para ejecutar los nodos de ROS2.

* **python_package**: Lo mismo que `my_package` pero escrito en Python en vez de C++.

## Ejecución del container

Para iniciar el container:

```bash
./run.sh
```

En una nueva terminal, ejecute los comandos dentro del container con:

```bash
./exec.sh
```
