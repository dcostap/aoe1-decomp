// 00507EF0 TribeArtifactUnitAIModule::processMisc
// Source: taiuaimd.cpp lines 2897-2919
// protected: virtual int __thiscall TribeArtifactUnitAIModule::processMisc(void)
//
// Attempt log:
// Probe 1: natural shape with virtual calls at slots 22 (0x58) and 53 (0xD4), default flags

#include "..\..\include\game_globals.h"

extern FILE* actionFile;

#ifndef TAIUAIMD_COMPLETE_TU
// UnitAIModule — base class with virtual methods at correct slots
class UnitAIModule {
public:
    // 22 dummy virtual methods (slots 0-21)
    virtual void _d0() {} virtual void _d1() {} virtual void _d2() {} virtual void _d3() {}
    virtual void _d4() {} virtual void _d5() {} virtual void _d6() {} virtual void _d7() {}
    virtual void _d8() {} virtual void _d9() {} virtual void _d10() {} virtual void _d11() {}
    virtual void _d12() {} virtual void _d13() {} virtual void _d14() {} virtual void _d15() {}
    virtual void _d16() {} virtual void _d17() {} virtual void _d18() {} virtual void _d19() {}
    virtual void _d20() {} virtual void _d21() {}

    virtual void stopObject(int flag);  // Slot 22 (offset 0x58)

    // 30 more dummies (slots 23-52)
    virtual void _d23() {} virtual void _d24() {} virtual void _d25() {} virtual void _d26() {}
    virtual void _d27() {} virtual void _d28() {} virtual void _d29() {} virtual void _d30() {}
    virtual void _d31() {} virtual void _d32() {} virtual void _d33() {} virtual void _d34() {}
    virtual void _d35() {} virtual void _d36() {} virtual void _d37() {} virtual void _d38() {}
    virtual void _d39() {} virtual void _d40() {} virtual void _d41() {} virtual void _d42() {}
    virtual void _d43() {} virtual void _d44() {} virtual void _d45() {} virtual void _d46() {}
    virtual void _d47() {} virtual void _d48() {} virtual void _d49() {} virtual void _d50() {}
    virtual void _d51() {} virtual void _d52() {}

    virtual int getActionState(int flag);  // Slot 53 (offset 0xD4)

    void* obj;  // +0x04
    void removeCurrentTarget();
};

// TribeArtifactUnitAIModule size 0x134
class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    char _gap_08[0xF0];  // from +0x08 to +0xF8
    int field_F8;         // +0xF8

    int processMisc();
};
#endif

int TribeArtifactUnitAIModule::processMisc()
{
    if (this->getActionState(1) == 6) {
        this->removeCurrentTarget();
        if (actionFile != 0) {
            int value;
            if (this->obj != 0) {
                value = *(int*)((char*)this->obj + 4);
            } else {
                value = -1;
            }
            fprintf(actionFile, "#%d call stopObject %s %d\n", value, "C:\\msdev\\work\\age1_x1\\taiuaimd.cpp", 0xB60);
        }
        this->stopObject(1);
        this->field_F8 = 0;
        return 10;
    }
    return 9;
}
