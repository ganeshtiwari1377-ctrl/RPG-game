cmake_minimum_required(VERSION 3.16)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/ganes/OneDrive/Documents/coding/.vscode/projects/SFML-3.1.0-windows-vc17-64-bit/SFML-3.1.0/lib/cmake/SFML")
find_package(SFML 3.1 COMPONENTS Graphics Window System REQUIRED)

add_executable(MyGame main.cpp)
target_link_libraries(MyGame PRIVATE SFML::Graphics SFML::Window SFML::System)