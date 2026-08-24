// vis_unit.cpp target: Visible_Resource_Manager::AddResource
// appends a visible resource record, growing per-type storage when used == size.
// Attempt log:
// - Baseline manual byte-copy source was 14 bytes short, had no local frame, and
//   used operator_delete instead of the binary's free call.
// - Switched to memcpy, cdecl free, and one doubled-size local. Size, frame,
//   calls, and every growth-path block became exact.
// - The canonical typed growth and append source is retained.
// - Main-agent audit restored the canonical polymorphic static-object surface;
//   emitted code and the eight-byte residual are unchanged.
// - The period CRT header context and typed resource record are retained.
// - Restoring the period CRT header context with <stdlib.h> and <string.h>
//   changed only that localized append schedule and recovered an exact match.

#include <stdlib.h>
#include <string.h>

#if !defined(VIS_UNIT_TU_CONTEXT)
struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float x;
    float y;
};

struct VisibleResourceRec {
    int object_id;
    unsigned char distance;
    unsigned char zone;
    unsigned char pos_x;
    unsigned char pos_y;
};

extern RGE_Static_Object** VIS_UNIT_objectsValue;

class Visible_Resource_Manager {
public:
    VisibleResourceRec** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    void* owner;
    int num_visible_resource_lists;

    void AddResource(int object_id, int type);
};
#endif

void Visible_Resource_Manager::AddResource(int object_id, int type) {
    RGE_Static_Object* object;
    int n;
    if (this->num_visible_resource_lists != 0) {
        object = VIS_UNIT_objectsValue[object_id];
        if (object != 0) {
            n = this->VR_ListSize[type];
            if (this->VR_ListUsed[type] == n) {
                n = n + n;
                VisibleResourceRec* new_list = (VisibleResourceRec*)malloc(n * 8);
                memcpy(new_list, this->VR_List[type], this->VR_ListSize[type] << 3);
                free(this->VR_List[type]);
                this->VR_List[type] = new_list;
                this->VR_ListSize[type] = n;
            }

            VisibleResourceRec* rec = this->VR_List[type] + this->VR_ListUsed[type];
            int x = object->x;
            int y = object->y;
            rec->object_id = object_id;
            rec->distance = 0;
            rec->zone = 0;
            rec->pos_x = (unsigned char)x;
            rec->pos_y = (unsigned char)y;
            this->VR_ListUsed[type]++;
        }
    }
}
