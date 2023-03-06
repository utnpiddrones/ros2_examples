# Primeros pasos

En este tutorial vamos a ejecutar `turtlesim` y `rqt`, según indica el [tutorial de CLI Tools de ROS2](https://docs.ros.org/en/humble/Tutorials.html), pero usando las herramientas de Docker.

Para obtener la imagen del servidor ejecute:

```bash
docker compose pull
```

Luego, ya puede inciar el contenedor (en segundo plano) con:

```bash
./run.sh
```

Finalmente, puede ejecutar diferentes acciones dentro del contenedor con:

```bash
./exec.sh
```

## Explicación de los archivos

El archivo `Dockerfile` contiene todas las instrucciones necesarias para construir una *imagen* de Docker. Una imagen es una copia estática de las librerías y dependencias necesarias para poder compilar y/o ejecutar nuestro código.

El archivo `docker-compose.yaml` contiene todas las instrucciones necesarias para instanciar la imagen que creamos previamente, es decir, ejecutar un *contenedor*.

Luego, los otros tres scripts de bash sirven para facilitar el manejo al usuario:

* `run.sh` inicia el contenedor.

* `exec.sh` ejecuta comandos dentro del contenedor, una vez ya inicializado.

* `entrypoint.sh` es un archivo recurrente. Es lo primero que se ejecuta dentro del contendor al iniciarlo. Para este ejemplo, `entrypoint.sh` es un volumen, lo que significa que los cambios hechos desde fuera del contenedor se verán reflejados en tiempo real dentro del mismo.
