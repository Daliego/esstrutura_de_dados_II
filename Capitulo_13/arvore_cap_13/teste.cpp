#include "stdio.h"
#include <ctype.h>

int is_a_operator(char string) {
    switch (string) {
        case ('-'):
            return 1;
        case ('+'):
            return 1;
        case ('/'):
            return 1;
        case ('*'):
            return 1;
        default:
            return 0;
    }
}

int main() {
    int number = '+';

    printf("is a operator (true, false): %i", is_a_operator(number));
}