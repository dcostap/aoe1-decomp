// VA: 0050E9F0
// TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int, RGE_Sprite**, RGE_Sound**, int)
// Source: tm_co_ob.cpp lines 36-39
// BINARY NOTE: This qualified constructor owns [0050E9F0,0050EA5D). The base
// call, optional setup call, EH cleanup, and vtable publication stay in that order.

// attempt 1: default flags -> 96 bytes (no EH prolog)
// attempt 2: /GX rsp + virtual dtors in hierarchy -> EXACT MATCH (109/109, 0.0000%)
// FLAGS: /GX (needed for EH prolog; virtual dtors force vtable store)
// Exact-finish: removing the two unused derived destructor declarations kept
// this constructor exact. They are not codegen-active in this translation unit.

#ifndef TM_CO_OB_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char gap_FC[0x4C];  // sizeof(RGE_Master_Combat_Object) = 0x148, base = 0xFC
    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_148[0x1C];  // sizeof(TRIBE_Master_Combat_Object) = 0x164, base = 0x148

    void setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);

    TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
};
#endif

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, 0) {
    if (param_4 != 0) {
        this->setup(param_1, param_2, param_3);
    }
}
