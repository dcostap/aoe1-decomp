#include "../include/RGE_RMM_Object_Generator.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Zone_Map.h"
#include "../include/RGE_Zone_Map_List.h"
#include "../include/debug_helpers.h"

#include <new>
#include <string.h>

static long rmm_obj_rand_scaled(long scale, int line_no) {
    if (scale <= 0) {
        return 0;
    }
    long r = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", line_no);
    return (long)(((long long)r * (long long)scale) / 0x7fffLL);
}

static float rmm_obj_adjust_coord(float tile, float radius) {
    long i = (long)radius;
    if ((radius - (float)i) > 0.0f) {
        tile += 0.5f;
    }
    return tile;
}

static int rmm_obj_terrain_matches(RGE_RMM_Object_Generator* self, RGE_Object_Info_Line& line, long x, long y) {
    if (self == nullptr || self->map_row_offset == nullptr ||
        x < 0 || y < 0 || x >= self->map_width || y >= self->map_height) {
        return 0;
    }
    if (line.terrain < 0) {
        return 1;
    }
    uchar tt = (uchar)(self->map_row_offset[y][x].terrain_type & 0x1f);
    return tt == line.terrain;
}

static RGE_Player* rmm_obj_get_player_safe(RGE_RMM_Object_Generator* self, long player_index) {
    if (self == nullptr || self->world == nullptr || self->world->players == nullptr || self->world->player_num <= 0) {
        return nullptr;
    }
    if (player_index < 0 || player_index >= self->world->player_num) {
        player_index = 0;
    }
    return self->world->players[player_index];
}

RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(
    RGE_Map* param_1,
    RGE_Random_Map_Module* param_2,
    RGE_Game_World* param_3,
    RGE_Object_Info* param_4,
    uchar param_5)
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00485C50
    : RGE_Random_Map_Module(param_1, param_2, 1) {
    this->schedule = 3.0f;
    this->world = param_3;
    memset(&this->info, 0, sizeof(this->info));
    if (param_4 != nullptr) {
        memcpy(&this->info, param_4, sizeof(this->info));
    }
    memset(this->terrain_table, 0, sizeof(this->terrain_table));
    this->add_terrain = param_5;
}

void RGE_RMM_Object_Generator::add_quick_obj(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00485CB0
    if (this->info.object_num < 0 || this->info.object_num >= 99) {
        return;
    }

    RGE_Object_Info_Line* line = &this->info.objects[this->info.object_num];
    line->obj_id = param_1;
    line->terrain = -1;
    line->group_flag = 0;
    line->scale_flag = 0;
    line->object_number_per_group = 1;
    line->object_number_varience = 1;
    line->number_of_groups = param_2;
    line->group_area = 2;
    line->player_id = 0;
    line->land_id = -1;
    line->land_inner_radius = 0;
    line->land_outer_radius = 1;
    line->object_exclusion_zone = param_3;
    this->info.object_num = this->info.object_num + 1;
}

uchar RGE_RMM_Object_Generator::generate() {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00485DC0
    if (this->add_terrain != 0 && this->map != nullptr && this->world != nullptr &&
        this->world->players != nullptr && this->world->player_num > 0 && this->map_width > 0 && this->map_height > 0) {
        RGE_Player* gaia = this->world->players[0];
        this->map->set_terrain(
            gaia,
            this->world,
            0,
            0,
            (short)(this->map_width - 1),
            (short)(this->map_height - 1),
            1,
            0,
            0);
    }

    this->clear_stack();
    memset(this->terrain_table, 0, sizeof(this->terrain_table));

    for (long i = 0; i < this->info.object_num; ++i) {
        this->generate_objects(this->info.objects[i]);
    }

    if (this->map != nullptr && this->map->map_zones != nullptr) {
        this->map->map_zones->delete_zone_maps();
    }
    return 1;
}

void RGE_RMM_Object_Generator::generate_objects(RGE_Object_Info_Line& param_1) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00485E50
    if (param_1.scale_flag != 0) {
        long groups = (this->map_width * this->map_height * param_1.number_of_groups) / 0x5100;
        param_1.number_of_groups = groups;
        if (groups < 1) {
            param_1.number_of_groups = 1;
        }
    }

    if (param_1.land_id < 0) {
        if (param_1.land_id == -1) {
            this->place_objects(param_1);
            return;
        }
        if (param_1.land_id == -2) {
            this->place_avoid_objects(param_1, param_1.land_inner_radius);
        }
        return;
    }

    for (long i = 0; i < this->info.land_num; ++i) {
        if (this->info.lands[i].id == param_1.land_id) {
            this->place_land_objects(
                param_1,
                this->info.lands[i].x,
                this->info.lands[i].y,
                param_1.land_inner_radius,
                param_1.land_outer_radius,
                i);
        }
    }
}

void RGE_RMM_Object_Generator::make_placement_stack(
    Map_Stack& param_1,
    long param_2,
    long param_3,
    long param_4,
    long param_5) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00485F10
    (void)param_4;
    param_1.next = nullptr;
    param_1.prev = nullptr;

    if (this->search_map_rows == nullptr || this->stack_offsets == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0;
    long y0;
    long x1;
    long y1;

    if ((param_2 < 0) || (param_3 < 0) || (param_5 < 0)) {
        x0 = 0;
        y0 = 0;
        x1 = this->map_width - 1;
        y1 = this->map_height - 1;
    } else {
        x0 = param_2 - param_5;
        y0 = param_3 - param_5;
        x1 = param_2 + param_5;
        y1 = param_3 + param_5;
        if (x0 < 0) x0 = 0;
        if (y0 < 0) y0 = 0;
        if (x1 >= this->map_width) x1 = this->map_width - 1;
        if (y1 >= this->map_height) y1 = this->map_height - 1;
    }

    Map_Stack* last = &param_1;
    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            if (this->search_map_rows[y][x] != 0) {
                Map_Stack* node = &this->stack_offsets[y][x];
                this->add_stack_node(last, node);
                last = node;
            }
        }
    }

    long span_x = (x1 - x0) - 1;
    long span_y = (y1 - y0) - 1;
    if (span_x > 1 && span_y > 1) {
        long count = (span_y * span_x) / 4;
        while (count > 0) {
            long rx = rmm_obj_rand_scaled(span_x, 0xaf) + x0;
            long ry = rmm_obj_rand_scaled(span_y, 0xb0) + y0;
            if (rx >= 0 && ry >= 0 && rx < this->map_width && ry < this->map_height &&
                this->search_map_rows[ry][rx] != 0) {
                this->add_stack_node(&param_1, &this->stack_offsets[ry][rx]);
            }
            count = count - 1;
        }
    }
}

uchar RGE_RMM_Object_Generator::to_close(RGE_Object_Info_Line& param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486110
    for (long i = 0; i < this->info.land_num; ++i) {
        long dx = param_2 - this->info.lands[i].x;
        long dy = param_3 - this->info.lands[i].y;
        if (dx < 0) dx = -dx;
        if (dy < 0) dy = -dy;
        if (dx < param_1.land_inner_radius && dy < param_1.land_inner_radius) {
            return 1;
        }
    }
    return 0;
}

void RGE_RMM_Object_Generator::set_search_area(long param_1, long param_2, long param_3, uchar param_4) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486180
    if (this->search_map_rows == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_1 + param_3;
    long y1 = param_2 + param_3;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->search_map_rows[y][x] = param_4;
        }
    }
}

void RGE_RMM_Object_Generator::remove_area_from_lists(long param_1, long param_2, long param_3) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486210
    if (this->stack_offsets == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long x0 = param_1 - param_3;
    long y0 = param_2 - param_3;
    long x1 = param_1 + param_3;
    long y1 = param_2 + param_3;

    if (x0 < 0) x0 = 0;
    if (y0 < 0) y0 = 0;
    if (x1 >= this->map_width) x1 = this->map_width - 1;
    if (y1 >= this->map_height) y1 = this->map_height - 1;

    for (long y = y0; y <= y1; ++y) {
        for (long x = x0; x <= x1; ++x) {
            this->remove_stack_node(&this->stack_offsets[y][x]);
        }
    }
}

void RGE_RMM_Object_Generator::place_avoid_objects(RGE_Object_Info_Line& param_1, long param_2) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x004862B0
    (void)param_2;
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);
    for (long i = 0; i < this->info.land_num; ++i) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y, param_1.land_inner_radius, 0);
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    long player_index = (param_1.player_id < 0) ? 0 : param_1.player_id;
    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            player->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < player->master_object_num) {
            RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 0, 1);
                if (blocked == 0) {
                    this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                    if (param_1.group_flag == 0) {
                        player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    } else if (param_1.group_flag == 1) {
                        this->place_group(param_1, tile_x, tile_y, player);
                    } else if (param_1.group_flag == 2) {
                        this->place_cluster(param_1, tile_x, tile_y, player);
                    }
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& param_1) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x004864F0
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, -1, -1, -1, -1);

    long player_index = (param_1.player_id < 0) ? 0 : param_1.player_id;
    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            player->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < player->master_object_num) {
            RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 0, 1);
                if (blocked == 0) {
                    this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                    if (param_1.group_flag == 0) {
                        player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    } else if (param_1.group_flag == 1) {
                        this->place_group(param_1, tile_x, tile_y, player);
                    } else if (param_1.group_flag == 2) {
                        this->place_cluster(param_1, tile_x, tile_y, player);
                    }
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_land_objects(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    long param_4,
    long param_5,
    long param_6) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486700
    if (this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long min_x1 = param_2 - param_4;
    long min_y1 = param_3 - param_4;
    long min_y0 = param_2 + param_4;
    long local_28 = param_3 + param_4;

    if (min_x1 < 0) min_x1 = 0;
    if (min_y1 < 0) min_y1 = 0;
    if (min_y0 >= this->map_width) min_y0 = this->map_width - 1;
    if (local_28 >= this->map_height) local_28 = this->map_height - 1;

    memset(this->search_map, 1, (size_t)this->map_width * (size_t)this->map_height);
    for (long i = 0; i < this->info.land_num; ++i) {
        this->set_search_area(this->info.lands[i].x, this->info.lands[i].y, param_4, 0);
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, param_2, param_3, param_4, param_5);

    long player_index = param_1.player_id;
    if (player_index < 0) {
        player_index = 0;
        if (param_6 >= 0 && param_6 < this->info.land_num && this->info.lands[param_6].player_id > 0) {
            player_index = this->info.lands[param_6].player_id;
        }
    }

    RGE_Player* player = rmm_obj_get_player_safe(this, player_index);
    if (player == nullptr || player->master_objects == nullptr ||
        param_1.obj_id < 0 || param_1.obj_id >= player->master_object_num) {
        this->deinit_stack(&obj_stack);
        return;
    }

    RGE_Master_Static_Object* master = player->master_objects[param_1.obj_id];
    if (master == nullptr || this->map == nullptr || this->map->map_zones == nullptr ||
        this->world == nullptr || this->world->terrains == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    short terrain_index = master->terrain;
    if (terrain_index < 0 || terrain_index >= this->world->terrain_num) {
        this->deinit_stack(&obj_stack);
        return;
    }

    int zone_map_index = 0;
    RGE_Zone_Map* zone_map = this->map->map_zones->get_zone_map(this->world->terrains[terrain_index], 0x20, &zone_map_index);
    if (zone_map == nullptr) {
        this->deinit_stack(&obj_stack);
        return;
    }

    uchar center_zone = zone_map->get_zone_info(param_2, param_3);
    long remaining = param_1.number_of_groups;
    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);

    while (node != nullptr && remaining > 0) {
        uchar tile_zone = zone_map->get_zone_info(tile_x, tile_y);
        if (tile_zone == center_zone &&
            rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            (tile_x <= min_x1 ||
             ((min_y0 <= tile_x || tile_y <= min_y1) || (local_28 <= tile_y)))) {
            float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
            float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
            uchar blocked = master->check_placement(player, place_x, place_y, 0, 0, 1, 1, 1, 1, 1);
            if (blocked == 0) {
                this->remove_area_from_lists(tile_x, tile_y, param_1.object_exclusion_zone);
                if (param_1.group_flag == 0) {
                    player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                } else if (param_1.group_flag == 1) {
                    this->place_group(param_1, tile_x, tile_y, player);
                } else if (param_1.group_flag == 2) {
                    this->place_cluster(param_1, tile_x, tile_y, player);
                }
                remaining = remaining - 1;
            } else if (param_1.group_flag == 0 && obj_stack.prev == nullptr) {
                player->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
            }
        }

        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_group(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    RGE_Player* param_4) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486A60
    if (param_4 == nullptr) {
        return;
    }

    Map_Stack obj_stack;
    this->init_stack(&obj_stack);
    this->make_placement_stack(obj_stack, param_2, param_3, 0, param_1.group_area);

    long rv = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x212);
    long remaining = param_1.object_number_per_group +
        (long)(((long long)rv * (long long)param_1.object_number_varience * 2LL) / 0x7fffLL) -
        param_1.object_number_varience;
    if (remaining < 1) {
        remaining = 1;
    }

    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (rmm_obj_terrain_matches(this, param_1, tile_x, tile_y) != 0 &&
            param_4->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < param_4->master_object_num) {
            RGE_Master_Static_Object* master = param_4->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                if (master->check_placement(param_4, place_x, place_y, 0, 0, 1, 1, 1, 0, 1) == 0) {
                    param_4->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    remaining = remaining - 1;
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

void RGE_RMM_Object_Generator::place_cluster(
    RGE_Object_Info_Line& param_1,
    long param_2,
    long param_3,
    RGE_Player* param_4) {
    // Fully verified. Source of truth: rmm_obj.cpp.decomp @ 0x00486C40
    if (param_4 == nullptr || this->search_map_rows == nullptr || this->stack_offsets == nullptr) {
        return;
    }

    Map_Stack obj_stack;
    obj_stack.prev = nullptr;
    this->init_stack(&obj_stack);

    if (param_2 >= 0 && param_2 < this->map_width && param_3 >= 0 && param_3 < this->map_height) {
        this->add_stack_node(&obj_stack, &this->stack_offsets[param_3][param_2]);
    }

    long area = param_1.group_area;
    long min_y = param_3 - area;
    long max_x = param_2 + area;
    long max_y = param_3 + area;
    long min_x = param_2 - area;

    if (min_x < 0) min_x = 0;
    if (min_y < 0) min_y = 0;
    if (max_x >= this->map_width) max_x = this->map_width - 1;
    if (max_y >= this->map_height) max_y = this->map_height - 1;

    for (long y = min_y; y <= max_y; ++y) {
        for (long x = min_x; x <= max_x; ++x) {
            this->search_map_rows[y][x] = 1;
        }
    }

    long rv = (long)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x256);
    long remaining = param_1.object_number_per_group +
        (long)(((long long)rv * (long long)param_1.object_number_varience * 2LL) / 0x7fffLL) -
        param_1.object_number_varience;
    if (remaining < 1) {
        remaining = 1;
    }

    float pop_cost = 0.0f;
    long tile_x = 0;
    long tile_y = 0;
    Map_Stack* node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    while (node != nullptr && remaining > 0) {
        if (param_4->master_objects != nullptr &&
            param_1.obj_id >= 0 && param_1.obj_id < param_4->master_object_num) {
            RGE_Master_Static_Object* master = param_4->master_objects[param_1.obj_id];
            if (master != nullptr) {
                float place_x = rmm_obj_adjust_coord((float)tile_x, master->radius_x);
                float place_y = rmm_obj_adjust_coord((float)tile_y, master->radius_y);
                master->alignment(&place_x, &place_y, this->world, 1);
                if (master->check_placement(param_4, place_x, place_y, 0, 0, 1, 1, 1, 0, 1) == 0) {
                    param_4->make_new_object(param_1.obj_id, place_x, place_y, 0.0f, 1);
                    remaining = remaining - 1;
                    if (tile_x >= 0 && tile_x < this->map_width && tile_y >= 0 && tile_y < this->map_height) {
                        this->search_map_rows[tile_y][tile_x] = 0;
                    }

                    if ((min_x < tile_x) && this->search_map_rows[tile_y][tile_x - 1] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x - 1,
                            tile_y,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x270));
                    }
                    if ((tile_x < max_x) && this->search_map_rows[tile_y][tile_x + 1] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x + 1,
                            tile_y,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x273));
                    }
                    if ((min_y < tile_y) && this->search_map_rows[tile_y - 1][tile_x] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x,
                            tile_y - 1,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x276));
                    }
                    if ((tile_y < max_y) && this->search_map_rows[tile_y + 1][tile_x] != 0) {
                        this->push_stack(
                            &obj_stack,
                            tile_x,
                            tile_y + 1,
                            0.0f,
                            (float)debug_rand("C:\\msdev\\work\\age1_x1\\rmm_obj.cpp", 0x279));
                    }
                }
            }
        }
        node = this->pop_stack(&obj_stack, &tile_x, &tile_y, &pop_cost);
    }

    this->deinit_stack(&obj_stack);
}

