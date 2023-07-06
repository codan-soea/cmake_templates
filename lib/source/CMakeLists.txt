# Notice name prefix of this variable, set by CMake according
# to value given with "project()" in the root CMakeLists.txt.
include_directories(${PROJECT_SOURCE_DIR}/lib/include/)

add_library(lib io.cpp)
