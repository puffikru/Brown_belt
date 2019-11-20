#include_directories(${gtest_SOURSE_DIR/include}/include ${gtest_SOURSE_DIR})
#include_directories(../lib/googletest-master/googletest/include)
#include_directories(../lib/googletest-master/googlemock/include)
include_directories(../../set_iterator)
project(basic_tests)

add_executable(runBasicTests
    basic_check.cpp
)

target_link_libraries(runBasicTests gtest gtest_main)
#target_link_directories(runBasicTests basic_check.cpp)
#target_link_libraries(runBasicTests courses)