// TribeElephantUnitAIModule::TribeElephantUnitAIModule
// Constructor: calls base UnitAIModule(obj, category), sets vtable
// ret 8 = 2 params

struct RGE_Static_Object;

void __fastcall UnitAIModule_ctor(void*, int, RGE_Static_Object*, int);

struct TribeElephantUnitAIModule {
    int vfptr;
};

TribeElephantUnitAIModule* __fastcall TribeElephantUnitAIModule_ctor(TribeElephantUnitAIModule* self, int, RGE_Static_Object* obj, int category) {
    UnitAIModule_ctor(self, 0, obj, category);
    self->vfptr = 0x5759C8;
    return self;
}
