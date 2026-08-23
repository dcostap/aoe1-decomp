#include <stdlib.h>
#include <string.h>

// PDB owner: ?getstring@@YAXPAPADPAD@Z in mystring.cpp, lines 53-61.
// Boundary: 00462E30-00462E7B; the next symbol starts at 00462E80.
// BINARY NOTE: free, calloc, publication, and copy occur in this order.
// ORIGINAL BUG: a failed calloc is published before the copy faults.
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
