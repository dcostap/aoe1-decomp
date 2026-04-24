#include <stdlib.h>
#include <string.h>

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
