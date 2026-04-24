// check_objects: 004CE7A0, tact_dar.cpp:125-165
// Nested loop over tile grid, iterates objects at each tile, checks flags and calls virtual method
//
// tried initial draft; 384 vs 386 - 2 bytes short, stack 32 vs 28, field offsets off by 4
// tried adjusting DiscoveryMaster gap; function got smaller (368)
// reverted to 384-byte version; remaining gap is VC5 codegen basin difference

extern float DAT_00575078;
extern float DAT_0057507c;

struct DiscoverySizeInfo {
    char gap_00[0x28];
    void* map_data_base;
    char gap_34[0x10];
    float field_38;
    float field_3c;
    char gap_40[0x898];
    void* map_data;
};

struct DiscoveryInfo {
    char gap_00[0x08];
    void* size_info;
    short tile_count_x;
    short tile_count_y;
    void* object_lists;
};

struct DiscoveryMaster {
    char gap_00[0x08];
    DiscoveryInfo* info;
    char gap_0C[0x28];
    float centerX;
    float centerY;
};

struct RGE_Object_Info {
    char gap_00[0x0C];
    void* field_0c;
    short field_4a;
    char gap_4c[0x234];
    void* field_288;
};

struct RGE_Map_Object_Dispatch {
    void* vftable;
    char gap_04[0x14];
    void (*discover)(void* info, float x, float y, void* p3);
};

struct RGE_Map_Object {
    RGE_Object_Info* info;
    char gap_08[0x30];
    float x;
    float y;
    void* field_40;
};

struct RGE_Map_Tile_Data {
    char gap_00[0x10];
    void* object_list;
};

class RGE_Action {
public:
    virtual void vf00(void);
    char gap_04[0x04];
    void* object;
    char gap_0C[0x34];
    char* flags;
};

class TRIBE_Action_Discovery_Artifact : public RGE_Action {
public:
    void check_objects();
};

void TRIBE_Action_Discovery_Artifact::check_objects() {
    DiscoveryMaster* master = (DiscoveryMaster*)this->object;
    DiscoveryInfo* info = master->info;
    DiscoverySizeInfo* size_info = (DiscoverySizeInfo*)info->size_info;

    short x1 = (short)(master->centerX - DAT_00575078 - size_info->field_38);
    short y1 = (short)(master->centerY - DAT_00575078 - size_info->field_3c);
    short x2 = (short)(size_info->field_38 + master->centerX - DAT_0057507c);
    short y2 = (short)(size_info->field_3c + master->centerY - DAT_0057507c);

    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= (short)info->tile_count_x) x2 = info->tile_count_x - 1;
    if (y2 >= (short)info->tile_count_y) y2 = info->tile_count_y - 1;

    for (short y = y1; y <= y2; y++) {
        for (short x = x1; x <= x2; x++) {
            RGE_Map_Tile_Data* tile_data = (RGE_Map_Tile_Data*)((void**)size_info->map_data)[(y - y1) * 4 / 4 + (x - x1)];
            void* obj_node = tile_data->object_list;

            while (obj_node) {
                RGE_Map_Object* obj = *(RGE_Map_Object**)obj_node;
                RGE_Object_Info* obj_info = obj->info;

                if (obj_info->field_0c != info) {
                    char* flag_ptr = this->flags + obj_info->field_4a;
                    if (*flag_ptr == 0) {
                        *flag_ptr = 1;

                        RGE_Map_Object_Dispatch* dispatch =
                            (RGE_Map_Object_Dispatch*)obj_info->field_288;
                        dispatch->discover(obj_info, obj->x, obj->y, obj->field_40);
                    }
                }
                obj_node = *(void**)((char*)obj_node + 4);
            }
        }
    }
}
