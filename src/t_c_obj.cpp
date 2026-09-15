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

extern float DAT_00574c78;
extern float DAT_00574c7c;
extern float DAT_00574c80;
extern double DAT_00574c88;
extern float DAT_00574c90;
extern float DAT_00574c94;
extern float DAT_00574ca0;
extern float DAT_00574c98;
extern float DAT_00574ca4;
extern double DAT_00574ca8;
extern int __cdecl debug_rand(char*, int);
int __cdecl lines_intersect(float a_x1, float a_y1, float a_x2, float a_y2,
                            float b_x1, float b_y1, float b_x2, float b_y2);

TRIBE_Combat_Object::TRIBE_Combat_Object(
    TRIBE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y,
    float z, int do_setup)
    : RGE_Combat_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }
}

TRIBE_Combat_Object::TRIBE_Combat_Object(int infile, RGE_Game_World* gworld,
                                         int do_setup)
    : RGE_Combat_Object(infile, gworld, 0) {
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
    if (group == 4 || group == 0x15 || group == 2) {
        this->owner->attributes[37] -= DAT_00574c78;
    } else if ((group != 0x12 && master->master_type == 'F') ||
               master->id == 'O' || master->id == 'E' ||
               master->id == 0xC7) {
        this->owner->attributes[40] -= DAT_00574c78;
    }
}

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* tobj,
                               RGE_Player* obj_owner, float x, float y, float z) {
    RGE_Combat_Object::setup(tobj, obj_owner, x, y, z);

    if (this->owner->id == 0) {
        this->capture_flag = 1;
    }

    this->type = 0x46;
    this->initUnitAI();
    this->own_master = 0;

    if (this->master_obj->object_group == 4 ||
        this->master_obj->object_group == 0x15 ||
        this->master_obj->object_group == 2) {
        this->owner->attributes[37] -= DAT_00574c7c;
    } else if ((this->master_obj->object_group != 0x12 &&
                this->master_obj->master_type == 'F') ||
               this->master_obj->id == 0x4F || this->master_obj->id == 0x45 ||
               this->master_obj->id == 0xC7) {
        this->owner->attributes[40] -= DAT_00574c7c;
    }

    if (this->master_obj->object_group == 0x12) {
        this->attribute_amount_held = 100.0f;
        this->attribute_type_held = 0x22;
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
        if (master_type == 'F') {
            this->master_obj = new TRIBE_Master_Combat_Object(
                infile, this->owner->world->sprites, this->owner->world->sounds,
                1);
        } else if (master_type == 'P') {
            this->master_obj = new TRIBE_Master_Building_Object(
                infile, this->owner->world->sprites, this->owner->world->sounds,
                1);
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
    if (this->master_obj->object_group == 0x12 && this->object_state == 2) {
        this->attribute_amount_held +=
            this->owner->attributes[35] *
            this->owner->world->world_time_delta_seconds;
        if (this->attribute_amount_held >= 100.0f) {
            this->attribute_amount_held = 100.0f;
        }
        this->attribute_type_held = 0x22;
    }
    return RGE_Combat_Object::update();
}

void TRIBE_Combat_Object::modify(float amount, unsigned char flag) {
    if (flag == 0x65) {
        for (int i = 0; i < 3; ++i) {
            if (this->master_obj->attribute_type_held[i] == 4) {
                this->owner->attributes[4] -=
                    this->master_obj->attribute_amount_held[i];
                this->owner->attributes[4] += amount;
            }
            if (this->master_obj->attribute_type_held[i] == 0x0B) {
                this->owner->attributes[11] -=
                    this->master_obj->attribute_amount_held[i];
                this->owner->attributes[11] -= amount;
            }
            if (this->master_obj->attribute_type_held[i] == 0x13) {
                this->owner->attributes[19] -=
                    this->master_obj->attribute_amount_held[i];
                this->owner->attributes[19] -= amount;
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
    if (this->owner->world->game_state == 0 && new_object_state >= 3 &&
        this->object_state <= 2 && this->master_obj->object_group == 1) {
        this->reposition_artifact();
    } else {
        RGE_Static_Object::set_object_state(new_object_state);
    }
}

void TRIBE_Combat_Object::cancel_object() {
    this->die_die_die();
}

void TRIBE_Combat_Object::die_die_die() {
    if (this->object_state == 2 && this->owner->attributes[57] >= 1.0f) {
        RGE_Action* action = this->actions->get_action();
        if (action != 0 && action->type() == 0x68) {
            static_cast<TRIBE_Action_Convert*>(action)->martyrdom();
        }
    }
    RGE_Static_Object::die_die_die();
}

void TRIBE_Combat_Object::damage(int weapon_num, RGE_Armor_Weapon_Info* damage,
                                 float attack_modifier, RGE_Player* attacking_player,
                                 RGE_Static_Object* attackingObject) {
    const float temp_hp = this->hp;
    if (this->hp >= DAT_00574c88) {
        RGE_Combat_Object::damage(weapon_num, damage, attack_modifier,
                                   attacking_player, attackingObject);

        if (this->hp < DAT_00574c88 &&
            this->produceWhenKilledBy(attackingObject->master_obj->object_group) ==
                0) {
            this->set_attribute_amount(0.0f, 0, 1);
        }

        if (temp_hp - this->hp < DAT_00574c88) {
            this->hp = temp_hp - DAT_00574c78;
        }

        if (this->owner->id > 0 && this->hp < DAT_00574c78) {
            attacking_player->add_attribute_num(0x14, 1.0f, 0);
        }
    }
}

void TRIBE_Combat_Object::change_ownership(RGE_Player* new_owner) {
    if (this->id >= 0) {
        for (int i = 0; i < 9; ++i) {
            if (this->VUR_Ptrs[i] != 0) {
                this->VUR_Ptrs[i]->player = static_cast<unsigned char>(new_owner->id);
            }
        }
    }

    if (this->master_obj->object_group == 1) {
        RGE_Action_Object::change_ownership(new_owner);
        return;
    }

    if (new_owner->master_objects[this->master_obj->id] != 0) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object(this);
        }

        this->take_attribute_from_owner();
        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                                  this->player_object_node);
        this->player_object_node = new_owner->addObject(
            this, this->sleep_flag, this->dopple_flag);

        if (this->object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->owner = new_owner;

        if (this->own_master == 0) {
            this->master_obj = this->master_obj->make_new_master();
            this->own_master = 1;
        }

        if (this->object_state == 2) {
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
    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (master->missile_id >= 0) {
        if (this->higher_than_target(target) != 0) {
            return 1.5f;
        }
    } else if (this->world_z < target->world_z) {
        return 0.6666f;
    }
    return 1.0f;
}

unsigned char TRIBE_Combat_Object::attack(RGE_Static_Object* target,
                                          RGE_Combat_Object* attacker) {
    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (master->missile_id >= 0 && target != 0 && target->owner->id > 0) {
        target->owner->make_new_object(0x70, this->world_x, this->world_y,
                                       this->world_z, 0);
    }
    return RGE_Combat_Object::attack(target, attacker);
}

unsigned char TRIBE_Combat_Object::do_attack(RGE_Static_Object* target,
                                             RGE_Combat_Object* attacker,
                                             float x, float y, float z) {
    if (target == 0) {
        return 0;
    }

    if (rge_base_game->quick_build != 0 &&
        (this->master_obj->id == 0x7A || this->master_obj->id == 0x7B)) {
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        target->die_die_die();
        return 1;
    }

    if (static_cast<RGE_Master_Combat_Object*>(this->master_obj)
                ->area_effect_range > 0.0f &&
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)
                ->weapon_range < 0.99f) {
        this->area_attack(x, y, z, attacker, target);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        const int chance =
            debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x211) *
            100 / 0x7FFF;
        if (chance <= static_cast<RGE_Master_Combat_Object*>(this->master_obj)
                         ->base_hit_chance) {
            const float attack_modifier = this->calc_attack_modifier(target);
            target->damage(
                static_cast<RGE_Master_Combat_Object*>(this->master_obj)
                    ->weapon_num,
                static_cast<RGE_Master_Combat_Object*>(this->master_obj)
                    ->weapon,
                attack_modifier, this->owner, attacker);
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(target, attacker, x, y, z);
}

void TRIBE_Combat_Object::get_armor(short& cur_armor_in, short& orig_armor_in) {
    cur_armor_in =
        static_cast<RGE_Master_Combat_Object*>(master_obj)->base_armor;
    for (int i = 0;
         i < static_cast<RGE_Master_Combat_Object*>(master_obj)->armor_num;
         ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].type ==
                4 &&
            static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value >
                cur_armor_in) {
            cur_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)
                        ->armor[i]
                        .value;
        }
    }
    orig_armor_in =
        static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_armor;
}

void TRIBE_Combat_Object::get_pierce_armor(short& cur_armor_in,
                                           short& orig_armor_in) {
    cur_armor_in = 0;
    for (int i = 0;
         i < static_cast<RGE_Master_Combat_Object*>(this->master_obj)->armor_num;
         ++i) {
        RGE_Master_Combat_Object* master =
            static_cast<RGE_Master_Combat_Object*>(this->master_obj);
        if (master->armor[i].type == 3 &&
            master->armor[i].value > cur_armor_in) {
            cur_armor_in = master->armor[i].value;
        }
    }
    orig_armor_in = static_cast<TRIBE_Master_Combat_Object*>(this->master_obj)
                        ->orig_pierce_armor;
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
            terrain = map->get_terrain(
                static_cast<short>(i), static_cast<short>(x2));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(i) - DAT_00574ca0;
                x_pos = static_cast<float>(x2) - DAT_00574ca0;
                placement = this->master_obj->check_placement(
                    this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
                if (placement == 0) {
                    x = 1;
                    break;
                }
            }

            terrain = map->get_terrain(static_cast<short>(i),
                                       static_cast<short>(found_pos));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(i) - DAT_00574ca0;
                x_pos = static_cast<float>(found_pos) - DAT_00574ca0;
                placement = this->master_obj->check_placement(
                    this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
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

            terrain = map->get_terrain(
                static_cast<short>(y2), static_cast<short>(j));
            if (terrain != 1 && terrain != 2) {
                y1 = static_cast<float>(y2) - DAT_00574ca0;
                x_pos = static_cast<float>(j) - DAT_00574ca0;
                placement = this->master_obj->check_placement(
                    this->owner, y1, x_pos, 0, 1, 1, 1, 0, 1, 1);
                if (placement == 0) {
                    x = 1;
                    break;
                }
            }

            terrain = map->get_terrain(static_cast<short>(x1),
                                       static_cast<short>(j));
            if (terrain == 1 || terrain == 2) {
                continue;
            }
            y1 = static_cast<float>(x1) - DAT_00574ca0;
            x_pos = static_cast<float>(j) - DAT_00574ca0;
            placement = this->master_obj->check_placement(
                this->owner, y1, x_pos, 0, 0, 1, 1, 0, 1, 1);
            if (placement == 0) {
                x = 1;
                break;
            }
        }

        if (x) {
            break;
        }

        if (y2 == 0 && x1 == map_max_x && x2 == 0 &&
            found_pos == map_max_y) {
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
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x6E) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x6E) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x,
                                   target->world_y, target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Hunt* action = new TRIBE_Action_Hunt(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::convert(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x68) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x68) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x,
                                   target->world_y, target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Convert* action = new TRIBE_Action_Convert(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::heal(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x69) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x69) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x,
                                   target->world_y, target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Heal* action = new TRIBE_Action_Heal(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::repair(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x6A) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x6A) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Master_Static_Object* repair_master =
        this->owner->master_objects[0x9C];
    if (repair_master != 0) {
        this->transform(repair_master);
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y,
                                   target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Repair* action = new TRIBE_Action_Repair(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::build(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x65) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x65) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x, target->world_y,
                                   target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Build* action = new TRIBE_Action_Build(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int TRIBE_Combat_Object::trade(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) return 0;

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 0x6F) return 1;

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 0x6F) {
        this->actions->get_action()->work(target, target->world_x,
                                          target->world_y, target->world_z);
        return 1;
    }

    RGE_Task* task = this->getTask(target, target->world_x,
                                   target->world_y, target->world_z);
    if (task == 0) return 0;

    TRIBE_Action_Trade* action = new TRIBE_Action_Trade(this, task, target);
    if (action == 0) return 0;

    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

unsigned char TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int oType) const {
    if (oType != 0x32 && oType != 0x2D) {
        return 0;
    }
    return 1;
}

unsigned char TRIBE_Combat_Object::produceWhenKilledBy(int oGroup) const {
    const int group = this->master_obj->object_group;
    if (group != 9 && group != 10) return 1;
    if (oGroup != 4) return 0;
    return 1;
}

unsigned char TRIBE_Combat_Object::useSameZoneDropsite() const {
    const int group = this->master_obj->object_group;
    if (group == 0x15 || group == 2) return 0;
    return 1;
}

void TRIBE_Combat_Object::initUnitAI() {
    RGE_Master_Static_Object* master = this->master_obj;
    switch (master->object_group) {
    case 1:
        if (master->id == 0x63 || master->id == 0x0A) return;
        this->unitAIValue = new TribeArtifactUnitAIModule(this, 5);
        return;
    case 4:
        this->unitAIValue = new TribeCivilianUnitAIModule(this, 10);
        return;
    case 0x12:
        this->unitAIValue = new TribePriestUnitAIModule(this, 10);
        return;
    case 9:
        this->unitAIValue = new TribeHuntedAnimalUnitAIModule(this, 10);
        return;
    case 0x0A:
        if (master->id == 0x9D) {
            this->unitAIValue = new TribeHuntedAnimalUnitAIModule(this, 10);
        } else if (master->id == 0x30) {
            this->unitAIValue = new TribeElephantUnitAIModule(this, 10);
        } else if (master->id == 0x7E) {
            this->unitAIValue = new TribeLionUnitAIModule(this, 10);
        } else {
            this->unitAIValue = new TribePreditorUnitAIModule(this, 10);
        }
        return;
    case 0x15:
        this->unitAIValue = new TribeFishingShipUnitAIModule(this, 10);
        return;
    case 2:
        this->unitAIValue = new TribeTradeShipUnitAIModule(this, 10);
        return;
    case 0x14:
        this->unitAIValue = new TribeTransportShipUnitAIModule(this, 10);
        return;
    case 3:
    case 0x1B:
        if (master->id == 0x4F || master->id == 0xC7 || master->id == 0x45 ||
            master->id == 0x116 || master->id == 0x17F ||
            master->id == 0x17C) {
            this->unitAIValue = new TribeTowerUnitAIModule(this, 10);
        } else {
            this->unitAIValue = new TribeBuildingUnitAIModule(this, 10);
        }
        return;
    case 5:
    case 7:
    case 8:
    case 0x0B:
    case 0x0E:
    case 0x0F:
    case 0x10:
    case 0x1D:
    case 0x1E:
    case 0x1F:
    case 0x20:
    case 0x21:
        return;
    default:
        this->unitAIValue = new TribeSoldierUnitAIModule(this, 10);
        return;
    }
}

int __cdecl lines_intersect(float a_x1, float a_y1, float a_x2, float a_y2,
                            float b_x1, float b_y1, float b_x2, float b_y2) {
    return 1;
}

int TRIBE_Combat_Object::higher_check_for_cliff(
    RGE_Static_Object* target, int XTileInt, int YTileInt, float StartX,
    float StartY, float DestX, float DestY, RGE_Map* Map,
    RGE_Static_Object* LastCliffObject, float& AngleToTarget, int& HigherCalc) {
    if (YTileInt < 0 || YTileInt >= Map->map_height || XTileInt < 0 ||
        XTileInt >= Map->map_width) {
        return 0;
    }

    RGE_Object_Node* node =
        Map->map_row_offset[YTileInt][XTileInt].objects.list;
    while (node != 0) {
        RGE_Static_Object* cliff = node->node;
        if (cliff->master_obj->object_group == 0x22 &&
            cliff != LastCliffObject) {
            LastCliffObject = cliff;
            if (AngleToTarget == -1.0f) {
                AngleToTarget = atan2(target->world_y - this->world_y,
                                      target->world_x - this->world_x);
                if (AngleToTarget < 0.0f) AngleToTarget -= DAT_00574ca4;
            }

            const int facet = cliff->facet;
            if (lines_intersect(
                    StartX, StartY, DestX, DestY,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_x1 + StartX,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_y1 + StartY,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_x2 + DestX,
                    TRIBE_Cliff_Higher_Check_Table[facet].line_y2 + DestY)) {
                if ((facet >= 0x19 ||
                     AngleToTarget <
                         TRIBE_Cliff_Higher_Check_Table[facet].from_angle1 ||
                     AngleToTarget >
                         TRIBE_Cliff_Higher_Check_Table[facet].to_angle1) &&
                    (AngleToTarget <
                         TRIBE_Cliff_Higher_Check_Table[facet].from_angle2 ||
                     AngleToTarget >
                         TRIBE_Cliff_Higher_Check_Table[facet].to_angle2)) {
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
    if (Dx == DAT_00574c98 && Dy == DAT_00574c98) {
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
    if (XStep < DAT_00574c98) {
        Dx = -XStep;
    } else {
        Dx = XStep;
    }
    if (YStep < DAT_00574c98) {
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
                    target, XTileInt, YTileInt, StartX, StartY, DestX, DestY,
                    Map, 0, AngleToTarget, HigherCalc) == 0 &&
                this->higher_check_for_cliff(
                    target, XTileInt + Tile_Dx1, YTileInt + Tile_Dy1,
                    StartX, StartY, DestX, DestY, Map, 0, AngleToTarget,
                    HigherCalc) == 0) {
                this->higher_check_for_cliff(
                    target, XTileInt + Tile_Dx2, YTileInt + Tile_Dy2,
                    StartX, StartY, DestX, DestY, Map, 0, AngleToTarget,
                    HigherCalc);
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
    float x, float y, float z, RGE_Combat_Object* attacker,
    RGE_Static_Object* ignore_object) {
    float attack_modifier;
    RGE_Map* map = this->owner->world->map;
    float r2 =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)
            ->area_effect_range;
    short max_x = (short)map->map_width;
    short max_y = (short)map->map_height;
    float radius_squared = r2 * r2;
    --max_x;
    --max_y;
    if (!(r2 > DAT_00574ca8)) return 0;

    short x1;
    x1 = (short)(x - r2);
    x1 = x1 - 2;
    short x0;
    x0 = (short)(x + r2);
    x0 = x0 + 2;
    short first_y;
    first_y = (short)(y - r2);
    first_y = first_y - 2;
    short last_y;
    last_y = (short)(y + r2);
    last_y = last_y + 2;
    if (x1 < 0) x1 = 0;
    if (x0 > max_x + 1) x0 = max_x + 1;
    if (first_y < 0) first_y = 0;
    if (last_y > max_y + 1) last_y = max_y + 1;

    for (short row = first_y; row < last_y; row++) {
        for (short col = x1; col < x0; col++) {
            RGE_Object_Node* link =
                map->map_row_offset[row][col].objects.list;
            while (link != 0) {
                RGE_Combat_Object* object =
                    static_cast<RGE_Combat_Object*>(link->node);
                if (object != ignore_object) {
                    const short master_id = this->master_obj->id;
                    if (!(((master_id == 0x2E || master_id == 0x28 ||
                            master_id == 0x153 || master_id == 0x159) &&
                           object->owner == this->owner) ||
                          object == this) &&
                        object->master_obj->area_effect_object_level >=
                            static_cast<RGE_Master_Combat_Object*>(
                                this->master_obj)->area_effect_level) {
                        float dx = object->world_x - x;
                        float dy = object->world_y - y;
                        if (dx < DAT_00574c98) dx = -dx;
                        if (dy < DAT_00574c98) dy = -dy;
                        float radius_x = object->master_obj->radius_x;
                        float ry = object->master_obj->radius_y;
                        if (dx > radius_x) dx -= radius_x;
                        else dx = DAT_00574c98;
                        if (dy > ry) dy -= ry;
                        else dy = DAT_00574c98;
                        if (radius_squared > dx * dx + dy * dy) {
                            int chance =
                                debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp",
                                           0x653) * 100 / 0x7fff;
                            if ((short)chance <=
                                static_cast<RGE_Master_Combat_Object*>(
                                    this->master_obj)->base_hit_chance) {
                                attack_modifier =
                                    this->calc_attack_modifier(object);
                                object->damage(
                                    static_cast<RGE_Master_Combat_Object*>(
                                        this->master_obj)->weapon_num,
                                    static_cast<RGE_Master_Combat_Object*>(
                                        this->master_obj)->weapon,
                                    attack_modifier, this->owner, attacker);
                                if (object->hp < DAT_00574c78) {
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
    RGE_Master_Static_Object* master = this->master_obj;
    const short type = master->object_group;
    if (type != 2 && type != 0x14 && type != 0x15 && type != 0x16) {
        return RGE_Static_Object::heal(healing);
    }

    const long max_hp = master->hp;
    const long heal_rate =
        static_cast<TRIBE_Master_Combat_Object*>(master)->build_pts_required;
    const float maximum = static_cast<float>(max_hp);
    if ((healing = healing * maximum / heal_rate) + this->hp > maximum) {
        healing = maximum - this->hp;
    }

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->owner);
    if (player->pay_obj_cost(master->id,
                             healing / static_cast<float>(max_hp * 2), 1)) {
        return RGE_Static_Object::heal(healing);
    }
    return 2;
}

int TRIBE_Combat_Object::canRepair() {
    const float maximum = static_cast<float>(this->master_obj->hp);
    return static_cast<TRIBE_Player*>(this->owner)->check_obj_cost(
        this->master_obj->id, 0, (maximum - this->hp) / maximum, 0) != 0;
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
        if (this->master_obj->id != 0x9C) {
            this->transform(this->owner->master_objects[0x9C]);
        }

        repair_list =
            static_cast<RGE_Master_Action_Object*>(this->master_obj)->tasks;
        skip = 0;
        task_count = static_cast<int>(repair_list->list_num);
        if (task_count > 0) {
            task_list = repair_list->list;
            task = 0;
            do {
                task = *task_list;
                if (task->action_type == 0x6A) {
                    RGE_Master_Static_Object* target_master =
                        obj->master_obj;
                    if (target_master->master_type == 'P') {
                        if (task->object_group == -1 ||
                            task->object_group == 0) {
                            break;
                        }
                    }
                    if (task->object_group ==
                        target_master->object_group) {
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
        if (current_task != 0 && task == current_task &&
            this->actions->action_work(obj, obj->world_x, obj->world_y,
                                       obj->world_z) != 0) {
            action_type = this->actions->get_action()->type();
            action_worked = 1;
        }

        if (action_worked == 0) {
            if (task != 0) {
                action = this->actions->create_task_action(
                    task, obj, obj->world_x, obj->world_y, obj->world_z);
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
            if (action_type == 0x6A) {
                current_action = 0x26A;
                order = 0x2CE;
            }
            this->unitAIValue->setCurrentOrder(order);
            this->unitAIValue->setCurrentAction(current_action);
            this->unitAIValue->setCurrentTarget(
                obj->id, obj->master_obj->object_group, obj->world_x,
                obj->world_y, obj->world_z);
            this->unitAIValue->setTaskedByPlayer();
        }
    }
}
