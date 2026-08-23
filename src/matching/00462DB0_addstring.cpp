// PDB: mystring.cpp:35-49; qualified owner: ?addstring@@YAXPAPADPAD1@Z.
// Boundary: 00462DB0-00462E2D, after unconvert_us 00462D90-00462DAA.
// Exact finish: strict positional match, 125/125 bytes, 0.0000% diff.
// Natural C++: strlen two strings, calloc, memcpy twice, free+store.
#include <stdlib.h>
#include <string.h>

void addstring(char** param_1, char* param_2, char* param_3) {
    unsigned int len1, len2;
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
