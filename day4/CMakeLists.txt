# Add the source files for day4
add_library(day4 day4.cpp)

# Include the directory for header files
target_include_directories(day4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})