cmake_minimum_required(VERSION 3.7)
project(The-Walk-of-Life)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wpedantic -Wextra ")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
find_library(SOIL REQUIRED)

include_directories(${SOIL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS}
        ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
set(SOURCE_FILES main.cpp
        Models/Player.cpp Models/Point.cpp Models/Polygon.cpp
        Views/PlayerView.cpp Views/WallView.cpp Views/ObstacleView.cpp Views/GroundView.cpp
        Views/MiscView.cpp Views/SkyView.cpp Views/HomeView.cpp Views/WineryView.cpp Utility/imageloader.cpp GameLogic.cpp Views/WeatherView.cpp Views/ForestView.cpp Views/ForestView.h)
add_executable(Proiect2 ${SOURCE_FILES})
target_link_libraries(Proiect2 SOIL ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})