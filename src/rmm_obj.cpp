#include <string.h>
#include <memory.h>
#include "../include/m_s_obj.h"
#include "../include/rmm_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/world.h"
#include "../include/zone_map.h"


RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    RGE_Game_World* in_world, RGE_Object_Info* in_info,
    unsigned char add_terrain_objects)
    : RGE_Random_Map_Module(in_map, parent_module, 1) {
    this->world = in_world;
    if (in_info != 0) {
        memcpy(&this->info, in_info, sizeof(RGE_Object_Info));
    } else {
        this->info.object_num = 0;
        this->info.land_num = 0;
    }
    this->schedule = 3.0f;
    this->add_terrain = add_terrain_objects;
}

void RGE_RMM_Object_Generator::add_quick_obj(
    long obj_id, long count, long er) {
    this->info.objects[this->info.object_num].obj_id = obj_id;
    this->info.objects[this->info.object_num].terrain = -1;
    this->info.objects[this->info.object_num].group_flag = 0;
    this->info.objects[this->info.object_num].scale_flag = 0;
    this->info.objects[this->info.object_num].object_number_per_group = 1;
    this->info.objects[this->info.object_num].object_number_varience = 1;
    this->info.objects[this->info.object_num].number_of_groups = count;
    this->info.objects[this->info.object_num].group_area = 2;
    this->info.objects[this->info.object_num].player_id = 0;
    this->info.objects[this->info.object_num].land_id = -1;
    this->info.objects[this->info.object_num].land_inner_radius = 0;
    this->info.objects[this->info.object_num].land_outer_radius = 1;
    this->info.objects[this->info.object_num].object_exclusion_zone = er;
    this->info.object_num = this->info.object_num + 1;
}

unsigned char RGE_RMM_Object_Generator::generate() {
    if (this->add_terrain != 0) {
        RGE_Game_World* wld = this->world;
        short w = this->map_width;
        short h = this->map_height;
        h--;
        w--;
        this->map->set_terrain(*wld->players, wld, 0, 0, w, h, 1, 0, 0);
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

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& info_line) {
    if (info_line.scale_flag) {
        long n = (this->map_width * this->map_height *
                  info_line.number_of_groups) / 0x5100;
        info_line.number_of_groups = n;
        if (n < 1) {
            info_line.number_of_groups = 1;
        }
    }

    if (info_line.land_id >= 0) {
        for (int i = 0; i < this->info.land_num; i++) {
            RGE_Land_Point_Info_Line& land = this->info.lands[i];
            if (land.id == info_line.land_id) {
                this->place_land_objects(info_line, land.x, land.y,
                                         info_line.land_inner_radius, info_line.land_outer_radius, i);
            }
        }
    } else if (info_line.land_id == -1) {
        this->place_objects(info_line);
    } else if (info_line.land_id == -2) {
        this->place_avoid_objects(info_line, info_line.land_inner_radius);
    }
}

// tables, and the source's clipped rectangular scan.
extern int __cdecl debug_rand(char* file, int line);
extern char s_rmm_obj_cpp[];

void RGE_RMM_Object_Generator::make_placement_stack(
    Map_Stack& stack, long x, long y, long inner_radius, long outer_radius) {
    long y1;
    long y0;
    long x1;
    long x0;
    Map_Stack* last;
    int rows_remaining;

    stack.next = 0;
    stack.prev = 0;

    if (x < 0 || y < 0 || outer_radius < 0) {
        x0 = 0;
        y0 = 0;
        x1 = this->map_width - 1;
        y1 = this->map_height - 1;
    } else {
        x0 = x - outer_radius;
        y0 = y - outer_radius;
        x1 = x + outer_radius;
        y1 = y + outer_radius;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= this->map_width) x1 = this->map_width - 1;
        if (y1 >= this->map_height) y1 = this->map_height - 1;
    }

    last = &stack;
    if (y0 <= y1) {
        rows_remaining = y1 + (1 - y0);
        long row = y0;
        do {
            long xcur = x0;
            if (x0 <= x1) {
                do {
                    if (this->search_map_rows[row][xcur] != 0) {
                        Map_Stack* node = &this->stack_offsets[row][xcur];
                        this->add_stack_node(last, node);
                        last = node;
                    }
                    xcur = xcur + 1;
                } while (xcur <= x1);
            }
            row = row + 1;
            rows_remaining = rows_remaining - 1;
        } while (rows_remaining != 0);
    }

    int w = x1 - x0 - 1;
    int h = y1 - y0 - 1;
    if (w > 1 && h > 1) {
        int count = (h * w) / 4;
        if (count > 0) {
            do {
                int rx = (debug_rand(s_rmm_obj_cpp, 175) * w) / 0x7fff + x0;
                int ry = (debug_rand(s_rmm_obj_cpp, 176) * h) / 0x7fff + y0;
                if (this->search_map_rows[ry][rx] != 0) {
                    this->add_stack_node(&stack, &this->stack_offsets[ry][rx]);
                }
                count = count - 1;
            } while (count != 0);
        }
    }
}

unsigned char RGE_RMM_Object_Generator::to_close(
    RGE_Object_Info_Line& info_line, long x, long y) {
    long count = this->info.land_num;
    long i;
    for (i = 0; i < count; i++) {
        long* p = (long*)((char*)&this->info.lands[0].y + i * 0x10);
        long dx = x - *(p - 1);
        if (dx < 0) dx = -dx;

        long dy = y - *p;
        if (dy < 0) dy = -dy;

        if (dx < info_line.land_inner_radius && dy < info_line.land_inner_radius) {
            return 1;
        }
    }

    return 0;
}

void RGE_RMM_Object_Generator::set_search_area(
    long x, long y, long radius, unsigned char set_num) {
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
                    self->search_map_rows[y_cur][cx - 1] = set_num;
                } while (cx <= end_x);
            }
            ++y_cur;
        } while (y_cur <= end_y);
    }
}

void RGE_RMM_Object_Generator::remove_area_from_lists(
    long x, long y, long spacing) {
    long x_start = x - spacing;
    long y_start = y - spacing;
    long x_end = spacing + x;
    long y_end = spacing + y;

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
                this->remove_stack_node((Map_Stack*)((char*)this->stack_offsets[cur_y] + offset));
                offset += 24;
                count--;
            } while (count != 0);
        }
    }
}

extern "C" void* __cdecl memset(void*, int, unsigned int);

void RGE_RMM_Object_Generator::place_avoid_objects(
    RGE_Object_Info_Line& info_line, long inner_radius) {
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
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y, info_line.land_inner_radius, 0);
    }

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    RGE_Player* player = this->world->players[
        info_line.player_id & ((info_line.player_id <= -1) - 1)];
    count = info_line.number_of_groups;

    while (this->pop_stack(obj_stack, x, y, zone) && count > 0) {
        if (info_line.terrain >= 0) {
            if ((this->map_row_offset[y][x].terrain_type & 0x1f) != (unsigned int)info_line.terrain) {
                goto next;
            }
        }

        tile_x = (float)x;
        tile_y = (float)y;
        master = player->master_objects[info_line.obj_id];
        radius = (short)(int)master->radius_x;
        if (master->radius_x - (float)radius > 0.0f) {
            tile_x = tile_x + 0.5f;
        }
        radius = (short)(int)master->radius_y;
        if (master->radius_y - (float)radius > 0.0f) {
            tile_y = tile_y + 0.5f;
        }

        if (!master->check_placement(player, tile_x, tile_y, 0, 0, 1, 1, 1, 0, 1)) {
            this->remove_area_from_lists(x, y, info_line.object_exclusion_zone);
            switch (info_line.group_flag) {
            case 0:
                player->make_new_object(info_line.obj_id, tile_x, tile_y, 0, 1);
                break;
            case 1:
                this->place_group(info_line, x, y, player);
                break;
            case 2:
                this->place_cluster(info_line, x, y, player);
                break;
            }
            count--;
        }
    next:
        ;
    }
    this->deinit_stack(obj_stack);
}

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& info_line) {
    long y;
    long x;
    float tile_y;
    float tile_x;
    long count;
    Map_Stack obj_stack;
    float zone;
    RGE_Master_Static_Object* master;
    short radius;

    memset(this->search_map, 1, this->map_width * this->map_height);

    this->init_stack(obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    RGE_Player* player = this->world->players[
        info_line.player_id & ((info_line.player_id <= -1) - 1)];
    count = info_line.number_of_groups;

    while (this->pop_stack(obj_stack, x, y, zone) && count > 0) {
        if (info_line.terrain >= 0) {
            if ((this->map_row_offset[y][x].terrain_type & 0x1f) != (unsigned int)info_line.terrain) {
                goto next;
            }
        }

        tile_x = (float)x;
        tile_y = (float)y;
        master = player->master_objects[info_line.obj_id];
        radius = (short)(int)master->radius_x;
        if (master->radius_x - (float)radius > 0.0f) {
            tile_x = tile_x + 0.5f;
        }
        radius = (short)(int)master->radius_y;
        if (master->radius_y - (float)radius > 0.0f) {
            tile_y = tile_y + 0.5f;
        }

        if (!master->check_placement(player, tile_x, tile_y, 0, 0, 1, 1, 1, 0, 1)) {
            this->remove_area_from_lists(x, y, info_line.object_exclusion_zone);
            switch (info_line.group_flag) {
            case 0:
                player->make_new_object(info_line.obj_id, tile_x, tile_y, 0, 1);
                break;
            case 1:
                this->place_group(info_line, x, y, player);
                break;
            case 2:
                this->place_cluster(info_line, x, y, player);
                break;
            }
            count--;
        }
    next:
        ;
    }
    this->deinit_stack(obj_stack);
}

void RGE_RMM_Object_Generator::place_land_objects(
    RGE_Object_Info_Line& info_line, long map_x, long map_y, long inner_radius,
    long outer_radius, long land_id) {
    long radius = inner_radius;
    long min_x1 = map_x - radius;
    long min_y1 = map_y - radius;
    long max_x = map_x + radius;
    long min_y0 = map_y + radius;
    long min_x0;
    long y;
    int zone_index;
    unsigned char land_zone;
    float zone;
    int temp;
    Map_Stack obj_stack;

    if (min_x1 < 0) min_x1 = 0;
    if (min_y1 < 0) min_y1 = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (min_y0 >= this->map_height) min_y0 = this->map_height - 1;

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
    this->make_placement_stack(obj_stack, map_x, map_y, radius, outer_radius);

    RGE_Object_Info_Line* object = &info_line;
    int player_id = 0;
    if (object->player_id > -1) {
        player_id = object->player_id;
    } else {
        int land_player_id = this->info.lands[land_id].player_id;
        if (land_player_id > 0) player_id = land_player_id;
    }

    RGE_Player* player = this->world->players[player_id];
    RGE_Master_Static_Object* master =
        player->master_objects[object->obj_id];
    if (master != 0) {
        RGE_Zone_Map* map_zone = this->map->map_zones->get_zone_map(
            this->world->terrains[master->terrain], 0x20, zone_index);
        land_zone = map_zone->get_zone_info(map_x, map_y);

        long count = object->number_of_groups;
        while (this->pop_stack(obj_stack, y, min_x0, zone) != 0 && count > 0) {
            if ((unsigned char)land_zone == map_zone->get_zone_info(y, min_x0) && (object->terrain < 0 ||
                 (this->map_row_offset[min_x0][y].terrain_type & 0x1f) == object->terrain) && (y <= min_x1 || y >= max_x ||
                 min_x0 <= min_y1 || min_x0 >= min_y0)) {
                float fx = (float)y;
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

                if (!placement_master->check_placement(player, fx, fy, 0, 0, 1, 1, 1, 1, 1)) {
                    this->remove_area_from_lists(y, min_x0, object->object_exclusion_zone);
                    switch (object->group_flag) {
                    case 0:
                        player->make_new_object(object->obj_id, fx, fy, 0, 1);
                        break;
                    case 1:
                        this->place_group(*object, y, min_x0, player);
                        break;
                    case 2:
                        this->place_cluster(*object, y, min_x0, player);
                        break;
                    }
                    --count;
                } else if (object->group_flag == 0 && obj_stack.next == 0) {
                    player->make_new_object(object->obj_id, fx, fy, 0, 1);
                }
            }
        }
        this->deinit_stack(obj_stack);
    }
}

void RGE_RMM_Object_Generator::place_group(
    RGE_Object_Info_Line& info_line, long map_x, long map_y, RGE_Player* player) {
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
    this->make_placement_stack(obj_stack, map_x, map_y, 0, info_line.group_area);

    int count = info_line.object_number_per_group;
    register int var = info_line.object_number_varience;
    int delta = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 530) *
                 (var << 1)) / 0x7fff - var;
    count += delta;
    if (count < 1) count = 1;

    while (pop_stack(obj_stack, col, x, cost) && count > 0) {
        if (info_line.terrain < 0 || ((this->map_row_offset[x][col].terrain_type & 0x1f) ==
             (unsigned int)info_line.terrain)) {
            fx = (float)col;
            fy = (float)x;
            RGE_Master_Static_Object* master =
                player->master_objects[info_line.obj_id];
            zone = (short)(int)master->radius_x;
            if (0.0f < master->radius_x - (float)zone) {
                fx = fx + 0.5f;
            }
            zone = (short)(int)master->radius_y;
            if (0.0f < master->radius_y - (float)zone) {
                fy = fy + 0.5f;
            }
            if (!master->check_placement(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                player->make_new_object(info_line.obj_id, fx, fy, 0, 1);
                count--;
            }
        }
    }
    self->deinit_stack(obj_stack);
}

void RGE_RMM_Object_Generator::place_cluster(
    RGE_Object_Info_Line& info_line, long map_x, long map_y, RGE_Player* player) {
    long x;
    long y;
    float cost;
    float tile_x;
    float tile_y;
    Map_Stack obj_stack;

    obj_stack.next = 0;
    obj_stack.prev = 0;
    this->init_stack(obj_stack);
    this->add_stack_node(&obj_stack, &this->stack_offsets[map_y][map_x]);

    long min_x = map_x - info_line.group_area;
    long y0 = map_y - info_line.group_area;
    long x1 = map_x + info_line.group_area;
    long y1 = map_y + info_line.group_area;

    if (min_x < 0) min_x = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (y = y0; y <= y1; y++) {
        for (x = min_x; x <= x1; x++) {
            this->search_map_rows[y][x] = 1;
        }
    }

    int count = info_line.object_number_per_group;
    register int var = info_line.object_number_varience;
    int delta = (debug_rand(s_rmm_obj_cpp, 598) * (var << 1)) /
                0x7fff - var;
    count += delta;
    if (count < 1) count = 1;

    while (this->pop_stack(obj_stack, x, y, cost) && count > 0) {
        tile_x = (float)x;
        tile_y = (float)y;
        RGE_Master_Static_Object* master =
            player->master_objects[info_line.obj_id];

        short radius = (short)(int)master->radius_x;
        if (master->radius_x - (float)radius > 0.0f) {
            tile_x = tile_x + 0.5f;
        }
        radius = (short)(int)master->radius_y;
        if (master->radius_y - (float)radius > 0.0f) {
            tile_y = tile_y + 0.5f;
        }

        master->alignment(tile_x, tile_y, this->world, 1);
        if (!master->check_placement(player, tile_x, tile_y, 0, 0, 1, 1, 1, 0, 1)) {
            player->make_new_object(info_line.obj_id, tile_x, tile_y, 0, 1);
            count--;
            this->search_map_rows[y][x] = 0;

            if (x > min_x && this->search_map_rows[y][x - 1] != 0) {
                this->push_stack(obj_stack, x - 1, y, 0.0f, (float)debug_rand(s_rmm_obj_cpp, 624));
            }
            if (x < x1 && this->search_map_rows[y][x + 1] != 0) {
                this->push_stack(obj_stack, x + 1, y, 0.0f, (float)debug_rand(s_rmm_obj_cpp, 627));
            }
            if (y > y0 && this->search_map_rows[y - 1][x] != 0) {
                this->push_stack(obj_stack, x, y - 1, 0.0f, (float)debug_rand(s_rmm_obj_cpp, 630));
            }
            if (y < y1 && this->search_map_rows[y + 1][x] != 0) {
                this->push_stack(obj_stack, x, y + 1, 0.0f, (float)debug_rand(s_rmm_obj_cpp, 633));
            }
        }
    }

    this->deinit_stack(obj_stack);
}
