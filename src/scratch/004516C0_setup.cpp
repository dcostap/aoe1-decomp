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
// GIVEUP: behavior is understood (base setup, set +0xA4/+4, fscanf five %hd into temp/parameter slots plus %f into +0x150, copy low bytes to +0x148..+0x14C). Remaining mismatch is source/stack-topology: original uses one pushed local, saves param_1 in EDI, evaluates base-call args right-to-left, and forms fscanf addresses from overlapping incoming parameter stack slots; rebuilt either omits EDI or perturbs argument/address ordering. Not proposing accepted_drift because stack writes/call setup are broad, not localized.

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
    FILE* file = param_1;

    ((RGE_Master_Combat_Object_setup4*)this)->setup(param_1, param_2, param_3, param_4);

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
