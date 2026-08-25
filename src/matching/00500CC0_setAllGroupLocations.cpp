#ifndef TAITACMD_SHARED_CONTEXT
// VA: 00500CC0, TribeTacticalAIModule::setAllGroupLocations, 277 bytes
// Source: taitacmd.cpp lines 11628-11664
// Status: EXACT candidate â€” clean typed reconstruction; final validation and
// promotion are pending.
//
// Attempt log:
// - Prior scaffold used a cached group type, an object2 helper, a wrong
//   desiredNumberUnits(int) declaration, and omitted the flag argument from
//   findGatherPosition. Those forms changed call identity/count and are not a
//   canonical source model.
// - Corrected the overload/ABI surface: MainDecisionAIModule::object is
//   overloaded, desiredNumberUnits has no argument, and
//   findGatherPosition takes XYPoint references plus the flag argument.
// - Canonicalized md as TribeMainDecisionAIModule with its named
//   informationAI subobject at +0xCEC; this preserves the exact call bytes.
// - The third type result is named before the default flag store; this is a
//   plausible local reuse that preserves the original call-before-store order.
// - Exact emitted match reached at 277 bytes with default VC5 /O2 /Oy.
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
    void setAllLocations(float x, float y, float z);
};
class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char _pad_004[0x100];
    RGE_Static_Object* object(int commander);
    RGE_Static_Object* object(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
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
    char _pad_0F4[0x0F8];
    int sn_16;                  // +0x1EC
    char _pad_1F0[0xC4];
    int sn_48;                  // +0x2B4

    int setAllGroupLocations(TacticalAIGroup* group);
};
#endif
int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* group)
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

    RGE_Static_Object* target = this->md->object(-1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (target != 0) {
        XYPoint centerPoint;
        XYPoint gatherPoint;
        centerPoint.x = (int)target->world_x;
        centerPoint.y = (int)target->world_y;

        int result = this->md->informationAI.findGatherPosition(
            centerPoint, group->desiredNumberUnits(), flag,
            this->sn_16, this->sn_48, obj, gatherPoint);
        if (result == 1) {
            group->setAllLocations((float)gatherPoint.x,
                                   (float)gatherPoint.y, obj->world_z);
            return 1;
        }
    }

    group->setAllLocations(obj->world_x, obj->world_y, obj->world_z);
    return 1;
}
#else
int TribeTacticalAIModule::setAllGroupLocations(TacticalAIGroup* group) {
    return 0;
}
#endif
