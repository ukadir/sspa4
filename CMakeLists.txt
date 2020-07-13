cmake_minimum_required(VERSION 3.1)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(MyProject VERSION 1.0
                  DESCRIPTION "Very nice project"
                  LANGUAGES CXX)

enable_testing() # Must be in main file
include(AddGoogleTest) # Could be in /tests/CMakeLists.txt

add_executable(SetTest)
add_gtest(SetTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage -fprofile-arcs -ftest-coverage -std=c++11")

add_custom_target(cov COMMAND ${CMAKE_CURRENT_LIST_DIR}/build_scripts/generate_coverage_report -r "make" "make test")
add_custom_target(SetTest DEPENDS ${ArrayListSet.cpp, HashTableSet.cpp, LinkedListSet.cpp MultiwayTrieSet.cpp, RedBlackTreeSet.cpp SetTest.cpp Set.h})

# Make sure build_scripts are always runnable
add_custom_target(chmod COMMAND chmod +x ${CMAKE_CURRENT_LIST_DIR}/build_scripts/*)
add_dependencies(cov chmod)