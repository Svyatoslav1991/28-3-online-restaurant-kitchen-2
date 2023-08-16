cmake_minimum_required (VERSION 3.8)

project ("28-3-online-restaurant-kitchen-2")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(28-3-online-restaurant-kitchen "main.cpp" ${MY_INCLUDE_DIR}/functions.h  "functions.cpp")

target_include_directories(28-3-online-restaurant-kitchen PUBLIC ${CMAKE_SOURCE_DIR}/include)