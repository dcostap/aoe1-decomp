class RGE_Static_Object;

class UnitAIModule {
public:
    int vfptr;

    UnitAIModule(RGE_Static_Object* obj, int category);
};

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object* obj, int category);
};

TribeRangedUnitAIModule::TribeRangedUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    this->vfptr = 0x575B88;
}
