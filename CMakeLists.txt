cmake_minimum_required(VERSION 3.5)

project(Qonsole VERSION 0.1 LANGUAGES CXX)
set(LIBRARY_COMPILE TRUE)

if(NOT LIBRARY_COMPILE)
	set(CMAKE_AUTOUIC ON)
	set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTORCC ON)

        set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

set (EXAMPLES
    example/main.cpp
    example/example.qrc
)

set(PROJECT_SOURCES
    include/qonsole.qrc
    include/Qonsole/debug.hpp

    src/debug.cpp
    src/debug_p.hpp
)

if(LIBRARY_COMPILE)
    add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
else()
    add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${EXAMPLES})
endif()

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(Qonsole PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Quick
)
