// VA: 004FAC90, TribeTacticalAIModule::taskFollower, 260 bytes
// Source: taitacmd.cpp lines 8919-8929
// FLAGS: default
//
// Attempt log:
// - v1: __stdcall function pointers for vtable[0x30] → extra 'player' push on stack (13 vs 12 args)
// - v2: float arg casts (int)(-1.0f) → FPU instructions added, wrong
// - v3: hex constants 0xBF800000 → generates direct push, cleaner but extra stack slot
// - v4-6: various loop structures (for, do-while, while) and variable scoping
// - v7: PlayerVf30Proxy struct with 12 virtual dummies + v30 pure virtual.
//   Generates correct thiscall dispatch: ecx=player, exact 12-push sequence.
//   Prologue matches byte-exact (offset 0-12: 53 55 8b 6c 24 0c 56 8b f1 33 c0 57)
// - v8-10: ManagedIntArray struct (corrects +0xD60/+0xD64 offsets), various hoisting prevention tricks
// - variant_lab: tested 3 structural variants (direct_member, locals, for_loop). 
//   Best: direct_member, text_size=256, first_mismatch=13, edit_diff=103
//
// Remaining blockers:
// 1. Register allocation: original loads 'count' (this->taskedUnits.numberValue, +0xD5C) into ECX.
//    My code loads into EDX. First byte diff at offset 13. This cascades through the entire function
//    (every subsequent register choice differs: original uses ecx/edx/edi for count/maxSize/value,
//    mine uses edx/edi/ecx). All source structure variants produce EDX for count.
// 2. 4 bytes short (256 vs 260): the original has a redundant `mov edx,[esp+24h]` reload of param_4
//    between the two param_4 pushes in the vtable call. My VC5 does CSE and reuses the register,
//    saving 4 bytes. No source trick found to force the reload.
// 3. The call's instruction schedule also differs: original loads vtable (mov eax,[ecx]) AFTER the
//    -1.0f pushes but BEFORE the param_2 push; my code loads vtable BEFORE the -1.0f pushes.
//
// Everything else: prologue, search/grow/append logic, vtable call push order all match the original.
// The vtable proxy approach (PlayerVf30Proxy) correctly generates thiscall dispatch.

#include <stddef.h>

extern "C" void* __cdecl operator_new(size_t size);
extern "C" void __cdecl operator_delete(void* ptr);

// VTable proxy for RGE_Player vtable[0x30] (slot 12). Generates thiscall dispatch.
struct PlayerVf30Proxy {
    virtual void v00() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void v20() {}
    virtual void v24() {}
    virtual void v28() {}
    virtual void v2C() {}
    virtual int v30(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
};

struct ManagedIntArray {
    int* value;              // +0x00
    int numberValue;         // +0x04
    int desiredNumberValue;  // +0x08
    int maximumSizeValue;    // +0x0C
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    void* md;                       // +0xF0
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray taskedUnits;    // +0xD58 (size 0x10)

    int taskFollower(int param_1, int param_2, float param_3, int param_4);
};

int TribeTacticalAIModule::taskFollower(int param_1, int param_2, float param_3, int param_4)
{
    int i = 0;
    int count = this->taskedUnits.numberValue;

    // Search for existing entry
    if (count > 0) {
        int cap;
        cap = this->taskedUnits.maximumSizeValue;
        do {
            if (i >= cap) break;
            if (this->taskedUnits.value[i] == param_1)
                goto call_v30;
            i++;
        } while (i < count);
    }

    // Grow if needed
    if (count >= this->taskedUnits.maximumSizeValue) {
        int newSize = count + 1;
        int* newArray = (int*)operator_new(newSize * 4);
        if (newArray != 0) {
            for (int j = 0; j < this->taskedUnits.maximumSizeValue; j++)
                newArray[j] = this->taskedUnits.value[j];
            operator_delete(this->taskedUnits.value);
            this->taskedUnits.value = newArray;
            this->taskedUnits.maximumSizeValue = newSize;
        }
    }

    // Append unit
    this->taskedUnits.value[this->taskedUnits.numberValue] = param_1;
    this->taskedUnits.numberValue++;

call_v30:
    // Virtual call: player->vf30(...)
    // Generates thiscall dispatch: ecx=player, 12 stack args in correct order
    void* playerP = *(void**)((char*)this->md + 0xF0);
    short field4A_short = *(short*)((char*)playerP + 0x4A);
    ((PlayerVf30Proxy*)playerP)->v30((int)field4A_short, param_1, 0x2C8, param_2, -1,
        (int)(-1.0f), (int)(-1.0f), (int)(-1.0f), param_4, 1, 0, param_4);
    return 1;
}
