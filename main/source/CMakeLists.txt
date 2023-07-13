include_directories(${PROJECT_SOURCE_DIR}/main/include)

#Assumption is that lib to be used as a library in main!
include_directories(${PROJECT_SOURCE_DIR}/lib/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/source)

## load in pkg-config support
find_package(PkgConfig)
## use pkg-config to get hints for 0mq locations
pkg_check_modules(PC_ZeroMQ QUIET zmq)
## use the hint from above to find where 'zmq.hpp' is located
find_path(ZeroMQ_INCLUDE_DIR
        NAMES zmq.hpp
        PATHS ${PC_ZeroMQ_INCLUDE_DIRS}
        )
## use the hint from above to find the location of libzmq
find_library(ZeroMQ_LIBRARY
        NAMES zmq
        PATHS ${PC_ZeroMQ_LIBRARY_DIRS}
        )
set(SOURCE_FILES main.cpp)
add_executable(main ${SOURCE_FILES})

target_include_directories(main PUBLIC ${ZeroMQ_INCLUDE_DIR})
target_link_libraries(main PRIVATE lib PUBLIC ${ZeroMQ_LIBRARY})
