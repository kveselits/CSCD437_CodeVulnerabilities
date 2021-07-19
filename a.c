//
// Created by kjuli on 7/18/2021.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int foo(char *arg, char *out) {
    //Missing #include <string.h>
    // Vulnerability: input buffer copied to output without checking size of input < output
    strcpy(out, arg);
    return 0;

}

int main(int argc, char *argv[]) {
    char buf[64];
    if (argc != 2) {
        //Missing #include <stdio.h>
        fprintf(stderr, "a: argc != 2\n");
        //Missing #include <stdlib.h>
        exit(EXIT_FAILURE);
    }// end if
    foo(argv[1], buf);
    return 0;
}// end main

/*
./a.c:11:  [4] (buffer) strcpy:
Does not check for buffer overflows when copying to destination [MS-banned]
        (CWE-120). Consider using snprintf, strcpy_s, or strlcpy (warning: strncpy
        easily misused).
./a.c:17:  [2] (buffer) char:
Statically-sized arrays can be improperly restricted, leading to potential
overflows or other issues (CWE-119!/CWE-120). Perform bounds checking, use
        functions that limit length, or ensure that the size is larger than the
        maximum possible length.*/
