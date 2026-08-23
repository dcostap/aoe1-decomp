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

class RGE_Master_Combat_Object_View {
public:
    char gap_000[0x108];
    short weapon_num;
    char gap_10A[2];
    void* weapon;
};

struct UnitAIObjectEntry {
    int object_id;
    int unknown;
};

// Beta uses narrower argument lists at these two established object slots.
class RGE_Static_Object_Threat_Query {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70();
    virtual float calculateDamage(int, void*, float); // +0x74
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(); virtual void vA0(); virtual void vA4();
    virtual void vA8(); virtual void vAC(); virtual void vB0(); virtual void vB4();
    virtual void vB8(); virtual void vBC(); virtual void vC0(); virtual void vC4();
    virtual void vC8(); virtual void vCC(); virtual void vD0(); virtual void vD4();
    virtual void vD8(); virtual void vDC(); virtual void vE0(); virtual void vE4();
    virtual void vE8(); virtual void vEC();
    virtual float calc_attack_modifier(RGE_Static_Object*, RGE_Player*,
                                       RGE_Static_Object*); // +0xF0
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
                float f = ((RGE_Static_Object_Threat_Query*)objectValue)
                    ->calculateDamage(
                        ((RGE_Master_Combat_Object_View*)obj->master_obj)->weapon_num,
                        ((RGE_Master_Combat_Object_View*)obj->master_obj)->weapon,
                        ((RGE_Static_Object_Threat_Query*)objectValue)
                            ->calc_attack_modifier(obj, obj->owner, obj));
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
