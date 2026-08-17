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
// Follow-up 2026-08-12 (follow-501B90-r1): exact 00501D70 nested layout review
// corrected false ownership. TribeBuildAIModule is the typed build subobject;
// TribeInformationAIModule is standalone at +0xCEC and TribeResourceAIModule
// follows at +0x10D7C. Tactical strategicNumbers[226] owns +0x3EC and +0x48C.
//
// Probe 1 baseline: current six-byte register basin with the old narrow
// declarations. Probe 2: full AIModule/TribeMainDecision nested layout moved
// resourceAI incorrectly because informationAI was falsely derived. Probe 3:
// standalone informationAI restored the six-byte basin. Probe 4: a branch-local
// typed decision pointer duplicated it. Probe 5: named strategicNumbers[226]
// ownership duplicated it. Probe 6: direct post-gate strategic count duplicated
// it. Probe 7: branch-local tactical reference duplicated it. Probe 8: literal
// result locals regressed to the known 27-byte basin and was rolled back.
//
// Current canonical source is the typed nested layout with named strategic
// numbers. It is natural and behaviorally complete. Remaining drift is six
// register-encoding bytes: original md is EDI and the product is ESI; VC5
// keeps the rebuilt md in ESI and product in EDI. Donor 004F5FB0 shows that
// post-md this-member liveness can produce the original coloring, but natural
// forms tested here do not preserve it without a codegen-only alias.
// - Current TU pass: the dossier confirms exact size, frame, CFG, calls, and
//   six relocation-safe byte differences. Donor search again identifies the
//   same post-md this-liveness pattern, but direct strategic-number rereads
//   already tested in this source produce the same basin. The 00501D70 nested
//   layout remains canonical; no new natural ABI or ownership lead remains.
//
// Fresh bounded pass (sa-d6fdf820-r1): named attributes pointer, storage-count
// reference, original scalar declaration order, direct post-call md use,
// inline storage-count accessor, branch-local capacity declaration, decision
// pointer declaration order, and TRIBE_Player-derived player typing all kept
// exact size/CFG/call parity but reproduced the six-byte md/product register
// basin. The reference and derived-player forms were rolled back because they
// are not canonical source facts here. The current source is restored to the
// pinned natural nested-layout reconstruction.
// Fresh bounded pass (sa-37ed7ad3-r1): compared the 004E3E90 sibling's
// InformationAIModule inheritance, full TribeBuild virtual surface, complete
// tactical extent (0x100C), function-scope md lifetime, separate storage-limit
// local, and minimal header context. All retained the 222-byte / six-byte
// md-product register-swap basin. The clean nested-layout source is restored.
// Fresh bounded pass (sa-92b4ab98-r1): scoped capacity/product/count locals
// and direct natural remaining-value data flow both regressed to the known
// 27-byte scheduling basin. Restored the clean typed reconstruction; the
// remaining six bytes are still only md/product register encodings.
// Revisit (sa-c6deaba1-r1): tested direct post-md strategic rereads, old
// capacity-in-place and product/count local lifetimes, unsigned product,
// expression-level subtraction, and top-scope count. The separate-count
// forms keep md in EDI but sink imul after the count call (27 bytes); reusing
// the proven count home restores the 222-byte six-byte md/product basin.
// Restored the pinned natural source. No new exact natural lead remains.
//
// Translation-unit reconstruction pass (sa-10694da2-r1): 16 focused context
// probes kept the body unchanged and preserved the 222-byte size, six calls,
// and full CFG. Standard-header combinations, repository game headers, late
// and early neutral declaration sweeps, inline and exception pragmas, and
// supported flag variants all emitted the same six-byte basin. Exact same-TU
// AI surfaces from 00502920, full tactical ManagedArray members, full player
// virtual slots, the 00501B50 preceding function body, exact donor declaration
// order, non-polymorphic 00501C70-style surfaces, and inherited information
// surfaces also emitted the same six-byte basin. No context or function-order
// lead changes md from ESI to EDI without changing the body or adding a fake
// liveness use. The pinned natural source remains authoritative.
// Object audit: FPO, PDB, COFF, owner, six relocations, field offsets, and ABI
// all match. PDB has no omitted local or inline frame that can keep this live.
// The remaining md/product swap is allocator coloring; a fake later this use
// remains unsupported.
//
// Exact finish (sa-5dc5a657-r1, 2026-08-17): DIA records only this and the
// PDB parameters numStoragePits, numUnbuiltStoragePits, and rType. The target
// has two int references and one int parameter. Renaming parameters to these
// names and changing declaration order did not change the six-byte basin.
// DIA reports a thiscall function type with const=0, so the method stays
// non-const; the decorated symbol also proves the two-reference ABI.
// A natural direct assignment of the final build count to the first reference
// changed the basin to an exact 222-byte match. The prior local-plus-copy form
// was walked back and restored the six-byte mismatch. Removing the branch-local
// decision alias also stayed exact, so direct typed md expressions are retained.
// Current source preserves InformationAIModule inheritance, the +0xF0 member
// frontier, informationAI size 0x10090, resourceAI +0x10D7C, six ordered calls,
// and the original behavior.

#include <stdlib.h>

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class BuildAIModule : public AIModule {
public:
    int numberUnbuiltItemsOfType(int type, int unk);  // 00409D40h, ret 8
    int numberItemsOfType(int type, int unk);          // 00409C70h, ret 8
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x5C0 - 0xF0];
};

class TribeResourceAIModule : public AIModule {
public:
    char gap_F0[0x08];
    int resource(int type);                          // 004E6C70h, ret 4
};

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class TribeMainDecisionAIModule;

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray_int farmsTaskedThisUpdate; // +0xF0
    TribeMainDecisionAIModule* md;          // +0x100
    char gap_104_to_500[0x500 - 0x104];
    int dropsitesByAge[4][4];               // +0x500
    int closestDropsiteValue[4];            // +0x540
    int closestDropsiteResourceID[4];       // +0x550
    char gap_560_to_10090[0x10090 - 0x560];
    int numberAvailableStoragePits(int type);        // 004E3E90h, ret 4
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x4C];
    float* attributes;   // +0x50
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;          // +0xF0
    char gap_F4[0x10];           // +0xF4 to +0x103
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;       // +0x104
    char gap_6C4[0xCEC - 0x6C4];
    TribeInformationAIModule informationAI; // +0xCEC
    // informationAI ends at +0x10D7C; resourceAI follows it in the
    // original nested decision-module layout.
    TribeResourceAIModule resourceAI;       // +0x10D7C
};

class TacticalAIModule : public AIModule {
public:
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;  // +0xF0
    char gap_F4[0xA0];         // +0xF4 to +0x193
    int sn[226];               // +0x194; strategic-number table

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
    if (this->sn[param3 + 0xBE] <= value) {
        return 0;
    }

    value = this->sn[0x96];
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
        param1 = this->md->buildAI.numberItemsOfType(0x67, 0);
        return this->md->informationAI.numberAvailableStoragePits(param3);
    }
}
