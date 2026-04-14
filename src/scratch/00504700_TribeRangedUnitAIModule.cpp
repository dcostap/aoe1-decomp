// TribeRangedUnitAIModule::TribeRangedUnitAIModule
// Constructor: calls base UnitAIModule(obj, category), sets vtable
// ret 8 = 2 params

struct RGE_Static_Object;

void __fastcall UnitAIModule_ctor(void*, int, RGE_Static_Object*, int);

struct TribeRangedUnitAIModule {
    int vfptr;
};

TribeRangedUnitAIModule* __fastcall TribeRangedUnitAIModule_ctor(TribeRangedUnitAIModule* self, int, RGE_Static_Object* obj, int category) {
    UnitAIModule_ctor(self, 0, obj, category);
    self->vfptr = 0x575B88;
    return self;
}
