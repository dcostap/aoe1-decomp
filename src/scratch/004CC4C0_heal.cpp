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
    amount = amount * maxf / heal_rate;
    if (amount + this->hit_points > maxf) {
        amount = maxf - this->hit_points;
    }

    if (this->player->pay_obj_cost(master->cost_type, amount / (float)(max_hp * 2), 1)) {
        return RGE_Static_Object::heal(amount);
    }
    return 2;
}
