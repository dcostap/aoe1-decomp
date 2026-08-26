// 00545C00 RGE_Game_World::objectGroupOnTile(int, int, int, int, int&)
#include "../world_phase2_context.h"
// PDB: World.cpp lines 3512-3536; owning range 00545C00-00545CA5.
// Retry 2026-05-20: the natural body remains exact only with the reviewed map
// row-data offset. The current phase2 header places row_data at +0x8DC4, while
// World.cpp proves +0x8D8C. This leaves a grouped 3-byte mismatch. Do not add
// a local offset view; repair the shared RGE_Map layout through the main agent.
// Positive nested bounds plus a natural `while (node != 0)` walk keeps the
// bad-bounds tail and not-found tail in the original order and preserves the
// compact bottom `jne` node-loop backedge.
// BINARY NOTE: The PDB-qualified output parameter is an int reference. The
// preceding World anchor at 00545BF0 owns the separate unsigned-long +0xF8
// time field; do not merge that anchor or assign this body to another class.
// Direct map reads, output publication, and failure order remain explicit.

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
