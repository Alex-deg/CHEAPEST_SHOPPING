cmake_minimum_required(VERSION 3.10)
project(CHEAPEST_SHOPPING)

find_package(CURL REQUIRED)

find_package(xml2 REQUIRED)

set(SOURCES main.cpp)

#set(HEADERS )

add_executable(CHEAPEST_SHOPPING ${SOURCES})
target_link_libraries(CHEAPEST_SHOPPING curl xml2)