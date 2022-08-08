cmake_minimum_required(VERSION 3.5)
project(my_package)

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
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(my_interface REQUIRED)

###############################################################################
#   Ejecutables
###############################################################################
add_executable(publisher src/publisher.cpp)
target_include_directories(publisher PUBLIC include)
ament_target_dependencies(publisher rclcpp std_msgs)

add_executable(subscriber src/subscriber.cpp)
target_include_directories(subscriber PUBLIC include)
ament_target_dependencies(subscriber rclcpp std_msgs)

add_executable(service src/service.cpp)
ament_target_dependencies(service rclcpp my_interface)

add_executable(client src/client.cpp)
ament_target_dependencies(client rclcpp my_interface)

add_executable(parameter src/parameter.cpp)
target_include_directories(parameter PUBLIC include)
ament_target_dependencies(parameter rclcpp)


###############################################################################
#   Instalación
###############################################################################
install(TARGETS publisher subscriber service client parameter DESTINATION lib/${PROJECT_NAME})

# Para incluir los archivos launch
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME}/)

ament_package()