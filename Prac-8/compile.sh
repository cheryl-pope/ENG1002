#!/usr/bin/env bash

# Prepare submission
cp /autograder/submission/*.c /autograder/source/
cp /autograder/submission/week9practice/*.c /autograder/source

cd /autograder/source

gcc -Wall -Werror=vla -std=c11 -o temperatures01 temperatures01.c
gcc -Wall -Werror=vla -std=c11 -o odds_evens01 odds_evens01.c
gcc -Wall -Werror=vla -std=c11 -o temperatures02 temperatures02.c