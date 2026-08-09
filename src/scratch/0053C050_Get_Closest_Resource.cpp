// vis_unit.cpp target: Visible_Resource_Manager::Get_Closest_Resource
// initial natural reconstruction from packet/decompiler; scans one resource list for closest non-rejected record.
// Attempt log:
// - Baseline has exact size/frame and both __ftol calls, but VC5 keeps this in ECX through the guards instead of the original ESI save.
// - Split versus combined guards and direct versus manager-alias spelling did not change the prologue basin.
// - Replaced guessed distance constants with the binary-proven DAT_005776D0/DAT_005776D8 double globals; fmul/fsubr sites and several body blocks moved closer.
// - Named used/list array pointers and register-qualified manager were diagnostic only; both worsened or duplicated codegen, so the clean typed direct-member form is retained.
// Left in scratch: remaining drift is early this/index scheduling plus loop register/block coloring; behavior, size/frame, and call set are established.

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
        int count = this->VR_ListUsed[type];
        if (count != 0) {
            VisibleResourceRec* rec = this->VR_List[type];
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
                            int i = 0;
                            if (reject_count > 0) {
                                do {
                                    if (rec->object_id == *reject_list) {
                                        rejected = 1;
                                        break;
                                    }
                                    i++;
                                    reject_list++;
                                } while (i < reject_count);
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
