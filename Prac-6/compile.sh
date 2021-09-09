#!/usr/bin/env bash

# Prepare submission
cp /autograder/submission/week8practice/*.c /autograder/source/

cd /autograder/source

gcc gcc -Wall -Werror=vla -std=c11 -o err1 err1.c
gcc gcc -Wall -Werror=vla -std=c11 -o err2 err2.c
gcc gcc -Wall -Werror=vla -std=c11 -o err3 err3.c
gcc gcc -Wall -Werror=vla -std=c11 -o form_letter form_letter.c
gcc gcc -Wall -Werror=vla -std=c11 -o digits digits.c
gcc gcc -Wall -Werror=vla -std=c11 -o education education.c
gcc gcc -Wall -Werror=vla -std=c11 -o months months.c