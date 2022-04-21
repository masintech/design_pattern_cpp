cmake_minimum_required(VERSION 3.0.0)
project(singlton VERSION 0.1.0)
find_package(Boost 1.76)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )


include(CTest)
enable_testing()

add_executable(singlton main.cpp)
target_link_libraries(singlton LINK_PUBLIC ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
