#ifndef TAIUAIMD_COMPLETE_TU
#include "../../include/taiuaimd_context.h"

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* obj, int category);
};
#endif

TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}
