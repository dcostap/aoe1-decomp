// vis_unit.cpp target: Visible_Resource_Manager::Remove_Resource
// left in scratch: behavior modeled, but VC5 allocates type offset to EBP and object id to EBX;
// original uses EBX for type*4 offset and loads object_id into EBP after last>=0 gate.
// tried explicit byte offset, while vs do-while, direct object_id, wanted local, and typeLocal; no match.

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
                do {
                    if (rec->object_id == wanted) {
                        if (i < last) {
                            list[i] = list[last];
                        }
                        int typeLocal = type;
                        this->VR_ListUsed[typeLocal]--;
                        return 1;
                    }
                    i++;
                    rec++;
                } while (i <= last);
                return 0;
            }
        }
    }
    return 0;
}
