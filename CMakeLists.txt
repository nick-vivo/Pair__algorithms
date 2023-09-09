cmake_minimum_required(VERSION 3.27.4)

project(Pair CXX)

include_directories(include)

#pair
set(PAIR_LIB include/pair.h src/pair.cpp)
add_library(pair ${PAIR_LIB})
target_link_libraries(pair)

#tests
add_subdirectory(modules/googletest)
set(TESTS_INCLUDE modules/googletest/googlemock/include modules/googletest/googletest/include)

#TEST_PAIR
set(TEST_PAIR_EXE tests/gtest_pair.cpp)
add_executable(gtest_pair ${TEST_PAIR_EXE})
target_include_directories(gtest_pair PUBLIC ${TESTS_INCLUDE})
target_link_libraries(gtest_pair gmock gmock_main gtest gtest_main pair)
