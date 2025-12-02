# Add the source files for day2
add_library(day2 day2.cpp)

# Include the directory for header files
target_include_directories(day2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})