# Add the source files for day3
add_library(day3 day3.cpp)

# Include the directory for header files
target_include_directories(day3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})