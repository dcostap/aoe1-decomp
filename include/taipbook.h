// Compiler-facing declarations for the original taipbook.cpp module.
#ifndef AOE1_TAIPBOOK_H
#define AOE1_TAIPBOOK_H

#include "aiplaybook.h"

class TribeAIPlayBook : public AIPlayBook {
  public:
    virtual ~TribeAIPlayBook();
    virtual int convertTargetNameToIntType(char* t) const;
    virtual int convertTargetCharacteristicNameToIntType(char* t) const;
    virtual int convertUnitNameToIntType(char* t) const;
    virtual int convertUnitToIntType(RGE_Static_Object* obj) const;

    TribeAIPlayBook();
};

typedef char taipbook_tribe_size[(sizeof(TribeAIPlayBook) == 0x50) ? 1 : -1];

#endif
