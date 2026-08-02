// 00501B90 TribeTacticalAIModule::numberAvailableStoragePits
// PDB: taitacmd.cpp:12296-12337, 222 bytes
// __thiscall, int, ret 0Ch (3 params)
// FLAGS: default
//
// Attempt log:
// probe 1: 43.2% - block layout wrong (jne vs je)
// probe 2: 10.4% - layout fixed (if != -1 {main} else {alt})
//   remaining: register encoding only (esi for md, edi for capacity)
// probe 3: 28.4% - explicit md var, worse register allocation
//
// Session 2026-08-02 (sa-6032f135), 7 probes:
// - Canonical ownership established: md(+0xF0) -> RGE_Player(player+0xF0) ->
//   float* attributes(+0x50); capacity = (int)attributes[6] via __ftol (PDB
//   12313). sn is the real strategicNumbers[226] array at +0x194; +0x3EC =
//   sn[0x96], +0x48C = sn[param3+0xBE]. buildAI at md+0x104, resourceAI at
//   md+0x10D7C, informationAI at md+0xCEC (granaries sibling 00501C70 matched
//   with raw-cast md style; that style kept here).
// - Best clean reconstruction (this file, pinned): in-place multiply + named
//   result-first tail -> 12.16% (27 bytes, 3 spans), 222/222, calls 100%,
//   EXACT CODEGEN stage. md->edi, tail sub/store/clamp order correct.
// - Remaining drift is ONE localized VC5 register/scheduling basin:
//   orig keeps capacity in EAX through test/jne/mov/`imul eax,ebx` and saves
//   the product to ESI only right before the call; every rebuilt variant
//   coalesces capacity+product into a callee-saved register (esi or edi) and
//   sinks `imul` after the call. 4 variant-lab rounds (~47 source shapes:
//   in-place vs separate product, operand swap, store-first vs result-first,
//   named vs anonymous ternary, ghidra `((r<0)-1)&r` return, register/const
//   qualifiers, top-declared locals, multiply-in-return, param mutation) +
//   full real class surfaces (TacticalAIModule base + sn[226] + typed md
//   members with real sizes) + risky-flag sweep all collapse into the same
//   two basins; no third basin reaches the original. Store-first ternary
//   keeps imul before call but forces md->esi/product->edi plus an extra
//   mov; result-first is clean in the tail but coalesces/sinks.
// - Next lead: none obvious at single-function scope. Sibling 004E3E90
//   (TribeInformationAIModule::numberAvailableStoragePits) is stuck on the
//   same esi/edi register-swap family. A future worker might re-try md typed
//   as the real TribeMainDecisionAIModule (0x125C8) or check whether the
//   original source reused iVar3 for the product with an explicit separate
//   result variable under a slightly different TU include context.

#include <stdlib.h>

class BuildAIModule {
public:
    int numberUnbuiltItemsOfType(int type, int unk);  // 00409D40h, ret 8
    int numberItemsOfType(int type, int unk);          // 00409C70h, ret 8
};

class TribeResourceAIModule {
public:
    int resource(int type);                          // 004E6C70h, ret 4
};

class TribeInformationAIModule {
public:
    int numberAvailableStoragePits(int type);        // 004E3E90h, ret 4
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;   // +0x50
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;          // +0xF0
    char gap_F4[0x10];           // +0xF4 to +0x103
    BuildAIModule buildAI;       // +0x104
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;  // +0xF0
    char gap_F4[0x2F8];        // +0xF4 to +0x3EB
    int sn_3EC;                // +0x3EC (storage pit count?)
    char gap_3F0[0x9C];        // +0x3F0 to +0x48B
    int sn_array_48C[1];       // +0x48C indexed by resource type

    int numberAvailableStoragePits(int& param1, int& param2, int param3);
};

int TribeTacticalAIModule::numberAvailableStoragePits(int& param1, int& param2, int param3) {
    int unbuilt = ((BuildAIModule*)((char*)this->md + 0x104))->numberUnbuiltItemsOfType(0x67, 0);
    param2 = unbuilt;
    if (unbuilt > 0) {
        return 0;
    }

    int resource_val = ((TribeResourceAIModule*)((char*)this->md + 0x10D7C))->resource(param3);
    if (this->sn_array_48C[param3] <= resource_val) {
        return 0;
    }

    int storage_pit_count = this->sn_3EC;
    if (storage_pit_count != -1) {
        int capacity = (int)this->md->player->attributes[6];
        if (capacity == 0) {
            capacity = 1;
        }
        capacity *= storage_pit_count;
        int count = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x67, 0);
        int result = capacity - count;
        param1 = count;
        return result < 0 ? 0 : result;
    } else {
        int count = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x67, 0);
        param1 = count;
        return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->numberAvailableStoragePits(param3);
    }
}
