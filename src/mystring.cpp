
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>

void convert_us(char* string) {
    while (*string != '\0') {
        if (*string == '_') {
            *string = ' ';
        }
        string = string + 1;
    }
}

void unconvert_us(char* string) {
    while (*string != '\0') {
        if (*string == ' ') {
            *string = '_';
        }
        string = string + 1;
    }
}

void addstring(char** out, char* first, char* last) {
    unsigned int first_length;
    unsigned int last_length;
    char* dst;

    first_length = strlen(first);
    last_length = strlen(last);
    dst = (char*)calloc(first_length + last_length + 1, 1);
    memcpy(dst, first, first_length);
    memcpy(dst + first_length, last, last_length);

    if (*out != 0) {
        free(*out);
    }
    *out = dst;
}

// The old value is freed before allocation and publication.
// A failed calloc is published before the copy faults.
void getstring(char** out, char* in) {
    unsigned int len;
    char* dst;

    len = (unsigned int)strlen(in) + 1;
    if (*out != 0) {
        free(*out);
    }

    dst = (char*)calloc(len, 1);
    *out = dst;
    memcpy(dst, in, len);
}
