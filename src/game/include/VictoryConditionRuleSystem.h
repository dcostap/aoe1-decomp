#pragma once
#include "common.h"

class VictoryConditionRuleSystem {
public:
    // Virtuals (best-effort)
    virtual ~VictoryConditionRuleSystem(); // vt[0] (0x0)

    int sn[226];
};
static_assert(sizeof(VictoryConditionRuleSystem) == 0x38C, "Size mismatch");
