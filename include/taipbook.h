// Compiler-facing declarations for the original taipbook.cpp module.
#ifndef AOE1_TAIPBOOK_H
#define AOE1_TAIPBOOK_H

#include "aiplaybook.h"

class TribeAIPlayBook : public AIPlayBook {
public:
    virtual ~TribeAIPlayBook();
    virtual int convertTargetNameToIntType(char* name) const;
    virtual int convertTargetCharacteristicNameToIntType(char* name) const;
    virtual int convertUnitNameToIntType(char* name) const;
    virtual int convertUnitToIntType(RGE_Static_Object* object) const;

    TribeAIPlayBook();
};

typedef char taipbook_tribe_size[(sizeof(TribeAIPlayBook) == 0x50) ? 1 : -1];

#endif
