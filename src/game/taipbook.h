#pragma once
#include "common.h"

class TribeAIPlayBook : public AIPlayBook {
public:

    virtual int convertTargetNameToIntType(char* param_1);  // vt0[1]+0x4=0x4E6900
    virtual int convertTargetCharacteristicNameToIntType(char* param_1); // vt0[2]+0x8=0x4E6910
    virtual int convertUnitNameToIntType(char* param_1);    // vt0[3]+0xC=0x4E6920
    virtual int convertUnitToIntType(RGE_Static_Object* param_1); // vt0[4]+0x10=0x4E6AD0
    TribeAIPlayBook();
    ~TribeAIPlayBook();
};

static_assert(sizeof(TribeAIPlayBook) == 0x50, "TribeAIPlayBook Size Mismatch");

