#include "../include/Command.h"
#include "../include/basegame.h"
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"
#include "../include/m_s_obj.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/rge_base_game_global.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long __cdecl debug_timeGetTime(char*, int);

// PDB source order for C:\\msdev\\work\\age1_x1\\Command.cpp.

struct RGE_Command_Work {
    unsigned char command;
    unsigned char gap_01[3];
    int target;
    unsigned char recipient_count;
    unsigned char gap_09[3];
    float target_x;
    float target_y;
};

struct WayPacket {
    unsigned char cmd;
    unsigned char player;
    char pad2[2];
    int rec;
    unsigned char one;
    unsigned char p3;
    unsigned char p4;
    unsigned char p5;
    char rest[12];
};

RGE_Command::RGE_Command(RGE_Game_World* world, TCommunications_Handler* com_hand) {
    this->world = world;
    this->com_hand = com_hand;
    this->last_order = 0;
    this->last_order_size = 0;
}

RGE_Command::~RGE_Command() {
    this->world = 0;
    this->com_hand = 0;
    void* p = this->last_order;
    if (p != 0) {
        free(p);
    }
}

void RGE_Command::reset_communications(TCommunications_Handler* v) {
    this->com_hand = v;
}

RGE_Static_Object* RGE_Command::get_obj(RGE_Obj_Info info) {
    if (info.id == -1) {
        return 0;
    }
    return this->world->object(info.id);
}

void RGE_Command::do_commands(void) {
    void* command;

    if (this->com_hand != 0) {
        while ((command = this->com_hand->get_command()) != 0) {
            this->do_command(command);
            if (command != 0) {
                operator delete(command);
            }
        }
    }
}

void RGE_Command::do_command(void* cmd)
{
    switch (*(unsigned char*)cmd) {
    case 0:
        do_command_order((RGE_Command_Order*)cmd);
        return;
    case 1:
        do_command_stop((RGE_Command_Stop*)cmd);
        return;
    case 2:
        do_command_work((RGE_Command_Order*)cmd);
        return;
    case 3:
        do_command_move((RGE_Command_Order*)cmd);
        return;
    case 4:
        do_command_create((RGE_Command_Create*)cmd);
        return;
    case 5:
        do_command_add_attribute((RGE_Command_Add_Attribute*)cmd);
        return;
    case 6:
        do_command_formation((RGE_Command_Formation*)cmd);
        return;
    case 7:
        this->do_command_give_attribute((RGE_Command_Give_Attribute*)cmd);
        return;
    case 8:
        do_command_create_group((RGE_Command_Create_Group*)cmd);
        return;
    case 9:
        do_command_destroy_group((RGE_Command_Destroy_Group*)cmd);
        return;
    case 10:
        do_command_ai_order((RGE_Command_AI_Order*)cmd);
        return;
    case 17:
        do_command_group_ai_order((RGE_Command_Group_AI_Order*)cmd);
        return;
    case 11:
        do_command_resign((RGE_Command_Resign*)cmd);
        return;
    case 12:
        do_command_add_waypoint((RGE_Command_Add_Waypoint*)cmd);
        return;
    case 16:
        do_command_group_waypoint((RGE_Command_Group_Waypoint*)cmd);
        return;
    case 14:
        do_command_add_to_group((RGE_Command_Add_To_Group*)cmd);
        return;
    case 15:
        do_command_remove_from_group((RGE_Command_Remove_From_Group*)cmd);
        return;
    }
}

void RGE_Command::do_command_order(RGE_Command_Order* command)
{
    int unit_num = command->unit_num;
    RGE_Obj_Info* units = command->units;
    RGE_Static_Object* target = this->get_obj(command->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        if (unit_num > 0) {
            int remaining = unit_num;
            RGE_Obj_Info* unit = units;
            do {
                RGE_Static_Object* object = this->get_obj(*unit);
                if (object != 0) {
                    if (object->world_x < min_x) {
                        min_x = object->world_x;
                    } else if (object->world_x > max_x) {
                        max_x = object->world_x;
                    }

                    if (object->world_y < min_y) {
                        min_y = object->world_y;
                    } else if (object->world_y > max_y) {
                        max_y = object->world_y;
                    }

                    total_x += object->world_x;
                    total_y += object->world_y;
                }
                ++unit;
                --remaining;
            } while (remaining != 0);
        }

        if (max_x - min_x <= DAT_0056f4d8 &&
            max_y - min_y <= DAT_0056f4d8) {
            total_x /= (float)unit_num;
            total_y /= (float)unit_num;

            RGE_Obj_Info* unit;
            int index = 0;
            if (unit_num > 0) {
                unit = units;
                do {
                    RGE_Static_Object* object = this->get_obj(*unit);
                    if (object != 0) {
                        object->removeAllFromPathingGroup();
                        object->setWaitingToMove(1);

                        int other_index = 0;
                        RGE_Obj_Info* other_unit = units;
                        do {
                            if (other_index != index)
                                object->addToPathingGroup(other_unit->id);
                            ++other_index;
                            ++other_unit;
                        } while (other_index < unit_num);

                        float adjusted_x =
                            (object->world_x - total_x) + command->location_x;
                        float adjusted_y =
                            (object->world_y - total_y) + command->location_y;

                        if (adjusted_x < DAT_0056f4e0) {
                            adjusted_x = 1.0f;
                        } else {
                            float width = (float)object->owner->world->map->map_width;
                            if (adjusted_x >= width)
                                adjusted_x = width - DAT_0056f4e8;
                        }

                        if (adjusted_y < DAT_0056f4e0) {
                            adjusted_y = 1.0f;
                        } else {
                            float height = (float)object->owner->world->map->map_height;
                            if (adjusted_y >= height)
                                adjusted_y = height - DAT_0056f4e8;
                        }

                        if (target != 0 &&
                            (target->master_obj->radius_x > DAT_0056f4e0 ||
                             target->master_obj->radius_y > DAT_0056f4e0)) {
                            object->do_command(target, adjusted_x, adjusted_y, 0);
                        } else {
                            object->do_command(0, adjusted_x, adjusted_y, 0);
                        }
                    }
                    ++index;
                    ++unit;
                } while (index < unit_num);
            }
            return;
        }
    }

    int index = 0;
    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* object = this->get_obj(*unit);
            if (object != 0) {
                object->removeAllFromPathingGroup();
                object->setWaitingToMove(1);

                int other_index = 0;
                RGE_Obj_Info* other_unit = units;
                do {
                    if (other_index != index)
                        object->addToPathingGroup(other_unit->id);
                    ++other_index;
                    ++other_unit;
                } while (other_index < unit_num);

                object->do_command(target, command->location_x,
                                   command->location_y, 0);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}

void RGE_Command::do_command_stop(RGE_Command_Stop* stop) {
    int count = stop->unit_num;
    RGE_Obj_Info* id = (RGE_Obj_Info*)stop->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->stop();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}

void RGE_Command::do_command_pause(RGE_Command_Pause* pause) {
    int count = pause->unit_num;
    RGE_Obj_Info* id = (RGE_Obj_Info*)pause->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->pause();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}

void RGE_Command::do_command_work(RGE_Command_Order* order)
{
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = order->units;
    RGE_Static_Object* target = this->get_obj(order->target);
    int index = 0;

    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* obj = this->get_obj(*unit);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->setWaitingToMove(1);
                int i = 0;
                do {
                    if (i != index)
                        obj->addToPathingGroup(units[i].id);
                    ++i;
                } while (i < unit_num);
                obj->work(target, order->location_x, order->location_y, 0);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}




void RGE_Command::do_command_move(RGE_Command_Order* order) {
    int n = order->unit_num;
    RGE_Obj_Info* ids = order->units;
    RGE_Static_Object* target = this->get_obj(order->target);
    if (n > 1) {
        float minx = 10000.0f;
        float maxx = 0.0f;
        float miny = 10000.0f;
        float maxy = 0.0f;
        float totalx = 0.0f;
        float totaly = 0.0f;
        if (n > 0) {
            int i = n;
            RGE_Obj_Info* p = ids;
            do {
                RGE_Static_Object* obj = this->get_obj(*p);
                if (obj) {
                    if (obj->world_x < minx) minx = obj->world_x; else if (obj->world_x > maxx) maxx = obj->world_x;
                    if (obj->world_y < miny) miny = obj->world_y; else if (obj->world_y > maxy) maxy = obj->world_y;
                    totalx += obj->world_x;
                    totaly += obj->world_y;
                }
                ++p;
            } while (--i);
        }
        if (maxx - minx > DAT_0056f4d8 || maxy - miny > DAT_0056f4d8) goto simple;
        totalx /= (float)n;
        totaly /= (float)n;
        int idx = 0;
        if (n > 0) {
            RGE_Obj_Info* p = ids;
            do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setWaitingToMove(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                float nx = (obj->world_x - totalx) + order->location_x;
                float ny = (obj->world_y - totaly) + order->location_y;
                if (nx < DAT_0056f4e0) nx = 1.0f;
                else {
                    float width = (float)obj->owner->world->map->map_width;
                    if (nx >= width) nx = width - DAT_0056f4e8;
                }
                if (ny < DAT_0056f4e0) ny = 1.0f;
                else {
                    float height = (float)obj->owner->world->map->map_height;
                    if (ny >= height) ny = height - DAT_0056f4e8;
                }
                if (target != 0 &&
                    (target->master_obj->radius_x > DAT_0056f4e0 ||
                     target->master_obj->radius_y > DAT_0056f4e0))
                obj->move_to(target, nx, ny, 0);
                else
                obj->move_to(0, nx, ny, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master_obj->radius_x > DAT_0056f4e0 ||
                         target->master_obj->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master_obj->object_group, nx, ny, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, nx, ny, 0.0f);
                }
            }
                ++idx; ++p;
            } while (idx < n);
        }
        return;
    }
simple:
    int idx = 0;
    if (n > 0) {
        RGE_Obj_Info* p = ids;
        do {
            RGE_Static_Object* obj = this->get_obj(*p);
            if (obj) {
                obj->removeAllFromPathingGroup(); obj->setWaitingToMove(1);
                int j = 0; RGE_Obj_Info* q = ids;
                do { if (j != idx) obj->addToPathingGroup(q->id); ++j; ++q; } while (j < n);
                obj->move_to(target, order->location_x, order->location_y, 0);
                UnitAIModule* ai = obj->unitAI();
                if (ai) {
                    obj->unitAI()->setCurrentOrder(0x2c6); obj->unitAI()->setCurrentAction(0x262);
                    if (target != 0 &&
                        (target->master_obj->radius_x > DAT_0056f4e0 ||
                         target->master_obj->radius_y > DAT_0056f4e0))
                        obj->unitAI()->setCurrentTarget(target->id, target->master_obj->object_group, order->location_x, order->location_y, 0.0f);
                    else obj->unitAI()->setCurrentTarget(-1, -1, order->location_x, order->location_y, 0.0f);
                }
            }
            ++idx; ++p;
        } while (idx < n);
    }
}

void RGE_Command::do_command_create(RGE_Command_Create* param_1) {
    RGE_Player* player = this->world->players[param_1->player_id];
    RGE_Master_Static_Object* master = player->master_objects[param_1->obj_catagory];
    master->make_new_obj(player, param_1->location_x, param_1->location_y,
                         param_1->location_z);
}

void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* param_1) {
    RGE_Player* player = this->world->players[param_1->player_id];
    player->add_attribute_num(param_1->attr_id, param_1->amount, 0);
}

void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* cmd)
{
    RGE_Player* player = this->world->players[cmd->player_id];

    if (player->attributes[cmd->attr_id] >= cmd->amount) {
        player->add_attribute_num(cmd->attr_id, -cmd->amount, 0);
        this->world->players[cmd->to_player_id]->add_attribute_num(
            cmd->attr_id, cmd->amount, 0);

        rge_base_game->notification(7, cmd->player_id, cmd->to_player_id,
                                    cmd->attr_id, (long)cmd->amount);

        this->world->players[cmd->to_player_id]->notify(
            cmd->player_id, cmd->to_player_id, 0x20A, cmd->attr_id,
            (long)cmd->amount, 0);
    }
}

#pragma intrinsic(sqrt)


void RGE_Command::do_command_formation(RGE_Command_Formation* command)
{
    int unit_num = command->unitNum;
    RGE_Obj_Info* units = command->units;

    if (unit_num > 1) {
        RGE_Static_Object* reference_unit = 0;
        float distance;
        int i = 0;
        if (i < unit_num) {
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    float object_distance =
                        (float)sqrt(object->world_x * object->world_x +
                                    object->world_y * object->world_y);
                    if (i == 0 || object_distance < distance) {
                        reference_unit = object;
                        distance = object_distance;
                    }
                }
                ++i;
                ++units;
            } while (i < unit_num);
        }

        float adjusted_y = 1.0f;
        float temp_x = 1.0f;
        int alternate = 0;
        switch (command->formationID) {
        case 0:
            adjusted_y = 1.0f;
            temp_x = 1.0f;
            break;
        case 2:
        case 3:
            adjusted_y = 2.0f;
            temp_x = 2.0f;
            break;
        case 1:
        case 4:
        case 5:
            adjusted_y = 1.5f;
            temp_x = 1.5f;
            break;
        }

        int index = 0;
        if (index < unit_num) {
            units = command->units;
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    object->removeAllFromPathingGroup();
                    object->setWaitingToMove(1);

                    int other_index = 0;
                    RGE_Obj_Info* other_unit = command->units;
                    do {
                        if (other_index != index)
                            object->addToPathingGroup(other_unit->id);
                        ++other_index;
                        ++other_unit;
                    } while (other_index < unit_num);

                    if (object != reference_unit) {
                        float temp_count = reference_unit->world_x;
                        float adjusted_x = reference_unit->world_y;

                        switch (command->formationID) {
                        case 0:
                            temp_count += adjusted_y;
                            adjusted_y = adjusted_y - -1.0f;
                            adjusted_x = adjusted_x + temp_x;
                            temp_x = temp_x - -1.0f;
                            break;
                        case 1:
                            temp_count = temp_count + adjusted_y;
                            adjusted_y = adjusted_y - -1.5f;
                            adjusted_x = adjusted_x - temp_x;
                            temp_x = temp_x - -1.5f;
                            break;
                        case 2:
                            temp_count += adjusted_y;
                            adjusted_y = adjusted_y - -2.0f;
                            break;
                        case 3:
                            adjusted_x += temp_x;
                            temp_x = temp_x - -2.0f;
                            break;
                        case 5:
                            temp_count -= adjusted_y;
                            if (alternate == 0) {
                                adjusted_x -= temp_x;
                                alternate = 1;
                            } else {
                                adjusted_x += temp_x;
                                temp_x = temp_x - -1.5f;
                                adjusted_y = adjusted_y - -1.5f;
                                alternate = 0;
                            }
                            break;
                        case 4:
                            temp_count += adjusted_y;
                            if (alternate == 0) {
                                adjusted_x -= temp_x;
                                alternate = 1;
                            } else {
                                adjusted_x += temp_x;
                                temp_x = temp_x - -1.5f;
                                adjusted_y = adjusted_y - -1.5f;
                                alternate = 0;
                            }
                            break;
                        }

                        object->move_to(0, temp_count, adjusted_x, 1.0f);
                    }
                }
                ++index;
                ++units;
            } while (index < unit_num);
        }
    }
}

void RGE_Command::do_command_ai_order(RGE_Command_AI_Order* cmd) {
    RGE_Static_Object* obj = this->world->object(cmd->recipient);
    if (obj != 0) {
        obj->removeAllFromPathingGroup();
        RGE_Game_World* world = this->world;
        RGE_Player* player = (RGE_Player*)world->players[cmd->player_id];
        player->processAIOrder(cmd->issuer, cmd->recipient, cmd->orderType, cmd->target,
                         cmd->targetOwner, cmd->targetX, cmd->targetY, cmd->targetZ,
                         cmd->range, cmd->immediate, cmd->inFront, cmd->orderPriority);
    }
}

void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order* command)
{
    RGE_Command* self = this;
    int count = command->recipient_count;
    RGE_Obj_Info* recipient_base = (RGE_Obj_Info*)(command + 1);

    if (count > 0) {
        RGE_Obj_Info* recipients = recipient_base;
        int loop_count = count;
        do {
            RGE_Static_Object* object = self->get_obj(*recipients);
            if (object != 0) {
                int default_coord = -1082130432;
                float target_x;
                if (*(int*)&command->targetX != default_coord)
                    target_x = command->targetX;
                else
                    target_x = object->world_x;

                float target_y;
                if (*(int*)&command->targetY != default_coord)
                    target_y = command->targetY;
                else
                    target_y = object->world_y;

                float target_z;
                if (*(int*)&command->targetZ != default_coord)
                    target_z = command->targetZ;
                else
                    target_z = object->world_z;

                object->removeAllFromPathingGroup();

                RGE_Player* player = self->world->players[command->player_id];
                player->processAIOrder(command->issuer, object->id,
                                       command->orderType, command->target,
                                       command->targetOwner, target_x, target_y,
                                       target_z, command->range,
                                       command->immediate, command->inFront,
                                       command->orderPriority);
            }
            ++recipients;
            --loop_count;
        } while (loop_count != 0);
    }
}



void RGE_Command::do_command_resign(RGE_Command_Resign* cmd)
{
    if (rge_base_game->multiplayerGame()) {
        RGE_Base_Game* game = rge_base_game;
        int comm = cmd->comm_player_id;
        int total = 0; int resigned_count = 0; int i = 1;
        game->resigned[comm] = 1;
        do { if (rge_base_game->playerID(i) == cmd->player_id) { total++; if (rge_base_game->resigned[i]) resigned_count++; } i++; } while (i < 9);
        if (total != resigned_count) return;
        this->world->players[cmd->player_id]->do_resign(cmd->dropped);
        return;
    }
    this->world->players[cmd->player_id]->do_resign(cmd->dropped);
}

void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* param_1) {
    if (this->world->object(param_1->recipient) != 0) {
        this->world->players[param_1->player_id]->processAddWaypointCommand(param_1->recipient, param_1->waypoint, param_1->numberWaypoints);
    }
}


typedef unsigned char uchar;


void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* packet) {
    int c;
    RGE_Obj_Info* ids;
    XYZBYTEPoint waypoint;

    c = packet->unit_num;
    ids = (RGE_Obj_Info*)((char*)packet + 4);
    if (c > 0) {
        int count = c;
        do {
            RGE_Static_Object* obj = this->get_obj(*ids);
            if (obj != 0) {
                waypoint.x = packet->x;
                waypoint.y = packet->y;
                waypoint.z = 0;
                obj->owner->processAddWaypointCommand(obj->id, &waypoint, 1);
            }
            ++ids;
            --count;
        } while (count != 0);
    }
}

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* param_1) {
    RGE_Static_Object* object = this->world->object(param_1->groupCommander);
    if (object != 0 && object->owner->id == (unsigned short)param_1->player_id) {
        object->commanderCreateGroup(param_1->unitsToGroup,
                                     (int)param_1->numberUnitsToGroup,
                                     param_1->groupCommander,
                                     param_1->groupRange);
    }
}


void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group* command) {
    RGE_Static_Object* object = this->world->object(command->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)command->player_id)) {
        int newUnit = command->newUnit;
        int groupRange = command->groupRange;
        object->commanderAddToGroup(newUnit, groupRange);
    }
}


void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* command) {
    RGE_Static_Object* object = this->world->object(command->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)command->player_id)) {
        object->commanderRemoveFromGroup(command->unit);
    }
}

void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* cmd) {
    RGE_Static_Object* obj = (RGE_Static_Object*)this->world->object(cmd->groupCommander);

    if (obj != 0) {
        if (obj->owner->id == (unsigned short)cmd->player_id)
            obj->commanderDestroyGroup();
    }
}



unsigned char RGE_Command::duplicate_check_command_order(RGE_Command_Order* param_1)
{
    unsigned int n = (unsigned char)param_1->unit_num;
    long* p1 = (long*)param_1->units;
    RGE_Command_Order* last_order = (RGE_Command_Order*)this->last_order;
    unsigned int last_n = (unsigned char)last_order->unit_num;
    long* p2 = (long*)last_order->units;

    if (n == last_n) {

        if ((short)(int)last_order->location_x == (short)(int)param_1->location_x) {
            if ((short)(int)last_order->location_y == (short)(int)param_1->location_y) {
                long target_id = last_order->target.id;
                if (target_id == param_1->target.id) {
                    for (int i = 0; i < (int)n; i++) {
                        if (p1[i] != p2[i])
                            goto fail;
                    }
                    return 1;
                }
            }
        }
    }
fail:
    return 0;
}

unsigned char RGE_Command::duplicate_check_command_stop(RGE_Command_Stop* param1) {
    int n = *(unsigned char*)((char*)param1 + 1);
    long* p = (long*)((char*)param1 + 2);
    RGE_Command_Stop* last = (RGE_Command_Stop*)this->last_order;
    long* l = (long*)((char*)last + 2);

    if (n != *(unsigned char*)((char*)last + 1)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (p[i] != l[i]) {
            return 0;
        }
    }

    return 1;
}


unsigned char RGE_Command::close_check_for_duplicate_orders(unsigned char* param_1) {
    unsigned char selector = *param_1;
    switch (selector) {
    case 0:
    case 2:
    case 3:
        if (this->duplicate_check_command_order((RGE_Command_Order*)param_1) != 0) {
            return 1;
        }
        break;
    case 1:
        if (this->duplicate_check_command_stop((RGE_Command_Stop*)param_1) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

unsigned char RGE_Command::check_for_duplicate_orders(unsigned char* order, long size) {
    if (last_order != 0) {
        if (last_order_size == size) {
            if (*last_order == *order) {
                unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 0x497);
                if ((int)(now - last_order_time) < 0x1F4) {
                    return close_check_for_duplicate_orders(order);
                }
            }
        }
    }
    return 0;
}

void RGE_Command::submit(void* order, long size) {
    unsigned char dup = check_for_duplicate_orders((unsigned char*)order, size);
    if (dup == 0) {
        com_hand->new_command(order, size);
    }
    if (last_order != 0) {
        free(last_order);
    }
    last_order = (unsigned char*)order;
    last_order_size = size;
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 0x4AC);
    last_order_time = t;
}

void RGE_Command::command_order(RGE_Static_Object** list, short list_num,
                                RGE_Static_Object* target, float x, float y)
{
    int size = list_num * 4 + 0x14;
    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            if (target != 0) {
                *(int*)(buf + 4) = target->id;
            } else {
                *(int*)(buf + 4) = -1;
            }
            buf[0] = 0;
            buf[8] = (unsigned char)list_num;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;

            const char* target_name;
            if (target != 0) {
                target_name = target->master_obj->name;
            } else {
                target_name = "X";
            }
            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log("      >SEND CMD ORDER (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", list_num, owner, name, target_name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_stop(RGE_Static_Object** list, short list_num)
{
    int size = list_num * 4 + 2;
    if (list != 0 && list_num >= 1) {
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 2);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) dst[i] = list[i]->id;
                else dst[i] = -1;
            }
            buf[0] = 1;
            buf[1] = (char)list_num;
            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }
            L->Log("      >SEND CMD STOP (CNT=%d,OWN=%d,UNIT=%s)", list_num, owner, name);
            this->submit(buf, size);
        }
    }
}




void RGE_Command::command_stop(int player, int* arr, int count)
{
    if (arr != 0 && count >= 1) {
        int size = count * 4 + 2;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 2);
        if (buf != 0) {
            if (count > 0) { int delta = (char*)arr - (char*)dst; int n = count; do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n); }
            buf[0] = 1; buf[1] = (char)count;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = *(const char**)((char*)obj->master_obj + 8); else name = "X";
            L->Log("      >SEND CMD STOP2 (CNT=%d,OWN=%d,UNIT=%s)", count, player, name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_pause(int param_1, int* data, int count) {
    if (data != 0 && count >= 1) {
        int alloc_size = count * 4 + 2;
        unsigned char* buf = (unsigned char*)calloc(1, alloc_size);
        if (buf != 0) {
            int* dst = (int*)(buf + 2);
            if (count > 0) {
                int* src = data;
                int n = count;
                do {
                    *dst = *src;
                    ++dst;
                    ++src;
                    --n;
                } while (n != 0);
            }
            buf[0] = 0x0D;
            buf[1] = (unsigned char)count;
            L->Log("      >SEND CMD PAUSE");
            this->submit(buf, alloc_size);
        }
    }
}

void RGE_Command::command_work(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    int size = list_num * 4 + 0x14;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        RGE_Command_Work* packet = (RGE_Command_Work*)buf;
        int* dst = (int*)(packet + 1);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            if (target != 0) {
                packet->target = target->id;
            } else {
                packet->target = -1;
            }
            packet->command = 2;
            packet->recipient_count = (unsigned char)list_num;
            packet->target_x = x;
            packet->target_y = y;

            const char* target_name;
            if (target != 0) {
                target_name = target->master_obj->name;
            } else {
                target_name = "X";
            }

            RGE_Static_Object* obj = list[0];
            const char* unit_name;
            int owner;
            if (obj != 0) {
                unit_name = obj->master_obj->name;
            } else {
                unit_name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log("      >SEND CMD WORK (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", list_num, owner, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_work(int player, int* arr, int count, int target, int unused, float x, float y)
{
    int* src;
    if (arr != 0 && count >= 1) {
        src = arr;
        int size = count * 4 + 0x14;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            if (count > 0) { int delta = (char*)src - (char*)dst; int n = count; do { *dst = *(int*)((char*)dst + delta); dst++; } while (--n); }
            *(float*)(buf + 0x0C) = x;
            buf[0] = 2;
            buf[8] = (char)count;
            *(int*)(buf + 4) = target;
            *(float*)(buf + 0x10) = y;
            RGE_Static_Object* unit_obj = this->world->object(src[0]);
            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name; if (target_obj != 0) target_name = *(const char**)((char*)target_obj->master_obj + 8); else target_name = "X";
            const char* unit_name; if (unit_obj != 0) unit_name = *(const char**)((char*)unit_obj->master_obj + 8); else unit_name = "X";
            L->Log("      >SEND CMD WORK2 (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", count, player, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_move(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    if (list != 0 && list_num >= 1) {
        int size = list_num * 4 + 0x14;
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            if (target != 0) {
                *(int*)(buf + 4) = target->id;
            } else {
                *(int*)(buf + 4) = -1;
            }
            buf[0] = 3;
            buf[8] = (unsigned char)list_num;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;

            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log("      >SEND CMD MOVE (CNT=%d,OWN=%d,UNIT=%s)", list_num, owner, name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_move(int player, int* arr, int count, int param4, int unused, float x, float y)
{
    if (arr != 0 && count >= 1) {
        int size = count * 4 + 0x14;
        char* buf = (char*)calloc(1, size);
        int* dst = (int*)(buf + 0x14);
        if (buf != 0) {
            for (int i = 0; i < count; ++i) dst[i] = arr[i];
            buf[0] = 3; buf[8] = (char)count;
            *(int*)(buf + 4) = param4;
            *(float*)(buf + 0x0C) = x;
            *(float*)(buf + 0x10) = y;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = obj->master_obj->name; else name = "X";
            L->Log("      >SEND CMD MOVE2 (CNT=%d,OWN=%d,UNIT=%s)", count, player, name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_create(short param_1, short param_2, float param_3, float param_4, float param_5) {
    unsigned char* packet = (unsigned char*)calloc(1, 0x14);
    packet[0] = 4;
    *(short*)(packet + 2) = param_1;
    packet[4] = (unsigned char)param_2;
    *(float*)(packet + 8) = param_3;
    *(float*)(packet + 0xC) = param_4;
    *(float*)(packet + 0x10) = param_5;
    L->Log("      >SEND CMD CREATE (CAT=%d,PLR=%d)",
           (int)param_1, (int)param_2);
    this->submit(packet, 0x14);
}

void RGE_Command::command_add_attribute(int param_1, int param_2, float param_3) {
    unsigned char* cmd = (unsigned char*)calloc(1, 8);
    cmd[0] = 5;
    cmd[1] = (unsigned char)param_1;
    cmd[2] = (unsigned char)param_2;
    *(float*)(cmd + 4) = param_3;
    L->Log("      >SEND CMD ADD ATTR (PLR=%d,ATT=%d)", param_1, param_2);
    this->submit(cmd, 8);
}

void RGE_Command::command_give_attribute(int param_1, int param_2, int param_3, float param_4) {
    unsigned char* cmd = (unsigned char*)calloc(1, 8);
    cmd[0] = 7;
    cmd[1] = (unsigned char)param_1;
    cmd[2] = (unsigned char)param_2;
    cmd[3] = (unsigned char)param_3;
    *(float*)(cmd + 4) = param_4;
    L->Log("      >SEND CMD GIV ATTR (FRM=%d,TO=%d,ATT=%d)",
           param_1, param_2, param_3);
    submit(cmd, 8);
}

void RGE_Command::command_formation(RGE_Static_Object** list, int list_num,
                                    int formation)
{
    int size = list_num * 4 + 0x0C;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x0C);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            buf[0] = 6;
            *(int*)(buf + 4) = list_num & 0xFF;
            *(int*)(buf + 8) = formation;

            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log("      >SEND CMD FORMATION (CNT=%d,OWN=%d,UNIT=%s)", list_num, owner, name);
            this->submit(buf, size);
        }
    }
}






void RGE_Command::command_create_group(int p1, int p2, int* p3, int p4, float p5)
{
    char* buf = (char*)calloc(1, 0x74);
    int count = p4;

    buf[0] = 8;
    buf[1] = (char)p1;
    *(int*)(buf + 4) = p2;

    if (count > 0) {
        int* d = (int*)(buf + 0x0C);
        int* s = p3;
        int cnt = count;
        do {
            *d = *s;
            d++;
            s++;
        } while (--cnt);
    }

    buf[0x70] = (char)count;
    *(int*)(buf + 8) = p5;

    int first_id = p3[0];
    RGE_Static_Object* obj = this->world->object(first_id);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = ((const char*)0x00583B74);
    }
    L->Log((char*)0x00583D74, count, p1, name);
    this->submit(buf, 0x74);
}

void RGE_Command::command_add_to_group(int plr, int rec, int target, float angle) {
    char* buf = (char*)calloc(1, 0x10);

    *(int*)(buf + 4) = rec;
    *buf = 0x0E;
    *(buf + 1) = (char)plr;
    *(int*)(buf + 0x0C) = target;
    *(float*)(buf + 0x08) = angle;

    void* obj = this->world->object(target);
    const char* name;
    if (obj != 0) {
        RGE_Static_Object* sobj = (RGE_Static_Object*)obj;
        name = sobj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD ADD GROUP (PLR=%d,UNIT=%s)", plr, name);

    this->submit(buf, 0x10);
}

void RGE_Command::command_remove_from_group(int param_1, int param_2, int param_3) {
    unsigned char* cmd = (unsigned char*)calloc(1, 0xC);
    cmd[0] = 0x0F;
    cmd[1] = (unsigned char)param_1;
    *(int*)(cmd + 4) = param_2;
    *(int*)(cmd + 8) = param_3;

    RGE_Static_Object* obj = this->world->object(param_3);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD REM GROUP (PLR=%d,UNIT=%s)", param_1, name);
    this->submit(cmd, 0xC);
}

struct CommandDestroyGroupPacket {
    unsigned char type;
    unsigned char player_id;
    unsigned short gap_02;
    int group_id;
};

void RGE_Command::command_destroy_group(int player_id, int group_id) {
    CommandDestroyGroupPacket* packet = (CommandDestroyGroupPacket*)calloc(1, 8);
    packet->type = 9;
    packet->player_id = (unsigned char)player_id;
    packet->group_id = group_id;
    L->Log("      >SEND CMD DES GROUP (PLR=%d)", player_id);
    this->submit(packet, 8);
}

void RGE_Command::command_ai_order(int player, int issuer, int recipient,
                                   int order_type, int target, int target_owner,
                                   float target_x, float target_y, float target_z,
                                   float range, unsigned char immediate,
                                   unsigned char in_front,
                                   unsigned char order_priority)
{
    RGE_Command_AI_Order* cmd =
        (RGE_Command_AI_Order*)calloc(1, sizeof(RGE_Command_AI_Order));

    cmd->player_id = (unsigned char)player;
    cmd->issuer = (unsigned char)issuer;
    cmd->orderType = (short)order_type;
    cmd->orderPriority = order_priority;
    cmd->targetOwner = (unsigned char)target_owner;
    cmd->targetX = target_x;
    cmd->targetY = target_y;
    cmd->targetZ = target_z;
    cmd->command = 10;
    cmd->recipient = recipient;
    cmd->target = target;
    cmd->range = range;
    cmd->immediate = immediate;
    cmd->inFront = in_front;

    RGE_Static_Object* recipient_obj = this->world->object(recipient);
    RGE_Static_Object* target_obj = this->world->object(target);

    const char* target_name;
    if (target_obj != 0)
        target_name = target_obj->master_obj->name;
    else
        target_name = "X";

    const char* recipient_name;
    if (recipient_obj != 0)
        recipient_name = recipient_obj->master_obj->name;
    else
        recipient_name = "X";

    L->Log("      >SEND CMD AI ORD (PLR=%d, TYP=%d, ISS=%d, REC=%d-%s, TAR=%d-%s, TXY=%d,%d)", player, order_type, issuer, recipient,
           recipient_name, target, target_name, (long)target_x, (long)target_y);
    this->submit(cmd, 0x28);
}

void RGE_Command::command_group_ai_order(
    int player, int issuer, RGE_Static_Object** list, short list_num,
    int order_type, int target, int target_owner, float target_x,
    float target_y, float target_z, float range, unsigned char immediate,
    unsigned char in_front, unsigned char order_priority)
{
    if (list != 0 && list_num >= 1) {
        int size = list_num * 4 + 0x24;
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 0x24);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            RGE_Command_Group_AI_Order* packet =
                (RGE_Command_Group_AI_Order*)buf;
            packet->command = 0x11;
            packet->player_id = (unsigned char)player;
            packet->issuer = (unsigned char)issuer;
            packet->recipient_count = (unsigned char)list_num;
            packet->orderType = (short)order_type;
            packet->orderPriority = order_priority;
            packet->target = target;
            packet->targetOwner = (unsigned char)target_owner;
            packet->targetX = target_x;
            packet->targetY = target_y;
            packet->targetZ = target_z;
            packet->range = range;
            packet->immediate = immediate;
            packet->inFront = in_front;

            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name;
            if (target_obj != 0) {
                target_name = target_obj->master_obj->name;
            } else {
                target_name = "X";
            }

            RGE_Static_Object* obj = list[0];
            const char* unit_name;
            if (obj != 0) {
                unit_name = obj->master_obj->name;
            } else {
                unit_name = "X";
            }

            L->Log("      >SEND CMD GRP AI ORD (PLR=%d, TYP=%d, ISS=%d, CNT=%d, REC=%s, TAR=%s)", player, order_type,
                   issuer, list_num, unit_name, target_name);
            this->submit(buf, size);
        }
    }
}

void RGE_Command::command_resign(int player, int drop, int reason) {
    unsigned char* packet = (unsigned char*)calloc(1, 4);
    packet[2] = (unsigned char)drop;
    packet[0] = 0x0B;
    packet[1] = (unsigned char)player;
    packet[3] = (unsigned char)reason;
    L->Log("      >SEND CMD RESIGN (PLR=%d,DROP=%d)", player, reason);
    this->submit(packet, 4);
}

void RGE_Command::command_add_waypoint(int player, int obj_id, XYZBYTEPoint* pts, int count)
{
    unsigned char* buf = (unsigned char*)calloc(1, 0x18);
    buf[0] = 0x0C;
    buf[1] = (unsigned char)player;
    *(int*)(buf + 4) = obj_id;
    buf[8] = (unsigned char)count;

    for (int i = 0; i < count; i++) {
        buf[9 + i * 3 + 0] = pts[i].x;
        buf[9 + i * 3 + 1] = pts[i].y;
        buf[9 + i * 3 + 2] = pts[i].z;
    }

    RGE_Static_Object* obj = this->world->object(obj_id);
    char* name;
    if (obj != 0)
        name = obj->master_obj->name;
    else
        name = "X";

    L->Log("      >SEND CMD ADD WAY (PLR=%d,REC=%s)", player, name);

    submit(buf, 0x18);
}



void RGE_Command::command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5) {
    WayPacket* buf = (WayPacket*)calloc(1, 0x18);
    buf->cmd = 0x0C;
    buf->player = (unsigned char)player;
    buf->rec = rec;
    buf->one = 1;
    buf->p3 = p3;
    buf->p4 = p4;
    buf->p5 = p5;
    RGE_Static_Object* obj = this->world->object(rec);
    char* name;
    if (obj != 0) name = obj->master_obj->name; else name = (char*)"X";
    L->Log("      >SEND CMD ADD WAY2 (PLR=%d,REC=%s)", player, name);
    this->submit(buf, 0x18);
}

void RGE_Command::command_group_waypoint(RGE_Static_Object** list,
                                         short list_num,
                                         unsigned char x,
                                         unsigned char y)
{
    int size = list_num * 4 + 4;

    if (list != 0 && list_num >= 1) {
        unsigned char* buf = (unsigned char*)calloc(1, size);
        int* dst = (int*)(buf + 4);
        if (buf != 0) {
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    dst[i] = list[i]->id;
                } else {
                    dst[i] = -1;
                }
            }

            buf[0] = 0x10;
            buf[1] = (unsigned char)list_num;
            buf[2] = x;
            buf[3] = y;

            RGE_Static_Object* obj = list[0];
            const char* name;
            int owner;
            if (obj != 0) {
                name = obj->master_obj->name;
            } else {
                name = "X";
            }
            if (obj != 0) {
                owner = obj->owner->id;
            } else {
                owner = -1;
            }

            L->Log("      >SEND CMD GRP WAY (PLR=%d,UNIT=%s)", owner, name);
            this->submit(buf, size);
        }
    }
}
