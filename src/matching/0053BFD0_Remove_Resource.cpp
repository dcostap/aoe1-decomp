// vis_unit.cpp target: Visible_Resource_Manager::Remove_Resource
// VA: 0053BFD0
//
// Attempt log:
// - Initial scratch modeled behavior with a pointer-walking do/while and wanted/type locals. VC5 allocated type
//   offset to EBP and object id to EBX, duplicated the first compare, and produced shifted failure tails.
// - SpruceGlow try 1: explicit byte offset local was still worse (edit diff 29).
// - SpruceGlow try 2 MATCH: use a simple indexed `for (int i = 0; i <= last; i++)` and direct `list[i]` access.
//   VC5 naturally keeps type*4 in EBX, loads object_id into EBP after the last>=0 gate, and emits the exact
//   last-record copy plus used-count decrement sequence.
// Result: MATCH locally with `python tools/check_function.py --va 0053BFD0`.

#if !defined(VIS_UNIT_TU_CONTEXT)
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
#endif

int Visible_Resource_Manager::Remove_Resource(int object_id, int type) {
    if (this->num_visible_resource_lists == 0) {
        return 0;
    }

    int last = this->VR_ListUsed[type];
    if (last == 0) {
        return 0;
    }

    --last;
    VisibleResourceRec* list = this->VR_List[type];

    for (int i = 0; i <= last; i++) {
        if (list[i].object_id == object_id) {
            if (i < last) {
                list[i] = list[last];
            }
            this->VR_ListUsed[type]--;
            return 1;
        }
    }

    return 0;
}
