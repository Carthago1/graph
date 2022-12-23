cmake_minimum_required(VERSION 3.23)
project(main)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(GraphsLib)

target_include_directories(${PROJECT_NAME} PUBLIC ${GRAPHS_LIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} PRIVATE ${GRAPHS_LIB_LIBRARIES})

#add_executable(1 main.cpp GraphsLib/include/IGraph.h GraphsLib/include/ListGraph.h GraphsLib/include/MatrixGraph.h GraphsLib/include/SetGraph.h GraphsLib/include/ArcGraph.h GraphsLib/src/ArcGraph.cpp GraphsLib/src/ListGraph.cpp GraphsLib/src/MatrixGraph.cpp GraphsLib/src/SetGraph.cpp)

#add_executable(main.cpp)

