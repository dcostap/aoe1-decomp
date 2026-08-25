// 004E1A00 TribeInformationAIModule::withinXTilesOfAttackOnPlayer
// Source: taiinfmd.cpp lines 6682-6716, size 233 bytes
//
// Attempt log:
// - Initial state: struct missing `type` at +0x04 (minX at +4 instead of +5,
//   stride 0x0C instead of 0x18) and an explicit `if (max <= 0) return 0;`
//   guard before the for loop -> rebuilt 219 bytes, redundant double guard
//   (test edi,edi; jle twice) and wrong field offsets.
// - Probe 1 (baseline): canonical AttackMemory layout from exact donor
//   004E1190 (type at +0x04, minX..targetOwner at +5..+0A, stride 0x18),
//   dropped explicit guard (VC5 for-loop guard covers it), natural dy/dx
//   reassignment checks. Now: rebuilt 211B vs 233B; struct offsets, stride,
//   call set, and 4-check register-reuse pattern (dy1=edi reused by check4)
//   all correct. Remaining drift is register allocation only: original spills
//   the loop counter to the param_1 slot ([esp+18h]) with am=edx (this stays
//   esi), tilesSq=ebp/tx=ebx, push ecx local; rebuilt keeps counter in eax,
//   am=esi (clobbers this), tilesSq=ebx/tx=ebp, no local. Matched sibling
//   004E1AF0 has the identical push-ecx/tilesSq=ebp prologue basin.
//   Next leads (untried): pointer-walk `AttackMemory* am = attackMemories`
//   declared before the loop; one-line `long dy=..., dx=...` declaration
//   (PDB line map attributes both statements to line 6694); indexed
//   `attackMemories[i]` access without the am local; hoisting this-based
//   reloads to keep `this` live in the loop body.
// - Follow-up probes: direct indexed access, split/compound square setup,
//   separate loop-counter/max locals, hoisted pointer declaration, and
//   one-line/long dy/dx declarations all emitted the same 211-byte basin.
//   A scoped pointer walk changed topology and worsened to 204 bytes; restored.
//   Modeling the proven InformationAIModule base changed only register/layout
//   scheduling (71.7% shape), so the narrow field-offset surface is retained.
// - Completed AttackMemory ownership/layout from ground truth: unsigned byte
//   fields, +0x0B padding, timestamp at +0x10, play at +0x14, total 0x18.
//   Final validated clean source remains natural indexed scan with shared
//   continue/increment path. Calls and touched offsets are correct; remaining
//   drift is the VC5 allocator basin (counter home, am/this coloring, and
//   tilesSq/tx register swap), not a known behavior or layout mismatch.
// - Main-agent normalization retained the proven InformationAIModule base and
//   canonical inheritance boundary; emitted code is unchanged.
// - Session probe: natural positive-count if/do-while around the indexed scan
//   worsened to 204 bytes with an extra CFG return; restored the clean for-loop.
// - Session probes: a natural positive-count do/while with a carried
//   AttackMemory pointer worsened to 204 bytes; an indexed nested positive gate
//   with a short-circuit four-corner expression reached 206 bytes but lost the
//   original CFG island; both were restored. Grouped coordinate declarations,
//   a dead target-parameter zero assignment, and an early loop-counter
//   declaration all emitted the same 211-byte basin. No source/layout/call
//   lead displaced the canonical indexed scan; remaining drift is the known
//   VC5 allocator/stack-home basin.
// - Fresh bounded pass: split eligibility guards, signed-char AttackMemory
//   declarations, a positive combined guard, a reference record alias, and a
//   Win32-long loop index all emitted the same 211-byte basin; restored.
// - Canonical full TribeInformation surface (+F0 ManagedArray/md), reversed
//   first sum terms, and coordinate declaration experiments were nonexact;
//   swapping y/x improved edit resync only (142 vs 187) while losing an exact
//   block, so the original x-then-y source was restored.
// - Variant lab (36 natural declaration/loop/access/sum combinations): no
//   exact or size/frame/call-set eligible result; emitted groups were 211 or
//   197 bytes. Clean source remains the typed indexed scan; unresolved drift
//   is allocator/stack-home coloring (counter, pointer/this, square/x).
// - Fresh lease baseline confirmed the clean 211-byte basin. A max local with
//   a positive cursor guard reached 219 bytes but added a CFG edge; a max plus
//   cursor for-loop stayed 211 bytes. Both were restored.
// - Named module owner/max/memory locals reached 214 bytes and lost exact
//   blocks. A donor-supported <stdlib.h> include, flat class layout, and an
//   address-taken index were unchanged or worse; the last was optimized away.
//   Separate max/base locals reached 214 bytes and were restored.
// - Refreshed assembly-donor search found the exact taiinfmd.cpp sibling
//   004E1AF0 prologue and confirmed the remaining gap is the target's distinct
//   allocator/stack-home basin, not a missing call or known layout fact.
// - Reassessment probes: a positive do/while with a carried cursor worsened
//   to 204 bytes and changed the CFG; top-level counter initialization inside
//   the positive guard added a duplicate bound test (219 bytes).  Restored.
// - Reassessment probes: moving the squared-range declaration after the
//   coordinate conversions reached 211 bytes with diff 218 but did not improve
//   structure; direct repeated member indexing, explicit this-based pointer
//   arithmetic, and top-level declaration reordering were codegen duplicates.
//   A for update ordered cursor before counter kept 211 bytes but lost an exact
//   block.  Restored the clean indexed scan.
// - Current lease baseline confirmed the clean 211-byte basin.  A natural
//   long loop copy inside the positive-count guard worsened to 204 bytes and
//   changed the loop CFG; it was restored.  No new lead remains within this
//   bounded pass.
// - Fresh bounded probes tested register-qualified tiles, a cached max local,
//   function-scoped dy/dx and AttackMemory declarations, explicit this-qualified
//   indexing, a flat class surface, a top-tested carried-pointer while loop,
//   const/long coordinate locals, and a hoisted pointer assignment. All natural
//   forms duplicated the 211-byte basin except the while form, which worsened
//   structural alignment. The clean indexed scan remains authoritative.
// - Revisit probes: a positive-count indexed do/while reached 204 bytes and
//   changed the loop CFG; an AttackMemory reference, named max copy, and y-before-x
//   declaration were duplicate 211-byte codegen. A function-scope memory alias
//   reached 214 bytes and hoisted the base load before the count guard.
// - Revisit probe: a carried-pointer positive do/while reached 204 bytes and
//   changed the record-gate CFG. Original PDB symbols show i/objY home aliases,
//   while the Ghidra lead uses a pointer walk and parameter-home counter. Those
//   forms are not retained because policy forbids raw cursor and home reuse.
// - Fresh revisit: an early initialized i local reached 221 bytes and 85.1%
//   shape with a local counter, but it did not recover the original parameter
//   home or EDX cursor; declaration-order variants and split guards duplicated
//   or worsened the clean 211-byte basin. Pointer-for and positive-gate forms
//   also changed CFG or size. Restored the natural indexed scan.
// - Revisit audit (current clean baseline, 220 strict bytes in 10 spans):
//   +00..+27 crosses the prologue and first max load; the missing push-ecx
//   local, parameter-home shift, and tiles/target register colors cause it.
//   +29..+3E crosses max-load tail, coordinate-home stores, the zero counter,
//   local max, and the initial JLE; the baseline has no pushed max local and
//   uses different homes. +41..+4A is the memory-base load and owner test;
//   the baseline reuses ESI for the cursor instead of retaining this in ESI
//   with the cursor in EDX. +4C..+9F is the player test and four corner
//   calculations; the source behavior and call set match, but the threshold,
//   x/y homes, byte-load registers, and square accumulators use another
//   allocator basin. +A2, +A4, +A6, and +A8 are isolated bytes inside the
//   max-X accumulator and branch encodings; they are not independent source
//   statements. +AA..+E8 covers the final corner, max reload, loop update,
//   three epilogues, and the rebuilt short tail; the baseline lacks the
//   original counter/max home pair and the push-ecx/pop-ecx epilogue shape.
//   Calls, direct targets, field offsets, stride, and return CFG behavior
//   remain aligned. No probe found a supported source lead for the allocator
//   basin. All 20 fresh probes were restored to this clean source.
// - Revisit pass: 20 new evidence-led probes tested source context, real
//   headers, object and base surfaces, counter lifetime, geometry declaration
//   order, and named square lifetimes. Most forms duplicated the 211-byte
//   basin. The best valid source names `dySquared` and `dxSquared` and carries
//   those values across the four corner checks. It emits 233 bytes, matches the
//   original boundary, and restores the push-ecx local plus five exact blocks.
// - BINARY NOTE: The improved source matches the original bytes through +2C.
//   The remaining first mismatch swaps the `ty` and `i` parameter-home stores
//   at +2D and +33. The original reloads `ty` before each needed subtraction.
//   The improved source keeps `ty` in EAX and avoids those reloads. This is a
//   register and home-allocation difference, not a proven behavior difference.
// - Revisit result: 233-byte rebuild, 144 strict-byte difference, 16 spans,
//   200 equal bytes, two ordered __ftol calls, and three returns. The semantic
//   square-local source is pinned as the clean reconstruction. No raw cursor,
//   home alias, volatility, helper, wrapper, or compiler steering is retained.
// - Object audit: FPO confirms one real local word, four saved registers, no
//   SEH, and the expected parameters. PDB confirms AttackMemory and coordinate
//   layouts, plus compiler home reuse for objY and i. No inline or ABI defect
//   explains the remaining allocation at that checkpoint. A later reduced
//   direct-square form produced a useful allocation improvement below.
// - Fresh allocation pass: twenty natural object/layout/lifetime/control-flow
//   probes tested the remaining home and register basin. Object field spelling,
//   full object surface, char field widths, const forms, pointer spelling, and
//   guard polarity were unchanged or worse. Direct typed square expressions
//   were the only useful lead: they restore the original ty/i parameter homes,
//   retain the 233-byte boundary, and reduce strict drift from 144 to 128 bytes.
//   The reduced source has 79.79% exact-block coverage and the same two calls.
//   Remaining drift is square arithmetic lowering and branch displacement.
// Accepted-drift review: both versions convert target x and y in the same
// order. Each record reads minY, minX, maxY, and maxX in the same order. The
// rebuild reads the private ty home earlier and keeps the first minY square for
// the fourth corner. The executable keeps the difference and squares it there.
// All integer results, overflow truncation, predicates, two calls, and returns
// match. The shorter arithmetic basin only moves later branch displacements.
// - Exact-finish context audit: restored the full period RGE_Static_Object,
//   RGE_Master_Static_Object, AIModule, and InformationAIModule surfaces from
//   exact same-TU donors. The target remains a 229-byte mismatch with 128
//   differing bytes, but keeps the original boundary, owner, calls, and stack
//   home behavior. Natural delta and declaration-order variants were restored.
// - Fresh exact-codegen probe: retaining the first minY delta as a natural
//   `dy` local after the first corner predicate reproduces the original 233-byte
//   boundary, 94-instruction CFG, both __ftol calls, all block boundaries, and
//   all returns. The only remaining mismatch is a consistent ECX/EDX recolor:
//   the rebuilt cursor uses ECX where the executable uses EDX, and the rebuilt
//   player-id/coordinate accumulator uses EDX where the executable uses ECX.
//   The source is retained because this local preserves the original raw-delta
//   reuse and the compiler emits the observed minY load before the first test.
//   Natural explicit-this, const, reference, indexed, declaration-order,
//   register-qualified, and parameter-alias variants did not change that
//   recolor. No policy-valid exact source was found.
// - Exact finish: a staged first minX difference selects the original colors.
//   `dxSquared = minX - tx; dxSquared *= dxSquared;` emits exact bytes.
//   It keeps the record cursor in EDX and the squared x value in ECX.
//   The direct repeated minX form restores the 22-byte ECX/EDX swap.
// - Reduction removed the separate `dx` alias without changing emitted code.
//   Compound and expanded maxY and maxX square updates are also exact.
//   The compound form matches PDB line splits 6699/6700 and 6704/6705.
// - The first minY square stays direct before the late `dy` declaration.
//   Conventional raw-dy reductions emit 230 bytes and change block layout.
// - Context and traversal audits found no other required change. Supported
//   headers, full class layout, split and positive guards, and register hints
//   keep the same basin. Pointer walks load the array before the count guard.
// - Final exact result: 233 bytes, 94 instructions, two ordered __ftol calls,
//   three returns, the original owner, and 0.0000% positional difference.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Action_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Tile;
class RGE_Color_Table;
class TDrawArea;
class RGE_Armor_Weapon_Info;
class LOSTBL;

#endif
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player*, float, float, int*,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char,
                                          unsigned char, unsigned char);
    virtual unsigned char alignment(float*, float*, void*, unsigned char);
    virtual long calc_base_damage_ability(void*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, unsigned char);
    char gap_04[0x24];
    float los;                           // +0x2C
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                         float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);

    long id;                             // +0x04
    char gap_08[0x38 - 0x08];
    float world_x;                       // +0x38
    float world_y;                       // +0x3C
};

struct AttackMemory {
    int id;                 // +0x00
    unsigned char type;              // +0x04
    unsigned char minX;              // +0x05
    unsigned char minY;              // +0x06
    unsigned char maxX;              // +0x07
    unsigned char maxY;              // +0x08
    unsigned char attackingOwner;    // +0x09
    unsigned char targetOwner;       // +0x0A
    unsigned char gap_0B;            // +0x0B
    short kills;            // +0x0C
    unsigned char success;  // +0x0E
    unsigned char gap_0F;   // +0x0F
    unsigned long timeStamp; // +0x10
    int play;               // +0x14
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(void*);
    virtual int update(int);
    virtual void setCallbackMessage(void*);
    virtual int filterOutMessage(void*);
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[0x40];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[0x40];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

// Main-agent audit confirmed canonical typed attack-memory ownership and kept
// the ordinary indexed proximity scan.
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public InformationAIModule {
public:
    char gap_F0[0x1FC - 0xF0];
    int maxAttackMemories;               // +0x1FC
    AttackMemory* attackMemories;        // +0x200

    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* target, int tiles, int playerId);
};
#endif

#endif
int TribeInformationAIModule::withinXTilesOfAttackOnPlayer(
    RGE_Static_Object* target, int tiles, int playerId)
{
    int tilesSq = tiles * tiles;
    int tx = (int)target->world_x;
    int ty = (int)target->world_y;

    for (int i = 0; i < this->maxAttackMemories; i++) {
        AttackMemory* am = &attackMemories[i];
        if (am->id == -1 || !am->attackingOwner || (unsigned char)am->targetOwner != playerId)
            continue;

        int dxSquared = (unsigned char)am->minX - tx;
        dxSquared *= dxSquared;
        int dySquared = ((unsigned char)am->minY - ty) *
                        ((unsigned char)am->minY - ty);
        if (dySquared + dxSquared <= tilesSq) return 1;
        int dy = (unsigned char)am->minY - ty;

        dySquared = (unsigned char)am->maxY - ty;
        dySquared *= dySquared;
        if (dySquared + dxSquared <= tilesSq) return 1;

        dxSquared = (unsigned char)am->maxX - tx;
        dxSquared *= dxSquared;
        if (dySquared + dxSquared <= tilesSq) return 1;

        if (dy * dy + dxSquared <= tilesSq) return 1;
    }

    return 0;
}
