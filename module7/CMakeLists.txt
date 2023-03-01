cmake_minimum_required(VERSION 3.11)

project(MYBOOST CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC_LIST
    coroutines.cpp
)
# Find boost packages(eg. system, program_option, filesystem, regex etc...)
find_package(Boost COMPONENTS system program_options)
# Optional if you want to specific version or higher
set(BOOST_REQUESTED_VERSION 1.71)
# Optional include all directories
include_directories(${Boost_INCLUDE_DIRS}) 

add_executable(${PROJECT_NAME} ${SRC_LIST})

# Link your program with boost library
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})