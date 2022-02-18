cmake_minimum_required(VERSION 3.14)

project(
  AlphaBetaTicTacToe
  VERSION 1.0
  LANGUAGES CXX
)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif()

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-Wall -std=c++17")

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC src/*.cpp)

add_subdirectory(test)
add_subdirectory(lib/googletest)
add_subdirectory(demo)

add_executable(${PROJECT_NAME} ${SRC})
add_library(${PROJECT_NAME}_lib STATIC ${SRC})

add_custom_target(valgrind
	COMMAND valgrind ./${PROJECT_NAME}
	DEPENDS ${PROJECT_NAME}
)

add_custom_target(test
	COMMAND ./test/${PROJECT_NAME}_test
	DEPENDS test/${PROJECT_NAME}_test
)
