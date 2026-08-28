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
    switch (static_cast<RGE_Command_Header*>(cmd)->command) {
    case 0:
        do_command_order(static_cast<RGE_Command_Order*>(cmd));
        return;
    case 1:
        do_command_stop(static_cast<RGE_Command_Stop*>(cmd));
        return;
    case 2:
        do_command_work(static_cast<RGE_Command_Order*>(cmd));
        return;
    case 3:
        do_command_move(static_cast<RGE_Command_Order*>(cmd));
        return;
    case 4:
        do_command_create(static_cast<RGE_Command_Create*>(cmd));
        return;
    case 5:
        do_command_add_attribute(static_cast<RGE_Command_Add_Attribute*>(cmd));
        return;
    case 6:
        do_command_formation(static_cast<RGE_Command_Formation*>(cmd));
        return;
    case 7:
        this->do_command_give_attribute(
            static_cast<RGE_Command_Give_Attribute*>(cmd));
        return;
    case 8:
        do_command_create_group(static_cast<RGE_Command_Create_Group*>(cmd));
        return;
    case 9:
        do_command_destroy_group(static_cast<RGE_Command_Destroy_Group*>(cmd));
        return;
    case 10:
        do_command_ai_order(static_cast<RGE_Command_AI_Order*>(cmd));
        return;
    case 17:
        do_command_group_ai_order(
            static_cast<RGE_Command_Group_AI_Order*>(cmd));
        return;
    case 11:
        do_command_resign(static_cast<RGE_Command_Resign*>(cmd));
        return;
    case 12:
        do_command_add_waypoint(static_cast<RGE_Command_Add_Waypoint*>(cmd));
        return;
    case 16:
        do_command_group_waypoint(
            static_cast<RGE_Command_Group_Waypoint*>(cmd));
        return;
    case 14:
        do_command_add_to_group(static_cast<RGE_Command_Add_To_Group*>(cmd));
        return;
    case 15:
        do_command_remove_from_group(
            static_cast<RGE_Command_Remove_From_Group*>(cmd));
        return;
    }
}

void RGE_Command::do_command_order(RGE_Command_Order* command)
{
    int unit_num = command->unit_num;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(command) + sizeof(*command));
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
    RGE_Obj_Info* id = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(stop) + sizeof(*stop));
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
    RGE_Obj_Info* id = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(pause) + sizeof(*pause));
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
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(order) + sizeof(*order));
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
    RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(order) + sizeof(*order));
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
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(command) + sizeof(*command));

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
            units = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(command) + sizeof(*command));
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    object->removeAllFromPathingGroup();
                    object->setWaitingToMove(1);

                    int other_index = 0;
                    RGE_Obj_Info* other_unit =
                        reinterpret_cast<RGE_Obj_Info*>(
                            reinterpret_cast<unsigned char*>(command) +
                            sizeof(*command));
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
        RGE_Player* player = world->players[cmd->player_id];
        player->processAIOrder(cmd->issuer, cmd->recipient, cmd->orderType, cmd->target,
                         cmd->targetOwner, cmd->targetX, cmd->targetY, cmd->targetZ,
                         cmd->range, cmd->immediate, cmd->inFront, cmd->orderPriority);
    }
}

void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order* command)
{
    RGE_Command* self = this;
    int count = command->recipient_count;
    RGE_Obj_Info* recipient_base = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(command) + sizeof(*command));

    if (count > 0) {
        RGE_Obj_Info* recipients = recipient_base;
        int loop_count = count;
        do {
            RGE_Static_Object* object = self->get_obj(*recipients);
            if (object != 0) {
                float target_x;
                if (command->targetX != -1.0f)
                    target_x = command->targetX;
                else
                    target_x = object->world_x;

                float target_y;
                if (command->targetY != -1.0f)
                    target_y = command->targetY;
                else
                    target_y = object->world_y;

                float target_z;
                if (command->targetZ != -1.0f)
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
    ids = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
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
        object->commanderAddToGroup(newUnit, command->group_range);
    }
}


void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* command) {
    RGE_Static_Object* object = this->world->object(command->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)command->player_id)) {
        object->commanderRemoveFromGroup(command->unit);
    }
}

void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* cmd) {
    RGE_Static_Object* obj = this->world->object(cmd->groupCommander);

    if (obj != 0) {
        if (obj->owner->id == (unsigned short)cmd->player_id)
            obj->commanderDestroyGroup();
    }
}



unsigned char RGE_Command::duplicate_check_command_order(RGE_Command_Order* param_1)
{
    unsigned int n = (unsigned char)param_1->unit_num;
    RGE_Obj_Info* p1 = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(param_1) + sizeof(*param_1));
    RGE_Command_Order* last_order =
        reinterpret_cast<RGE_Command_Order*>(this->last_order);
    unsigned int last_n = (unsigned char)last_order->unit_num;
    RGE_Obj_Info* p2 = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(last_order) + sizeof(*last_order));

    if (n == last_n) {

        if ((short)(int)last_order->location_x == (short)(int)param_1->location_x) {
            if ((short)(int)last_order->location_y == (short)(int)param_1->location_y) {
                long target_id = last_order->target.id;
                if (target_id == param_1->target.id) {
                    for (int i = 0; i < (int)n; i++) {
                        if (p1[i].id != p2[i].id)
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
    int n = param1->unit_num;
    RGE_Obj_Info* p = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(param1) + sizeof(*param1));
    RGE_Command_Stop* last =
        reinterpret_cast<RGE_Command_Stop*>(this->last_order);
    RGE_Obj_Info* l = reinterpret_cast<RGE_Obj_Info*>(
        reinterpret_cast<unsigned char*>(last) + sizeof(*last));

    if (n != last->unit_num) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (p[i].id != l[i].id) {
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
        if (this->duplicate_check_command_order(
                reinterpret_cast<RGE_Command_Order*>(param_1)) != 0) {
            return 1;
        }
        break;
    case 1:
        if (this->duplicate_check_command_stop(
                reinterpret_cast<RGE_Command_Stop*>(param_1)) != 0) {
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
    unsigned char dup = check_for_duplicate_orders(
        static_cast<unsigned char*>(order), size);
    if (dup == 0) {
        com_hand->new_command(order, size);
    }
    if (last_order != 0) {
        free(last_order);
    }
    last_order = static_cast<unsigned char*>(order);
    last_order_size = size;
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 0x4AC);
    last_order_time = t;
}

void RGE_Command::command_order(RGE_Static_Object** list, short list_num,
                                RGE_Static_Object* target, float x, float y)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    ids[i].id = list[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            if (target != 0) {
                packet->target.id = target->id;
            } else {
                packet->target.id = -1;
            }
            packet->command = 0;
            packet->unit_num = static_cast<unsigned char>(list_num);
            packet->location_x = x;
            packet->location_y = y;

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
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_stop(RGE_Static_Object** list, short list_num)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Stop) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Stop* packet = static_cast<RGE_Command_Stop*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) ids[i].id = list[i]->id;
                else ids[i].id = -1;
            }
            packet->command = 1;
            packet->unit_num = static_cast<unsigned char>(list_num);
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
            this->submit(packet, size);
        }
    }
}




void RGE_Command::command_stop(int player, int* arr, int count)
{
    if (arr != 0 && count >= 1) {
        int size = sizeof(RGE_Command_Stop) +
                   count * sizeof(RGE_Obj_Info);
        RGE_Command_Stop* packet = static_cast<RGE_Command_Stop*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < count; ++i)
                ids[i].id = arr[i];
            packet->command = 1;
            packet->unit_num = static_cast<unsigned char>(count);
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name;
            if (obj != 0) name = obj->master_obj->name;
            else name = "X";
            L->Log("      >SEND CMD STOP2 (CNT=%d,OWN=%d,UNIT=%s)", count, player, name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_pause(int param_1, int* data, int count) {
    if (data != 0 && count >= 1) {
        int size = sizeof(RGE_Command_Pause) +
                   count * sizeof(RGE_Obj_Info);
        RGE_Command_Pause* packet = static_cast<RGE_Command_Pause*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < count; ++i)
                ids[i].id = data[i];
            packet->command = 0x0D;
            packet->unit_num = static_cast<unsigned char>(count);
            L->Log("      >SEND CMD PAUSE");
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_work(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    ids[i].id = list[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            if (target != 0) {
                packet->target.id = target->id;
            } else {
                packet->target.id = -1;
            }
            packet->command = 2;
            packet->unit_num = static_cast<unsigned char>(list_num);
            packet->location_x = x;
            packet->location_y = y;

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
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_work(int player, int* arr, int count, int target, int unused, float x, float y)
{
    if (arr != 0 && count >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   count * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < count; ++i)
                ids[i].id = arr[i];
            packet->location_x = x;
            packet->command = 2;
            packet->unit_num = static_cast<unsigned char>(count);
            packet->target.id = target;
            packet->location_y = y;
            RGE_Static_Object* unit_obj = this->world->object(arr[0]);
            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name;
            if (target_obj != 0) target_name = target_obj->master_obj->name;
            else target_name = "X";
            const char* unit_name;
            if (unit_obj != 0) unit_name = unit_obj->master_obj->name;
            else unit_name = "X";
            L->Log("      >SEND CMD WORK2 (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", count, player, unit_name, target_name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_move(RGE_Static_Object** list, short list_num,
                               RGE_Static_Object* target, float x, float y)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    ids[i].id = list[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            if (target != 0) {
                packet->target.id = target->id;
            } else {
                packet->target.id = -1;
            }
            packet->command = 3;
            packet->unit_num = static_cast<unsigned char>(list_num);
            packet->location_x = x;
            packet->location_y = y;

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
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_move(int player, int* arr, int count, int param4, int unused, float x, float y)
{
    if (arr != 0 && count >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   count * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < count; ++i) ids[i].id = arr[i];
            packet->command = 3;
            packet->unit_num = static_cast<unsigned char>(count);
            packet->target.id = param4;
            packet->location_x = x;
            packet->location_y = y;
            RGE_Static_Object* obj = this->world->object(arr[0]);
            const char* name; if (obj != 0) name = obj->master_obj->name; else name = "X";
            L->Log("      >SEND CMD MOVE2 (CNT=%d,OWN=%d,UNIT=%s)", count, player, name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_create(short param_1, short param_2, float param_3, float param_4, float param_5) {
    RGE_Command_Create* packet = static_cast<RGE_Command_Create*>(
        calloc(1, sizeof(RGE_Command_Create)));
    packet->command = 4;
    packet->obj_catagory = param_1;
    packet->player_id = static_cast<unsigned char>(param_2);
    packet->location_x = param_3;
    packet->location_y = param_4;
    packet->location_z = param_5;
    L->Log("      >SEND CMD CREATE (CAT=%d,PLR=%d)",
           (int)param_1, (int)param_2);
    this->submit(packet, sizeof(RGE_Command_Create));
}

void RGE_Command::command_add_attribute(int param_1, int param_2, float param_3) {
    RGE_Command_Add_Attribute* cmd =
        static_cast<RGE_Command_Add_Attribute*>(
            calloc(1, sizeof(RGE_Command_Add_Attribute)));
    cmd->command = 5;
    cmd->player_id = static_cast<unsigned char>(param_1);
    cmd->attr_id = static_cast<unsigned char>(param_2);
    cmd->amount = param_3;
    L->Log("      >SEND CMD ADD ATTR (PLR=%d,ATT=%d)", param_1, param_2);
    this->submit(cmd, sizeof(RGE_Command_Add_Attribute));
}

void RGE_Command::command_give_attribute(int param_1, int param_2, int param_3, float param_4) {
    RGE_Command_Give_Attribute* cmd =
        static_cast<RGE_Command_Give_Attribute*>(
            calloc(1, sizeof(RGE_Command_Give_Attribute)));
    cmd->command = 7;
    cmd->player_id = static_cast<unsigned char>(param_1);
    cmd->to_player_id = static_cast<unsigned char>(param_2);
    cmd->attr_id = static_cast<unsigned char>(param_3);
    cmd->amount = param_4;
    L->Log("      >SEND CMD GIV ATTR (FRM=%d,TO=%d,ATT=%d)",
           param_1, param_2, param_3);
    submit(cmd, sizeof(RGE_Command_Give_Attribute));
}

void RGE_Command::command_formation(RGE_Static_Object** list, int list_num,
                                    int formation)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Formation) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Formation* packet = static_cast<RGE_Command_Formation*>(
            calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    ids[i].id = list[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            packet->command = 6;
            packet->unitNum = list_num & 0xFF;
            packet->formationID = formation;

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
            this->submit(packet, size);
        }
    }
}






void RGE_Command::command_create_group(int p1, int p2, int* p3, int p4, float p5)
{
    RGE_Command_Create_Group* packet =
        static_cast<RGE_Command_Create_Group*>(
            calloc(1, sizeof(RGE_Command_Create_Group)));
    int count = p4;

    packet->command = 8;
    packet->player_id = static_cast<unsigned char>(p1);
    packet->groupCommander = p2;

    if (count > 0) {
        for (int i = 0; i < count; ++i)
            packet->unitsToGroup[i] = p3[i];
    }

    packet->numberUnitsToGroup = static_cast<unsigned char>(count);
    packet->groupRange = p5;

    int first_id = p3[0];
    RGE_Static_Object* obj = this->world->object(first_id);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }
    L->Log("      >SEND CMD CRT GROUP (CNT=%d,PLR=%d,UNIT=%s)",
           count, p1, name);
    this->submit(packet, sizeof(RGE_Command_Create_Group));
}

void RGE_Command::command_add_to_group(int plr, int rec, int target, float angle) {
    RGE_Command_Add_To_Group* packet =
        static_cast<RGE_Command_Add_To_Group*>(
            calloc(1, sizeof(RGE_Command_Add_To_Group)));

    packet->groupCommander = rec;
    packet->command = 0x0E;
    packet->player_id = static_cast<unsigned char>(plr);
    packet->newUnit = target;
    packet->group_range = angle;

    RGE_Static_Object* obj = this->world->object(target);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD ADD GROUP (PLR=%d,UNIT=%s)", plr, name);

    this->submit(packet, sizeof(RGE_Command_Add_To_Group));
}

void RGE_Command::command_remove_from_group(int param_1, int param_2, int param_3) {
    RGE_Command_Remove_From_Group* cmd =
        static_cast<RGE_Command_Remove_From_Group*>(
            calloc(1, sizeof(RGE_Command_Remove_From_Group)));
    cmd->command = 0x0F;
    cmd->player_id = static_cast<unsigned char>(param_1);
    cmd->groupCommander = param_2;
    cmd->unit = param_3;

    RGE_Static_Object* obj = this->world->object(param_3);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD REM GROUP (PLR=%d,UNIT=%s)", param_1, name);
    this->submit(cmd, sizeof(RGE_Command_Remove_From_Group));
}

void RGE_Command::command_destroy_group(int player_id, int group_id) {
    RGE_Command_Destroy_Group* packet =
        static_cast<RGE_Command_Destroy_Group*>(
            calloc(1, sizeof(RGE_Command_Destroy_Group)));
    packet->command = 9;
    packet->player_id = static_cast<unsigned char>(player_id);
    packet->groupCommander = group_id;
    L->Log("      >SEND CMD DES GROUP (PLR=%d)", player_id);
    this->submit(packet, sizeof(RGE_Command_Destroy_Group));
}

void RGE_Command::command_ai_order(int player, int issuer, int recipient,
                                   int order_type, int target, int target_owner,
                                   float target_x, float target_y, float target_z,
                                   float range, unsigned char immediate,
                                   unsigned char in_front,
                                   unsigned char order_priority)
{
    RGE_Command_AI_Order* cmd =
        static_cast<RGE_Command_AI_Order*>(
            calloc(1, sizeof(RGE_Command_AI_Order)));

    cmd->player_id = static_cast<unsigned char>(player);
    cmd->issuer = static_cast<unsigned char>(issuer);
    cmd->orderType = static_cast<short>(order_type);
    cmd->orderPriority = order_priority;
    cmd->targetOwner = static_cast<unsigned char>(target_owner);
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
    this->submit(cmd, sizeof(RGE_Command_AI_Order));
}

void RGE_Command::command_group_ai_order(
    int player, int issuer, RGE_Static_Object** list, short list_num,
    int order_type, int target, int target_owner, float target_x,
    float target_y, float target_z, float range, unsigned char immediate,
    unsigned char in_front, unsigned char order_priority)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Group_AI_Order) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Group_AI_Order* packet =
            static_cast<RGE_Command_Group_AI_Order*>(calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* recipients = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    recipients[i].id = list[i]->id;
                } else {
                    recipients[i].id = -1;
                }
            }

            packet->command = 0x11;
            packet->player_id = static_cast<unsigned char>(player);
            packet->issuer = static_cast<unsigned char>(issuer);
            packet->recipient_count = static_cast<unsigned char>(list_num);
            packet->orderType = static_cast<short>(order_type);
            packet->orderPriority = order_priority;
            packet->target = target;
            packet->targetOwner = static_cast<unsigned char>(target_owner);
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
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_resign(int player, int drop, int reason) {
    RGE_Command_Resign* packet = static_cast<RGE_Command_Resign*>(
        calloc(1, sizeof(RGE_Command_Resign)));
    packet->comm_player_id = static_cast<unsigned char>(drop);
    packet->command = 0x0B;
    packet->player_id = static_cast<unsigned char>(player);
    packet->dropped = static_cast<unsigned char>(reason);
    L->Log("      >SEND CMD RESIGN (PLR=%d,DROP=%d)", player, reason);
    this->submit(packet, sizeof(RGE_Command_Resign));
}

void RGE_Command::command_add_waypoint(int player, int obj_id, XYZBYTEPoint* pts, int count)
{
    RGE_Command_Add_Waypoint* packet =
        static_cast<RGE_Command_Add_Waypoint*>(
            calloc(1, sizeof(RGE_Command_Add_Waypoint)));
    packet->command = 0x0C;
    packet->player_id = static_cast<unsigned char>(player);
    packet->recipient = obj_id;
    packet->numberWaypoints = static_cast<unsigned char>(count);

    for (int i = 0; i < count; i++) {
        packet->waypoint[i] = pts[i];
    }

    RGE_Static_Object* obj = this->world->object(obj_id);
    char* name;
    if (obj != 0)
        name = obj->master_obj->name;
    else
        name = "X";

    L->Log("      >SEND CMD ADD WAY (PLR=%d,REC=%s)", player, name);

    submit(packet, sizeof(RGE_Command_Add_Waypoint));
}



void RGE_Command::command_add_waypoint(int player, int rec, unsigned char p3, unsigned char p4, unsigned char p5) {
    RGE_Command_Add_Waypoint* packet =
        static_cast<RGE_Command_Add_Waypoint*>(
            calloc(1, sizeof(RGE_Command_Add_Waypoint)));
    packet->command = 0x0C;
    packet->player_id = static_cast<unsigned char>(player);
    packet->recipient = rec;
    packet->numberWaypoints = 1;
    packet->waypoint[0].x = p3;
    packet->waypoint[0].y = p4;
    packet->waypoint[0].z = p5;
    RGE_Static_Object* obj = this->world->object(rec);
    char* name;
    if (obj != 0) name = obj->master_obj->name; else name = "X";
    L->Log("      >SEND CMD ADD WAY2 (PLR=%d,REC=%s)", player, name);
    this->submit(packet, sizeof(RGE_Command_Add_Waypoint));
}

void RGE_Command::command_group_waypoint(RGE_Static_Object** list,
                                         short list_num,
                                         unsigned char x,
                                         unsigned char y)
{
    if (list != 0 && list_num >= 1) {
        int size = sizeof(RGE_Command_Group_Waypoint) +
                   list_num * sizeof(RGE_Obj_Info);
        RGE_Command_Group_Waypoint* packet =
            static_cast<RGE_Command_Group_Waypoint*>(calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(
                reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < list_num; ++i) {
                if (list[i] != 0) {
                    ids[i].id = list[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            packet->command = 0x10;
            packet->unit_num = static_cast<unsigned char>(list_num);
            packet->x = x;
            packet->y = y;

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
            this->submit(packet, size);
        }
    }
}
