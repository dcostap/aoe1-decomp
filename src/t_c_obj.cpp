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
extern "C" int __cdecl debug_rand(const char*, int);
int __cdecl lines_intersect(float, float, float, float, float, float, float,
                            float);

TRIBE_Combat_Object::TRIBE_Combat_Object(
    TRIBE_Master_Combat_Object* master, RGE_Player* player, float x, float y,
    float z, int flag)
    : RGE_Combat_Object(master, player, x, y, z, 0)
{
    if (flag != 0) {
        setup(master, player, x, y, z);
    }
}

TRIBE_Combat_Object::TRIBE_Combat_Object(int mode, RGE_Game_World* world,
                                         int do_setup)
    : RGE_Combat_Object(mode, world, 0)
{
    if (do_setup != 0) {
        setup(mode, world);
    }
}

TRIBE_Combat_Object::~TRIBE_Combat_Object()
{
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

int TRIBE_Combat_Object::setup(TRIBE_Master_Combat_Object* master,
                               RGE_Player* player, float x, float y, float z)
{
    RGE_Combat_Object::setup(master, player, x, y, z);

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

int TRIBE_Combat_Object::setup(int file, RGE_Game_World* world)
{
    RGE_Combat_Object::setup(file, world);
    this->type = 0x46;
    rge_read(file, &this->own_master, 1);

    if (this->own_master != 0) {
        unsigned char master_type;
        rge_read(file, &master_type, 1);
        if (master_type == 'F') {
            this->master_obj = new TRIBE_Master_Combat_Object(
                file, this->owner->world->sprites, this->owner->world->sounds,
                1);
        } else if (master_type == 'P') {
            this->master_obj = new TRIBE_Master_Building_Object(
                file, this->owner->world->sprites, this->owner->world->sounds,
                1);
        }
    }

    int has_unit_ai;
    rge_read(file, &has_unit_ai, 4);
    if (has_unit_ai == 1) {
        this->initUnitAI();
        if (this->unitAIValue != 0) {
            this->unitAIValue->load(file);
        }
    }
    return 1;
}

RGE_Action_List* TRIBE_Combat_Object::create_action_list()
{
    return new TRIBE_Action_List(this);
}

void TRIBE_Combat_Object::save(int file)
{
    RGE_Combat_Object::save(file);
    rge_write(file, &this->own_master, 1);

    if (this->own_master != 0) {
        this->master_obj->save(file);
    }

    int has_unit_ai = this->unitAIValue != 0;
    rge_write(file, &has_unit_ai, 4);
    if (this->unitAIValue != 0) {
        this->unitAIValue->save(file);
    }
}

unsigned char TRIBE_Combat_Object::update()
{
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

void TRIBE_Combat_Object::modify(float value, unsigned char attribute)
{
    if (attribute == 0x65) {
        RGE_Master_Static_Object* master = this->master_obj;
        for (int i = 0; i < 3; ++i) {
            if (master->attribute_type_held[i] == 4) {
                this->owner->attributes[4] -= master->attribute_amount_held[i];
                this->owner->attributes[4] += value;
            }
            if (master->attribute_type_held[i] == 0x0B) {
                this->owner->attributes[11] -= master->attribute_amount_held[i];
                this->owner->attributes[11] += value;
            }
            if (master->attribute_type_held[i] == 0x13) {
                this->owner->attributes[19] -= master->attribute_amount_held[i];
                this->owner->attributes[19] += value;
            }
        }
    }
    RGE_Static_Object::modify(value, attribute);
}

void TRIBE_Combat_Object::transform(RGE_Master_Static_Object* master)
{
    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Action_Object::transform(master);
    if (this->own_master == 1) {
        if (old_master != 0) {
            delete old_master;
        }
        this->own_master = 0;
    }
}

void TRIBE_Combat_Object::set_object_state(unsigned char state)
{
    if (this->owner->world->game_state == 0 && state >= 3 &&
        this->object_state <= 2 && this->master_obj->object_group == 1) {
        this->reposition_artifact();
    } else {
        RGE_Static_Object::set_object_state(state);
    }
}

void TRIBE_Combat_Object::cancel_object()
{
    this->die_die_die();
}

void TRIBE_Combat_Object::die_die_die()
{
    if (this->object_state == 2 && this->owner->attributes[57] >= 1.0f) {
        RGE_Action* action = this->actions->get_action();
        if (action != 0 && action->type() == 0x68) {
            static_cast<TRIBE_Action_Convert*>(action)->martyrdom();
        }
    }
    RGE_Static_Object::die_die_die();
}

void TRIBE_Combat_Object::damage(int amount, RGE_Armor_Weapon_Info* armor,
                                 float value, RGE_Player* player,
                                 RGE_Static_Object* target)
{
    const float original_hp = this->hp;
    if (this->hp >= DAT_00574c88) {
        RGE_Combat_Object::damage(amount, armor, value, player, target);

        if (this->hp < DAT_00574c88 &&
            this->produceWhenKilledBy(target->master_obj->object_group) == 0) {
            this->set_attribute_amount(0.0f, 0, 1);
        }

        if (original_hp - this->hp < DAT_00574c88) {
            this->hp = original_hp - DAT_00574c78;
        }

        if (this->owner->id > 0 && this->hp < DAT_00574c78) {
            player->add_attribute_num(0x14, 1.0f, 0);
        }
    }
}

void TRIBE_Combat_Object::change_ownership(RGE_Player* player)
{
    if (this->id >= 0) {
        for (int i = 0; i < 9; ++i) {
            if (this->VUR_Ptrs[i] != 0) {
                this->VUR_Ptrs[i]->player = static_cast<unsigned char>(player->id);
            }
        }
    }

    if (this->master_obj->object_group == 1) {
        RGE_Action_Object::change_ownership(player);
        return;
    }

    if (player->master_objects[this->master_obj->id] != 0) {
        if ((this->selected & 1) != 0) {
            this->owner->unselect_one_object(this);
        }

        this->take_attribute_from_owner();
        this->owner->removeObject(this, this->sleep_flag, this->dopple_flag,
                                  this->player_object_node);
        this->player_object_node = player->addObject(
            this, this->sleep_flag, this->dopple_flag);

        if (this->object_state == 2) {
            this->unexplore_terrain(this->owner, 0, -1);
        }

        this->owner = player;

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

        this->notify(this->id, this->id, 0x20B, player->id, 0, 0);
    }
}

float TRIBE_Combat_Object::calc_attack_modifier(RGE_Static_Object* target)
{
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
                                          RGE_Combat_Object* other)
{
    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (master->missile_id >= 0 && target != 0 && target->owner->id > 0) {
        target->owner->make_new_object(0x70, this->world_x, this->world_y,
                                       this->world_z, 0);
    }
    return RGE_Combat_Object::attack(target, other);
}

unsigned char TRIBE_Combat_Object::do_attack(RGE_Static_Object* target,
                                             RGE_Combat_Object* attacker,
                                             float x, float y, float z)
{
    if (target == 0) {
        return 0;
    }

    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    if (rge_base_game->quick_build != 0 &&
        (master->id == 0x7A || master->id == 0x7B)) {
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        target->die_die_die();
        return 1;
    }

    if (master->area_effect_range > 0.0f && master->weapon_range < 0.99f) {
        this->area_attack(x, y, z, attacker, target);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        const int chance =
            debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x211) *
            100 / 0x7FFF;
        if (chance <= master->base_hit_chance) {
            target->damage(master->weapon_num, master->weapon,
                           this->calc_attack_modifier(target), this->owner,
                           attacker);
        }
        return 1;
    }

    return RGE_Combat_Object::do_attack(target, attacker, x, y, z);
}

void TRIBE_Combat_Object::get_armor(short& armor, short& original)
{
    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    armor = master->base_armor;
    for (int i = 0; i < master->armor_num; ++i) {
        if (master->armor[i].type == 4 && master->armor[i].value > armor) {
            armor = master->armor[i].value;
        }
    }
    original = master->orig_armor;
}

void TRIBE_Combat_Object::get_pierce_armor(short& armor, short& original)
{
    armor = 0;
    for (int i = 0;
         i < static_cast<RGE_Master_Combat_Object*>(this->master_obj)->armor_num;
         ++i) {
        RGE_Master_Combat_Object* master =
            static_cast<RGE_Master_Combat_Object*>(this->master_obj);
        if (master->armor[i].type == 3 && master->armor[i].value > armor) {
            armor = master->armor[i].value;
        }
    }
    original = static_cast<TRIBE_Master_Combat_Object*>(this->master_obj)
                   ->orig_pierce_armor;
}

void TRIBE_Combat_Object::reposition_artifact()
{
    RGE_Static_Object* parent = this->inside_obj;
    float x = parent != 0 ? parent->world_x : this->world_x;
    float y = parent != 0 ? parent->world_y : this->world_y;
    int min_x = static_cast<int>(x);
    int min_y = static_cast<int>(y);
    int max_x = min_x;
    int max_y = min_y;

    RGE_Map* map = this->owner->world->map;
    const int map_max_x = map->map_width - 1;
    const int map_max_y = map->map_height - 1;

    for (;;) {
        for (int row = min_x; row <= max_x; ++row) {
            const int columns[2] = {min_y, max_y};
            for (int side = 0; side < 2; ++side) {
                if (map->get_terrain(static_cast<short>(row),
                                     static_cast<short>(columns[side])) != 1 &&
                    map->get_terrain(static_cast<short>(row),
                                     static_cast<short>(columns[side])) != 2) {
                    x = static_cast<float>(row) - DAT_00574ca0;
                    y = static_cast<float>(columns[side]) - DAT_00574ca0;
                    if (this->master_obj->check_placement(this->owner, x, y, 0,
                                                          1, 1, 1, 0, 1, 1) == 0) {
                        goto found_position;
                    }
                }
            }
        }

        for (int col = min_y + 1; col <= max_y - 1; ++col) {
            const int rows[2] = {min_x, max_x};
            for (int side = 0; side < 2; ++side) {
                if (map->get_terrain(static_cast<short>(rows[side]),
                                     static_cast<short>(col)) != 1 &&
                    map->get_terrain(static_cast<short>(rows[side]),
                                     static_cast<short>(col)) != 2) {
                    x = static_cast<float>(rows[side]) - DAT_00574ca0;
                    y = static_cast<float>(col) - DAT_00574ca0;
                    if (this->master_obj->check_placement(this->owner, x, y, 0,
                                                          side == 0, 1, 1, 0, 1,
                                                          1) == 0) {
                        goto found_position;
                    }
                }
            }
        }

        if (min_x == 0 && max_x == map_max_x && min_y == 0 &&
            max_y == map_max_y) {
            parent = this->inside_obj;
            x = parent != 0 ? parent->world_x : this->world_x;
            y = parent != 0 ? parent->world_y : this->world_y;
            break;
        }

        if (min_x > 0) --min_x;
        if (min_y > 0) --min_y;
        if (max_x < map_max_x) ++max_x;
        if (max_y < map_max_y) ++max_y;
    }

found_position:
    this->set_location(x, y, this->world_z);
    if (this->inside_obj != 0) {
        this->exit_obj();
    }
    this->teleport(x, y, this->world_z);
    this->change_ownership(this->owner->world->players[0]);
    this->move_to(0, x, y, this->world_z);
    this->hp = 1.0f;
}

int TRIBE_Combat_Object::can_debark()
{
    return this->master_obj->unit_level == 7 && this->objects != 0 &&
           this->objects->number_of_objects != 0;
}

int TRIBE_Combat_Object::hunt(int object_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(object_id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

int TRIBE_Combat_Object::convert(int object_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(object_id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

int TRIBE_Combat_Object::heal(int id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

int TRIBE_Combat_Object::repair(int id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

int TRIBE_Combat_Object::build(int id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

int TRIBE_Combat_Object::trade(int id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(id);
    if (target == 0) return 0;

    if (force == 0 && this->actions->have_action() == 1 &&
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

unsigned char TRIBE_Combat_Object::keepGatheringWhenObjectIsOut(int value) const
{
    if (value != 0x32 && value != 0x2D) {
        return 0;
    }
    return 1;
}

unsigned char TRIBE_Combat_Object::produceWhenKilledBy(int cause) const
{
    const int group = this->master_obj->object_group;
    if (group != 9 && group != 10) return 1;
    if (cause != 4) return 0;
    return 1;
}

unsigned char TRIBE_Combat_Object::useSameZoneDropsite() const
{
    const int group = this->master_obj->object_group;
    if (group == 0x15 || group == 2) return 0;
    return 1;
}

void TRIBE_Combat_Object::initUnitAI()
{
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

int __cdecl lines_intersect(float, float, float, float, float, float, float,
                            float)
{
    return 1;
}

int TRIBE_Combat_Object::higher_check_for_cliff(
    RGE_Static_Object* target, int col, int row, float x1, float y1, float x2,
    float y2, RGE_Map* map, RGE_Static_Object* old_object, float& angle,
    int& direction)
{
    if (row < 0 || row >= map->map_height || col < 0 || col >= map->map_width) {
        return 0;
    }

    RGE_Object_Node* node = map->map_row_offset[row][col].objects.list;
    while (node != 0) {
        RGE_Static_Object* cliff = node->node;
        if (cliff->master_obj->object_group == 0x22 && cliff != old_object) {
            old_object = cliff;
            if (angle == -1.0f) {
                const double result = atan2(target->world_y - this->world_y,
                                            target->world_x - this->world_x);
                angle = static_cast<float>(result);
                if (result < DAT_00574c98) angle = result - DAT_00574ca4;
            }

            if (lines_intersect(x1, y1, x2, y2,
                                TRIBE_Cliff_Higher_Check_Table[cliff->facet].line_x1 + x1,
                                TRIBE_Cliff_Higher_Check_Table[cliff->facet].line_y1 + y1,
                                TRIBE_Cliff_Higher_Check_Table[cliff->facet].line_x2 + x2,
                                TRIBE_Cliff_Higher_Check_Table[cliff->facet].line_y2 + y2)) {
                if ((cliff->facet >= 0x19 ||
                     angle < TRIBE_Cliff_Higher_Check_Table[cliff->facet].from_angle1 ||
                     TRIBE_Cliff_Higher_Check_Table[cliff->facet].to_angle1 > angle) &&
                    (angle < TRIBE_Cliff_Higher_Check_Table[cliff->facet].from_angle2 ||
                     TRIBE_Cliff_Higher_Check_Table[cliff->facet].to_angle2 > angle)) {
                    --direction;
                } else {
                    ++direction;
                }
                return 1;
            }
        }
        node = node->next;
    }
    return 0;
}

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* target)
{
    if (this->world_z > target->world_z) return 1;

    const float target_x = target->world_x;
    const float target_y = target->world_y;
    const float x_distance = target_x - this->world_x;
    const float y_distance = target_y - this->world_y;
    if (x_distance == 0.0f && y_distance == 0.0f) return 0;

    const int steps = fabs(y_distance) > fabs(x_distance)
        ? abs(static_cast<int>(y_distance)) * 2
        : abs(static_cast<int>(x_distance)) * 2;
    const float x_step = x_distance / steps;
    const float y_step = y_distance / steps;
    const float abs_x = x_step < 0.0f ? -x_step : x_step;
    const float abs_y = y_step < 0.0f ? -y_step : y_step;

    int second_x_offset;
    int second_y_offset;
    int third_x_offset;
    int third_y_offset;
    if (abs_x > abs_y) {
        second_x_offset = 0;
        second_y_offset = -1;
        third_x_offset = 0;
        third_y_offset = 1;
    } else {
        second_x_offset = -1;
        second_y_offset = 0;
        third_x_offset = 1;
        third_y_offset = 0;
    }

    float x = this->world_x;
    float y = this->world_y;
    int old_x = -999;
    int old_y = -999;
    float angle = -1.0f;
    int direction = 0;
    RGE_Map* map = this->owner->world->map;

    for (int i = steps; i > 0; --i) {
        x += x_step;
        y += y_step;
        const int tile_x = static_cast<int>(x);
        const int tile_y = static_cast<int>(y);
        if (tile_x == old_x && tile_y == old_y) continue;
        old_x = tile_x;
        old_y = tile_y;

        if (this->higher_check_for_cliff(target, tile_x, tile_y,
                                         this->world_x, this->world_y,
                                         target_x, target_y, map, 0, angle,
                                         direction) == 0 &&
            this->higher_check_for_cliff(target, tile_x + second_x_offset,
                                         tile_y + second_y_offset, this->world_x,
                                         this->world_y, target_x, target_y,
                                         map, 0, angle, direction) == 0) {
            this->higher_check_for_cliff(target, tile_x + third_x_offset,
                                         tile_y + third_y_offset, this->world_x,
                                         this->world_y, target_x, target_y,
                                         map, 0, angle, direction);
        }
    }

    if (direction < 1) direction = 0;
    if (direction > 0) direction = 1;
    return direction;
}

unsigned char TRIBE_Combat_Object::area_attack(
    float x, float y, float, RGE_Combat_Object* attacker,
    RGE_Static_Object* ignored)
{
    RGE_Player* owner = this->owner;
    RGE_Map* map = owner->world->map;
    RGE_Master_Combat_Object* master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    const float radius = master->area_effect_range;
    const float radius_squared = radius * radius;
    const short max_x = static_cast<short>(map->map_width - 1);
    const short max_y = static_cast<short>(map->map_height - 1);
    if (!(radius > DAT_00574ca8)) return 0;

    short first_x = static_cast<short>(x - radius) - 2;
    short last_x = static_cast<short>(x + radius) + 2;
    short first_y = static_cast<short>(y - radius) - 2;
    short last_y = static_cast<short>(y + radius) + 2;
    if (first_x < 0) first_x = 0;
    if (last_x > max_x + 1) last_x = max_x + 1;
    if (first_y < 0) first_y = 0;
    if (last_y > max_y + 1) last_y = max_y + 1;

    for (short row = first_y; row < last_y; ++row) {
        for (short col = first_x; col < last_x; ++col) {
            for (RGE_Object_Node* link = map->map_row_offset[row][col].objects.list;
                 link != 0; link = link->next) {
                RGE_Combat_Object* object =
                    static_cast<RGE_Combat_Object*>(link->node);
                if (object == ignored) continue;

                const short master_id = master->id;
                RGE_Master_Static_Object* object_master = object->master_obj;
                if (((master_id == 0x2E || master_id == 0x28 ||
                      master_id == 0x153 || master_id == 0x159) &&
                     object->owner == owner) || object == this ||
                    object_master->area_effect_object_level <
                    master->area_effect_level) continue;

                float dx = object->world_x - x;
                float dy = object->world_y - y;
                if (dx < 0.0f) dx = -dx;
                if (dy < 0.0f) dy = -dy;
                if (dx > object_master->radius_x) dx -= object_master->radius_x;
                else dx = 0.0f;
                if (dy > object_master->radius_y) dy -= object_master->radius_y;
                else dy = 0.0f;

                if (radius_squared > dx * dx + dy * dy &&
                    static_cast<short>(
                        debug_rand("C:\\msdev\\work\\age1_x1\\t_c_obj.cpp",
                                   0x653) * 100 / 0x7FFF) <=
                        master->base_hit_chance) {
                    object->damage(master->weapon_num, master->weapon,
                                   this->calc_attack_modifier(object), owner,
                                   attacker);
                    if (object->hp < DAT_00574c78) {
                        object->set_attribute_amount(0.0f, 0, 1);
                    }
                }
            }
        }
    }
    return 1;
}

unsigned char TRIBE_Combat_Object::heal(float amount)
{
    RGE_Master_Static_Object* master = this->master_obj;
    const short type = master->object_group;
    if (type != 2 && type != 0x14 && type != 0x15 && type != 0x16) {
        return RGE_Static_Object::heal(amount);
    }

    const long max_hp = master->hp;
    const long heal_rate =
        static_cast<TRIBE_Master_Combat_Object*>(master)->build_pts_required;
    const float maximum = static_cast<float>(max_hp);
    if ((amount = amount * maximum / heal_rate) + this->hp > maximum) {
        amount = maximum - this->hp;
    }

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->owner);
    if (player->pay_obj_cost(master->id,
                             amount / static_cast<float>(max_hp * 2), 1)) {
        return RGE_Static_Object::heal(amount);
    }
    return 2;
}

int TRIBE_Combat_Object::canRepair()
{
    const float maximum = static_cast<float>(this->master_obj->hp);
    return static_cast<TRIBE_Player*>(this->owner)->check_obj_cost(
        this->master_obj->id, 0, (maximum - this->hp) / maximum, 0) != 0;
}

void TRIBE_Combat_Object::do_repair(RGE_Static_Object* target)
{
    if (static_cast<RGE_Action_Object*>(target) == this) return;

    if (this->master_obj->id != 0x9C) {
        RGE_Master_Static_Object* repair_master =
            this->owner->master_objects[0x9C];
        if (repair_master != 0) this->transform(repair_master);
    }

    RGE_Task_List* tasks =
        static_cast<RGE_Master_Action_Object*>(this->master_obj)->tasks;
    RGE_Task* repair_task;
    if (tasks->list_num > 0) {
        repair_task = 0;
        for (int i = 0; i < tasks->list_num; ++i) {
            RGE_Task* task = tasks->list[i];
            if (task->action_type == 0x6A &&
                (task->object_group == target->master_obj->object_group ||
                 (target->master_obj->master_type == 'P' &&
                  (task->object_group == -1 || task->object_group == 0)))) {
                repair_task = task;
                break;
            }
        }
    }

    short action_type = 0;
    RGE_Task* current_task = this->actions->get_task();
    if (current_task != 0 && repair_task == current_task &&
        this->actions->action_work(target, target->world_x, target->world_y,
                                   target->world_z) != 0) {
        action_type = this->actions->get_action()->type();
    } else {
        RGE_Action* action = repair_task == 0 ? 0 :
            this->actions->create_task_action(repair_task, target,
                                              target->world_x, target->world_y,
                                              target->world_z);
        if (action != 0) {
            action_type = action->type();
            this->set_only_action(action);
        }
    }

    if (this->unitAIValue != 0) {
        int order = -1;
        int current_action = -1;
        if (action_type == 0x6A) {
            current_action = 0x26A;
            order = 0x2CE;
        }
        this->unitAIValue->setCurrentOrder(order);
        this->unitAIValue->setCurrentAction(current_action);
        this->unitAIValue->setCurrentTarget(
            target->id, target->master_obj->object_group, target->world_x,
            target->world_y, target->world_z);
        this->unitAIValue->setTaskedByPlayer();
    }
}
