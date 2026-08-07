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
// Retry 2026-05-24 Boss pass: 10 more probes. Revalidated kept baseline (150B, 68.0000% positional / 54.6667% edit). Tried pre-base file local and register file (restores EDI lifetime but regresses first mismatch to +2 and wrong initial load order), reversed fscanf argument source order, explicit base pointer local, volatile FILE* after base, captured base setup return, widened base param_4 to int (movsx/worse), and /Ob0 flag (no change, removed). Best remains kept delayed-file baseline. Not accepted_drift: mismatch remains broad structural stack/call/register topology around base setup/fscanf and post-read copies.
// Retry 2026-05-26 Boss pass: 15 probes on VA 004516C0 only. Revalidated kept source: 150B, 68.0000% positional / 54.6667% edit, first mismatch +16. Tried pre-base file local and file-used-in-base (restored EDI but regressed to +2 / 81.3333%), explicit p4/p2/p3/file locals (88.6667%), short* casts for fscanf destinations, fmt local, byte-pointer field stores, return local, post-copy byte temps, captured base return, void* ballistics arg, and flag probes /G5 /Og /Oa /Oy- /O1. No improvement; most variants optimized to kept baseline or regressed broadly. GIVEUP: not accepted_drift quality; remaining mismatch is structural call/stack/register topology around base setup, fscanf address formation, and post-read copies.
// Luna-4516C0 2026-08-02: fresh baseline rebuilt 152B (75.0000% positional, first mismatch +16; prior 150B record was stale).
// Tried exact RGE_Master_Combat_Object declaration (no code change), pre-base FILE alias (88.1579%, wrong entry loads), using alias in base call (duplicate), register alias/declaration reorder (duplicate), and register FILE parameter (same 75.0000% family). Restored the delayed FILE alias best source. Structural blocker remains: original saves EDI before base-argument pushes and keeps incoming parameter homes as overlapping fscanf destinations; current source omits EDI and schedules the post-fscanf byte reload/store family differently. Not accepted_drift: broad call/stack topology drift.
// Luna4516C0 2026-08-02: bounded retry probes tested direct FILE use, volatile/separate FILE aliases, an address-taken parameter home, explicit base-call aliases, and the canonical named base layout. The volatile/pre-base families saved EDI but moved the initial parameter loads and remained 134-byte mismatches; direct/named-layout families were codegen duplicates of the 152-byte clean source. Restored the clean delayed-FILE source; blocker remains structural call/stack/register topology, not behavior or call-set uncertainty.
// Luna4516C0 sequential pass: dossier/donor/ABI evidence confirms the canonical base setup plus six-conversion fscanf behavior and exact call set.
// Tried typed RGE_Sprite**/RGE_Sound** parameters, this/self-slot overlap models, declaration-order moves, and comma-sequenced FILE aliases; no exact basin. A focused five-case alias lab grouped into only the delayed 152-byte family and the 134-byte prebase family.
// Restored the delayed-FILE clean source; remaining broad drift is the original EDI save plus overlapping parameter-home fscanf topology and post-read register coloring. Not accepted_drift.
// orch-w5 2026-08-07 EXACT MATCH: LESSONS.md parameter-slot reuse pattern (00438720 handle_scroll_view) applied.
// Declare short OUTPUT LOCALS (targetting_out/hit_info_out/die_info_out/area_specials_out) as the fscanf %hd
// destinations and leave the parameters untouched in source (file/sprites/sounds/target_type passed by value to
// base setup + fscanf). VC5 coalesces the locals into the incoming parameter homes (entry+0x10/+0xC/+8/+4) and
// keeps the unmodified file value in EDI across the base call, reproducing the original batch-arg prologue,
// overlapping lea destinations, and post-read byte reload/store family exactly. diff 114 -> 0. Moved to matching.

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
    int setup(FILE* file, void** sprites, void** sounds, short target_type);
};

struct RGE_Master_Combat_Object {
    char base[0x148];
    int setup(FILE* file, void** sprites, void** sounds, short target_type);
};

int RGE_Master_Missile_Object::setup(FILE* file, void** sprites, void** sounds, short target_type)
{
    short temp_missile_type;
    short targetting_out;
    short hit_info_out;
    short die_info_out;
    short area_specials_out;

    ((RGE_Master_Combat_Object*)this)->setup(file, sprites, sounds, target_type);

    *(unsigned char*)((char*)this + 0xA4) = 1;
    *(unsigned char*)((char*)this + 4) = 0x3C;

    fscanf(file, "%hd %hd %hd %hd %hd %f",
           &temp_missile_type,
           &targetting_out,
           &hit_info_out,
           &die_info_out,
           &area_specials_out,
           &ballistics_ratio);

    targetting_type = (unsigned char)targetting_out;
    missile_hit_info = (unsigned char)hit_info_out;
    missile_die_info = (unsigned char)die_info_out;
    area_effect_specials = (unsigned char)area_specials_out;
    missile_type = (unsigned char)temp_missile_type;

    return 1;
}
