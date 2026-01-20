#pragma once
#include "common.h"

class AIPlayBook {
public:
    // Virtuals (best-effort)
    virtual ~AIPlayBook(); // vt[0] (0x0)
    virtual int convertTargetNameToIntType(char* param_1); // vt[1] (0x4)
    virtual int convertTargetCharacteristicNameToIntType(char* param_1); // vt[2] (0x8)
    virtual int convertUnitNameToIntType(char* param_1); // vt[3] (0xC)
    virtual int convertUnitToIntType(RGE_Static_Object* param_1); // vt[4] (0x10)

    int numberPlaysValue;
    char nameValue[65];
    AIPlay* plays;
};
static_assert(sizeof(AIPlayBook) == 0x50, "Size mismatch");
