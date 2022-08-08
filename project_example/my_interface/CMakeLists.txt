cmake_minimum_required(VERSION 3.5)
project(my_interface)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

###############################################################################
#   Paquetes
###############################################################################
find_package(ament_cmake REQUIRED)

###############################################################################
#   Generación de mensajes, servicios y acciones propios
###############################################################################
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
    "msg/MyMsg.msg"
    "srv/MySrv.srv"
    "action/MyAction.action" 
)

###############################################################################
#   Instalación
###############################################################################
ament_package()