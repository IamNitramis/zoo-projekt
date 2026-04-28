cmake_minimum_required(VERSION 3.20)

project(Projekt-zoo)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(Projekt-zoo main.cpp
        Input.cpp
        Input.h
        Renderer.cpp
        Renderer.h
        Menu.cpp
        Menu.h
        Hatch.cpp
        Hatch.h
        Module.cpp
        Module.h
        Station.cpp
        Station.h
        ModuleFactory.cpp
        ModuleFactory.h
        Position.h
)