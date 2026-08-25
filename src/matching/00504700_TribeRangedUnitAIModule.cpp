#ifndef TAIUAIMD_COMPLETE_TU
#include "../../include/taiuaimd_context.h"

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object* obj, int category);
};
#endif

TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}
