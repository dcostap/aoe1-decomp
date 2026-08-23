// VA: 004CF090 TRIBE_Action_Hunt::TRIBE_Action_Hunt(int, RGE_Action_Object*)
// PDB source: tact_hnt.cpp lines 70-73 (103 bytes, 32 asm lines)
// FLAGS: config/flags/004CF090_TRIBE_Action_Hunt.rsp keeps /GX for the original EH-framed constructor.
// MATCHED 2026-05-09: the EH frame appears when rge_read is declared as an ordinary C++ function, not extern "C".
// In a /GX constructor after a nontrivial base ctor, the C++ call surface is treated as potentially throwing and VC5
// emits the base-unwind state without adding fake cleanup locals/calls.

#ifndef TACT_HNT_SHARED_CONTEXT
class RGE_Action_Object;

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[0x3C];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
};

void rge_read(int, void*, int);

class TRIBE_Action_Hunt : public RGE_Action {
public:
    int targetType; // +0x40

    TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2);
};
#endif

TRIBE_Action_Hunt::TRIBE_Action_Hunt(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    *(void**)this = (void*)0x5750F0;
    *(short*)((char*)this + 4) = 0x6E;
    rge_read(param_1, &targetType, 4);
}
