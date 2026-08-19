// RGE_Victory_Conditions::handle_points_high_attribute_once
// VA: 00533330
// victory.cpp
// Attempt log:
// - Probe 1 (baseline): natural for-loop, walking pp = players+1, per-iteration re-reads of
//   this->player->id / world->player_num. Recovered push ecx frame, size 224, both ftol calls,
//   param-slot reuse for val; diff 217 -> 61. Remaining: prologue register roles and tail arms.
// - Probe 2: guarded do/while with pp++ at top (Ghidra shape) -> frame 0x8, diff 221 (self local
//   forced a stack home); rolled back. For-loop was the right basin.
// - Probe 3: flipped final if/else arms to `>=` with points inline -> original je-to-end tail
//   layout; diff 61 -> 43, tail region byte-exact.
// - Probes 4-6: p=entry alias / entry direct, do/while variants -> no better; register coloring
//   (entry in ebx vs original edi) was the only remaining gap at 43.
// - Probes 7-8: guard-if with pp init inside (pp = players+1 after jle) + do/while bottom
//   increments -> 32; then pp = players pre-guard + pp++ inside guard + do/while bottom i++/pp++
//   -> 29, shape 96.4%, blocks 88.1%, loop prelude order matches (cmp; mov players; jle; add 4).
// - Probes 9-11: register on pp, plain for-loop with separate pp=players+1 statement -> 43, no
//   flip; rolled back to the 29-byte do/while form. `register` on pp is a no-op.
// - Left in scratch: remaining 29 bytes = pure register coloring swap: rebuilt keeps entry in ebx
//   and pp in edi while the original keeps entry in edi and pp in ebx (same push order ebx/ebp/
//   esi/edi). Prologue interleave and every [reg+X] operand differ only by that swap. All calls,
//   frame, size, CFG, block topology, and tail are exact. Next lead: a source/type-surface change
//   that makes VC5 allocate the loop-invariant pp (not entry) to ebx (donor 00533180 gives ebx to
//   the loop-invariant scaled attribute; all matched victory.cpp donors keep entry in edi).
// - A 12-variant natural surface lab (parameter register, guard polarity, and
//   pointer-array constness) formed one 224-byte codegen group at the same 29-byte
//   entry/pp register swap; clean typed source retained.
// - Main-agent audit restored canonical polymorphic player/world/victory
//   ownership and removed the raw vftable field.
// - New TU-context pass: constructor-recovered victory vtable slots (without virtual destructor),
//   world virtual slot, and read-only attributes field were all codegen duplicates. The
//   recovered constructor/class context therefore gives no new lead beyond the documented
//   29-byte entry/pp register-color swap.
// - orch-victory-02 bounded pass: constructor/save evidence added the +0x18 next link and
//   32-bit int temporary surfaces; both were codegen-neutral. Ghidra-shaped attribute/result
//   reuse, transient player-owner refreshes, and eight declaration-initialization variants all
//   remained one 29-byte codegen group. A field-only/minimal class surface regressed to 37 bytes
//   and was restored. The remaining gap is still only the EBX/EDI entry-versus-player-array
//   coloring (original entry=EDI, rebuilt entry=EBX); no call, frame, CFG, layout, or behavior
//   blocker changed.
// - wave21-victory-01 probes: a binary-supported entry alias before the state guard, positive
//   state-guard spelling, pp-first function-scope declarations, and a const attributes pointer
//   all emitted the same 224-byte/29-byte-diff codegen group; each was restored. The clean
//   natural do/while source remains authoritative; the unresolved gap is still only entry/pp
//   callee-save coloring.
// - sa-5b01da12-r1 probes: preloading pp before the initial attribute read did select the
//   oracle's entry=EDI/pp=EBX colors, but forced early world/players loads, a shifted initial
//   FPU sequence, and 196-214 bytes of structural drift; rolled back. Null-initializing pp,
//   naming the reused attribute index, and reordering pp/i declarations were neutral or
//   duplicate 29-byte codegen. Clean source restored; no ABI/call/layout lead remains.
// - orch-00533330-L bounded pass: adding a victory destructor, removing the pp register
//   qualifier, stdlib/string header context, an inline attribute accessor, and long result
//   types were duplicate or neutral 29-byte groups. A short index widened the drift to 147
//   bytes; a persistent player local widened it to 207 bytes; removing player/world
//   destructors widened it to 37 bytes. All were rolled back. The clean source remains the
//   best canonical reconstruction; the only gap is entry=EBX versus original entry=EDI and
//   pp=EDI versus original pp=EBX callee-save coloring.
// - close-533330-r1 probe: mirrored the exact victory.cpp sibling's player and point-entry
//   aliases inside the positive state guard; frame grew to 0x8 and diff to 236, so restored.
// - close-533330-r1 probe: made the reused attribute/result local a period long; output was
//   unchanged at 224 bytes and 29-byte diff, so restored.
// - close-533330-r1 probe: captured player only for the loop self-id test; frame grew to 0x8
//   and diff to 230, so restored. No new source or ABI lead remains.
// - tu-victory-533330 probe: removed the no-op register qualifier from the natural player-array
//   cursor; output stayed at 224 bytes and a 29-byte diff. The clean source is now ordinary typed
//   C++ with the exact sibling loop retained; only EBX/EDI coloring remains.
// - sa-1ed6a47a-r1 ABI probe: normalized RGE_Game_World slot 0 to the exact-donor
//   virtual unsigned char data_load_world(void*) surface instead of a virtual destructor;
//   codegen stayed unchanged at 224 bytes and a 29-byte diff. No new ABI lead remains.
// - shardE-533330 initialized a period-plausible point-entry alias before the state guard;
//   VC5 folded it away and kept the 224-byte, 29-byte register-coloring gap.
// - shardE-533330 delayed and then block-scoped an ordinary player alias around the scan;
//   both forms created the 0x8 frame and 233-byte structural drift, so both were restored.
// - sa-ba695c8f-r1 introduced one ordinary point-entry alias and used it throughout; VC5 emitted
//   the same 224-byte, 29-byte register-coloring group.
// - sa-ba695c8f-r1 reversed the state guard into a positive body; output stayed unchanged.
// - sa-ba695c8f-r1 moved the result declaration before val; output stayed unchanged.
// - sa-ba695c8f-r1 scoped a player alias to the initial attribute conversion; output stayed
//   unchanged. Clean typed source restored; no source-backed lead remains beyond EBX/EDI coloring.
// - sa-563b4173-r1 baseline validation confirmed 224 bytes, exact calls/frame/CFG, and a 29-byte
//   PARTIAL_REGISTER_RECOLOR gap: original entry=EDI/pp=EBX, rebuilt entry=EBX/pp=EDI.
// - This pass tested a register-qualified entry parameter, a post-guard point-entry alias, a
//   point-entry reference alias, and long val/result locals. Each was codegen-neutral.
// - A 64-variant ambient file-scope declaration lab formed one 224-byte/29-byte codegen group.
//   A Ghidra-shaped named attribute/player source widened the frame to 0x8 and diff to 208 bytes;
//   both families were restored. No natural source or ABI lead changed the register-color gap.
// - CodeView symbols identify the parameter as `node` and the reused conversion temporary as
//   `long amount`; the PDB class records confirm the point-entry long fields and exact pointer
//   ownership. A positive state block and implicit float-to-long initialization both emit the
//   same 224-byte/29-byte group. The unresolved gap remains only entry=EBX versus original
//   entry=EDI and player-array cursor=EDI versus original EBX.
// - Object/CodeView audit: DIA finds compiland `victory.obj` with compiler string
//   `Microsoft (R) 32-bit C/C++ Optimizing Compiler Version 11.00`. The target has exactly two
//   function debug boundary records, then only `this`, `node`, and `amount`. `this` is ECX;
//   `node` is RegRel VFRAME (+4), and `amount` is RegRel VFRAME (+8), both with zero live-range
//   data. No `pp`, `i`, result, or other hidden local appears. The target has zero inline frames.
// - CodeView type audit: `node` points to the complete 0x1C `RGE_Victory_Point_Entry`; its ten
//   members are at 0,1,2,3,4,8,C,10,14,18. The PDB UDTs also prove `RGE_Player` size 0x220 with
//   world +3C, id +4A, attributes +50; `RGE_Game_World` size 0x104 with player_num +3C and
//   players +40; and `RGE_Victory_Conditions` size 0x20 with player +0C and total +1C.
// - FPO/COFF audit: original and rebuilt target FPO records both report 224 bytes, 4 local
//   dwords, 4 saved registers, zero prolog, BP=Y, SEH=N, fpo, and 4 parameter bytes. The rebuilt
//   COFF has one 224-byte .text COMDAT, two __ftol REL32 relocations, and one associative
//   .debug$F record; its 16-byte FPO payload matches the original after the function-start
//   relocation. The original PE has no COFF symbols and records only NB10 CodeView plus FPO.
//   These records support the pinned VC5 11.00.7022/5.00.7022 toolchain, not another source.
// - Object-level conclusion: the PDB is incomplete for optimized local ranges, but it gives no
//   hidden inline context or natural local that could select the inverse EBX/EDI colors. The
//   clean typed source remains authoritative; no alias, volatility, raw offset, or ABI change
//   is supported by this audit.
// - sa-7e040161-r1 pass: sixteen clean-source probes tested amount and pp declaration scope,
//   loop update operators and order, nested threshold control flow, comparison direction,
//   conversion width and spelling, const-qualified array slots, players[0] addressing, and
//   parameter constness. Fifteen emitted the pinned 224-byte/29-byte group; reversed updates
//   widened it to 32 bytes, and a const parameter changed the decorated ABI. All variants were
//   restored. The canonical source remains the clean typed reconstruction; the only gap is the
//   unsupported entry=EBX versus original entry=EDI and pp=EDI versus original pp=EBX colors.
// ACCEPTED DRIFT: All 29 changed bytes exchange EBX and EDI for the point entry
// and player-array cursor. Every field access, conversion, comparison, call,
// branch, point update, total update, return, and fault order remains unchanged.

class RGE_Game_World;
class RGE_Victory_Entry;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;    // +0x3C
    char gap_40[0x0A];
    short id;                 // +0x4A
    char gap_4C[4];
    float* attributes;        // +0x50
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num;         // +0x3C
    char gap_3E[2];
    RGE_Player** players;     // +0x40
};

class RGE_Victory_Point_Entry {
public:
    unsigned char command;    // +0x00
    unsigned char state;      // +0x01
    unsigned char id;         // +0x02
    unsigned char group;      // +0x03
    long attribute;           // +0x04
    long amount;              // +0x08
    long points;              // +0x0C
    long curr_points;         // +0x10
    float curr_attribute_amount; // +0x14
    RGE_Victory_Point_Entry* next; // +0x18
};

class RGE_Victory_Conditions {
public:
    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);
    RGE_Victory_Entry* victory_list; // +0x04
    long list_num;            // +0x08
    RGE_Player* player;       // +0x0C
    unsigned char victory;    // +0x10
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list; // +0x14
    long point_list_num;      // +0x18
    long tot_victory_points;  // +0x1C

    void handle_points_high_attribute_once(RGE_Victory_Point_Entry* node);
};

void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* node) {
    if (node->state == 0) {
        long amount = this->player->attributes[node->attribute];
        if (node->curr_attribute_amount < (float)amount) {
            node->curr_attribute_amount = (float)amount;
        }

        int i = 1;
        RGE_Player** pp = this->player->world->players;
        if (i < this->player->world->player_num) {
            pp++;
            do {
                if (i != this->player->id && (float)node->amount <= (*pp)->attributes[node->attribute]) {
                    node->amount = (long)(*pp)->attributes[node->attribute];
                }
                i++;
                pp++;
            } while (i < this->player->world->player_num);
        }

        int result;
        if (node->curr_attribute_amount >= (float)node->amount) {
            result = node->points;
        } else {
            result = (amount == node->amount) ? node->curr_points : 0;
        }

        if (result != node->curr_points) {
            this->tot_victory_points += result - node->curr_points;
            node->curr_points = result;
        }
    }
}
