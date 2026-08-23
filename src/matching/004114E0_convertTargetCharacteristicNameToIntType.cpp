// VA: 004114E0 AIPlayBook::convertTargetCharacteristicNameToIntType (355 bytes, 157 asm lines)
// PDB owner: AIPlayBook::convertTargetCharacteristicNameToIntType(char*) const
// PDB source: aipbook.cpp, lines 1339-1348; body boundary: 004114E0-0041164F.
// The five strcmp results own returns 1..5. Unknown input returns 0.
// String-to-int conversion for characteristic names: Stationary=1, Moving=2, Slow=3, Fast=4, Any=5

#include <string.h>

extern char s_Stationary[];
extern char s_Moving[];
extern char s_Slow[];
extern char s_Fast[];
extern char s_Any[];

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayBook {
public:
    virtual int convertTargetCharacteristicNameToIntType(char *name) const;
};
#endif

int AIPlayBook::convertTargetCharacteristicNameToIntType(char *name) const {
    int r;
    r = strcmp(name, s_Stationary);
    if (r == 0) return 1;
    r = strcmp(name, s_Moving);
    if (r == 0) return 2;
    r = strcmp(name, s_Slow);
    if (r == 0) return 3;
    r = strcmp(name, s_Fast);
    if (r == 0) return 4;
    r = strcmp(name, s_Any);
    if (r == 0) return 5;
    return 0;
}
