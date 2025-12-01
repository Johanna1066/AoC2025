# adventOfCode2024

https://adventofcode.com/2025/


# Usage

the X below represent the number of the day you want to run.

1. go to CMakeLists and add the subdirectories and link the libraries for day X.

2. Go to main cpp and uncomment the #include "dayX/dayX.h" and write dayX(); in main().

3. Paste your indata in dayX/inputDayX.txt

4.  In a WSL terminal run the following commands to make, build, and run the code
    - mkdir build
    - cd build
    - cmake ..
    - cmake -build .
    - ./AoC
