// VA: 00415A10 UnitAIModule::mostDangerousEnemy
// aiuaimod.cpp
// Retry 2026-05-26: rebuilt full behavior with lookupObject, objectValue virtual threat calls, FPU compare, and outThreat store.
// Best result: exact size 188B, MISMATCH 73 positional / 20 edit bytes, first mismatch +40.
// Tried 10 variants: nested virtual call vs temp float, explicit actionObj local, owner local, master local order, threat2 short vs int,
// direct global id expression vs id temp, idx temp for best update, objectValue direct reload vs saved local, and loop/source order changes.
// Left in scratch: remaining drift is localized codegen/register coloring and one-byte branch-distance shifts in the per-object threat block:
// rebuilt keeps master in EDI and vtable in EBX while original keeps master in EBX and vtable in EDI; update block loads global/index in
// opposite order. Behavior/calls/stack cleanup/FPU compare look equivalent, but not proposing accepted_drift because drift spans register
// allocation throughout the central virtual-call block rather than a tiny isolated encoding difference.
// Luna415A10 pass: baseline rebuilt to 189B under the stricter boundary/call checker; old 188B cache
// had truncated the final ret operand. Direct loop-index ID spelling was codegen-duplicate.
// Unified objectValue/target as the proven polymorphic RGE_Static_Object surface and typed owner as
// RGE_Player*; both were codegen-duplicate. A focused central lab showed direct master/owner member
// access is the clean best source: 68 positional / 13 edit bytes, 98.53% shape, 189B.
// Update-order lab found pointer-local and volatile-index forms alter the prologue; the volatile-index
// probe regressed to 84 bytes. Restored the direct nonvolatile ID expression; remaining drift is the
// two independent update-block loads (original index-before-global, rebuilt global-before-index).
// Main-agent audit replaced literal absolute dereferences with the established shared globals and
// modeled the 8-byte lookup entry. That natural declaration context recovered exact load order,
// register allocation, branch distances, and 188/188-byte equality.

#include "../../include/game_globals.h"
#include "../../include/aiuaimod_context.h"

struct UnitAIObjectEntry {
    int object_id;
    int unknown;
};

int UnitAIModule::mostDangerousEnemy(float* outThreat) {
    search();

    int best = -1;
    float bestThreat = 0.0f;
    int i = 0;
    if ((int)DAT_0087d7d8 > 0) {
        do {
            RGE_Static_Object* obj = lookupObject(((UnitAIObjectEntry*)DAT_0087d7f0)[i].object_id);
            if (obj) {
                float f = objectValue->calculateDamage(
                    ((RGE_Master_Combat_Object*)obj->master_obj)->weapon_num,
                    ((RGE_Master_Combat_Object*)obj->master_obj)->weapon,
                    objectValue->calc_attack_modifier(obj, obj->owner, obj));
                if (best == -1 || f > bestThreat) {
                    bestThreat = f;
                    best = ((UnitAIObjectEntry*)DAT_0087d7f0)[i].object_id;
                }
            }
            i++;
        } while (i < (int)DAT_0087d7d8);
    }

    if (outThreat) {
        *outThreat = bestThreat;
    }
    return best;
}
