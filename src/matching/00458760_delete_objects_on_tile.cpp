// 00458760 RGE_Map::delete_objects_on_tile(RGE_Player*, RGE_Game_World*, int, int, int, int)
// Source: map.cpp lines 1947-1964
// Size: 110 bytes, 46 asm lines
// Attempt 8: use separate `next` local to force separate registers for p and next

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    char _gap_00[0x10];
    short id;
};

class RGE_Object_Node {
public:
    class RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    RGE_Master_Static_Object* master_obj;
    class RGE_Player* owner;
};

struct RGE_Tile {
    short screen_xpos;       // +0
    short screen_ypos;       // +2
    unsigned char fields[8];  // +4 to +11
    char _pad[4];             // +12 to +15
    RGE_Object_Node* objects_list;  // +0x10
    char _pad2[4];            // +0x14 to +0x17 (sizeof=24)
};

struct StaticObject_VTableHelper {
    virtual void release(int x);
};

class RGE_Map {
public:
    char _gap_00[8];
    int map_width;       // +8
    int map_height;      // +0xC
    char _gap_10[0x8D7C];
    RGE_Tile** map_row_offset;  // +0x8D8C

    void delete_objects_on_tile(class RGE_Player* player, class RGE_Game_World* world, int x, int y, int min_id, int max_id);
};

void RGE_Map::delete_objects_on_tile(RGE_Player* player, RGE_Game_World* /*world*/, int x, int y, int min_id, int max_id)
{
    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node* p = this->map_row_offset[y][x].objects_list;
    if (p == 0)
        return;

    while (p != 0) {
        RGE_Static_Object* obj = p->node;
        RGE_Object_Node* next = p->next;

        int obj_id = obj->master_obj->id;
        if (obj->owner == player) {
            if (obj_id < min_id || obj_id > max_id) {
                if (obj != 0) {
                    ((StaticObject_VTableHelper*)obj)->release(1);
                }
            }
        }

        p = next;
    }
}
