#!/usr/bin/env bash

# Prepare submission
cp /autograder/submission/*.c /autograder/source/

cd /autograder/source

gcc -Wall -Werror=vla -std=c11 -o err1 err1.c
gcc -Wall -Werror=vla -std=c11 -o err2 err2.c
gcc -Wall -Werror=vla -std=c11 -o err3 err3.c
gcc -Wall -Werror=vla -std=c11 -o temp temp.c
gcc -Wall -Werror=vla -std=c11 -o form_letter form_letter.c
gcc -Wall -Werror=vla -std=c11 -o digits digits.c
gcc -Wall -Werror=vla -std=c11 -o education education.c
gcc -Wall -Werror=vla -std=c11 -o months months.c