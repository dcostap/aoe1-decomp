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
//
// This claim (10 meaningful probes): restoring distinct iVar3/iVar4/uVar5
// roles and reusing iVar3 for the post-call count moved 27 -> 6 bytes and
// restored all block/CFG parity. Direct md use, declaration reordering,
// register qualifiers on md/product/result, signed result storage, and the
// explicit md-local form all emitted the same 6-byte register-swapped basin.
// Initializing uVar5 with the product then compound-subtracting the call
// result regressed to the 27-byte capacity-coalesced basin and was rolled back.
// Final blocker: original uses EDI for md and ESI for the pre-call product;
// this canonical source emits the same roles swapped (6 single-byte register
// encoding differences). Left in scratch for a future TU/context lead.
// Main-agent normalization replaced decompiler local names and raw leading
// gaps with descriptive roles and donor-backed polymorphic ownership; emitted
// code remains the same 6-byte register-encoding mismatch.
// Main-agent audit replaced cross-member raw casts with canonical named
// main-decision submodule ownership.
// Current session probe: a top-level md alias used across both branches
// regressed to a 197-byte structural basin (209 differing bytes); restored.
// Fresh bounded pass (orch-taitacmd-02): derived md typing at size 0x125C8,
// branch-initialized md lifetime, same-TU math.h context, full proven md
// subobject sizes, and a branch-local md reference all emitted the same exact
// 222-byte / six-byte register-swapped basin. A positive-branch BuildAIModule
// pointer alias regressed structurally to 224 bytes / 113 differing bytes and
// was restored. No ABI, call, layout, or behavior uncertainty remains.
// Fresh bounded pass (sa-89b3fb34-r1): declaration-order variants, nested
// md/self aliases, direct storage-count rereads, stdio context, 32-bit long
// local widths, and proper TacticalAIModule/MainDecisionAIModule/AIModule
// virtual-base surfaces all reproduced the same 222-byte six-byte basin.
// Restored the pinned canonical source; no new codegen lead was found.
// Bounded pass (orch2-501B90-live): natural direct this->sn_3EC use in the
// main-path product reproduced the prior six-byte basin with no movement.
// Restored the pinned canonical source; no natural donor-backed liveness lead
// remains without adding a redundant or non-behavioral member use.
// Bounded pass (orch-00501B90-D): re-ran dossier/donors/ABI. search_asm_donors
// on +0053-+0064 found the only same-TU exact donor with the target's exact
// register topology: 004F5FB0 emits `mov edi,[esi+0F0h]` (md->EDI, this stays
// ESI) because its source reads this->sn[0xB0] AFTER the md load
// (`mov eax,[esi+454h]` at 004F60B5). Liveness theory: original keeps this in
// ESI through the md load (md->EDI, reusing param3's dead EDI slot LIFO), and
// kills this only at the product move (+008B, mov esi,eax); the rebuilt kills
// this at the md load itself (destructive mov esi,[esi+0F0h]; product->EDI).
// Next lead: spell the main path so a this-based member is still read after
// the md load (mirroring the donor's liveness) without adding instructions,
// e.g. a source construct that keeps this live to the product point; prior
// probes never tested a main-path this read between +005E and +008B.

#include <stdlib.h>

class BuildAIModule {
public:
    virtual ~BuildAIModule();
    int numberUnbuiltItemsOfType(int type, int unk);  // 00409D40h, ret 8
    int numberItemsOfType(int type, int unk);          // 00409C70h, ret 8
};

class TribeResourceAIModule {
public:
    virtual ~TribeResourceAIModule();
    int resource(int type);                          // 004E6C70h, ret 4
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int numberAvailableStoragePits(int type);        // 004E3E90h, ret 4
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;   // +0x50
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;          // +0xF0
    char gap_F4[0x10];           // +0xF4 to +0x103
    BuildAIModule buildAI;       // +0x104
    char gap_108[0xCEC - 0x108];
    TribeInformationAIModule informationAI; // +0xCEC
    char gap_CF0[0x10D7C - 0xCF0];
    TribeResourceAIModule resourceAI;       // +0x10D7C
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    MainDecisionAIModule* md;  // +0xF0
    char gap_F4[0x2F8];        // +0xF4 to +0x3EB
    int sn_3EC;                // +0x3EC (storage pit count?)
    char gap_3F0[0x9C];        // +0x3F0 to +0x48B
    int sn_array_48C[1];       // +0x48C indexed by resource type

    int numberAvailableStoragePits(int& param1, int& param2, int param3);
};

int TribeTacticalAIModule::numberAvailableStoragePits(int& param1, int& param2, int param3) {
    int product;
    int value;
    int capacity_or_count;
    unsigned int remaining;

    value = this->md->buildAI.numberUnbuiltItemsOfType(0x67, 0);
    param2 = value;
    if (value > 0) {
        return 0;
    }

    value = this->md->resourceAI.resource(param3);
    if (this->sn_array_48C[param3] <= value) {
        return 0;
    }

    value = this->sn_3EC;
    if (value != -1) {
        capacity_or_count = (int)this->md->player->attributes[6];
        if (capacity_or_count == 0) {
            capacity_or_count = 1;
        }
        product = capacity_or_count * value;
        capacity_or_count = this->md->buildAI.numberItemsOfType(0x67, 0);
        remaining = product - capacity_or_count;
        param1 = capacity_or_count;
        return ((int)remaining < 0) ? 0 : remaining;
    } else {
        value = this->md->buildAI.numberItemsOfType(0x67, 0);
        param1 = value;
        return this->md->informationAI.numberAvailableStoragePits(param3);
    }
}
