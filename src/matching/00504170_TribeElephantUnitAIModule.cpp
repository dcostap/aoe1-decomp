#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Static_Object;

class UnitAIModule {
public:
    int vfptr;

    UnitAIModule(RGE_Static_Object* obj, int category);
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* obj, int category);
};
#endif

#ifdef TAIUAIMD_COMPLETE_TU
TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}
#else
TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    this->vfptr = 0x5759C8;
}
#endif
