cmake_minimum_required(VERSION 3.23)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(GraphsLib)

target_include_directories(${PROJECT_NAME} PUBLIC ${GRAPHS_LIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${GRAPHS_LIB_LIBRARIES})

