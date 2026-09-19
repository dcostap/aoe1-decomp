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



RGE_Command::RGE_Command(RGE_Game_World* gworld, TCommunications_Handler* com_handler)
    : world(gworld), com_hand(com_handler) {
    last_order = 0;
    last_order_size = 0;
}

RGE_Command::~RGE_Command() {
    this->world = 0;
    this->com_hand = 0;
    void* p = this->last_order;
    if (p != 0) {
        free(p);
    }
}

void RGE_Command::reset_communications(TCommunications_Handler* com_hand_in) {
    this->com_hand = com_hand_in;
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

void RGE_Command::do_command(void* order) {
    switch (static_cast<RGE_Command_Header*>(order)->command) {
    case 0:
        do_command_order(static_cast<RGE_Command_Order*>(order));
        return;
    case 1:
        do_command_stop(static_cast<RGE_Command_Stop*>(order));
        return;
    case 2:
        do_command_work(static_cast<RGE_Command_Order*>(order));
        return;
    case 3:
        do_command_move(static_cast<RGE_Command_Order*>(order));
        return;
    case 4:
        do_command_create(static_cast<RGE_Command_Create*>(order));
        return;
    case 5:
        do_command_add_attribute(static_cast<RGE_Command_Add_Attribute*>(order));
        return;
    case 6:
        do_command_formation(static_cast<RGE_Command_Formation*>(order));
        return;
    case 7:
        this->do_command_give_attribute(static_cast<RGE_Command_Give_Attribute*>(order));
        return;
    case 8:
        do_command_create_group(static_cast<RGE_Command_Create_Group*>(order));
        return;
    case 9:
        do_command_destroy_group(static_cast<RGE_Command_Destroy_Group*>(order));
        return;
    case 10:
        do_command_ai_order(static_cast<RGE_Command_AI_Order*>(order));
        return;
    case 17:
        do_command_group_ai_order(static_cast<RGE_Command_Group_AI_Order*>(order));
        return;
    case 11:
        do_command_resign(static_cast<RGE_Command_Resign*>(order));
        return;
    case 12:
        do_command_add_waypoint(static_cast<RGE_Command_Add_Waypoint*>(order));
        return;
    case 16:
        do_command_group_waypoint(static_cast<RGE_Command_Group_Waypoint*>(order));
        return;
    case 14:
        do_command_add_to_group(static_cast<RGE_Command_Add_To_Group*>(order));
        return;
    case 15:
        do_command_remove_from_group(static_cast<RGE_Command_Remove_From_Group*>(order));
        return;
    }
}

void RGE_Command::do_command_order(RGE_Command_Order* order) {
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    RGE_Static_Object* target = this->get_obj(order->target);

    if (unit_num > 1) {
        float minX = 10000.0f;
        float maxX = 0.0f;
        float minY = 10000.0f;
        float maxY = 0.0f;
        float totalX = 0.0f;
        float totalY = 0.0f;

        if (unit_num > 0) {
            int i = unit_num;
            RGE_Obj_Info* unit = units;
            do {
                RGE_Static_Object* object = this->get_obj(*unit);
                if (object != 0) {
                    if (object->world_x < minX) {
                        minX = object->world_x;
                    } else if (object->world_x > maxX) {
                        maxX = object->world_x;
                    }

                    if (object->world_y < minY) {
                        minY = object->world_y;
                    } else if (object->world_y > maxY) {
                        maxY = object->world_y;
                    }

                    totalX += object->world_x;
                    totalY += object->world_y;
                }
                ++unit;
                --i;
            } while (i != 0);
        }

        if (maxX - minX <= DAT_0056f4d8 && maxY - minY <= DAT_0056f4d8) {
            totalX /= (float)unit_num;
            totalY /= (float)unit_num;

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
                            if (other_index != index) {
                                object->addToPathingGroup(other_unit->id);
                            }
                            ++other_index;
                            ++other_unit;
                        } while (other_index < unit_num);

                        float adjustedXLocation =
                            (object->world_x - totalX) + order->location_x;
                        float adjustedYLocation =
                            (object->world_y - totalY) + order->location_y;

                        if (adjustedXLocation < DAT_0056f4e0) {
                            adjustedXLocation = 1.0f;
                        } else {
                            float width =
                                (float)object->owner->world->map->map_width;
                            if (adjustedXLocation >= width) {
                                adjustedXLocation = width - DAT_0056f4e8;
                            }
                        }

                        if (adjustedYLocation < DAT_0056f4e0) {
                            adjustedYLocation = 1.0f;
                        } else {
                            float height =
                                (float)object->owner->world->map->map_height;
                            if (adjustedYLocation >= height) {
                                adjustedYLocation = height - DAT_0056f4e8;
                            }
                        }

                        if (target != 0 && (target->master_obj->radius_x > DAT_0056f4e0 ||
                             target->master_obj->radius_y > DAT_0056f4e0)) {
                            object->do_command(target, adjustedXLocation, adjustedYLocation, 0.0f);
                        } else {
                            object->do_command(0, adjustedXLocation, adjustedYLocation, 0.0f);
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
                    if (other_index != index) {
                        object->addToPathingGroup(other_unit->id);
                    }
                    ++other_index;
                    ++other_unit;
                } while (other_index < unit_num);

                object->do_command(target, order->location_x, order->location_y, 0.0f);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}

void RGE_Command::do_command_stop(RGE_Command_Stop* order) {
    int count = order->unit_num;
    RGE_Obj_Info* id = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
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

void RGE_Command::do_command_pause(RGE_Command_Pause* order) {
    int count = order->unit_num;
    RGE_Obj_Info* id = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
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

void RGE_Command::do_command_work(RGE_Command_Order* order) {
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
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
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    RGE_Static_Object* target = this->get_obj(order->target);
    if (unit_num > 1) {
        float minX = 10000.0f;
        float maxX = 0.0f;
        float minY = 10000.0f;
        float maxY = 0.0f;
        float totalX = 0.0f;
        float totalY = 0.0f;
        if (unit_num > 0) {
            int i = unit_num;
            RGE_Obj_Info* unit = units;
            do {
                RGE_Static_Object* object = this->get_obj(*unit);
                if (object) {
                    if (object->world_x < minX)
                        minX = object->world_x;
                    else if (object->world_x > maxX)
                        maxX = object->world_x;

                    if (object->world_y < minY)
                        minY = object->world_y;
                    else if (object->world_y > maxY)
                        maxY = object->world_y;

                    totalX += object->world_x;
                    totalY += object->world_y;
                }
                ++unit;
            } while (--i);
        }
        if (maxX - minX > DAT_0056f4d8 || maxY - minY > DAT_0056f4d8)
            goto simple;

        totalX /= (float)unit_num;
        totalY /= (float)unit_num;
        int index = 0;
        if (unit_num > 0) {
            RGE_Obj_Info* unit = units;
            do {
                RGE_Static_Object* object = this->get_obj(*unit);
                if (object) {
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

                    float adjustedXLocation =
                        (object->world_x - totalX) + order->location_x;
                    float adjustedYLocation =
                        (object->world_y - totalY) + order->location_y;
                    if (adjustedXLocation < DAT_0056f4e0)
                        adjustedXLocation = 1.0f;
                    else {
                        float width =
                            (float)object->owner->world->map->map_width;
                        if (adjustedXLocation >= width)
                            adjustedXLocation = width - DAT_0056f4e8;
                    }

                    if (adjustedYLocation < DAT_0056f4e0)
                        adjustedYLocation = 1.0f;
                    else {
                        float height =
                            (float)object->owner->world->map->map_height;
                        if (adjustedYLocation >= height)
                            adjustedYLocation = height - DAT_0056f4e8;
                    }

                    if (target != 0 && (target->master_obj->radius_x > DAT_0056f4e0 ||
                         target->master_obj->radius_y > DAT_0056f4e0))
                        object->move_to(target, adjustedXLocation, adjustedYLocation, 0);
                    else
                        object->move_to(0, adjustedXLocation, adjustedYLocation, 0);

                    UnitAIModule* ai = object->unitAI();
                    if (ai) {
                        object->unitAI()->setCurrentOrder(0x2c6);
                        object->unitAI()->setCurrentAction(0x262);
                        if (target != 0 && (target->master_obj->radius_x > DAT_0056f4e0 ||
                             target->master_obj->radius_y > DAT_0056f4e0))
                            object->unitAI()->setCurrentTarget(target->id, target->master_obj->object_group,
                                                               adjustedXLocation, adjustedYLocation, 0.0f);
                        else
                            object->unitAI()->setCurrentTarget(-1, -1, adjustedXLocation, adjustedYLocation, 0.0f);
                    }
                }
                ++index;
                ++unit;
            } while (index < unit_num);
        }
        return;
    }
simple:
    int index = 0;
    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* object = this->get_obj(*unit);
            if (object) {
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

                object->move_to(target, order->location_x, order->location_y, 0);
                UnitAIModule* ai = object->unitAI();
                if (ai) {
                    object->unitAI()->setCurrentOrder(0x2c6);
                    object->unitAI()->setCurrentAction(0x262);
                    if (target != 0 && (target->master_obj->radius_x > DAT_0056f4e0 ||
                         target->master_obj->radius_y > DAT_0056f4e0))
                        object->unitAI()->setCurrentTarget(target->id, target->master_obj->object_group,
                                                           order->location_x, order->location_y, 0.0f);
                    else
                        object->unitAI()->setCurrentTarget(-1, -1, order->location_x, order->location_y, 0.0f);
                }
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}

void RGE_Command::do_command_create(RGE_Command_Create* order) {
    RGE_Player* player = this->world->players[order->player_id];
    player->master_objects[order->obj_catagory]->make_new_obj(
        player, order->location_x, order->location_y, order->location_z);
}

void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* order) {
    int player_id = order->player_id;
    world->players[player_id]->add_attribute_num(order->attr_id, order->amount, 0);
}

void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* order) {
    RGE_Player* player = this->world->players[order->player_id];

    if (player->attributes[order->attr_id] >= order->amount) {
        player->add_attribute_num(order->attr_id, -order->amount, 0);
        this->world->players[order->to_player_id]->add_attribute_num(order->attr_id, order->amount, 0);

        rge_base_game->notification(7, order->player_id, order->to_player_id, order->attr_id, (long)order->amount);

        this->world->players[order->to_player_id]->notify(order->player_id, order->to_player_id, 0x20A, order->attr_id,
                                                          (long)order->amount, 0);
    }
}

#pragma intrinsic(sqrt)


void RGE_Command::do_command_formation(RGE_Command_Formation* fCommand) {
    int unitNum = fCommand->unitNum;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(fCommand) + sizeof(*fCommand));

    if (unitNum > 1) {
        RGE_Static_Object* referenceUnit = 0;
        float distance;
        int i = 0;
        if (i < unitNum) {
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    float object_distance =
                        (float)sqrt(object->world_x * object->world_x + object->world_y * object->world_y);
                    if (i == 0 || object_distance < distance) {
                        referenceUnit = object;
                        distance = object_distance;
                    }
                }
                ++i;
                ++units;
            } while (i < unitNum);
        }

        float adjustedYLocation = 1.0f;
        float tempX = 1.0f;
        int alternate = 0;
        switch (fCommand->formationID) {
        case 0:
            adjustedYLocation = 1.0f;
            tempX = 1.0f;
            break;
        case 2:
        case 3:
            adjustedYLocation = 2.0f;
            tempX = 2.0f;
            break;
        case 1:
        case 4:
        case 5:
            adjustedYLocation = 1.5f;
            tempX = 1.5f;
            break;
        }

        int index = 0;
        if (index < unitNum) {
            units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(fCommand) + sizeof(*fCommand));
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    object->removeAllFromPathingGroup();
                    object->setWaitingToMove(1);

                    int other_index = 0;
                    RGE_Obj_Info* other_unit =
                        reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(fCommand) + sizeof(*fCommand));
                    do {
                        if (other_index != index)
                            object->addToPathingGroup(other_unit->id);
                        ++other_index;
                        ++other_unit;
                    } while (other_index < unitNum);

                    if (object != referenceUnit) {
                        float tempCount = referenceUnit->world_x;
                        float adjustedXLocation = referenceUnit->world_y;

                        switch (fCommand->formationID) {
                        case 0:
                            tempCount += adjustedYLocation;
                            adjustedYLocation = adjustedYLocation - -1.0f;
                            adjustedXLocation = adjustedXLocation + tempX;
                            tempX = tempX - -1.0f;
                            break;
                        case 1:
                            tempCount = tempCount + adjustedYLocation;
                            adjustedYLocation = adjustedYLocation - -1.5f;
                            adjustedXLocation = adjustedXLocation - tempX;
                            tempX = tempX - -1.5f;
                            break;
                        case 2:
                            tempCount += adjustedYLocation;
                            adjustedYLocation = adjustedYLocation - -2.0f;
                            break;
                        case 3:
                            adjustedXLocation += tempX;
                            tempX = tempX - -2.0f;
                            break;
                        case 5:
                            tempCount -= adjustedYLocation;
                            if (alternate == 0) {
                                adjustedXLocation -= tempX;
                                alternate = 1;
                            } else {
                                adjustedXLocation += tempX;
                                tempX = tempX - -1.5f;
                                adjustedYLocation = adjustedYLocation - -1.5f;
                                alternate = 0;
                            }
                            break;
                        case 4:
                            tempCount += adjustedYLocation;
                            if (alternate == 0) {
                                adjustedXLocation -= tempX;
                                alternate = 1;
                            } else {
                                adjustedXLocation += tempX;
                                tempX = tempX - -1.5f;
                                adjustedYLocation = adjustedYLocation - -1.5f;
                                alternate = 0;
                            }
                            break;
                        }

                        object->move_to(0, tempCount, adjustedXLocation, 1.0f);
                    }
                }
                ++index;
                ++units;
            } while (index < unitNum);
        }
    }
}

void RGE_Command::do_command_ai_order(RGE_Command_AI_Order* aiOrder) {
    RGE_Static_Object* obj = this->world->object(aiOrder->recipient);
    if (obj != 0) {
        obj->removeAllFromPathingGroup();
        RGE_Game_World* world = this->world;
        RGE_Player* player = world->players[aiOrder->player_id];
        player->processAIOrder(aiOrder->issuer, aiOrder->recipient, aiOrder->orderType, aiOrder->target,
                               aiOrder->targetOwner, aiOrder->targetX, aiOrder->targetY, aiOrder->targetZ,
                               aiOrder->range, aiOrder->immediate, aiOrder->inFront, aiOrder->orderPriority);
    }
}

void RGE_Command::do_command_group_ai_order(
    RGE_Command_Group_AI_Order* aiOrder) {
    int recipient_count = aiOrder->recipient_count;
    RGE_Obj_Info* recipients = reinterpret_cast<RGE_Obj_Info*>(aiOrder + 1);

    if (recipient_count > 0) {
        do {
            RGE_Static_Object* object = this->get_obj(*recipients);
            if (object != 0) {
                float targetX = aiOrder->targetX;
                if (targetX == -1.0f)
                    targetX = object->world_x;

                float targetY = aiOrder->targetY;
                if (targetY == -1.0f)
                    targetY = object->world_y;

                float targetZ = aiOrder->targetZ;
                if (targetZ == -1.0f)
                    targetZ = object->world_z;

                object->removeAllFromPathingGroup();
                this->world->players[aiOrder->player_id]->processAIOrder(aiOrder->issuer, object->id, aiOrder->orderType,
                                                                         aiOrder->target, aiOrder->targetOwner, targetX, targetY, targetZ, aiOrder->range, aiOrder->immediate,
                                                                         aiOrder->inFront, aiOrder->orderPriority);
            }
            ++recipients;
            --recipient_count;
        } while (recipient_count != 0);
    }
}



void RGE_Command::do_command_resign(RGE_Command_Resign* order) {
    if (rge_base_game->multiplayerGame()) {
        RGE_Base_Game* game = rge_base_game;
        int comm = order->comm_player_id;
        int total = 0; int resigned_count = 0; int i = 1;
        game->resigned[comm] = 1;
        do { if (rge_base_game->playerID(i) == order->player_id) { total++; if (rge_base_game->resigned[i]) resigned_count++; } i++; } while (i < 9);
        if (total != resigned_count) return;
        this->world->players[order->player_id]->do_resign(order->dropped);
        return;
    }
    this->world->players[order->player_id]->do_resign(order->dropped);
}

void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* wOrder) {
    if (this->world->object(wOrder->recipient) != 0) {
        this->world->players[wOrder->player_id]->processAddWaypointCommand(
            wOrder->recipient, wOrder->waypoint, wOrder->numberWaypoints);
    }
}


typedef unsigned char uchar;


void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* order) {
    int c;
    RGE_Obj_Info* ids;
    XYZBYTEPoint p;

    c = order->unit_num;
    ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    if (c > 0) {
        int count = c;
        do {
            RGE_Static_Object* obj = this->get_obj(*ids);
            if (obj != 0) {
                p.x = order->x;
                p.y = order->y;
                p.z = 0;
                obj->owner->processAddWaypointCommand(obj->id, &p, 1);
            }
            ++ids;
            --count;
        } while (count != 0);
    }
}

void RGE_Command::do_command_create_group(RGE_Command_Create_Group* gCommand) {
    RGE_Static_Object* object = this->world->object(gCommand->groupCommander);
    if (object != 0 && object->owner->id == (unsigned short)gCommand->player_id) {
        object->commanderCreateGroup(gCommand->unitsToGroup, (int)gCommand->numberUnitsToGroup, gCommand->groupCommander,
                                     gCommand->groupRange);
    }
}


void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group* gCommand) {
    RGE_Static_Object* object = this->world->object(gCommand->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)gCommand->player_id)) {
        int newUnit = gCommand->newUnit;
        object->commanderAddToGroup(newUnit, gCommand->group_range);
    }
}


void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* gCommand) {
    RGE_Static_Object* object = this->world->object(gCommand->groupCommander);
    if ((object != 0) && (object->owner->id == (unsigned short)gCommand->player_id)) {
        object->commanderRemoveFromGroup(gCommand->unit);
    }
}

void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* gCommand) {
    RGE_Static_Object* obj = this->world->object(gCommand->groupCommander);

    if (obj != 0) {
        if (obj->owner->id == (unsigned short)gCommand->player_id)
            obj->commanderDestroyGroup();
    }
}



unsigned char RGE_Command::duplicate_check_command_order(RGE_Command_Order* order) {
    unsigned int n = (unsigned char)order->unit_num;
    RGE_Obj_Info* units;
    RGE_Obj_Info* last_units;
    units = reinterpret_cast<RGE_Obj_Info*>(order + 1);
    RGE_Command_Order* last_order =
        reinterpret_cast<RGE_Command_Order*>(this->last_order);
    unsigned int last_n = (unsigned char)last_order->unit_num;
    last_units = reinterpret_cast<RGE_Obj_Info*>(last_order + 1);

    if (n == last_n) {

        if ((short)(int)last_order->location_x == (short)(int)order->location_x) {
            int order_y = (int)order->location_y;
            if ((short)last_order->location_y == (short)order_y) {
                if (last_order->target.id == order->target.id) {
                    for (int i = 0; i < (int)n; i++) {
                        if (units[i].id != last_units[i].id)
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

unsigned char RGE_Command::duplicate_check_command_stop(RGE_Command_Stop* order) {
    int n = order->unit_num;
    RGE_Obj_Info* p = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    RGE_Command_Stop* last =
        reinterpret_cast<RGE_Command_Stop*>(this->last_order);
    RGE_Obj_Info* l = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(last) + sizeof(*last));

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


unsigned char RGE_Command::close_check_for_duplicate_orders(unsigned char* order) {
    unsigned char selector = *order;
    switch (selector) {
    case 0:
    case 2:
    case 3:
        if (this->duplicate_check_command_order(reinterpret_cast<RGE_Command_Order*>(order)) != 0) {
            return 1;
        }
        break;
    case 1:
        if (this->duplicate_check_command_stop(reinterpret_cast<RGE_Command_Stop*>(order)) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}

unsigned char RGE_Command::check_for_duplicate_orders(unsigned char* order,
                                                      long order_size) {
    if (last_order != 0) {
        if (last_order_size == order_size) {
            if (*last_order == *order) {
                unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 1175);
                if ((int)(now - last_order_time) < 0x1F4) {
                    return close_check_for_duplicate_orders(order);
                }
            }
        }
    }
    return 0;
}

void RGE_Command::submit(void* order, long order_size) {
    unsigned char dup = check_for_duplicate_orders(static_cast<unsigned char*>(order), order_size);
    if (dup == 0) {
        com_hand->new_command(order, order_size);
    }
    if (last_order != 0) {
        free(last_order);
    }
    last_order = static_cast<unsigned char*>(order);
    last_order_size = order_size;
    unsigned long t = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Command.cpp", 1196);
    last_order_time = t;
}

void RGE_Command::command_order(RGE_Static_Object** unit, short unit_count,
                                RGE_Static_Object* target, float location_x,
                                float location_y) {
    int size = sizeof(RGE_Command_Order) +
               unit_count * sizeof(RGE_Obj_Info);
    if (unit != 0 && unit_count >= 1) {
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unit_count; ++i) {
                if (unit[i] != 0) {
                    ids[i].id = unit[i]->id;
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
            packet->unit_num = static_cast<unsigned char>(unit_count);
            packet->location_x = location_x;
            packet->location_y = location_y;

            const char* target_name;
            if (target != 0) {
                target_name = target->master_obj->name;
            } else {
                target_name = "X";
            }
            RGE_Static_Object* obj = unit[0];
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

            L->Log("      >SEND CMD ORDER (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", unit_count, owner, name, target_name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_stop(RGE_Static_Object** unit, short unit_count) {
    int size = sizeof(RGE_Command_Stop) +
               unit_count * sizeof(RGE_Obj_Info);
    if (unit != 0 && unit_count >= 1) {
        RGE_Command_Stop* packet = static_cast<RGE_Command_Stop*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unit_count; ++i) {
                if (unit[i] != 0) ids[i].id = unit[i]->id;
                else ids[i].id = -1;
            }
            packet->command = 1;
            packet->unit_num = static_cast<unsigned char>(unit_count);
            RGE_Static_Object* obj = unit[0];
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
            L->Log("      >SEND CMD STOP (CNT=%d,OWN=%d,UNIT=%s)", unit_count, owner, name);
            this->submit(packet, size);
        }
    }
}




void RGE_Command::command_stop(int playerID, int* unitID, int numUnits) {
    if (unitID != 0 && numUnits >= 1) {
        int size = sizeof(RGE_Command_Stop) +
                   numUnits * sizeof(RGE_Obj_Info);
        RGE_Command_Stop* packet = static_cast<RGE_Command_Stop*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < numUnits; ++i)
                ids[i].id = unitID[i];
            packet->command = 1;
            packet->unit_num = static_cast<unsigned char>(numUnits);
            RGE_Static_Object* obj = this->world->object(unitID[0]);
            const char* name;
            if (obj != 0) name = obj->master_obj->name;
            else name = "X";
            L->Log("      >SEND CMD STOP2 (CNT=%d,OWN=%d,UNIT=%s)", numUnits, playerID, name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_pause(int playerID, int* unitID, int numUnits) {
    if (unitID != 0 && numUnits >= 1) {
        int size = sizeof(RGE_Command_Pause) +
                   numUnits * sizeof(RGE_Obj_Info);
        RGE_Command_Pause* packet = static_cast<RGE_Command_Pause*>(calloc(1, size));
        if (packet != 0) {
            RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
            for (int i = 0; i < numUnits; ++i)
                ids[i].id = unitID[i];
            packet->command = 0x0D;
            packet->unit_num = static_cast<unsigned char>(numUnits);
            L->Log("      >SEND CMD PAUSE");
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_work(RGE_Static_Object** unit, short unit_count,
                               RGE_Static_Object* target, float location_x,
                               float location_y) {
    int size = sizeof(RGE_Command_Order) +
               unit_count * sizeof(RGE_Obj_Info);
    if (unit != 0 && unit_count >= 1) {
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unit_count; ++i) {
                if (unit[i] != 0) {
                    ids[i].id = unit[i]->id;
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
            packet->unit_num = static_cast<unsigned char>(unit_count);
            packet->location_x = location_x;
            packet->location_y = location_y;

            const char* target_name;
            if (target != 0) {
                target_name = target->master_obj->name;
            } else {
                target_name = "X";
            }

            RGE_Static_Object* obj = unit[0];
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

            L->Log("      >SEND CMD WORK (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", unit_count, owner, unit_name, target_name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_work(int playerID, int* unitID, int numUnits,
                               int targetID, int targetPlayerID, float xLoc,
                               float yLoc) {
    if (unitID != 0 && numUnits >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   numUnits * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < numUnits; ++i)
                ids[i].id = unitID[i];
            packet->location_x = xLoc;
            packet->command = 2;
            packet->unit_num = static_cast<unsigned char>(numUnits);
            packet->target.id = targetID;
            packet->location_y = yLoc;
            RGE_Static_Object* unit_obj = this->world->object(unitID[0]);
            RGE_Static_Object* target_obj = this->world->object(targetID);
            const char* target_name;
            if (target_obj != 0) target_name = target_obj->master_obj->name;
            else target_name = "X";
            const char* unit_name;
            if (unit_obj != 0) unit_name = unit_obj->master_obj->name;
            else unit_name = "X";
            L->Log("      >SEND CMD WORK2 (CNT=%d,OWN=%d,UNIT=%s,TAR=%s)", numUnits, playerID, unit_name, target_name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_move(RGE_Static_Object** unit, short unit_count,
                               RGE_Static_Object* target, float location_x,
                               float location_y) {
    if (unit != 0 && unit_count >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   unit_count * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unit_count; ++i) {
                if (unit[i] != 0) {
                    ids[i].id = unit[i]->id;
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
            packet->unit_num = static_cast<unsigned char>(unit_count);
            packet->location_x = location_x;
            packet->location_y = location_y;

            RGE_Static_Object* obj = unit[0];
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

            L->Log("      >SEND CMD MOVE (CNT=%d,OWN=%d,UNIT=%s)", unit_count, owner, name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_move(int playerID, int* unitID, int numUnits,
                               int targetID, int targetPlayerID, float xLoc,
                               float yLoc) {
    if (unitID != 0 && numUnits >= 1) {
        int size = sizeof(RGE_Command_Order) +
                   numUnits * sizeof(RGE_Obj_Info);
        RGE_Command_Order* packet = static_cast<RGE_Command_Order*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < numUnits; ++i) ids[i].id = unitID[i];
            packet->command = 3;
            packet->unit_num = static_cast<unsigned char>(numUnits);
            packet->target.id = targetID;
            packet->location_x = xLoc;
            packet->location_y = yLoc;
            RGE_Static_Object* obj = this->world->object(unitID[0]);
            const char* name; if (obj != 0) name = obj->master_obj->name; else name = "X";
            L->Log("      >SEND CMD MOVE2 (CNT=%d,OWN=%d,UNIT=%s)", numUnits, playerID, name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_create(short obj_catagory, short player_id,
                                  float location_x, float location_y,
                                  float location_z) {
    RGE_Command_Create* packet = static_cast<RGE_Command_Create*>(calloc(1, sizeof(RGE_Command_Create)));
    packet->command = 4;
    packet->obj_catagory = obj_catagory;
    packet->player_id = static_cast<unsigned char>(player_id);
    packet->location_x = location_x;
    packet->location_y = location_y;
    packet->location_z = location_z;
    L->Log("      >SEND CMD CREATE (CAT=%d,PLR=%d)", (int)obj_catagory, (int)player_id);
    this->submit(packet, sizeof(RGE_Command_Create));
}

void RGE_Command::command_add_attribute(int player_id, int attr_id,
                                        float attr_amount) {
    RGE_Command_Add_Attribute* cmd =
        static_cast<RGE_Command_Add_Attribute*>(calloc(1, sizeof(RGE_Command_Add_Attribute)));
    cmd->command = 5;
    cmd->player_id = static_cast<unsigned char>(player_id);
    cmd->attr_id = static_cast<unsigned char>(attr_id);
    cmd->amount = attr_amount;
    L->Log("      >SEND CMD ADD ATTR (PLR=%d,ATT=%d)", player_id, attr_id);
    this->submit(cmd, sizeof(RGE_Command_Add_Attribute));
}

void RGE_Command::command_give_attribute(int player_id, int to_player_id,
                                          int attr_id, float attr_amount) {
    RGE_Command_Give_Attribute* cmd =
        static_cast<RGE_Command_Give_Attribute*>(calloc(1, sizeof(RGE_Command_Give_Attribute)));
    cmd->command = 7;
    cmd->player_id = static_cast<unsigned char>(player_id);
    cmd->to_player_id = static_cast<unsigned char>(to_player_id);
    cmd->attr_id = static_cast<unsigned char>(attr_id);
    cmd->amount = attr_amount;
    L->Log("      >SEND CMD GIV ATTR (FRM=%d,TO=%d,ATT=%d)", player_id, to_player_id, attr_id);
    submit(cmd, sizeof(RGE_Command_Give_Attribute));
}

void RGE_Command::command_formation(RGE_Static_Object** unit, int unitCount,
                                    int formationID) {
    int size = sizeof(RGE_Command_Formation) +
               unitCount * sizeof(RGE_Obj_Info);
    if (unit != 0 && unitCount >= 1) {
        RGE_Command_Formation* packet = static_cast<RGE_Command_Formation*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unitCount; ++i) {
                if (unit[i] != 0) {
                    ids[i].id = unit[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            packet->command = 6;
            packet->unitNum = unitCount & 0xFF;
            packet->formationID = formationID;

            RGE_Static_Object* obj = unit[0];
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

            L->Log("      >SEND CMD FORMATION (CNT=%d,OWN=%d,UNIT=%s)", unitCount, owner, name);
            this->submit(packet, size);
        }
    }
}






void RGE_Command::command_create_group(int playerID, int groupCommander,
                                       int* units, int unitCount, float range) {
    RGE_Command_Create_Group* packet =
        static_cast<RGE_Command_Create_Group*>(calloc(1, sizeof(RGE_Command_Create_Group)));
    int count = unitCount;

    packet->command = 8;
    packet->player_id = static_cast<unsigned char>(playerID);
    packet->groupCommander = groupCommander;

    if (count > 0) {
        for (int i = 0; i < count; ++i)
            packet->unitsToGroup[i] = units[i];
    }

    packet->numberUnitsToGroup = static_cast<unsigned char>(count);
    packet->groupRange = range;

    int first_id = units[0];
    RGE_Static_Object* obj = this->world->object(first_id);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }
    L->Log("      >SEND CMD CRT GROUP (CNT=%d,PLR=%d,UNIT=%s)", count, playerID, name);
    this->submit(packet, sizeof(RGE_Command_Create_Group));
}

void RGE_Command::command_add_to_group(int playerID, int groupCommander,
                                       int newUnit, float range) {
    RGE_Command_Add_To_Group* packet =
        static_cast<RGE_Command_Add_To_Group*>(calloc(1, sizeof(RGE_Command_Add_To_Group)));

    packet->groupCommander = groupCommander;
    packet->command = 0x0E;
    packet->player_id = static_cast<unsigned char>(playerID);
    packet->newUnit = newUnit;
    packet->group_range = range;

    RGE_Static_Object* obj = this->world->object(newUnit);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD ADD GROUP (PLR=%d,UNIT=%s)", playerID, name);

    this->submit(packet, sizeof(RGE_Command_Add_To_Group));
}

void RGE_Command::command_remove_from_group(int playerID, int commander,
                                            int unit) {
    RGE_Command_Remove_From_Group* cmd =
        static_cast<RGE_Command_Remove_From_Group*>(calloc(1, sizeof(RGE_Command_Remove_From_Group)));
    cmd->command = 0x0F;
    cmd->player_id = static_cast<unsigned char>(playerID);
    cmd->groupCommander = commander;
    cmd->unit = unit;

    RGE_Static_Object* obj = this->world->object(unit);
    const char* name;
    if (obj != 0) {
        name = obj->master_obj->name;
    } else {
        name = "X";
    }

    L->Log("      >SEND CMD REM GROUP (PLR=%d,UNIT=%s)", playerID, name);
    this->submit(cmd, sizeof(RGE_Command_Remove_From_Group));
}

void RGE_Command::command_destroy_group(int playerID, int groupCommander) {
    RGE_Command_Destroy_Group* packet =
        static_cast<RGE_Command_Destroy_Group*>(calloc(1, sizeof(RGE_Command_Destroy_Group)));
    packet->command = 9;
    packet->player_id = static_cast<unsigned char>(playerID);
    packet->groupCommander = groupCommander;
    L->Log("      >SEND CMD DES GROUP (PLR=%d)", playerID);
    this->submit(packet, sizeof(RGE_Command_Destroy_Group));
}

void RGE_Command::command_ai_order(int playerID, int issuer, int recipient,
                                   int orderType, int target, int targetOwner,
                                   float targetX, float targetY, float targetZ,
                                   float range, unsigned char immediate,
                                   unsigned char inFront,
                                   unsigned char priority) {
    RGE_Command_AI_Order* cmd =
        static_cast<RGE_Command_AI_Order*>(calloc(1, sizeof(RGE_Command_AI_Order)));

    cmd->player_id = static_cast<unsigned char>(playerID);
    cmd->issuer = static_cast<unsigned char>(issuer);
    cmd->orderType = static_cast<short>(orderType);
    cmd->orderPriority = priority;
    cmd->targetOwner = static_cast<unsigned char>(targetOwner);
    cmd->targetX = targetX;
    cmd->targetY = targetY;
    cmd->targetZ = targetZ;
    cmd->command = 10;
    cmd->recipient = recipient;
    cmd->target = target;
    cmd->range = range;
    cmd->immediate = immediate;
    cmd->inFront = inFront;

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

    L->Log("      >SEND CMD AI ORD (PLR=%d, TYP=%d, ISS=%d, REC=%d-%s, TAR=%d-%s, TXY=%d,%d)", playerID, orderType, issuer, recipient,
           recipient_name, target, target_name, (long)targetX, (long)targetY);
    this->submit(cmd, sizeof(RGE_Command_AI_Order));
}

void RGE_Command::command_group_ai_order(
    int playerID, int issuer, RGE_Static_Object** recipient, short recipient_count,
    int orderType, int target, int targetOwner, float targetX,
    float targetY, float targetZ, float range, unsigned char immediate,
    unsigned char inFront, unsigned char priority) {
    if (recipient != 0 && recipient_count >= 1) {
        int size = sizeof(RGE_Command_Group_AI_Order) +
                   recipient_count * sizeof(RGE_Obj_Info);
        RGE_Command_Group_AI_Order* packet =
            static_cast<RGE_Command_Group_AI_Order*>(calloc(1, size));
        RGE_Obj_Info* recipients = reinterpret_cast<RGE_Obj_Info*>(
            reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < recipient_count; ++i) {
                if (recipient[i] != 0) {
                    recipients[i].id = recipient[i]->id;
                } else {
                    recipients[i].id = -1;
                }
            }

            packet->command = 0x11;
            packet->player_id = static_cast<unsigned char>(playerID);
            packet->issuer = static_cast<unsigned char>(issuer);
            packet->recipient_count = static_cast<unsigned char>(recipient_count);
            packet->orderType = static_cast<short>(orderType);
            packet->orderPriority = priority;
            packet->target = target;
            packet->targetOwner = static_cast<unsigned char>(targetOwner);
            packet->targetX = targetX;
            packet->targetY = targetY;
            packet->targetZ = targetZ;
            packet->range = range;
            packet->immediate = immediate;
            packet->inFront = inFront;

            RGE_Static_Object* target_obj = this->world->object(target);
            const char* target_name;
            if (target_obj != 0) {
                target_name = target_obj->master_obj->name;
            } else {
                target_name = "X";
            }

            RGE_Static_Object* obj = recipient[0];
            const char* unit_name;
            if (obj != 0) {
                unit_name = obj->master_obj->name;
            } else {
                unit_name = "X";
            }

            L->Log("      >SEND CMD GRP AI ORD (PLR=%d, TYP=%d, ISS=%d, CNT=%d, REC=%s, TAR=%s)", playerID, orderType,
                   issuer, recipient_count, unit_name, target_name);
            this->submit(packet, size);
        }
    }
}

void RGE_Command::command_resign(int player_id, int comm_player_id,
                                 int dropped) {
    RGE_Command_Resign* packet = static_cast<RGE_Command_Resign*>(calloc(1, sizeof(RGE_Command_Resign)));
    packet->comm_player_id = static_cast<unsigned char>(comm_player_id);
    packet->command = 0x0B;
    packet->player_id = static_cast<unsigned char>(player_id);
    packet->dropped = static_cast<unsigned char>(dropped);
    L->Log("      >SEND CMD RESIGN (PLR=%d,DROP=%d)", player_id, dropped);
    this->submit(packet, sizeof(RGE_Command_Resign));
}

void RGE_Command::command_add_waypoint(int playerID, int recipient,
                                       XYZBYTEPoint* waypoint,
                                       int numWaypoints) {
    RGE_Command_Add_Waypoint* packet =
        static_cast<RGE_Command_Add_Waypoint*>(calloc(1, sizeof(RGE_Command_Add_Waypoint)));
    packet->command = 0x0C;
    packet->player_id = static_cast<unsigned char>(playerID);
    packet->recipient = recipient;
    packet->numberWaypoints = static_cast<unsigned char>(numWaypoints);

    for (int i = 0; i < numWaypoints; i++) {
        packet->waypoint[i].x = waypoint[i].x;
        packet->waypoint[i].y = waypoint[i].y;
        packet->waypoint[i].z = waypoint[i].z;
    }

    RGE_Static_Object* obj = this->world->object(recipient);
    char* name;
    if (obj != 0)
        name = obj->master_obj->name;
    else
        name = "X";

    L->Log("      >SEND CMD ADD WAY (PLR=%d,REC=%s)", playerID, name);

    submit(packet, sizeof(RGE_Command_Add_Waypoint));
}



void RGE_Command::command_add_waypoint(int playerID, int recipient,
                                       unsigned char x, unsigned char y,
                                       unsigned char z) {
    RGE_Command_Add_Waypoint* packet =
        static_cast<RGE_Command_Add_Waypoint*>(calloc(1, sizeof(RGE_Command_Add_Waypoint)));
    packet->command = 0x0C;
    packet->player_id = static_cast<unsigned char>(playerID);
    packet->recipient = recipient;
    packet->numberWaypoints = 1;
    packet->waypoint[0].x = x;
    packet->waypoint[0].y = y;
    packet->waypoint[0].z = z;
    RGE_Static_Object* obj = this->world->object(recipient);
    char* name;
    if (obj != 0) name = obj->master_obj->name; else name = "X";
    L->Log("      >SEND CMD ADD WAY2 (PLR=%d,REC=%s)", playerID, name);
    this->submit(packet, sizeof(RGE_Command_Add_Waypoint));
}

void RGE_Command::command_group_waypoint(RGE_Static_Object** unit,
                                         short unit_count,
                                         unsigned char location_x,
                                         unsigned char location_y) {
    int size = sizeof(RGE_Command_Group_Waypoint) +
               unit_count * sizeof(RGE_Obj_Info);
    if (unit != 0 && unit_count >= 1) {
        RGE_Command_Group_Waypoint* packet =
            static_cast<RGE_Command_Group_Waypoint*>(calloc(1, size));
        RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet != 0) {
            for (int i = 0; i < unit_count; ++i) {
                if (unit[i] != 0) {
                    ids[i].id = unit[i]->id;
                } else {
                    ids[i].id = -1;
                }
            }

            packet->command = 0x10;
            packet->unit_num = static_cast<unsigned char>(unit_count);
            packet->x = location_x;
            packet->y = location_y;

            RGE_Static_Object* obj = unit[0];
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
