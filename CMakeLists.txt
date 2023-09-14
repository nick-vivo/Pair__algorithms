cmake_minimum_required(VERSION 3.27.4)

project(Pair CXX)

include_directories(include)

#pair
set(PAIR_LIB include/pair.h src/pair.cpp)
add_library(pair ${PAIR_LIB})
target_link_libraries(pair)

#array
set(ARRAY_LIB include/array.h src/array.cpp)
add_library(array ${ARRAY_LIB})
target_link_libraries(array)

#container
set(CONTAINER_PAIR_LIB include/container_pair.h src/container_pair.cpp)
add_library(container_pair ${ARRAY_LIB})
target_link_libraries(container_pair array pair)

option(TEST "Enable testing" OFF)

if (TEST)
    #tests
    add_subdirectory(modules/googletest)
    set(TESTS_INCLUDE modules/googletest/googlemock/include modules/googletest/googletest/include)

    #TEST_PAIR
    set(TEST_PAIR_EXE tests/gtest_pair.cpp)
    add_executable(gtest_pair ${TEST_PAIR_EXE})
    target_include_directories(gtest_pair PUBLIC ${TESTS_INCLUDE})
    target_link_libraries(gtest_pair gmock gmock_main gtest gtest_main pair)

    #TEST_ARRAY
    set(TEST_ARRAY_EXE tests/gtest_array.cpp)
    add_executable(gtest_array ${TEST_ARRAY_EXE})
    target_include_directories(gtest_array PUBLIC ${TESTS_INCLUDE})
    target_link_libraries(gtest_array gmock gmock_main gtest gtest_main array)


    #TEST_CONTAINER
    set(TEST_CONTAINER_EXE tests/gtest_container.cpp)
    add_executable(gtest_container ${TEST_CONTAINER_EXE})
    target_include_directories(gtest_container PUBLIC ${TESTS_INCLUDE})
    target_link_libraries(gtest_container gmock gmock_main gtest gtest_main container_pair)
endif()
    