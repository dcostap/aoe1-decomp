// 00458760 RGE_Map::delete_objects_on_tile
// Source: map.cpp lines 1947-1964
// public: void __thiscall RGE_Map::delete_objects_on_tile(RGE_Player*,RGE_Game_World*,int,int,int,int)
//
// Attempt log:
// Probe 1: basic linked-list walk — wrong tile size (RGE_Object_Node declared after RGE_Tile use)
// Probe 2: fixed order — tile still 20 bytes not 24 (RGE_Object_List struct needed)
// Probe 3: full RGE_Tile with RGE_Object_List (24 bytes) — tile index correct, but param loading differs
// Probe 4: pre-loaded master_obj/id before owner check — register allocation still differs
//   Remaining gap: VC5 makes different register choices (eax->esi, swapped min/max regs),
//   owner loaded as `mov edx,[mem]; cmp edx,reg` instead of `cmp [mem],reg`,
//   virtual call has `add esp,4` cleanup (stdcall-like) vs original naked `call [eax]` (thiscall).
//   Logic and tile access are correct; this is register-allocation drift in VC5.

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    char _gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    void* vtable;
    int id;
    RGE_Master_Static_Object* master_obj;
    void* owner;
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

struct RGE_Object_List {
    void* vtable;
    RGE_Object_Node* list;
    short number_of_objects;
    char _pad[2];
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    RGE_Object_List objects;
};

class RGE_Map {
public:
    char _gap_00[8];
    int map_width;
    int map_height;
    char _gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void delete_objects_on_tile(void* player, void* world, int x, int y, int min_id, int max_id);
};

void RGE_Map::delete_objects_on_tile(void* player, void* world, int x, int y, int min_id, int max_id)
{
    if (x < 0 || x >= this->map_width || y < 0 || y >= this->map_height)
        return;

    RGE_Object_Node* p = this->map_row_offset[y][x].objects.list;
    if (p == 0)
        return;

    void* pPlayer = player;
    int lo = min_id;
    int hi = max_id;

    while (p != 0) {
        RGE_Static_Object* obj = p->node;
        p = p->next;

        short obj_id = obj->master_obj->id;
        if (obj->owner == pPlayer) {
            if (obj_id < lo || obj_id > hi) {
                if (obj != 0) {
                    (*(void (**)(int))obj->vtable)(1);
                }
            }
        }
    }
}
