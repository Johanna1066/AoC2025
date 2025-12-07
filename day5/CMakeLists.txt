# Add the source files for day5
add_library(day5 day5.cpp)

# Include the directory for header files
target_include_directories(day5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})