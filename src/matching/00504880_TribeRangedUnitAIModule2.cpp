#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Static_Object;

class UnitAIModule {
public:
    int vfptr;

    UnitAIModule(RGE_Static_Object* obj, int category);
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category);
};
#endif

#ifdef TAIUAIMD_COMPLETE_TU
TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {}
#else
TribeRangedUnitAIModule2::TribeRangedUnitAIModule2(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    this->vfptr = 0x575C68;
}
#endif
