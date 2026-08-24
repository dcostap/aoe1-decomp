// 004E6AD0 TribeAIPlayBook::convertUnitToIntType
// Source: taipbook.cpp lines 62-81
// public: virtual int __thiscall TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object*) const
//
// Attempt log:
// Probe 1: natural if-else chain + virtual weaponRange() call, default flags

#ifdef TAIPBOOK_CANONICAL_TU
#include "../../include/taipbook_context.h"
#else
#include "..\..\include\game_globals.h"

// RGE_Master_Static_Object — only object_group at +0x14 needed
class RGE_Master_Static_Object {
public:
    char _gap_00[0x14];
    short object_group; // +0x14 (2)
};

// RGE_Static_Object has 181 virtual methods. weaponRange() is at slot 67 (vt[67], offset 0x10C).
// We need this exact vtable offset to match the `call dword [edx+10Ch]` asm.
class RGE_Static_Object {
public:
    // 67 dummy virtual methods to push weaponRange to slot 67 (offset 0x10C)
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
    virtual void _d64() {} virtual void _d65() {} virtual void _d66() {}

    // Data fields follow the implicit vptr at +0x00
    int id;                              // +0x04 (4)
    RGE_Master_Static_Object* master_obj; // +0x08 (4)

    virtual float weaponRange(); // slot 67 = offset 0x10C
};
#endif

#ifndef TAIPBOOK_CANONICAL_TU
class TribeAIPlayBook {
public:
    int convertUnitToIntType(RGE_Static_Object* obj) const;
};
#endif

int TribeAIPlayBook::convertUnitToIntType(RGE_Static_Object* obj) const
{
    short group = obj->master_obj->object_group;
    if (group == 0x12) return 4;
    if (group == 0x1C) return 3;
    if (group == 0x0D) return 5;
    if (group == 0x0C || group == 0x23) return 2;

    float result = obj->weaponRange();
    if (result > 1.0f) return 1;
    return 0;
}
