#ifndef TAIUAIMD_COMPLETE_TU
#include "../../include/taiuaimd_context.h"

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category);
};
#endif

TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}
