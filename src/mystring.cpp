
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>

void convert_us(char* str) {
    while (*str != '\0') {
        if (*str == '_') {
            *str = ' ';
        }
        str = str + 1;
    }
}

void unconvert_us(char* str) {
    while (*str != '\0') {
        if (*str == ' ') {
            *str = '_';
        }
        str = str + 1;
    }
}

void addstring(char** param_1, char* param_2, char* param_3) {
    unsigned int len1;
    unsigned int len2;
    char* dst;

    len1 = strlen(param_2);
    len2 = strlen(param_3);
    dst = (char*)calloc(len1 + len2 + 1, 1);
    memcpy(dst, param_2, len1);
    memcpy(dst + len1, param_3, len2);

    if (*param_1 != 0) {
        free(*param_1);
    }
    *param_1 = dst;
}

// The old value is freed before allocation and publication.
// A failed calloc is published before the copy faults.
void getstring(char** param_1, char* param_2) {
    unsigned int len;
    char* dst;

    len = (unsigned int)strlen(param_2) + 1;
    if (*param_1 != 0) {
        free(*param_1);
    }

    dst = (char*)calloc(len, 1);
    *param_1 = dst;
    memcpy(dst, param_2, len);
}
