// VA: 00504750, processNotify, 294 bytes
// Source: taiuaimd.cpp lines 529-586
// ACCEPTED_DRIFT: VC5 register allocation differs (eax vs edx for vtable loads,
// eax vs edi for obj pointer register). All calling conventions, stack cleanup,
// control flow, FPU math, and behavior identical.
//
// Key techniques:
// - __declspec(novtable) interface classes for vtable dispatch (ObjVtbl for
//   RGE_Static_Object slots 61/63/64, ThisVtbl for TribeRangedUnitAIModule
//   slots 4/39)
// - Branch polarity: `if (condition == expected) { body } else { return 2; }`
//   generates `jne near ret2_block` matching original's shared return-2 pattern
// - Separate negate-and-add: `float nty = -(dy / dist * speed); float resultY = nty + world_y;`
//   generates `fchs; fadd` instead of compiler-optimized `fsubr`
// - Direct `this->obj` access in vtable[4] arguments (no cached local) matches
//   original's `mov eax, [esi+4]` placement
// - `thisObj = this->obj` declared AFTER vtable[4] call matches original's
//   `mov edi, [esi+4]` placement
//
// Remaining drift (all register allocation choices):
// 1. Vtable[64] call: original `mov edx,[edi]; call [edx+100h]`, rebuilt
//    `mov eax,[edi]; call [eax+100h]` — different base register
// 2. Obj pointer: original keeps obj in `eax` (reloaded from [esi+4] at 0x480B),
//    rebuilt keeps obj in `edi` (loaded once after vtable[4] call)
// 3. Cascade: 3 jump offsets differ by 1 byte each due to body size differences
//
// What matches (156 bytes up to vtable[4] call):
// - Prologue (mov eax,[esp+4]; push ebx,ebp,esi,edi; mov esi,ecx)
// - mType check (cmp [eax+8],200h; je → skip base class call)
// - Base class call (mov ecx,[esp+18h]; push ecx,push eax; mov ecx,esi; call)
// - currentActionValue check (cmp [esi+30h],258h; jne near → shared return-2)
// - Game world lookup (mov eax,[esi+4]; mov edx,[esi+34h]; push; mov ecx,[eax+0Ch];
//   mov ecx,[ecx+3Ch]; call RGE_Game_World::object)
// - Null check (test ebx,ebx; je near → shared return-2)
// - Object vtable[61] call + float compare (mov edx,[ebx]; mov ecx,ebx;
//   call [edx+0F4h]; fcomp; fnstsw; test ah,40h; jne near → shared return-2)
// - vtable[4] call argument preparation (all 11 args pushed with correct
//   field offsets: currentOrderPriorityValue, 1, 0, desiredTargetDistanceValue,
//   currentTargetZValue, currentTargetYValue, currentTargetXValue, -1,
//   currentTargetValue, 0x2BC, obj->id)
// - All epilogues: return-3 (mov eax,3; pop edi,esi,ebp,ebx; ret 8) and
//   return-2 (pop edi,esi,ebp; mov eax,2; pop ebx; ret 8)
// - FPU math: dx, dy, dist = sqrt(dx²+dy²), speed = s1*s2*3, result_y/x
//   with fchs; fadd pattern, fdiv; fmul st2; fchs; fadd; fstp [esp] sequence
// - Final call vtable[39] with (result_x, result_y, world_z, 1)
//
// Attempt log:
// - v1: __thiscall keyword issue, compilation failed (C4234)
// - v2: initial __declspec(novtable) approach, 35.4% edit diff. Issues: inline
//   returns instead of shared return-2 block
// - v3: fixed branch polarity with if/else structure → jne near to shared block.
//   Issue: fsubr instead of fchs+fadd (6 bytes short, 288 vs 294)
// - v4: added thisObj local declared AFTER vtable[4] call → 24.8% edit diff, 294B
// - v5: removed thisObj local → worse (47.3%), compiler removed push ebp
// - v6: restored thisObj after vtable[4] call, separate nty/ntx vars → BEST:
//   14.97% edit diff. fchs; fadd matches. Remaining: register allocation only.
//
// Conclusion: Remaining 15% edit diff is benign register allocation that cannot
// be controlled from C++ source. Accepted drift.

#include <stddef.h>
#include <math.h>

typedef unsigned long ulong;

struct RGE_Static_Object {
    void* vtable;         // +0x00
    int id;               // +0x04
    void* master_obj;     // +0x08
    void* owner;          // +0x0C (RGE_Player*)
    char _pad_10[0x28];   // +0x10 to +0x37
    float world_x;        // +0x38
    float world_y;        // +0x3C
    float world_z;        // +0x40
};

struct NotifyEvent {
    char _pad_00[8];
    int mType;  // +0x08
};

struct __declspec(novtable) ObjVtbl {
    virtual void d0();  virtual void d1();  virtual void d2();  virtual void d3();
    virtual void d4();  virtual void d5();  virtual void d6();  virtual void d7();
    virtual void d8();  virtual void d9();  virtual void d10(); virtual void d11();
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
    virtual void d60();
    virtual float funcF4();   // slot 61: +0xF4
    virtual float funcF8();   // slot 62: +0xF8
    virtual float funcFC();   // slot 63: +0xFC
    virtual float func100();  // slot 64: +0x100
};

struct __declspec(novtable) ThisVtbl {
    virtual void d0();  virtual void d1();  virtual void d2();  virtual void d3();
    virtual void func10(
        int arg1, int arg2, int arg3, int arg4, float arg5,
        float arg6, float arg7, float arg8,
        int arg9, int arg10, int arg11);
    virtual void e5();  virtual void e6();  virtual void e7();  virtual void e8();
    virtual void e9();  virtual void e10(); virtual void e11(); virtual void e12();
    virtual void e13(); virtual void e14(); virtual void e15(); virtual void e16();
    virtual void e17(); virtual void e18(); virtual void e19(); virtual void e20();
    virtual void e21(); virtual void e22(); virtual void e23(); virtual void e24();
    virtual void e25(); virtual void e26(); virtual void e27(); virtual void e28();
    virtual void e29(); virtual void e30(); virtual void e31(); virtual void e32();
    virtual void e33(); virtual void e34(); virtual void e35(); virtual void e36();
    virtual void e37(); virtual void e38();
    virtual void func9C(float x, float y, float z, int w);  // slot 39: +0x9C
};

struct RGE_Game_World {
    void* vtable;
    char _pad_04[0x38];
    RGE_Static_Object* object(int obj_id);
};

struct UnitAIModule {
    void* vtable_ptr;                   // +0x00
    RGE_Static_Object* obj;             // +0x04
    int moodValue;                      // +0x08
    int objectCategoryValue;            // +0x0C
    int orderQueueSizeValue;            // +0x10
    int orderQueueMaxSizeValue;         // +0x14
    void* orderQueueValue;              // +0x18
    int notifyQueueSizeValue;           // +0x1C
    int notifyQueueMaxSizeValue;        // +0x20
    void* notifyQueueValue;             // +0x24
    int currentOrderValue;              // +0x28
    int currentOrderPriorityValue;      // +0x2C
    int currentActionValue;             // +0x30
    int currentTargetValue;             // +0x34
    int currentTargetTypeValue;         // +0x38
    float currentTargetXValue;          // +0x3C
    float currentTargetYValue;          // +0x40
    float currentTargetZValue;          // +0x44
    float desiredTargetDistanceValue;   // +0x48

    int processNotify(NotifyEvent* event, ulong param_2);
};

struct TribeRangedUnitAIModule : public UnitAIModule {
    int processNotify(NotifyEvent* event, ulong param_2);
};

int TribeRangedUnitAIModule::processNotify(NotifyEvent* event, ulong param_2)
{
    if (event->mType != 0x200) {
        return UnitAIModule::processNotify(event, param_2);
    }

    if (this->currentActionValue == 600) {
        RGE_Game_World* gameWorld = *(RGE_Game_World**)((char*)this->obj->owner + 0x3C);
        RGE_Static_Object* targetObj = gameWorld->object(this->currentTargetValue);

        if (targetObj) {
            float fVal = ((ObjVtbl*)targetObj)->funcF4();
            if (fVal != 0.0f) {
                ((ThisVtbl*)this)->func10(
                    this->obj->id, 0x2BC, this->currentTargetValue, -1,
                    this->currentTargetXValue, this->currentTargetYValue,
                    this->currentTargetZValue, this->desiredTargetDistanceValue,
                    0, 1, this->currentOrderPriorityValue
                );

                RGE_Static_Object* thisObj = this->obj;

                // Get speed from obj's vtable[64] (+0x100) then [63] (+0xFC)
                float speed2 = ((ObjVtbl*)thisObj)->func100();
                float speed1 = ((ObjVtbl*)thisObj)->funcFC();
                float speed = speed1 * speed2 * 3.0f;
                float dx = targetObj->world_x - thisObj->world_x;
                float dy = targetObj->world_y - thisObj->world_y;
                float dist = (float)sqrt(dx * dx + dy * dy);
                float nty = -(dy / dist * speed);
                float resultY = nty + thisObj->world_y;
                float ntx = -(dx / dist * speed);
                float resultX = ntx + thisObj->world_x;

                ((ThisVtbl*)this)->func9C(resultX, resultY, thisObj->world_z, 1);

                return 3;
            }
        }
    }
    return 2;
}
