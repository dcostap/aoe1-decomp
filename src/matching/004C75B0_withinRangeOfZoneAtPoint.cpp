// 004C75B0 RGE_Static_Object::withinRangeOfZoneAtPoint(uchar, float, XYPoint&)
// Source: stat_obj.cpp lines 4725-4737
// Size: 114 bytes, 40 asm lines
// Attempt 2: proper struct layout with gap, class methods for thiscall

#include "..\..\include\game_globals.h"

struct XYPoint {
    int x;
    int y;
};

class RGE_Zone_Map_List {
public:
    class RGE_Zone_Map* get_zone_map(int terrain_idx, int terrain_val, int* out_idx);
    class RGE_Zone_Map* get_zone_map(int index);
};

class RGE_Zone_Map {
public:
    int withinRange(unsigned char param_1, int x, int y, float param_2);
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    void* master_obj;
    void* owner;
    char _gap_10[0x6C];  // padding from +0x10 to +0x7C
    int zoneMapIndex;    // +0x7C

    int withinRangeOfZoneAtPoint(unsigned char param_1, float param_2, void* param_3);
};

int RGE_Static_Object::withinRangeOfZoneAtPoint(unsigned char param_1, float param_2, void* param_3) {
    RGE_Zone_Map* zone_map;

    if (this->zoneMapIndex == -1) {
        void* owner_field = *(void**)((char*)this->owner + 0x3C);
        void* world_field = *(void**)((char*)owner_field + 0x28);
        RGE_Zone_Map_List* zone_list = *(RGE_Zone_Map_List**)((char*)world_field + 0x8DC4);
        void* terrain_array = *(void**)((char*)owner_field + 0x54);
        int terrain_value = (short)(*(short*)((char*)owner_field + 0x52));
        int terrain_type = (short)(*(short*)((char*)this->master_obj + 0x66));
        int terrain_index = *(int*)((char*)terrain_array + terrain_type * 4);
        zone_map = zone_list->get_zone_map(terrain_index, terrain_value, &this->zoneMapIndex);
    } else {
        void* owner_field = *(void**)((char*)this->owner + 0x3C);
        void* world_field = *(void**)((char*)owner_field + 0x28);
        RGE_Zone_Map_List* zone_list = *(RGE_Zone_Map_List**)((char*)world_field + 0x8DC4);
        zone_map = zone_list->get_zone_map(this->zoneMapIndex);
    }

    if (zone_map != 0) {
        XYPoint* pt = (XYPoint*)param_3;
        return zone_map->withinRange(param_1, pt->x, pt->y, param_2);
    }
    return 0;
}
