
#include "../include/com_obj.h"
#include "../include/act_atak.h"
#include "../include/act_entr.h"
#include "../include/act_expl.h"
#include "../include/act_gath.h"
#include "../include/act_list.h"
#include "../include/act_move.h"
#include "../include/act_tran.h"
#include "../include/vis_unit.h"
#include "../include/game_globals.h"
#include "../include/map.h"
#include "../include/m_co_obj.h"
#include "../include/misl_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/task_lst.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

extern "C" {
    float g_attack_modifier;
    int __cdecl debug_rand(const char*, int);
}


RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z, int do_setup)
    : RGE_Action_Object(master_obj, player, x, y, z, 0) {
    if (do_setup != 0) {
        setup(master_obj, player, x, y, z);
    }
}

RGE_Combat_Object::RGE_Combat_Object(int handle, RGE_Game_World* world, int do_setup)
    : RGE_Action_Object(handle, world, 0) {
    if (do_setup != 0) {
        setup(handle, world);
    }
}

RGE_Combat_Object::~RGE_Combat_Object() {
    if (id >= 0) {
        VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
    }
}

void RGE_Combat_Object::recycle_in_to_game(RGE_Master_Static_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    int i;
    float attack_timer_local;
    RGE_Master_Combat_Object* combat_master;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::recycle_in_to_game(master_obj, player, x, y, z);
    combat_master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    attack_timer_local = combat_master->speed_of_attack;
    attack_timer = attack_timer_local;
}

int RGE_Combat_Object::setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z) {
    int i;
    float attack_timer_local;
    RGE_Master_Combat_Object* combat_master;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(master_obj, player, x, y, z);
    type = 0x32;
    combat_master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    attack_timer_local = combat_master->speed_of_attack;
    attack_timer = attack_timer_local;
    capture_flag = 0;
    return 1;
}

int RGE_Combat_Object::setup(int handle, RGE_Game_World* world) {
    int i;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(handle, world);
    type = 0x32;
    rge_read(handle, &attack_timer, 4);
    if (!(save_game_version < 2.01f)) {
        rge_read(handle, &capture_flag, 1);
    }
    return 1;
}

void RGE_Combat_Object::save(int handle) {
    RGE_Action_Object::save(handle);
    rge_write(handle, &attack_timer, 4);
    rge_write(handle, &capture_flag, 1);
}

void RGE_Combat_Object::stop() {
    RGE_Action_Object::stop();
    if (unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xAB);
        }
        unitAIValue->stopObject(1);
    }
}

float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* unused) {
    return g_attack_modifier;
}

unsigned char RGE_Combat_Object::area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignored)
{
    float attack_modifier;
    RGE_Map* map = this->owner->world->map;
    float radius =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range;
    short maxx = (short)(map->map_width - 1);
    short maxy = (short)(map->map_height - 1);
    float r2 = radius * radius;
    if (!(radius > DAT_0056f4a0)) return 0;

    short x0;
    x0 = (short)((long)(x - radius));
    x0 = x0 - 2;
    short x1;
    x1 = (short)((long)(x + radius));
    x1 = x1 + 2;
    short y0;
    y0 = (short)((long)(y - radius));
    y0 = y0 - 2;
    short y1;
    y1 = (short)((long)(y + radius));
    y1 = y1 + 2;
    if (x0 < 0) x0 = 0;
    if (x1 > maxx + 1) x1 = maxx + 1;
    if (y0 < 0) y0 = 0;
    if (y1 > maxy + 1) y1 = maxy + 1;

    for (short yy = y0; yy < y1; yy++) {
        for (short xx = x0; xx < x1; xx++) {
            RGE_Object_Node* link = map->map_row_offset[yy][xx].objects.list;
            while (link != 0) {
                RGE_Combat_Object* obj =
                    static_cast<RGE_Combat_Object*>(link->node);
                if (obj != this &&
                    obj->master_obj->area_effect_object_level >=
                        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_level &&
                    obj != static_cast<RGE_Combat_Object*>(ignored)) {
                    float dx = obj->world_x - x;
                    float dy = obj->world_y - y;
                    if (dx < DAT_0056f4a8) dx = -dx;
                    if (dy < DAT_0056f4a8) dy = -dy;
                    float radius_x = obj->master_obj->radius_x;
                    float radius_y = obj->master_obj->radius_y;
                    if (dx > radius_x) dx -= radius_x;
                    else dx = DAT_0056f4a8;
                    if (dy > radius_y) dy -= radius_y;
                    else dy = DAT_0056f4a8;
                    if (r2 > dx * dx + dy * dy) {
                        int rnd = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xFA) * 100;
                        int chance = rnd / 0x7fff;
                        if ((short)chance <=
                            static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
                            attack_modifier = this->calc_attack_modifier(obj);
                            obj->damage(
                                (int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
                                static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon,
                                        attack_modifier, this->owner, attacker);
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}

unsigned char RGE_Combat_Object::attack(RGE_Static_Object* target, RGE_Combat_Object* other)
{
    float c;
    float s;
    float range;

    if (target == 0) {
        return 0;
    }

    short missile_id =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->missile_id;
    if (missile_id >= 0) {
        float radius_x = this->master_obj->radius_x;
        float radius_y = this->master_obj->radius_y;
        c = (float)cos(this->angle);
        s = (float)sin(this->angle);
        range = (float)sqrt(radius_x * radius_x + radius_y * radius_y) +
            static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range -
            DAT_0056f4ac;

        RGE_Missile_Object* missile = (RGE_Missile_Object*)this->owner->master_objects[missile_id]->make_new_obj(this->owner,
            this->world_x + c * static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_offset_y -
                s * static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_offset_x,
            this->world_y + s * static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_offset_y +
                c * static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_offset_x,
            this->world_z + static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_offset_z);
        missile->init_missile(this, target, range);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        if (static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range > DAT_0056f49c) {
            if (1 == target->owner->computerPlayer()) {
                int hp = (int)target->hp;
                target->notify(this->id, target->id, 0x20F,
                               (long)this->id, (long)hp,
                               (long)target->master_obj->hp);
                return 1;
            }
        }
    } else {
        this->do_attack(target, other, this->world_x, this->world_y, this->world_z);
    }
    return 1;
}

unsigned char RGE_Combat_Object::attack(float x, float y, float z, RGE_Combat_Object* target)
{
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    short missile_id = combat_master->missile_id;
    if (missile_id >= 0) {
        float radius_y = this->master_obj->radius_y;
        float radius_x = this->master_obj->radius_x;
        float range = (float)sqrt(radius_y * radius_y + radius_x * radius_x) +
            combat_master->weapon_range + 6.0f;
        float angle1 = this->angle;
        float angle2 = this->angle;
        float c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Master_Static_Object* entry = owner->master_objects[missile_id];
        float s = (float)sin(angle2);

        RGE_Missile_Object* missile = (RGE_Missile_Object*)entry->make_new_obj(owner,
            this->world_x + c * combat_master->weapon_offset_y -
                s * combat_master->weapon_offset_x,
            this->world_y + s * combat_master->weapon_offset_y +
                c * combat_master->weapon_offset_x,
            this->world_z + combat_master->weapon_offset_z);

        missile->init_missile(target, x, y, z,
            range);
        this->notify(this->id, this->id, 0x200, 0x258, -1, 0);
        return 1;
    }
    return 0;
}

unsigned char RGE_Combat_Object::do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float p3, float p4, float p5)
{
    if (target == 0) {
        return 0;
    }

    if (static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range > 0.0f) {
        this->area_attack(p3, p4, p5, attacker, 0);
        return 1;
    }

    this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0x17b);
    int chance = (r * 100) / 0x7fff;
    if (chance <=
        (int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
        float mod = this->calc_attack_modifier(target);
        target->damage(
                      (int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
                      static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon,
                      mod,
                      this->owner,
                      attacker);
    }
    return 1;
}

void RGE_Combat_Object::damage(int param_1, RGE_Armor_Weapon_Info* armor, float value, RGE_Player* player, RGE_Static_Object* target) {
    hp -= calculateDamage(param_1, armor, value, player, target);
    if (target != 0) {
        notify(target->id, id, 0x1F4, target->id, (int)hp, master_obj->hp);
    }
    if (hp < 1.0) {
        hp = 0.0f;
    }
}

float RGE_Combat_Object::calculateDamage(int param_1, RGE_Armor_Weapon_Info* param_2,
                                         float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    RGE_Master_Combat_Object* obj =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    float mult = DAT_0056f49c;
    short weaponKind = obj->defense_terrain_bonus;
    RGE_Armor_Weapon_Info* armorTbl = obj->armor;
    int nArmor = obj->armor_num;

    if (weaponKind >= 0 && this->tile != 0) {
        unsigned char cls = this->tile->terrain_type;
        RGE_Game_World* wld = this->owner->world;
        float** tbl = wld->terrains;
        mult = tbl[weaponKind][cls];
    }

    float total = DAT_0056f4a8;

    if (param_1 > 0) {
        RGE_Armor_Weapon_Info* weapon = param_2;
        int tot_armor = obj->base_armor;
        int cnt = param_1;

        do {
            int attack = tot_armor;

            if (nArmor > 0) {
                RGE_Armor_Weapon_Info* srch = armorTbl;
                int n = nArmor;
                do {
                    if (srch->type == weapon->type) {
                        attack = srch->value;
                    }
                    ++srch;
                    n--;
                } while (n != 0);
            }

            float d = (float)weapon->value - (float)attack;
            float dmg = d * mult * param_3;

            if (dmg > DAT_0056f4a0) {
                total += dmg;
            }

            weapon++;
            cnt--;
        } while (cnt != 0);
    }

    return total;
}

unsigned char RGE_Combat_Object::can_attack() {
    if (attack_timer > 0.0f) {
        return 0;
    }
    return 1;
}

void RGE_Combat_Object::reset_attack_timer() {
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    float timer = combat_master->speed_of_attack;
    this->attack_timer = timer;
}

void RGE_Combat_Object::get_armor(short& armor, short& original_armor) {
    int i;

    armor = static_cast<RGE_Master_Combat_Object*>(master_obj)->base_armor;
    for (i = 0; i < static_cast<RGE_Master_Combat_Object*>(master_obj)->armor_num; ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value > armor) {
            armor = static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value;
        }
    }
    original_armor = static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_armor;
}

void RGE_Combat_Object::get_weapon(short& weapon, short& original_weapon) {
    int i;

    weapon = 0;
    for (i = 0; i < static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon_num; ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon[i].value > weapon) {
            weapon = static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon[i].value;
        }
    }
    original_weapon = static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_weapon;
}

void RGE_Combat_Object::get_weapon_range(float& a, float& b) {
    a = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range;
    b = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->orig_weapon_range;
}

void RGE_Combat_Object::get_speed_of_attack(float& a, float& b) {
    a = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->speed_of_attack;
    b = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->orig_speed_of_attack;
}

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* target) {
    RGE_Animated_Object::release_being_worked_on(target);
    if (target->id >= 0) {
        notify(target->id, id, 0x2BB, target->master_obj->object_group, 0, 0);
    }
}

void RGE_Combat_Object::enter_obj(RGE_Static_Object* obj) {
    RGE_Static_Object::enter_obj(obj);
    if (inside_obj != 0) {
        if (id >= 0) {
            VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
            Unified_Map_Value = 0;
        }
    }
}

unsigned char RGE_Combat_Object::update(void)
{
    long local_4 = -1;

    if (this->attack_timer > 0.0f) {
        this->attack_timer = this->attack_timer -
            this->owner->world->world_time_delta_seconds;
        if (this->attack_timer < 0.0f) {
            this->attack_timer = 0.0f;
        }
    }

    unsigned char result = RGE_Action_Object::update();

    int object_id = this->id;
    if (object_id >= 0 && this->inside_obj == 0) {
        int x = (int)this->world_x;
        int y = (int)this->world_y;
        unsigned long new_value = unified_map_offsets[y][x];
        unsigned long old_value = this->Unified_Map_Value;
        this->Unified_Map_Value = new_value;
        if (new_value != old_value) {
            VisibleUnitManager->Update_Unit_Info(object_id,
                                                 (int)this->owner->id,
                                                 x,
                                                 y,
                                                 (int)this->master_obj->object_group,
                                                 old_value,
                                                 new_value,
                                                 this->VUR_Ptrs);
            if (this->capture_flag) {
                RGE_Game_World* world = this->owner->world;
                int player = 1;
                int player_num = world->player_num;
                if (player_num > 1) {
                    int owner_id = this->owner->id;
                    do {
                        if (player != owner_id) {
                            unsigned long mask = 1 << player;
                            if ((new_value & mask) > 0) {
                                local_4 = player;
                                break;
                            }
                        }
                        ++player;
                    } while (player < player_num);
                }
                if (local_4 >= 0) {
                    if (world->players[local_4]->computerPlayer() == 0) {
                        this->change_ownership(this->owner->world->players[local_4]);
                        if (this->capture_flag == 1) {
                            this->capture_flag = 0;
                        }
                    }
                }
            }
        }
    }

    if (this->unitAIValue != 0) {
        if (this->owner->world->is_player_turn((int)this->owner->id)) {
            this->unitAIValue->update(
                this->owner->world->get_accum_time_delta((int)this->owner->id));
        }
    }

    return result;
}

void RGE_Combat_Object::copy_obj(RGE_Master_Static_Object* master_obj) {
    RGE_Sprite* sound;
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    RGE_Master_Combat_Object* source_master =
        static_cast<RGE_Master_Combat_Object*>(master_obj);

    sound = 0;
    if (sprite == combat_master->fight_sprite) {
        sound = source_master->fight_sprite;
    }
    if (sound != 0) {
        new_sprite(sound);
    }
    RGE_Action_Object::copy_obj(master_obj);
}

void RGE_Combat_Object::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6) {
    if (object_state == 2) {
        if (unitAIValue != 0) {
            if (unitAIValue->notify(param_1, param_2, param_3, param_4, param_5, param_6) != 0) {
                return;
            }
        }
        if (param_3 != 0x2BB) {
            owner->notify(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
}

int RGE_Combat_Object::attack(int target_id, int force)
{
    RGE_Static_Object* target = this->owner->world->object(target_id);
    if (target == 0) {
        return 0;
    }

    if (force == 0) {
        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->get_target_obj() == target) {
                if (this->actions->get_action()->type() == 9) {
                    return 1;
                }
                if (this->actions->get_action()->type() == 7) {
                    return 1;
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        if (this->actions->get_action()->get_target_obj() == target) {
            if (this->actions->get_action()->type() == 9) {
                this->actions->get_action()->work(
                    target, target->world_x, target->world_y, target->world_z);
                return 1;
            }
        }
    }

    if (this->master_obj->object_group == 4) {
        RGE_Master_Static_Object* transform_master =
            this->owner->master_objects[0x53];
        if (transform_master != 0) {
            this->transform(transform_master);
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, target, 0, 0, 0,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->minimum_weapon_range,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->missile_id,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->fire_missile_at_frame);
    if (action == 0) {
        return 0;
    }
    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int RGE_Combat_Object::attack(float x, float y, float z, int force)
{
    if (force == 0) {
        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->targetX() == x) {
                if (this->actions->get_action()->targetX() == y) {
                    if (this->actions->get_action()->targetX() == z) {
                        if (this->actions->get_action()->type() == 9) {
                            return 1;
                        }
                        if (this->actions->get_action()->type() == 7) {
                            return 1;
                        }
                    }
                }
            }
        }
    }

    RGE_Action_Attack* action = new RGE_Action_Attack(this, x, y, z, 0, 0, 0,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->minimum_weapon_range,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->missile_id,
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->fire_missile_at_frame);
    if (action == 0) {
        return 0;
    }
    this->actions->delete_list();
    this->set_only_action(action);
    return 1;
}

int RGE_Combat_Object::moveTo(int x, int y) {
    return moveTo(x, 1.0f, y);
}

int RGE_Combat_Object::moveTo(int param_1, float param_2, int param_3)
{
    RGE_Game_World* world;
    RGE_Static_Object* obj;
    RGE_Action* action;
    RGE_Action_Move_To* moveAction;
    RGE_Sprite* sprite;
    RGE_Sprite* running_sprite;
    RGE_Master_Moving_Object* moving_master;

    world = this->owner->world;
    obj = world->object(param_1);

    if (obj == 0)
        return 0;

    if (param_3 == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->get_target_obj() == obj) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->type() == 1)
                    goto success;
            }
        }
    }

    moving_master = static_cast<RGE_Master_Moving_Object*>(this->master_obj);
    running_sprite = moving_master->run_sprite;
    if (running_sprite != 0)
        sprite = running_sprite;
    else
        sprite = moving_master->move_sprite;
    moveAction = new RGE_Action_Move_To(this, obj, param_2, sprite);
    if (moveAction == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(moveAction);

success:
    return 1;
}

int RGE_Combat_Object::moveTo(float x, float y, float z, float range, int force)
{
    RGE_Action* action;
    RGE_Action_Move_To* move_action;
    RGE_Sprite* sprite;
    int result;
    RGE_Master_Moving_Object* moving_master;

    if (force == 0) {
        if (this->actions->have_action() == 1) {
            action = (RGE_Action*)this->actions->get_action();
            if (action->targetX() == x) {
                action = (RGE_Action*)this->actions->get_action();
                if (action->targetY() == y) {
                    action = (RGE_Action*)this->actions->get_action();
                    if (action->targetZ() == z) {
                        action = (RGE_Action*)this->actions->get_action();
                        if (action->type() == 1) {
                            goto success;
                        }
                    }
                }
            }
        }
    }

    if (this->actions->have_action() == 1) {
        action = (RGE_Action*)this->actions->get_action();
        if (action->move_to(this, x, y, z) == 1) {
            goto success;
        }
    }

    moving_master = static_cast<RGE_Master_Moving_Object*>(this->master_obj);
    sprite = moving_master->move_sprite;
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }

    move_action = new RGE_Action_Move_To(this, x, y, z, range, sprite);
    result = 0;
    if (move_action != 0) {
        this->actions->delete_list();
        this->set_only_action(move_action);

success:
        result = 1;
    }
    return result;
}

int RGE_Combat_Object::moveAwayFrom(int p0, int p1) { return 0; }

int RGE_Combat_Object::gather(int object_id, int force) {
    RGE_Static_Object* target = this->owner->world->object(object_id);
    RGE_Task* task;
    RGE_Action_Gather* action;
    RGE_Static_Object* result = target;
    if (target == 0) {
        goto done;
    }

    if (force == 0 &&
        this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target &&
        this->actions->get_action()->type() == 5) {
        goto success;
    }

    if (this->actions->have_action() == 1 &&
        this->actions->get_action()->type() == 5) {
        this->actions->get_action()->set_target_obj(target);
        goto success;
    }

    task = this->getTask(target, target->world_x, target->world_y,
                         target->world_z);
    if (task == 0) {
        result = 0;
        goto done;
    }

    action = new RGE_Action_Gather(this, task, target);
    result = (RGE_Static_Object*)action;
    if (action == 0) {
        goto done;
    }

    this->actions->delete_list();
    this->set_only_action(action);
success:
    result = (RGE_Static_Object*)1;
done:
    return (int)result;
}

int RGE_Combat_Object::explore(int param_1, int param_2, int param_3)
{
    if (param_3 == 0) {
        if (actions->have_action() == 1) {
            RGE_Action* action = (RGE_Action*)actions->get_action();
            if (action->type() == 4)
                goto done;
        }
    }

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 4) {
            action = (RGE_Action*)actions->get_action();
            action->work(0, (float)param_1, (float)param_2, this->world_z);
            goto done;
        }
    }

    {
        RGE_Action_Explore* explore_action = new RGE_Action_Explore(
            this, 0, (float)param_1, (float)param_2,
            this->world_z);
        if (explore_action == 0)
            return 0;

        actions->delete_list();
        this->set_only_action(explore_action);
    }

done:
    return 1;
}

int RGE_Combat_Object::enter(int param_1, int param_2)
{
    RGE_Static_Object* obj;
    RGE_Task* task;
    RGE_Action_Enter* action_enter;

    obj = this->owner->world->object(param_1);
    if (obj == 0)
        return 0;

    if (param_2 == 0) {
        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->get_target_obj() == obj) {
                if (this->actions->get_action()->type() == 3)
                    goto success;
            }
        }
    }

    task = this->getTask(obj, obj->world_x, obj->world_y, obj->world_z);
    if (task == 0)
        return 0;

    action_enter = new RGE_Action_Enter(this,
                                        task,
                                        obj);
    if (action_enter == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action_enter);

success:
    return 1;
}

int RGE_Combat_Object::transport(float x, float y, float z, int w)
{
    int result;

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 0x0C) {
            // Call get_action() AGAIN (original does this)
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->work(0, x, y, z);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, x, y, z);
    result = 0;
    if (transport != 0) {
        actions->delete_list();
        this->set_only_action(transport);
        transport->work(this, x, y, z);
        result = 1;
    }
    return result;
}

int RGE_Combat_Object::unload(int param_1, float param_2, float param_3, float param_4)
{
    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 0x0C) {
            // Call get_action() again. The original does this.
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->work((RGE_Static_Object*)this, world_x, world_y, world_z);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, world_x, world_y, world_z);
    if (transport == 0) {
        return 0;
    }

    actions->delete_list();
    this->set_only_action(transport);
    transport->work((RGE_Static_Object*)this, param_2, param_3, param_4);
    return 1;
}

int RGE_Combat_Object::stopAction() {
    actions->delete_list();
    new_sprite(master_obj->sprite);
    return 1;
}

int RGE_Combat_Object::pause() {
    new_sprite(master_obj->sprite);
    return 1;
}

float RGE_Combat_Object::rateOfFire() {
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    return combat_master->speed_of_attack;
}

float RGE_Combat_Object::damageCapability() {
    float total;
    short* value;
    int count;
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(master_obj);

    total = 0.0f;
    count = combat_master->weapon_num;
    if (count > 0) {
        value = &combat_master->weapon[0].value;
        do {
            if ((float)(int)*value > 0.0f) {
                total = total + (float)(int)*value;
            }
            value = value + 2;
            count = count - 1;
        } while (count != 0);
    }
    return total;
}

float RGE_Combat_Object::damageCapability(RGE_Static_Object* target) {
    float base_damage;

    base_damage = target->calc_attack_modifier((RGE_Static_Object*)this);
    return calculateDamage(((RGE_Master_Combat_Object*)target->master_obj)->weapon_num,
                           ((RGE_Master_Combat_Object*)target->master_obj)->weapon,
                           base_damage, target->owner, target);
}

int RGE_Combat_Object::inAttackRange(RGE_Static_Object* obj) {
    float radius_distance;
    float max_distance;
    float range_x;
    float range_y;

    range_x = master_obj->radius_x;
    range_y = master_obj->radius_y;
    radius_distance = range_x * range_x + range_y * range_y;
    radius_distance = (float)sqrt((double)radius_distance);
    max_distance = weaponRange() + radius_distance - -0.300000012f;
    if (distance_to_object(obj) <= max_distance) {
        return 1;
    }
    return 0;
}

float RGE_Combat_Object::weaponRange() {
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    return combat_master->weapon_range;
}

float RGE_Combat_Object::minimumWeaponRange() {
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    return combat_master->minimum_weapon_range;
}

int RGE_Combat_Object::currentTargetID() const {
    if (actions->have_action() == 1) {
        if (actions->get_action()->get_target_obj() != 0) {
            return actions->get_action()->get_target_obj()->id;
        }
    }
    return -1;
}

float RGE_Combat_Object::currentTargetX() const {
    if (actions->have_action() == 1) {
        return actions->get_action()->targetX();
    }
    return -1.0f;
}

float RGE_Combat_Object::currentTargetY() const {
    if (actions->have_action() == 1) {
        return actions->get_action()->targetY();
    }
    return -1.0f;
}

float RGE_Combat_Object::currentTargetZ() const {
    if (actions->have_action() == 1) {
        return actions->get_action()->targetZ();
    }
    return -1.0f;
}

float RGE_Combat_Object::teleport(float x, float y, float z) {
    VISIBLE_UNIT_REC** vur;
    VISIBLE_UNIT_REC* rec;
    float result;
    int old_x;
    int old_y;
    int new_x;
    int new_y;
    int i;

    old_x = (int)world_x;
    old_y = (int)world_y;
    result = RGE_Moving_Object::teleport(x, y, z);
    if (id >= 0) {
        new_x = (int)world_x;
        new_y = (int)world_y;
        if (new_x != old_x || new_y != old_y) {
            vur = VUR_Ptrs;
            for (i = 0; i < 9; ++i) {
                rec = *vur;
                if (rec != 0) {
                    rec->pos_x = (unsigned char)new_x;
                    rec->pos_y = (unsigned char)new_y;
                }
                ++vur;
            }
        }
    }
    return result;
}
