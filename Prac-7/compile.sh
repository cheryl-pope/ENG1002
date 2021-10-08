#!/usr/bin/env bash

# Prepare submission
cp /autograder/submission/*.c /autograder/source/
cp /autograder/submission/week9practice/*.c /autograder/source

cd /autograder/source

gcc -Wall -Werror=vla -std=c11 -o odd_evens odd_evens.c
gcc -Wall -Werror=vla -std=c11 -o process_ages process_ages.c
gcc -Wall -Werror=vla -std=c11 -o to_uppercase to_uppercase.c
gcc -Wall -Werror=vla -std=c11 -o to_uppercase2 to_uppercase2.c
gcc -Wall -Werror=vla -std=c11 -o reverse_in_place reverse_in_place.c