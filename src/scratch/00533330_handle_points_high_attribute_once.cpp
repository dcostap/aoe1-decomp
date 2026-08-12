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

class RGE_Game_World;

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
    virtual ~RGE_Game_World();
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
    virtual void handle_point_condition(void* entry);
    virtual void handle_condition(void* entry);
    virtual char* condition_description(void* entry);
    virtual void save(int handle);
    void* victory_list;       // +0x04
    long list_num;            // +0x08
    RGE_Player* player;       // +0x0C
    unsigned char victory;    // +0x10
    char gap_11[3];
    void* victory_point_list; // +0x14
    long point_list_num;      // +0x18
    long tot_victory_points;  // +0x1C

    void handle_points_high_attribute_once(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_high_attribute_once(RGE_Victory_Point_Entry* entry) {
    if (entry->state != 0) return;

    int val = (long)this->player->attributes[entry->attribute];
    if (entry->curr_attribute_amount < (float)val) {
        entry->curr_attribute_amount = (float)val;
    }

    int i = 1;
    register RGE_Player** pp = this->player->world->players;
    if (i < this->player->world->player_num) {
        pp++;
        do {
            if (i != this->player->id && (float)entry->amount <= (*pp)->attributes[entry->attribute]) {
                entry->amount = (long)(*pp)->attributes[entry->attribute];
            }
            i++;
            pp++;
        } while (i < this->player->world->player_num);
    }

    int result;
    if (entry->curr_attribute_amount >= (float)entry->amount) {
        result = entry->points;
    } else {
        result = (val == entry->amount) ? entry->curr_points : 0;
    }

    if (result != entry->curr_points) {
        this->tot_victory_points += result - entry->curr_points;
        entry->curr_points = result;
    }
}
