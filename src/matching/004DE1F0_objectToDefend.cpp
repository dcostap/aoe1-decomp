// VA: 004DE1F0, TribeInformationAIModule::objectToDefend, 314 bytes
// Source: taiinfmd.cpp lines 4440-4521
// FLAGS: default
//
// Status: EXACT â€” MATCH under the default VC5 flags.
//
// Selects the best ObjectMemory entry that is in itemsToDefend, has no attack
// attempts, and has no tactical group at its stored point.
// It scores each candidate with defendPriority and publishes the best entry.
//
// BINARY NOTE: The PDB line band at taiinfmd.cpp:4459 owns the containment
// scan. Its assembly reads numberValue and maximumSizeValue, then scans value.
// The reviewed ManagedArray::contains surface reproduces that scan and the
// original EDX/EDI allocation.
//
// BINARY NOTE: The target lookup occurs before all candidate reads. The null
// return therefore preserves the executable fault order.
//
// Exact-finish record:
// - The reviewed information_dropsites_context.h declarations retain the
//   ObjectMemory stride, md/world ownership, tacticalAI calls, and ABI.
// - Replacing the expanded caller loop with a natural inline contains method
//   changed the known six-byte EDX/EDI recolor to exact bytes.
// - Removing contains temporaries, using its result as a Boolean, and scoping
//   its index each stayed exact. These forms are not required.
// - Restoring the pinned expanded loop returned the six-byte mismatch.
//   The contains method is the required source model.
//
// Validation: 314 bytes, 97 instructions, 0.0000%, four ordered direct calls,
// 0x10 frame, original boundary, and the TribeInformationAIModule owner.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

template <class T>
int ManagedArray<T>::contains(const T& item) const
{
    for (int j = 0; j < this->numberValue; j++) {
        if (j >= this->maximumSizeValue)
            return 0;
        if (this->value[j] == item)
            return 1;
    }
    return 0;
}

#endif
ObjectMemory* TribeInformationAIModule::objectToDefend(int target_obj_id)
{
    ObjectMemory* bestEntry;
    int bestDefendValue;
    XYPoint pt;
    int i;
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
                if (this->itemsToDefend.contains(objectId)) {
                    if (this->importantObjectMemory[i].attackAttempts <= 0) {
                        pt.x = (int)this->importantObjectMemory[i].x;
                        pt.y = (int)this->importantObjectMemory[i].y;

                        TacticalAIGroup* bestG =
                            this->md->tacticalAI.bestGroup(
                                -1, 4,
                                this->md->tacticalAI.strategicNumber(0x5C),
                                &pt, -1);

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
                }
            }

            i++;
        } while (i < this->maxImportantObjectMemory);
    }

    return bestEntry;
}
