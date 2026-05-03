// VA: 00500CC0, TribeTacticalAIModule::setAllGroupLocations, 277 bytes
// Source: taitacmd.cpp lines 11628-11664
// Status: SCRATCH — multiple cascading compiler optimization differences.
//
// Known correct: function behavior, field offsets (md at +0xF0,
// sn_16 at +0x1EC, sn_48 at +0x2B4, world_y/z/x at +0x38/0x3C/0x40),
// calling sequence (commander, object, type, object2, desiredNumberUnits,
// findGatherPosition, setAllLocations), __ftol for float→int conversion.
//
// Remaining issues:
// 1. Local space: original uses `sub esp, 0x10` (reuses param_1 slot for
//    flag at [esp+24h]). Modern compiler uses `sub esp, 0x18` (allocates
//    separate local for flag at [esp+10h]). Cannot force param slot reuse
//    from C++.
// 2. ftol/store interleaving: original interleaves ftol calls with result
//    stores (stores cy AFTER loading world_z; stores gx after loading sn48/
//    sn16). Modern compiler stores both ftol results immediately in
//    registers (ebp=cy, edi=gx).
// 3. findGatherPosition parameter order: original constructs call with
//    interleaved pushes (some before desiredNumberUnits, some after).
//    Modern compiler generates different push order.
// 4. setAllLocations success path: original uses `fild [esp+N]; push; fstp`
//    for float conversion. Modern compiler generates different FPU code.
// 5. Object register: original uses ebx for first obj, edi for target.
//    Modern compiler uses same registers but different scheduling.
//
// Attempt log:
// - v1: messy _impl wrapper → 256 bytes
// - v2: XYPoint structs, __ftol → sub esp, 0x14 (too much local space)
// - v3-v4: flag/param slot reuse attempts → hacky
// - v5: clean implementation → 277 bytes but sub esp 0x18 vs 0x10
//   and pervasive ftol/store interleaving differences
// - Conclusion: modern VC5 generates different FPU scheduling and
//   parameter-reuse patterns. Multiple interdependent axes prevent
//   exact matching without deeper VC5 version analysis.
// FLAGS: /nologo /c /O2 /Oy

#include <math.h>

typedef unsigned char uchar;

struct RGE_Static_Object {
    char _pad_00[0x38];
    float world_y;       // +0x38
    float world_z;       // +0x3C
    float world_x;       // +0x40
};

struct TacticalAIGroup {
    int commander();
    int type();
    int desiredNumberUnits(int flag);
    void setAllLocations(float x, float y, float z);
};

struct MainDecisionAIModule {
    char _pad_000[0xCEC];
    RGE_Static_Object* object(int commander);
    RGE_Static_Object* object2(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
};

class TribeTacticalAIModule {
public:
    char _pad_000[0x0F0];
    MainDecisionAIModule* md;  // +0x0F0
    char _pad_0F4[0x0F8];
    int sn_16;                  // +0x1EC
    char _pad_1F0[0xC4];
    int sn_48;                  // +0x2B4

    int setAllGroupLocations(TacticalAIGroup* group);
};

struct InfoAIHelper {
    int findGatherPosition(int* center, int desiredUnits, int sn16, int sn48, void* obj, int* gatherOut);
};

int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* group)
{
    int cmdr = group->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag = 0;
    int gtype = group->type();
    if (gtype == 100 || gtype == 101 || gtype == 102)
        flag = 1;

    RGE_Static_Object* target = this->md->object2(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (target != 0) {
        int cy = (int)target->world_y;
        int gx = (int)target->world_z;

        int sn48 = this->sn_48;
        int sn16 = this->sn_16;
        int desiredUnits = group->desiredNumberUnits(flag);

        int centerPt[2];
        int gatherPt[2];
        centerPt[0] = cy;
        centerPt[1] = gx;

        InfoAIHelper* infoAI = (InfoAIHelper*)((char*)this->md + 0xCEC);
        int result = infoAI->findGatherPosition(centerPt, desiredUnits, sn16, sn48, obj, gatherPt);
        if (result == 1) {
            group->setAllLocations((float)gatherPt[1], obj->world_z, obj->world_x);
            return 1;
        }
    }

    group->setAllLocations(obj->world_y, obj->world_z, obj->world_x);
    return 1;
}
