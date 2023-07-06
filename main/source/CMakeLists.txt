include_directories(${PROJECT_SOURCE_DIR}/main/include)

#Assumption is that lib to be used as a library in main!
include_directories(${PROJECT_SOURCE_DIR}/lib/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/source)

add_executable(main main.cpp)

target_link_libraries(main lib)
