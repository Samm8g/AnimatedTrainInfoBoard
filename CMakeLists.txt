cmake_minimum_required(VERSION 3.16)
project(AnimatedTrainInfoBoard)

set(CMAKE_CXX_STANDARD 20)

# Find Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(AnimatedTrainInfoBoard
    main.cpp
    sideboard.cpp
    maindisplayboard.cpp
    mainwindow.cpp
)

# Link to Qt
target_link_libraries(AnimatedTrainInfoBoard PRIVATE Qt6::Widgets)
