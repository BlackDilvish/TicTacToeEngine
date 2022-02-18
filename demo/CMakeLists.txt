set(BINARY ${PROJECT_NAME}_demo)

file(GLOB_RECURSE DEMO_SOURCES LIST_DIRECTORIES false *.h *.cpp)
set(SOURCES ${DEMO_SOURCES})

add_executable(${BINARY} ${DEMO_SOURCES})
target_link_libraries(${BINARY} PUBLIC ${PROJECT_NAME}_lib)