
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
#include "../include/aiuaimod.h"
#include "../include/world.h"
#include <math.h>
#include <stddef.h>
#include <stdio.h>

int __cdecl debug_rand(char*, int);


RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup)
    : RGE_Action_Object(tobj, obj_owner, x, y, z, 0) {
    if (do_setup != 0) {
        setup(tobj, obj_owner, x, y, z);
    }
}

RGE_Combat_Object::RGE_Combat_Object(int infile, RGE_Game_World* gworld, int do_setup)
    : RGE_Action_Object(infile, gworld, 0) {
    if (do_setup != 0) {
        setup(infile, gworld);
    }
}

RGE_Combat_Object::~RGE_Combat_Object() {
    if (id >= 0) {
        VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
    }
}

void RGE_Combat_Object::recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    int i;
    float attack_timer_local;
    RGE_Master_Combat_Object* combat_master;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::recycle_in_to_game(tobj, obj_owner, x, y, z);
    combat_master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    attack_timer_local = combat_master->speed_of_attack;
    attack_timer = attack_timer_local;
}

int RGE_Combat_Object::setup(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z) {
    int i;
    float attack_timer_local;
    RGE_Master_Combat_Object* combat_master;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(tobj, obj_owner, x, y, z);
    type = 0x32;
    combat_master = static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    attack_timer_local = combat_master->speed_of_attack;
    attack_timer = attack_timer_local;
    capture_flag = 0;
    return 1;
}

int RGE_Combat_Object::setup(int infile, RGE_Game_World* gworld) {
    int i;

    for (i = 0; i < 9; ++i) {
        VUR_Ptrs[i] = 0;
    }
    Unified_Map_Value = 0;
    RGE_Action_Object::setup(infile, gworld);
    type = 0x32;
    rge_read(infile, &attack_timer, 4);
    if (!(save_game_version < 2.01f)) {
        rge_read(infile, &capture_flag, 1);
    }
    return 1;
}

void RGE_Combat_Object::save(int outfile) {
    RGE_Action_Object::save(outfile);
    rge_write(outfile, &attack_timer, 4);
    rge_write(outfile, &capture_flag, 1);
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

float RGE_Combat_Object::calc_attack_modifier(RGE_Static_Object* target) {
    return 1.0f;
}

unsigned char RGE_Combat_Object::area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignore_object) {
    float attack_modifier;
    RGE_Map* map = this->owner->world->map;
    float radius =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range;
    short maxx = (short)(map->map_width - 1);
    short maxy = (short)(map->map_height - 1);
    float r2 = radius * radius;
    //! This early-out also tests blast radius where blast level is the criterion.
    if (!(radius > g_combat_area_zero_range)) return 0;

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
                if (obj != this && obj->master_obj->area_effect_object_level >=
                    static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_level &&
                    obj != static_cast<RGE_Combat_Object*>(ignore_object)) {
                    float dx = obj->world_x - x;
                    float dy = obj->world_y - y;
                    if (dx < g_combat_area_zero_float) dx = -dx;
                    if (dy < g_combat_area_zero_float) dy = -dy;
                    float radius_x = obj->master_obj->radius_x;
                    float radius_y = obj->master_obj->radius_y;
                    if (dx > radius_x) dx -= radius_x;
                    else dx = g_combat_area_zero_float;
                    if (dy > radius_y) dy -= radius_y;
                    else dy = g_combat_area_zero_float;
                    if (r2 > dx * dx + dy * dy) {
                        int rnd = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 250) * 100;
                        int chance = rnd / 0x7fff;
                        if ((short)chance <= static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
                            attack_modifier = this->calc_attack_modifier(obj);
                            obj->damage((int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
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

unsigned char RGE_Combat_Object::attack(RGE_Static_Object* target,
                                        RGE_Combat_Object* attacker) {
    float c;
    float s;
    float rangeDistance;

    if (target == 0) {
        return 0;
    }

    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    short missile_id = combat_master->missile_id;
    if (missile_id >= 0) {
        float radius_y = combat_master->radius_y;
        float radius_x = combat_master->radius_x;
        rangeDistance =
            (float)sqrt(radius_x * radius_x + radius_y * radius_y) +
            combat_master->weapon_range - g_combat_missile_range_adjustment;
        float angle1 = this->angle;
        float angle2 = this->angle;
        c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Master_Static_Object* entry = owner->master_objects[missile_id];
        s = (float)sin(angle2);

        RGE_Missile_Object* missile =
            (RGE_Missile_Object*)entry->make_new_obj(owner, this->world_x + c * combat_master->weapon_offset_y -
                                                     s * combat_master->weapon_offset_x, this->world_y + s * combat_master->weapon_offset_y +
                                                     c * combat_master->weapon_offset_x, this->world_z + combat_master->weapon_offset_z);
        missile->init_missile(attacker, target, rangeDistance);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);

        if (static_cast<RGE_Master_Combat_Object*>(this->master_obj) ->weapon_range > g_combat_attack_modifier_one &&
            target->owner->computerPlayer() == 1) {
            target->notify(this->id, target->id, 0x20F, this->id, (long)target->hp, target->master_obj->hp);
        }
    } else {
        this->do_attack(target, attacker, this->world_x, this->world_y, this->world_z);
    }

    return 1;
}

unsigned char RGE_Combat_Object::attack(float target_x, float target_y, float target_z,
                                        RGE_Combat_Object* attacker) {
    float c;
    float s;
    float rangeDistance;

    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    short missile_id = combat_master->missile_id;
    if (missile_id >= 0) {
        float radius_y = combat_master->radius_y;
        float radius_x = combat_master->radius_x;
        rangeDistance =
            (float)sqrt(radius_x * radius_x + radius_y * radius_y) +
            combat_master->weapon_range - g_combat_missile_range_adjustment;
        float angle1 = this->angle;
        float angle2 = this->angle;
        c = (float)cos(angle1);
        RGE_Player* owner = this->owner;
        RGE_Master_Static_Object* entry = owner->master_objects[missile_id];
        s = (float)sin(angle2);

        RGE_Missile_Object* missile =
            (RGE_Missile_Object*)entry->make_new_obj(owner, this->world_x + c * combat_master->weapon_offset_y -
                                                     s * combat_master->weapon_offset_x, this->world_y + (s * combat_master->weapon_offset_y +
                c * combat_master->weapon_offset_x), this->world_z + combat_master->weapon_offset_z);
        missile->init_missile(attacker, target_x, target_y, target_z, rangeDistance);
        this->notify(this->id, this->id, 0x200, 0x258, -1, 0);
        return 1;
    }
    return 0;
}

unsigned char RGE_Combat_Object::do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float x, float y, float z) {
    if (target == 0) {
        return 0;
    }

    //! This radius gate repeats the mistake in t_c_obj.cpp do_attack; blast level is correct.
    if (static_cast<RGE_Master_Combat_Object*>(this->master_obj)->area_effect_range > 0.0f) {
        this->area_attack(x, y, z, attacker, 0);
        return 1;
    }

    this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
    int r = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 379);
    int chance = (r * 100) / 0x7fff;
    if (chance <= (int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->base_hit_chance) {
        float attack_modifier = this->calc_attack_modifier(target);
        target->damage((int)static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_num,
                       static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon, attack_modifier, this->owner,
                       attacker);
    }
    return 1;
}

void RGE_Combat_Object::damage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier, RGE_Player* attacking_player, RGE_Static_Object* attackingObject) {
    hp -= calculateDamage(weapon_num, damage, attack_modifier, attacking_player, attackingObject);
    if (attackingObject != 0) {
        notify(attackingObject->id, id, 0x1F4, attackingObject->id, (int)hp, master_obj->hp);
    }
    if (hp < 1.0) {
        hp = 0.0f;
    }
}

float RGE_Combat_Object::calculateDamage(int weapon_num, RGE_Armor_Weapon_Info* damage,
                                         float attack_modifier, RGE_Player* attacking_player, RGE_Static_Object* attackingObject) {
    RGE_Master_Combat_Object* obj =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    float mult = g_combat_attack_modifier_one;
    short weaponKind = obj->defense_terrain_bonus;
    RGE_Armor_Weapon_Info* armorTbl = obj->armor;
    int nArmor = obj->armor_num;

    if (weaponKind >= 0 && this->tile != 0) {
        unsigned char cls = this->tile->terrain_type;
        RGE_Game_World* wld = this->owner->world;
        float** tbl = wld->terrains;
        mult = tbl[weaponKind][cls];
    }

    float total = g_combat_area_zero_float;

    if (weapon_num > 0) {
        RGE_Armor_Weapon_Info* weapon = damage;
        int tot_armor = obj->base_armor;
        int cnt = weapon_num;

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
            float dmg = d * mult * attack_modifier;

            if (dmg > g_combat_area_zero_range) {
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

void RGE_Combat_Object::get_armor(short& cur_armor_in, short& orig_armor_in) {
    int i;

    cur_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->base_armor;
    for (i = 0; i < static_cast<RGE_Master_Combat_Object*>(master_obj)->armor_num; ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value > cur_armor_in) {
            cur_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->armor[i].value;
        }
    }
    orig_armor_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_armor;
}

void RGE_Combat_Object::get_weapon(short& cur_weapon_in, short& orig_weapon_in) {
    int i;

    cur_weapon_in = 0;
    for (i = 0; i < static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon_num; ++i) {
        if (static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon[i].value > cur_weapon_in) {
            cur_weapon_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->weapon[i].value;
        }
    }
    orig_weapon_in = static_cast<RGE_Master_Combat_Object*>(master_obj)->orig_weapon;
}

void RGE_Combat_Object::get_weapon_range(float& cur_weapon_range_in, float& orig_weapon_range_in) {
    cur_weapon_range_in = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->weapon_range;
    orig_weapon_range_in = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->orig_weapon_range;
}

void RGE_Combat_Object::get_speed_of_attack(float& cur_speed_of_attack_in, float& orig_speed_of_attack_in) {
    cur_speed_of_attack_in = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->speed_of_attack;
    orig_speed_of_attack_in = static_cast<RGE_Master_Combat_Object*>(this->master_obj)->orig_speed_of_attack;
}

void RGE_Combat_Object::release_being_worked_on(RGE_Static_Object* caller) {
    RGE_Animated_Object::release_being_worked_on(caller);
    if (caller->id >= 0) {
        notify(caller->id, id, 0x2BB, caller->master_obj->object_group, 0, 0);
    }
}

void RGE_Combat_Object::enter_obj(RGE_Static_Object* target) {
    RGE_Static_Object::enter_obj(target);
    if (inside_obj != 0) {
        if (id >= 0) {
            VisibleUnitManager->Update_Unit_Info(id, owner->id, (int)world_x, (int)world_y, master_obj->object_group, Unified_Map_Value, 0, VUR_Ptrs);
            Unified_Map_Value = 0;
        }
    }
}

unsigned char RGE_Combat_Object::update(void) {
    long sighted_by_player = -1;

    if (this->attack_timer > 0.0f) {
        this->attack_timer = this->attack_timer -
            this->owner->world->world_time_delta_seconds;
        if (this->attack_timer < 0.0f) {
            this->attack_timer = 0.0f;
        }
    }

    unsigned char returnResult = RGE_Action_Object::update();

    int object_id = this->id;
    if (object_id >= 0 && this->inside_obj == 0) {
        int x = (int)this->world_x;
        int y = (int)this->world_y;
        unsigned long new_value = unified_map_offsets[y][x];
        unsigned long old_value = this->Unified_Map_Value;
        this->Unified_Map_Value = new_value;
        //! @bug This gate runs only on sight-bit change, and records store position only on add.
        //! A unit that moves under continuous vision keeps its first-seen position in every record.
        //! GetVisibleUnits() then filters by that stale position and drops the unit from AI scans.
        if (new_value != old_value) {
            VisibleUnitManager->Update_Unit_Info(object_id, (int)this->owner->id, x, y, (int)this->master_obj->object_group,
                                                 old_value, new_value, this->VUR_Ptrs);
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
                                sighted_by_player = player;
                                break;
                            }
                        }
                        ++player;
                    } while (player < player_num);
                }
                if (sighted_by_player >= 0) {
                    //! @bug First-sight capture runs only for human players (computerPlayer() == 0).
                    //! The change needs no unit nearby and no timer, unlike TRIBE_Action_Artifact.
                    //! An AI seer gets no capture here, so the human always wins the first sight.
                    if (world->players[sighted_by_player]->computerPlayer() == 0) {
                        this->change_ownership(this->owner->world->players[sighted_by_player]);
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
            this->unitAIValue->update(this->owner->world->get_accum_time_delta((int)this->owner->id));
        }
    }

    return returnResult;
}

void RGE_Combat_Object::copy_obj(RGE_Master_Static_Object* source2) {
    RGE_Sprite* sound;
    RGE_Master_Combat_Object* combat_master =
        static_cast<RGE_Master_Combat_Object*>(this->master_obj);
    RGE_Master_Combat_Object* source_master =
        static_cast<RGE_Master_Combat_Object*>(source2);

    sound = 0;
    if (sprite == combat_master->fight_sprite) {
        sound = source_master->fight_sprite;
    }
    if (sound != 0) {
        new_sprite(sound);
    }
    RGE_Action_Object::copy_obj(source2);
}

void RGE_Combat_Object::notify(int caller, int recipient, int mType, long p1, long p2, long p3) {
    if (object_state == 2) {
        if (unitAIValue != 0) {
            if (unitAIValue->notify(caller, recipient, mType, p1, p2, p3) != 0) {
                return;
            }
        }
        if (mType != 0x2BB) {
            owner->notify(caller, recipient, mType, p1, p2, p3);
        }
    }
}

int RGE_Combat_Object::attack(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    if (target == 0) {
        return 0;
    }

    if (unconditional == 0) {
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
                this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
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

int RGE_Combat_Object::attack(float x, float y, float z, int unconditional) {
    if (unconditional == 0) {
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

int RGE_Combat_Object::moveTo(int targetID, int unconditional) {
    return moveTo(targetID, 1.0f, unconditional);
}

int RGE_Combat_Object::moveTo(int targetID, float minRange, int unconditional) {
    RGE_Game_World* world;
    RGE_Static_Object* obj;
    RGE_Action* action;
    RGE_Action_Move_To* moveAction;
    RGE_Sprite* sprite;
    RGE_Sprite* running_sprite;
    RGE_Master_Moving_Object* moving_master;

    world = this->owner->world;
    obj = world->object(targetID);

    if (obj == 0)
        return 0;

    if (unconditional == 0) {
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
    moveAction = new RGE_Action_Move_To(this, obj, minRange, sprite);
    if (moveAction == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(moveAction);

success:
    return 1;
}

int RGE_Combat_Object::moveTo(float x, float y, float z, float minRange, int unconditional) {
    RGE_Action* action;
    RGE_Action_Move_To* move_action;
    RGE_Sprite* sprite;
    RGE_Master_Moving_Object* moving_master;

    if (unconditional == 0) {
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
    sprite = moving_master->run_sprite;
    if (sprite == 0) {
        sprite = moving_master->move_sprite;
    }

    move_action = new RGE_Action_Move_To(this, x, y, z, minRange, sprite);
    if (move_action == 0) {
        return 0;
    }
    this->actions->delete_list();
    this->set_only_action(move_action);

success:
    return 1;
}

int RGE_Combat_Object::moveAwayFrom(int targetID, int unconditional) { return 0; }

int RGE_Combat_Object::gather(int targetID, int unconditional) {
    RGE_Static_Object* target = this->owner->world->object(targetID);
    RGE_Task* task;
    RGE_Action_Gather* action;
    if (target == 0) {
        return 0;
    }

    if (unconditional == 0 && this->actions->have_action() == 1 &&
        this->actions->get_action()->get_target_obj() == target && this->actions->get_action()->type() == 5) {
        goto success;
    }

    if (this->actions->have_action() == 1 && this->actions->get_action()->type() == 5) {
        this->actions->get_action()->work(target, target->world_x, target->world_y, target->world_z);
        goto success;
    }

    task = this->getTask(target, target->world_x, target->world_y, target->world_z);
    if (task == 0) {
        return 0;
    }

    action = new RGE_Action_Gather(this, task, target);
    if (action == 0) {
        return 0;
    }

    this->actions->delete_list();
    this->set_only_action(action);
success:
    return 1;
}

int RGE_Combat_Object::explore(int tX, int tY, int unconditional) {
    if (unconditional == 0) {
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
            action->work(0, (float)tX, (float)tY, this->world_z);
            goto done;
        }
    }

    {
        RGE_Action_Explore* explore_action = new RGE_Action_Explore(this, 0, (float)tX, (float)tY, this->world_z);
        if (explore_action == 0)
            return 0;

        actions->delete_list();
        this->set_only_action(explore_action);
    }

done:
    return 1;
}

int RGE_Combat_Object::enter(int targetID, int unconditional) {
    RGE_Static_Object* obj;
    RGE_Task* task;
    RGE_Action_Enter* action_enter;

    obj = this->owner->world->object(targetID);
    if (obj == 0)
        return 0;

    if (unconditional == 0) {
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

    action_enter = new RGE_Action_Enter(this, task, obj);
    if (action_enter == 0)
        return 0;

    this->actions->delete_list();
    this->set_only_action(action_enter);

success:
    return 1;
}

int RGE_Combat_Object::transport(float tX, float tY, float tZ, int unconditional) {
    int result;

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 0x0C) {
            // Call get_action() AGAIN (original does this)
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->work(0, tX, tY, tZ);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, tX, tY, tZ);
    result = 0;
    if (transport != 0) {
        actions->delete_list();
        this->set_only_action(transport);
        transport->work(this, tX, tY, tZ);
        result = 1;
    }
    return result;
}

int RGE_Combat_Object::unload(int unconditional, float x, float y, float z) {
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
    transport->work((RGE_Static_Object*)this, x, y, z);
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

float RGE_Combat_Object::damageCapability(RGE_Static_Object* attackingUnit) {
    float attackModifier;

    attackModifier = attackingUnit->calc_attack_modifier((RGE_Static_Object*)this);
    return calculateDamage(((RGE_Master_Combat_Object*)attackingUnit->master_obj)->weapon_num,
                           ((RGE_Master_Combat_Object*)attackingUnit->master_obj)->weapon,
                           attackModifier, attackingUnit->owner, attackingUnit);
}

int RGE_Combat_Object::inAttackRange(RGE_Static_Object* target) {
    float radiusDistance;
    float rangeDistance;
    float range_x;
    float range_y;

    range_x = master_obj->radius_x;
    range_y = master_obj->radius_y;
    radiusDistance = range_x * range_x + range_y * range_y;
    radiusDistance = (float)sqrt((double)radiusDistance);
    rangeDistance = weaponRange() + radiusDistance + 0.3f;
    if (distance_to_object(target) <= rangeDistance) {
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
