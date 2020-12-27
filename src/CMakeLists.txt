
add_subdirectory(common)
add_subdirectory(days)

# main
add_executable(Code main.cpp)

target_link_libraries(Code Utils Days)
#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/inputs")

