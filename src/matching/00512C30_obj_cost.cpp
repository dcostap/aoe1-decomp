// Attempt log for 00512C30 TRIBE_Player::obj_cost
// try 1: natural reconstruction from packet/decompiler with three cost blocks and final food/wood/gold repair; exact size but xor ebx delayed and uses immediate zero stores.
// try 2: initialize int total before output stores to encourage EBX zeroing and bx stores; exact size and first mismatch deeper, but movsx ebp,ax instead of mov bp,ax.
// try 3: use short total again with early initialization; shrank to 640B, rolled back.
// try 4: restore int total and use int cost variables; first mismatch deeper but still movsx ebp,ax family.
// try 5: compare using (float)(short)cost; worse, rolled back.
// try 6: restore direct int cost compare best int-cost form.
// try 7: /Oy- flag probe; too small 624B, rolled back.
// try 8: /O1 flag probe; too small 592B, rolled back.
// try 9: reviewed final repair if/else structure; source matches original branch family, kept.
// try 10: reviewed parameter order and initialization; early init now matches prologue exactly through offset 180.
// try 11: use direct short output stores and function-scope short availability/total
// locals, matching the Ghidra-supported sVar3/sVar4/sVar6 shape. Exact 642B.
// The prior narrow-vs-int blocker is resolved without compiler steering.
//
// Bounded retry sa274ecf51_objcost (2026-08-11, 10 hypotheses):
// - Integrated baseline: typed object table/resources and natural three-cost source, 642B,
//   7/7 calls and exact prologue; 178 strict bytes (27.7259%), first mismatch at mov bp,ax.
// - Short cost locals alone moved the first mismatch earlier and worsened strict bytes.
// - Short total plus short cost/availability locals reached a stable 639B effective build
//   with exact CFG/call set, 100% exact-block coverage, and 29 edit bytes (95.95% resync),
//   but the three missing bytes are the oracle's partial-register mov bp,ax/mov si,ax forms;
//   positional drift then spans later branch displacements. Function-scope lifetimes,
//   explicit compare temporaries, psVar5-style common repair pointer, int/long cast spelling,
//   narrow _ftol declaration, and same-TU polymorphic class surfaces were codegen duplicates.
// - Retained source is the simplest binary-supported typed model: short cost/availability/
//   shortage values, PDB reference output ABI, and exact-sibling vptr/layout surfaces.
//   Remaining drift is broad register/partial-width codegen, not accepted-drift-safe.
//
// ShardB6 retry:
// - Restored the earlier pointer-ABI, explicit six-byte cost fields, and int shortage total.
//   This rebuilt at 642 bytes with 178 strict diff bytes; the old 642-byte size was not exact.
// - Removed explicit long casts from the natural float-to-short cost expression; code was unchanged.
// - Changed check_obj_cost's second parameter from int to the exact short-pointer donor ABI; code was unchanged.
// - Function-scope short cost/availability temporaries with an int total rebuilt at 642 bytes but worsened
//   to 304 diff bytes. Rolled back.
// - The final direct-output short form is the simplest binary-supported typed model.
//   Fresh authoritative validation is an exact MATCH: 642/642 bytes, 0.0000%.

typedef unsigned char uchar;
class TRIBE_Player;
class ObjectInfo {
public:
    char pad0[4]; unsigned char type; char pad5[3]; char* name;
    char pad0c[0x148-0x0c];
    short cost1_type; short cost1_amount; unsigned char cost1_used;
    char pad14d; short cost2_type; short cost2_amount; unsigned char cost2_used;
    char pad153; short cost3_type; short cost3_amount; unsigned char cost3_used;
};
class TRIBE_Player {
public:
    char pad0[0x24]; ObjectInfo** objects; char pad28[0x50-0x28]; float* resources;
    uchar check_obj_cost(short, short*, float, int);
    void obj_cost(short, char**, short*, short*, short*, short*, short*, short*, float);
};
extern "C" long __cdecl _ftol(void);

void TRIBE_Player::obj_cost(short obj, char** nameOut, short* t1, short* a1, short* t2, short* a2, short* t3, short* a3, float factor)
{
    short avail;
    short* amount_output;
    short total = 0;
    *t1 = -1; *a1 = total; *t2 = -1; *a2 = total; *t3 = -1; *a3 = total;
    uchar can = this->check_obj_cost(obj, 0, 1.0f, 0);
    ObjectInfo* info = this->objects[obj];
    if (info == 0 || info->type < 0x46) return;
    if (nameOut) *nameOut = info->name;

    if (info->cost1_used) {
        *t1 = info->cost1_type;
        if (*t1 >= 0) {
            *a1 = (short)(info->cost1_amount * factor);
            if ((float)(int)*a1 > this->resources[*t1] && can) {
                avail = (short)(long)this->resources[*t1];
                total = (short)(*a1 - avail);
                *a1 = avail;
            }
        }
    }
    if (info->cost2_used) {
        *t2 = info->cost2_type;
        if (*t2 >= 0) {
            *a2 = (short)(info->cost2_amount * factor);
            if ((float)(int)*a2 > this->resources[*t2] && can) {
                avail = (short)(long)this->resources[*t2];
                total += (short)(*a2 - avail);
                *a2 = avail;
            }
        }
    }
    if (info->cost3_used) {
        *t3 = info->cost3_type;
        if (*t3 >= 0) {
            *a3 = (short)(info->cost3_amount * factor);
            if ((float)(int)*a3 > this->resources[*t3] && can) {
                avail = (short)(long)this->resources[*t3];
                total += (short)(*a3 - avail);
                *a3 = avail;
            }
        }
    }
    if (total > 0) {
        if (*t1 == 3 || *t1 == -1) {
            *t1 = 3;
            amount_output = a1;
        }
        else {
            if (*t2 != 3 && *t2 != -1) {
                if (*t3 == 3 || *t3 == -1) {
                    *t3 = 3;
                    *a3 = total;
                }
                goto done_total;
            }
            *t2 = 3;
            amount_output = a2;
        }
        *amount_output += total;
    }
done_total:
    if (*a1 <= 0) *t1 = -1;
    if (*a2 <= 0) *t2 = -1;
    if (*a3 <= 0) *t3 = -1;
}
