// TribeRangedUnitAIModule2::TribeRangedUnitAIModule2
// Constructor: calls base UnitAIModule(obj, category), sets vtable
// ret 8 = 2 params

struct RGE_Static_Object;

void __fastcall UnitAIModule_ctor(void*, int, RGE_Static_Object*, int);

struct TribeRangedUnitAIModule2 {
    int vfptr;
};

TribeRangedUnitAIModule2* __fastcall TribeRangedUnitAIModule2_ctor(TribeRangedUnitAIModule2* self, int, RGE_Static_Object* obj, int category) {
    UnitAIModule_ctor(self, 0, obj, category);
    self->vfptr = 0x575C68;
    return self;
}
