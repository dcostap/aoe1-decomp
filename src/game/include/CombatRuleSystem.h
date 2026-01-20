#pragma once
#include "common.h"

class CombatRuleSystem {
public:
    // Virtuals (best-effort)
    virtual ~CombatRuleSystem(); // vt[0] (0x0)

    uchar ratingValue[2500];
};
static_assert(sizeof(CombatRuleSystem) == 0x9C8, "Size mismatch");
