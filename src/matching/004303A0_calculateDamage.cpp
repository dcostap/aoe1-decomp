// 004303A0 RGE_Combat_Object::calculateDamage
// Source: com_obj.cpp lines 433-466, size 213 bytes
//
// Attempt log:
// Prior worker: raw-offset variants reached a 7-byte edit diff but loaded the
// armor table into EBX before saving EBP; nine probes did not change that basin.
// 1 baseline: raw-offset source, 214-byte rebuild; armor pointer in EBX.
// 2 typed layout: named master/tile/player/world/table fields improved the
// diff by 15 bytes but kept the same prologue basin.
// 3 typed armor records: corrected the scan stride to sizeof(RGE_Armor_Weapon_Info)
// and recovered the exact inner-loop shape; codegen remained 214 bytes.
// 4 full same-TU virtual surface: duplicate codegen.
// 5 split terrain/world/table locals: duplicate codegen.
// 6 swapped armor/count declarations: duplicate codegen.
// 7 register-qualified armor pointer: duplicate codegen.
// 8/9 scoped armor pointer: worsened to a 203-byte diff and was rolled back.
// 10 inherited static-object field surface: duplicate of the best typed basin.
//
// Fresh exact pass (orch-luna-4303a0-w3): same-TU donors 00430320/004304B0/
// 00430510 and ABI evidence confirmed the virtual five-argument float signature,
// 4-byte armor records, signed short defense bonus, signed short armor count,
// and int promoted arithmetic. A widened terrain-class temporary was codegen
// neutral. Widening the defense bonus to int removed one byte but changed the
// proven short-load/test and was rolled back. A diagnostic top-level
// `int weaponIndex = weaponKind` reached 38 strict differing bytes (213 bytes,
// 71.62% exact-block coverage) but retained an extra promoted index and did not
// recover the original terrain schedule; declaration reordering and register
// hints were codegen duplicates. The diagnostic form was rolled back.
// Final natural reconstruction remains 169 strict differing bytes (214 emitted
// bytes vs 213), with exact calls/CFG and the localized armor-pointer register
// basin unresolved; no source-only register steering retained.
// Best reconstruction: canonical master armor fields at +100/+102/+104/+110,
// tile terrain bitfield at +1C/+5, owner world at +0C/+3C, and world terrain
// rows at +54, expressed with named types and ordinary loops. Remaining drift
// is compiler register scheduling: original saves EBP then loads armor into it,
// while VC5 loads armor into EBX before the EBP save; downstream terrain-index
// registers follow that choice. Left in scratch after the bounded session.
// Fresh worker: declaration-after-terrain reached a 76-byte diff by delaying
// armor loads to loop entry; direct member armor scan worsened to 210 bytes and
// was rolled back. The clean typed candidate remains authoritative.
// Main-agent audit restored canonical polymorphic master/world/player/static
// ownership while retaining the natural armor and terrain-table loops.
// Fresh worker: queried same-TU donors, ABI, and binary globals; replaced the
// FLOAT_*/DOUBLE_* placeholders with DAT_0056f49c/DAT_0056f4a8/DAT_0056f4a0.
// This is source-canonical but emitted-code neutral in the isolated TU.
// Paused: cumulative evidence still isolates the unresolved EBP-versus-EBX
// armor-pointer allocator basin; no register hint, volatility, or padding kept.
// Fresh bounded pass (orch-comobj-01, 10 hypotheses): short and unsigned-short
// attack widths regressed or changed the counter basin; direct terrain-chain,
// const-rdata, function-scope attack, living-global-include, proven master-base
// hierarchy, inline tile-index, and register-affinity probes were codegen
// duplicates or ABI regressions. Restored the pinned natural typed source.
// Final fresh evidence: clean source remains 214 emitted bytes vs 213 original,
// 169 strict differing bytes (79.0%), 94.59% shape, exact CFG/call-count; the
// historical diagnostic best is 38 bytes but is not source-canonical. Remaining
// lead is the unresolved VC5 EBP-versus-EBX armor-pointer allocator basin.
// Bounded follow-up: full Static->Animated->Moving->Action->Combat size gaps,
// baseline armor-pointer register hint, and function-scope terrain-table
// declaration were all codegen duplicates (169 bytes, 214 emitted bytes).
// Keeping armor count hoisted while introducing the armor pointer at the inner
// scan site changed the basin to 203 bytes and made obj persistent in EBX;
// hoisted armor pointer with inner-site count was 184 bytes/215 bytes. Both
// natural-source variants were rolled back. Clean typed source restored.
// Follow-up worker (follow-4303A0-r1): PDB parameter names and inline FPU
// expression spelling were codegen duplicates. Delaying armor pointer/count
// declarations until after the terrain lookup reached the known 76-byte
// diagnostic basin, but contradicted the line-441 declaration band and moved
// armor loads away from the original prologue. Restored the canonical source.
// Remaining evidence-backed gap is the VC5 EBP-versus-EBX armor pointer
// allocator choice; no natural arithmetic or liveness lead remains.
// Fresh PDB DIA evidence names the parameters weapon_num (int), damage
// (RGE_Armor_Weapon_Info*), attack_modifier (float), attacking_player, and
// attackingObject; tot_armor is the only emitted local and is an int at a
// reused parameter home. Function-scope tot_armor, declaration-order, direct
// parameter-mutation, direct-master, terrain-expression, and const-record
// variants were tested; only direct parameter mutation changed codegen and it
// lost aligned blocks despite exact size. Variant labs otherwise collapsed to
// the existing 214-byte basin. Clean typed source remains authoritative.
// Follow-up context probe: merged the declaration order and shared type surface
// from exact donors 00430320, 004304B0, and 00430510. The emitted code was an
// exact duplicate of the clean source; the EBP-versus-EBX armor-pointer basin
// did not move. Restored the clean typed source.
// Exact pass: the positive-count block declares the weapon pointer, then the
// base-armor local, then the counter. This source order makes VC5 emit the
// original base-armor load, counter home, EBP armor pointer, and 213-byte body.
// Current bounded pass: baseline validation, ABI/dossier review, and a narrow
// prologue donor search confirm the natural typed source and the same allocator
// basin. No new source-backed lead remains; preserve this clean reconstruction.

extern float DAT_0056f49c;
extern float DAT_0056f4a8;
extern double DAT_0056f4a0;

#include "../com_obj_phase2_context.h"

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                         float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    RGE_Master_Combat_Object* obj = this->master_obj;
    float mult = DAT_0056f49c;
    short weaponKind = obj->defense_terrain_bonus;
    RGE_Armor_Weapon_Info* armorTbl = obj->armor;
    int nArmor = obj->armor_num;

    if (weaponKind >= 0 && this->tile != 0) {
        unsigned char cls = this->tile->terrain_type;
        RGE_Game_World* wld = this->owner->world;
        float** tbl = wld->terrains;
        mult = tbl[weaponKind][cls];
    }

    float total = DAT_0056f4a8;

    if (param_1 > 0) {
        RGE_Armor_Weapon_Info* weapon = param_2;
        int tot_armor = obj->base_armor;
        int cnt = param_1;

        do {
            int attack = tot_armor;

            if (nArmor > 0) {
                RGE_Armor_Weapon_Info* srch = armorTbl;
                int n = nArmor;
                do {
                    if (srch->type == weapon->type) {
                        attack = srch->value;
                    }
                    ++srch;
                    n--;
                } while (n != 0);
            }

            float d = (float)weapon->value - (float)attack;
            float dmg = d * mult * param_3;

            if (dmg > DAT_0056f4a0) {
                total += dmg;
            }

            weapon++;
            cnt--;
        } while (cnt != 0);
    }

    return total;
}
