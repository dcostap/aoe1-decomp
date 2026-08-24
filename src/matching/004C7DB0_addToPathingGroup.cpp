// VA: 004C7DB0 addToPathingGroup (145B)
// stat_obj.cpp lines 5010-5012
// Retry 2026-05-19/20 assigned pass:
// - Replaced incorrect stub with dynamic int-array model at +0x54/+0x58/+0x60 and operator new/delete; exact size 145B but broad mismatch remains.
// - Baseline natural source: 79.3103% positional / 52.4138% edit; first mismatch +13. Original keeps count in ECX, max in EDX, reloads array into EDI each probe; rebuilt keeps count in EDX, max in EDI, uses pointer-walking first loop.
// - Tried explicit members local inside first duplicate scan: no codegen improvement; rolled back.
// - Tried j/k copy-loop spelling to mirror preincrement copy indexing: worsened edit diff/compile surface; rolled back.
// - /Ob0 flag probe: no change; removed.
// Boss retry 2026-05-19:
// - for-loop spelling of duplicate scan/copy loop greatly improved edit diff to 23B and kept exact size,
//   but inserted an extra redundant count test in scan and shifted the rest of function (76.55% positional).
// - goto-shaped scan did not help; fell back to pointer-walk/register-swapped family (78.62%).
// Kept for-loop variant as best current source. GIVEUP: behavior, offsets, allocation/copy/growth logic are understood, but remaining mismatch is register allocation plus shifted redundant-test/loop-shape drift. No accepted_drift: positional drift is broad, not localized.

#include "../../include/game_globals.h"

void* operator new(unsigned int size);
void operator delete(void* ptr);

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    char gap_00[0x54];
    int* pathingGroupMembers; // +0x54
    int pathingGroupCount;    // +0x58
    char gap_5C[4];
    int pathingGroupMax;      // +0x60

    void addToPathingGroup(int groupIndex);
};
#endif

void RGE_Static_Object::addToPathingGroup(int groupIndex)
{
    int i = 0;
    int count = this->pathingGroupCount;
    if (count > 0) {
        int max = this->pathingGroupMax;
        while (1) {
            if (i >= max)
                break;
            if (this->pathingGroupMembers[i] == groupIndex)
                return;
            i++;
            if (i < count)
                continue;
            break;
        }
    }

    if (count > this->pathingGroupMax - 1) {
        int newMax = count + 1;
        int* newMembers = (int*)operator new(newMax * 4);
        if (newMembers != 0) {
            int max = this->pathingGroupMax;
            int j = 0;
            if (max > 0) {
                for (; j < max; j++) {
                    if (j >= newMax)
                        break;
                    newMembers[j] = this->pathingGroupMembers[j];
                    max = this->pathingGroupMax;
                }
            }
            operator delete(this->pathingGroupMembers);
            this->pathingGroupMembers = newMembers;
            this->pathingGroupMax = newMax;
        }
    }

    this->pathingGroupMembers[this->pathingGroupCount] = groupIndex;
    this->pathingGroupCount++;
}
