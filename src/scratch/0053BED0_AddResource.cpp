// vis_unit.cpp target: Visible_Resource_Manager::AddResource
// appends a visible resource record, growing per-type storage when used == size.
// probing function-scope saved object/new_size locals to induce original sub esp,8 local frame.

extern "C" void* __cdecl malloc(unsigned int size);
void operator_delete(void* ptr);

struct RGE_Static_Object {
    char gap_00[0x38];
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

void Visible_Resource_Manager::AddResource(int object_id, int type) {
    RGE_Static_Object* object;
    int new_size;
    if (this->num_visible_resource_lists != 0) {
        object = VIS_UNIT_objectsValue[object_id];
        if (object != 0) {
            int size = this->VR_ListSize[type];
            if (this->VR_ListUsed[type] == size) {
                new_size = size + size;
                VisibleResourceRec* new_list = (VisibleResourceRec*)malloc(new_size * 8);
                int bytes = this->VR_ListSize[type] << 3;
                char* dst = (char*)new_list;
                char* src = (char*)this->VR_List[type];
                while (bytes-- != 0) {
                    *dst++ = *src++;
                }
                operator_delete(this->VR_List[type]);
                this->VR_List[type] = new_list;
                this->VR_ListSize[type] = new_size;
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
