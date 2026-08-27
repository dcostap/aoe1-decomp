// 00545C00 RGE_Game_World::objectGroupOnTile(int, int, int, int, int&)
// PDB: World.cpp lines 3512-3536; owning range 00545C00-00545CA5.
// BINARY NOTE: World.cpp reads RGE_Map::map_row_offset at +0x8D8C. The
// canonical RGE_Tile and RGE_Object_List owners recover the remaining fields.
#include "../../include/world.h"
#include "../../include/map.h"
#include "../../include/player.h"
#include "../../include/stat_obj.h"
#include "../../include/m_s_obj.h"

int RGE_Game_World::objectGroupOnTile(int owner_id, int object_group, int tile_x, int tile_y, int& output)
{
    if (tile_x >= 0) {
        if (tile_y >= 0) {
            RGE_Map* map = this->map;
            if (tile_x < map->map_width) {
                if (tile_y < map->map_height) {
                    output = map->map_row_offset[tile_y][tile_x].objects.number_of_objects;
                    RGE_Object_Node* node = this->map->map_row_offset[tile_y][tile_x].objects.list;
                    if (node != 0) {
                        RGE_Static_Object* object;
                        while (node != 0) {
                            object = node->node;
                            if (object == 0) {
                                break;
                            }
                            if ((owner_id == -1 || object->owner->id == owner_id) &&
                                object->master_obj->object_group == object_group) {
                                return object->id;
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
