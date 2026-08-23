// VA: 004D96B0 TribeInformationAIModule::gameIDsOfObjectType
// Attempt log:
// try 1: direct behavioral reconstruction from decompiler/asm: scan importantObjects, filter by player/master, grow output arrays and important object vector as needed.
// try 2: helper-based ensureImportant compiled too small (624B vs 691B); inlined both growth sites like original.
// try 3: inlined importantObjects growth at top of each iteration, matching original operator new/delete copy loop family.
// try 4: inlined second importantObjects growth before writing accepted result.
// try 5: modeled output ids/owners allocation as two arrays sized maxCount*8, then doubled maxCount.
// try 6: modeled copy of old output arrays before freeing/replacing pointers.
// try 7: modeled special playerFilter -5 same-player exclusion.
// try 8: modeled special playerFilter -6 relation check via virtual call on current AI player.
// try 9: modeled ordinary player and object type filters using owner id and master id offsets.
// try 10: /GX probe no change; removed.
// try 11: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 12: restored the same-TU RGE_Player virtual surface through vslot +0x14;
// relation is the +0x18 slot used by the original call.  The prior three-slot
// stub emitted an unrelated +0x0C virtual call and was not a valid ABI model.
// try 13: replaced the three-field array stub with the same-TU ManagedArray<int>
// surface.  This fixed maximumSizeValue at +0x124 and restored both inline
// growth blocks.  Direct md->aiPlayer->world ownership also removed an extra
// pointer hop.  The rebuilt body reached 319 differing bytes, then 24 bytes
// after removing the redundant positive-capacity copy guard.
// try 14: moved the loop-index initialization before the outer guard; exact
// size and all CFG/call counts now match.
// try 15: operand order, scoped aliases, combined relation predicate, and a
// final objectID local were neutral or worse.  The direct typed source is kept.
// try 16: a focused natural final-store lab kept the direct member spelling as
// the only size/frame/call-set eligible variant; pointer/reference/value-member
// forms changed the frame or broadened the mismatch.
// try 17: same-TU virtual class surfaces for the object, master, player, and
// main-decision types preserved offsets but emitted the same 24-byte drift.
// try 18: equivalent ids[0] indexing and post-increment output storage were
// neutral; restored the clean explicit count update.
// try 19: a typed ownerID local before the relation call was neutral; restored
// the direct owner-id argument and kept the clean source.
// revisit probes: direct final indexed assignment (without objectID), swapped
// -5 comparison operands, a scoped -5 owner alias, and a TRIBE_Player-derived
// aiPlayer type all stayed in the same 691-byte/24-byte-drift basin.  These
// variants did not improve the localized register/address mismatch.  Restored
// the pinned direct typed source; no policy-invalid form was retained.
// revisit-2: completed 20 additional evidence-led hypotheses.  Canonical
// object/master/world surfaces, AIModule inheritance, full player fields,
// named information fields, relation ABI/casts, sentinel predicate forms,
// scoped receiver/owner/ID/result locals, and output-array aliases either
// duplicated the basin or worsened size/CFG.  A 128-variant lab combining
// ambient TU declarations with four natural local/store axes produced one
// 691-byte group.  An eight-variant standard-header context lab also produced
// one 691-byte group.  No exact candidate or new source lead resulted.
// fresh pass: explicit relation owner locals, direct and aliased final stores,
// predicate conjunctions, PDB line directives, narrow relation ABI forms, and
// signed argument casts all duplicated the 691-byte/24-byte basin.  A sixteen-
// variant register-declaration lab also produced one unchanged code group.
// left in scratch: 24 localized register/address bytes remain in the -5/-6
// player filters and final ID store.  Size, frame, calls, CFG, and 89.52% of
// blocks are exact; the remaining drift is not accepted_drift-safe.
// Accepted-drift audit: the -6 filter reads aiPlayer before obj->owner in the
// rebuild, while the executable reads obj->owner first. The final store also
// dereferences *ids before it reads importantObjects[i], reversing the original
// order. These changes affect pointer faults and concurrent table replacement.
// Canonical taiinfmd group pass: paired post-increment output stores recovered
// the complete final-store block. Strict drift fell from 24 to 14 bytes, and
// exact-block coverage rose from 89.52% to 95.71%. The output pointer and
// importantObjects element now use the executable's fault order.
// Branch-local owner, player, owner-ID, register, partial-md, pointer-slot, and
// reference forms did not improve the two special player filters. Pointer-slot
// forms also added three bytes. The remaining -6 block still loads aiPlayer
// before obj->owner. This fault-order difference blocks accepted drift.
// Exact-finish continuation: retesting partial-md and shared-owner lifetimes
// after the final-store recovery produced broad 52-byte and 463-byte drift.
// An explicit short argument cast and the local player vslot-0 spelling were
// codegen-neutral. No natural form forced the required owner-before-aiPlayer
// read without adding code or changing other exact blocks. The 14-byte result
// remains the safe source.
// Exact-finish continuation: fresh checks of owner locals, receiver locals,
// comma sequencing, combined guards, period headers, donor virtual surfaces,
// direct member declarations, and long relation ABI all duplicated 691/14.
// The clean nested predicates and shared information-AI context are restored.

// The information arrays use the inline ManagedArray<int> surface from the
// same translation unit.  Its desired-size member is real, even though this
// function does not read it; maximumSizeValue is therefore at +0x0C.
#include <stddef.h>
#include "../../include/information_dropsites_context.h"

int TribeInformationAIModule::gameIDsOfObjectType(int objectType, int** ids, int** owners, int playerFilter)
{
    *ids = 0;
    int count = 0;
    *owners = 0;
    int maxCount = 10;
    int i = 0;
    if (this->importantObjects.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->aiPlayer->world->object(
                this->importantObjects[i]);
            if (obj != 0) {
                if (playerFilter == -5) {
                    if (this->md->aiPlayer->id == obj->owner->id) goto next;
                }
                if (playerFilter == -6) {
                    if (this->md->aiPlayer->relation(obj->owner->id) != 0) goto next;
                }
                if (playerFilter != -1 && obj->owner->id != playerFilter) goto next;
                if (objectType != -1 && objectType != ((RGE_Master_Object*)obj->master)->id) goto next;
                if (count == maxCount || *ids == 0) {
                    int* newIds = (int*)operator new(maxCount * 8);
                    int* newOwners = (int*)operator new(maxCount * 8);
                    if (*ids != 0) {
                        for (int j = 0; j < maxCount; j++) {
                            newIds[j] = (*ids)[j];
                            newOwners[j] = (*owners)[j];
                        }
                    }
                    maxCount *= 2;
                    if (*ids != 0) operator delete(*ids);
                    if (*owners != 0) operator delete(*owners);
                    *ids = newIds;
                    *owners = newOwners;
                }
                (*ids)[count] = this->importantObjects[i];
                (*owners)[count++] = obj->owner->id;
            }
next:
            i++;
        } while (i < this->importantObjects.numberValue);
    }
    return count;
}
