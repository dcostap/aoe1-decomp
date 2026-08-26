// VA: 00500BA0, TribeTacticalAIModule::setGatherLocation, 287 bytes
// Source: taitacmd.cpp lines 11588-11623
// Status: EXACT candidate â€” natural typed reconstruction; promotion pending.
//
// Attempt log:
// - Prior scaffold used a cached group type, a separate object2 helper, a
//   wrong desiredNumberUnits(int) declaration, and placed the default call
//   outside the target-success/failure split. Those forms changed call
//   identity/count and the target-null behavior.
// - Mirrored the exact same-TU setAllGroupLocations donor for the overload,
//   repeated type checks, informationAI ownership, and local source shape.
// - The target-null path is an early return; findGatherPosition failure uses
//   the ordinary object coordinates before the common return.
// - Probes 2â€“5 (recorded in session history): self alias, split declarations,
//   reversed result predicate, and register-qualified group were respectively
//   neutral, neutral, block-shape-worse, and neutral; all were rolled back.
// - The successful findGatherPosition arm returns immediately; leaving the
//   default setGatherLocation call as fall-through reproduces the exact
//   compiler tail merge and the original register ownership.
// - Main-agent audit restored canonical object and AI-module destructor
//   ownership; emitted code remains exact.
// FLAGS: /nologo /c /O2 /Oy

#include <math.h>

#ifndef TAITACMD_SHARED_CONTEXT
struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char _pad_04[0x34];
    float world_x;       // +0x38
    float world_y;       // +0x3C
    float world_z;       // +0x40
};
struct XYPoint {
    int x;
    int y;
};
struct TacticalAIGroup {
    int commander();
    int type();
    int desiredNumberUnits();
    void setGatherLocation(float x, float y, float z);
};
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char _pad_004[0x100];
    RGE_Static_Object* object(int commander);
    RGE_Static_Object* object(int a1, int a2, int a3, int a4, int a5,
                              int a6, int a7, int a8, int a9, int a10);
};
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int findGatherPosition(XYPoint& center, int desiredUnits, int flag,
                           int sn16, int sn48, RGE_Static_Object* object,
                           XYPoint& gather);
};
class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char _pad_104[0xCEC - 0x104];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char _pad_004[0x0EC];
    TribeMainDecisionAIModule* md;  // +0x0F0
    char _pad_0F4[0x0A0];
    int strategicNumbers[0x49]; // starts at +0x194; [0x16] and [0x48] are used

    int setGatherLocation(TacticalAIGroup* group);
};
#endif
int TribeTacticalAIModule::setGatherLocation(TacticalAIGroup* group)
{
    int cmdr = group->commander();
    RGE_Static_Object* obj = this->md->object(cmdr);
    if (obj == 0)
        return 0;

    int flag;
    if (group->type() == 100) {
        flag = 1;
    }
    else {
        if (group->type() == 101) {
            flag = 1;
        }
        else {
            int gtype = group->type();
            flag = 0;
            if (gtype == 102)
                flag = 1;
        }
    }

    RGE_Static_Object* target = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (target == 0)
        return 0;

    XYPoint centerPoint;
    XYPoint gatherPoint;
    centerPoint.x = (int)target->world_x;
    centerPoint.y = (int)target->world_y;

    int result = this->md->informationAI.findGatherPosition(
        centerPoint, group->desiredNumberUnits(), flag,
        this->strategicNumbers[0x16], this->strategicNumbers[0x48], obj, gatherPoint);
    if (result == 1) {
        group->setGatherLocation((float)gatherPoint.x,
                                 (float)gatherPoint.y, obj->world_z);
        return 1;
    }
    group->setGatherLocation(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}
