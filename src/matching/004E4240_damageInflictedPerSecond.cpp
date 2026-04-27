// 004E4240 TribeInformationAIModule::damageInflictedPerSecond
// Source: taiinfmd.cpp lines 8263-8292
// public: float __thiscall TribeInformationAIModule::damageInflictedPerSecond(int*,int,RGE_Static_Object*)
//
// Attempt log:
// Probe 1: natural loop, virtual calls at correct slots, default flags

#include "..\..\include\game_globals.h"

// RGE_Static_Object — minimal stub with virtual methods at correct vtable offsets:
//   vt[64] 0x100: rateOfFire()
//   vt[65] 0x104: damageCapability(RGE_Static_Object*)
class RGE_Static_Object {
public:
    // 65 dummy virtual methods to push rateOfFire to slot 64 (offset 0x100)
    virtual void _d0() {} virtual void _d1() {} virtual void _d2() {} virtual void _d3() {}
    virtual void _d4() {} virtual void _d5() {} virtual void _d6() {} virtual void _d7() {}
    virtual void _d8() {} virtual void _d9() {} virtual void _d10() {} virtual void _d11() {}
    virtual void _d12() {} virtual void _d13() {} virtual void _d14() {} virtual void _d15() {}
    virtual void _d16() {} virtual void _d17() {} virtual void _d18() {} virtual void _d19() {}
    virtual void _d20() {} virtual void _d21() {} virtual void _d22() {} virtual void _d23() {}
    virtual void _d24() {} virtual void _d25() {} virtual void _d26() {} virtual void _d27() {}
    virtual void _d28() {} virtual void _d29() {} virtual void _d30() {} virtual void _d31() {}
    virtual void _d32() {} virtual void _d33() {} virtual void _d34() {} virtual void _d35() {}
    virtual void _d36() {} virtual void _d37() {} virtual void _d38() {} virtual void _d39() {}
    virtual void _d40() {} virtual void _d41() {} virtual void _d42() {} virtual void _d43() {}
    virtual void _d44() {} virtual void _d45() {} virtual void _d46() {} virtual void _d47() {}
    virtual void _d48() {} virtual void _d49() {} virtual void _d50() {} virtual void _d51() {}
    virtual void _d52() {} virtual void _d53() {} virtual void _d54() {} virtual void _d55() {}
    virtual void _d56() {} virtual void _d57() {} virtual void _d58() {} virtual void _d59() {}
    virtual void _d60() {} virtual void _d61() {} virtual void _d62() {} virtual void _d63() {}

    // Data fields: vtable implicit at +0x00
    int id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08

    virtual float rateOfFire();                          // slot 64 = offset 0x100
    virtual float damageCapability(RGE_Static_Object*);  // slot 65 = offset 0x104
};

// MainDecisionAIModule with object() method
class MainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

// TribeInformationAIModule — md at +0x100
class TribeInformationAIModule {
public:
    char _gap_00[0x100];                 // skip base class data to md
    MainDecisionAIModule* md;            // +0x100 (4)

    float damageInflictedPerSecond(int* ids, int count, RGE_Static_Object* refObj);
};

float TribeInformationAIModule::damageInflictedPerSecond(int* ids, int count, RGE_Static_Object* refObj)
{
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        RGE_Static_Object* obj = this->md->object(ids[i]);
        if (obj != 0) {
            total += refObj->damageCapability(obj) / obj->rateOfFire();
        }
    }
    return total;
}
