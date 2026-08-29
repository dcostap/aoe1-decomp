
#include "../include/t_b_obj.h"
#include "../include/act_list.h"
#include "../include/basegame.h"
#include "../include/dpl_obj.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/tact_mob.h"
#include "../include/tact_tek.h"
#include "../include/tech.h"
#include "../include/tplayer.h"
#include "../include/tribegam.h"
#include "../include/tworld.h"
#include "../include/world.h"

#include <stdlib.h>

extern "C" {
    int debug_rand(const char*, int);
}


static TRIBE_Player* tribe_player(RGE_Player* player)
{
    return static_cast<TRIBE_Player*>(player);
}

static TRIBE_Master_Building_Object* building_master(
    TRIBE_Building_Object* object)
{
    return static_cast<TRIBE_Master_Building_Object*>(object->master_obj);
}

static TRIBE_Game* tribe_game()
{
    return static_cast<TRIBE_Game*>(rge_base_game);
}

static void adjust_pop_waiting(RGE_Player* player, int delta)
{
    short id = player->id;
    tribe_game()->queue_is_waiting_on_pop_counter[id] += delta;
}

static unsigned char tile_terrain(RGE_Tile* tile)
{
    return (unsigned char)(tile->terrain_type | (tile->height << 5));
}

static void set_tile_terrain(RGE_Tile* tile, unsigned char value)
{
    tile->terrain_type = value & 0x1F;
    tile->height = value >> 5;
}

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* master, RGE_Player* player,
    float x, float y, float z, int unique_id, int do_setup)
    : TRIBE_Combat_Object(master, player, x, y, z, 0),
      production_queue(0), production_queue_size(0),
      production_queue_count(0), production_queue_enabled(1),
      production_queue_actions(0), production_queue_change_flag(0),
      production_queue_auto_paused(0), production_queue_need_attr(-1),
      build_pts(0), unique_build_id(unique_id), culture(0), built(0),
      DoppleInstalled(0), PriorMap1(0), PriorMap2(0), PriorMap3(0),
      PriorTurn1(0), PriorTurn2(0), PriorTurn3(0)
{
    if (do_setup != 0) {
        setup(master, player, x, y, z);
    }

    RGE_Master_Static_Object* master_object = this->master_obj;
    if (master_object->id == 0x114) {
        set_task(master_object->copy_id);
    }

    int row = (int)world_y;
    int col = (int)world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);
}

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* master, RGE_Player* player,
    float x, float y, float z, int do_setup)
    : TRIBE_Combat_Object(master, player, x, y, z, 0),
      production_queue(0), production_queue_size(0),
      production_queue_count(0), production_queue_enabled(1),
      production_queue_actions(0), production_queue_change_flag(0),
      production_queue_auto_paused(0), production_queue_need_attr(-1),
      build_pts(0), unique_build_id(-1), culture(0), built(0),
      DoppleInstalled(0), PriorMap1(0), PriorMap2(0), PriorMap3(0),
      PriorTurn1(0), PriorTurn2(0), PriorTurn3(0)
{
    if (do_setup != 0) {
        setup(master, player, x, y, z);
    }

    int row = (int)world_y;
    int col = (int)world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);
}

TRIBE_Building_Object::TRIBE_Building_Object(
    int mode, RGE_Game_World* world, int do_setup)
    : TRIBE_Combat_Object(mode, world, 0),
      production_queue(0), production_queue_size(0),
      production_queue_count(0), production_queue_enabled(1),
      production_queue_actions(0), production_queue_change_flag(0),
      production_queue_auto_paused(0), production_queue_need_attr(-1),
      build_pts(0), unique_build_id(-1), culture(0), built(0),
      DoppleInstalled(0), PriorMap1(0), PriorMap2(0), PriorMap3(0),
      PriorTurn1(0), PriorTurn2(0), PriorTurn3(0)
{
    if (do_setup != 0) {
        setup(mode, world);
    }

    int row = (int)world_y;
    int col = (int)world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(
        this, unified_map_offsets[row] + col);
}

TRIBE_Building_Object::~TRIBE_Building_Object()
{
    owner->doppleganger_creator->remove_doppleganger_check(this);

    if (production_queue_actions != 0) {
        delete production_queue_actions;
        production_queue_actions = 0;
    }

    if (production_queue != 0) {
        free(production_queue);
        production_queue = 0;
        if (production_queue_need_attr == 4) {
            production_queue_need_attr = -1;
            adjust_pop_waiting(owner, -1);
        }
    }
}

void TRIBE_Building_Object::recycle_out_of_game()
{
    if (production_queue_actions != 0) {
        production_queue_actions->delete_list();
    }

    if (production_queue != 0) {
        free(production_queue);
        production_queue = 0;
        production_queue_size = 0;
        production_queue_count = 0;
        production_queue_enabled = 1;
        production_queue_change_flag = 0;
        production_queue_auto_paused = 0;
        production_queue_need_attr = -1;
    }

    RGE_Action_Object::recycle_out_of_game();
}

int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* master,
                                 RGE_Player* player, float x, float y, float z)
{
    built = 0;
    TRIBE_Combat_Object::setup(master, player, x, y, z);
    type = 0x50;
    set_object_state(0);

    if (building_master(this)->build_pts_required > 0) {
        new_sprite(building_master(this)->construction_sprite);
    }

    build_pts = 0;
    hp = 1.0f;
    facet = (unsigned char)building_master(this)->building_facet;
    culture = player->culture;

    static_cast<TRIBE_World*>(owner->world)->check_destructables(
        player->id, building_master(this)->id, world_y, world_x, 0);
    production_queue_actions = create_action_list();
    return 1;
}

int TRIBE_Building_Object::setup(int fd, RGE_Game_World* world_arg)
{
    TRIBE_Combat_Object::setup(fd, world_arg);
    type = 0x50;
    rge_read(fd, &built, 1);
    rge_read(fd, &build_pts, 4);
    rge_read(fd, &unique_build_id, 4);
    rge_read(fd, &culture, 1);
    production_queue_actions = create_action_list();

    if (save_game_version >= 7.21f) {
        rge_read(fd, &production_queue_size, 2);
        if (production_queue_size > 0) {
            production_queue = static_cast<Production_Queue_Record*>(calloc(
                production_queue_size, sizeof(Production_Queue_Record)));
            for (short i = 0; i < production_queue_size; ++i) {
                rge_read(fd, &production_queue[i].master_id, 2);
                rge_read(fd, &production_queue[i].unit_count, 2);
            }
        }
        rge_read(fd, &production_queue_count, 2);
        rge_read(fd, &production_queue_enabled, 1);
        production_queue_actions->load(fd);
    }
    return 1;
}

void TRIBE_Building_Object::take_building_attribute_from_owner()
{
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = master_obj;
        if (master->attribute_flag[i] > 3 &&
            master->attribute_type_held[i] >= 0) {
            owner->add_attribute_num(master->attribute_type_held[i],
                                     -master->attribute_amount_held[i], 0);
        }
    }
}

void TRIBE_Building_Object::give_building_attribute_to_owner()
{
    for (int i = 0; i < 3; ++i) {
        RGE_Master_Static_Object* master = master_obj;
        if (master->attribute_flag[i] > 3 &&
            master->attribute_type_held[i] >= 0) {
            owner->add_attribute_num(master->attribute_type_held[i],
                                     master->attribute_amount_held[i], 0);
        }
    }
}

void TRIBE_Building_Object::destroy_obj()
{
    die_die_die();
    RGE_Action_Object::destroy_obj();
    owner->doppleganger_creator->remove_doppleganger_check(this);
    DoppleInstalled = 0;
}

unsigned char TRIBE_Building_Object::heal(float amount)
{
    TRIBE_Master_Building_Object* master = building_master(this);
    float max_hp = (float)(int)master->hp;
    float required = max_hp * amount / (float)(int)master->build_pts_required;
    if (required + hp > max_hp) {
        required = max_hp - hp;
    }

    if (tribe_player(owner)->pay_obj_cost(
            master->id, required / (float)((int)master->hp * 2), 0) == 0) {
        return 2;
    }
    return TRIBE_Combat_Object::heal(required);
}

void TRIBE_Building_Object::set_object_state(unsigned char state)
{
    unsigned char dopple_removed;

    if (state == 2) {
        build_pts = (float)(int)building_master(this)->build_pts_required;

        int random_value = debug_rand(
            "C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x12B);
        int old_random = debug_random_on;
        debug_random_on = 0;

        RGE_Sound* sound = building_master(this)->construction_sound;
        if (sound != 0 && owner->id == owner->world->curr_player) {
            sound->play(1);
        }

        debug_random_on = old_random;
        debug_srand("C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 0x135,
                    random_value);

        built = 1;
        give_building_attribute_to_owner();

        if (building_master(this)->build_and_go_away != 0) {
            die_die_die();
        } else {
            unexplore_terrain(owner, 1, -1);
            explore_terrain(owner, 0, -1);
            new_sprite(building_master(this)->construction_sprite);
            facet = (unsigned char)building_master(this)->building_facet;
            if (building_master(this)->building_connect_flag != 0) {
                connect();
            }
        }

        if (building_master(this)->on_build_make_obj >= 0) {
            owner->master_objects[building_master(this)->on_build_make_obj]->make_new_obj(
                owner, world_x, world_y, world_z);
        }

        if (building_master(this)->on_build_make_tile >= 0) {
            RGE_Game_World* build_world = owner->world;
            RGE_Map* build_map = build_world->map;
            short x1 = (short)(world_x - building_master(this)->radius_x);
            short y1 = (short)(world_y - building_master(this)->radius_y);
            short x2 = (short)(world_x + building_master(this)->radius_x - DAT_005749e8);
            short y2 = (short)(world_y + building_master(this)->radius_y - DAT_005749e8);
            build_map->set_terrain(build_world->players[0], build_world,
                                   y1, x1, y2, x2,
                                   (unsigned char)building_master(this)->on_build_make_tile,
                                   1, 0);
            build_map->request_redraw(x1 - 1, y1 - 1,
                                      x2 + 1, y2 + 1, 0);
        }

        if (building_master(this)->on_build_make_tech >= 0) {
            tribe_player(owner)->tech_tree->do_tech(
                building_master(this)->on_build_make_tech);
        }

        rge_base_game->notification(0x69, owner->id, building_master(this)->id,
                                    (long)world_x, (long)world_y);
        tribe_player(owner)->registerBuild(this, unique_build_id);
    }

    if (state == 3 && object_state == 2) {
        take_building_attribute_from_owner();
        owner->doppleganger_creator->remove_doppleganger_check(this);
        DoppleInstalled = 0;
        dopple_removed = 1;
    } else {
        dopple_removed = 0;
    }

    RGE_Static_Object::set_object_state(state);

    if (dopple_removed != 0) {
        RGE_Static_Object* object = owner->objects->find_by_master_id(
            building_master(this)->id, -1.0f, -1.0f, 1, 2, 0);
        if (object == 0) {
            if (building_master(this)->on_build_make_tech >= 0) {
                tribe_player(owner)->tech_tree->undo_tech(
                    building_master(this)->on_build_make_tech);
            }
            tribe_player(owner)->tech_tree->undo_tech(0x4A);
            tribe_player(owner)->tech_tree->undo_tech(0x4B);
            tribe_player(owner)->tech_tree->undo_tech(0x4C);
        }
    }
}

void TRIBE_Building_Object::rehook()
{
    RGE_Action_Object::rehook();
    production_queue_actions->rehook();
}

unsigned char TRIBE_Building_Object::update()
{
    if (object_state == 0) {
        short max_value = building_master(this)->center_tile_req2;
        int build_time = building_master(this)->build_pts_required;
        unsigned char result = (unsigned char)((long)(
            (float)(int)max_value * build_pts / (float)build_time));

        if ((short)result < max_value && result != facet) {
            facet = result;
        }
        if ((float)build_time <= build_pts) {
            set_object_state(2);
        }
    }

    PriorMap3 = PriorMap2;
    PriorMap2 = PriorMap1;
    PriorTurn3 = PriorTurn2;
    PriorTurn2 = PriorTurn1;
    PriorTurn1 = world_update_counter;

    unsigned char result = TRIBE_Combat_Object::update();
    if (object_state > 2) {
        empty_production_queue();
    } else {
        update_production_queue();
    }
    PriorMap1 = Unified_Map_Value;
    return result;
}

int TRIBE_Building_Object::explore_terrain(RGE_Player* player,
                                           unsigned char value, int param)
{
    if (built != 0) {
        return RGE_Static_Object::explore_terrain(player, value, param);
    }
    return RGE_Static_Object::explore_terrain(player, 1, param);
}

void TRIBE_Building_Object::save(int fd)
{
    TRIBE_Combat_Object::save(fd);
    rge_write(fd, &built, 1);
    rge_write(fd, &build_pts, 4);
    rge_write(fd, &unique_build_id, 4);
    rge_write(fd, &culture, 1);
    rge_write(fd, &production_queue_size, 2);
    for (short i = 0; i < production_queue_size; ++i) {
        rge_write(fd, &production_queue[i].master_id, 2);
        rge_write(fd, &production_queue[i].unit_count, 2);
    }
    rge_write(fd, &production_queue_count, 2);
    rge_write(fd, &production_queue_enabled, 1);
    production_queue_actions->save(fd);
}

void TRIBE_Building_Object::change_ownership(RGE_Player* player)
{
    if (object_state == 2) {
        for (int i = 0; i < 3; ++i) {
            RGE_Master_Static_Object* master = master_obj;
            if (master->attribute_flag[i] > 3 &&
                master->attribute_type_held[i] >= 0) {
                owner->add_attribute_num(master->attribute_type_held[i],
                                         -master->attribute_amount_held[i], 0);
            }
        }
    }

    if (object_state == 0) {
        unexplore_terrain(owner, 1, -1);
    }

    if (production_queue_count > 0) {
        if (production_queue_need_attr == 4) {
            production_queue_need_attr = -1;
            adjust_pop_waiting(owner, -1);
        }
        production_queue_count = 1;
        production_queue->unit_count = 1;
    }

    production_queue_actions->delete_list();
    TRIBE_Combat_Object::change_ownership(player);

    if (object_state == 0) {
        explore_terrain(owner, 1, -1);
    }

    if (object_state == 2) {
        if (building_master(this)->on_build_make_tile >= 0) {
            owner->master_objects[building_master(this)->on_build_make_tile]->make_new_obj(
                owner, world_x, world_y, world_z);
        }
        if (building_master(this)->on_build_make_tech >= 0) {
            tribe_player(owner)->tech_tree->do_tech(
                building_master(this)->on_build_make_tech);
        }
        give_building_attribute_to_owner();
    }
}

void TRIBE_Building_Object::modify(float value, unsigned char attribute)
{
    if (attribute != 0x11) {
        TRIBE_Combat_Object::modify(value, attribute);
        return;
    }
    facet = (unsigned char)value;
}

void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* master)
{
    TRIBE_Combat_Object::transform(master);
    built = 0;
    if (master->build_pts_required > 0) {
        new_sprite(master->construction_sprite);
    }
    build_pts = 0;
}

long TRIBE_Building_Object::check(TRIBE_Building_Object** out)
{
    RGE_Map* map = owner->world->map;
    short x = (short)world_x;
    short y = (short)world_y;
    short max_x = (short)map->map_width - 1;
    short max_y = (short)map->map_height - 1;
    long count = 0;

    if (y > 0) {
        out[0] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y - 1][x].objects
            .find_by_master_id(building_master(this)->id, -1.0f, -1.0f, 0, 0, 0));
        if (out[0] != 0 && out[0]->owner == owner) {
            ++count;
        } else {
            out[0] = 0;
        }
    } else {
        out[0] = 0;
    }

    if (x > 0) {
        out[1] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y][x - 1].objects
            .find_by_master_id(building_master(this)->id, -1.0f, -1.0f, 0, 0, 0));
        if (out[1] != 0 && out[1]->owner == owner) {
            ++count;
        } else {
            out[1] = 0;
        }
    } else {
        out[1] = 0;
    }

    if (x < max_x) {
        out[2] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y][x + 1].objects
            .find_by_master_id(building_master(this)->id, -1.0f, -1.0f, 0, 0, 0));
        if (out[2] != 0 && out[2]->owner == owner) {
            ++count;
        } else {
            out[2] = 0;
        }
    } else {
        out[2] = 0;
    }

    if (y < max_y) {
        out[3] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y + 1][x].objects
            .find_by_master_id(building_master(this)->id, -1.0f, -1.0f, 0, 0, 0));
        if (out[3] != 0 && out[3]->owner == owner) {
            return count + 1;
        }
        out[3] = 0;
    } else {
        out[3] = 0;
    }
    return count;
}

void TRIBE_Building_Object::connect()
{
    if (this->master_obj == 0) {
        return;
    }
    if (building_master(this)->center_tile_req2 != 3) {
        facet = 0;
        return;
    }

    set_angle();
    TRIBE_Building_Object* checks[4];
    check(checks);

    if (checks[0] != 0 && checks[3] != 0 &&
        checks[1] == 0 && checks[2] == 0) {
        rotate(1 - facet);
    } else if (checks[1] != 0 && checks[2] != 0 &&
               checks[0] == 0 && checks[3] == 0) {
        rotate(-facet);
    } else {
        rotate(2 - facet);
    }

    if (checks[0] != 0) checks[0]->connect2();
    if (checks[1] != 0) checks[1]->connect2();
    if (checks[2] != 0) checks[2]->connect2();
    if (checks[3] != 0) checks[3]->connect2();
}

void TRIBE_Building_Object::connect2()
{
    if (this->master_obj == 0) {
        return;
    }
    if (building_master(this)->center_tile_req2 != 3) {
        facet = 0;
        return;
    }

    TRIBE_Building_Object* checks[4];
    check(checks);
    if (checks[0] != 0 && checks[3] != 0 &&
        checks[1] == 0 && checks[2] == 0) {
        rotate(1 - facet);
    } else if (checks[1] != 0 && checks[2] != 0 &&
               checks[0] == 0 && checks[3] == 0) {
        rotate(-facet);
    } else {
        rotate(2 - facet);
    }
}

void TRIBE_Building_Object::lay_down_impassable_terrain()
{
    RGE_Map* map = owner->world->map;
    if (building_master(this)->on_build_make_tile >= 0) {
        return;
    }

    short x1 = (short)(world_x - building_master(this)->radius_x);
    short x2 = (short)(world_x + building_master(this)->radius_x - 10.0f);
    short y1 = (short)(world_y - building_master(this)->radius_y);
    short y2 = (short)(world_y + building_master(this)->radius_y - 10.0f);
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= map->map_width) x2 = (short)map->map_width - 1;
    if (y2 >= map->map_height) y2 = (short)map->map_height - 1;

    for (short y = y1; y <= y2; ++y) {
        for (short x = x1; x <= x2; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            unsigned char terrain = tile_terrain(tile);
            switch (terrain & 0x1F) {
            case 0:
                set_tile_terrain(tile, (terrain & 0xF0) | 0x10);
                break;
            case 1:
                set_tile_terrain(tile, (terrain & 0xEF) | 0x0F);
                break;
            case 6:
                set_tile_terrain(tile, (terrain & 0xEE) | 0x0E);
                break;
            default:
                break;
            }
        }
    }
}

void TRIBE_Building_Object::lay_down_passable_terrain()
{
    RGE_Map* map = owner->world->map;
    if (building_master(this)->on_build_make_tile >= 0) {
        return;
    }

    short x1 = (short)(world_x - building_master(this)->radius_x);
    short x2 = (short)(world_x + building_master(this)->radius_x - 10.0f);
    short y1 = (short)(world_y - building_master(this)->radius_y);
    short y2 = (short)(world_y + building_master(this)->radius_y - 10.0f);
    if (x1 < 0) x1 = 0;
    if (y1 < 0) y1 = 0;
    if (x2 >= map->map_width) x2 = (short)map->map_width - 1;
    if (y2 >= map->map_height) y2 = (short)map->map_height - 1;

    for (short y = y1; y <= y2; ++y) {
        for (short x = x1; x <= x2; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            unsigned char terrain = tile_terrain(tile);
            switch (terrain & 0x1F) {
            case 0x0E:
                set_tile_terrain(tile, (terrain & 0xE6) | 6);
                break;
            case 0x0F:
                set_tile_terrain(tile, (terrain & 0xE1) | 1);
                break;
            case 0x10:
                set_tile_terrain(tile, terrain & 0xE0);
                break;
            default:
                break;
            }
        }
    }
}

void TRIBE_Building_Object::cancel_object()
{
    if (object_state < 2) {
        cancel_build();
    } else {
        TRIBE_Combat_Object::cancel_object();
    }
}

void TRIBE_Building_Object::cancel_build()
{
    if ((selected & 1) != 0) {
        owner->unselect_one_object(this);
    }

    float percent;
    if (object_state >= 2 || hp <= DAT_005749f4) {
        percent = 0.0f;
    } else {
        percent = ((float)(int)building_master(this)->build_pts_required - build_pts) /
                  (float)(int)building_master(this)->build_pts_required * DAT_005749f8;
    }
    if (percent > DAT_00574a00) {
        percent = 1.0f;
    }

    for (int i = 0; i < 3; ++i) {
        if (building_master(this)->build_inventory[i].type >= 0 &&
            building_master(this)->build_inventory[i].flag != 0) {
            owner->add_attribute_num(
                building_master(this)->build_inventory[i].type,
                (float)(int)building_master(this)->build_inventory[i].amount * percent, 0);
        }
    }
    hp = 0.0f;
}

unsigned char TRIBE_Building_Object::build(float amount)
{
    if (object_state != 0) {
        return 1;
    }

    float needed = (float)(int)building_master(this)->build_pts_required;
    if (amount + build_pts > needed) {
        amount = needed - build_pts;
    }
    hp = (float)(int)building_master(this)->hp * amount / needed + hp;
    if (hp > (float)(int)building_master(this)->hp) {
        hp = (float)(int)building_master(this)->hp;
    }
    build_pts += amount;
    if (build_pts >= needed) {
        set_object_state(2);
        return 1;
    }
    return 0;
}

int TRIBE_Building_Object::work_status(short& type_out, short& p2,
                                       short& p3, char* p4, short p5)
{
    RGE_Action* action = actions->get_action();
    if (action != 0) {
        type_out = action->action_type;
    } else {
        type_out = 0;
    }

    if (type_out == 0x66) {
        static_cast<TRIBE_Action_Make_Obj*>(action)->get_info(p2, p3, p4, p5);
        return 1;
    }
    if (type_out == 0x67) {
        static_cast<TRIBE_Action_Make_Tech*>(action)->get_info(p2, p3, p4, p5);
        return 1;
    }
    p2 = -1;
    p3 = 0;
    if (p4 != 0) *p4 = 0;
    return 0;
}

short TRIBE_Building_Object::get_construction_progress()
{
    if (built != 0 || building_master(this)->build_pts_required == 0) {
        return 100;
    }
    return (short)(build_pts /
                   (float)(int)building_master(this)->build_pts_required * 100.0f);
}

void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* source)
{
    TRIBE_Master_Building_Object* master =
        static_cast<TRIBE_Master_Building_Object*>(source);
    if (sprite == master->construction_sprite) {
        new_sprite(master->construction_sprite);
    }
    RGE_Action_Object::copy_obj(source);
    if (master->building_connect_flag != 0) {
        connect();
    }
}

void TRIBE_Building_Object::rotate(long)
{
}

void TRIBE_Building_Object::damage(int param_1,
                                   RGE_Armor_Weapon_Info* param_2,
                                   float param_3, RGE_Player* param_4,
                                   RGE_Static_Object* param_5)
{
    float old_hp = hp;
    if (hp <= DAT_005749f4) {
        return;
    }

    RGE_Combat_Object::damage(param_1, param_2, param_3, param_4, param_5);
    RGE_Master_Static_Object* master = param_5->master_obj;
    short group = master->object_group;
    float damage_taken = old_hp - hp;

    if (group == 0 || group == 0x17 || group == 0x24 || group == 0x1A ||
        master->id == 0x4F || master->id == 0x45 || master->id == 0xC7 ||
        master->id == 0x17F || master->id == 0x17C) {
        if (damage_taken < DAT_00574a10) {
            hp = old_hp - DAT_00574a18;
        }
    } else if (damage_taken < DAT_00574a00) {
        hp = old_hp - DAT_00574a08;
    }

    if (owner->id > 0 && hp < DAT_00574a00) {
        param_4->add_attribute_num(0x2B, 1.0f, 0);
    }
}

void TRIBE_Building_Object::add_to_production_queue(short master_id,
                                                     short count)
{
    short queue_count = production_queue_count;
    unsigned char changed = 0;

    if (queue_count > 0 &&
        production_queue[queue_count - 1].master_id == master_id) {
        for (short i = 0; i < count; ++i) {
            short id = master_id;
            if (tribe_player(owner)->check_obj_cost(id, &id, 1.0f, 1) == 0) {
                rge_base_game->notification(0x7D, owner->id, id, 0, 0);
                break;
            }
            tribe_player(owner)->pay_obj_cost(master_id, 1.0f, 1);
            production_queue[production_queue_count - 1].unit_count++;
            changed = 1;
        }
        if (changed != 0) {
            production_queue_change_flag++;
            rge_base_game->notification(0x7C, owner->id, 0, 0, 0);
        }
        return;
    }

    while (queue_count > 0) {
        remove_from_production_queue(production_queue[0].master_id, 1);
        queue_count = production_queue_count;
    }

    short id = master_id;
    if (tribe_player(owner)->check_obj_cost(id, &id, 1.0f, 1) == 0) {
        rge_base_game->notification(0x7D, owner->id, id, 0, 0);
        return;
    }

    if (production_queue_count == production_queue_size) {
        Production_Queue_Record* new_queue =
            static_cast<Production_Queue_Record*>(calloc(
                production_queue_size + 10, sizeof(Production_Queue_Record)));
        if (new_queue == 0) return;
        for (short i = 0; i < production_queue_size; ++i) {
            new_queue[i] = production_queue[i];
        }
        free(production_queue);
        production_queue = new_queue;
        production_queue_size += 10;
    }

    production_queue[production_queue_count].unit_count = 0;
    for (short i = 0; i < count; ++i) {
        short check_id = master_id;
        if (tribe_player(owner)->check_obj_cost(
                check_id, &check_id, 1.0f, 1) == 0) {
            rge_base_game->notification(0x7D, owner->id, check_id, 0, 0);
            break;
        }
        tribe_player(owner)->pay_obj_cost(master_id, 1.0f, 1);
        production_queue[production_queue_count].unit_count++;
    }
    production_queue[production_queue_count].master_id = master_id;
    production_queue_count++;
    production_queue_change_flag++;
    rge_base_game->notification(0x7C, owner->id, 0, 0, 0);
}

void TRIBE_Building_Object::remove_from_production_queue(short master_id,
                                                          short max_remove)
{
    if (production_queue_count == 0) {
        return;
    }

    short index = production_queue_count - 1;
    while (index >= 0 && production_queue[index].master_id != master_id) {
        --index;
    }
    if (index < 0) {
        return;
    }

    short remove_count = max_remove;
    if (production_queue[index].unit_count <= max_remove) {
        remove_count = production_queue[index].unit_count;
    }
    while (remove_count > 0) {
        tribe_player(owner)->reimburse_obj_cost(master_id);
        --remove_count;
    }

    production_queue[index].unit_count -= max_remove;
    production_queue_change_flag++;
    if (production_queue[index].unit_count <= 0) {
        --production_queue_count;
        for (short i = index; i < production_queue_count; ++i) {
            production_queue[i] = production_queue[i + 1];
        }
        if (index == 0) {
            if (production_queue_need_attr == 4) {
                adjust_pop_waiting(owner, -1);
                production_queue_need_attr = -1;
            }
            production_queue_actions->action_stop();
            production_queue_actions->delete_list();
        }
    }
    rge_base_game->notification(0x7C, owner->id, 0, 0, 0);
}

void TRIBE_Building_Object::advance_production_queue()
{
    if (production_queue_count == 0) {
        return;
    }

    --production_queue->unit_count;
    production_queue_change_flag++;
    if (production_queue->unit_count <= 0) {
        --production_queue_count;
        for (short i = 0; i < production_queue_count; ++i) {
            production_queue[i] = production_queue[i + 1];
        }
    }
    rge_base_game->notification(0x7C, owner->id, 0, 0, 0);
}

void TRIBE_Building_Object::empty_production_queue()
{
    if (production_queue_need_attr == 4) {
        adjust_pop_waiting(owner, -1);
        production_queue_need_attr = -1;
    }
    production_queue_count = 0;
    production_queue_actions->delete_list();
    production_queue_change_flag++;
}

void TRIBE_Building_Object::enable_production_queue(int enabled)
{
    production_queue_enabled = (unsigned char)enabled;
}

void TRIBE_Building_Object::update_production_queue()
{
    short work_type;
    short unused_1;
    short unused_2;

    if (production_queue_enabled == 0 || production_queue_count == 0) {
        if (production_queue_need_attr == 4) {
            adjust_pop_waiting(owner, -1);
            production_queue_need_attr = -1;
        }
        return;
    }

    if (work_status(work_type, unused_1, unused_2, 0, 0) != 0 &&
        (work_type == 0x66 || work_type == 0x67)) {
        while (production_queue_count > 0) {
            remove_from_production_queue(production_queue->master_id, -1);
        }
        return;
    }

    if (production_queue_actions->list == 0) {
        float* attributes = owner->attributes;
        if (attributes[0x2C / 4] < attributes[0x80 / 4]) {
            if (production_queue_need_attr == 0x20) {
                return;
            }
            production_queue_need_attr = 0x20;
            rge_base_game->notification(0x7D, owner->id, 0x20, 0, 0);
            return;
        }

        if (attributes[0x10 / 4] > DAT_005749f4) {
            if (production_queue_need_attr == 4) {
                adjust_pop_waiting(owner, -1);
            }
            production_queue_need_attr = -1;
            TRIBE_Action_Make_Obj* action =
                new TRIBE_Action_Make_Obj(this,
                                           production_queue->master_id, -1, 1);
            if (action != 0) {
                production_queue_actions->add_action(action);
            }
        } else {
            if (production_queue_need_attr == 4) {
                return;
            }
            production_queue_need_attr = 4;
            rge_base_game->notification(0x7D, owner->id, 4, 0, 0);
            adjust_pop_waiting(owner, 1);
            return;
        }
    }

    unsigned char action_state = production_queue_actions->update();
    if (action_state == 3 || action_state == 2 || action_state == 1) {
        production_queue_actions->remove_action();
        advance_production_queue();
    }
}

int TRIBE_Building_Object::production_queue_status(short& type_out,
                                                   short& count_out)
{
    type_out = -1;
    count_out = 0;

    TRIBE_Action_Make_Obj* action = static_cast<TRIBE_Action_Make_Obj*>(
        production_queue_actions->get_action());
    if (action != 0 && action->action_type == 0x66) {
        action->get_info(type_out, count_out, 0, 0);
        return 1;
    }

    if (production_queue_count > 0) {
        type_out = production_queue->master_id;
        return 1;
    }
    return 0;
}

void TRIBE_Building_Object::stop()
{
    RGE_Combat_Object::stop();
    while (production_queue_count > 0) {
        remove_from_production_queue(production_queue->master_id, 1);
    }
}
