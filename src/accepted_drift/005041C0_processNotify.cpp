// VA: 005041C0, TribeElephantUnitAIModule::processNotify, 261 bytes
// Source: taiuaimd.cpp lines 274-317
// ACCEPTED_DRIFT: register allocation (ebp/ecx swap for caller/count) and copy loop
// pattern differ slightly. All behavior identical.
//
// Remaining drift:
// 1. Register swap: original keeps caller in ebp, count in ecx. My compiler
//    reverses this (caller in ecx saved to stack, count in ebp). This adds 4 bytes
//    for the stack save (`mov [esp+18h], ecx`).
// 2. Copy/reallocation loop uses different register allocation and slightly
//    different instruction scheduling (same structure, different registers).
// 3. The original uses `jg short` for p2 check (body=jump target, purge=fallthrough);
//    this layout is achieved with `if (event->p2 <= 0)` in the switch.
//
// What matches (first 90 bytes): prologue, switch dispatch (sub/je chain), default
// parent call, return-2 path, p2 check (jg short), purge/return-4 path.
// Also matches: search loop structure (scaled-index access, capacity reload per
// iteration), store-to-array, virtual call sequence (funcEC/func3C/func5C), epilogues.
//
// Attempt log:
// - v1: if-else chaining → cmp not sub for dispatch, wrong NotifyEvent layout
// - v2: switch dispatch, fixed NotifyEvent layout (p2 at +0x10), loop structure off
// - v3: switch → sub pattern works (63 bytes match), p2 check wrong branch layout
// - v4: attempted raw-offset hacks (failed)
// - v5-v6: refined loop structure
// - v7: raw-offset access forced correct scaled-index loop, register allocation off
// - v8: declaration order didn't help register allocation
// - v9: goto-based layout attempt
// - v10: if(p2<=0) fixes branch layout (90 bytes match), register allocation persists
// FLAGS: /nologo /c /O2 /Oy

#ifndef TAIUAIMD_COMPLETE_TU
typedef unsigned char uchar;

struct NotifyEvent {
    int caller;
    int field_04;
    int mType;
    int field_0C;
    int p2;
};

void* operator_new(unsigned int size);
void operator_delete(void* ptr);

struct CallECHelper {
    virtual void s00();  virtual void s01();  virtual void s02();  virtual void s03();
    virtual void s04();  virtual void s05();  virtual void s06();  virtual void s07();
    virtual void s08();  virtual void s09();  virtual void s10();  virtual void s11();
    virtual void s12();  virtual void s13();  virtual void s14();  virtual void s15();
    virtual void s16();  virtual void s17();  virtual void s18();  virtual void s19();
    virtual void s20();  virtual void s21();  virtual void s22();  virtual void s23();
    virtual void s24();  virtual void s25();  virtual void s26();  virtual void s27();
    virtual void s28();  virtual void s29();  virtual void s30();  virtual void s31();
    virtual void s32();  virtual void s33();  virtual void s34();  virtual void s35();
    virtual void s36();  virtual void s37();  virtual void s38();  virtual void s39();
    virtual void s40();  virtual void s41();  virtual void s42();  virtual void s43();
    virtual void s44();  virtual void s45();  virtual void s46();  virtual void s47();
    virtual void s48();  virtual void s49();  virtual void s50();  virtual void s51();
    virtual void s52();  virtual void s53();  virtual void s54();  virtual void s55();
    virtual void s56();  virtual void s57();  virtual void s58();
    virtual void funcEC(int arg);  // slot 59 -> vtable[0xEC]
};

class UnitAIModule {
public:
    virtual void _v00(); virtual void _v01(); virtual void _v02();
    virtual void _v03(); virtual void _v04(); virtual void _v05();
    virtual void _v06(); virtual void _v07(); virtual void _v08();
    virtual void _v09(); virtual void _v10(); virtual void _v11();
    virtual void _v12(); virtual void _v13(); virtual void _v14();
    virtual int func3C(int arg);   // vt[15]: +0x3C
    virtual void _v16(); virtual void _v17(); virtual void _v18();
    virtual void _v19(); virtual void _v20(); virtual void _v21();
    virtual void _v22();
    virtual void func5C(int arg1, int arg2);  // vt[23]: +0x5C

    void* objectValue;  // +0x04

    int processNotify(NotifyEvent* event, unsigned long param_2);
    void purgeNotifyQueue(unsigned long param_2);
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x58];      // +0x08 to +0x5F
    int* notifyArray;       // +0x60
    int notifyCount;        // +0x64
    int gap_68;             // +0x68
    int notifyCapacity;     // +0x6C

    int processNotify(NotifyEvent* event, unsigned long param_2);
};
#endif

int TribeElephantUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 500:
        if (event->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }
        {
            int caller = event->caller;
            int count = this->notifyCount;
            int i = 0;
            if (count > 0) {
                goto loop_check;
                do {
                    if (i >= this->notifyCapacity)
                        goto after_loop;
                    if (this->notifyArray[i] == caller)
                        goto found;
                    i++;
loop_check:;
                } while (i < count);
after_loop:;
            }

            if (count >= this->notifyCapacity) {
                int newCapacity = count + 1;
                int* newArray = (int*)operator_new(newCapacity * 4);
                if (newArray != 0) {
                    int j = 0;
                    if (count > 0) {
                        while (j < newCapacity && j < count) {
                            newArray[j] = this->notifyArray[j];
                            j++;
                        }
                    }
                    operator_delete(this->notifyArray);
                    this->notifyArray = newArray;
                    this->notifyCapacity = newCapacity;
                }
            }
            this->notifyArray[this->notifyCount] = caller;
            this->notifyCount++;
found:
            ((CallECHelper*)(this->objectValue))->funcEC(1);
            int val = this->func3C(0);
            this->func5C(val, 0);
            return 3;
        }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }
}
