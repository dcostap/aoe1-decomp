// 00505CC0 TribePriestUnitAIModule::bestUnitToConvert
// taiuaimd.cpp:1517-1558, 263 bytes
//
// int __thiscall TribePriestUnitAIModule::bestUnitToConvert(float* param_1)
// - ret 4 cleanup (1 stack param + this in ecx)
//
// Returns: best unit ID (int), or -1 if none found
// param_1: optional output for priority value (can be NULL)
//
// === Attempt log ===
// 1: C-style function pointer virtual calls; RGE_Player class with virtual
//    Compiles to 263 bytes, 79% positional diff (~208 bytes mismatched)
//    Virtual calls use __cdecl (ecx not set = wrong calling convention)
//    Stack frame: sub esp,10h + push ebx,ebp vs sub esp,0Ch + push ebp,edi
//    Same TU-context register cascade as other view/tai functions
// 2: No virtual functions in any class — .text section issue (263 > 256)
//    Function body 246 bytes (17 bytes short of original)
// BLOCKER: TU-context register allocation + calling convention for virtual
//          dispatch vs function pointers in standalone C source

#include <stdlib.h>

extern int DAT_0087d7d8;
extern int* DAT_0087d7f0;

struct RGE_MasterObj {
    char _pad0[0x26];
    short hp;
};

struct RGE_StaticObj {
    void* vtbl;
    int id;
    RGE_MasterObj* master;
    void* owner;
    char _pad1[0x48 - 0x10];
    unsigned char obj_state;
};

class UnitAIModule {
public:
    void* vtbl;
    RGE_StaticObj* obj;
    char _pad2[0x130];

    RGE_StaticObj* lookupObject(int unit_id);
};

class TribePriestAIMod : public UnitAIModule {
public:
    int bestUnitToConvert(float* param_1);
};

int TribePriestAIMod::bestUnitToConvert(float* param_1)
{
    // vtable[0x20] — slot 8: update (ecx still = this from function entry)
    ((void (*)())((void**)(*(void**)this))[8])();

    int best_id = -1;
    int i = 0;
    float targetValue = 0.0f;

    if (DAT_0087d7d8 > 0) {
        do {
            int byte_offset = i * 8;
            int* table_base = DAT_0087d7f0;

            // Check type via owner's vtable[0x18] — slot 6
            unsigned char type_byte = ((unsigned char*)table_base)[byte_offset + 5];
            void* owner = this->obj->owner;
            int type_ok = ((int (*)(void*, unsigned char))((void**)(*(void**)owner))[6])(owner, type_byte);

            if (type_ok != 0) {
                int unit_id = *(int*)((char*)table_base + byte_offset);
                RGE_StaticObj* found = this->lookupObject(unit_id);

                if (found != 0 && found->obj_state < 3) {
                    // vtable[0xC4] — slot 49: conversion check (ecx NOT set = BUG)
                    int check_ok = ((int (*)(int))((void**)(*(void**)this))[49])(found->id);

                    if (check_ok != 0) {
                        unsigned char pri_byte = ((unsigned char*)table_base)[byte_offset + 4];
                        float priority = (float)pri_byte;
                        if (priority < 1.0f)
                            priority = 1.0f;

                        short hp_short = found->master->hp;
                        float hp_float = (float)hp_short;
                        float score = hp_float / priority;

                        if (best_id == -1 || score > targetValue) {
                            targetValue = score;
                            best_id = found->id;
                            if (param_1 != 0)
                                *param_1 = priority;
                        }
                    }
                }
            }

            i++;
        } while (i < DAT_0087d7d8);
    }

    return best_id;
}
