#pragma once
#include "common.h"
#include "AIPlayBook.h"

class TribeAIPlayBook : public AIPlayBook {
public:
    TribeAIPlayBook();

    // Virtuals (best-effort)
    virtual ~TribeAIPlayBook(); // vt[0] (0x0)
    virtual int convertTargetNameToIntType(char* param_1); // vt[1] (0x4)
    virtual int convertTargetCharacteristicNameToIntType(char* param_1); // vt[2] (0x8)
    virtual int convertUnitNameToIntType(char* param_1); // vt[3] (0xC)
    virtual int convertUnitToIntType(RGE_Static_Object* param_1); // vt[4] (0x10)

};
static_assert(sizeof(TribeAIPlayBook) == 0x50, "Size mismatch");
