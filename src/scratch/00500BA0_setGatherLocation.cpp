// VA: 00500BA0, TribeTacticalAIModule::setGatherLocation, 287 bytes
// Source: taitacmd.cpp lines 11588-11623
// Status: SCRATCH — structurally identical to setAllGroupLocations (00500CC0),
// with same multi-axis optimization diffs.
//
// Function flow (same as setAllGroupLocations):
// 1. group->commander() → this->md->object(cmdr) → obj
// 2. If obj == 0: return 0
// 3. group->type() check: 100/101/102 → flag=1 else flag=0 (reuses param_1 slot)
// 4. this->md->object2(-1, ..., 0x6D, ...) → target
// 5. If target == 0: return 0
// 6. ftol(target->world_y) → centerPoint.y at [esp+10h]
// 7. ftol(target->world_z) → centerPoint.x at [esp+14h]
// 8. this->sn[0x48], this->sn[0x16] loaded; gatherPoint.y lea
// 9. desiredNumberUnits(flag) called; findGatherPosition(...) called
// 10. Success path: setGatherLocation(gatherPoint.y_float, gatherPoint.x_float, obj->world_z_float)
// 11. Default path: setGatherLocation(obj->world_x, obj->world_y, obj->world_z)
// 12. return 1
//
// Persistent issues (same as setAllGroupLocations):
// 1. Local space: original sub esp, 0x10 (reuses param_1 slot for flag).
//    Modern compiler: sub esp, 0x1C (separate local for flag, stored in ebx).
// 2. FTOL/store interleaving: original stores cy AFTER loading world_z, stores
//    gx AFTER loading sn48/sn16. Modern compiler stores both in registers
//    immediately.
// 3. findGatherPosition parameter order: original interleaves pushes (some
//    before desiredNumberUnits, some after). Modern compiler uses different
//    push ordering.
// 4. setGatherLocation success path: original uses fild/push/fstp pattern for
//    float conversion. Modern compiler generates different FPU code.
// 5. Object register: original uses ebx for group obj, edi for target.
//    Modern compiler uses ebp for obj, edi for target.
// 6. Type check: original calls type() three separate times with je dispatch.
//    Modern compiler calls type() once and caches in eax with je/jne pattern.
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
    void setGatherLocation(float x, float y, float z);
};

struct InfoAI {
    int findGatherPosition(int* center, int desiredUnits, int sn16, int sn48, void* obj, int* gatherOut);
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

    int setGatherLocation(TacticalAIGroup* group);
};

int TribeTacticalAIModule::setGatherLocation(TacticalAIGroup* group)
{
    int cmdr = group->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int gtype = group->type();
    int flag = (gtype == 100 || gtype == 101 || gtype == 102) ? 1 : 0;

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

        InfoAI* infoAI = (InfoAI*)((char*)this->md + 0xCEC);
        int result = infoAI->findGatherPosition(centerPt, desiredUnits, sn16, sn48, obj, gatherPt);
        if (result == 1) {
            group->setGatherLocation((float)gatherPt[1], (float)gatherPt[0], obj->world_z);
            return 1;
        }
    }

    group->setGatherLocation(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}
