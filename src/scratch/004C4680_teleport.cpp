// VA: 004C4680 RGE_Static_Object::teleport(float, float, float)
// PDB: stat_obj.cpp:2105-2373
// Attempt log:
// - The packet's initial scratch used a reduced tile-shape switch and helper
//   shims; it was 409 bytes short and had direct add/remove/update calls.
// - Current pass restores the typed RGE world/map/tile/object-list ownership,
//   the 17-case switch, parameter-home coordinate clamps, and terrain calls.
// - The remaining structural lead is the original zero-temporary spill and VC5
//   switch block placement. This source remains scratch.
// BINARY NOTE: teleport uses the canonical named terrain methods.

#include "../../include/stat_obj_context.h"

float RGE_Static_Object::teleport(float param_1, float param_2, float param_3) {
    float result;
    RGE_Map* map;
    float rx;
    float rz;
    int tx;
    int ty;
    RGE_Tile* new_tile;
    result = ZERO_F;
    map = this->owner->world->map;
    if (this->inside_obj != 0) {
        return 0.0f;
    }

    if (0.0 < this->master_obj->radius_z) {
        this->removeFromObstructionMap(2);
    }

    if (param_1 < 0.0f) {
        param_1 = 0.0f;
    }
    // BINARY NOTE: The upper-bound loads come directly from map width and height.
    if (param_1 >= (float)map->map_width) {
        param_1 = (float)map->map_width - TILE_EPSILON;
    }
    if (param_2 < 0.0f) {
        param_2 = 0.0f;
    }
    if (param_2 >= (float)map->map_height) {
        param_2 = (float)map->map_height - TILE_EPSILON;
    }

    tx = (int)param_1;
    ty = (int)param_2;
    rx = param_1 - (float)tx;
    rz = param_2 - (float)ty;
    if (tx < map->map_width) {
        if (tx < 0) {
            tx = 0;
        }
    } else {
        tx = map->map_width - 1;
    }
    if (ty < map->map_height) {
        if (ty < 0) {
            ty = 0;
        }
    } else {
        ty = map->map_height - 1;
    }

    new_tile = map->map_row_offset[ty] + tx;
    if (new_tile == this->tile || this->inside_obj != 0) {
        this->world_x = param_1;
        this->world_y = param_2;
        this->world_z = param_3;
    } else {
        if (this->tile != 0) {
            this->tile->objects.remove_node(this, 0);
        }
        new_tile->objects.add_node(this);
        if (this->tile != 0) {
            this->unexplore_terrain(this->owner, 0, -1);
        }
        this->world_z = param_3;
        this->world_x = param_1;
        this->world_y = param_2;
        this->tile = new_tile;
        if (this->object_state == 2) {
            this->explore_terrain(this->owner, 0, -1);
        }
    }

    if (0.0 < this->master_obj->radius_z) {
        this->addToObstructionMap(2);
    }

    switch (new_tile->tile_type) {
    case 1:
        if (rx + rz < ONE_F) {
            result = rz;
        } else {
            result = ONE_F - rx;
        }
        break;
    case 2:
        if (rx + rz < ONE_F) {
            result = rx;
        } else {
            result = ONE_F - rz;
        }
        break;
    case 3:
        if (rx <= rz) {
            result = ONE_F - rz;
        } else {
            result = ONE_F - rx;
        }
        break;
    case 4:
        if (rx <= rz) {
            result = rx;
        } else {
            result = rz;
        }
        break;
    case 5:
        result = ONE_F - rx;
        break;
    case 6:
        result = ONE_F - rz;
        break;
    case 7:
        result = rz;
        break;
    case 8:
        result = rx;
        break;
    case 9:
        if (rx - rz < 0.0f) {
            result = -(rx - rz);
        } else {
            result = 0.0f;
        }
        break;
    case 10:
        result = rx - rz;
        if (result <= 0.0f) {
            result = 0.0f;
        }
        break;
    case 11:
        if (rx + rz < 1.0f) {
            result = ONE_F - (rx + rz);
        } else {
            result = 0.0f;
        }
        break;
    case 12:
        if (1.0f < rx + rz) {
            result = (rx + rz) - ONE_F;
        } else {
            result = 0.0f;
        }
        break;
    case 0:
        result = 0.0f;
        break;
    case 13:
        if (1.0f <= rx + rz) {
            result = rz;
        } else {
            result = ONE_F - rx;
        }
        break;
    case 14:
        if (1.0f <= rx + rz) {
            result = rx;
        } else {
            result = ONE_F - rz;
        }
        break;
    case 15:
        if (rx <= rz) {
            result = rz;
        } else {
            result = rx;
        }
        break;
    case 16:
        if (rx <= rz) {
            result = ONE_F - rx;
        } else {
            result = ONE_F - rz;
        }
        break;
    default:
        break;
    }

    RGE_Master_Static_Object* master = this->master_obj;
    unsigned char movement = master->movement_type;
    result += (float)(new_tile->tile_level >> 5);
    if (movement == 0 || (movement == 1 && this->world_z < result)) {
        this->world_z = result;
    }

    this->screen_x_offset = (short)((rx + rz) * map->screen_x_scale);
    this->screen_y_offset = (short)((result + rx - SCREEN_BIAS - rz - this->world_z) * map->screen_y_scale);

    if (movement == 0) {
        this->shadow_x_offset = this->screen_x_offset;
        this->shadow_y_offset = this->screen_y_offset;
    } else if (movement == 1) {
        this->shadow_x_offset = (short)((rx + rz) * map->screen_x_scale);
        this->shadow_y_offset = (short)((result - rz) * map->screen_y_scale);
    }
    return result;
}
