#!/usr/bin/env bash

# Prepare submission
cp /autograder/submission/*.c /autograder/source/
cp /autograder/submission/pracexam2practice/*.c /autograder/source

# Remove extraneous files
cd /autograder/submission
find . -type f ! -name "*.c" ! -name "*.txt*" -exec rm {} \;

# Compile sources
cd /autograder/source
gcc -Wall -Werror=vla -std=c11 -o q1 q1.c
gcc -Wall -Werror=vla -std=c11 -o q2 main2.c
gcc -Wall -Werror=vla -std=c11 -o q3 q3.c
gcc -Wall -Werror=vla -std=c11 -o q3f main3.c