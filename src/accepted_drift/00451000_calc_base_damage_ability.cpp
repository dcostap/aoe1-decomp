// RGE_Master_Combat_Object::calc_base_damage_ability
// VA: 00451000
// m_co_obj.cpp
// Matching attempt log:
// - Hoisted armor_num/base_armor outside the weapon loop; this recovered 188-byte size and the original nested-loop topology.
// - Separate `(float)attack - (float)value` operands recovered the original two-fild/fxch/fsubp x87 sequence.
// - Leaving the inner counter uninitialized until after the armor pointer load recovered the exact +0039..+00BC block island.
// - DAT_00570504/08/10/18 are the proven global surfaces; the full inherited polymorphic class surface and register-qualified target were neutral.
// - Best: 42 strict differing bytes, 95.08% instruction-shape similarity, 188/188 bytes, exact call set; remaining drift is the entry prologue/register basin and value reload (`edx` vs original `eax`) at +0039.
// - Paused after 10 meaningful probes; no accepted_drift proposed.
// - Main-agent ABI audit restored the binary-backed inherited virtual surface through slot +0x28;
//   emitted code and the remaining prologue/register mismatch were unchanged.
// - Sequential pass: direct target-count guards, target aliasing, register-qualified count,
//   declaration order, branch-local lifetimes, full derived layout/vtable surface, and a short
//   counter were either worse or codegen-neutral; the 8-variant prologue lab collapsed to one
//   188-byte group. The binary-backed RGE_Armor_Weapon_Info surface is retained.
// - Final best remains 42 strict bytes: exact +0039..+00BC island, 188-byte size/frame/call set;
//   unresolved entry target/count register basin only. No accepted_drift proposed.
// - orch-w13 claim: loop-form axis fully explored. Init-order permutations
//   (count/weapon/total, count/total/weapon) are codegen duplicates; hoisting
//   armor_count/base_armor before the guard is worse (57B).
// - KEY NEGATIVE: every top-condition loop (while(count!=0), for(int i=count;i>0;i--),
//   for(;count>0;count--), for(int i=0;i<count;i++)) reproduces the ORIGINAL's exact
//   prologue (mov edx,[esp+4] pre-frame; movsx eax,[edx+108h]; pushes after movsx;
//   mov edi,[edx+10Ch]), the in-guard count spill, single guard, and the correct homes
//   (count -8, base_armor -4, value +8) -- but ALWAYS inserts `mov ebp,ecx` (this->EBP)
//   at +001E, cascading base_armor->ECX/armor->value->ECX/value->EDX and producing
//   153B diff in the real function (prologue exact, body register-cascade).
// - The do-while keeps this->ECX and the body registers right (armor->value->EBP) but
//   sits in the target->EAX/count->EDX prologue basin (42B). The ORIGINAL's allocation
//   (target->EDX, count->EAX, this->ECX, base_armor->EDX, value->EAX, attack->EDX,
//   armor->value->EBP) is NOT producible by any single natural loop form: top-condition
//   loops give count->EAX but force this->EBP; the do-while keeps this->ECX but colors
//   count->EDX. The only form with this->ECX + count->EAX + base_armor->EDX was the
//   for-index-noif variant WITH an integer-sub body (`(float)((int)weapon->value - v)`
//   carried in EBX) -- but that changes the binary's two-fild/fxch/fsubp float-sub body
//   and the home mapping, so it is not the original source.
// - 18-variant lab (6 loop forms x 3 tails, 20260807_180331) confirms do-while is the
//   best emitted-code basin (pos 39/focus 35); every other family is worse. Flags
//   (/O1, /O2 alone, /Og /Oy, /GB) do not leave the do-while basin.
// - Conclusion: 42B stays the frontier. The remaining drift is the systematic EAX/EDX
//   swap of {target,count-init,base_armor,value,attack} (loop-data chain EAX vs
//   address/base chain EDX), steered by the loop-form-dependent allocator order.
//   Next lead: a TU/header-context difference (the original m_co_obj.cpp include set)
//   or a genuinely different control structure not yet found; a fresh worker should
//   audit the real class hierarchy (RGE_Master_Static_Object base chain) before more
//   codegen probes.
// - orch-luna fresh pass: rebuilt the exact Static->Animated->Moving->Action data
//   hierarchy (both full-vslot and destructor-only local surfaces); both were codegen
//   neutral at 42B. Top-level declaration/assignment splitting was also neutral.
// - Fresh initializer/liveness negatives: weapon-first and total/weapon/count orders
//   were 47B; a self alias paired with the top-count loop reproduced the known 153B
//   this->EBP cascade; short armor_count was 162B; register weapon was neutral.
// - Fresh control-flow negatives: assigning count in the signed guard was 47B, and
//   moving --count into the do-while condition was 129B. Restored clean do-while.
// - Fresh worker checks: target alias, count-first initialization, neighboring
//   stdlib context, and a register-qualified target parameter were codegen
//   duplicates at 42B; the clean natural do-while remains authoritative.
// - orch-mcoobj-01 fresh bounded pass (10 meaningful probes): TU-wide /GX,
//   unqualified member lookup, an inner top-tested for scan, a separate
//   weapon-start alias, per-iteration base_armor reload, register-qualified
//   count, remaining initial declaration orders, and combined declarations
//   were all neutral or worse. The six-way initial-order lab formed only the
//   existing 42B group and a worse 47B group.
// - Final clean source restored and validated; remaining evidence is still
//   the systematic entry target/count EAX/EDX basin (42 strict bytes), with
//   exact size/frame/call set and exact +0039..+00BC body island.
// - orch-mcoobj-fresh-04 adopted the stabilized Static->Animated->Moving->Action->Combat
//   hierarchy and the exact modify donor's Combat override declaration; both remain
//   codegen-neutral at 42 bytes.
// - Fresh bounded probes: outer-scope value lifetime, split attack/diff declarations,
//   a reference target alias, long count, PDB-supported one-line prologue declarations,
//   register hints on armor locals, and an explicit signed-short count promotion were
//   all neutral. The clean natural do-while was restored after each diagnostic form.
// - Session conclusion: 10/10 meaningful probes exhausted; no exact or accepted_drift
//   candidate. Retain the canonical natural source; unresolved bytes are the known
//   entry target/count EAX/EDX allocation basin and the dependent reload coloring.
// - wave20-mcoobj-01 baseline: revalidated the stabilized master-object hierarchy and
//   exact +0039..+00BC body island before a focused entry-allocation pass.
// - Combined register hints and target/count field references were codegen-neutral;
//   scoping weapon inside the positive count arm was worse (51B).
// - A natural branch-local `remaining = count` copy is a distinct, materially closer
//   basin: it recovers the original target load/count allocation and exact +0000..+0022
//   prologue, leaving 12 strict bytes. Declaration/assignment order around
//   armor_count/base_armor was duplicate; a for-header or function-scope remaining
//   counter caused the known 153B/190B structural basin.
// - Final bounded pass: retain the readable branch-local remaining-counter source as
//   the best reconstruction. Remaining drift is the EAX/EDX base-armor/value coloring
//   at +0029..+0039 and dependent attack reload; no accepted_drift proposed.

// ACCEPTED_DRIFT REVIEW (main-drift-00451000): Direct comparison with the
// original confirms identical size/frame, saved registers, one __ftol call,
// seven conditional branches plus the same jump, all stack homes, nested loop
// bounds, x87 arithmetic/rounding sequence, global thresholds, and return.
// The remaining 12 strict bytes are only the zero-extension/register choice
// for base_armor and the dependent reload (`EDX` versus `EAX`) at +0x29..+0x39;
// both versions store and consume the same values before the exact body island.
// There is no changed predicate, call, stack cleanup, memory target, copy size,
// or FPU event. The readable natural do-while source is the promoted candidate;
// register hints and allocator scaffolding were not retained.

#ifndef RGE_MCO_OBJ_SHARED_CONTEXT
#include "..\..\include\game_globals.h"

class RGE_Armor_Weapon_Info {
public:
    short type;
    short value;
};

class RGE_Sprite;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Task_List;
class TDrawArea;
class RGE_Color_Table;
class RGE_Master_Combat_Object;

class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x,
                                          float y, int* value,
                                          unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d,
                                          unsigned char e, unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    unsigned char master_type;
    char gap_005[0xB3];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
    virtual void modify(float value, unsigned char attribute);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite; // +0xFC
    unsigned char base_armor; // +0x100
    char gap_101;
    short armor_num;          // +0x102
    RGE_Armor_Weapon_Info* armor; // +0x104
    short weapon_num;         // +0x108
    RGE_Armor_Weapon_Info* weapon; // +0x10C

    virtual void modify(float value, unsigned char attribute);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* target);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int,
        unsigned char);
    virtual RGE_Task_List* create_task_list();
    short defense_terrain_bonus; // +0x110
    char gap_112[2];
    float weapon_range; // +0x114
    float area_effect_range; // +0x118
    unsigned char area_effect_level; // +0x11C
    char gap_11D[3];
    float speed_of_attack; // +0x120
    short missile_id; // +0x124
    short base_hit_chance; // +0x126
    unsigned char break_off_combat; // +0x128
    char gap_129;
    short fire_missile_at_frame; // +0x12A
    float weapon_offset_x; // +0x12C
    float weapon_offset_y; // +0x130
    float weapon_offset_z; // +0x134
    float minimum_weapon_range; // +0x138
    short orig_armor; // +0x13C
    short orig_weapon; // +0x13E
    float orig_weapon_range; // +0x140
    float orig_speed_of_attack; // +0x144
};
#endif

long RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object* target)
{
    float total = DAT_00570504;
    int count = target->weapon_num;
    RGE_Armor_Weapon_Info* weapon = target->weapon;

    if (count > 0) {
        int remaining = count;
        int armor_count = this->armor_num;
        int base_armor = this->base_armor;
        do {
            int n;
            int value = base_armor;
            if (armor_count > 0) {
                short weapon_type = weapon->type;
                RGE_Armor_Weapon_Info* armor = this->armor;
                n = armor_count;
                do {
                    if (armor->type == weapon_type) {
                        value = armor->value;
                    }
                    ++armor;
                    --n;
                } while (n != 0);
            }

            int attack = weapon->value;
            float diff = (float)attack - (float)value;
            if ((double)diff > DAT_00570508) {
                total += diff;
            }
            ++weapon;
            --remaining;
        } while (remaining != 0);
    }

    if ((double)total < DAT_00570510) {
        total = DAT_00570518;
    }
    return (long)total;
}
