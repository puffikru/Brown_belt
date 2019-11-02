cmake_minimum_required(VERSION 3.8)

if ($ENV{TRAVIS_BUILD_NUMBER})
    project(Brown VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ($ENV{TRAVIS_BUILD_NUMBER})
    project(Brown VERSION 0.0.1)
endif ($ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")

add_subdirectory(hash_set)
add_subdirectory(point)
add_subdirectory(set_iterator)

install(TARGETS ${hash} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")

set(CPACK_PACKAGE_CONTACT igorbulakh1987@yandex.ru)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)
