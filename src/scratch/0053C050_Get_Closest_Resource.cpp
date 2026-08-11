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
// Left in scratch: remaining drift is the early receiver-save/index LEA basin
//   and associated register coloring; behavior, size/frame, calls, and inner
//   reject-loop CFG are established.

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

class Visible_Resource_Manager {
public:
    VisibleResourceRec** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    void* owner;
    int num_visible_resource_lists;

    VisibleResourceRec* Get_Closest_Resource(int x, int y, int param3, int type, int* reject_list, int reject_count);
};

VisibleResourceRec* Visible_Resource_Manager::Get_Closest_Resource(int x, int y, int param3, int type, int* reject_list, int reject_count) {
    if (type >= 0 && this->num_visible_resource_lists != 0 && type < this->num_visible_resource_lists) {
        int* usedLists = this->VR_ListUsed;
        VisibleResourceRec** resourceLists = this->VR_List;
        int count = usedLists[type];
        if (count != 0) {
            VisibleResourceRec* rec = resourceLists[type];
            int bestDistance = 9999;
            VisibleResourceRec* best = 0;
            if (count > 0) {
                do {
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
                            int* reject_cursor = reject_list;
                            int i = 0;
                            while (i < reject_count) {
                                if (rec->object_id == *reject_cursor) {
                                    rejected = 1;
                                    break;
                                }
                                i++;
                                reject_cursor++;
                            }
                        }
                        if (!rejected) {
                            best = rec;
                            bestDistance = dist;
                        }
                    }
                    rec++;
                    count--;
                } while (count != 0);
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
