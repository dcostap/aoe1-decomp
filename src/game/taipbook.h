#pragma once
#include "../common.h"

class TribeAIPlayBook : public AIPlayBook {
public:

    TribeAIPlayBook();
    virtual ~TribeAIPlayBook();
    virtual int convertTargetNameToIntType(char* param_1);
    virtual int convertTargetCharacteristicNameToIntType(char* param_1);
    virtual int convertUnitNameToIntType(char* param_1);
    virtual int convertUnitToIntType(RGE_Static_Object* param_1);
};

static_assert(sizeof(TribeAIPlayBook) == 0x50, "TribeAIPlayBook Size Mismatch");

