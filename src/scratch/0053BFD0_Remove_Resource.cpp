// vis_unit.cpp target: Visible_Resource_Manager::Remove_Resource
// removes an object id from a resource-type list by replacing it with the last used entry.
// tried explicit byte-offset arithmetic; it worsened register choice and block layout, so reverted to natural list/record source.
// remaining mismatch: VC5 shares the not-found epilogue and uses ebp for the type offset instead of original ebx.
// trying an explicit saved object_id local and offset local to bias object id into ebp and offset into ebx.

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

    int Remove_Resource(int object_id, int type);
};

int Visible_Resource_Manager::Remove_Resource(int object_id, int type) {
    if (this->num_visible_resource_lists != 0) {
        int last = this->VR_ListUsed[type];
        if (last != 0) {
            last--;
            VisibleResourceRec* list = this->VR_List[type];
            int i = 0;
            if (last >= 0) {
                int wanted = object_id;
                VisibleResourceRec* rec = list;
                for (;;) {
                    if (rec->object_id == wanted) {
                        if (i < last) {
                            list[i] = list[last];
                        }
                        this->VR_ListUsed[type]--;
                        return 1;
                    }
                    i++;
                    rec++;
                    if (i > last) {
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
