cmake_minimum_required(VERSION 3.0.0)
project(groovy_builder VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.76)
find_package( GTest REQUIRED )      

INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})


include(CTest)
enable_testing()
add_library(libs SHARED Person.cpp PersonBuilder.cpp )
add_executable(groovy_builder main.cpp)
target_link_libraries(groovy_builder LINK_PUBLIC libs ${GTEST_LIBRARIES} ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
