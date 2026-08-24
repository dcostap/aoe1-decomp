// Attempt log:
// v1: manual byte loop; completely wrong
// v2: strcpy in if/else - body matches but branch inverted (je vs jne)
// v3: ternary operator - try to get null case at end with je
#include <string.h>

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    char gap_00[0x1C];
    char path[260];

    void set_path(char* param_1);
};
#endif

void TSound_Driver::set_path(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->path, param_1);
    } else {
        this->path[0] = 0;
    }
}
