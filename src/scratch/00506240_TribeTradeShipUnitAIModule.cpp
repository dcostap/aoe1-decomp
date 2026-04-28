// TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule
// VA: 00506240, taiuaimd.cpp:1804-1817
// Status: PARKED in scratch - VC5 constructor SEH frame generation
//
// Attempt log:
// v0: C++ constructor calling UnitAIModule base → 96 bytes, no SEH frame
// v1: Added /GX flag via config/flags/00506240_TribeTradeShipUnitAIModule.rsp → still 96 bytes
// v2: try/catch in constructor body → 160 bytes, heavy _CxxFrameHandler SEH with EBP frame
// v3: __try/__except(1) → similar heavy frame, different structure
// v4: Virtual base class approach → wrong offsets
// v5: Correct struct offsets with gap_04[0x120] → 96 bytes without SEH
//
// Remaining issue:
// The original function has a LIGHTWEIGHT constructor SEH frame (push -1, push handler,
// fs:[0] save/restore, add esp, 10h) that VC5 generates automatically for constructors
// with operator_new calls under /GX. But standalone compilation doesn't trigger this
// frame despite /GX flag. The try/catch approach generates a different (heavier) frame.
// Without the SEH frame, the function is 96 bytes vs required 168 bytes.
//
// TODO: To match this function, VC5 TU compilation context (/GX) must trigger the auto
// constructor SEH frame. This might require:
// - Moving the function to a compilation unit with /GX where other constructors also get SEH
// - Or finding the specific VC5 flag/condition that triggers the lightweight constructor frame

void* __cdecl operator_new(size_t size);

struct RGE_Static_Object;

struct UnitAIModule {
    int vfptr;           // +0x00
    char gap_04[0x120];  // +0x04 to +0x123

    UnitAIModule(RGE_Static_Object* obj, int category);
};

struct TribeTradeShipUnitAIModule : UnitAIModule {
    int* importantObjects;       // +0x124
    int numberImportantObjects;  // +0x128

    TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int category);
};

TribeTradeShipUnitAIModule::TribeTradeShipUnitAIModule(RGE_Static_Object* obj, int category)
    : UnitAIModule(obj, category) {
    int* buf;

    this->vfptr = 0x575F10;
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
