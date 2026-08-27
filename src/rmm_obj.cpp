#include <string.h>
#include "../include/rmm_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/zone_map.h"

// PDB source order for C:\\msdev\\work\\age1_x1\\rmm_obj.cpp.

// VA: 00485C50 RGE_RMM_Object_Generator::RGE_RMM_Object_Generator
RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
    RGE_Map* param_1, RGE_Random_Map_Module* param_2,
    RGE_Game_World* param_3, RGE_Object_Info* param_4, unsigned char param_5)
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->world = param_3;
    if (param_4 != 0) {
        memcpy(&this->info, param_4, sizeof(RGE_Object_Info));
    } else {
        *(long*)((char*)&this->info + 0x1290) = 0;
        *(long*)((char*)&this->info + 0x18C4) = 0;
    }
    this->schedule = 3.0f;
    this->add_terrain = param_5;
}

// VA: 00485CB0 RGE_RMM_Object_Generator::add_quick_obj
void RGE_RMM_Object_Generator::add_quick_obj(
    long obj_id, long number_of_groups, long object_exclusion_zone)
{
    this->info.objects[this->info.object_num].obj_id = obj_id;
    this->info.objects[this->info.object_num].terrain = -1;
    this->info.objects[this->info.object_num].group_flag = 0;
    this->info.objects[this->info.object_num].scale_flag = 0;
    this->info.objects[this->info.object_num].object_number_per_group = 1;
    this->info.objects[this->info.object_num].object_number_varience = 1;
    this->info.objects[this->info.object_num].number_of_groups = number_of_groups;
    this->info.objects[this->info.object_num].group_area = 2;
    this->info.objects[this->info.object_num].player_id = 0;
    this->info.objects[this->info.object_num].land_id = -1;
    this->info.objects[this->info.object_num].land_inner_radius = 0;
    this->info.objects[this->info.object_num].land_outer_radius = 1;
    this->info.objects[this->info.object_num].object_exclusion_zone = object_exclusion_zone;
    this->info.object_num = this->info.object_num + 1;
}

// VA: 00485DC0 RGE_RMM_Object_Generator::generate
unsigned char RGE_RMM_Object_Generator::generate() {
    if (this->add_terrain != 0) {
        RGE_Game_World* wld = this->world;
        short w = this->map_width;
        short h = this->map_height;
        h--;
        w--;
        this->map->set_terrain(
            *wld->players, wld,
            0, 0,
            w, h,
            1, 0, 0
        );
    }

    this->clear_stack();

    long* zero_ptr = (long*)this->terrain_table;
    int zero_cnt = 8;
    do {
        *zero_ptr++ = 0;
        zero_cnt--;
    } while (zero_cnt != 0);

    for (int i = 0; i < this->info.object_num; i++) {
        this->generate_objects(this->info.objects[i]);
    }

    this->map->map_zones->delete_zone_maps();

    return 1;
}

// VA: 00485E50 RGE_RMM_Object_Generator::generate_objects
void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& line) {
    if (line.scale_flag) {
        long n = (this->map_width * this->map_height *
                  line.number_of_groups) / 0x5100;
        line.number_of_groups = n;
        if (n < 1) {
            line.number_of_groups = 1;
        }
    }

    if (line.land_id >= 0) {
        for (int i = 0; i < this->info.land_num; i++) {
            RGE_Land_Point_Info_Line& land = this->info.lands[i];
            if (land.id == line.land_id) {
                this->place_land_objects(line, land.x, land.y,
                    line.land_inner_radius, line.land_outer_radius, i);
            }
        }
    } else if (line.land_id == -1) {
        this->place_objects(line);
    } else if (line.land_id == -2) {
        this->place_avoid_objects(line, line.land_inner_radius);
    }
}

// VA: 00485F10 RGE_RMM_Object_Generator::make_placement_stack
// The clean reconstruction retains the proven Map_Stack reference, typed row
// tables, and the source's clipped rectangular scan.
extern "C" int __cdecl debug_rand(char* file, int line);
extern char s_rmm_obj_cpp[];

void RGE_RMM_Object_Generator::make_placement_stack(
    Map_Stack& stack, long x, long y, long unused, long range)
{
    long y1;
    long last;
    Map_Stack* local_c;
    int local_4;

    stack.next = 0;
    stack.prev = 0;

    if (x < 0 || y < 0 || range < 0) {
        x = 0;
        y = 0;
        range = this->map_width - 1;
        last = this->map_height - 1;
    } else {
        long min_x = x;
        long min_y = y;
        long max_x = x;
        long max_y = y;
        min_x -= range;
        min_y -= range;
        max_x += range;
        max_y += range;
        x = min_x;
        y = min_y;
        last = max_y;
        range = max_x;
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (range >= this->map_width) range = this->map_width - 1;
        if (last >= this->map_height) last = this->map_height - 1;
    }

    local_c = &stack;
    if (y <= last) {
        local_4 = last + (1 - y);
        long row = y;
        do {
            y1 = x;
            if (x <= range) {
                do {
                    if (this->search_map_rows[row][y1] != 0) {
                        Map_Stack* node = &this->stack_offsets[row][y1];
                        this->add_stack_node(local_c, node);
                        local_c = node;
                    }
                    y1 = y1 + 1;
                } while (y1 <= range);
            }
            row = row + 1;
            local_4 = local_4 - 1;
        } while (local_4 != 0);
    }

    int w = range - x - 1;
    int h = last - y - 1;
    if (w > 1 && h > 1) {
        int count = (h * w) / 4;
        if (count > 0) {
            do {
                int rx = (debug_rand(s_rmm_obj_cpp, 0xaf) * w) / 0x7fff + x;
                int ry = (debug_rand(s_rmm_obj_cpp, 0xb0) * h) / 0x7fff + y;
                if (this->search_map_rows[ry][rx] != 0) {
                    this->add_stack_node(&stack, &this->stack_offsets[ry][rx]);
                }
                count = count - 1;
            } while (count != 0);
        }
    }
}

// VA: 00486110 RGE_RMM_Object_Generator::to_close
unsigned char RGE_RMM_Object_Generator::to_close(
    RGE_Object_Info_Line& info_line, long x, long y)
{
    long count = this->info.land_num;
    long i;
    for (i = 0; i < count; i++) {
        long* p = (long*)((char*)&this->info.lands[0].y + i * 0x10);
        long dx = x - *(p - 1);
        if (dx < 0) dx = -dx;

        long dy = y - *p;
        if (dy < 0) dy = -dy;

        if (dx < info_line.land_inner_radius &&
            dy < info_line.land_inner_radius) {
            return 1;
        }
    }

    return 0;
}

// VA: 00486180 RGE_RMM_Object_Generator::set_search_area
void RGE_RMM_Object_Generator::set_search_area(
    long x, long y, long radius, unsigned char fill)
{
    long sx = x - radius;
    long sy = y - radius;
    long end_x = x + radius;
    long end_y = radius;
    RGE_RMM_Object_Generator* self = this;
    end_y += y;

    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    if (end_x >= self->map_width) end_x = self->map_width - 1;
    if (end_y >= self->map_height) end_y = self->map_height - 1;

    long y_cur = sy;
    if (y_cur <= end_y) {
        do {
            long cx = sx;
            if (cx <= end_x) {
                do {
                    ++cx;
                    self->search_map_rows[y_cur][cx - 1] = fill;
                } while (cx <= end_x);
            }
            ++y_cur;
        } while (y_cur <= end_y);
    }
}

// VA: 00486210 RGE_RMM_Object_Generator::remove_area_from_lists
void RGE_RMM_Object_Generator::remove_area_from_lists(
    long left, long right, long y) {
    long x_start = left - y;
    long y_start = right - y;
    long x_end = y + left;
    long y_end = y + right;

    if (x_start < 0)
        x_start = 0;
    if (y_start < 0)
        y_start = 0;

    if (x_end >= this->map_width)
        x_end = this->map_width - 1;
    if (y_end >= this->map_height)
        y_end = this->map_height - 1;

    for (long cur_y = y_start; cur_y <= y_end; cur_y++) {
        if (x_start <= x_end) {
            long offset = x_start * 24;
            long count = x_end - x_start + 1;
            do {
                this->remove_stack_node(
                    (Map_Stack*)((char*)this->stack_offsets[cur_y] + offset));
                offset += 24;
                count--;
            } while (count != 0);
        }
    }
}

// VA: 004862B0 RGE_RMM_Object_Generator::place_avoid_objects
// ACCEPTED DRIFT: The typed source preserves the executable's call order,
// placement gates, FPU work, and state changes. Its private setup block has a
// reviewed register and scheduling difference.
extern "C" void* __cdecl memset(void*, int, unsigned int);

void RGE_RMM_Object_Generator::place_avoid_objects(
    RGE_Object_Info_Line& info, long unused)
{
    long y;
    long x;
    float tile_y;
    float tile_x;
    long count;
    Map_Stack obj_stack;
    float zone;
    RGE_Master_Static_Object* master;
    short radius;
    int i;

    memset(this->search_map, 1, this->map_width * this->map_height);

    for (i = 0; i < this->info.land_num; i++) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y,
                              info.land_inner_radius, 0);
    }

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    RGE_Player* player = this->world->players[
        info.player_id & ((info.player_id <= -1) - 1)];
    count = info.number_of_groups;

    while (this->pop_stack(obj_stack, x, y, zone) && count > 0) {
        if (info.terrain >= 0) {
            if ((this->map_row_offset[y][x].terrain_type & 0x1f) !=
                (unsigned int)info.terrain) {
                goto next;
            }
        }

        tile_x = (float)x;
        tile_y = (float)y;
        master = player->master_objects[info.obj_id];
        radius = (short)(int)master->radius_x;
        if (master->radius_x - (float)radius > 0.0f) {
            tile_x = tile_x - -0.5f;
        }
        radius = (short)(int)master->radius_y;
        if (master->radius_y - (float)radius > 0.0f) {
            tile_y = tile_y - -0.5f;
        }

        if (!master->check_placement(player, tile_x, tile_y,
                                     0, 0, 1, 1, 1, 0, 1)) {
            this->remove_area_from_lists(x, y, info.object_exclusion_zone);
            switch (info.group_flag) {
            case 0:
                player->make_new_object(info.obj_id, tile_x, tile_y, 0, 1);
                break;
            case 1:
                this->place_group(info, x, y, player);
                break;
            case 2:
                this->place_cluster(info, x, y, player);
                break;
            }
            count--;
        }
    next:
        ;
    }
    this->deinit_stack(obj_stack);
}

// VA: 004864F0 RGE_RMM_Object_Generator::place_objects
// SCRATCH: The source model and call sequence are understood. The executable
// still differs in the initial world/player/count scheduling block.
#include <memory.h>

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& info)
{
    long y;
    long x;
    float tile_y;
    float tile_x;
    long count;
    Map_Stack obj_stack;
    float zone;

    memset(this->search_map, 1, this->map_width * this->map_height);

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    RGE_Player* player = this->world->players[
        info.player_id & (info.player_id <= -1 ? 0 : -1)];
    count = info.number_of_groups;

    while (pop_stack(obj_stack, x, y, zone) && count > 0) {
        if (info.terrain < 0 ||
            ((this->map_row_offset[y][x].terrain_type & 0x1f) ==
             (unsigned int)info.terrain)) {
            tile_x = (float)x;
            tile_y = (float)y;
            RGE_Master_Static_Object* master =
                player->master_objects[info.obj_id];
            short radius = (short)(int)master->radius_x;
            if (0.0f < master->radius_x - (float)radius) {
                tile_x = tile_x - -0.5f;
            }
            radius = (short)(int)master->radius_y;
            if (0.0f < master->radius_y - (float)radius) {
                tile_y = tile_y - -0.5f;
            }
            if (!master->check_placement(player, tile_x, tile_y,
                                         0, 0, 1, 1, 1, 0, 1)) {
                remove_area_from_lists(x, y, info.object_exclusion_zone);
                switch (info.group_flag) {
                case 0:
                    player->make_new_object(info.obj_id, tile_x, tile_y, 0, 1);
                    break;
                case 1:
                    place_group(info, x, y, player);
                    break;
                case 2:
                    place_cluster(info, x, y, player);
                    break;
                }
                count--;
            }
        }
    }
    this->deinit_stack(obj_stack);
}

// VA: 00486700 RGE_RMM_Object_Generator::place_land_objects
void RGE_RMM_Object_Generator::place_land_objects(
    RGE_Object_Info_Line& line, long x, long y, long inner_radius,
    long outer_radius, long land_index)
{
    long radius = inner_radius;
    long min_x = x - radius;
    long min_y = y - radius;
    long max_x = x + radius;
    long max_y = y + radius;
    long min_x0;
    long y1;
    int zone_index;
    unsigned char zone;
    float cost;
    int temp;
    Map_Stack obj_stack;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    memset(this->search_map, 1, this->map_width * this->map_height);

    int i = 0;
    if (this->info.land_num > 0) {
        RGE_Land_Point_Info_Line* land = this->info.lands;
        do {
            this->set_search_area(land->x, land->y, radius, 0);
            ++i;
            ++land;
        } while (i < this->info.land_num);
    }

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, x, y, radius, outer_radius);

    RGE_Object_Info_Line* object = &line;
    int player_id = 0;
    if (object->player_id > -1) {
        player_id = object->player_id;
    } else {
        int land_player_id = this->info.lands[land_index].player_id;
        if (land_player_id > 0) player_id = land_player_id;
    }

    RGE_Player* player = this->world->players[player_id];
    RGE_Master_Static_Object* master =
        player->master_objects[object->obj_id];
    if (master != 0) {
        RGE_Zone_Map* zone_map = this->map->map_zones->get_zone_map(
            this->world->terrains[master->terrain], 0x20, zone_index);
        zone = zone_map->get_zone_info(x, y);

        long count = object->number_of_groups;
        while (this->pop_stack(obj_stack, y1, min_x0, cost) != 0 &&
               count > 0) {
            if ((unsigned char)zone ==
                    zone_map->get_zone_info(y1, min_x0) &&
                (object->terrain < 0 ||
                 (this->map_row_offset[min_x0][y1].terrain_type & 0x1f) ==
                     object->terrain) &&
                (y1 <= min_x || y1 >= max_x ||
                 min_x0 <= min_y || min_x0 >= max_y)) {
                float fx = (float)y1;
                RGE_Master_Static_Object* placement_master =
                    player->master_objects[object->obj_id];
                float fy = (float)min_x0;

                temp = (short)(int)placement_master->radius_x;
                if (0.0f < placement_master->radius_x - (float)temp) {
                    fx -= -0.5f;
                }
                temp = (short)(int)placement_master->radius_y;
                if (0.0f < placement_master->radius_y - (float)temp) {
                    fy -= -0.5f;
                }

                if (!placement_master->check_placement(player, fx, fy,
                    0, 0, 1, 1, 1, 1, 1)) {
                    this->remove_area_from_lists(y1, min_x0,
                        object->object_exclusion_zone);
                    switch (object->group_flag) {
                    case 0:
                        player->make_new_object(object->obj_id, fx, fy, 0, 1);
                        break;
                    case 1:
                        this->place_group(*object, y1, min_x0, player);
                        break;
                    case 2:
                        this->place_cluster(*object, y1, min_x0, player);
                        break;
                    }
                    --count;
                } else if (object->group_flag == 0 &&
                           obj_stack.next == 0) {
                    player->make_new_object(object->obj_id, fx, fy, 0, 1);
                }
            }
        }
        this->deinit_stack(obj_stack);
    }
}

// VA: 00486A60 RGE_RMM_Object_Generator::place_group
// MATCH: The variance doubling and typed radius scratch preserve the exact
// period VC5 x87 and register topology.
void RGE_RMM_Object_Generator::place_group(
    RGE_Object_Info_Line& info, long px, long py, RGE_Player* player)
{
    long x;
    long col;
    float cost;
    RGE_RMM_Object_Generator* self;
    int zone;
    float fx;
    float fy;
    Map_Stack obj_stack;

    self = this;
    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, px, py, 0, info.group_area);

    int count = info.object_number_per_group;
    register int var = info.object_number_varience;
    int delta = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x212) *
                 (var << 1)) / 0x7fff - var;
    count += delta;
    if (count < 1) count = 1;

    while (pop_stack(obj_stack, col, x, cost) && count > 0) {
        if (info.terrain < 0 ||
            ((this->map_row_offset[x][col].terrain_type & 0x1f) ==
             (unsigned int)info.terrain)) {
            fx = (float)col;
            fy = (float)x;
            RGE_Master_Static_Object* master =
                player->master_objects[info.obj_id];
            zone = (short)(int)master->radius_x;
            if (0.0f < master->radius_x - (float)zone) {
                fx = fx - -0.5f;
            }
            zone = (short)(int)master->radius_y;
            if (0.0f < master->radius_y - (float)zone) {
                fy = fy - -0.5f;
            }
            if (!master->check_placement(player, fx, fy,
                                         0, 0, 1, 1, 1, 0, 1)) {
                player->make_new_object(info.obj_id, fx, fy, 0, 1);
                count--;
            }
        }
    }
    self->deinit_stack(obj_stack);
}

// VA: 00486C40 RGE_RMM_Object_Generator::place_cluster
// SCRATCH: The typed cluster expansion preserves the executable's 19 calls,
// bounds, placement state, and neighbor pushes. Local liveness still differs.
void RGE_RMM_Object_Generator::place_cluster(
    RGE_Object_Info_Line& info, long x, long y, RGE_Player* player)
{
    long tile_y;
    long x1;
    long y0;
    long y1;
    long x_start;
    long zone;
    long count;
    float tile_x;
    float tile_y_float;
    float cost;
    Map_Stack* node;

    Map_Stack obj_stack;
    this->init_stack(obj_stack);
    this->add_stack_node(&obj_stack, &this->stack_offsets[y][x]);

    y1 = y - info.group_area;
    y0 = x + info.group_area;
    zone = y + info.group_area;
    x_start = x - info.group_area;
    if (x_start < 0) x_start = 0;
    if (y1 < 0) y1 = 0;
    if (y0 >= this->map_width) y0 = this->map_width - 1;
    if (zone >= this->map_height) zone = this->map_height - 1;

    for (x1 = y1; x1 <= zone; ++x1) {
        for (tile_y = x_start; tile_y <= y0; ++tile_y) {
            this->search_map_rows[x1][tile_y] = 1;
        }
    }

    count = info.object_number_per_group;
    long variance = info.object_number_varience;
    count += (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x256) *
        (variance << 1)) / 0x7fff - variance;
    if (count < 1) count = 1;

    node = this->pop_stack(obj_stack, tile_y, x1, cost);
    while (node != 0 && count > 0) {
        RGE_Master_Static_Object* master = player->master_objects[info.obj_id];
        tile_y_float = (float)tile_y;
        tile_x = (float)x1;
        if (master->radius_x -
                (float)(short)(int)master->radius_x > 0.0f) {
            tile_y_float += 0.5f;
        }
        if (master->radius_y -
                (float)(short)(int)master->radius_y > 0.0f) {
            tile_x += 0.5f;
        }

        master->alignment(tile_y_float, tile_x, this->world, 1);
        if (master->check_placement(player, tile_y_float, tile_x,
                0, 0, 1, 1, 1, 0, 1) == 0) {
            player->make_new_object(info.obj_id, tile_y_float, tile_x, 0, 1);
            --count;
            this->search_map_rows[x1][tile_y] = 0;

            if (tile_y > x_start &&
                this->search_map_rows[x1][tile_y - 1] != 0) {
                this->push_stack(obj_stack, tile_y - 1, x1, 0.0f,
                    (float)debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x270));
            }
            if (tile_y < y0 &&
                this->search_map_rows[x1][tile_y + 1] != 0) {
                this->push_stack(obj_stack, tile_y + 1, x1, 0.0f,
                    (float)debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x273));
            }
            if (x1 > y1 &&
                this->search_map_rows[x1 - 1][tile_y] != 0) {
                this->push_stack(obj_stack, tile_y, x1 - 1, 0.0f,
                    (float)debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x276));
            }
            if (x1 < zone &&
                this->search_map_rows[x1 + 1][tile_y] != 0) {
                this->push_stack(obj_stack, tile_y, x1 + 1, 0.0f,
                    (float)debug_rand(
                        "C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x279));
            }
        }
        node = this->pop_stack(obj_stack, tile_y, x1, cost);
    }

    this->deinit_stack(obj_stack);
}
