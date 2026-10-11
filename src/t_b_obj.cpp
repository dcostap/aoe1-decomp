
#include "../include/t_b_obj.h"
#include "../include/act_list.h"
#include "../include/basegame.h"
#include "../include/dpl_obj.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/rge_base_game_global.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/sprite.h"
#include "../include/tact_mob.h"
#include "../include/tact_tek.h"
#include "../include/tech.h"
#include "../include/tplayer.h"
#include "../include/tribegam.h"
#include "../include/tworld.h"
#include "../include/world.h"

#include <stdlib.h>

int debug_rand(char*, int);

static TRIBE_Game* tribe_game() {
    return static_cast<TRIBE_Game*>(rge_base_game);
}

static void adjust_pop_waiting(RGE_Player* player, int delta) {
    short id = player->id;
    tribe_game()->queue_is_waiting_on_pop_counter[id] += delta;
}

static unsigned char tile_terrain(RGE_Tile* tile) {
    return (unsigned char) (tile->terrain_type | (tile->height << 5));
}

static void set_tile_terrain(RGE_Tile* tile, unsigned char value) {
    tile->terrain_type = value & 0x1F;
    tile->height = value >> 5;
}

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int uID, int do_setup
) :
    TRIBE_Combat_Object(tobj, obj_owner, x, y, z, 0), production_queue(0), production_queue_size(0),
    production_queue_count(0), production_queue_enabled(1), production_queue_actions(0),
    production_queue_change_flag(0), production_queue_auto_paused(0), production_queue_need_attr(-1),
    unique_build_id(uID), DoppleInstalled(0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }

    TRIBE_Master_Building_Object* master_object = static_cast<TRIBE_Master_Building_Object*>(this->master_obj);
    if (master_object->id == MASTER_OBJECT_WONDER) {
        set_task(master_object->default_task);
    }

    int row = (int) world_y;
    int col = (int) world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(this, unified_map_offsets[row] + col);
    PriorMap1 = 0;
    PriorMap2 = 0;
    PriorMap3 = 0;
    PriorTurn1 = 0;
    PriorTurn2 = 0;
    PriorTurn3 = 0;
}

TRIBE_Building_Object::TRIBE_Building_Object(
    TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup
) :
    TRIBE_Combat_Object(tobj, obj_owner, x, y, z, 0), production_queue(0), production_queue_size(0),
    production_queue_count(0), production_queue_enabled(1), production_queue_actions(0),
    production_queue_change_flag(0), production_queue_auto_paused(0), production_queue_need_attr(-1),
    unique_build_id(-1), DoppleInstalled(0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }

    int row = (int) world_y;
    int col = (int) world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(this, unified_map_offsets[row] + col);
    PriorMap1 = 0;
    PriorMap2 = 0;
    PriorMap3 = 0;
    PriorTurn1 = 0;
    PriorTurn2 = 0;
    PriorTurn3 = 0;
}

TRIBE_Building_Object::TRIBE_Building_Object(int infile, RGE_Game_World* gworld, int do_setup) :
    TRIBE_Combat_Object(infile, gworld, 0), production_queue(0), production_queue_size(0), production_queue_count(0),
    production_queue_enabled(1), production_queue_actions(0), production_queue_change_flag(0),
    production_queue_auto_paused(0), production_queue_need_attr(-1), DoppleInstalled(0) {
    if (do_setup != 0) {
        setup(infile, gworld);
    }

    int row = (int) world_y;
    int col = (int) world_x;
    DoppleInstalled = owner->doppleganger_creator->add_doppleganger_check(this, unified_map_offsets[row] + col);
}

TRIBE_Building_Object::~TRIBE_Building_Object() {
    owner->doppleganger_creator->remove_doppleganger_check(this);

    if (production_queue_actions != 0) {
        delete production_queue_actions;
        production_queue_actions = 0;
    }

    if (production_queue != 0) {
        free(production_queue);
        production_queue = 0;
        if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
            production_queue_need_attr = -1;
            int id = owner->id;
            TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
            long* value = &game->queue_is_waiting_on_pop_counter[id];
            long old = *value;
            long result = old - 1;
            *value = result;
        }
    }
}

void TRIBE_Building_Object::recycle_out_of_game() {
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

int TRIBE_Building_Object::setup(TRIBE_Master_Building_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    built = 0;
    TRIBE_Combat_Object::setup(tobj, obj_owner, x, y, z);
    type = 0x50;
    set_object_state(RGE_OBJECT_STATE_UNBUILT);

    if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_pts_required > 0) {
        new_sprite(static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_sprite);
    }

    build_pts = 0;
    hp = 1.0f;
    facet = (unsigned char) static_cast<TRIBE_Master_Building_Object*>(master_obj)->building_facet;
    culture = obj_owner->culture;

    static_cast<TRIBE_World*>(owner->world)
        ->check_destructables(
            owner->id, static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, world_x, world_y, 0
        );
    production_queue_actions = create_action_list();
    return 1;
}

int TRIBE_Building_Object::setup(int infile, RGE_Game_World* gworld) {
    TRIBE_Combat_Object::setup(infile, gworld);
    type = 0x50;
    rge_read(infile, &built, 1);
    rge_read(infile, &build_pts, 4);
    rge_read(infile, &unique_build_id, 4);
    rge_read(infile, &culture, 1);
    production_queue_actions = create_action_list();

    if (save_game_version >= 7.21f) {
        rge_read(infile, &production_queue_size, 2);
        if (production_queue_size > 0) {
            production_queue =
                static_cast<Production_Queue_Record*>(calloc(production_queue_size, sizeof(Production_Queue_Record)));
            for (short i = 0; i < production_queue_size; ++i) {
                rge_read(infile, &production_queue[i].master_id, 2);
                rge_read(infile, &production_queue[i].unit_count, 2);
            }
        }
        rge_read(infile, &production_queue_count, 2);
        rge_read(infile, &production_queue_enabled, 1);
        production_queue_actions->load(infile);
    }
    return 1;
}

void TRIBE_Building_Object::take_building_attribute_from_owner() {
    for (int i = 0; i < 3; ++i) {
        if (this->master_obj->attribute_flag[i] >= 4 && this->master_obj->attribute_type_held[i] >= 0) {
            owner->add_attribute_num(
                this->master_obj->attribute_type_held[i], -this->master_obj->attribute_amount_held[i], 0
            );
        }
    }
}

void TRIBE_Building_Object::give_building_attribute_to_owner() {
    for (int i = 0; i < 3; ++i) {
        if (this->master_obj->attribute_flag[i] >= 4 && this->master_obj->attribute_type_held[i] >= 0) {
            this->owner->add_attribute_num(
                this->master_obj->attribute_type_held[i], this->master_obj->attribute_amount_held[i], 0
            );
        }
    }
}

void TRIBE_Building_Object::destroy_obj() {
    take_building_attribute_from_owner();
    RGE_Action_Object::destroy_obj();
    owner->doppleganger_creator->remove_doppleganger_check(this);
    DoppleInstalled = 0;
}

unsigned char TRIBE_Building_Object::heal(float healing) {
    TRIBE_Master_Building_Object* master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
    float max_hp = (float) (int) master->hp;
    healing = healing * (float) (int) master->hp / (float) (int) master->build_pts_required;
    if (healing + hp > max_hp) {
        healing = max_hp - hp;
    }

    if (static_cast<TRIBE_Player*>(owner)->pay_obj_cost(master->id, healing / (float) ((int) master->hp * 2), 0) != 0) {
        return TRIBE_Combat_Object::heal(healing);
    }
    return 2;
}

void TRIBE_Building_Object::set_object_state(unsigned char new_object_state) {
    unsigned char dopple_removed;

    if (new_object_state == RGE_OBJECT_STATE_ACTIVE) {
        build_pts = (float) (int) static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_pts_required;

        int random_value = debug_rand("C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 299);
        int old_random = debug_random_on;
        debug_random_on = 0;

        RGE_Sound* sound = static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_sound;
        if (sound != 0 && owner->id == owner->world->curr_player) {
            sound->play(1);
        }

        debug_random_on = old_random;
        debug_srand("C:\\msdev\\work\\age1_x1\\t_b_obj.cpp", 309, random_value);

        built = 1;
        give_building_attribute_to_owner();

        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_and_go_away != 0) {
            die_die_die();
        } else {
            unexplore_terrain(owner, 1, -1);
            explore_terrain(owner, 0, -1);
            new_sprite(static_cast<TRIBE_Master_Building_Object*>(master_obj)->sprite);
            facet = (unsigned char) static_cast<TRIBE_Master_Building_Object*>(master_obj)->building_facet;
            if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->building_connect_flag != 0) {
                connect();
            }
        }

        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_obj > -1) {
            owner->master_objects[static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_obj]
                ->make_new_obj(owner, world_x, world_y, world_z);
        }

        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tile > -1) {
            short x1 =
                (short) (world_x - static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_x);
            short y1 =
                (short) (world_y - static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_y);
            short x2 = (short) (world_x + static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_x
                                - g_build_tile_coordinate_epsilon);
            short y2 = (short) (world_y + static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_y
                                - g_build_tile_coordinate_epsilon);
            owner->world->map->set_terrain(
                owner->world->players[0], owner->world, x1, y1, x2, y2,
                (unsigned char) static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tile, 1, 0
            );
            owner->world->map->request_redraw(
                (short) (world_x - static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_x) - 1,
                (short) (world_y - static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_y) - 1,
                (short) (world_x + static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_x
                         - g_build_tile_coordinate_epsilon)
                    + 1,
                (short) (world_y + static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_radius_y
                         - g_build_tile_coordinate_epsilon)
                    + 1,
                0
            );
        }

        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech > -1) {
            static_cast<TRIBE_Player*>(owner)->tech_tree->do_tech(
                static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech
            );
        }

        rge_base_game->notification(
            GAME_NOTIFY_BUILDING_COMPLETED, owner->id, static_cast<TRIBE_Master_Building_Object*>(master_obj)->id,
            (long) world_x, (long) world_y
        );
        static_cast<TRIBE_Player*>(owner)->registerBuild(this, unique_build_id);
    }

    if (new_object_state == RGE_OBJECT_STATE_DYING && object_state == RGE_OBJECT_STATE_ACTIVE) {
        take_building_attribute_from_owner();
        owner->doppleganger_creator->remove_doppleganger_check(this);
        DoppleInstalled = 0;
        dopple_removed = 1;
    } else {
        dopple_removed = 0;
    }

    RGE_Static_Object::set_object_state(new_object_state);

    if (dopple_removed != 0) {
        RGE_Static_Object* object = owner->objects->find_by_master_id(
            static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, -1.0f, -1.0f, 1, RGE_OBJECT_STATE_ACTIVE, 0
        );
        if (object == 0) {
            if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech > -1) {
                static_cast<TRIBE_Player*>(owner)->tech_tree->undo_tech(
                    static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech
                );
            }
            static_cast<TRIBE_Player*>(owner)->tech_tree->undo_tech(TECH_A01_B01_F01_I01_TOOL_AGE);
            static_cast<TRIBE_Player*>(owner)->tech_tree->undo_tech(TECH_D01_H01_J01_BRONZE_AGE);
            static_cast<TRIBE_Player*>(owner)->tech_tree->undo_tech(TECH_B3_C1_D1_IRON_AGE);
        }
    }
}

void TRIBE_Building_Object::rehook() {
    RGE_Action_Object::rehook();
    production_queue_actions->rehook();
}

unsigned char TRIBE_Building_Object::update() {
    if (object_state == RGE_OBJECT_STATE_UNBUILT) {
        short max_value = sprite->facet_num;
        TRIBE_Master_Building_Object* master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
        unsigned char result =
            (unsigned char) ((long) (((float) (int) max_value * build_pts) / (float) (int) master->build_pts_required));

        if ((short) result < max_value && result != facet) {
            facet = result;
        }
        if ((float) (int) master->build_pts_required <= build_pts) {
            set_object_state(RGE_OBJECT_STATE_ACTIVE);
        }
    }

    PriorMap3 = PriorMap2;
    PriorMap2 = PriorMap1;
    PriorTurn3 = PriorTurn2;
    PriorTurn2 = PriorTurn1;
    PriorTurn1 = world_update_counter;

    unsigned char result = TRIBE_Combat_Object::update();
    if (object_state > RGE_OBJECT_STATE_ACTIVE) {
        empty_production_queue();
    } else {
        update_production_queue();
    }
    PriorMap1 = Unified_Map_Value;
    return result;
}

int TRIBE_Building_Object::explore_terrain(RGE_Player* whos, unsigned char explore_type, int Override_LOS) {
    if (built != 0) {
        return RGE_Static_Object::explore_terrain(whos, explore_type, Override_LOS);
    }
    return RGE_Static_Object::explore_terrain(whos, 1, Override_LOS);
}

void TRIBE_Building_Object::save(int outfile) {
    TRIBE_Combat_Object::save(outfile);
    rge_write(outfile, &built, 1);
    rge_write(outfile, &build_pts, 4);
    rge_write(outfile, &unique_build_id, 4);
    rge_write(outfile, &culture, 1);
    rge_write(outfile, &production_queue_size, 2);
    if (production_queue_size > 0) {
        for (short i = 0; i < production_queue_size; ++i) {
            rge_write(outfile, &production_queue[i].master_id, 2);
            rge_write(outfile, &production_queue[i].unit_count, 2);
        }
    }
    rge_write(outfile, &production_queue_count, 2);
    rge_write(outfile, &production_queue_enabled, 1);
    production_queue_actions->save(outfile);
}

//! @bug This change never updates the per-player building check lists.
//! The old owner keeps a stale entry, and the new owner gets no entry.
//! A later building death leaves a dangling entry that other code still reads.
//! No fog ghost spawns for the ex-owner, so the converted building vanishes in its fog.
void TRIBE_Building_Object::change_ownership(RGE_Player* new_owner) {
    if (object_state == RGE_OBJECT_STATE_ACTIVE) {
        for (int i = 0; i < 3; ++i) {
            RGE_Master_Static_Object* master = master_obj;
            if (master->attribute_flag[i] >= 4 && master->attribute_type_held[i] >= 0) {
                owner->add_attribute_num(master->attribute_type_held[i], -master->attribute_amount_held[i], 0);
            }
        }
    }

    if (object_state == RGE_OBJECT_STATE_UNBUILT) {
        unexplore_terrain(owner, 1, -1);
    }

    if (production_queue_count > 0) {
        if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
            production_queue_need_attr = -1;
            int id = owner->id;
            long* value = &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
            *value = *value - 1;
        }
        production_queue_count = 1;
        production_queue->unit_count = 1;
    }

    actions->delete_list();
    TRIBE_Combat_Object::change_ownership(new_owner);

    if (object_state == RGE_OBJECT_STATE_UNBUILT) {
        explore_terrain(owner, 1, -1);
    }

    if (object_state == RGE_OBJECT_STATE_ACTIVE) {
        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_obj > -1) {
            owner->master_objects[static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_obj]
                ->make_new_obj(owner, world_x, world_y, world_z);
        }
        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech > -1) {
            static_cast<TRIBE_Player*>(owner)->tech_tree->do_tech(
                static_cast<TRIBE_Master_Building_Object*>(master_obj)->on_build_make_tech
            );
        }
    }

    if (object_state == RGE_OBJECT_STATE_ACTIVE) {
        for (int i = 0; i < 3; ++i) {
            RGE_Master_Static_Object* master = master_obj;
            if (master->attribute_flag[i] >= 4 && master->attribute_type_held[i] >= 0) {
                owner->add_attribute_num(master->attribute_type_held[i], master->attribute_amount_held[i], 0);
            }
        }
    }
}

void TRIBE_Building_Object::modify(float amount, unsigned char flag) {
    if (flag != 0x11) {
        TRIBE_Combat_Object::modify(amount, flag);
        return;
    }
    facet = (unsigned char) amount;
}

void TRIBE_Building_Object::transform(TRIBE_Master_Building_Object* obj) {
    TRIBE_Combat_Object::transform(obj);
    object_state = RGE_OBJECT_STATE_UNBUILT;
    TRIBE_Master_Combat_Object* combat_master = static_cast<TRIBE_Master_Combat_Object*>(master_obj);
    if (combat_master->build_pts_required > 0) {
        new_sprite(obj->construction_sprite);
    }
    build_pts = 0;
}

long TRIBE_Building_Object::check(TRIBE_Building_Object** checks) {
    RGE_Map* map = owner->world->map;
    short x = (short) world_x;
    short y = (short) world_y;
    short w = (short) map->map_width - 1;
    short h = (short) map->map_height - 1;
    long counter = 0;

    if (y > 0) {
        checks[0] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y - 1][x].objects.find_by_master_id(
            static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, -1.0f, -1.0f, 0, 0, 0
        ));
        if (checks[0] != 0) {
            if (checks[0]->owner == owner) {
                ++counter;
            } else {
                checks[0] = 0;
            }
        }
    } else {
        checks[0] = 0;
    }

    if (x > 0) {
        checks[1] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y][x - 1].objects.find_by_master_id(
            static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, -1.0f, -1.0f, 0, 0, 0
        ));
        if (checks[1] != 0) {
            if (checks[1]->owner == owner) {
                ++counter;
            } else {
                checks[1] = 0;
            }
        }
    } else {
        checks[1] = 0;
    }

    if (x < w) {
        checks[2] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y][x + 1].objects.find_by_master_id(
            static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, -1.0f, -1.0f, 0, 0, 0
        ));
        if (checks[2] != 0) {
            if (checks[2]->owner == owner) {
                ++counter;
            } else {
                checks[2] = 0;
            }
        }
    } else {
        checks[2] = 0;
    }

    if (y < h) {
        checks[3] = static_cast<TRIBE_Building_Object*>(map->map_row_offset[y + 1][x].objects.find_by_master_id(
            static_cast<TRIBE_Master_Building_Object*>(master_obj)->id, -1.0f, -1.0f, 0, 0, 0
        ));
        if (checks[3] != 0) {
            if (checks[3]->owner == owner) {
                ++counter;
            } else {
                checks[3] = 0;
            }
        }
    } else {
        checks[3] = 0;
    }
    return counter;
}

void TRIBE_Building_Object::connect() {
    if (this->sprite == 0) {
        return;
    }
    if (this->sprite->facet_num == 3) {
        set_angle();
        TRIBE_Building_Object* checks[4];
        check(checks);

        if (checks[0] != 0 && checks[3] != 0 && checks[1] == 0 && checks[2] == 0) {
            RGE_Moving_Object::rotate(1 - facet);
        } else if (checks[1] != 0 && checks[2] != 0 && checks[0] == 0 && checks[3] == 0) {
            RGE_Moving_Object::rotate(-facet);
        } else {
            RGE_Moving_Object::rotate(2 - facet);
        }

        if (checks[0] != 0)
            checks[0]->connect2();
        if (checks[1] != 0)
            checks[1]->connect2();
        if (checks[2] != 0)
            checks[2]->connect2();
        if (checks[3] != 0)
            checks[3]->connect2();
    } else {
        facet = 0;
    }
}

void TRIBE_Building_Object::connect2() {
    if (this->sprite == 0) {
        return;
    }
    if (this->sprite->facet_num == 3) {
        TRIBE_Building_Object* checks[4];
        check(checks);
        if (checks[0] != 0 && checks[3] != 0 && checks[1] == 0 && checks[2] == 0) {
            RGE_Moving_Object::rotate(1 - facet);
        } else if (checks[1] != 0 && checks[2] != 0 && checks[0] == 0 && checks[3] == 0) {
            RGE_Moving_Object::rotate(-facet);
        } else {
            RGE_Moving_Object::rotate(2 - facet);
        }
    } else {
        facet = 0;
    }
}

void TRIBE_Building_Object::lay_down_impassable_terrain() {
    RGE_Map* map = owner->world->map;
    TRIBE_Master_Building_Object* object_master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
    if (object_master->on_build_make_tile > -1) {
        return;
    }

    short tx1 = (short) (world_x - object_master->radius_x);
    short tx2 = (short) (world_x + object_master->radius_x - 0.01f);
    short y1 = (short) (world_y - object_master->radius_y);
    short y2 = (short) (world_y + object_master->radius_y - 0.01f);
    if (tx1 < 0)
        tx1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (tx2 >= map->map_width)
        tx2 = (short) map->map_width - 1;
    if (y2 >= map->map_height)
        y2 = (short) map->map_height - 1;

    for (short y = y1; y <= y2; ++y) {
        for (short x = tx1; x <= tx2; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            switch (tile->terrain_type) {
                case 0:
                    tile->terrain_type = 0x10;
                    break;
                case 1:
                    tile->terrain_type = 0x0F;
                    break;
                case 6:
                    tile->terrain_type = 0x0E;
                    break;
                default:
                    continue;
            }
        }
    }
}

void TRIBE_Building_Object::lay_down_passable_terrain() {
    RGE_Map* map = owner->world->map;
    TRIBE_Master_Building_Object* object_master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
    if (object_master->on_build_make_tile > -1) {
        return;
    }

    short tx1 = (short) (world_x - object_master->radius_x);
    short tx2 = (short) (world_x + object_master->radius_x - 0.01f);
    short y1 = (short) (world_y - object_master->radius_y);
    short y2 = (short) (world_y + object_master->radius_y - 0.01f);
    if (tx1 < 0)
        tx1 = 0;
    if (y1 < 0)
        y1 = 0;
    if (tx2 >= map->map_width)
        tx2 = (short) map->map_width - 1;
    if (y2 >= map->map_height)
        y2 = (short) map->map_height - 1;

    for (short y = y1; y <= y2; ++y) {
        for (short x = tx1; x <= tx2; ++x) {
            RGE_Tile* tile = &map->map_row_offset[y][x];
            switch (tile->terrain_type) {
                case 0x0E:
                    tile->terrain_type = 6;
                    break;
                case 0x0F:
                    tile->terrain_type = 1;
                    break;
                case 0x10:
                    tile->terrain_type = 0;
                    break;
                default:
                    continue;
            }
        }
    }
}

void TRIBE_Building_Object::cancel_object() {
    if (object_state < RGE_OBJECT_STATE_ACTIVE) {
        cancel_build();
    } else {
        TRIBE_Combat_Object::cancel_object();
    }
}

void TRIBE_Building_Object::cancel_build() {
    if ((selected & 1) != 0) {
        owner->unselect_one_object(this);
    }

    float percent;
    if (object_state >= RGE_OBJECT_STATE_ACTIVE || hp <= g_building_zero_hp) {
        percent = 0.0f;
    } else {
        percent = ((float) (int) static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_pts_required - build_pts)
                  / (float) (int) static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_pts_required
                  * g_build_cancel_refund_factor;
    }
    if (percent > g_building_one_threshold) {
        percent = 1.0f;
    }

    for (int i = 0; i < 3; ++i) {
        if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_inventory[i].type >= 0
            && static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_inventory[i].flag != 0) {
            owner->add_attribute_num(
                static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_inventory[i].type,
                (float) (int) static_cast<TRIBE_Master_Building_Object*>(master_obj)->build_inventory[i].amount
                    * percent,
                0
            );
        }
    }
    hp = 0.0f;
}

unsigned char TRIBE_Building_Object::build(float build_amount) {
    if (object_state == RGE_OBJECT_STATE_UNBUILT) {
        TRIBE_Master_Building_Object* object_master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
        if (build_amount + build_pts > (float) (int) object_master->build_pts_required) {
            build_amount = (float) (int) object_master->build_pts_required - build_pts;
        }
        hp = (float) (int) object_master->hp * build_amount / (float) (int) object_master->build_pts_required + hp;
        if (hp > (float) (int) object_master->hp) {
            hp = (float) (int) object_master->hp;
        }
        build_pts += build_amount;
        if (build_pts >= (float) (int) object_master->build_pts_required) {
            set_object_state(RGE_OBJECT_STATE_ACTIVE);
            return 1;
        }
        return 0;
    }
    return 1;
}

int TRIBE_Building_Object::work_status(
    short& work_type, short& work_target, short& progress, char* name, short name_size
) {
    RGE_Action* action = actions->get_action();
    if (action != 0) {
        work_type = action->action_type;
    } else {
        work_type = 0;
    }

    switch (work_type) {
        case TRIBE_ACTION_TYPE_MAKE_OBJECT:
            static_cast<TRIBE_Action_Make_Obj*>(action)->get_info(work_target, progress, name, name_size);
            return 1;
        case TRIBE_ACTION_TYPE_MAKE_TECH:
            static_cast<TRIBE_Action_Make_Tech*>(action)->get_info(work_target, progress, name, name_size);
            return 1;
        default:
            break;
    }
    work_target = -1;
    progress = 0;
    if (name != 0)
        *name = 0;
    return 0;
}

short TRIBE_Building_Object::get_construction_progress() {
    if (object_state != RGE_OBJECT_STATE_UNBUILT) {
        return 100;
    }
    TRIBE_Master_Building_Object* master = static_cast<TRIBE_Master_Building_Object*>(master_obj);
    short required = master->build_pts_required;
    if (required == 0) {
        return 100;
    }
    return (short) (build_pts / (float) (int) required * 100.0f);
}

void TRIBE_Building_Object::copy_obj(RGE_Master_Static_Object* source) {
    TRIBE_Master_Building_Object* source_master = static_cast<TRIBE_Master_Building_Object*>(source);
    if (sprite == static_cast<TRIBE_Master_Building_Object*>(master_obj)->construction_sprite) {
        new_sprite(source_master->construction_sprite);
    }
    RGE_Combat_Object::copy_obj(source);
    if (static_cast<TRIBE_Master_Building_Object*>(master_obj)->building_connect_flag != 0) {
        connect();
    }
}

void TRIBE_Building_Object::rotate(long amount) {
}

void TRIBE_Building_Object::damage(
    int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier, RGE_Player* attacking_player,
    RGE_Static_Object* attacking_object
) {
    float temp_hp = hp;
    if (hp <= g_building_zero_hp) {
        return;
    }

    RGE_Combat_Object::damage(weapon_num, damage, attack_modifier, attacking_player, attacking_object);
    RGE_Master_Static_Object* master = attacking_object->master_obj;
    short group = master->object_group;

    if (group == OBJECT_GROUP_ARCHER || group == OBJECT_GROUP_CHARIOT_ARCHER || group == OBJECT_GROUP_HORSE_ARCHER
        || group == OBJECT_GROUP_ELEPHANT_ARCHER || master->id == MASTER_OBJECT_WATCH_TOWER
        || master->id == MASTER_OBJECT_GUARD_TOWER || master->id == MASTER_OBJECT_SENTRY_TOWER
        || master->id == MASTER_OBJECT_MIRROR_TOWER || master->id == MASTER_OBJECT_HERO_ZENOBIA_S_TOWER) {
        if (temp_hp - hp < g_building_small_damage_threshold) {
            hp = temp_hp - g_building_small_damage_amount;
        }
    } else if (temp_hp - hp < g_building_one_threshold) {
        hp = temp_hp - g_building_minimum_damage;
    }

    if (owner->id > 0 && hp < g_building_one_threshold) {
        attacking_player->add_attribute_num(0x2B, 1.0f, 0);
    }
}

void TRIBE_Building_Object::add_to_production_queue(short master_id, short unit_count) {
    short original_master_id = master_id;
    short queue_count = production_queue_count;
    unsigned char queue_changed = 0;

    if (queue_count <= 0 || production_queue[queue_count - 1].master_id != master_id) {
        while (queue_count > 0) {
            remove_from_production_queue(production_queue[0].master_id, 1);
            queue_count = production_queue_count;
        }

        if (static_cast<TRIBE_Player*>(owner)->check_obj_cost(original_master_id, &master_id, 1.0f, 1) == 0) {
            rge_base_game->notification(GAME_NOTIFY_ATTRIBUTE_NEEDED, owner->id, master_id, 0, 0);
            return;
        }

        if (production_queue_count == production_queue_size) {
            Production_Queue_Record* new_queue = static_cast<Production_Queue_Record*>(
                calloc(production_queue_size + 10, sizeof(Production_Queue_Record))
            );
            if (new_queue == 0)
                return;
            if (production_queue != 0) {
                for (short i = 0; i < production_queue_size; ++i) {
                    new_queue[i].master_id = production_queue[i].master_id;
                    new_queue[i].unit_count = production_queue[i].unit_count;
                }
                free(production_queue);
            }
            production_queue_size += 10;
            production_queue = new_queue;
        }

        production_queue[production_queue_count].unit_count = 0;
        for (int i = 0; i < unit_count; ++i) {
            if (static_cast<TRIBE_Player*>(owner)->check_obj_cost(original_master_id, &master_id, 1.0f, 1) == 0) {
                rge_base_game->notification(GAME_NOTIFY_ATTRIBUTE_NEEDED, owner->id, master_id, 0, 0);
                break;
            }
            static_cast<TRIBE_Player*>(owner)->pay_obj_cost(original_master_id, 1.0f, 1);
            production_queue[production_queue_count].unit_count++;
        }
        production_queue[production_queue_count].master_id = original_master_id;
        production_queue_count++;
        production_queue_change_flag++;
        rge_base_game->notification(GAME_NOTIFY_PRODUCTION_QUEUE_CHANGED, owner->id, 0, 0, 0);
    } else {
        for (int i = 0; i < unit_count; ++i) {
            if (static_cast<TRIBE_Player*>(owner)->check_obj_cost(original_master_id, &master_id, 1.0f, 1) == 0) {
                rge_base_game->notification(GAME_NOTIFY_ATTRIBUTE_NEEDED, owner->id, master_id, 0, 0);
                break;
            }
            static_cast<TRIBE_Player*>(owner)->pay_obj_cost(original_master_id, 1.0f, 1);
            production_queue[production_queue_count - 1].unit_count++;
            queue_changed = 1;
        }
        if (queue_changed == 1) {
            production_queue_change_flag++;
            rge_base_game->notification(GAME_NOTIFY_PRODUCTION_QUEUE_CHANGED, owner->id, 0, 0, 0);
        }
    }
}

void TRIBE_Building_Object::remove_from_production_queue(short master_id, short unit_count) {
    int remove_count;
    short index;
    short copy_index;

    index = production_queue_count;
    if (index != 0) {
        index--;
        while (index >= 0) {
            if (production_queue[index].master_id == master_id) {
                remove_count = unit_count;
                if (production_queue[index].unit_count <= unit_count) {
                    remove_count = production_queue[index].unit_count;
                }

                if (remove_count > 0) {
                    do {
                        static_cast<TRIBE_Player*>(owner)->reimburse_obj_cost(master_id);
                        remove_count--;
                    } while (remove_count != 0);
                }

                production_queue[index].unit_count -= unit_count;
                production_queue_change_flag++;

                if (production_queue[index].unit_count <= 0) {
                    production_queue_count--;
                    copy_index = index;
                    if (index < production_queue_count) {
                        do {
                            production_queue[copy_index].master_id = production_queue[copy_index + 1].master_id;
                            production_queue[copy_index].unit_count = production_queue[copy_index + 1].unit_count;
                            copy_index++;
                        } while (copy_index < production_queue_count);
                    }

                    if (index == 0) {
                        if (production_queue_need_attr != -1) {
                            if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
                                int id = owner->id;
                                long* value =
                                    &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
                                long old = *value;
                                long result = old - 1;
                                *value = result;
                            }
                            production_queue_need_attr = -1;
                        }
                        production_queue_actions->action_stop();
                        production_queue_actions->delete_list();
                    }
                }
                break;
            }
            index--;
        }

        rge_base_game->notification(GAME_NOTIFY_PRODUCTION_QUEUE_CHANGED, owner->id, 0, 0, 0);
    }
}

void TRIBE_Building_Object::advance_production_queue() {
    if (production_queue_count == 0) {
        return;
    }

    --production_queue->unit_count;
    production_queue_change_flag++;
    if (production_queue->unit_count <= 0) {
        --production_queue_count;
        for (int i = 0; i < production_queue_count; ++i) {
            production_queue[i].master_id = production_queue[i + 1].master_id;
            production_queue[i].unit_count = production_queue[i + 1].unit_count;
        }
    }
    rge_base_game->notification(GAME_NOTIFY_PRODUCTION_QUEUE_CHANGED, owner->id, 0, 0, 0);
}

void TRIBE_Building_Object::empty_production_queue() {
    if (production_queue_need_attr != -1) {
        if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
            int id = owner->id;
            long* value = &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
            long old = *value;
            long result = old - 1;
            *value = result;
        }
        production_queue_need_attr = -1;
    }
    production_queue_count = 0;
    production_queue_actions->delete_list();
    production_queue_change_flag++;
}

void TRIBE_Building_Object::enable_production_queue(int enabled) {
    production_queue_enabled = (unsigned char) enabled;
}

void TRIBE_Building_Object::update_production_queue() {
    short work_type;
    short work_target;
    short progress;

    if (production_queue_enabled == 0 || production_queue_count == 0) {
        if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
            production_queue_need_attr = -1;
            int id = owner->id;
            long* value = &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
            long old = *value;
            long result = old - 1;
            *value = result;
        }
        return;
    }

    if (work_status(work_type, work_target, progress, 0, 0) == 0
        || (work_type != TRIBE_ACTION_TYPE_MAKE_OBJECT && work_type != TRIBE_ACTION_TYPE_MAKE_TECH)) {
        if (production_queue_actions->list == 0) {
            float* attributes = owner->attributes;
            if (attributes[PLAYER_ATTRIBUTE_POPULATION] >= attributes[PLAYER_ATTRIBUTE_POPULATION_LIMIT]) {
                if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_LIMIT) {
                    return;
                }
                production_queue_need_attr = PLAYER_ATTRIBUTE_POPULATION_LIMIT;
                rge_base_game->notification(
                    GAME_NOTIFY_ATTRIBUTE_NEEDED, owner->id, PLAYER_ATTRIBUTE_POPULATION_LIMIT, 0, 0
                );
                static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[owner->id]++;
                return;
            }

            if (attributes[PLAYER_ATTRIBUTE_POPULATION_HEADROOM] > g_building_zero_hp) {
                if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
                    int id = owner->id;
                    long* value = &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
                    long old = *value;
                    long result = old - 1;
                    *value = result;
                }
                production_queue_need_attr = -1;
                TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj(this, production_queue->master_id, -1, 1);
                if (action != 0) {
                    production_queue_actions->add_action(action);
                }
            } else {
                if (production_queue_need_attr == PLAYER_ATTRIBUTE_POPULATION_HEADROOM) {
                    return;
                }
                production_queue_need_attr = PLAYER_ATTRIBUTE_POPULATION_HEADROOM;
                rge_base_game->notification(
                    GAME_NOTIFY_ATTRIBUTE_NEEDED, owner->id, PLAYER_ATTRIBUTE_POPULATION_HEADROOM, 0, 0
                );
                int id = owner->id;
                long* value = &static_cast<TRIBE_Game*>(rge_base_game)->queue_is_waiting_on_pop_counter[id];
                long old = *value;
                long result = old + 1;
                *value = result;
                return;
            }
        }

        char action_state = production_queue_actions->update();
        if (action_state == RGE_ACTION_UPDATE_FAILED || action_state == RGE_ACTION_UPDATE_COMPLETED
            || action_state == RGE_ACTION_UPDATE_REMOVE) {
            production_queue_actions->remove_action();
            advance_production_queue();
        }
    } else if (production_queue_count > 0) {
        do {
            remove_from_production_queue(production_queue->master_id, -1);
        } while (production_queue_count > 0);
    }
}

int TRIBE_Building_Object::production_queue_status(short& master_id, short& progress) {
    master_id = -1;
    progress = 0;

    TRIBE_Action_Make_Obj* action = static_cast<TRIBE_Action_Make_Obj*>(production_queue_actions->get_action());
    if (action != 0 && action->action_type == TRIBE_ACTION_TYPE_MAKE_OBJECT) {
        action->get_info(master_id, progress, 0, 0);
        return 1;
    }

    if (production_queue_count > 0) {
        master_id = production_queue->master_id;
        progress = 0;
        return 1;
    }
    return 0;
}

void TRIBE_Building_Object::stop() {
    RGE_Combat_Object::stop();
    while (production_queue_count > 0) {
        remove_from_production_queue(production_queue->master_id, 1);
    }
}
