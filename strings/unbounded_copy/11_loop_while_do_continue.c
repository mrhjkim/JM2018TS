#include <stdio.h>
#include <string.h>
#include "string_copy.h"

void string_copy_do_while_continue(int x) {
    char long_string[22];
    char short_string[13];
    char* to_print = short_string;
    int i = 0;

#ifdef CATCH_BAD_PARAM
    if(x < 10) {
        return;
    }
#endif

    do {
        if(i > x) {
            strcpy(to_print, "this is a long string"); /* DANGER: x < 10 */
        } else {
            strcpy(to_print, "short string");
        }
        if(i == 10) {
            to_print = long_string;
        }
        printf("val = %s\n", to_print);
        i++;
        if(i < 20) {
            continue;
        }
    } while(i < 30);
}

#ifndef NO_MAIN
int main() {
#ifdef NO_BUG
    string_copy_do_while_continue(10);
#else
    string_copy_do_while_continue(9);
#endif

    return 1;
}
#endif
