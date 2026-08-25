// VA: 0052EAC0 TRIBE_World::check_destructables (560 B)
// PDB source: tworld.cpp
// Packet-grounded: inspect nearby master objects and notify/destruct objects
// whose bounding radii overlap the requested map coordinate.
// Attempt log:
// - Recovered typed ownership: players[short] -> master_objects,
//   RGE_Map rows of 0x18-byte RGE_Tile records, inline tile object lists, and
//   RGE_Static_Object/master radius fields.  All six oracle calls are aligned.
// - Short coordinate locals reproduce the word clamps and four __ftol calls.
//   The typed row/tile do-while preserves the natural object-list traversal.
// - A direct row index plus the known 0x18-byte tile stride is closer than a
//   cached row pointer. Raw byte cursors and parameter-home mutation are not
//   retained because policy forbids them.
// - Naming both real object radius fields before coordinate math, then using a
//   combined overlap predicate, reaches 560 B/frame 0x20 and 84.15% shape.
//   It also raises exact-block coverage to 43.43% with all six calls aligned.
// - World/map aliases and alternate radius operand directions were tested and
//   discarded when they worsened or did not change the natural code shape.
// - Canonical class-dump audit: replaced the world/object/list vfXX surfaces
//   with their reviewed names and signatures, retained TRIBE_World inheritance,
//   and used the canonical RGE_Tile/RGE_Object_Node fields.
// - Structural probes moved the row/tile calculation before the horizontal
//   gate and moved the column count into that gate.  This reduced the mismatch
//   from 530 to 306 bytes and reached the original 560-byte body size.
// - Direct master_id use, a typed stride local, a moving row cursor, widened
//   x-index locals, an explicit next pointer, and unqualified members were
//   tested.  The stride and cursor forms regressed.  The other forms were
//   neutral or are retained only when they simplify the source.
// - Current validation: 306 strict bytes differ; rebuilt instructions are
//   183 versus 175 original.  The first mismatch is the implicit-this home
//   at +0008.  All six calls remain aligned and the frame is 0x20.
// BINARY NOTE: Keep the initial players[player_id] and master_objects[master_id]
//   reads before radius, map, or coordinate work. Do not add defensive guards.
// BINARY NOTE: Advance the list node before reading object_master. Publish the
//   delete or destroy action only after the complete overlap predicate.
// Prefix TU pass: use the shared canonical world, map, tile, object-list, and
// object surfaces. The source keeps the observed fault and action order.
// Shared-context check: the 560-byte boundary, 0x20 frame, six aligned calls,
// and 306 strict-byte drift are unchanged.

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void TRIBE_World::check_destructables(short player_id, short master_id,
                                      float x, float y, unsigned char flag)
{
    RGE_Master_Static_Object* master =
        players[player_id]->master_objects[master_id];

    if (master != 0) {
        float radius_x = master->radius_x;
        float radius_y = master->radius_y;
        if (radius_x > 0.0f || radius_y > 0.0f) {
            short x_min = (short)(x - 0.5f);
            short y_min = (short)(y - 0.5f);
            short x_max = (short)(x + 0.5f);
            short y_max = (short)(y + 0.5f);
            if (x_min < 0)
                x_min = 0;
            if (x_max >= map->map_width)
                x_max = (short)(map->map_width - 1);
            if (y_min < 0)
                y_min = 0;
            if (y_max >= map->map_height)
                y_max = map->map_height - 1;

            if (y_min <= y_max) {
                int row_index = y_min;
                int row_count = (int)y_max - (int)y_min + 1;
                do {
                    RGE_Tile* tile =
                        map->map_row_offset[row_index] + x_min;
                    if (x_min <= x_max) {
                        int columns = (int)x_max - (int)x_min + 1;
                        do {
                            RGE_Object_Node* node = tile->objects.list;
                            while (node != 0) {
                                RGE_Static_Object* object = node->node;
                                node = node->next;
                                RGE_Master_Static_Object* object_master = object->master_obj;

                                if (object_master->id != master_id &&
                                    object_master->can_be_built_on != 0) {
                                    float object_radius_x = object_master->radius_x;
                                    float object_radius_y = object_master->radius_y;
                                    float dy = object->world_y - y;
                                    float dx = object->world_x - x;
                                    if (dy < 0.0f)
                                        dy = -dy;
                                    if (dx < 0.0f)
                                        dx = -dx;

                                    if (dx < object_radius_x + radius_x &&
                                        dy < object_radius_y + radius_y) {
                                        if (flag != 0) {
                                            if (object != 0)
                                                delete object;
                                        } else {
                                            object->destroy_obj();
                                        }
                                    }
                                }
                            }
                            ++tile;
                            --columns;
                        } while (columns != 0);
                    }
                    ++row_index;
                    --row_count;
                } while (row_count != 0);
            }
        }
    }
}
