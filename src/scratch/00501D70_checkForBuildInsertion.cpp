// VA: 00501D70 TribeTacticalAIModule::checkForBuildInsertion(int,int,int)
// FLAGS: config/flags/00501D70_checkForBuildInsertion.rsp (/GX)
// Attempt log:
// 1: natural decompiler source with ResourceItem ctor/dtor and typed member calls; /GX required for EH frame.
// 2: /GX /Oy compiled but .text 752B too small vs original 814B; no-/GX even smaller (704B).
// 3: no-/Oy probe also 752B; original needs EH but source/control-flow still too compact.
// 4: rewrote top-level dispatch as `if (id != 0x32) { 44/4f } else { 32 }`; recovered same-size 814B but frame became 0xE8 vs original 0x78 and broad drift.
// 5: original dispatch is `cmp 32 je later; cmp 44 je middle; cmp 4f inline`; source order can recover size but not EH stack layout.
// 6: removed forbidden raw `__thiscall` vtable cast; modeled BuildAI vtable slot +0x48 with padded virtual method.
// 7: used raw MD offset macros (+0x104 buildAI, +0x10D7C resourceAI, +0x1256C aiPlayer, +0x122C closestDropsite) after typed MasterData gap produced invalid negative layout.
// 8: ResourceItem size 0x70 and /GX produce EH prologue with handler 00560BB0; call set/cleanup broadly plausible.
// 9: no-/GX is definitely wrong (704B, too small), /GX is required; custom flag retained.
// 10: left in scratch: best same-size check is 79.7297% positional / 104.0541% edit; first mismatch offset 25 at EH frame allocation (`sub esp,78h` vs `sub esp,0E8h`) and broad block order drift, not accepted-drift-safe.

typedef unsigned char uchar;

class ResourceItem {
public:
    char data[0x70];
    ResourceItem(int n);
    ~ResourceItem();
    int value(int i);
    void setValue(int i, int v);
};

class TRIBE_Player { public: void objectCost(int id, int a, ResourceItem* r, int b); int objectAvailable(int id); };
class TribeResourceAIModule { public: int resourcesAvailable(ResourceItem* r); };
#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_a)
#define VPAD4(n) VPAD2(n) VPAD2(n##_b)
#define VPAD8(n) VPAD4(n) VPAD4(n##_c)
#define VPAD16(n) VPAD8(n) VPAD8(n##_d)
class TribeBuildAIModule { public: VPAD16(b0) VPAD1(b16) VPAD1(b17) virtual int countQueued(int id, int zero); int insert(int id, int n, int priority); int allBuilt(int a, int b); };
class TribeTacticalAIModule {
public:
    char gap[0x510];
    int numberAvailableGranaries(int* unbuilt, int* granaries);
    int inAge(int age);
    void checkForBuildInsertion(int id, int count, int priority);
};

#define MD (*(char**)((char*)this+0xF0))
#define BUILD ((TribeBuildAIModule*)(MD+0x104))
#define RESAI ((TribeResourceAIModule*)(MD+0x10D7C))
#define AIPLAYER (*(TRIBE_Player**)(MD+0x1256C))
#define CLOSEST (*(int*)(MD+0x122C))
#define SN_A3 (*(int*)((char*)this+0x420))
#define SN_DC (*(int*)((char*)this+0x504))
#define SN_DE (*(int*)((char*)this+0x50C))
#define FLAG_44 (*(int*)((char*)this+0x4C8))
#define FLAG_32 (*(int*)((char*)this+0x4CC))
#define FLAG_4F (*(int*)((char*)this+0x4D0))

void TribeTacticalAIModule::checkForBuildInsertion(int id, int count, int priority)
{
    if (id != 0x32) {
    if (id == 0x44) {
        if (FLAG_44 == 1 && CLOSEST != -1) {
            int unbuilt = 0;
            int granaries = 0;
            int n = this->numberAvailableGranaries(&unbuilt, &granaries);
            if (granaries <= 0 && n > 0 && SN_A3 < CLOSEST) {
                BUILD->insert(0x44, count, priority);
            }
        }
        return;
    }
    if (id == 0x4f) {
        if (FLAG_4F != 1) return;
        ResourceItem itemCost(4);
        for (int i = 0; i < count; i++) itemCost.setValue(i, itemCost.value(i) * count);
        AIPLAYER->objectCost(0x4f, -1, &itemCost, 1);
        if (RESAI->resourcesAvailable(&itemCost) == 0) return;
        if (AIPLAYER->objectAvailable(0x4f) == 0) return;
        if (BUILD->allBuilt(0,0) == 0) return;
        if (BUILD->countQueued(0x4f, 0) >= SN_DE) return;
        BUILD->insert(0x4f, count, priority);
    }
    return;
    }
    if (FLAG_32 != 1 || this->inAge(4) == 0) return;
    ResourceItem itemCost(4);
    for (int i = 0; i < count; i++) itemCost.setValue(i, itemCost.value(i) * count);
    AIPLAYER->objectCost(0x32, -1, &itemCost, 1);
    if (RESAI->resourcesAvailable(&itemCost) != 0 &&
        AIPLAYER->objectAvailable(0x32) != 0 &&
        BUILD->allBuilt(0,0) != 0 &&
        BUILD->countQueued(0x32, 0) < SN_DC) {
        BUILD->insert(0x32, count, priority);
    }
}
