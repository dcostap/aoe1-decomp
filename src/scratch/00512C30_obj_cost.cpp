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
// BLOCKER: exact 642B with correct prologue/initialization, but cost blocks remain in a different narrow-vs-int codegen basin: original keeps __ftol result in BP then sign-extends BP for fild; rebuilt sign-extends AX into EBP directly and schedules fild/lea differently. Broad downstream positional drift remains, not accepted_drift-safe.
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

typedef unsigned char uchar;
class TRIBE_Player;
class ObjectInfo {
public:
    virtual ~ObjectInfo();
    unsigned char type; char pad5[3]; char* name;
    char pad0c[0x148-0x0c];
    short cost1_type; short cost1_amount; unsigned char cost1_used;
    char pad14d; short cost2_type; short cost2_amount; unsigned char cost2_used;
    char pad153; short cost3_type; short cost3_amount; unsigned char cost3_used;
};
class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char pad4[0x20]; ObjectInfo** objects; char pad28[0x50-0x28]; float* resources;
    uchar check_obj_cost(short, int, float, int);
    void obj_cost(short, char**, short&, short&, short&, short&, short&, short&, float);
};
extern "C" long __cdecl _ftol(void);

void TRIBE_Player::obj_cost(short obj, char** nameOut, short& t1, short& a1, short& t2, short& a2, short& t3, short& a3, float factor)
{
    short cost;
    short avail;
    short* amount_output;
    short total = 0;
    t1 = -1; a1 = total; t2 = -1; a2 = total; t3 = -1; a3 = total;
    uchar can = this->check_obj_cost(obj, 0, 1.0f, 0);
    ObjectInfo* info = this->objects[obj];
    if (info == 0 || info->type < 0x46) return;
    if (nameOut) *nameOut = info->name;

    if (info->cost1_used) {
        t1 = info->cost1_type;
        if (t1 >= 0) {
            cost = (short)(int)(info->cost1_amount * factor);
            a1 = cost;
            if ((float)cost > this->resources[t1] && can) {
                avail = (short)(long)this->resources[t1];
                total = cost - avail;
                a1 = avail;
            }
        }
    }
    if (info->cost2_used) {
        t2 = info->cost2_type;
        if (t2 >= 0) {
            cost = (short)(int)(info->cost2_amount * factor);
            a2 = cost;
            if ((float)cost > this->resources[t2] && can) {
                avail = (short)(long)this->resources[t2];
                total += cost - avail;
                a2 = avail;
            }
        }
    }
    if (info->cost3_used) {
        t3 = info->cost3_type;
        if (t3 >= 0) {
            cost = (short)(int)(info->cost3_amount * factor);
            a3 = cost;
            if ((float)cost > this->resources[t3] && can) {
                avail = (short)(long)this->resources[t3];
                total += cost - avail;
                a3 = avail;
            }
        }
    }
    if (total > 0) {
        if (t1 == 3 || t1 == -1) {
            t1 = 3;
            amount_output = &a1;
        }
        else {
            if (t2 != 3 && t2 != -1) {
                if (t3 == 3 || t3 == -1) {
                    t3 = 3;
                    a3 = total;
                }
                goto done_total;
            }
            t2 = 3;
            amount_output = &a2;
        }
        *amount_output += total;
    }
done_total:
    if (a1 <= 0) t1 = -1;
    if (a2 <= 0) t2 = -1;
    if (a3 <= 0) t3 = -1;
}
