cmake_minimum_required(VERSION 3.2.0)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED True)

## Build gatherWind application

# ensure deps.
# Curl4.

# Boost required 1.74 built by docker cmake Find sucks for boost.
# Note: another source dep built by docker is nlohmann json and it is expected
# to be installed in default locations e.g. /usr/include.
# Note: CURLPP is also required and is installed by docker build.
# Note: EIGEN is another required and is installed by docker build
# Note: Gnuplot iostream is another and is installed from source by docker build.
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS "-g")
set(GwName emergence)

project(${GwName})

FILE(GLOB GatherWindSrcs "./src/*.cpp")

add_executable(${GwName} ${GatherWindSrcs})

target_include_directories(${GwName} PRIVATE "./src/")

target_link_libraries(${GwName} PRIVATE "ncurses")

# copy config file needed for establishing json and csv archive directories.
#configure_file(../cfg/gatherWind.json ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

# install to /usr/bin
install(TARGETS ${GwName} 
    RUNTIME DESTINATION bin)
