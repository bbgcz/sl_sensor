cmake_minimum_required(VERSION 2.8.3)
project(sl_sensor_timer)

find_package(catkin_simple REQUIRED)
catkin_simple(ALL_DEPS_REQUIRED)

add_definitions(-Wall -Wextra)
set (CMAKE_CXX_STANDARD 17)

#############
# LIBRARIES #
#############
cs_add_library(${PROJECT_NAME}
        src/timer.cpp
  )

target_include_directories(${PROJECT_NAME} PUBLIC "/include")

##########
# EXPORT #
##########
cs_install()
cs_export()
