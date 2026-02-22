#include "../include/common.h"
#include "../include/mystring.h"
#include <stdlib.h>
#include <string.h>

// Fully verified. Source of truth: mystring.cpp.decomp @ 0x00462E30
void getstring(char** param_1, char* param_2) {
    size_t len = strlen(param_2) + 1;
    if (*param_1 != nullptr) {
        free(*param_1);
    }
    *param_1 = (char*)calloc(len, 1);
    memcpy(*param_1, param_2, len);
}

