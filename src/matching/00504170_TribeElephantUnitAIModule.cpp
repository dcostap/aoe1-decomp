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

TribeElephantUnitAIModule::TribeElephantUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    this->vfptr = 0x5759C8;
}
