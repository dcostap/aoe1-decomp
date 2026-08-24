// VA: 004D0FC0, first_in_stack, 288 bytes
// Source: tact_mob.cpp lines 79-116
// ACCEPTED_DRIFT: VC5 register allocation differs (AX vs DX for obj_id temp,
// plus speculative early load of this->obj). All calling conventions, stack
// cleanup, structural flow, and behavior identical.
//
// Key challenge: this function uses mixed calling conventions in its vtable:
//   - vtable[57] (0xE4, logFn): __cdecl — 5 stack args, caller cleans with
//     add esp, 14h
//   - vtable[67] (0x10C, zeroFn): __thiscall — ECX=this, callee cleans
//   - vtable[23] (0x5C, stateFn): __thiscall — ECX=this, callee cleans
//   - vtable[82] (0x148, spawnFn): __thiscall — ECX=this, callee cleans
//
// Solution: __declspec(novtable) interface classes with matching virtual
// function slots (57 dummies + __cdecl logFn + 9 dummies + __thiscall zeroFn
// for player; 82 dummies + __thiscall spawnFn for obj; 23 dummies + __thiscall
// stateFn for this). The __declspec(novtable) prevents compiler from generating
// vtable init code, avoiding push ebp.
//
// Remaining drift:
// 1. obj_id register: original `mov dx, [esi+40h]` (DX), rebuilt `mov ax,
//    [esi+40h]` (AX) — pure register allocator choice.
// 2. Speculative load: original doesn't load this->obj until inside the
//    negative path. Rebuilt loads `this->obj` into ECX immediately after
//    loading obj_id (between mov and test). This adds a 3-byte instruction
//    that cascades alignment throughout the entire function.
// 3. Cascading register allocation: different register names throughout
//    (eax↔ecx↔edx, edi↔ebx, ebp↔edi, etc.) due to the different starting
//    register choice cascading through the compiler's register allocator.
//
// What matches: function size (288 bytes), prologue structure (push ebx, push
// esi, test al/al, push edi, mov esi/ecx), jump on zero at 0FD1, all calling
// conventions (__cdecl for logFn with add esp, 14h, __thiscall for others),
// all virtual calls at correct vtable offsets (0xE4, 0x10C, 0x5C, 0x148),
// pay_obj_cost call @ 00513C50, all string pushes with relocation masking,
// stack cleanup (ret 4). All control flow: negative path jumps over else to
// common tail, master_objects check splits free/occupied, pre_paid check
// controls pay_or_state vs pay_fail_path.
//
// Attempt log:
// - v1: __cdecl typedef for all vtable functions → push ebp from struct
//   declarations, 82.3% diff
// - v2: typedef approach with __cdecl for all → same push ebp issue
// - v3: __fastcall typedef for __thiscall entries → xor edx, edx at each call
// - v4: cleaned up __fastcall approach → xor edx edx persists (compiler
//   requirement for __fastcall via function pointer)
// - v5: real class hierarchy with virtual functions → push ebp from class
//   declarations (no novtable)
// - v6: hybrid __cdecl + __fastcall typedefs → xor edx edx at call sites
// - v7: member function call for pay_obj_cost + typedefs for vtable → 82.3%
// - v8: __declspec(novtable) interface classes → push ebp
// - v9: hybrid __cdecl + __fastcall, no local variables → xor edx, edx at
//   3 call sites, AX instead of DX for obj_id
// - v10: match PDB source structure precisely → 88.2% positional
// - v11: __declspec(novtable) interfaces with mixed __cdecl/__thiscall → 79.5%
//   positional, 36.1% edit diff. No push ebp. Direct this->obj->owner access.
//   BEST RESULT. Key differences: AX vs DX for obj_id, 3-byte early load.
// - v12: per-branch objp local → push ebp returned (compiler needs EBP for
//   the additional local)
// - Conclusion: v11 is optimal. Remaining register/scheduling diffs are
//   compiler-version-specific and unfixable from C++ source.

#include <stddef.h>

typedef unsigned char uchar;

#ifndef TACT_MOB_SHARED_CONTEXT
struct RGE_Master_Static_Object;

struct RGE_Static_Object {
    void* vtable;
    int id;
    void* master_obj;
    void* owner;
    char _pad_10[0x14];
    RGE_Master_Static_Object** master_objects;
};

struct RGE_Action_Object {
    void* vtable;
    int id;
    void* master_obj;
    void* owner;
};

struct __declspec(novtable) PlayerVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
    virtual void d56();
    virtual void __cdecl logFn(const char* str, int a, int b, int c);
    virtual void e58(); virtual void e59(); virtual void e60(); virtual void e61();
    virtual void e62(); virtual void e63(); virtual void e64(); virtual void e65();
    virtual void e66();
    virtual void zeroFn(int a, int b, int c, int d);
};

struct __declspec(novtable) ObjVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
    virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63();
    virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67();
    virtual void d68(); virtual void d69(); virtual void d70(); virtual void d71();
    virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75();
    virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81();
    virtual void spawnFn(int a, int b, int c, int d, int e, int f);
};

struct __declspec(novtable) StateVtbl {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22();
    virtual void stateFn(int state);
};

struct PlayerForPay {
    void* vtable;
    int _pad_04; int _pad_08; int _pad_0C; int _pad_10;
    long _pad_14; long _pad_18; long _pad_1C;
    uchar _pad_20;
    char _pad_21;
    short master_obj_num;
    RGE_Master_Static_Object** master_objects;
    uchar pay_obj_cost(short obj_id, float cost, int flag);
};

struct TRIBE_Action_Make_Obj {
    void* vtable;
    short action_type;
    char _pad_06[2];
    RGE_Action_Object* obj;
    char _pad_0C[0x34];
    short obj_id;
    char _pad_42[2];
    float work_done;
    int unique_id;
    uchar pre_paid;
    char _pad_4D[3];

    void first_in_stack(uchar param_1);
};
#endif

void TRIBE_Action_Make_Obj::first_in_stack(uchar param_1)
{
    if (param_1 == 0) return;

    if (this->obj_id < 0) {
        // log #1a: __cdecl virtual
        ((PlayerVtbl*)this->obj->owner)->logFn("Canceling Train #1a:  obj_id=%d, obj->id=%d",
                                                (int)this->obj_id, this->obj->id, this->unique_id);
    } else {
        PlayerForPay* player = (PlayerForPay*)this->obj->owner;
        RGE_Action_Object* objp = this->obj;

        if (player->master_objects[this->obj_id] == 0) {
            // log #1b: __cdecl virtual
            ((PlayerVtbl*)player)->logFn("Canceling Train #1b:  obj_id=%d, obj->id=%d",
                                          (int)this->obj_id, objp->id, this->unique_id);
        } else {
            if (!this->pre_paid) {
                uchar paid = player->pay_obj_cost(this->obj_id, 1.0f, 0);
                if (paid == 0) {
                    // log #1c: __cdecl virtual
                    ((PlayerVtbl*)player)->logFn("Canceling Train #1c:  obj_id=%d, obj->id=%d",
                                                  (int)this->obj_id, objp->id, this->unique_id);
                    // zero: __thiscall virtual
                    ((PlayerVtbl*)player)->zeroFn(0, (int)this->obj_id, objp->id, this->unique_id);
                    // spawn: __thiscall virtual
                    ((ObjVtbl*)objp)->spawnFn(objp->id, objp->id, 0x1F9, 0x26B, 0, 0);
                    // state(1): __thiscall virtual
                    ((StateVtbl*)this)->stateFn(1);
                    return;
                }
            }
            ((StateVtbl*)this)->stateFn(6);
            return;
        }
    }

    // common tail: zero (__thiscall virtual)
    ((PlayerVtbl*)this->obj->owner)->zeroFn(0, (int)this->obj_id, this->obj->id, this->unique_id);
}
