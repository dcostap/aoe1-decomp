// VA: 00411480 AIPlayBook::convertTargetNameToIntType (82 bytes, 37 asm lines)
// Compares name against "Any", returns 5 if match, 0 otherwise.

#include <string.h>

extern char s_Any[];

class AIPlayBook {
public:
    int convertTargetNameToIntType(char *name) const;
};

int AIPlayBook::convertTargetNameToIntType(char *name) const {
    int r;
    r = strcmp(name, s_Any);
    if (r == 0) return 5;
    return 0;
}
