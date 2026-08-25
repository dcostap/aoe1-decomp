// VA 004D9240 TribeInformationAIModule::gameIDOfResourceObject
// taiinfmd.cpp:1188-1484
// Attempt log:
// 1: Natural reconstruction from packet/decompiler, modeling ResourceMemory scan and scoring/filter logic.
// 2: Added output resource id initialization to -1 and mainDecision object(gathererId) lookup/null return.
// 3: Added currentZone and __ftol-style gatherer X/Y capture plus isBoat(gatherer) classification.
// 4: Added resource-list scan over arrays at +0x4D0/+0x4E0 and ResourceMemory stride 0x14 with dead/delay handling.
// 5: Added caller-supplied exclusion-list scan and missing-object dead marking/dropsite-update detection.
// 6: Added boat-vs-land class filters for classes 5/0x1F/0x21.
// 7: Added score calculation from squared tile distance, memory base field, age/amount divisors, numberGatherersWithTarget pressure, and best-score replacement.
// 8: Added special filters for animals/farms/buildings: towncenter/enemy attack checks, same-civ/state checks, important-id scan, per-resource gatherer thresholds, strategic-number/resource-count test.
// 9: Added gatherer lookupZone equality gate and final best-object result update: increment memory byte +6, write resource id, return memory id.
// 10: Fixed VC5 goto-crosses-initialization errors by hoisting loop locals.
// 11: Default /O2 /Oy exact-size build compares but is broad: 954 bytes / 84.4248% positional, first mismatch offset 9. Main early issue is register allocation/prologue: original keeps this in ESI and object in EDI; rebuilt keeps this in EBP and object in ESI, cascading through the function.
// 12: Probed /O2 /Oy /Ob0: identical broad mismatch; removed flag.
// 13: Probed /Od: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 14: Probed /O2 /Oy /Og-: exact size but wrong basin from offset 0 (91.5044% positional); removed flag.
// 15: Replaced the out-of-line tactical() wrapper with direct +0x1146C typed calls and bound the threshold to DAT_00575568; this removes six extra wrapper call sites and restores the original global identity, while retaining the clean reconstruction.
// 16: Restored canonical RGE_Static_Object/RGE_Master_Static_Object offsets and ResourceMemory/ManagedArray ownership names (compiler pointer, id, gatherValue, farmsTaskedThisUpdate); this is a source/layout reconstruction probe, not a raw-offset workaround.
// 17: Changed the gatherer gate to a positive outer guard with the shared -1 epilogue, matching the original far JE topology instead of an early negative return.
// 18: Corrected two binary-proven farm/strategic rejection edges to the shared next-resource path (004D9642/004D9646); removed the decompiler-only skip_restore label.
// GIVEUP: left in scratch. Behavior is broad but source/register topology is far from original; no accepted_drift because mismatch is broad and begins in prologue/register allocation.
// Main-agent audit: a donor-backed virtual-destructor replacement for the
// proven compiler pointer fields was tested and rolled back because it changed the early
// VC5 prologue/register basin. The typed compiler pointer fields remain explicit binary
// layout evidence in this unresolved scratch reconstruction.
// 19: Same-TU taiinf donors and ABI evidence show md->object returns a typed
// RGE_Static_Object*. Corrected that ownership surface and removed two casts;
// this is a direct typed-call probe, not a register-coloring adjustment.
// 20-29: Tested standard headers, full AIModule inheritance, polymorphic owner
// surfaces, top-level local declarations, cursor forms, and for/do loop forms.
// The best clean basin is 1075/1130 bytes, 88.29% shape, 51.51% exact blocks,
// with all 16 calls aligned. The first mismatch remains the prologue at +9.
// BINARY NOTE: master object_group is at +0x14; the +0x12 pad is required.
// BINARY NOTE: town-center gather attempts use signed division by 150.
// BINARY NOTE: the amount bonus uses a strict greater-than threshold.
// BINARY NOTE: the current source recovers the original ESI this and EDI
// candidate roles. Score and resource type still use opposite registers.
// 30: Recovered the original moving byte cursor with direct typed record
//   accesses. This restored ESI/EDI roles, the +008B cursor setup, and most
//   loop blocks. An exclusion pointer and bool flag improved the structural
//   basin. A named farm object ID restored the farm scan memory compare.
//   Best check: 1131/1130 bytes, 97.90% shape, 85.84% exact blocks, diff 606.
//   All 16 direct calls remain aligned. The remaining broad residue swaps
//   EBX score with EBP resource type and starts in the exclusion scan.
// UNRESOLVED: current source is natural but does not match the original
//   dword exclusion flag or the original EBX/EBP register roles.
// 31: Fresh exact-finish validation restored the pinned source at 1131/1130
// bytes, diff 606, with all 16 ordered calls aligned. A positive nested
// exclusion body reached diff 542 and exact size, but changed block shape and
// did not match the original CMP flag form. Guarded exclusion, dword flags,
// ID aliases, register hints, and resource-index copies regressed or emitted
// duplicate code. Keep the pinned source authoritative.
// UNRESOLVED: the exclusion scan still selects BL for its flag and EBP for the
// resource type, while the executable uses EBP and EBX. The first hunk is
// taiinfmd.cpp:1245-1251 and preserves the direct object reread after it.
// 32: Fresh natural probes of positive score/exclusion guards, scoped and
// reordered score locals, early resource-index aliases, register hints, and
// exclusion ID locals did not improve the pinned basin. Positive exclusion
// nesting reached diff 542 at exact size, but it changed the original block
// topology. The clean source is restored. The executable still proves the
// EBP exclusion flag, EBX resource index, direct object reread, and ordered
// special-filter calls.

#include <math.h>
#include <stdlib.h>
#include <string.h>
#ifndef TAIINFMD_PREFIX_CONTEXT
#define TAIINFMD_INFO_CONTEXT "../../include/information_dropsites_context.h"
#include TAIINFMD_INFO_CONTEXT
#undef TAIINFMD_INFO_CONTEXT
#endif

extern double __cdecl floor(double);
extern float DAT_00575568;

int TribeInformationAIModule::gameIDOfResourceObject(int resType, int gathererId, float& outX, float& outY, int& outResourceId, int* exclude, int excludeCount)
{
    unsigned char zone;
    int gx;
    int gy;
    int boat;
    int score;
    int bestObject;
    ResourceMemory* bestValue;
    int fishingBoat;
    int needUpdateDropsite;
    int i;
    bool excluded;
    int j;
    int* excludePtr;
    int objectId;
    RGE_Static_Object* obj;
    int dx;
    int dy;
    short cls3;
    short cls;
    short cls2;
    int k;
    RGE_Static_Object* gatherer;

    outResourceId = -1;
    gatherer = this->md->object(gathererId);
    if (gatherer) {

    zone = gatherer->currentZone();
    gx = (int)gatherer->x;
    gy = (int)gatherer->y;
    boat = this->isBoat(gatherer);

    fishingBoat = -1;
    bestValue = 0;
    needUpdateDropsite = 0;

    i = 0;
    if (this->numResources[resType] > 0) {
        bestObject = 0;
        do {
            if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone == 1) goto next;
            if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->valid != 0) {
                if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone != 0) goto next;
                --((ResourceMemory*)((char*)this->resources[resType] + bestObject))->valid;
                goto next;
            }
            excluded = 0;
            excludePtr = exclude;
            for (j = 0; j < excludeCount; ++j, ++excludePtr) {
                if (*excludePtr == ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id) { excluded = 1; break; }
            }
            if (excluded == 1) goto next;
            obj = this->md->object(((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id);
            if (!obj) {
                ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gone = 1;
                if (this->dropsiteIds[resType] == ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->id) needUpdateDropsite = 1;
                goto next;
            }
            if (boat == 1) {
                cls = obj->master_obj->object_group;
                if (cls != 5 && cls != 0x1f && cls != 0x21) goto next;
            }
            if (boat == 0) {
                cls2 = obj->master_obj->object_group;
                if (cls2 == 5 || cls2 == 0x1f || cls2 == 0x21) goto next;
            }
            dx = gx - ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->x;
            dy = gy - ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->y;
            score = dx * dx + dy * dy + ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherValue * 10;
            if (obj->master_obj->id == 0x3b) {
                if (((ResourceMemory*)((char*)this->resources[resType] + bestObject))->dropDistance > 0x14) goto next;
                score += ((int)((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherAttempts) / 150;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 2) score += 200;
            } else {
                score += ((int)((ResourceMemory*)((char*)this->resources[resType] + bestObject))->gatherAttempts) / 50;
            }
            if (bestValue && score >= fishingBoat) goto next;
            cls3 = obj->master_obj->object_group;
            if ((cls3 == 9 || cls3 == 10) && obj->state > 2 && obj->amount > DAT_00575568) score += 25;
            if (this->withinXTilesOfEnemyTowncenter(obj, 25) == 1) goto next;
            if (this->withinXTilesOfAttackOnPlayer(obj, 15, this->md->player->civ_id) == 1) score += 500;
            if (obj->master_obj->id == 0x32) {
                if (obj->player->civ_id != this->md->player->civ_id) goto next;
                if (obj->state != 2) goto next;
                if (this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
                objectId = obj->id;
                k = 0;
                while (k < this->farmsTaskedThisUpdate.numberValue) {
                    if (k >= this->farmsTaskedThisUpdate.maximumSizeValue) break;
                    if (this->farmsTaskedThisUpdate[k] == objectId) goto next;
                    ++k;
                }
            }
            if (resType == 1 && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 0) goto next;
            if ((resType == 3 || resType == 2) && this->md->tacticalAI.numberGatherersWithTarget(obj->id) > 3) goto next;
            if (obj->master_obj->id == 0x30 && obj->state == 2) {
                int want = this->md->tacticalAI.strategicNumber(0xcc);
                if (this->md->tacticalAI.actualGathererCountByRealResourceID(0) < want) goto next;
            }
            if (gatherer->lookupZone(((ResourceMemory*)((char*)this->resources[resType] + bestObject))->x,
                                     ((ResourceMemory*)((char*)this->resources[resType] + bestObject))->y) != zone) goto next;
            if (bestValue && score >= fishingBoat) goto next;
            bestValue = (ResourceMemory*)((char*)this->resources[resType] + bestObject);
            fishingBoat = score;
            outX = obj->x;
            outY = obj->y;
next:
            ++i;
            bestObject += 20;
        } while (i < this->numResources[resType]);
    }

        if (needUpdateDropsite == 1) this->updateResourceDropsites(resType);
        if (bestValue) {
            bestValue->gatherAttempts++;
            outResourceId = bestValue->dropsiteID;
            return bestValue->id;
        }
    }
    return -1;
}
