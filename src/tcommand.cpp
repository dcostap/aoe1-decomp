// Authentic source module for C:\\msdev\\work\\age1_x1\\tcommand.cpp.
// The function order follows the PDB source order from lines 56 through 1796.
// The vector deleting destructor at 00509740 is compiler-generated.

#include "../include/tcommand.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "../include/basegame.h"
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

extern FILE* actionFile;
extern FILE* DVlogf;
extern FILE* DDlogf;
extern int do_debug_random;
extern int out_of_sync2;
extern TCommunications_Handler* comm;
extern void __cdecl debug_random_write();
extern void __cdecl dump_vismap_log();

// PDB order: lines 56-57.
TRIBE_Command::TRIBE_Command(
    TRIBE_World* world,
    TCommunications_Handler* com_hand)
    : RGE_Command(world, com_hand)
{
}

// PDB order: lines 62-125.
extern "C" int __cdecl debug_rand(const char* file, int line);

void TRIBE_Command::do_command(void* cmd)
{
    debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);
    switch (static_cast<TRIBE_Command_Header*>(cmd)->command) {
    case 0x64:
        do_command_make(static_cast<TRIBE_Command_Make*>(cmd));
        return;
    case 0x65:
        do_command_research(static_cast<TRIBE_Command_Research*>(cmd));
        return;
    case 0x66:
        do_command_build(static_cast<TRIBE_Command_Build*>(cmd));
        return;
    case 0x69:
        do_command_build_wall(static_cast<TRIBE_Command_Build_Wall*>(cmd));
        return;
    case 0x68:
        do_command_explore(static_cast<TRIBE_Command_Explore*>(cmd));
        return;
    case 0x67:
        do_command_game(static_cast<TRIBE_Command_Game*>(cmd));
        return;
    case 0x04:
        do_command_tribe_create(static_cast<RGE_Command_Create*>(cmd));
        return;
    case 0x6A:
        do_command_cancel_build(static_cast<TRIBE_Command_Cancel_Build*>(cmd));
        return;
    case 0x6B:
        do_command_attack_ground(static_cast<TRIBE_Command_Attack_Ground*>(cmd));
        return;
    case 0x6C:
        do_command_give_attribute(static_cast<TRIBE_Command_Give_Attribute*>(cmd));
        return;
    case 0x6D:
        do_command_trade_attribute(static_cast<TRIBE_Command_Trade_Attribute*>(cmd));
        return;
    case 0x6E:
        do_command_repair(static_cast<TRIBE_Command_Repair*>(cmd));
        return;
    case 0x6F:
        do_command_unload(static_cast<TRIBE_Command_Unload*>(cmd));
        return;
    case 0x77:
        do_command_queue(static_cast<TRIBE_Command_Queue*>(cmd));
        return;
    default:
        RGE_Command::do_command(cmd);
        return;
    }
}

// PDB order: lines 130-139.
void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* cmd)
{
    int player_offset = (unsigned int)cmd->player_id * 4;
    int category_offset = (int)cmd->obj_catagory * 4;

    if (this->world->players[cmd->player_id]->master_objects[cmd->obj_catagory]->movement_type == 1) {
        cmd->location_z = 4.0f;
    }

    RGE_Static_Object* obj = this->world->players[cmd->player_id]->master_objects[cmd->obj_catagory]->make_new_obj(
        this->world->players[cmd->player_id],
        cmd->location_x,
        cmd->location_y,
        cmd->location_z);

    if (obj->master_obj->master_type == 0x50) {
        static_cast<TRIBE_Building_Object*>(obj)->build(10000.0f);
    }
}

// PDB order: lines 143-205.
void TRIBE_Command::do_command_make(TRIBE_Command_Make* cmd)
{
    short progress;
    short work_target;
    short work_state;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = static_cast<TRIBE_Building_Object*>(
        this->world->object(cmd->unit_id));
    if (building != 0) {
        building->work_status(progress, work_target, work_state, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj(building, cmd->train_id, cmd->unique_id, 0);
            if (action != 0) {
                building->add_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(cmd->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
        TRIBE_Player* player = static_cast<TRIBE_Player*>(
            this->world->players[cmd->player_index]);
        if (player != 0) {
            player->cancelTrain(0, cmd->train_id, cmd->unit_id, cmd->unique_id);
        }
    } else {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(
            this->world->players[cmd->player_index]);
        if (player != 0) {
            player->cancelTrain(0, cmd->train_id, cmd->unit_id, cmd->unique_id);
        }
    }
}

// PDB order: lines 209-251.
void TRIBE_Command::do_command_research(TRIBE_Command_Research* cmd)
{
    short progress;
    short work_target;
    short work_state;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = static_cast<TRIBE_Building_Object*>(
        this->world->object(cmd->unit_id));
    if (building != 0) {
        building->work_status(progress, work_target, work_state, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Tech* action = new TRIBE_Action_Make_Tech(
                static_cast<RGE_Action_Object*>(building), cmd->tech_id,
                cmd->unique_id);
            if (action != 0) {
                building->add_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(cmd->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
        TRIBE_Player* player = static_cast<TRIBE_Player*>(
            this->world->players[cmd->player_index]);
        if (player != 0) {
            player->cancelResearch(cmd->tech_id, cmd->unit_id, -1, cmd->unique_id);
        }
    } else {
        TRIBE_Player* player = static_cast<TRIBE_Player*>(
            this->world->players[cmd->player_index]);
        if (player != 0) {
            player->cancelResearch(cmd->tech_id, cmd->unit_id, -1, cmd->unique_id);
        }
    }
}

// PDB order: lines 256-331.
void TRIBE_Command::do_command_build(TRIBE_Command_Build* cmd)
{
    RGE_Static_Object* blockingObject;
    int placement;
    uchar placementResult;
    int count = cmd->count;
    RGE_Static_Object* obj;

    TRIBE_Player* player = static_cast<TRIBE_Player*>(
        this->world->players[cmd->player_id]);
    if (player == 0) {
        return;
    }
    if (cmd->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* info =
        static_cast<TRIBE_Master_Building_Object*>(
            player->master_objects[cmd->obj_id]);
    if (info == 0) {
        return;
    }

    placementResult = info->check_placement(player, cmd->x, cmd->y,
                                            &placement, 1, 1, 1, 1, 1, 1);
    if (placementResult != 0) {
        if (count > 0) {
            obj = this->get_obj(cmd->unit_ids[0]);
            if (obj != 0) {
                player->cancelBuild(placementResult, placement,
                                    cmd->obj_id, cmd->x, cmd->y, cmd->unique_id,
                                    obj->id);
            }
        }
        return;
    }

    if (!player->pay_obj_cost(cmd->obj_id, 1.0f, 0)) {
        if (count <= 0) {
            return;
        }
        obj = this->get_obj(cmd->unit_ids[0]);
        if (obj == 0) {
            return;
        }
        player->cancelBuild(0, placement, cmd->obj_id,
                            cmd->x, cmd->y, cmd->unique_id, obj->id);
        return;
    }

    blockingObject = info->make_new_obj(player, cmd->x, cmd->y, 0,
                                        cmd->unique_id);
    if (count <= 0) {
        return;
    }

    RGE_Obj_Info* idp = cmd->unit_ids;
    int n = count;
    do {
        obj = this->get_obj(*idp);
        if (obj != 0) {
            obj->removeAllFromPathingGroup();
            obj->do_command(blockingObject, cmd->x, cmd->y, 0.0f);
        }
        ++idp;
        --n;
    } while (n != 0);
}

// PDB order: lines 337-450.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
// BINARY NOTE: The idp alias reproduces the original 500-byte grouped owner.
void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* cmd)
{
    int count = cmd->count;
    RGE_Obj_Info* ids = cmd->unit_ids;
    TRIBE_Player* player = static_cast<TRIBE_Player*>(
        this->world->players[cmd->player_id]);
    if (player == 0) return;
    if (cmd->obj_id == -1) return;
    TRIBE_Master_Building_Object* info =
        static_cast<TRIBE_Master_Building_Object*>(
            player->master_objects[cmd->obj_id]);
    if (info == 0) return;

    RGE_Static_Object* foundation = 0;
    int dy = abs((int)cmd->y2 - (int)cmd->y1);
    int dx = abs((int)cmd->x2 - (int)cmd->x1);

    if (dy == dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y2,
                                  &foundation);
    } else if (dy >= dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x1, cmd->y2,
                                  &foundation);
        uchar x2 = cmd->x2;
        if (cmd->x1 < x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 + 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->x1 > x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 - 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        }
    } else {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y1,
                                  &foundation);
        uchar y2 = cmd->y2;
        if (cmd->y1 < y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 + 1,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->y1 > y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 - 1,
                                      cmd->x2, cmd->y2, &foundation);
        }
    }

    if (foundation != 0 && count > 0) {
        int n = count;
        RGE_Obj_Info* idp = ids;
        do {
            RGE_Static_Object* obj = this->get_obj(*idp);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->do_command(foundation, foundation->world_x,
                                foundation->world_y, 0.0f);
            }
            ++idp;
            --n;
        } while (n != 0);
    }
}

// PDB order: lines 456-503.
void TRIBE_Command::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master,
    int object_id,
    int start_x,
    int start_y,
    int end_x,
    int end_y,
    RGE_Static_Object** result)
{
    int y_skip;
    int x_skip;

    if (start_x == end_x) {
        y_skip = 0;
    } else {
        y_skip = (((int)(end_x <= start_x) - 1) & 2) - 1;
    }

    if (start_y == end_y) {
        x_skip = 0;
    } else {
        x_skip = (((int)(end_y <= start_y) - 1) & 2) - 1;
    }

    int temp = start_y;
    start_y = start_x;
    start_x = temp;

    for (;;) {
        float coordinate_x = (float)start_y + 0.5f;
        float coordinate_y = (float)start_x + 0.5f;
        if (master->check_placement(
                player,
                coordinate_x,
                coordinate_y,
                0, 1, master->elevation_flag,
                0, 1, 1, 1) == 0) {
            if (player->pay_obj_cost(master->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* object = master->make_new_obj(
                player,
                coordinate_x,
                coordinate_y,
                0,
                object_id);
            if (object != 0 && *result == 0) {
                *result = object;
            }
        }

        if (start_y == end_x && start_x == end_y) {
            break;
        }

        start_y += y_skip;
        start_x += x_skip;
    }
}

// PDB order: lines 508-527.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* cmd)
{
    TRIBE_Command* self = this;
    RGE_Game_World* world = self->world;
    int player_id = cmd->unit_player_id;
    RGE_Obj_Info* ids = cmd->unit_ids;
    if (world->players[player_id] != 0) {
        int i = 0;
        if (cmd->unit_num > 0) {
            do {
                RGE_Static_Object* obj = self->get_obj(*ids);
                if (obj != 0) {
                    obj->removeAllFromPathingGroup();
                    obj->explore((int)cmd->target_x,
                                 (int)cmd->target_y, 1);
                }
                ++i;
                ++ids;
            } while (i < (int)cmd->unit_num);
        }
    }
}

// PDB order: lines 531-665.
// BINARY NOTE: Original game fields use draw_system +0x48 and quick_build +0x9A8.
void TRIBE_Command::do_command_game(TRIBE_Command_Game* cmd)
{
    char file_name[260];
    switch (cmd->game_command) {
    case 5:
        this->world->players[cmd->var1]->set_allied_victory((unsigned char)cmd->var2);
        break;
    case 0:
        this->world->players[cmd->var1]->set_relation(cmd->var2, (unsigned char)cmd->var3);
        rge_base_game->notification(8, cmd->var1, cmd->var2, cmd->var4, 0);
        this->world->update_mutual_allies();
        break;
    case 1:
        this->world->set_game_speed(cmd->var3);
        break;
    case 8:
        {
        out_of_sync2 = 1;
        TRIBE_Screen_Status_Message* status = new TRIBE_Screen_Status_Message("Temp Screen", "", 0, -1);
        (void)status;
        panel_system.setCurrentPanel("Temp Screen", 0);
        TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
        game->close_game_screens(1);
        if (do_debug_random != 0) {
            debug_random_write();
            dump_vismap_log();
            if (actionFile != 0) { fclose(actionFile); actionFile = 0; }
            if (DVlogf != 0) { fclose(DVlogf); DVlogf = 0; }
            if (DDlogf != 0) { fclose(DDlogf); DDlogf = 0; }
        }
        sprintf(file_name, "syncerr%d.gam", comm->WhoAmI());
        game->save_game(file_name);
        this->world->players[this->world->curr_player]->loss_if_game_on();
        game->do_game_over();
        TEasy_Panel* panel = static_cast<TEasy_Panel*>(
            panel_system.currentPanel());
        if (panel != 0) {
            TDrawSystem* draw_system = rge_base_game->draw_system;
            draw_system->SetPalette(panel->get_palette());
            rge_base_game->set_render_all();
            rge_base_game->draw_window();
            panel->popupOKDialog(0x966, 0, 0x1C2, 100);
        }
        panel_system.destroyPanel("Temp Screen");
        break;
        }
    case 2:
        this->world->players[cmd->var1]->add_attribute_num(cmd->var2, cmd->var3, 0);
        break;
    case 4:
        {
        TRIBE_Game* game = static_cast<TRIBE_Game*>(rge_base_game);
        game->quick_build = cmd->var1;
        break;
        }
    case 6:
        static_cast<TRIBE_World*>(this->world)->cheat(
            cmd->var1, static_cast<short>(static_cast<unsigned char>(cmd->var2)));
        break;
    case 7:
        this->world->effects->do_effect(0x71, this->world->players[cmd->var1]);
        break;
    default:
        break;
    }
}

// PDB order: lines 671-683.
void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* cmd)
{
    RGE_Static_Object* object = this->world->object(cmd->unit_id);
    if (object != 0) {
        static_cast<TRIBE_Combat_Object*>(object)->cancel_object();
    }
}

// PDB order: lines 688-703.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* packet)
{
    RGE_Obj_Info* ids = packet->unit_ids;
    unsigned int count = (unsigned int)packet->unit_num;
    if ((int)count <= 0) {
        return;
    }
    do {
        RGE_Static_Object* object = this->get_obj(*ids);
        if (object != 0) {
            object->attack(packet->location_x, packet->location_y, 0.0f, 1);
        }
        ++ids;
        --count;
    } while (count != 0);
}

// PDB order: lines 708-770.
void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* ca)
{
    float cost;
    float v;

    cost = 0.0f;
    if (ca->attr_amount >= 0.0f) {
        v = ca->attr_amount;
    } else {
        v = 0.0f;
    }

    if (v > 0.0) {
        cost = ca->attr_cost * v;
    }

    {
        float* attr_ptr = &this->world->players[ca->player_id]->attributes[ca->attr_id];
        if (v + cost > *attr_ptr) {
            cost = *attr_ptr;
            cost *= ca->attr_cost;
            v = *attr_ptr - cost;
        }
    }

    this->world->players[ca->to_player_id]->add_attribute_num(ca->attr_id, v, 0);
    this->world->players[ca->player_id]->add_attribute_num(ca->attr_id, -(v + cost), 0);
    this->world->players[ca->player_id]->add_attribute_num(0x35, v + cost, 0);
    this->world->players[ca->to_player_id]->add_attribute_num(0x35, -v, 0);
    rge_base_game->notification(7, ca->player_id, ca->to_player_id,
                                ca->attr_id, (long)v);
    this->world->players[ca->to_player_id]->notify(
        ca->player_id, ca->to_player_id, 0x20A, ca->attr_id,
        (long)ca->attr_amount, 0);
}

// PDB order: lines 776-789.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* packet)
{
    int count = packet->unit_num;
    RGE_Obj_Info* ids = packet->unit_ids;
    if (count > 0) {
        do {
            RGE_Static_Object* object = this->get_obj(*ids);
            if (object != 0) {
                object->attribute_type_held = (short)packet->attribute;
            }
            ++ids;
        } while (--count != 0);
    }
}

// PDB order: lines 795-815.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* packet)
{
    int target_id = packet->target.id;
    unsigned char unit_count = packet->unit_num;
    RGE_Obj_Info* ids = packet->unit_ids;
    RGE_Obj_Info target_info;
    target_info.id = target_id;
    RGE_Static_Object* target = this->get_obj(target_info);

    if ((int)unit_count > 0) {
        do {
            RGE_Static_Object* object = this->get_obj(*ids);
            if (object != 0) {
                static_cast<TRIBE_Combat_Object*>(object)->do_repair(target);
            }
            ++ids;
            --unit_count;
        } while (unit_count != 0);
    }
}

// PDB order: lines 820-846.
void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* cmd)
{
    TRIBE_Command* v_this = this;
    RGE_Obj_Info* v_ids = cmd->unit_ids;
    for (int v_count = (int)cmd->unit_num; v_count > 0; v_count--) {
        RGE_Static_Object* obj = v_this->get_obj(*v_ids);
        if (obj) {
            obj->removeAllFromPathingGroup();
            RGE_Player* owner = obj->owner;
            owner->processAIOrder(
                owner->id, obj->id, 0x2D1, obj->id, owner->id,
                cmd->location_x, cmd->location_y, 0, 1.0f, 1, 0, 100);
        }
        v_ids++;
    }
}

// PDB order: lines 852-867.
void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* queue) {
    TRIBE_Building_Object* building =
        static_cast<TRIBE_Building_Object*>(
            this->world->object(queue->building_id));
    if (building != 0) {
        if (0 < queue->train_count) {
            building->add_to_production_queue(queue->train_id, queue->train_count);
            return;
        }
        building->remove_from_production_queue(
            queue->train_id, (short)-queue->train_count);
    }
}

// PDB order: lines 872-900.
extern "C" TDebuggingLog* L;
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_make(RGE_Static_Object* obj, short unit_id)
{
    if (obj) {
        TRIBE_Command_Make* cmd = static_cast<TRIBE_Command_Make*>(
            calloc(1, sizeof(TRIBE_Command_Make)));
        if (cmd) {
            cmd->unit_id = obj->id;
            RGE_Player* owner = obj->owner;
            short unit_id_copy = unit_id;
            cmd->player_index = static_cast<unsigned char>(owner->id);
            cmd->command = 100;
            cmd->train_id = unit_id_copy;
            cmd->unique_id = -1;
            RGE_Master_Static_Object* master = obj->master_obj;
            int unit_id_int = (int)unit_id_copy;
            L->Log("      >SEND CMD MAKE (UNIT=%s,OBJ=%d)",
                   master->name, unit_id_int);
            this->submit(cmd, sizeof(TRIBE_Command_Make));
        }
    }
}

// PDB order: lines 906-938.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_make(
    int player_id, int bldg_id, int unit_id, int param4)
{
    if (bldg_id >= 0) {
        TRIBE_Command_Make* cmd = static_cast<TRIBE_Command_Make*>(
            calloc(1, sizeof(TRIBE_Command_Make)));
        if (cmd) {
            cmd->unit_id = bldg_id;
            cmd->player_index = static_cast<unsigned char>(player_id);
            cmd->command = 0x64;
            cmd->train_id = static_cast<short>(unit_id);
            cmd->unique_id = param4;
            L->Log("      >SEND CMD MAKE2 (PLR=%d,BLDG=%d,OBJ=%d)",
                   player_id, bldg_id, unit_id);
            this->submit(cmd, sizeof(TRIBE_Command_Make));
        }
    }
}

// PDB order: lines 944-972.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_research(RGE_Static_Object* obj, short tech_id)
{
    if (obj) {
        TRIBE_Command_Research* cmd = static_cast<TRIBE_Command_Research*>(
            calloc(1, sizeof(TRIBE_Command_Research)));
        if (cmd) {
            cmd->unit_id = obj->id;
            RGE_Player* owner = obj->owner;
            short tech_id_copy = tech_id;
            cmd->player_index = static_cast<unsigned char>(owner->id);
            cmd->command = 0x65;
            cmd->tech_id = tech_id_copy;
            cmd->unique_id = -1;
            RGE_Master_Static_Object* master = obj->master_obj;
            int tech_id_int = (int)tech_id_copy;
            L->Log("      >SEND CMD RESEARCH (UNIT=%s,TECH=%d)",
                   master->name, tech_id_int);
            this->submit(cmd, sizeof(TRIBE_Command_Research));
        }
    }
}

// PDB order: lines 978-1009.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_research(
    int player_id, int bldg_id, int tech_id, int param4)
{
    if (bldg_id >= 0) {
        TRIBE_Command_Research* cmd = static_cast<TRIBE_Command_Research*>(
            calloc(1, sizeof(TRIBE_Command_Research)));
        if (cmd) {
            cmd->unit_id = bldg_id;
            cmd->player_index = static_cast<unsigned char>(player_id);
            cmd->command = 0x65;
            cmd->tech_id = static_cast<short>(tech_id);
            cmd->unique_id = param4;
            L->Log("      >SEND CMD RESEARCH2 (PLR=%d,BLDG=%d,TECH=%d)",
                   player_id, bldg_id, tech_id);
            this->submit(cmd, sizeof(TRIBE_Command_Research));
        }
    }
}

// PDB order: lines 1015-1060.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(
    RGE_Static_Object** objs, short count, short build_id, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = sizeof(TRIBE_Command_Build) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build* cmd = static_cast<TRIBE_Command_Build*>(
            calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    cmd->unit_ids[i].id = objs[i]->id;
                } else {
                    cmd->unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x66;
            cmd->count = static_cast<unsigned char>(count);
            int owner_id;
            if (objs[0]) {
                owner_id = objs[0]->owner->id;
            } else {
                owner_id = -1;
            }
            cmd->x = x;
            cmd->y = y;
            cmd->player_id = static_cast<unsigned char>(owner_id);
            cmd->obj_id = build_id;
            cmd->unique_id = -1;
            L->Log("      >SEND CMD BUILD (CNT=%d,CAT=%d)",
                   obj_count, (int)build_id);
            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1066-1110.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
extern void Log(void* log, const char* format, ...);
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build(int player_id, int* ids, int count,
                                  int build_id, float x, float y, int terrain)
{
    if (ids && count >= 1) {
        int size = sizeof(TRIBE_Command_Build) +
                   (count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build* cmd = static_cast<TRIBE_Command_Build*>(
            calloc(1, size));
        if (cmd) {
            for (int i = 0; i < count; ++i) {
                cmd->unit_ids[i].id = ids[i];
            }
            short build_short = (short)build_id;
            int cat_for_log = build_id;
            cmd->x = x;
            cmd->y = y;
            cmd->command = 0x66;
            cmd->count = static_cast<unsigned char>(count);
            cmd->obj_id = build_short;
            cmd->unique_id = terrain;
            cmd->player_id = static_cast<unsigned char>(player_id);
            Log(L, "      >SEND CMD BUILD2 (CNT=%d,CAT=%d)", count, cat_for_log);
            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1116-1176.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_build_wall(
    RGE_Static_Object** objs, short count, short build_id,
    long a, long b, long c, long d)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = sizeof(TRIBE_Command_Build_Wall) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Build_Wall* cmd =
            static_cast<TRIBE_Command_Build_Wall*>(calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    cmd->unit_ids[i].id = objs[i]->id;
                } else {
                    cmd->unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x69;
            cmd->count = static_cast<unsigned char>(count);
            int owner_id;
            if (objs[0]) {
                owner_id = objs[0]->owner->id;
            } else {
                owner_id = -1;
            }
            cmd->player_id = static_cast<unsigned char>(owner_id);
            cmd->obj_id = build_id;
            if (a < 0) a = 0;
            if (a > 0xFF) a = 0xFF;
            if (b < 0) b = 0;
            if (b > 0xFF) b = 0xFF;
            if (c < 0) c = 0;
            if (c > 0xFF) c = 0xFF;
            if (d < 0) d = 0;
            if (d > 0xFF) d = 0xFF;
            cmd->y2 = static_cast<unsigned char>(d);
            cmd->x1 = static_cast<unsigned char>(a);
            cmd->y1 = static_cast<unsigned char>(b);
            cmd->x2 = static_cast<unsigned char>(c);
            cmd->unique_id = -1;

            L->Log("      >SEND CMD WALL (CNT=%d,CAT=%d)",
                   obj_count, (int)build_id);

            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1182-1221.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_explore(
    int player_id, int* obj_ids, int obj_count, float x, float y)
{
    if (obj_ids && obj_count >= 1) {
        int size = sizeof(TRIBE_Command_Explore) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Explore* cmd = static_cast<TRIBE_Command_Explore*>(
            calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                cmd->unit_ids[i].id = obj_ids[i];
            }
            cmd->command = 0x68;
            cmd->unit_num = static_cast<unsigned char>(obj_count);
            cmd->unit_player_id = static_cast<unsigned char>(player_id);
            cmd->target_x = x;
            cmd->target_y = y;
            L->Log("      >SEND CMD EXPLORE (CNT=%d)", obj_count);
            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1227-1250.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_allied_victory(short player_id, unsigned char flag)
{
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        int flag_int = (int)flag;
        unsigned short flag_short = static_cast<unsigned short>(flag);
        int player_id_int = (int)player_id;
        cmd->var1 = player_id;
        cmd->var2 = static_cast<short>(flag_short);
        cmd->var3 = 0.0f;
        cmd->command = 0x67;
        cmd->game_command = 5;
        L->Log("      >SEND CMD ALLIED VIC (PLR=%d,FLAG=%d)",
               player_id_int, flag_int);
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1256-1281.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::command_relation(short player_id, short target_player_id, short relation)
{
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        short rel_s = relation;
        short player_s = player_id;
        short target_s = target_player_id;
        int rel_i = (int)rel_s;
        cmd->var2 = target_s;
        cmd->var3 = static_cast<float>(rel_i);
        cmd->var4 = rel_s;
        L->Log("      >SEND CMD RELATION (PLR=%d,TAR=%d,REL=%d)",
               (int)player_s, (int)target_s, rel_i);
        cmd->var1 = player_s;
        cmd->command = 0x67;
        cmd->game_command = 0;
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1287-1308.
void TRIBE_Command::command_game_speed(float speed)
{
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var3 = speed;
        packet->game_command = 1;
        L->Log("      >SEND CMD GAME SPD");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1314-1334.
void TRIBE_Command::command_save_game()
{
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->game_command = 0x08;
        L->Log("      >SEND CMD SAVEGAME");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1340-1363.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
void TRIBE_Command::command_inventory(short player_id, short inventory_id, float amount)
{
    TRIBE_Command_Game* cmd = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (cmd) {
        short inv = inventory_id;
        short player = player_id;
        cmd->var2 = inv;
        cmd->var3 = amount;
        cmd->var1 = player;
        cmd->command = 0x67;
        cmd->game_command = 2;
        L->Log("      >SEND CMD INV (PLR=%d,INV=%d)",
               (int)player_id, (int)inventory_id);
        this->submit(cmd, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1369-1390.
extern void Log(void* log, const char* text, ...);

void TRIBE_Command::command_upgrade_town(short town_id) {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var1 = town_id;
        packet->game_command = 3;
        Log(L, "      >SEND CMD UPG TOWN");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1396-1417.
void TRIBE_Command::command_quick_build(short value) {
    TRIBE_Command_Game* packet = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (packet != 0) {
        packet->command = 0x67;
        packet->var1 = value;
        packet->game_command = 4;
        L->Log("      >SEND CMD QUICKBLD");
        this->submit(packet, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1423-1444.
void TRIBE_Command::command_shared_los(short param_1) {
    TRIBE_Command_Game* order;

    order = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (order != 0) {
        order->command = 0x67;
        order->var1 = param_1;
        order->game_command = 7;
        L->Log("      >SEND CMD SHAREDLOS");
        this->submit(order, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1450-1471.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_cancel_build(RGE_Static_Object* obj)
{
    TRIBE_Command_Cancel_Build* cmd =
        static_cast<TRIBE_Command_Cancel_Build*>(
            calloc(1, sizeof(TRIBE_Command_Cancel_Build)));
    if (cmd) {
        cmd->command = 0x6A;
        cmd->unit_id = obj->id;
        L->Log("      >SEND CMD CANCELBLD");
        this->submit(cmd, sizeof(TRIBE_Command_Cancel_Build));
    }
}

// PDB order: lines 1477-1519.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_attack_ground(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = sizeof(TRIBE_Command_Attack_Ground) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Attack_Ground* cmd =
            static_cast<TRIBE_Command_Attack_Ground*>(calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    cmd->unit_ids[i].id = objs[i]->id;
                } else {
                    cmd->unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6B;
            cmd->unit_num = (unsigned char)count;
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log(
                "      >SEND CMD ATTACK GROUND (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1525-1547.
extern "C" void* __cdecl calloc(size_t, size_t);

void TRIBE_Command::command_cheat(short param1, short param2) {
    TRIBE_Command_Game* buf = static_cast<TRIBE_Command_Game*>(
        calloc(1, sizeof(TRIBE_Command_Game)));
    if (buf) {
        buf->command = 0x67;
        buf->var1 = param1;
        buf->var2 = param2;
        buf->game_command = 6;
        L->Log("      >SEND CMD CHEAT %d", param2);
        submit(buf, sizeof(TRIBE_Command_Game));
    }
}

// PDB order: lines 1553-1579.
void TRIBE_Command::command_give_attribute(
    int player_id,
    int to_player_id,
    int attr,
    float amount,
    float amount2)
{
    TRIBE_Command_Give_Attribute* packet =
        static_cast<TRIBE_Command_Give_Attribute*>(calloc(
            1, sizeof(TRIBE_Command_Give_Attribute)));
    packet->command = 0x6C;
    packet->player_id = static_cast<unsigned char>(player_id);
    packet->to_player_id = static_cast<unsigned char>(to_player_id);
    packet->attr_id = static_cast<unsigned char>(attr);
    packet->attr_amount = amount;
    packet->attr_cost = amount2;
    L->Log("      >SEND CMD GIVE ATTR (PLR=%d,TO=%d)",
           player_id,
           to_player_id);
    this->submit(packet, sizeof(TRIBE_Command_Give_Attribute));
}

// PDB order: lines 1585-1625.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_trade_attribute(RGE_Static_Object** objs, short count, long attribute)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = sizeof(TRIBE_Command_Trade_Attribute) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Trade_Attribute* cmd =
            static_cast<TRIBE_Command_Trade_Attribute*>(calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    cmd->unit_ids[i].id = objs[i]->id;
                } else {
                    cmd->unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6D;
            cmd->unit_num = (unsigned char)count;
            cmd->attribute = attribute;

            L->Log(
                "      >SEND CMD TRADE ATTR (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1632-1660.
extern void* __cdecl calloc(unsigned int, unsigned int);

void TRIBE_Command::command_trade_attribute(int param_1, int param_2, long param_3) {
    TRIBE_Command_Trade_Attribute* buf =
        static_cast<TRIBE_Command_Trade_Attribute*>(
            calloc(1, sizeof(TRIBE_Command_Trade_Attribute)));

    if (buf) {
        buf->unit_ids[0].id = param_1;
        buf->command = 0x6D;
        buf->unit_num = 1;
        buf->attribute = param_3;
        L->Log("      >SEND CMD TRADE ATTR2");
        this->submit(buf, sizeof(TRIBE_Command_Trade_Attribute));
    }
}

// PDB order: lines 1666-1716.
extern "C" void* __cdecl calloc(size_t count, size_t size);

void TRIBE_Command::command_repair(
    RGE_Static_Object** objects,
    short count,
    RGE_Static_Object* target)
{
    int object_count = (int)count;
    if (objects && count >= 1) {
        int size = sizeof(TRIBE_Command_Repair) +
                   (object_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Repair* packet =
            static_cast<TRIBE_Command_Repair*>(calloc(1, size));
        if (packet) {
            for (int i = 0; i < object_count; ++i) {
                if (objects[i]) {
                    packet->unit_ids[i].id = objects[i]->id;
                } else {
                    packet->unit_ids[i].id = -1;
                }
            }
            packet->target.id = target->id;
            packet->command = 0x6E;
            packet->unit_num = (unsigned char)count;
            L->Log("      >SEND CMD REPAIR (CNT=%d)", object_count);
            this->submit(packet, size);
        }
    }
}

// PDB order: lines 1722-1764.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_unload(RGE_Static_Object** objs, short count, float x, float y)
{
    if (objs && count >= 1) {
        int obj_count = (int)count;
        int size = sizeof(TRIBE_Command_Unload) +
                   (obj_count - 1) * sizeof(RGE_Obj_Info);
        TRIBE_Command_Unload* cmd = static_cast<TRIBE_Command_Unload*>(
            calloc(1, size));
        if (cmd) {
            for (int i = 0; i < obj_count; ++i) {
                if (objs[i]) {
                    cmd->unit_ids[i].id = objs[i]->id;
                } else {
                    cmd->unit_ids[i].id = -1;
                }
            }
            cmd->command = 0x6F;
            cmd->unit_num = static_cast<unsigned char>(count);
            cmd->location_x = x;
            cmd->location_y = y;

            L->Log("      >SEND CMD UNLOAD (CNT=%d)", obj_count);

            this->submit(cmd, size);
        }
    }
}

// PDB order: lines 1770-1796.
extern "C" void* __cdecl calloc(size_t num, size_t size);

void TRIBE_Command::command_queue(
    RGE_Static_Object* building,
    short train_id,
    short count)
{
    TRIBE_Command_Queue* cmd = static_cast<TRIBE_Command_Queue*>(
        calloc(1, sizeof(TRIBE_Command_Queue)));
    if (cmd) {
        cmd->command = 0x77;
        int building_id = building->id;
        cmd->train_count = count;
        cmd->building_id = building_id;
        cmd->train_id = train_id;
        L->Log("      >SEND CMD QUEUE (B=%d,T=%d,C=%d)",
               building->id, (int)train_id, (int)count);
        this->submit(cmd, sizeof(TRIBE_Command_Queue));
    }
}
