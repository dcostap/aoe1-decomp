// vis_unit.cpp target: Visible_Resource_Manager::Get_Closest_Resource
// initial natural reconstruction from packet/decompiler; scans one resource list for closest non-rejected record.

struct VisibleResourceRec {
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

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
    Visible_Resource_Manager* mgr = this;
    if (type >= 0 && mgr->num_visible_resource_lists != 0 && type < mgr->num_visible_resource_lists) {
        int count = mgr->VR_ListUsed[type];
        if (count != 0) {
            VisibleResourceRec* rec = mgr->VR_List[type];
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
                        dist = (dx - (int)(dy * 0.4142135623730951 + 0.5)) - dy;
                    } else {
                        dist = (dy - (int)(dx * 0.4142135623730951 + 0.5)) - dx;
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
