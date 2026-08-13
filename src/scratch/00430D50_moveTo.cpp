// VA: 00430D50 RGE_Combat_Object::moveTo(float,float,float,float,int)
// Source: com_obj.cpp lines 930-974
// FLAGS: config/flags/00430D50_moveTo.rsp uses /GX for original EH-framed new+ctor cleanup.
// Attempt log:
// initial natural source modeled from packet, reusing nearby 00430C30 moveTo type surface.
// added /GX flag: required to match original EH-framed new+ctor region/prologue.
// added full RGE_Action data layout: fixed operator new size from 8 to original 0x44.
// direct virtual/nonvirtual action surface matches calls through targetX/Y/Z, func18, func30, and add_action +0x208.
// tried volatile x/parameter-slot casts for early comparisons: worsened prologue/register allocation; rolled back.
// tried bool found/result style and volatile result: worsened tail or forced stack result reload; rolled back.
// tried if/else, goto fail/have_move, initialized result, and result=(int)move_action tail forms.
// best remaining diff (this file): 359 bytes, edit diff 16 (4.4568%), first mismatch at success-branch displacement.
// localized drift: after RGE_Action_Move_To ctor, rebuilt zeros eax before EH-state reset and uses test/je to shared epilogue;
// original tests edi before EH-state reset, uses jne to success body, then xor eax/jmp epilogue on null. Store does not affect flags,
// eax is overwritten on success, and null path returns 0, so this looks behavior-equivalent but is not exact.
// Fresh worker: a pointer-as-status diagnostic reached 49 strict differing bytes
// but added `mov edi,1; mov eax,edi` on success; it was rolled back to the
// natural int result candidate (54 bytes, exact size/calls).
// Main-agent audit replaced the proxy cast, raw vptr field, and raw master
// offsets with canonical inherited virtual and master-object ownership.
// Current worker: explicit constructor-null/done-label and direct-return forms
// expanded the EH tail to 378/382 bytes and were rolled back.
// A pointer-typed constructor result with canonical ownership reproduced the
// 359-byte/49-diff basin, but retained opposite `je` polarity and the
// `mov edi,1; mov eax,edi` success conversion; restored the clean int-result form.
// The remaining exactness blocker is the VC5 EH-tail lowering around the
// constructor null test: the clean source hoists `xor eax,eax` before `test edi`
// while the oracle tests first, resets EH state, then branches `jne` to success.
// Follow-up worker: mirrored the exact 00430C30 same-TU allocation tail with direct
// returns; VC5 produced 382 bytes / 161 diff because it duplicated the EH epilogue.
// Converted the constructor pointer into an int status, matching the decompiler's
// iVar4 shape; this reached the known 359-byte / 49-diff diagnostic basin but kept
// the opposite `je` layout. Negative if/else, goto-done, pointer-only, and switch
// status forms either duplicated the epilogue or reproduced the 54-byte clean basin.
// Reordered locals to PDB-like int-before-pointer order; emitted bytes unchanged.
// Variant lab of six plausible tail forms under /GX found no exact or new invariant
// basin. Restored the canonical int-result source; blocker remains localized to the
// constructor null-test/EH-tail branch layout.
// Follow-up worker: retested positive constructor if/else, direct success return, and positive-goto tail forms; all entered the known 378-byte EH basin. Restored the validated 359-byte int-result source.
// Current worker: tested a same-TU-style nested allocation scope for the Move_To pointer; emitted code was unchanged and the scope was rolled back.

#include <stddef.h>

typedef unsigned char uchar;

class RGE_Sprite;
class RGE_Action_Object;

class RGE_Action_List {
public:
    uchar have_action();
    void* get_action();
    void delete_list();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual short func18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual int func30(RGE_Action_Object* obj, float x, float y, float z);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    float targetX();
    float targetY();
    float targetZ();
};

class RGE_Action_Move_To : public RGE_Action {
public:
    int pad_40;
    RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z, float range, RGE_Sprite* spr);
};

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char gap_04[0xB8];
    RGE_Sprite* sprite;
    RGE_Sprite* moving_sprite;
};

struct RGE_Action_Object {
    virtual ~RGE_Action_Object(); virtual void s004(); virtual void s008(); virtual void s00C();
    virtual void s010(); virtual void s014(); virtual void s018(); virtual void s01C();
    virtual void s020(); virtual void s024(); virtual void s028(); virtual void s02C();
    virtual void s030(); virtual void s034(); virtual void s038(); virtual void s03C();
    virtual void s040(); virtual void s044(); virtual void s048(); virtual void s04C();
    virtual void s050(); virtual void s054(); virtual void s058(); virtual void s05C();
    virtual void s060(); virtual void s064(); virtual void s068(); virtual void s06C();
    virtual void s070(); virtual void s074(); virtual void s078(); virtual void s07C();
    virtual void s080(); virtual void s084(); virtual void s088(); virtual void s08C();
    virtual void s090(); virtual void s094(); virtual void s098(); virtual void s09C();
    virtual void s0A0(); virtual void s0A4(); virtual void s0A8(); virtual void s0AC();
    virtual void s0B0(); virtual void s0B4(); virtual void s0B8(); virtual void s0BC();
    virtual void s0C0(); virtual void s0C4(); virtual void s0C8(); virtual void s0CC();
    virtual void s0D0(); virtual void s0D4(); virtual void s0D8(); virtual void s0DC();
    virtual void s0E0(); virtual void s0E4(); virtual void s0E8(); virtual void s0EC();
    virtual void s0F0(); virtual void s0F4(); virtual void s0F8(); virtual void s0FC();
    virtual void s100(); virtual void s104(); virtual void s108(); virtual void s10C();
    virtual void s110(); virtual void s114(); virtual void s118(); virtual void s11C();
    virtual void s120(); virtual void s124(); virtual void s128(); virtual void s12C();
    virtual void s130(); virtual void s134(); virtual void s138(); virtual void s13C();
    virtual void s140(); virtual void s144(); virtual void s148(); virtual void s14C();
    virtual void s150(); virtual void s154(); virtual void s158(); virtual void s15C();
    virtual void s160(); virtual void s164(); virtual void s168(); virtual void s16C();
    virtual void s170(); virtual void s174(); virtual void s178(); virtual void s17C();
    virtual void s180(); virtual void s184(); virtual void s188(); virtual void s18C();
    virtual void s190(); virtual void s194(); virtual void s198(); virtual void s19C();
    virtual void s1A0(); virtual void s1A4(); virtual void s1A8(); virtual void s1AC();
    virtual void s1B0(); virtual void s1B4(); virtual void s1B8(); virtual void s1BC();
    virtual void s1C0(); virtual void s1C4(); virtual void s1C8(); virtual void s1CC();
    virtual void s1D0(); virtual void s1D4(); virtual void s1D8(); virtual void s1DC();
    virtual void s1E0(); virtual void s1E4(); virtual void s1E8(); virtual void s1EC();
    virtual void s1F0(); virtual void s1F4(); virtual void s1F8(); virtual void s1FC();
    virtual void s200(); virtual void s204();
    virtual void add_action(void* action);

    int id;
    RGE_Master_Action_Object* master_obj;
    void* owner;
    char gap_10[0x174];
    RGE_Action_List* actions;
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int moveTo(float x, float y, float z, float range, int force);
};

int RGE_Combat_Object::moveTo(float x, float y, float z, float range, int force)
{
    RGE_Action* action;
    RGE_Action_Move_To* move_action;
    RGE_Sprite* sprite;
    int result;

    if (force == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->targetX() == x) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->targetY() == y) {
                    action = (RGE_Action*)this->actions->get_action();
                    if (action->targetZ() == z) {
                        action = (RGE_Action*)this->actions->get_action();
                        if (action->func18() == 1) {
                            goto success;
                        }
                    }
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        action = (RGE_Action*)this->actions->get_action();
        if (action->func30(this, x, y, z) == 1) {
            goto success;
        }
    }

    sprite = this->master_obj->moving_sprite;
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }

    move_action = new RGE_Action_Move_To(this, x, y, z, range, sprite);
    result = 0;
    if (move_action != 0) {
        this->actions->delete_list();
        this->add_action(move_action);

success:
        result = 1;
    }
    return result;
}
