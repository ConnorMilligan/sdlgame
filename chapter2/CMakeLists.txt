cmake_minimum_required(VERSION 3.2)
project(graphics)

# Set normal compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated -Werror=return-type")

# Checks to see if git is present
find_package(Git REQUIRED)

# Initialize the submodule if not already done so
if(NOT EXISTS lib/SDL/CMakeLists.txt)
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive -- ${dir}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            COMMAND_ERROR_IS_FATAL ANY)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR})

# Set the project files
file(GLOB PROJECT_HEADERS src/*.h)
file(GLOB PROJECT_SOURCES src/*.cpp)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)


source_group("Headers" FILES ${PROJECT_HEADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})

# Build the source files
add_executable(${PROJECT_NAME} 
               ${PROJECT_SOURCES} 
               ${PROJECT_HEADERS} 
               ${PROJECT_CONFIGS})

# Link SDL to the executable
target_link_libraries(${PROJECT_NAME} 
                      ${SDL2_LIBRARY}
                      ${SDL2_IMAGE_LIBRARIES}
                      ${SDL2_TTF_LIBRARIES})