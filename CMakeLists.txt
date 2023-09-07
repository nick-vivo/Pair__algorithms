cmake_minimum_required(VERSION 3.27.4)

project(Pair CXX)

include_directories(include)

#Подключение своего модуля STL со string
add_subdirectory(modules/STL)

#pair
set(PAIR_LIB include/pair.h src/pair.cpp)
add_library(pair ${PAIR_LIB})
target_include_directories(pair PUBLIC modules/STL/include/)
target_link_libraries(pair string memory)

#main.cpp
add_executable(main main.cpp)
target_link_libraries(main pair)