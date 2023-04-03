cmake_minimum_required(VERSION 3.2)
project(graphics)

# Set normal compiler flags
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-deprecated -Wall")

# Chapter to compile
set(CHAPTER "chpt2")

# Checks to see if git is present
find_package(Git REQUIRED)

# Initialize the submodule if not already done so
if(NOT EXISTS lib/SDL/CMakeLists.txt)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            COMMAND_ERROR_IS_FATAL ANY)
endif()

set(BUILD_SHARED_LIBS OFF)

add_subdirectory(lib/SDL2)
set(SDL2_INCLUDE_DIRS lib/SDL2/include)
set(SDL2_LIBRARIES SDL2-static)

add_subdirectory(lib/SDL2_image)
set(SDL2_IMAGE_INCLUDE_DIRS lib/SDL2_image)
set(SDL2_IMAGE_LIBRARIES SDL2_image)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})

# Set the project files
file(GLOB PROJECT_HEADERS "src/${CHAPTER}/*.h")
file(GLOB PROJECT_SOURCES "src/${CHAPTER}/*.c")

source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})

# Link SDL to the executable
target_link_libraries(${PROJECT_NAME} 
                      ${SDL2_LIBRARIES}
                      ${SDL2_IMAGE_LIBRARIES})