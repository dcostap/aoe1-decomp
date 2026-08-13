// VA: 004DE1F0, TribeInformationAIModule::objectToDefend, 314 bytes
// Source: taiinfmd.cpp lines 4440-4521
// FLAGS: default
//
// Finds the best ImportantObjectEntry to defend based on:
// - Entry must be in itemsToDefend (value, numberValue, maxSize at +0x148/4C/54)
// - Entry's field_10 (+0x10) must be <= 0
// - No bestGroup found at position via tacticalAI (md + 0x1146C)
// - Uses defendPriority(type, group) scoring to pick the best entry
//
// Returns pointer to ImportantObjectEntry (reuses param_1 slot on stack)
//
// === Attempt log ===
// Prior scratch work used packed records, a moving entry pointer, and a
// separately computed strategic-number temporary; that basin was 26-34 bytes
// short and had the wrong tactical-call argument schedule.
// Fresh baseline: canonical ObjectMemory/ManagedArray ownership and the
// typed MainDecision -> TribeMainDecision -> tacticalAI surface.  The direct
// indexed scan and nested strategicNumber expression restored the 314-byte
// structural basin and the original point-argument push/store sequence.
// Probes then tested outer-index lifetime, local scope/order, comparison
// spelling, and named record-id/count locals.  The useful result is the
// canonical typed source below; remaining drift is confined to prologue/early
// null-return register allocation, the count/id register colors, and branch
// span placement.  No custom flags, inline asm, or raw layout plumbing kept.
//
// Fresh session evidence (sa-a7a5bf85-r1): initializing the outer index before
// md->object() keeps EBX saved at entry and improves the diagnostic diff to
// 293 bytes, but moves the argument load/zero-store schedule and is not the
// clean source.  Separate explicit byteOffset/cursor forms, scoped entry
// pointers, count/id declaration permutations, a reused strategic-number local,
// and the derived virtual-destructor declaration were either neutral or
// structurally worse.  A 64-variant natural local/id/count lab found no exact
// size/frame/call-set candidate.  Restored clean source remains the natural
// typed indexed scan; unresolved drift is the entry prologue/null-return basin
// plus EDX/EDI count-versus-id coloring and associated branch spans.
//
// Fresh session evidence (sat-4DE1F0-cursor): corrected MainDecisionAIModule::
// object() to the canonical RGE_Static_Object* return type.  The first cursor
// probe used a top-level byte offset, a guarded reset, a separate count, and a
// scoped entry pointer; it changed the frame to 0x14 and moved to the EDI/ESI
// prologue basin (diff 289, shape 66.67%).  The second probe removed the
// scoped pointer and used the raw 004D9970 offset expressions.  It restored
// the 0x10 frame, EBX/ESI saves, and 77.32% exact-block coverage (diff 293),
// but the first prologue hunk remained different.  Both diagnostics were
// rolled back.  The natural indexed scan remains the clean source.
//
// Fresh session evidence (refill-4DE1F0-r1): naming the md->object result
// before the null guard matches the binary's explicit RGE_Static_Object local.
// It restores all 97 instruction shapes and reduces drift from 298 to 6
// bytes.  The remaining six bytes are only EDX/EDI coloring for the record id
// and itemsToDefend count.  Scoped typed entry, list aliases, local lifetime
// changes, and declaration order changes were duplicates or structural losses.
// The best source keeps named nested ownership and the explicit object result.
//
// Session orch-4DE1F0-a: direct numberValue conditions, direct record-id
// expressions, scoped id/count lifetime splits, assignment-in-condition,
// field reference/pointer bindings, and a four-variant int/long plus
// value/reference lab all preserved the same six-byte EDX/EDI register-color
// gap.  One deliberate strategic-number local reuse worsened the call block
// to 35 bytes; all other probes were duplicates or structural losses.  Restored
// and validated the clean typed indexed scan; no evidence-backed lead remains.
//
// Session orch-4DE1F0-b: a persistent typed entry pointer changed the frame
// to 0x14 and widened the mismatch to 291 bytes, so it was rolled back.
// Register declarations for the list count, record id, and outer index were
// neutral or structural duplicates.  A natural for-loop increment, direct
// repeated id expressions, an id-address lvalue, and an inner-scope id were
// also duplicates.  The clean indexed scan remains at 314 bytes with 97/97
// instruction shapes and four ordered calls.  The only gap is the six-byte
// EDX/EDI allocation swap at the inner list scan; no plausible source lead
// remains in this claim.

#include <stddef.h>

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

class InformationAIModule : public AIModule {
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct ObjectMemory {
    int id;                         // +0x00
    short type;                     // +0x04
    short group;                    // +0x06
    unsigned char x;                // +0x08
    unsigned char y;                // +0x09
    unsigned char z;                // +0x0A
    unsigned char owner;            // +0x0B
    short hitPoints;                // +0x0C
    unsigned char pad_0E[2];        // +0x0E
    int attackAttempts;             // +0x10
    unsigned char kills;            // +0x14
    unsigned char pad_15[3];        // +0x15
    float damageCapability;         // +0x18
    float rateOfFire;               // +0x1C
    float range;                    // +0x20
};

struct XYPoint {
    int x;
    int y;
};

class TacticalAIGroup;
class RGE_Static_Object;

class MainDecisionAIModule : public AIModule {
public:
    void* player;                   // +0xF0
    ManagedArray<int> objects;      // +0xF4
    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule;

class TacticalAIModule : public AIModule {
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    int strategicNumber(int index);
    TacticalAIGroup* bestGroup(int param_1, int param_2, int param_3,
                               XYPoint* param_4, int param_5);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1146C - 0x104];
    TribeTacticalAIModule tacticalAI;  // +0x1146C
};

class TribeInformationAIModule : public InformationAIModule {
public:
    ManagedArray<int> farmsTaskedThisUpdate; // +0xF0
    TribeMainDecisionAIModule* md;           // +0x100
    int mapXSizeValue;                       // +0x104
    int mapYSizeValue;                       // +0x108
    int lastUpdateRowValue;                  // +0x10C
    int maxImportantObjectMemory;            // +0x110
    ObjectMemory* importantObjectMemory;     // +0x114
    ManagedArray<int> importantObjects;      // +0x118
    ManagedArray<int> importantUnits;        // +0x128
    ManagedArray<int> importantMiscs;        // +0x138
    ManagedArray<int> itemsToDefend;         // +0x148

    ObjectMemory* objectToDefend(int target_obj_id);
    int defendPriority(int type, int group);
};

ObjectMemory* TribeInformationAIModule::objectToDefend(int target_obj_id)
{
    ObjectMemory* bestEntry;
    int bestDefendValue;
    XYPoint pt;
    int i;
    int numValues;
    int objectId;

    RGE_Static_Object* target = this->md->object(target_obj_id);
    if (target == 0)
        return 0;

    bestEntry = 0;
    bestDefendValue = -1;
    i = 0;

    if (this->maxImportantObjectMemory > 0) {
        do {
            objectId = this->importantObjectMemory[i].id;
            if (objectId != -1) {
                numValues = this->itemsToDefend.numberValue;
                int idx = 0;

                if (numValues > 0) {
                    while (idx < numValues) {
                        if (idx >= this->itemsToDefend.maximumSizeValue)
                            break;
                        if (this->itemsToDefend.value[idx] ==
                            objectId) {
                            if (this->importantObjectMemory[i].attackAttempts <= 0) {
                                pt.x = (int)this->importantObjectMemory[i].x;
                                pt.y = (int)this->importantObjectMemory[i].y;
                                idx = -1;

                                TacticalAIGroup* bestG =
                                    this->md->tacticalAI.bestGroup(
                                        -1, 4,
                                        this->md->tacticalAI.strategicNumber(0x5C),
                                        &pt, idx);
                                
                                if (bestG == 0) {
                                    int priority = this->defendPriority(
                                        (int)this->importantObjectMemory[i].type,
                                        (int)this->importantObjectMemory[i].group);
                                    if (bestEntry == 0 || bestDefendValue > priority) {
                                        bestEntry = &this->importantObjectMemory[i];
                                        bestDefendValue = priority;
                                    }
                                }
                            }
                            break;
                        }
                        
                        idx++;
                    }
                }
            }
            
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    
    return bestEntry;
}
