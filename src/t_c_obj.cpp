// Recovered from C:\msdev\work\age1_x1\t_c_obj.cpp.
// This module owns TRIBE_Combat_Object.

#include "../include/t_c_obj.h"

#include "../include/basegame.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/tact_bld.h"
#include "../include/tact_cnv.h"
#include "../include/tact_hea.h"
#include "../include/tact_hnt.h"
#include "../include/tact_lst.h"
#include "../include/tact_rep.h"
#include "../include/tact_trd.h"
#include "../include/task_lst.h"
#include "../include/tm_b_obj.h"
#include "../include/tribe_unit_ai.h"
#include "../include/tplayer.h"
#include "../include/vis_unit.h"
#include "../include/world.h"
#include "../include/rge_base_game_global.h"

#include <math.h>
#include <stdlib.h>

int __cdecl lines_intersect(
    float a_x1, float a_y1, float a_x2, float a_y2, float b_x1, float b_y1, float b_x2, float b_y2
);

TRIBE_Combat_Object::TRIBE_Combat_Object(
    TRIBE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup
) : RGE_Combat_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }
}

TRIBE_Combat_Object::TRIBE_Combat_Object(int infile, RGE_Game_World* gworld, int do_setup) :
    RGE_Combat_Object(infile, gworld, 0) {
    if (do_setup != 0) {
        setup(infile, gworld);
    }
}

TRIBE_Combat_Object::~TRIBE_Combat_Object() {
    if (this->own_master != 0) {
        RGE_Master_Static_Object* master = this->master_obj;
        // The executable reads master->id before this test.
        const int id = master->id;
        if (master != 0) {
            delete master;
        }
        this->master_obj = this->owner->master_objects[id];
    }

    RGE_Master_Static_Object* master = this->master_obj;
    const short group = master->object_group;
    if (group == OBJECT_GROUP_CIVILIAN || group == OBJECT_GROUP_FISHING_BOAT || group == OBJECT_GROUP_TRADE_BOAT) {
        this->owner->attributes[PLAYER_ATTRIBUTE_CIVILIAN_POPULATION] -= g_combat_one_float;
    } else if ((group != OBJECT_GROUP_PRIEST && master->master_type == TRIBE_MASTER_TYPE_COMBAT)
               || master->id == MASTER_OBJECT_WATCH_TOWER || master->id == MASTER_OBJECT_GUARD_TOWER
               || master->id == MASTER_OBJECT_SENTRY_TOWER) {
        this->owner->attributes[PLAYER_ATTRIBUTE_MILITARY_POPULATION] -= g_combat_one_float;
    }
}

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    RGE_Combat_Object::setup(tobj, obj_owner, x, y, z);

    if (this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (this->master_obj->object_group == OBJECT_GROUP_CIVILIAN
        || this->master_obj->object_group == OBJECT_GROUP_FISHING_BOAT
        || this->master_obj->object_group == OBJECT_GROUP_TRADE_BOAT) {
        this->owner->attributes[PLAYER_ATTRIBUTE_CIVILIAN_POPULATION] -= g_combat_negative_one;
    } else if ((this->master_obj->object_group != OBJECT_GROUP_PRIEST
                && this->master_obj->master_type == TRIBE_MASTER_TYPE_COMBAT)
               || this->master_obj->id == MASTER_OBJECT_WATCH_TOWER || this->master_obj->id == MASTER_OBJECT_GUARD_TOWER
               || this->master_obj->id == MASTER_OBJECT_SENTRY_TOWER) {
        this->owner->attributes[PLAYER_ATTRIBUTE_MILITARY_POPULATION] -= g_combat_negative_one;
    }

    if (this->master_obj->object_group == OBJECT_GROUP_PRIEST) {
        this->attribute_amount_held = 100.0f;
        this->attribute_type_held = RGE_RESOURCE_FAITH;
    }

    return 1;
}

int TRIBE_Combat_Object::setup(int infile, RGE_Game_World* gworld) {
    RGE_Combat_Object::setup(infile, gworld);
    this->type = 0x46;
    rge_read(infile, &this->own_master, 1);

    if (this->own_master != 0) {
        unsigned char master_type;
        rge_read(infile, &master_type, 1);
        if (master_type == TRIBE_MASTER_TYPE_COMBAT) {
            this->master_obj =
                new TRIBE_Master_Combat_Object(infile, this->owner->world->sprites, this->owner->world->sounds, 1);
        } else if (master_type == TRIBE_MASTER_TYPE_BUILDING) {
            this->master_obj =
                new TRIBE_Master_Building_Object(infile, this->owner->world->sprites, this->owner->world->sounds, 1);
        }
    }

    int needUnitAI;
    rge_read(infile, &needUnitAI, 4);
    if (needUnitAI == 1) {
        this->initUnitAI();
        if (this->unitAIValue != 0) {
            this->unitAIValue->load(infile);
        }
    }
    return 1;
}

RGE_Action_List* TRIBE_Combat_Object::create_action_list() {
    return new TRIBE_Action_List(this);
}

void TRIBE_Combat_Object::save(int outfile) {
    RGE_Combat_Object::save(outfile);
    rge_write(outfile, &this->own_master, 1);

    if (this->own_master != 0) {
        this->master_obj->save(outfile);
    }

    if (this->unitAIValue != 0) {
        int haveUnitAI = 1;
        rge_write(outfile, &haveUnitAI, 4);
        this->unitAIValue->save(outfile);
    } else {
        int haveUnitAI = 0;
        rge_write(outfile, &haveUnitAI, 4);
    }
}

unsigned char TRIBE_Combat_Object::update() {
    if (this->master_obj->object_group == OBJECT_GROUP_PRIEST && this->object_state == RGE_OBJECT_STATE_ACTIVE) {
        this->attribute_amount_held += this->owner->attributes[PLAYER_ATTRIBUTE_FAITH_RECHARGE_RATE]
                                       * this->owner->world->world_time_delta_seconds;
        if (this->attribute_amount_held >= 100.0f) {
            this->attribute_amount_held = 100.0f;
        }
        this->attribute_type_held = RGE_RESOURCE_FAITH;
    }
    return RGE_Combat_Object::update();
}

void TRIBE_Combat_Object::modify(float amount, unsigned char flag) {
    if (flag == 0x65) {
        for (int i = 0; i < 3; ++i) {
            if (this->master_obj->attribute_type_held[i] == 4) {
                this->owner->attributes[PLAYER_ATTRIBUTE_POPULATION_HEADROOM] -=
                    this->master_obj->attribute_amount_held[i];
                this->owner->attributes[PLAYER_ATTRIBUTE_POPULATION_HEADROOM] += amount;
            }
            if (this->master_obj->attribute_type_held[i] == 0x0B) {
                this->owner->attributes[PLAYER_ATTRIBUTE_POPULATION] -= this->master_obj->attribute_amount_held[i];
                this->owner->attributes[PLAYER_ATTRIBUTE_POPULATION] -= amount;
            }
            if (this->master_obj->attribute_type_held[i] == 0x13) {
                this->owner->attributes[PLAYER_ATTRIBUTE_TOTAL_UNITS_OWNED] -=
                    this->master_obj->attribute_amount_held[i];
                this->owner->attributes[PLAYER_ATTRIBUTE_TOTAL_UNITS_OWNED] -= amount;
            }
        }
    }
    RGE_Static_Object::modify(amount, flag);
}

void TRIBE_Combat_Object::transform(RGE_Master_Static_Object* obj) {
    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Action_Object::transform(obj);
    if (this->own_master == 1) {
        if (old_master != 0) {
            delete old_master;
        }
        this->own_master = 0;
    }
}

void TRIBE_Combat_Object::set_object_state(unsigned char new_object_state) {
    if (this->owner->world->game_state == 0 && new_object_state >= RGE_OBJECT_STATE_DYING
        && this->object_state <= RGE_OBJECT_STATE_ACTIVE && this->master_obj->object_group == OBJECT_GROUP_ARTIFACT) {
        this->reposition_artifact();
    } else {
        RGE_Static_Object::set_object_state(new_object_state);
    }
}

void TRIBE_Combat_Object::cancel_object() {
    this->die_die_die();
}

void TRIBE_Combat_Object::die_die_die() {
    if (this->object_state == RGE_OBJECT_STATE_ACTIVE && this->owner->attributes[PLAYER_ATTRIBUTE_MARTYRDOM] >= 1.0f) {
        RGE_Action* action = this->actions->get_action();
        if (action != 0 && action->type() == TRIBE_ACTION_TYPE_CONVERT) {
            static_cast<TRIBE_Action_Convert*>(action)->martyrdom();
        }
    }
    RGE_Static_Object::die_die_die();
}

void TRIBE_Combat_Object::damage(
    int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier, RGE_Player* attacking_player,
    RGE_Static_Object* attackingObject
) {
    const float temp_hp = this->hp;
    if (this->hp >= g_combat_one_threshold) {
        RGE_Combat_Object::damage(weapon_num, damage, attack_modifier, attacking_player, attackingObject);

        //! See produceWhenKilledBy(): a non-villager kill zeroes the carcass food.
        if (this->hp < g_combat_one_threshold
            && this->produceWhenKilledBy(attackingObject->master_obj->object_group) == 0) {
            this->set_attribute_amount(0.0f, 0, 1);
        }

        if (temp_hp - this->hp < g_combat_one_threshold) {
            this->hp = temp_hp - g_combat_one_float;
        }

        if (this->owner->id > 0 && this->hp < g_combat_one_float) {
            attacking_player->add_attribute_num(0x14, 1.0f, 0);
        }
    }
}

//! @bug This transfer never adjusts the per-unit counts in resources 37 and 40.
//! setup() adds 1 at creation, and the destructor removes 1 at deletion.
//! A converted unit leaves +1 on the old owner and adds 0 to the new one.
//! This skews the civilian high and largest army score values.
//! addObject() also runs before the owner switch, so AI memory records the old owner.
void TRIBE_Combat_Object::change_ownership(RGE_Player* new_owner) {
    if (this->id >= 0) {
        for (int i = 0; i < 9; ++i) {
            if (this->VUR_Ptrs[i] != 0) {
                this->VUR_Ptrs[i]->player = static_cast<unsigned char>(new_owner->id);
            }
        }
    }

    if (this->master_obj->object_group == OBJECT_GROUP_ARTIFACT) {
        RGE_Action_Object::change_ownership(new_owner);
        return;
    }

    if (new_owner->master_objects[this->master_obj->id] != 0) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object(this);
        }

        this->take_attribute_from_owner();
        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag, this->player_object_node);
        this->player_object_node = new_owner->addObject(this, this->sleep_flag, this->dopple_flag);

        if (this->object_state == RGE_OBJECT_STATE_ACTIVE) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->owner = new_owner;

        if (this->own_master == 0) {
            this->master_obj = this->master_obj->make_new_master();
            this->own_master = 1;
        }

        if (this->object_state == RGE_OBJECT_STATE_ACTIVE) {
            this->explore_terrain(this->owner, 0, -1);
        }

        this->give_attribute_to_owner();

        if (this->unitAIValue != 0) {
            this->unitAIValue->purgeNotifyQueue(this->owner->world->world_time);
        }

        this->notify(this->id, this->id, 0x20B, new_owner->id, 0, 0);
    }
}

float TRIBE_Combat_Object::calc_attack_modifier(RGE_Static_Object* target) {
    RGE_Master_Combat_Object* master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (master->missile_id >= 0) {
        if (this->higher_than_target(target) != 0) {
            return 1.5f;
        }
    } else if (this->world_z < target->world_z) {
        return 0.6666f;
    }
    return 1.0f;
}

unsigned char TRIBE_Combat_Object::attack(RGE_Static_Object* target, RGE_Combat_Object* attacker) {
    RGE_Master_Combat_Object* master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (master->missile_id >= 0 && target != 0 && target->owner->id > 0) {
        target->owner->make_new_object(MASTER_OBJECT_FLARE, this->world_x, this->world_y, this->world_z, 0);
    }
    return RGE_Combat_Object::attack(target, attacker);
}

unsigned char TRIBE_Combat_Object::do_attack(
    RGE_Static_Object* target, RGE_Combat_Object* attacker, float x, float y, float z
) {
    if (target == 0) {
        return 0;
    }

    if (rge_base_game->quick_build != 0
        && (this->master_obj->id == MASTER_OBJECT_HUNTER || this->master_obj->id == MASTER_OBJECT_LUMBERJACK)) {
        this->notify(this->id, this->id, 0x200, UNIT_AI_ACTION_ATTACK, target->id, 0);
        target->die_die_die();
        return 1;
    }

    //! @bug The blast branch tests blast radius == 0, but blast level is the correct criterion.
    //! A unit with blast level > 0 and radius 0 never splashes in melee, missile, or ground hits.
    //! The devs used radius because the dat ships wrong blast levels, then the test spread everywhere.
    if (static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range > 0.0f
        && static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range < 0.99f) {
        this->area_attack(x, y, z, attacker, target);
        this->notify(this->id, this->id, 0x200, UNIT_AI_ACTION_ATTACK, target->id, 0);
        const int chance = debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 529) * 100 / 0x7FFF;
        if (chance <= static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
            const float attack_modifier = this->calc_attack_modifier(target);
            target->damage(
                static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
                static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon, attack_modifier, this->owner, attacker
            );
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(target, attacker, x, y, z);
}

void TRIBE_Combat_Object::get_armor(short& cur_armor_in, short& orig_armor_in) {
    cur_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->base_armor;
    for (int i = 0; i < static_cast<RGE_Master_Combat_Object*>(master_obj)->armor_num; ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].type == 4
            && static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value > cur_armor_in) {
            cur_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value;
        }
    }
    orig_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_armor;
}

void TRIBE_Combat_Object::get_pierce_armor(short& cur_armor_in, short& orig_armor_in) {
    cur_armor_in = 0;
    for (int i = 0; i < static_cast<RGE_Master_Combat_Object*>(this->master_obj)->armor_num; ++i) {
        RGE_Master_Combat_Object* master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
        if (master->armor[i].type == 3 && master->armor[i].value > cur_armor_in) {
            cur_armor_in = master->armor[i].value;
        }
    }
    orig_armor_in = static_cast<TRIBE_Master_Combat_Object*>(this->master_obj)->orig_pierce_armor;
}

void TRIBE_Combat_Object::reposition_artifact() {
    int y2;
    int x2;
    float y1;
    float x_pos;
    int x1;
    int found_pos;
    int map_max_x;
    int map_max_y;
    int x;
    unsigned char terrain;
    char placement;
    RGE_Static_Object* parent = this->inside_obj;
    if (parent != 0) {
        y2 = static_cast<int>(parent->world_x);
        x2 = static_cast<int>(parent->world_y);
        y1 = parent->world_x;
        x_pos = parent->world_y;
    } else {
        y2 = static_cast<int>(this->world_x);
        x2 = static_cast<int>(this->world_y);
        y1 = this->world_x;
        x_pos = this->world_y;
    }
    x1 = y2;
    found_pos = x2;

    RGE_Map* map = this->owner->world->map;
    x = 0;
    map_max_x = map->map_width - 1;
    map_max_y = map->map_height - 1;
    do {
        int i = y2;
        for (; i <= x1; ++i) {
            terrain = map->get_terrain(static_cast<short>(i), static_cast<short>(x2));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(i) - g_combat_tile_center_adjustment;
                x_pos = static_cast<float>(x2) - g_combat_tile_center_adjustment;
                placement = this->master_obj->check_placement(this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
                if (placement == 0) {
                    x = 1;
                    break;
                }
            }

            terrain = map->get_terrain(static_cast<short>(i), static_cast<short>(found_pos));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(i) - g_combat_tile_center_adjustment;
                x_pos = static_cast<float>(found_pos) - g_combat_tile_center_adjustment;
                placement = this->master_obj->check_placement(this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
                if (placement == 0) {
                    x = 1;
                    break;
                }
            }
        }

        if (x) {
            break;
        }

        int j = x2 + 1;
        for (; j <= found_pos - 1; ++j) {

            terrain = map->get_terrain(static_cast<short>(y2), static_cast<short>(j));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(y2) - g_combat_tile_center_adjustment;
                x_pos = static_cast<float>(j) - g_combat_tile_center_adjustment;
                placement = this->master_obj->check_placement(this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
                if (placement == 0) {
                    x = 1;
                    break;
                }
            }

            terrain = map->get_terrain(static_cast<short>(x1), static_cast<short>(j));
            if (terrain == 1 || terrain == 2) {
                continue;
            }
            y1 = static_cast<float>(x1) - g_combat_tile_center_adjustment;
            x_pos = static_cast<float>(j) - g_combat_tile_center_adjustment;
            placement = this->master_obj->check_placement(this->owner, y1, x_pos, 0, 0, 1, 1, 0, 1, 1);
            if (placement == 0) {
                x = 1;
                break;
            }
        }

        if (x) {
            break;
        }

        if (y2 == 0 && x1 == map_max_x && x2 == 0 && found_pos == map_max_y) {
            parent = this->inside_obj;
            if (parent != 0) {
                y1 = parent->world_x;
                x_pos = parent->world_y;
            } else {
                y1 = this->world_x;
                x_pos = this->world_y;
            }
            break;
        }

        if (y2 > 0) {
            --y2;
        }
        if (x2 > 0) {
            --x2;
        }
        if (x1 < map_max_x) {
            ++x1;
        }
        if (found_pos < map_max_y) {
            ++found_pos;
        }
    } while (1);

    this->set_location(y1, x_pos, this->world_z);
    if (this->inside_obj != 0) {
        this->exit_obj();
    }
    this->teleport(y1, x_pos, this->world_z);
    this->change_ownership(this->owner->world->players[0]);
    this->move_to(0, y1, x_pos, this->world_z);
    this->hp = 1.0f;
}

int TRIBE_Combat_Object::can_debark() {
    if (this->master_obj->unit_level != 7) {
        return 0;
    }
    return this->objects->number_of_objects != 0;
}

int TRIBE_Combat_Object::hunt(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_HUNT)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_HUNT) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Hunt* action = new TRIBE_Action_Hunt(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::convert(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_CONVERT)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_CONVERT) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Convert* action = new TRIBE_Action_Convert(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::heal(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_HEAL)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_HEAL) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Heal* action = new TRIBE_Action_Heal(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::repair(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_REPAIR)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_REPAIR) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Master_Static_Object* repair_master = this->owner->master_objects[MASTER_OBJECT_REPAIR_MAN];
    if (repair_master != 0) {
        this->transform(repair_master);
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Repair* action = new TRIBE_Action_Repair(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::build(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_BUILD)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_BUILD) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Build* action = new TRIBE_Action_Build(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::trade(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0)
        return 0;

    if (unconditional == 0 && this->actions->have_action() == 1
        && this->actions->get_action()->get_target_obj() == target
        && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_TRADE)
        return 1;

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == TRIBE_ACTION_TYPE_TRADE) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0)
        return 0;

    TRIBE_Action_Trade* action = new TRIBE_Action_Trade(this, task, target);
    if (action == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

unsigned char TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int oType) const {
    //! Trade keep-working accepts only farm and dock; the dock id is hard-coded here too.
    if (oType != MASTER_OBJECT_FARM && oType != MASTER_OBJECT_DOCK_1) {
        return 0;
    }
    return 1;
}

//! @bug This keeps the held food only for killer group 4 (villagers).
//! A lion kill sets the carcass food to 0, so no gatherer can use it.
//! area_attack() clears the attribute for every kill and has no group test.
unsigned char TRIBE_Combat_Object::produceWhenKilledBy(int oGroup) const {
    const int group = this->master_obj->object_group;
    if (group != OBJECT_GROUP_HUNTED_ANIMAL && group != OBJECT_GROUP_PREDATOR)
        return 1;
    if (oGroup != OBJECT_GROUP_CIVILIAN)
        return 0;
    return 1;
}

unsigned char TRIBE_Combat_Object::useSameZoneDropsite() const {
    const int group = this->master_obj->object_group;
    if (group == OBJECT_GROUP_FISHING_BOAT || group == OBJECT_GROUP_TRADE_BOAT)
        return 0;
    return 1;
}

void TRIBE_Combat_Object::initUnitAI() {
    RGE_Master_Static_Object* master = this->master_obj;
    switch (master->object_group) {
        case OBJECT_GROUP_ARTIFACT:
            if (master->id == 0x63 || master->id == MASTER_OBJECT_ARTIFACT_DISCOVERY1)
                return;
            this->unitAIValue = new TribeArtifactUnitAIModule(this, 5);
            return;
        case OBJECT_GROUP_CIVILIAN:
            this->unitAIValue = new TribeCivilianUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_PRIEST:
            this->unitAIValue = new TribePriestUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_HUNTED_ANIMAL:
            this->unitAIValue = new TribeHuntedAnimalUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_PREDATOR:
            if (master->id == MASTER_OBJECT_HORSE) {
                this->unitAIValue = new TribeHuntedAnimalUnitAIModule(this, 10);
            } else if (master->id == MASTER_OBJECT_ELEPHANT) {
                this->unitAIValue = new TribeElephantUnitAIModule(this, 10);
            } else if (master->id == MASTER_OBJECT_LION) {
                this->unitAIValue = new TribeLionUnitAIModule(this, 10);
            } else {
                this->unitAIValue = new TribePreditorUnitAIModule(this, 10);
            }
            return;
        case OBJECT_GROUP_FISHING_BOAT:
            this->unitAIValue = new TribeFishingShipUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_TRADE_BOAT:
            this->unitAIValue = new TribeTradeShipUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_TRANSPORT_BOAT:
            this->unitAIValue = new TribeTransportShipUnitAIModule(this, 10);
            return;
        case OBJECT_GROUP_BUILDING:
        case OBJECT_GROUP_WALL:
            if (master->id == MASTER_OBJECT_WATCH_TOWER || master->id == MASTER_OBJECT_SENTRY_TOWER
                || master->id == MASTER_OBJECT_GUARD_TOWER || master->id == MASTER_OBJECT_GUARD_TOWER2
                || master->id == MASTER_OBJECT_MIRROR_TOWER || master->id == MASTER_OBJECT_HERO_ZENOBIA_S_TOWER) {
                this->unitAIValue = new TribeTowerUnitAIModule(this, 10);
            } else {
                this->unitAIValue = new TribeBuildingUnitAIModule(this, 10);
            }
            return;
        case 5:
        case 7:
        case OBJECT_GROUP_STONE_SOURCE:
        case 0x0B:
        case 0x0E:
        case OBJECT_GROUP_TREE:
        case 0x10:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case OBJECT_GROUP_GOLD_SOURCE:
        case 0x21:
            return;
        default:
            this->unitAIValue = new TribeSoldierUnitAIModule(this, 10);
            return;
    }
}

int __cdecl lines_intersect(
    float a_x1, float a_y1, float a_x2, float a_y2, float b_x1, float b_y1, float b_x2, float b_y2
) {
    return 1;
}

int TRIBE_Combat_Object::higher_check_for_cliff(
    RGE_Static_Object* target, int XTileInt, int YTileInt, float StartX, float StartY, float DestX, float DestY,
    RGE_Map* Map, RGE_Static_Object* LastCliffObject, float& AngleToTarget, int& HigherCalc
) {
    if (YTileInt < 0 || YTileInt >= Map->map_height || XTileInt < 0 || XTileInt >= Map->map_width) {
        return 0;
    }

    RGE_Object_Node* node = Map->map_row_offset[YTileInt][XTileInt].objects.list;
    while (node != 0) {
        RGE_Static_Object* cliff = node->node;
        if (cliff->master_obj->object_group == OBJECT_GROUP_CLIFF && cliff != LastCliffObject) {
            LastCliffObject = cliff;
            if (AngleToTarget == -1.0f) {
                AngleToTarget = atan2(target->world_y - this->world_y, target->world_x - this->world_x);
                if (AngleToTarget < 0.0f)
                    AngleToTarget -= g_angle_negative_two_pi;
            }

            const int facet = cliff->facet;
            if (lines_intersect(
                    StartX, StartY, DestX, DestY, TRIBE_Cliff_Higher_Check_Table[facet].line_x1 + StartX,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_y1 + StartY,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_x2 + DestX,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_y2 + DestY
                )) {
                if ((facet >= 0x19 || AngleToTarget < TRIBE_Cliff_Higher_Check_Table[facet].from_angle1
                     || AngleToTarget > TRIBE_Cliff_Higher_Check_Table[facet].to_angle1)
                    && (AngleToTarget < TRIBE_Cliff_Higher_Check_Table[facet].from_angle2
                        || AngleToTarget > TRIBE_Cliff_Higher_Check_Table[facet].to_angle2)) {
                    --HigherCalc;
                } else {
                    ++HigherCalc;
                }
                return 1;
            }
        }
        node = node->next;
    }
    return 0;
}

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* target) {
    if (this->world_z > target->world_z) {
        return 1;
    }

    float StartX = this->world_x;
    float StartY = this->world_y;
    float DestX = target->world_x;
    float DestY = target->world_y;
    float Dx = DestX - StartX;
    float Dy = DestY - StartY;
    if (Dx == g_combat_zero_float && Dy == g_combat_zero_float) {
        return 0;
    }

    int NumSteps;
    if (fabs(Dy) > fabs(Dx)) {
        NumSteps = abs(static_cast<int>(Dy)) * 2;
    } else {
        NumSteps = abs(static_cast<int>(Dx)) * 2;
    }

    float XStep = Dx / NumSteps;
    float YStep = Dy / NumSteps;
    int Tile_Dx1;
    int Tile_Dy1;
    int Tile_Dx2;
    int Tile_Dy2;
    if (XStep < g_combat_zero_float) {
        Dx = -XStep;
    } else {
        Dx = XStep;
    }
    if (YStep < g_combat_zero_float) {
        Dy = -YStep;
    } else {
        Dy = YStep;
    }
    if (Dx > Dy) {
        Tile_Dx1 = 0;
        Tile_Dy1 = -1;
        Tile_Dx2 = 0;
        Tile_Dy2 = 1;
    } else {
        Tile_Dx1 = -1;
        Tile_Dy1 = 0;
        Tile_Dx2 = 1;
        Tile_Dy2 = 0;
    }

    float XTile = StartX;
    float YTile = StartY;
    int PriorX = -999;
    int PriorY = -999;
    RGE_Map* Map = this->owner->world->map;
    float AngleToTarget = -1.0f;
    int HigherCalc = 0;

    while (NumSteps > 0) {
        XTile += XStep;
        YTile += YStep;
        int XTileInt = static_cast<int>(XTile);
        int YTileInt = static_cast<int>(YTile);
        if (XTileInt != PriorX || YTileInt != PriorY) {
            PriorX = XTileInt;
            PriorY = YTileInt;
            if (this->higher_check_for_cliff(
                    target, XTileInt, YTileInt, StartX, StartY, DestX, DestY, Map, 0, AngleToTarget, HigherCalc
                ) == 0
                && this->higher_check_for_cliff(
                       target, XTileInt + Tile_Dx1, YTileInt + Tile_Dy1, StartX, StartY, DestX, DestY, Map, 0,
                       AngleToTarget, HigherCalc
                   ) == 0) {
                this->higher_check_for_cliff(
                    target, XTileInt + Tile_Dx2, YTileInt + Tile_Dy2, StartX, StartY, DestX, DestY, Map, 0,
                    AngleToTarget, HigherCalc
                );
            }
        }
        --NumSteps;
    }

    if (HigherCalc < 1) {
        HigherCalc = 0;
    }
    if (HigherCalc > 0) {
        HigherCalc = 1;
    }
    return HigherCalc > 0;
}

unsigned char TRIBE_Combat_Object::area_attack(
    float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignore_object
) {
    float attack_modifier;
    RGE_Map* map = this->owner->world->map;
    float r2 = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range;
    short max_x = (short) map->map_width;
    short max_y = (short) map->map_height;
    float radius_squared = r2 * r2;
    --max_x;
    --max_y;
    //! This early-out also tests blast radius where blast level is the criterion.
    if (!(r2 > g_combat_zero_range))
        return 0;

    short x1;
    x1 = (short) (x - r2);
    x1 = x1 - 2;
    short x0;
    x0 = (short) (x + r2);
    x0 = x0 + 2;
    short first_y;
    first_y = (short) (y - r2);
    first_y = first_y - 2;
    short last_y;
    last_y = (short) (y + r2);
    last_y = last_y + 2;
    if (x1 < 0)
        x1 = 0;
    if (x0 > max_x + 1)
        x0 = max_x + 1;
    if (first_y < 0)
        first_y = 0;
    if (last_y > max_y + 1)
        last_y = max_y + 1;

    for (short row = first_y; row < last_y; row++) {
        for (short col = x1; col < x0; col++) {
            RGE_Object_Node* link = map->map_row_offset[row][col].objects.list;
            while (link != 0) {
                RGE_Combat_Object* object = static_cast<RGE_Combat_Object*>(link->node);
                if (object != ignore_object) {
                    const short master_id = this->master_obj->id;
                    if (!(((master_id == MASTER_OBJECT_SOLDIER_ELEPHANT || master_id == MASTER_OBJECT_SOLDIER_CHARIOT1
                            || master_id == MASTER_OBJECT_SOLDIER_HVY_CHARIOT
                            || master_id == MASTER_OBJECT_SOLDIER_ARMOR_ELEPHANT)
                           && object->owner == this->owner)
                          || object == this)
                        && object->master_obj->area_effect_object_level
                               >= static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_level) {
                        float dx = object->world_x - x;
                        float dy = object->world_y - y;
                        if (dx < g_combat_zero_float)
                            dx = -dx;
                        if (dy < g_combat_zero_float)
                            dy = -dy;
                        float radius_x = object->master_obj->radius_x;
                        float ry = object->master_obj->radius_y;
                        if (dx > radius_x)
                            dx -= radius_x;
                        else
                            dx = g_combat_zero_float;
                        if (dy > ry)
                            dy -= ry;
                        else
                            dy = g_combat_zero_float;
                        if (radius_squared > dx * dx + dy * dy) {
                            int chance = debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 1619) * 100 / 0x7fff;
                            if ((short) chance
                                <= static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
                                attack_modifier = this->calc_attack_modifier(object);
                                object->damage(
                                    static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
                                    static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon, attack_modifier,
                                    this->owner, attacker
                                );
                                if (object->hp < g_combat_one_float) {
                                    object->set_attribute_amount(0.0f, 0, 1);
                                }
                            }
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}

unsigned char TRIBE_Combat_Object::heal(float healing) {
    TRIBE_Master_Combat_Object* master = static_cast<TRIBE_Master_Combat_Object*>(this->master_obj);
    const short type = master->object_group;
    if (type != OBJECT_GROUP_TRADE_BOAT && type != OBJECT_GROUP_TRANSPORT_BOAT && type != OBJECT_GROUP_FISHING_BOAT
        && type != OBJECT_GROUP_WAR_BOAT) {
        return RGE_Static_Object::heal(healing);
    }

    healing = healing * master->hp / master->build_pts_required;
    if (healing + this->hp > master->hp) {
        healing = master->hp - this->hp;
    }

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->owner);
    if (player->pay_obj_cost(master->id, healing / static_cast<float>(master->hp * 2), 1)) {
        return RGE_Static_Object::heal(healing);
    }
    return 2;
}

int TRIBE_Combat_Object::canRepair() {
    const float maximum = static_cast<float>(this->master_obj->hp);
    return static_cast<TRIBE_Player*>(this->owner)
               ->check_obj_cost(this->master_obj->id, 0, (maximum - this->hp) / maximum, 0)
           != 0;
}

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* obj) {
    RGE_Task* task;
    RGE_Task_List* repair_list;
    int skip;
    int task_count;
    RGE_Task** task_list;
    RGE_Task* current_task;
    short action_type;
    int action_worked;
    RGE_Action* action;
    int order;
    int current_action;

    if (static_cast<RGE_Action_Object*>(obj) != this) {
        if (this->master_obj->id != MASTER_OBJECT_REPAIR_MAN) {
            this->transform(this->owner->master_objects[MASTER_OBJECT_REPAIR_MAN]);
        }

        repair_list = static_cast<RGE_Master_Action_Object*>(this->master_obj)->tasks;
        skip = 0;
        task_count = static_cast<int>(repair_list->list_num);
        if (task_count > 0) {
            task_list = repair_list->list;
            task = 0;
            do {
                task = *task_list;
                if (task->action_type == TRIBE_ACTION_TYPE_REPAIR) {
                    RGE_Master_Static_Object* target_master = obj->master_obj;
                    if (target_master->master_type == TRIBE_MASTER_TYPE_BUILDING) {
                        if (task->object_group == -1 || task->object_group == 0) {
                            break;
                        }
                    }
                    if (task->object_group == target_master->object_group) {
                        break;
                    }
                }
                task = 0;
                ++skip;
                ++task_list;
            } while (skip < task_count);
        }

        current_task = this->actions->get_task();
        action_type = 0;
        action_worked = 0;
        if (current_task != 0 && task == current_task
            && this->actions->action_work(obj, obj->world_x, obj->world_y, obj->world_z) != 0) {
            action_type = this->actions->get_action()->type();
            action_worked = 1;
        }

        if (action_worked == 0) {
            if (task != 0) {
                action = this->actions->create_task_action(task, obj, obj->world_x, obj->world_y, obj->world_z);
            } else {
                action = 0;
            }

            if (action != 0) {
                action_type = action->type();
                this->set_only_action(action);
            } else {
                action_type = 0;
            }
        }

        if (this->unitAIValue != 0) {
            order = -1;
            current_action = -1;
            if (action_type == TRIBE_ACTION_TYPE_REPAIR) {
                current_action = UNIT_AI_ACTION_REPAIR;
                order = UNIT_AI_ORDER_REPAIR;
            }
            this->unitAIValue->setCurrentOrder(order);
            this->unitAIValue->setCurrentAction(current_action);
            this->unitAIValue->setCurrentTarget(
                obj->id, obj->master_obj->object_group, obj->world_x, obj->world_y, obj->world_z
            );
            this->unitAIValue->setTaskedByPlayer();
        }
    }
}
