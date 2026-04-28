// 00545C00 RGE_Game_World::objectGroupOnTile
// Source: World.cpp lines 3512-3536
// Attempt log:
// initial: 77% diff — VC5 clobbered ECX (this) with this->map.
// two-path tile access (m vs this->map): map in ESI, this preserved in ECX, 88% match.
// proper struct types: loop body matches (owner->id, master_obj->object_group, node walk).
// FLAGS: none
// Left in scratch: remaining diff is branch encoding (short jl vs near jl) in bounds
// checks and error path layout. Tile access, linked list walk, and return paths match.
// 147/166 equal bytes, 26 edit bytes.

struct RGE_Object_Node {
    void* object;            // +0x00
    RGE_Object_Node* next;   // +0x04
};

struct MasterObj {
    char gap_00[0x14];
    short object_group;      // +0x14
};

struct OwnerInfo {
    char gap_00[0x4A];
    short id;                // +0x4A
};

struct RGE_Static_Object {
    char gap_00[0x04];
    int id;                  // +0x04
    MasterObj* master_obj;   // +0x08
    OwnerInfo* owner_info;   // +0x0C
};

struct RGE_Map {
    char gap_00[0x08];
    int map_width;           // +0x08
    int map_height;          // +0x0C
    char gap_10[0x8D7C];
    char** row_data;         // +0x8D8C
};

struct RGE_Game_World {
    char gap_00[0x28];
    RGE_Map* map;            // +0x28

    int objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int* output);
};

int RGE_Game_World::objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int* output)
{
    if (tile_x < 0 || tile_y < 0) {
        *output = 0;
        return -1;
    }

    RGE_Map* m = this->map;
    if (tile_x >= m->map_width || tile_y >= m->map_height) {
        *output = 0;
        return -1;
    }

    // Path 1: write count via cached map
    char* row_base = m->row_data[tile_y];
    *output = *(short*)(row_base + tile_x * 0x18 + 0x14);

    // Path 2: get list head via this->map (forces fresh read)
    char* row_base2 = this->map->row_data[tile_y];
    RGE_Object_Node* node = *(RGE_Object_Node**)(row_base2 + tile_x * 0x18 + 0x10);

    if (node == 0)
        return -1;

    while (1) {
        RGE_Static_Object* obj = (RGE_Static_Object*)node->object;
        if (obj == 0)
            return -1;

        if ((owner_id == -1 || obj->owner_info->id == owner_id) &&
            obj->master_obj->object_group == object_group) {
            return obj->id;
        }

        node = node->next;
        if (node == 0)
            return -1;
    }
}
