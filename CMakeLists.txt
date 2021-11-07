cmake_minimum_required(VERSION 3.0.0)
project(compression VERSION 0.1.0)

include(CTest)
enable_testing()
ADD_LIBRARY(LibsModule Tree.cpp Node.cpp Simple.cpp)
add_executable(compression main.cpp)
target_link_libraries(compression LibsModule)
add_test(main_test compression)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
