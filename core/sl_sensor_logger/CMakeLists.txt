cmake_minimum_required(VERSION 2.8.3)
project(sl_sensor_logger)

find_package(catkin_simple REQUIRED)
find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)

catkin_simple(ALL_DEPS_REQUIRED)

add_definitions(-Wall -Wextra)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

#############
# LIBRARIES #
#############
cs_add_library(${PROJECT_NAME}
  src/logger_nodelet.cpp
  src/image_array_logger_nodelet.cpp
  src/point_cloud_logger_nodelet.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC "/include" ${PCL_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${PCL_LIBRARIES})

##########
# EXPORT #
##########
cs_install()
cs_export()
