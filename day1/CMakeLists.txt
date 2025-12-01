# Add the source files for day1
add_library(day1 day1.cpp)

# Include the directory for header files
target_include_directories(day1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})