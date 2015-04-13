# Build Code
g++ -Wall -Wextra -O0 -g -Isrc  -o Build/debug/./src/main.o -c -MMD -MP -MF Build/debug/./src/main.d src/main.cpp