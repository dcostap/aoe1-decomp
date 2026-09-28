
#include "../include/tcommand.h"
#include "../include/resource_ids.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/basegame.h"
#include "../include/game_globals.h"
#include "../include/com_hand.h"
#include "../include/debuglog.h"
#include "../include/effects.h"
#include "../include/panel_ez.h"
#include "../include/scr_stms.h"
#include "../include/stat_obj.h"
#include "../include/t_b_obj.h"
#include "../include/tact_mob.h"
#include "../include/tact_tek.h"
#include "../include/tm_b_obj.h"
#include "../include/tplayer.h"
#include "../include/tribegam.h"
#include "../include/tworld.h"
#include "../include/unit_ai_module.h"

extern FILE* DDlogf;
extern int do_debug_random;
extern int out_of_sync2;
extern void __cdecl debug_random_write();
extern void __cdecl dump_vismap_log();

TRIBE_Command::TRIBE_Command(
    TRIBE_World* world,
    TCommunications_Handler* com_hand)
    : RGE_Command(world, com_hand) {
}

extern int __cdecl debug_rand(char* file, int line);

void TRIBE_Command::do_command(void* order) {
    debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 63);
    switch (static_cast<TRIBE_Command_Header*>(order)->command) {
    case 0x64:
        do_command_make(static_cast<TRIBE_Command_Make*>(order));
        return;
    case 0x65:
        do_command_research(static_cast<TRIBE_Command_Research*>(order));
        return;
    case 0x66:
        do_command_build(static_cast<TRIBE_Command_Build*>(order));
        return;
    case 0x69:
        do_command_build_wall(static_cast<TRIBE_Command_Build_Wall*>(order));
        return;
    case 0x68:
        do_command_explore(static_cast<TRIBE_Command_Explore*>(order));
        return;
    case 0x67:
        do_command_game(static_cast<TRIBE_Command_Game*>(order));
        return;
    case 0x04:
        do_command_tribe_create(static_cast<RGE_Command_Create*>(order));
        return;
    case 0x6A:
        do_command_cancel_build(static_cast<TRIBE_Command_Cancel_Build*>(order));
        return;
    case 0x6B:
        do_command_attack_ground(static_cast<TRIBE_Command_Attack_Ground*>(order));
        return;
    case 0x6C:
        do_command_give_attribute(static_cast<TRIBE_Command_Give_Attribute*>(order));
        return;
    case 0x6D:
        do_command_trade_attribute(static_cast<TRIBE_Command_Trade_Attribute*>(order));
        return;
    case 0x6E:
        do_command_repair(static_cast<TRIBE_Command_Repair*>(order));
        return;
    case 0x6F:
        do_command_unload(static_cast<TRIBE_Command_Unload*>(order));
        return;
    case 0x77:
        do_command_queue(static_cast<TRIBE_Command_Queue*>(order));
        return;
    default:
        RGE_Command::do_command(order);
        return;
    }
}

void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* order) {
    int player_offset = (unsigned int)order->player_id * 4;
    int category_offset = (int)order->obj_catagory * 4;

    if (this->world->players[order->player_id]->master_objects[order->obj_catagory]->movement_type == 1) {
        order->location_z = 4.0f;
    }

    RGE_Static_Object* obj = this->world->players[order->player_id]->master_objects[order->obj_catagory]->make_new_obj(
        this->world->players[order->player_id], order->location_x, order->location_y, order->location_z);

    if (obj->master_obj->master_type == 0x50) {
        static_cast<TRIBE_Building_Object*>(obj)->build(10000.0f);
    }
}

void TRIBE_Command::do_command_make(TRIBE_Command_Make* order) {
    short progress;
    short work_target;
    short work_type;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = static_cast<TRIBE_Building_Object*>(this->world->object(order->unit_id));
    if (building != 0) {
        building->work_status(progress, work_target, work_type, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj(building, order->obj_id, order->unique_id, 0);
            if (action != 0) {
                building->set_only_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(order->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
        TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
        if (player != 0) {
            player->cancelTrain(0, order->obj_id, order->unit_id, order->unique_id);
        }
    } else {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
        if (player != 0) {
            player->cancelTrain(0, order->obj_id, order->unit_id, order->unique_id);
        }
    }
}

void TRIBE_Command::do_command_research(TRIBE_Command_Research* order) {
    short progress;
    short work_target;
    short work_type;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = static_cast<TRIBE_Building_Object*>(this->world->object(order->unit_id));
    if (building != 0) {
        building->work_status(progress, work_target, work_type, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Tech* action = new TRIBE_Action_Make_Tech(
                static_cast<RGE_Action_Object*>(building), order->tech_id, order->unique_id);
            if (action != 0) {
                building->set_only_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(order->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
        TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
        if (player != 0) {
            player->cancelResearch(order->tech_id, order->unit_id, -1, order->unique_id);
        }
    } else {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
        if (player != 0) {
            player->cancelResearch(order->tech_id, order->unit_id, -1, order->unique_id);
        }
    }
}

void TRIBE_Command::do_command_build(TRIBE_Command_Build* order) {
    RGE_Static_Object* blockingObject;
    int placement;
    uchar placementResult;
    int unitNum = order->unit_num;
    RGE_Static_Object* obj;

    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
    if (player == 0) {
        return;
    }
    if (order->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* info =
        static_cast<TRIBE_Master_Building_Object*>(player->master_objects[order->obj_id]);
    if (info == 0) {
        return;
    }

    placementResult = info->check_placement(player, order->location_x, order->location_y, &placement, 1, 1, 1, 1, 1, 1);
    RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    if (placementResult != 0) {
        if (unitNum > 0) {
            obj = this->get_obj(unit_ids[0]);
            if (obj != 0) {
                player->cancelBuild(placementResult, placement,
                                    order->obj_id, order->location_x, order->location_y, order->unique_id, obj->id);
            }
        }
        return;
    }

    if (!player->pay_obj_cost(order->obj_id, 1.0f, 0)) {
        if (unitNum <= 0) {
            return;
        }
        obj = this->get_obj(unit_ids[0]);
        if (obj == 0) {
            return;
        }
        player->cancelBuild(0, placement, order->obj_id, order->location_x, order->location_y, order->unique_id, obj->id);
        return;
    }

    blockingObject = info->make_new_obj(player, order->location_x, order->location_y, 0, order->unique_id);
    if (unitNum <= 0) {
        return;
    }

    RGE_Obj_Info* idp = unit_ids;
    int n = unitNum;
    do {
        obj = this->get_obj(*idp);
        if (obj != 0) {
            obj->removeAllFromPathingGroup();
            obj->do_command(blockingObject, order->location_x, order->location_y, 0.0f);
        }
        ++idp;
        --n;
    } while (n != 0);
}

void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* order) {
    int unitNum = order->unit_num;
    RGE_Obj_Info* units = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->world->players[order->unit_player_id]);
    if (player == 0) return;
    if (order->obj_id == -1) return;
    TRIBE_Master_Building_Object* info =
        static_cast<TRIBE_Master_Building_Object*>(player->master_objects[order->obj_id]);
    if (info == 0) return;

    RGE_Static_Object* first_wall = 0;
    int dy = abs((int)order->y2 - (int)order->y1);
    int dx = abs((int)order->x2 - (int)order->x1);

    if (dy == dx) {
        this->place_line_of_walls(player, info, order->unique_id, order->x1, order->y1, order->x2, order->y2, &first_wall);
    } else if (dy >= dx) {
        this->place_line_of_walls(player, info, order->unique_id, order->x1, order->y1, order->x1, order->y2, &first_wall);
        uchar x2 = order->x2;
        if (order->x1 < x2) {
            this->place_line_of_walls(player, info, order->unique_id, (int)order->x1 + 1, order->y2,
                                      order->x2, order->y2, &first_wall);
        } else if (order->x1 > x2) {
            this->place_line_of_walls(player, info, order->unique_id, (int)order->x1 - 1, order->y2,
                                      order->x2, order->y2, &first_wall);
        }
    } else {
        this->place_line_of_walls(player, info, order->unique_id, order->x1, order->y1, order->x2, order->y1, &first_wall);
        uchar y2 = order->y2;
        if (order->y1 < y2) {
            this->place_line_of_walls(player, info, order->unique_id, order->x2, (int)order->y1 + 1,
                                      order->x2, order->y2, &first_wall);
        } else if (order->y1 > y2) {
            this->place_line_of_walls(player, info, order->unique_id, order->x2, (int)order->y1 - 1,
                                      order->x2, order->y2, &first_wall);
        }
    }

    if (first_wall != 0 && unitNum > 0) {
        int n = unitNum;
        RGE_Obj_Info* idp = units;
        do {
            RGE_Static_Object* obj = this->get_obj(*idp);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->do_command(first_wall, first_wall->world_x, first_wall->world_y, 0.0f);
            }
            ++idp;
            --n;
        } while (n != 0);
    }
}

void TRIBE_Command::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master_obj,
    int unique_id,
    int x1,
    int y1,
    int x2,
    int y2,
    RGE_Static_Object** first_wall) {
    int y_skip;
    int x_skip;

    if (x1 == x2) {
        y_skip = 0;
    } else {
        y_skip = (((int)(x2 <= x1) - 1) & 2) - 1;
    }

    if (y1 == y2) {
        x_skip = 0;
    } else {
        x_skip = (((int)(y2 <= y1) - 1) & 2) - 1;
    }

    int temp = y1;
    y1 = x1;
    x1 = temp;

    for (;;) {
        float world_x = (float)y1 + 0.5f;
        float world_y = (float)x1 + 0.5f;
        if (master_obj->check_placement(player, world_x, world_y, 0, 1, master_obj->elevation_flag, 0, 1, 1, 1) == 0) {
            if (player->pay_obj_cost(master_obj->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* object = master_obj->make_new_obj(player, world_x, world_y, 0, unique_id);
            if (object != 0 && *first_wall == 0) {
                *first_wall = object;
            }
        }

        if (y1 == x2 && x1 == y2) {
            break;
        }

        y1 += y_skip;
        x1 += x_skip;
    }
}

void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* order) {
    RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(order + 1);
    if (this->world->players[order->unit_player_id] == 0) {
        return;
    }

    int i = 0;
    if (order->numUnits > 0) {
        do {
            RGE_Static_Object* obj = this->get_obj(*ids);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->explore((int)order->targetXPosition, (int)order->targetYPosition, 1);
            }
            ++i;
            ++ids;
        } while (i < (int)order->numUnits);
    }
}

// Original game fields use draw_system +0x48 and quick_build +0x9A8.
void TRIBE_Command::do_command_game(TRIBE_Command_Game* order) {
    char fileName[260];
    switch (order->game_command) {
    case 5:
        this->world->players[order->var1]->set_allied_victory(order->var2);
        break;
    case 0:
        this->world->players[order->var1]->set_relation(order->var2, order->var3);
        rge_base_game->notification(8, order->var1, order->var2, order->var4, 0);
        this->world->update_mutual_allies();
        break;
    case 1:
        this->world->set_game_speed(order->var3);
        break;
    case 8: {
        out_of_sync2 = 1;
        TRIBE_Screen_Status_Message* status = new TRIBE_Screen_Status_Message("Temp Screen", "", 0, -1);
        (void)status;
        panel_system.setCurrentPanel("Temp Screen", 0);
        static_cast<TRIBE_Game*>(rge_base_game)->close_game_screens(1);
        if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
            if (actionFile != 0) { fclose(actionFile); actionFile = 0; }
            if (DVlogf != 0) { fclose(DVlogf); DVlogf = 0; }
            if (DDlogf != 0) { fclose(DDlogf); DDlogf = 0; }
        }
        sprintf(fileName, "syncerr%d.gam", comm->WhoAmI());
        static_cast<TRIBE_Game*>(rge_base_game)->save_game(fileName);
        this->world->players[this->world->curr_player]->loss_if_game_on();
        static_cast<TRIBE_Game*>(rge_base_game)->do_game_over();
        TEasy_Panel* panel = static_cast<TEasy_Panel*>(panel_system.currentPanel());
        if (panel != 0) {
            TDrawSystem* draw_system = rge_base_game->draw_system;
            draw_system->SetPalette(panel->get_palette());
            rge_base_game->set_render_all();
            rge_base_game->draw_window();
            panel->popupOKDialog(STRING_ID_ERROR_SYNC, 0, TEASY_POPUP_WIDTH, 100);
        }
        panel_system.destroyPanel("Temp Screen");
        break;
    }
    case 2:
        this->world->players[order->var1]->add_attribute_num(order->var2, order->var3, 0);
        break;
    case 4: {
        TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
        game->quick_build = order->var1;
        break;
    }
    case 6:
        static_cast<TRIBE_World*>(this->world)->cheat(
            order->var1, static_cast<short>(static_cast<unsigned char>(order->var2)));
        break;
    case 7:
        this->world->effects->do_effect(0x71, this->world->players[order->var1]);
        break;
    default:
        break;
    }
}

void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* order) {
    RGE_Static_Object* object = this->world->object(order->unit_id);
    if (object != 0) {
        static_cast<TRIBE_Combat_Object*>(object)->cancel_object();
    }
}

void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* order) {
    RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(order + 1);
    for (int count = order->unit_num; count > 0; --count) {
        RGE_Static_Object* object = this->get_obj(*ids);
        if (object) {
            object->attack(order->location_x, order->location_y, 0.0f, 1);
        }
        ++ids;
    }
}

void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* order) {
    float cost;
    float tribute_amount;

    cost = 0.0f;
    if (order->attr_amount >= 0.0f) {
        tribute_amount = order->attr_amount;
    } else {
        tribute_amount = 0.0f;
    }

    if (tribute_amount > 0.0) {
        cost = order->attr_cost * tribute_amount;
    }

    {
        float* attr_ptr = &this->world->players[order->player_id]->attributes[order->attr_id];
        if (tribute_amount + cost > *attr_ptr) {
            cost = *attr_ptr;
            cost *= order->attr_cost;
            tribute_amount = *attr_ptr - cost;
        }
    }

    this->world->players[order->to_player_id]->add_attribute_num(order->attr_id, tribute_amount, 0);
    this->world->players[order->player_id]->add_attribute_num(order->attr_id, -(tribute_amount + cost), 0);
    this->world->players[order->player_id]->add_attribute_num(0x35, tribute_amount + cost, 0);
    this->world->players[order->to_player_id]->add_attribute_num(0x35, -tribute_amount, 0);
    rge_base_game->notification(7, order->player_id, order->to_player_id, order->attr_id, (long)tribute_amount);
    this->world->players[order->to_player_id]->notify(order->player_id, order->to_player_id, 0x20A, order->attr_id,
                                                      (long)order->attr_amount, 0);
}

void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* order) {
    RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(order + 1);
    for (int count = order->unit_num; count > 0; --count) {
        RGE_Static_Object* object = this->get_obj(*ids);
        if (object != 0) {
            object->attribute_type_held = (short)order->attribute;
        }
        ++ids;
    }
}

void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* order) {
    RGE_Obj_Info* ids = (RGE_Obj_Info*)(order + 1);
    int unit_count = order->unit_num;
    RGE_Static_Object* target = this->get_obj(order->target);

    for (int i = 0; i < unit_count; ++i) {
        RGE_Static_Object* object = this->get_obj(ids[i]);
        if (object != 0) {
            static_cast<TRIBE_Combat_Object*>(object)->do_repair(target);
        }
    }
}

void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* order) {
    TRIBE_Command* command = this;
    RGE_Obj_Info* ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(order) + sizeof(*order));
    for (int count = (int)order->unit_num; count > 0; count--) {
        RGE_Static_Object* obj = command->get_obj(*ids);
        if (obj) {
            obj->removeAllFromPathingGroup();
            RGE_Player* owner = obj->owner;
            owner->processAIOrder(owner->id, obj->id, 0x2D1, obj->id, owner->id,
                                  order->location_x, order->location_y, 0, 1.0f, 1, 0, 100);
        }
        ids++;
    }
}

void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* order) {
    TRIBE_Building_Object* building =
        static_cast<TRIBE_Building_Object*>(this->world->object(order->bldg_id));
    if (building != 0) {
        if (0 < order->train_count) {
            building->add_to_production_queue(order->train_id, order->train_count);
            return;
        }
        building->remove_from_production_queue(order->train_id, (short)-order->train_count);
    }
}

extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_make(RGE_Static_Object* unit, short obj_id) {
    if (unit) {
        TRIBE_Command_Make* cmd = static_cast<TRIBE_Command_Make*>(calloc(1, sizeof(TRIBE_Command_Make)));
        if (cmd) {
            cmd->unit_id = unit->id;
            RGE_Player* owner = unit->owner;
            short unit_id_copy = obj_id;
            cmd->unit_player_id = static_cast<unsigned char>(owner->id);
            cmd->command = 100;
            cmd->obj_id = unit_id_copy;
            cmd->unique_id = -1;
            RGE_Master_Static_Object* master = unit->master_obj;
            int unit_id_int = (int)unit_id_copy;
            L->Log("      >SEND CMD MAKE (UNIT=%s,OBJ=%d)", master->name, unit_id_int);
            this->submit(cmd, sizeof(TRIBE_Command_Make));
        }
    }
}


void TRIBE_Command::command_make(
    int playerID, int buildingID, int objID, int uniqueID) {
    if (buildingID >= 0) {
        TRIBE_Command_Make* cmd = static_cast<TRIBE_Command_Make*>(calloc(1, sizeof(TRIBE_Command_Make)));
        if (cmd) {
            cmd->unit_id = buildingID;
            cmd->unit_player_id = static_cast<unsigned char>(playerID);
            cmd->command = 0x64;
            cmd->obj_id = static_cast<short>(objID);
            cmd->unique_id = uniqueID;
            L->Log("      >SEND CMD MAKE2 (PLR=%d,BLDG=%d,OBJ=%d)", playerID, buildingID, objID);
            this->submit(cmd, sizeof(TRIBE_Command_Make));
        }
    }
}


void TRIBE_Command::command_research(RGE_Static_Object* unit, short tech_id) {
    if (unit) {
        TRIBE_Command_Research* cmd = static_cast<TRIBE_Command_Research*>(calloc(1, sizeof(TRIBE_Command_Research)));
        if (cmd) {
            cmd->unit_id = unit->id;
            RGE_Player* owner = unit->owner;
            short tech_id_copy = tech_id;
            cmd->unit_player_id = static_cast<unsigned char>(owner->id);
            cmd->command = 0x65;
            cmd->tech_id = tech_id_copy;
            cmd->unique_id = -1;
            RGE_Master_Static_Object* master = unit->master_obj;
            int tech_id_int = (int)tech_id_copy;
            L->Log("      >SEND CMD RESEARCH (UNIT=%s,TECH=%d)", master->name, tech_id_int);
            this->submit(cmd, sizeof(TRIBE_Command_Research));
        }
    }
}


void TRIBE_Command::command_research(
    int playerID, int buildingID, int techID, int uniqueID) {
    if (buildingID >= 0) {
        TRIBE_Command_Research* cmd = static_cast<TRIBE_Command_Research*>(calloc(1, sizeof(TRIBE_Command_Research)));
        if (cmd) {
            cmd->unit_id = buildingID;
            cmd->unit_player_id = static_cast<unsigned char>(playerID);
            cmd->command = 0x65;
            cmd->tech_id = static_cast<short>(techID);
            cmd->unique_id = uniqueID;
            L->Log("      >SEND CMD RESEARCH2 (PLR=%d,BLDG=%d,TECH=%d)", playerID, buildingID, techID);
            this->submit(cmd, sizeof(TRIBE_Command_Research));
        }
    }
}


void TRIBE_Command::command_build(
    RGE_Static_Object** unit, short list_num, short obj_id,
    float location_x, float location_y) {
    if (unit && list_num >= 1) {
        int obj_count = (int)list_num;
        int size = sizeof(TRIBE_Command_Build) +
                   obj_count * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build* cmd = static_cast<TRIBE_Command_Build*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x66;
            cmd->unit_num = static_cast<unsigned char>(list_num);
            int owner_id;
            if (unit[0]) {
                owner_id = unit[0]->owner->id;
            } else {
                owner_id = -1;
            }
            cmd->location_x = location_x;
            cmd->location_y = location_y;
            cmd->unit_player_id = static_cast<unsigned char>(owner_id);
            cmd->obj_id = obj_id;
            cmd->unique_id = -1;
            L->Log("      >SEND CMD BUILD (CNT=%d,CAT=%d)", obj_count, (int)obj_id);
            this->submit(cmd, size);
        }
    }
}


void TRIBE_Command::command_build(int playerID, int* unitID, int numUnits,
                                  int objectID, float xLoc, float yLoc,
                                  int uniqueID) {
    if (unitID && numUnits >= 1) {
        int size = sizeof(TRIBE_Command_Build) +
                   numUnits * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build* cmd = static_cast<TRIBE_Command_Build*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < numUnits; ++i) {
                unit_ids[i].id = unitID[i];
            }
            cmd->command = 0x66;
            cmd->unit_num = static_cast<unsigned char>(numUnits);
            cmd->obj_id = static_cast<short>(objectID);
            cmd->location_x = xLoc;
            cmd->location_y = yLoc;
            cmd->unique_id = uniqueID;
            cmd->unit_player_id = static_cast<unsigned char>(playerID);
            L->Log("      >SEND CMD BUILD2 (CNT=%d,CAT=%d)", numUnits, objectID);
            this->submit(cmd, size);
        }
    }
}


void TRIBE_Command::command_build_wall(
    RGE_Static_Object** unit, short list_num, short obj_id,
    long x1, long y1, long x2, long y2) {
    if (unit && list_num >= 1) {
        int obj_count = (int)list_num;
        int size = sizeof(TRIBE_Command_Build_Wall) +
                   obj_count * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build_Wall* cmd =
            static_cast<TRIBE_Command_Build_Wall*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x69;
            cmd->unit_num = static_cast<unsigned char>(list_num);
            int owner_id;
            if (unit[0]) {
                owner_id = unit[0]->owner->id;
            } else {
                owner_id = -1;
            }
            cmd->unit_player_id = static_cast<unsigned char>(owner_id);
            cmd->obj_id = obj_id;
            if (x1 < 0) x1 = 0;
            if (x1 > 0xFF) x1 = 0xFF;
            if (y1 < 0) y1 = 0;
            if (y1 > 0xFF) y1 = 0xFF;
            if (x2 < 0) x2 = 0;
            if (x2 > 0xFF) x2 = 0xFF;
            if (y2 < 0) y2 = 0;
            if (y2 > 0xFF) y2 = 0xFF;
            cmd->y2 = static_cast<unsigned char>(y2);
            cmd->x1 = static_cast<unsigned char>(x1);
            cmd->y1 = static_cast<unsigned char>(y1);
            cmd->x2 = static_cast<unsigned char>(x2);
            cmd->unique_id = -1;

            L->Log("      >SEND CMD WALL (CNT=%d,CAT=%d)", obj_count, (int)obj_id);

            this->submit(cmd, size);
        }
    }
}


void TRIBE_Command::command_explore(
    int playerID, int* unitID, int numUnits, float x, float y) {
    if (unitID && numUnits >= 1) {
        int size = sizeof(TRIBE_Command_Explore) +
                   numUnits * sizeof(RGE_Obj_Info);
        TRIBE_Command_Explore* cmd = static_cast<TRIBE_Command_Explore*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < numUnits; ++i) {
                unit_ids[i].id = unitID[i];
            }
            cmd->command = 0x68;
            cmd->numUnits = static_cast<unsigned char>(numUnits);
            cmd->unit_player_id = static_cast<unsigned char>(playerID);
            cmd->targetXPosition = x;
            cmd->targetYPosition = y;
            L->Log("      >SEND CMD EXPLORE (CNT=%d)", numUnits);
            this->submit(cmd, size);
        }
    }
}


void TRIBE_Command::command_allied_victory(short player, unsigned char flag) {
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        int flag_int = (int)flag;
        unsigned short flag_short = static_cast<unsigned short>(flag);
        int player_id_int = (int)player;
        cmd->var1 = player;
        cmd->var2 = static_cast<short>(flag_short);
        cmd->var3 = 0.0f;
        cmd->command = 0x67;
        cmd->game_command = 5;
        L->Log("      >SEND CMD ALLIED VIC (PLR=%d,FLAG=%d)", player_id_int, flag_int);
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_relation(short player, short target_player, short relation) {
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        cmd->var1 = player;
        cmd->var2 = target_player;
        cmd->var3 = static_cast<float>((int)relation);
        cmd->var4 = relation;
        cmd->command = 0x67;
        cmd->game_command = 0;
        L->Log("      >SEND CMD RELATION (PLR=%d,TAR=%d,REL=%d)", (int)player, (int)target_player, (int)relation);
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_game_speed(float gamespeed) {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var3 = gamespeed;
        packet->game_command = 1;
        L->Log("      >SEND CMD GAME SPD");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_save_game() {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->game_command = 0x08;
        L->Log("      >SEND CMD SAVEGAME");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_inventory(short player, short inventory, float amount) {
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        cmd->var1 = player;
        cmd->var2 = inventory;
        cmd->var3 = amount;
        cmd->command = 0x67;
        cmd->game_command = 2;
        L->Log("      >SEND CMD INV (PLR=%d,INV=%d)", (int)player, (int)inventory);
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}


void TRIBE_Command::command_upgrade_town(short player) {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var1 = player;
        packet->game_command = 3;
        L->Log("      >SEND CMD UPG TOWN");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_quick_build(short quick_build) {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var1 = quick_build;
        packet->game_command = 4;
        L->Log("      >SEND CMD QUICKBLD");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_shared_los(short player) {
    TRIBE_Command_Game* order;

    order = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (order != 0) {
        order->command = 0x67;
        order->var1 = player;
        order->game_command = 7;
        L->Log("      >SEND CMD SHAREDLOS");
        this->submit(order, sizeof(TRIBE_Command_Game));
    }
}


void TRIBE_Command::command_cancel_build(RGE_Static_Object* unit) {
    TRIBE_Command_Cancel_Build* cmd =
        static_cast<TRIBE_Command_Cancel_Build*>(calloc(1, sizeof(TRIBE_Command_Cancel_Build)));
    if (cmd) {
        cmd->command = 0x6A;
        cmd->unit_id = unit->id;
        L->Log("      >SEND CMD CANCELBLD");
        this->submit(cmd, sizeof(TRIBE_Command_Cancel_Build));
    }
}


void TRIBE_Command::command_attack_ground(RGE_Static_Object** unit, short list_num, float x, float y) {
    if (unit && list_num >= 1) {
        int obj_count = (int)list_num;
        int size = sizeof(TRIBE_Command_Attack_Ground) +
                   obj_count * sizeof(RGE_Obj_Info);
        TRIBE_Command_Attack_Ground* cmd =
            static_cast<TRIBE_Command_Attack_Ground*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6B;
            cmd->unit_num = (unsigned char)list_num;
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log("      >SEND CMD ATTACK GROUND (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}

extern "C" void* __cdecl calloc(size_t, size_t);

void TRIBE_Command::command_cheat(short player, short cheat_code) {
    TRIBE_Command_Game* buf = static_cast<TRIBE_Command_Game*>(calloc(1, sizeof(TRIBE_Command_Game)));
    if (buf) {
        buf->command = 0x67;
        buf->var1 = player;
        buf->var2 = cheat_code;
        buf->game_command = 6;
        L->Log("      >SEND CMD CHEAT %d", cheat_code);
        submit(buf, sizeof(TRIBE_Command_Game));
    }
}

void TRIBE_Command::command_give_attribute(
    int player_id,
    int to_player_id,
    int attr_id,
    float attr_amount,
    float attr_cost) {
    TRIBE_Command_Give_Attribute* packet =
        static_cast<TRIBE_Command_Give_Attribute*>(calloc(1, sizeof(TRIBE_Command_Give_Attribute)));
    packet->command = 0x6C;
    packet->player_id = static_cast<unsigned char>(player_id);
    packet->to_player_id = static_cast<unsigned char>(to_player_id);
    packet->attr_id = static_cast<unsigned char>(attr_id);
    packet->attr_amount = attr_amount;
    packet->attr_cost = attr_cost;
    L->Log("      >SEND CMD GIVE ATTR (PLR=%d,TO=%d)", player_id, to_player_id);
    this->submit(packet, sizeof(TRIBE_Command_Give_Attribute));
}


void TRIBE_Command::command_trade_attribute(RGE_Static_Object** unit, short list_num, long attribute) {
    if (unit && list_num >= 1) {
        int obj_count = (int)list_num;
        int size = sizeof(TRIBE_Command_Trade_Attribute) +
                   obj_count * sizeof(RGE_Obj_Info);
        TRIBE_Command_Trade_Attribute* cmd =
            static_cast<TRIBE_Command_Trade_Attribute*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6D;
            cmd->unit_num = (unsigned char)list_num;
            cmd->attribute = attribute;

            L->Log("      >SEND CMD TRADE ATTR (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}

extern void* __cdecl calloc(unsigned int, unsigned int);

void TRIBE_Command::command_trade_attribute(int unitID, int playerID, long attribute) {
    TRIBE_Command_Trade_Attribute* buf =
        static_cast<TRIBE_Command_Trade_Attribute*>(calloc(1, sizeof(TRIBE_Command_Trade_Attribute) +
                                                           sizeof(RGE_Obj_Info)));
    RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(buf) + sizeof(*buf));

    if (buf && unit_ids) {
        unit_ids[0].id = unitID;
        buf->command = 0x6D;
        buf->unit_num = 1;
        buf->attribute = attribute;
        L->Log("      >SEND CMD TRADE ATTR2");
        this->submit(buf, sizeof(TRIBE_Command_Trade_Attribute) + sizeof(RGE_Obj_Info));
    }
}

extern "C" void* __cdecl calloc(size_t count, size_t size);

void TRIBE_Command::command_repair(
    RGE_Static_Object** unit,
    short unit_count,
    RGE_Static_Object* target) {
    int object_count = (int)unit_count;
    int size = sizeof(TRIBE_Command_Repair) +
               object_count * sizeof(RGE_Obj_Info);
    if (unit && unit_count >= 1) {
        TRIBE_Command_Repair* packet =
            static_cast<TRIBE_Command_Repair*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(
            reinterpret_cast<unsigned char*>(packet) + sizeof(*packet));
        if (packet) {
            for (int i = 0; i < object_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            packet->target.id = target->id;
            packet->command = 0x6E;
            packet->unit_num = (unsigned char)unit_count;
            L->Log("      >SEND CMD REPAIR (CNT=%d)", object_count);
            this->submit(packet, size);
        }
    }
}


void TRIBE_Command::command_unload(RGE_Static_Object** unit, short list_num, float x, float y) {
    if (unit && list_num >= 1) {
        int obj_count = (int)list_num;
        int size = sizeof(TRIBE_Command_Unload) +
                   obj_count * sizeof(RGE_Obj_Info);
        TRIBE_Command_Unload* cmd = static_cast<TRIBE_Command_Unload*>(calloc(1, size));
        RGE_Obj_Info* unit_ids = reinterpret_cast<RGE_Obj_Info*>(reinterpret_cast<unsigned char*>(cmd) + sizeof(*cmd));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (unit[i]) {
                    unit_ids[i].id = unit[i]->id;
                } else {
                    unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6F;
            cmd->unit_num = static_cast<unsigned char>(list_num);
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log("      >SEND CMD UNLOAD (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}


void TRIBE_Command::command_queue(
    RGE_Static_Object* bldg_obj,
    short train_id,
    short train_count) {
    TRIBE_Command_Queue* cmd = static_cast<TRIBE_Command_Queue*>(calloc(1, sizeof(TRIBE_Command_Queue)));
    if (cmd) {
        cmd->command = 0x77;
        int building_id = bldg_obj->id;
        cmd->train_count = train_count;
        cmd->bldg_id = building_id;
        cmd->train_id = train_id;
        L->Log("      >SEND CMD QUEUE (B=%d,T=%d,C=%d)", bldg_obj->id, (int)train_id, (int)train_count);
        this->submit(cmd, sizeof(TRIBE_Command_Queue));
    }
}
