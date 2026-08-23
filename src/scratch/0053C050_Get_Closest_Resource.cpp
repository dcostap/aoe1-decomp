// vis_unit.cpp target: Visible_Resource_Manager::Get_Closest_Resource
// initial natural reconstruction from packet/decompiler; scans one resource list for closest non-rejected record.
// Attempt log:
// - Baseline has exact size/frame and both __ftol calls, but VC5 keeps this in ECX through the guards instead of the original ESI save.
// - Split versus combined guards and direct versus manager-alias spelling did not change the prologue basin.
// - Replaced guessed distance constants with the binary-proven DAT_005776D0/DAT_005776D8 double globals; fmul/fsubr sites and several body blocks moved closer.
// - Named used/list array pointers and register-qualified manager were diagnostic only; both worsened or duplicated codegen, so the clean typed direct-member form is retained.
// - A top-tested reject-list while loop plus a branch-local cursor recovered the
//   original single compare/backedge topology, stack homes, and persistent
//   reject_count register; mutating the incoming reject_list did not.
// - Explicit typed used/resource-list locals recovered the original list-before-
//   used load order and improved the localized diff to 321 bytes; a register hint
//   on the list pointer was unchanged and was removed from the living source.
// - Retry session: an explicit manager pointer, same-TU RGE_Static_Object context,
//   and the canonical RGE_Player owner type were codegen duplicates.
// - A diagnostic pointer-typed alias for VR_ListUsed preserved the index LEA and
//   raised shape coverage to 96%, but worsened positional diff by 5 bytes and did
//   not restore the original early ESI=this save; it was rolled back as opaque.
// - Member-slot, volatile-manager, function-scope-local, and delayed-count variants
//   likewise did not move the receiver-save basin; all were restored.
// - Direct member indexing worsened the positional diff by 6 bytes and emitted
//   a shifted count/list block; a named VR_ListUsed element pointer duplicated
//   that result. Both natural typed probes were restored.
// - This pass tested the packet's pointer/index reject-loop coloring with the
//   natural indexed form `reject_list[i]`; it preserved the exact inner loop
//   register/CFG topology and improved edit similarity, but positional bytes
//   stayed at 321. It is retained as the cleanest source spelling.
// - Reusing the incoming type parameter for the distance bound emitted the
//   same 321-byte code and was rolled back. Three explicit early returns grew
//   the function by 12 bytes and were also rolled back.
// - Taking explicit addresses of the used/list elements emitted a duplicate
//   327-byte result and was rolled back.
// - Follow-up probes for a named type offset, direct or delayed member access,
//   pointer-entry locals, reversed array-base declarations, and a function-scope
//   record cursor were unchanged or six bytes worse; all were rolled back.
// - Void-list casts, top-level self aliases, result rebinding after the clamp,
//   and swapped best/bestDistance declarations were duplicate or less natural;
//   none moved the early receiver-save basin.
// - This pass tested a typed-array byte offset in both direct and split local
//   forms; the direct form was 327 bytes different and the split form was a
//   codegen duplicate, so both were restored.
// - Replaced the unused owner void pointer with the canonical RGE_Player*
//   field type. This is codegen-identical and preserves the reviewed ownership.
// - Hoisting best initialization to the count-guard scope improves the current
//   result to 317 differing bytes, 90.24% shape, and 80.51% exact blocks.
//   Other natural alias and offset forms were worse or codegen duplicates.
// - Replaced the guarded do/while resource scan with one top-tested
//   `while (count > 0)` loop. Delaying best initialization until after the
//   record load preserves the natural store order and improves the result to
//   308 differing bytes, 96.64% shape, 82.20% exact blocks, and 32 edit bytes.
//   Direct count-before-list variants preserve the blocker fault order but are
//   323-326 bytes different; they do not improve the current codegen basin.
//   Receiver aliases and reversed array declarations are codegen duplicates.
// - Specialist follow-up restored the pinned source after direct member-order,
//   manager-alias, address-taken slot, and function-scope cursor probes. These
//   forms stayed in the same 326-byte basin or duplicated the 308-byte clean
//   result; none recovered the original ESI receiver save.
// - The reviewed player context cannot be included in this isolated owner: it
//   defines Visible_Resource_Manager and causes a type redefinition. No context
//   edit was retained. Fresh grouped view anchors, including 0053DBA0, remain
//   exact and were not changed by this pass.
// Left in scratch: remaining drift is the early receiver-save/index LEA basin
//   and associated register coloring; behavior, size/frame, calls, and inner
//   reject-loop CFG are established. The current source uses the stronger
//   top-tested scan shape but retains the member-read-order blocker below.
// BLOCKER: the executable reads VR_ListUsed[type] and rejects a zero count
// before it reads VR_List. The rebuild reads VR_List first. An empty list thus
// adds a member read, and the nonempty path changes member-read and fault order.
// Keep the typed resource scan in scratch.

#include <stdlib.h>
#include <string.h>

struct VisibleResourceRec {
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

extern double DAT_005776D0;
extern double DAT_005776D8;

class RGE_Player;

class Visible_Resource_Manager {
public:
    VisibleResourceRec** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;

    VisibleResourceRec* Get_Closest_Resource(int x, int y, int param3, int type, int* reject_list, int reject_count);
};

VisibleResourceRec* Visible_Resource_Manager::Get_Closest_Resource(int x, int y, int param3, int type, int* reject_list, int reject_count) {
    if (type >= 0 && this->num_visible_resource_lists != 0 && type < this->num_visible_resource_lists) {
        VisibleResourceRec** resourceLists = this->VR_List;
        int* usedLists = this->VR_ListUsed;
        int count = usedLists[type];
        VisibleResourceRec* best;
        if (count != 0) {
            VisibleResourceRec* rec = resourceLists[type];
            int bestDistance = 9999;
            best = 0;
            while (count > 0) {
                int dx;
                int dy;
                int rejected = 0;
                int rx = rec->pos_x;
                int ry = rec->pos_y;
                if (rx > x) {
                    dx = rx - x;
                } else {
                    dx = x - rx;
                }
                if (ry > y) {
                    dy = ry - y;
                } else {
                    dy = y - ry;
                }
                int dist;
                if (dx > dy) {
                    dist = (dx - (int)(DAT_005776D8 - dy * DAT_005776D0)) - dy;
                } else {
                    dist = (dy - (int)(DAT_005776D8 - dx * DAT_005776D0)) - dx;
                }
                if (dist < bestDistance) {
                    if (reject_count && reject_list) {
                        int i = 0;
                        while (i < reject_count) {
                            if (rec->object_id == reject_list[i]) {
                                rejected = 1;
                                break;
                            }
                            i++;
                        }
                    }
                    if (!rejected) {
                        best = rec;
                        bestDistance = dist;
                    }
                }
                rec++;
                count--;
            }
            if (bestDistance > 0xff) {
                bestDistance = 0xff;
            }
            if (best != 0) {
                best->distance = (unsigned char)bestDistance;
            }
            return best;
        }
    }
    return 0;
}
