// VA: 004516C0 RGE_Master_Missile_Object::setup
// PDB source: m_mi_obj.cpp
// Attempt log:
// try 1: inherited version used separate locals and post-fscanf float assignment; mismatch broad (sub esp 8, wrong stack homes).
// try 2: use incoming parameter stack slots as fscanf %hd destinations plus one local temp_missile_type, matching decompiler/original stack-overlap pattern.
// try 3: fixed object_type offset (+4 vs +0xA4) and removed separate float local/post-fscanf store; still wrong register/order basin.
// try 4: introduced FILE* file local/register to keep param_1 live in EDI across base setup; did preserve EDI but perturbed initial argument load/order and fscanf address generation.
// try 5: base call with original params plus later file local; no improvement.
// Boss retry 2026-05-19:
// try 6: explicit p4/p2/p3/file locals in desired load order before base call; optimized back to same
//        122/150 positional baseline.
// try 7: widened base setup param_4 to int; worsened to 134/150 positional with movsx param_4.
// try 8: explicit `(float*)((char*)this+0x150)` fscanf arg; no codegen change from baseline.
// Rolled back int base signature; kept best baseline exact-size source.
// Retry 2026-05-20 assigned pass:
// try 9: revalidated best baseline, exact 150B but 122 positional / 74 edit, first mismatch +2.
// try 10: predeclared p4/p2/p3/file locals in original desired load order before base call; optimized back to baseline.
// try 11: delayed file local until after base call; changed first mismatch to +16 but worsened to 102 positional and lost desired EDI lifetime.
// try 12: int a4 plus explicit a2/a3/file locals; worsened to 135 positional / wrong call setup.
// try 13: no file local until after call; same 102 positional family as delayed file.
// try 14: `*(short*)&param_4` base-call argument; no change from baseline.
// try 15: cast fscanf %hd destinations to `(short*)&param_N`; no change.
// try 16: use `&ballistics_ratio` instead of raw float pointer; no change.
// try 17: split fscanf argument addresses into void* locals; optimized back to baseline.
// try 18: dummy pre-fscanf missile_type assignment; worsened edit diff and did not affect first mismatch.
// try 19: flag probes /Ob0, no /Oy, and /Gf; no change. /Og- and /O1 produced wrong codegen families; flags removed.
// GIVEUP: behavior is understood (base setup, set +0xA4/+4, fscanf five %hd into temp/parameter slots plus %f into +0x150, copy low bytes to +0x148..+0x14C). Remaining mismatch is source/stack-topology: original uses one pushed local, saves param_1 in EDI, evaluates base-call args right-to-left, and forms fscanf addresses from overlapping incoming parameter stack slots; rebuilt either delays EDI or perturbs argument/address ordering. Not proposing accepted_drift because stack writes/call setup are broad, not localized.
// Retry 2026-05-21 Boss pass: 17 more probes. Tried p4/p2/p3/file locals in desired load order, no-file-local until after base call, delayed/register/volatile file, base call with file/param mixes and comma assignment, fscanf address locals, copied post-fscanf store order, short* casts to parameter slots, &ballistics_ratio/address locals, and several file-lifetime variants. Best kept below improves to 68.0000% positional with first mismatch +16 by delaying the file local until after the base setup call, matching the initial parameter-load order; however it loses the original EDI file lifetime and still has broad fscanf address/copy scheduling drift. No accepted_drift: stack/call/register topology remains structural.

#include <stdio.h>

struct RGE_Master_Missile_Object {
    char gap_000[0x148];
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    char gap_14D[3];
    float ballistics_ratio;
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
};

struct RGE_Master_Combat_Object_setup4 {
    char base[0x148];
    int setup(FILE* param_1, void** param_2, void** param_3, short param_4);
};

int RGE_Master_Missile_Object::setup(FILE* param_1, void** param_2, void** param_3, short param_4)
{
    short temp_missile_type;
    ((RGE_Master_Combat_Object_setup4*)this)->setup(param_1, param_2, param_3, param_4);
    FILE* file = param_1;

    *(unsigned char*)((char*)this + 0xA4) = 1;
    *(unsigned char*)((char*)this + 4) = 0x3C;

    fscanf(file, "%hd %hd %hd %hd %hd %f",
           &temp_missile_type,
           &param_4,
           &param_3,
           &param_2,
           &param_1,
           (float*)((char*)this + 0x150));

    targetting_type = (unsigned char)param_4;
    missile_hit_info = (unsigned char)param_3;
    missile_die_info = (unsigned char)param_2;
    area_effect_specials = (unsigned char)param_1;
    missile_type = (unsigned char)temp_missile_type;

    return 1;
}
