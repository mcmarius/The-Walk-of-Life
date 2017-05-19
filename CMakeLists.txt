cmake_minimum_required(VERSION 3.7)
project(The-Walk-of-Life)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wpedantic -Wextra ")

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

# this file will be added to .gitignore (these paths are context-sensitive)
set(SOIL_INCLUDE_DIR "C:/MinGW/include/GL")
set(GLM_INCLUDE_DIR "C:/Users/marius/Documents/facultate/anul_II/sem_II/gc/lib/glm")

include_directories(${SOIL_INCLUDE_DIR} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIR})
set(SOURCE_FILES main.cpp
        Models/Player.cpp Models/Player.h
        Views/PlayerView.cpp Views/WallView.cpp Views/ObstacleView.cpp Views/GroundView.cpp Views/MiscView.cpp Views/SkyView.cpp Views/HomeView.cpp Views/WineryView.cpp)
add_executable(Proiect2 ${SOURCE_FILES})
target_link_libraries(Proiect2 soil ${SOIL_LIBRARY} ${GLEW_LIBRARIES} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})