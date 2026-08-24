// ACCEPTED_DRIFT 2026-08-07 (orchestrator-reviewed): approved localized
// behavior-equivalent FPU-instruction encoding drift. Original emits
// `fld [esp+0Ch]; mov [esp+0Ch],eax; fmul st1; fidiv [esp+0Ch]` (amount loaded
// into ST0, divisor homed to the freed amount-parameter slot); rebuilt emits
// `mov [esp+4],eax; fld st0; fmul [esp+0Ch]; fidiv [esp+4]` (maxf dup + memory
// amount; divisor homed to the push-ecx slot). Both compute amount*maxf/heal_rate
// with identical x87 values and end with the same division result at [esp+0Ch]
// before the fadd; calls 3/3, CFG, size, frame, and returns exact. No dereference
// can fault in this hunk, so no fault-context divergence arises. Same residual
// family as accepted sibling 004C86C0 (fld st0; fmul [amount]; mov [amount],rate
// unreachable). 9 strict differing bytes in 3 spans, first mismatch +0x47.
//
// 004CC4C0 TRIBE_Combat_Object::heal
// t_c_obj.cpp lines 1637-1657, 173 bytes
// Retry 2026-05-21 Boss pass: replaced stub with natural member source and tried
// max/denominator locals as int/long, direct denominator expression, separate
// heal_amount local, split *= and /=, operand order swaps, cast/no-cast denominator,
// and both `max < amount+hp` and `amount+hp > max` comparison spellings. Best kept
// is exact-size but mismatching: first 56 bytes match through type dispatch/base-heal
// fallback, then FPU codegen diverges because VC5 emits an fild/fxch family instead
// of original fild max; fld param; store denom; fmul st1; fidiv stack-slot sequence.
// Not accepted_drift-worthy: remaining drift is broad FPU scheduling/stack topology.
// Retry 2026-05-24 Boss pass: 16 probes. Revalidated baseline: exact-size 173B, first 56 bytes match, then FPU scheduling diverges.
// Tried max_hp_f local, split *= then /=, float denominator, short source locals, direct denominator expression, product temp,
// reversed max/amount+hp compare, cost denominator local, fail-first pay_obj_cost branch, and flags /Op /Ob0 /Og /Ot /G5 /GB /O1.
// All sane source variants stayed in the same exact-size FPU basin (57.8035% positional / 36.4162% edit, first mismatch +56); /Op and branch/compare inversions worsened, /O1 too small.
// GIVEUP: no accepted_drift proposal because remaining mismatch is broad x87 stack/local-slot scheduling through heal clamp and payment argument setup.
// Retry 2026-05-26 Boss pass: 16 probes. Revalidated baseline (57.8035% positional / 36.4162% edit, first mismatch +56). Tried maxf local,
// maxf-left compare, double casts, volatile param reread, split product, max*amount operand order, parameter-slot/union denominator mutation,
// denominator locals, inverted/empty clamp branches, hp local, clamp-as-subtract, and flags /Op /Ob0 /G5. Best retained below is maxf local:
// 52.6012% positional / 31.7919% edit, first mismatch +72. It fixes the initial max fild/load order but VC5 still loads hp too early and
// the remaining x87 clamp/payment stack scheduling differs broadly. GIVEUP: no accepted_drift because drift spans x87 stack topology and call setup.
// Retry 2026-08-02 Luna-4CC4C0 pass: claimed target and ran dossier/donor/ABI evidence.
// Baseline rebuilt 177B, 103 positional diff bytes (58.1921%), exact calls/CFG and
// first mismatch +0x48. Ten meaningful hypotheses covered direct max casts, maxf
// product order/types, a post-product hp local, matched base context, volatile amount,
// declaration placement, flattened data surface, and reversed clamp comparison.
// The post-product hp and reversed-comparison variants worsened size/CFG; the other
// variants collapsed to the same 177B FPU basin. Restored the best natural maxf source.
// GIVEUP: exact match remains blocked by broad x87 scheduling/stack topology from
// +0x48 through clamp/payment setup; calls, cleanup, and return structure are aligned.
// Retry 2026-08-02 Luna4CC4C0 continuation: baseline after dossier/donor/ABI review
// remains 177B, 103 positional diff bytes, exact 3-call set/CFG, first mismatch +0x48.
// Tested deferred maxf (189B), volatile hp rereads (same size but worse CFG), typed
// TRIBE master fields, declaration/init order, virtual base surface, amount-home alias,
// and direct rate conversion; typed/declaration/virtual/direct-rate forms collapsed
// to the same baseline basin. A five-case focused FPU variant lab found no exact case:
// three 177B forms shared the baseline group, max-left was 189B, direct max cast 185B.
// Restored the pinned clean natural source; remaining gap is broad x87 scheduling and
// stack-slot placement, not calls or control flow. GIVEUP after 10 meaningful probes.
// Main-agent source audit retained the codegen-neutral typed master/player field
// surface from that pass instead of the older raw offset accesses; validation stayed
// in the same 177-byte FPU basin.
// Retry 2026-08-02 Luna4CC4C0b continuation: dossier/donor/ABI evidence confirmed
// exact 3-call ordering, 3-return CFG, and the proven +0x10/+0x14/+0x26/+0x15A
// master fields. Probe 031's data-only base view and probe 033's full typed master
// hierarchy were codegen duplicates; probe 035 mirrored the matched sibling's
// derived-data/base surface and was also unchanged. A pointer-local hit-points
// liveness probe (037) worsened to 181B, so it was rolled back. Combining the
// sibling surface with max-left product (039) and modeling the actual
// RGE_Static->RGE_Combat hierarchy plus virtual heal (041/045) likewise produced
// the same 177B basin. A 12-case focused surface/product/clamp variant lab (043)
// found only the existing 177B/189B groups, with no size-eligible or exact case.
// Restored the clean natural source. Final blocker remains the broad x87 stack
// topology and parameter-home choice from +0x48 through clamp/payment setup;
// calls, cleanup, and return structure remain aligned. GIVEUP for this pass.
// Retry 2026-08-07 orch-w6 pass (10+ probes): BREAKTHROUGH — the assignment-in-condition
// form drops the diff from 103 to 9 bytes (5.2023%), exact 173B size, first mismatch
// +0x47, 93.55% shape, 3/3 calls aligned, CFG/cleanup/returns exact:
//     if ((amount = amount * maxf / heal_rate) + this->hit_points > maxf) {
//         amount = maxf - this->hit_points;
//     }
// The division result is then kept in ST0 (fst; fadd [esi+30h]) exactly like the
// original. Only the product/divisor hunk remains: original emits
// fld [esp+0Ch]; mov [esp+0Ch],eax; fmul st1; fidiv [esp+0Ch] (amount loaded into
// ST0, divisor homed to the freed parameter slot) while rebuilt emits
// mov [esp+4],eax; fld st0; fmul dword [esp+0Ch]; fidiv dword [esp+4] (maxf dup +
// memory amount; divisor homed to the push-ecx slot). The 9-byte residual is robust
// to: product operand order, int/long locals, declaration order, explicit (float)
// casts, float amt local, volatile amount reads, statement splits (product/division
// split regresses to fild+fdivp family or store/reload), commuted division
// (amount / heal_rate * maxf), parenthesized (amount * maxf) / heal_rate (100B), no
// named maxf (115B), virtual/inheritance surface (139B), and flat raw-cast surface
// (duplicate). Matched sibling 004C86C0 (accepted_drift) has the identical residual
// family (`fld amount; mov [amount],rate; fmul st1` unreachable; its drift is
// `fld st0; fmul [amount]; mov [amount],rate`). Both originals want the amount-load
// product; neither VC5 rebuild can emit it. Left as validated scratch: 9-byte
// localized behavior-equivalent FPU-instruction drift; promotion to accepted_drift
// or further flag/context work is the orchestrator's call.

#ifndef T_C_OBJ_CONTEXT_H
struct TRIBE_Player;

struct TRIBE_Master_Combat_Object {
    char gap_00[0x10];
    short cost_type;          // +0x10
    char gap_12[2];
    short object_type;        // +0x14
    char gap_16[0x10];
    short max_hit_points;     // +0x26
    char gap_28[0x132];
    short heal_rate;          // +0x15A
};

struct RGE_Static_Object {
    char gap_00[8];
    TRIBE_Master_Combat_Object* master_obj; // +0x08
    TRIBE_Player* player;                    // +0x0C
    char gap_10[0x20];
    float hit_points;       // +0x30

    unsigned char heal(float amount);
};

struct TRIBE_Player {
    unsigned char pay_obj_cost(short type, float amount, int flag);
};

struct TRIBE_Combat_Object : RGE_Static_Object {
    unsigned char heal(float amount);
};
#endif

#ifdef T_C_OBJ_CONTEXT_H
#define hit_points hp
#define player owner
#endif

unsigned char TRIBE_Combat_Object::heal(float amount)
{
    TRIBE_Master_Combat_Object* master = this->master_obj;
    short type = master->object_type;
    if (type != 2 && type != 0x14 && type != 0x15 && type != 0x16) {
        return RGE_Static_Object::heal(amount);
    }

    long max_hp = master->max_hit_points;
    long heal_rate = master->heal_rate;
    float maxf = (float)max_hp;
    if ((amount = amount * maxf / heal_rate) + this->hit_points > maxf) {
        amount = maxf - this->hit_points;
    }

    if (this->player->pay_obj_cost(master->cost_type, amount / (float)(max_hp * 2), 1)) {
        return RGE_Static_Object::heal(amount);
    }
    return 2;
}

#ifdef T_C_OBJ_CONTEXT_H
#undef player
#undef hit_points
#endif
