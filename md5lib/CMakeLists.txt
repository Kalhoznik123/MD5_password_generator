cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(md5lib LANGUAGES CXX)

add_library(md5lib STATIC md5.cpp md5.h)
