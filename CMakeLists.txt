cmake_minimum_required(VERSION 3.28)
project(mandlebrot_explorer VERSION 0.0.1)



# build dependencies (vendor dir)

add_subdirectory(vendor)



# build main executable
file(GLOB SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME} PUBLIC ${SRC_FILES})
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

