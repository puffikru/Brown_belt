project(courses_tests)

add_subdirectory(basic_tests)
add_subdirectory(lib/googletest-master)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)
#include_directories(basic_tests)
set_target_properties(courses_test PROPERTIES
        INCLUDE_DIRECTIORIES ${Gtest_INCLUDE_DIR}
)