// TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule
// VA: 005067D0, taiuaimd.cpp:2035-2045
// Status: PARKED in scratch - same VC5 constructor SEH frame challenge as 00506240
//
// Attempt log:
// v0: C++ constructor calling UnitAIModule base → 96 bytes, no SEH frame
// v1: try/catch wrapping whole body → 168 bytes, heavy _CxxFrameHandler SEH with EBP frame
// v2: try/catch wrapping only operator_new → 168 bytes, still heavy SEH frame
// v3: Virtual destructor hypothesis → not tested, would change vtable layout
//
// This function is structurally IDENTICAL to 00506240 TribeTradeShipUnitAIModule.
// Same SEH frame block: push -1, push handler (560CC8h vs 560CA8h), fs:[0], push ecx,
// add esp,10h, ret 8. Same body: base constructor call, vtable (575FF0h vs 575F10h),
// numberImportantObjects=5, operator_new(20), buffer init [3,22,20,2,21].
//
// VC5 auto constructor SEH frame not reproducible in standalone /GX compilation.
// See 00506240 notes for full analysis.

void* __cdecl operator_new(size_t size);

struct RGE_Static_Object;

struct UnitAIModule {
    int vfptr;           // +0x00
    char gap_04[0x120];  // +0x04 to +0x123

    UnitAIModule(RGE_Static_Object* obj, int category);
};

struct TribeTransportShipUnitAIModule : UnitAIModule {
    int* importantObjects;       // +0x124
    int numberImportantObjects;  // +0x128

    TribeTransportShipUnitAIModule(RGE_Static_Object* obj, int category);
};

TribeTransportShipUnitAIModule::TribeTransportShipUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    int* buf;

    this->vfptr = 0x575FF0;
    this->numberImportantObjects = 5;
    buf = (int*)operator_new(20);
    this->importantObjects = buf;
    if (buf != 0) {
        buf[0] = 3;
        buf[1] = 22;
        buf[2] = 20;
        buf[3] = 2;
        buf[4] = 21;
    }
}
