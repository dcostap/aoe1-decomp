// 00545C00 RGE_Game_World::objectGroupOnTile(int, int, int, int, int&)
// PDB: World.cpp lines 3512-3536; owning range 00545C00-00545CA5.
// Retry 2026-05-20: exact match found. Positive nested bounds plus a natural
// `while (node != 0)` walk keeps the bad-bounds tail and not-found tail in the
// original order and preserves the compact bottom `jne` node-loop backedge.
// BINARY NOTE: The PDB-qualified output parameter is an int reference. The
// preceding World anchor at 00545BF0 owns the separate unsigned-long +0xF8
// time field; do not merge that anchor or assign this body to another class.
// Direct map reads, output publication, and failure order remain explicit.

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

    int objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int& output);
};

int RGE_Game_World::objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int& output)
{
    if (tile_x >= 0) {
        if (tile_y >= 0) {
            RGE_Map* m = this->map;
            if (tile_x < m->map_width) {
                if (tile_y < m->map_height) {
                    char* row = m->row_data[tile_y];
                    output = *(short*)(row + tile_x * 0x18 + 0x14);

                    char* row2 = this->map->row_data[tile_y];
                    RGE_Object_Node* node = *(RGE_Object_Node**)(row2 + tile_x * 0x18 + 0x10);
                    if (node != 0) {
                        while (node != 0) {
                            RGE_Static_Object* obj = (RGE_Static_Object*)node->object;
                            if (obj == 0)
                                break;
                            if (owner_id == -1 || obj->owner_info->id == owner_id) {
                                if (obj->master_obj->object_group == object_group)
                                    return obj->id;
                            }
                            node = node->next;
                        }
                    }
                    return -1;
                }
            }
        }
    }

    output = 0;
    return -1;
}
