// VA: 00411480
// PDB-qualified owner: public: virtual int __thiscall
// AIPlayBook::convertTargetNameToIntType(char *) const
// PDB source: C:\msdev\work\age1_x1\aipbook.cpp, lines 1330-1334
// Body boundary: 00411480-004114D1; the next PDB owner starts at 004114E0.
// The 004114D2-004114DF bytes are alignment padding, not this function.
// BINARY NOTE: VC5's natural strcmp expression lowers to the shipped two-byte
// compare loop, including its signed result transform and fault order.

#include <string.h>

extern char s_Any[];

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayBook {
public:
    virtual int convertTargetNameToIntType(char *name) const;
};
#endif

int AIPlayBook::convertTargetNameToIntType(char *name) const {
    int r;
    r = strcmp(name, s_Any);
    if (r == 0) return 5;
    return 0;
}
