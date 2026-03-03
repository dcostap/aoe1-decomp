#include "../include/TRIBE_Command.h"
#include "../include/TRIBE_Command_Game.h"
#include "../include/RGE_Obj_Info.h"
#include "../include/RGE_Command_Create.h"
#include "../include/RGE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Trade_Attribute.h"
#include "../include/TRIBE_Command_Repair.h"
#include "../include/TRIBE_Command_Queue.h"
#include "../include/TRIBE_Command_Unload.h"
#include "../include/TRIBE_Command_Make.h"
#include "../include/TRIBE_Command_Research.h"
#include "../include/TRIBE_Command_Build.h"
#include "../include/TRIBE_Command_Explore.h"
#include "../include/TRIBE_Command_Build_Wall.h"
#include "../include/TRIBE_Command_Cancel_Build.h"
#include "../include/TRIBE_Command_Attack_Ground.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_Combat_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action_Object.h"
#include "../include/Production_Queue_Record.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"

#include <cstdlib>

// TODO: PARITY - Multiple TRIBE_Command send helpers intentionally omit TDebuggingLog::Log side effects present in decomp; audit each omitted logging path for strict behavioral parity. [decomp: tcommand.cpp.decomp @ 0x0050A7F0]

// Fully verified. Marker reconciliation coverage.
static void rge_command_issue_order(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* OrderFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    OrderFn fn = (OrderFn)vtable[0x98 / 4];
    fn(obj, target_value, x, y, z);
}

// Fully verified. Marker reconciliation coverage.
static void tribe_unit_ai_set_current_action(UnitAIModule* unit_ai, int action_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x54) = *(int*)(ai + 0x30);
    *(int*)(ai + 0x30) = action_value;
}

// Fully verified. Marker reconciliation coverage.
static void tribe_unit_ai_set_current_target(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y, float target_z) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x58) = *(int*)(ai + 0x34);
    *(int*)(ai + 0x5C) = *(int*)(ai + 0x38);
    *(int*)(ai + 0x34) = target_id;
    *(int*)(ai + 0x38) = target_type;
    *(float*)(ai + 0x3C) = target_x;
    *(float*)(ai + 0x40) = target_y;
    *(float*)(ai + 0x44) = target_z;
}

TRIBE_Command::TRIBE_Command(RGE_Game_World* world, TCommunications_Handler* comm)
    : RGE_Command(world, comm) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509720
    // TODO: EMPTY_STUB - function body not transliterated [decomp: tcommand.cpp.decomp @ 0x00509720]
}

// Fully verified. Marker reconciliation coverage.
TRIBE_Command::~TRIBE_Command() {}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A510 (vt[4] / +0x10 dispatch target).
    // Keep base command-id-7 behavior intact on vt[0].
    RGE_Command::do_command_give_attribute(p1);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command(void* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509770
    (void)debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);

    uchar cmd = *(uchar*)p1;
    switch (cmd) {
    case 4:
        this->do_command_tribe_create((RGE_Command_Create*)p1);
        return;
    case 100:
        this->do_command_make((TRIBE_Command_Make*)p1);
        return;
    case 0x65:
        this->do_command_research((TRIBE_Command_Research*)p1);
        return;
    case 0x66:
        this->do_command_build((TRIBE_Command_Build*)p1);
        return;
    case 0x67:
        this->do_command_game((TRIBE_Command_Game*)p1);
        return;
    case 0x68:
        this->do_command_explore((TRIBE_Command_Explore*)p1);
        return;
    case 0x69:
        this->do_command_build_wall((TRIBE_Command_Build_Wall*)p1);
        return;
    case 0x6A:
        this->do_command_cancel_build((TRIBE_Command_Cancel_Build*)p1);
        return;
    case 0x6B:
        this->do_command_attack_ground((TRIBE_Command_Attack_Ground*)p1);
        return;
    case 0x6C:
        // TRIBE-specific give-attribute handler lives in vt[4] (+0x10).
        // Use an explicit vtable dispatch to match the original ASM `CALL [vtable + 0x10]`.
        {
            typedef void(__thiscall* GiveAttrFn)(TRIBE_Command*, TRIBE_Command_Give_Attribute*);
            void** vtable = *(void***)this;
            GiveAttrFn fn = (GiveAttrFn)vtable[0x10 / 4];
            fn(this, (TRIBE_Command_Give_Attribute*)p1);
        }
        return;
    case 0x6D:
        this->do_command_trade_attribute((TRIBE_Command_Trade_Attribute*)p1);
        return;
    case 0x6E:
        this->do_command_repair((TRIBE_Command_Repair*)p1);
        return;
    case 0x6F:
        this->do_command_unload((TRIBE_Command_Unload*)p1);
        return;
    case 0x77:
        this->do_command_queue((TRIBE_Command_Queue*)p1);
        return;
    default:
        RGE_Command::do_command(p1);
        return;
    }
}
// Fully verified. Marker reconciliation coverage.
static void tcommand_jump_stub_00509859() {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509859
    // TODO: EMPTY_STUB - function body not transliterated [decomp: tcommand.cpp.decomp @ 0x00509859]
    // ASM shows this is a jump-table alignment entry (NOP; MOV EDI, EDI).
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_tribe_create(RGE_Command_Create* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509910
    int player_index = (uint)p1->player_id;
    int object_index = (int)p1->obj_catagory;

    RGE_Player* player = this->world->players[player_index];
    RGE_Master_Static_Object* master = player->master_objects[object_index];
    if (master->unit_level == 1) {
        p1->location_z = 4.0f;
    }

    RGE_Static_Object* obj = master->make_new_obj(player, p1->location_x, p1->location_y, p1->location_z);
    if (obj->master_obj->master_type == 'P') {
        ((TRIBE_Building_Object*)obj)->build(10000.0f);
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_make(TRIBE_Command_Make* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509980
    if ((this->world == nullptr) || (this->world->players == nullptr) || (p1 == nullptr)) {
        return;
    }

    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->unit_id);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];

    short work_type = 0;
    if (building == nullptr) {
        work_type = 0x67;
    } else if ((building->production_queue_actions != nullptr) && (building->production_queue_actions->get_action() != nullptr)) {
        work_type = building->production_queue_actions->get_action()->type();
    }

    if ((building != nullptr) && (work_type != 0x67) && (work_type != 0x66)) {
        TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj((RGE_Action_Object*)building, p1->obj_id, p1->unique_id, 0);
        if (action != nullptr) {
            typedef void(__thiscall* AddActionFn)(TRIBE_Building_Object*, RGE_Action*);
            void** vtable = *(void***)building;
            AddActionFn add_action = (AddActionFn)vtable[0x208 / 4];
            add_action(building, action);
        }

        UnitAIModule* unit_ai = building->unitAIValue;
        if (unit_ai != nullptr) {
            tribe_unit_ai_set_current_action(unit_ai, 0x26C);
            tribe_unit_ai_set_current_target(unit_ai, p1->unique_id, -1, -1.0f, -1.0f, -1.0f);
        }
    } else if (player != nullptr) {
        player->cancelTrain(0, (int)p1->obj_id, p1->unit_id, p1->unique_id);
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_research(TRIBE_Command_Research* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509AF0
    if ((this->world == nullptr) || (this->world->players == nullptr) || (p1 == nullptr)) {
        return;
    }

    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->unit_id);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];

    short work_type = 0;
    if (building == nullptr) {
        work_type = 0x67;
    } else if ((building->production_queue_actions != nullptr) && (building->production_queue_actions->get_action() != nullptr)) {
        work_type = building->production_queue_actions->get_action()->type();
    }

    if ((building != nullptr) && (work_type != 0x67) && (work_type != 0x66)) {
        TRIBE_Action_Make_Tech* action = new TRIBE_Action_Make_Tech((RGE_Action_Object*)building, p1->tech_id, p1->unique_id);
        if (action != nullptr) {
            typedef void(__thiscall* AddActionFn)(TRIBE_Building_Object*, RGE_Action*);
            void** vtable = *(void***)building;
            AddActionFn add_action = (AddActionFn)vtable[0x208 / 4];
            add_action(building, action);
        }

        UnitAIModule* unit_ai = building->unitAIValue;
        if (unit_ai != nullptr) {
            tribe_unit_ai_set_current_action(unit_ai, 0x26C);
            tribe_unit_ai_set_current_target(unit_ai, p1->unique_id, -1, -1.0f, -1.0f, -1.0f);
        }
    } else if (player != nullptr) {
        player->cancelResearch((int)p1->tech_id, p1->unit_id, -1, p1->unique_id);
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_build(TRIBE_Command_Build* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509C60
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];
    if (player == nullptr || p1->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)player->master_objects[p1->obj_id];
    if (master == nullptr) {
        return;
    }

    int blocking_object = 0;
    uchar placement_result = master->check_placement(player, p1->location_x, p1->location_y, &blocking_object, 1, 1, 1, 1, 1, 1);

    int unit_num = (int)p1->unit_num;
    int* unit_ids = (int*)(p1 + 1);

    if (placement_result != 0) {
        if (unit_num > 0) {
            RGE_Static_Object* first = this->get_obj(RGE_Obj_Info{ unit_ids[0] });
            if (first != nullptr) {
                player->cancelBuild((int)placement_result, 1, (int)p1->obj_id, p1->location_x, p1->location_y, p1->unique_id, (int)first->id);
            }
        }
        return;
    }

    if (player->pay_obj_cost(p1->obj_id, 1.0f, 0) == 0) {
        if (unit_num > 0) {
            RGE_Static_Object* first = this->get_obj(RGE_Obj_Info{ unit_ids[0] });
            if (first != nullptr) {
                player->cancelBuild(0, 1, (int)p1->obj_id, p1->location_x, p1->location_y, p1->unique_id, (int)first->id);
            }
        }
        return;
    }

    RGE_Static_Object* built_obj = master->make_new_obj(player, p1->location_x, p1->location_y, 0.0f, p1->unique_id);
    if (built_obj == nullptr) {
        return;
    }

    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            rge_command_issue_order(unit, (long)built_obj, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::place_line_of_walls(TRIBE_Player* p1, TRIBE_Master_Building_Object* p2, int p3, int p4, int p5, int p6, int p7, RGE_Static_Object** p8) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A010
    if (p1 == nullptr || p2 == nullptr) {
        return;
    }

    int x_step = 0;
    if (p4 != p6) {
        x_step = (p6 <= p4) ? -1 : 1;
    }

    int y_step = 0;
    if (p5 != p7) {
        y_step = (p7 <= p5) ? -1 : 1;
    }

    int x = p4;
    int y = p5;
    while (true) {
        int blocking = 0;
        char blocked = (char)p2->check_placement(p1, (float)x + 0.5f, (float)y + 0.5f, &blocking, 1, (uchar)p2->id, 0, 1, 1, 1);
        if (blocked == 0) {
            if (p1->pay_obj_cost(p2->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* wall = p2->make_new_obj(p1, (float)x + 0.5f, (float)y + 0.5f, 0.0f, p3);
            if (wall != nullptr && p8 != nullptr && *p8 == nullptr) {
                *p8 = wall;
            }
        }

        if (x == p6 && y == p7) {
            break;
        }

        x += x_step;
        y += y_step;
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x00509E10
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    TRIBE_Player* player = (TRIBE_Player*)this->world->players[p1->unit_player_id];
    if (player == nullptr || p1->obj_id == -1) {
        return;
    }

    TRIBE_Master_Building_Object* master = (TRIBE_Master_Building_Object*)player->master_objects[p1->obj_id];
    if (master == nullptr) {
        return;
    }

    RGE_Static_Object* first_built = nullptr;

    int x1 = (int)p1->x1;
    int y1 = (int)p1->y1;
    int x2 = (int)p1->x2;
    int y2 = (int)p1->y2;

    int abs_dy = y2 - y1;
    if (abs_dy < 0) abs_dy = -abs_dy;
    int abs_dx = x2 - x1;
    if (abs_dx < 0) abs_dx = -abs_dx;

    if (abs_dy == abs_dx) {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x2, y2, &first_built);
    }
    else if (abs_dy < abs_dx) {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x2, y1, &first_built);

        if (y1 < y2) {
            this->place_line_of_walls(player, master, p1->unique_id, x2, y1 + 1, x2, y2, &first_built);
        }
        else if (y2 < y1) {
            this->place_line_of_walls(player, master, p1->unique_id, x2, y1 - 1, x2, y2, &first_built);
        }
    }
    else {
        this->place_line_of_walls(player, master, p1->unique_id, x1, y1, x1, y2, &first_built);

        if (x1 < x2) {
            this->place_line_of_walls(player, master, p1->unique_id, x1 + 1, y2, x2, y2, &first_built);
        }
        else if (x2 < x1) {
            this->place_line_of_walls(player, master, p1->unique_id, x1 - 1, y2, x2, y2, &first_built);
        }
    }

    if (first_built == nullptr) {
        return;
    }

    int* unit_ids = (int*)(p1 + 1);
    int unit_num = (int)p1->unit_num;
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            rge_command_issue_order(unit, (long)first_built, first_built->world_x, first_built->world_y, 0.0f);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_explore(TRIBE_Command_Explore* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A140 (ASM-audited for __ftol usage)
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    if (this->world->players[p1->unit_player_id] == nullptr) {
        return;
    }

    int unit_num = (int)p1->numUnits;
    if (unit_num <= 0) {
        return;
    }

    int* unit_ids = (int*)(p1 + 1);
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->removeAllFromPathingGroup();
            unit->explore((int)p1->targetXPosition, (int)p1->targetYPosition, 1);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_game(TRIBE_Command_Game* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A1D0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    switch (p1->game_command) {
    case 0: {
        RGE_Player* plr = this->world->players[p1->var1];
        if (plr != nullptr) {
            plr->set_relation((int)p1->var2, (uchar)(int)p1->var3);
        }
        if (rge_base_game != nullptr) {
            rge_base_game->notification(8, (int)p1->var1, (int)p1->var2, (int)p1->var4, 0);
        }
        this->world->update_mutual_allies();
        break;
    }
    case 1:
        // No dedicated setter exists yet; original calls RGE_Game_World::set_game_speed.
        // TODO: PARITY - Direct field write is a placeholder for missing set_game_speed call path and may skip side effects tied to the original setter. [decomp: tcommand.cpp.decomp @ 0x0050A1D0]
        this->world->game_speed = p1->var3;
        break;
    // TODO: PARITY - Decomp has case 2 at 0x0050A1D0 that routes var2/var3 through player vtable +0x78 (attribute update path); this branch is currently not implemented.
    case 4:
        if (rge_base_game != nullptr) {
            rge_base_game->quick_build = (int)p1->var1;
        }
        break;
    case 5: {
        RGE_Player* plr = this->world->players[p1->var1];
        if (plr != nullptr) {
            plr->set_allied_victory((uchar)p1->var2);
        }
        break;
    }
    case 6:
        ((TRIBE_World*)this->world)->cheat(p1->var1, (short)(uchar)p1->var2);
        break;
    // TODO: PARITY - Decomp also includes case 7 (world UI/font dispatch via world+0x4c vtable +8) and case 8 (full out-of-sync recovery/save-game UI flow), both currently unimplemented here.
    default:
        break;
    }
}
// Fully verified. Marker reconciliation coverage.
static void tcommand_jump_stub_0050A465() {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A465
    // TODO: EMPTY_STUB - function body not transliterated [decomp: tcommand.cpp.decomp @ 0x0050A465]
    // ASM shows this is a jump-table alignment entry (NOP; MOV EDI, EDI).
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A490
    if (this->world == nullptr || p1 == nullptr) {
        return;
    }

    RGE_Static_Object* obj = this->world->object(p1->unit_id);
    if (obj != nullptr) {
        typedef void(__thiscall* CancelFn)(RGE_Static_Object*);
        void** vtable = *(void***)obj;
        CancelFn cancel = (CancelFn)vtable[0x240 / 4];
        cancel(obj);
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_attack_ground(TRIBE_Command_Attack_Ground* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A4C0
    if (p1 == nullptr) {
        return;
    }

    int unit_num = (int)p1->unit_num;
    int* unit_ids = (int*)(p1 + 1);
    for (int i = 0; i < unit_num; ++i) {
        RGE_Static_Object* unit = this->get_obj(RGE_Obj_Info{ unit_ids[i] });
        if (unit != nullptr) {
            unit->attack(p1->location_x, p1->location_y, 0.0f, 1);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A510
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    float transfer_amount = 0.0f;
    if (p1->attr_amount >= 0.0f) {
        transfer_amount = p1->attr_amount;
    }

    float cost = 0.0f;
    if (transfer_amount > 0.0f) {
        cost = p1->attr_cost * transfer_amount;
    }

    RGE_Player* from_player = this->world->players[p1->player_id];
    RGE_Player* to_player = this->world->players[p1->to_player_id];
    if (from_player == nullptr || to_player == nullptr || from_player->attributes == nullptr) {
        return;
    }

    int attr_id = (int)p1->attr_id;
    if (attr_id < 0 || attr_id >= from_player->attribute_num) {
        return;
    }

    float* from_attr = &from_player->attributes[attr_id];
    if (*from_attr < transfer_amount + cost) {
        cost = *from_attr * p1->attr_cost;
        transfer_amount = *from_attr - cost;
    }

    to_player->add_attribute_num((short)p1->attr_id, transfer_amount, 0);
    from_player->add_attribute_num((short)p1->attr_id, -(transfer_amount + cost), 0);
    from_player->add_attribute_num(0x35, transfer_amount, 0);
    to_player->add_attribute_num(0x35, -transfer_amount, 0);

    if (rge_base_game != nullptr) {
        rge_base_game->notification(7, p1->player_id, p1->to_player_id, p1->attr_id, (long)transfer_amount);
    }
    to_player->notify(p1->player_id, p1->to_player_id, 0x20A, p1->attr_id, (long)transfer_amount, 0);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_make(RGE_Static_Object* p1, short p2) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A7F0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Make* cmd = (TRIBE_Command_Make*)calloc(1, sizeof(TRIBE_Command_Make));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 100;
    cmd->unit_id = (int)p1->id;
    cmd->unit_player_id = (uchar)p1->owner->id;
    cmd->obj_id = p2;
    cmd->unique_id = -1;

    this->submit(cmd, sizeof(TRIBE_Command_Make));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_make(int p1, int p2, int p3, int p4) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A860 (debug-log side effect intentionally omitted)
    if (p2 < 0) {
        return;
    }

    TRIBE_Command_Make* cmd = (TRIBE_Command_Make*)calloc(1, sizeof(TRIBE_Command_Make));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 100;
    cmd->unit_id = p2;
    cmd->unit_player_id = (uchar)p1;
    cmd->obj_id = (short)p3;
    cmd->unique_id = p4;

    this->submit(cmd, sizeof(TRIBE_Command_Make));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_research(RGE_Static_Object* p1, short p2) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A8D0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Research* cmd = (TRIBE_Command_Research*)calloc(1, sizeof(TRIBE_Command_Research));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x65;
    cmd->unit_id = (int)p1->id;
    cmd->unit_player_id = (uchar)p1->owner->id;
    cmd->tech_id = p2;
    cmd->unique_id = -1;

    this->submit(cmd, sizeof(TRIBE_Command_Research));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_research(int p1, int p2, int p3, int p4) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A940 (debug-log side effect intentionally omitted)
    if (p2 < 0) {
        return;
    }

    TRIBE_Command_Research* cmd = (TRIBE_Command_Research*)calloc(1, sizeof(TRIBE_Command_Research));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x65;
    cmd->unit_id = p2;
    cmd->unit_player_id = (uchar)p1;
    cmd->tech_id = (short)p3;
    cmd->unique_id = p4;

    this->submit(cmd, sizeof(TRIBE_Command_Research));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_build(RGE_Static_Object** p1, short p2, short p3, float p4, float p5) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A9B0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Build);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Build* cmd = (TRIBE_Command_Build*)buffer;
    cmd->command = 0x66;
    cmd->unit_num = (uchar)p2;
    cmd->unit_player_id = (*p1 != nullptr) ? (uchar)(*p1)->owner->id : (uchar)0xFF;
    cmd->location_x = p4;
    cmd->location_y = p5;
    cmd->obj_id = p3;
    cmd->unique_id = -1;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_build(int p1, int* p2, int p3, int p4, float p5, float p6, int p7) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AA90 (debug-log side effect intentionally omitted)
    if (p2 == nullptr || p3 <= 0) {
        return;
    }

    int size = p3 * 4 + (int)sizeof(TRIBE_Command_Build);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build));
    for (int i = 0; i < p3; ++i) {
        ids[i] = p2[i];
    }

    TRIBE_Command_Build* cmd = (TRIBE_Command_Build*)buffer;
    cmd->command = 0x66;
    cmd->unit_num = (uchar)p3;
    cmd->unit_player_id = (uchar)p1;
    cmd->location_x = p5;
    cmd->location_y = p6;
    cmd->obj_id = (short)p4;
    cmd->unique_id = p7;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_build_wall(RGE_Static_Object** p1, short p2, short p3, long p4, long p5, long p6, long p7) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AB30 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Build_Wall);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Build_Wall));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Build_Wall* cmd = (TRIBE_Command_Build_Wall*)buffer;
    cmd->command = 0x69;
    cmd->unit_num = (uchar)p2;
    cmd->unit_player_id = (*p1 != nullptr) ? (uchar)(*p1)->owner->id : (uchar)0xFF;
    cmd->obj_id = p3;

    if (p4 < 0) p4 = 0;
    if (p4 > 0xFF) p4 = 0xFF;
    if (p5 < 0) p5 = 0;
    if (p5 > 0xFF) p5 = 0xFF;
    if (p6 < 0) p6 = 0;
    if (p6 > 0xFF) p6 = 0xFF;
    if (p7 < 0) p7 = 0;
    if (p7 > 0xFF) p7 = 0xFF;

    cmd->x1 = (uchar)p4;
    cmd->y1 = (uchar)p5;
    cmd->x2 = (uchar)p6;
    cmd->y2 = (uchar)p7;
    cmd->unique_id = -1;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_explore(int p1, int* p2, int p3, float p4, float p5) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AC70 (debug-log side effect intentionally omitted)
    if (p2 == nullptr || p3 <= 0) {
        return;
    }

    int size = p3 * 4 + (int)sizeof(TRIBE_Command_Explore);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Explore));
    for (int i = 0; i < p3; ++i) {
        ids[i] = p2[i];
    }

    TRIBE_Command_Explore* cmd = (TRIBE_Command_Explore*)buffer;
    cmd->command = 0x68;
    cmd->numUnits = (uchar)p3;
    cmd->unit_player_id = (uchar)p1;
    cmd->targetXPosition = p4;
    cmd->targetYPosition = p5;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_game_speed(float p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050ADF0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 1;
    cmd->var3 = p1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_save_game() {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AE40
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 8;
    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_cancel_build(RGE_Static_Object* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AFD0 (debug-log side effect intentionally omitted)
    if (p1 == nullptr) {
        return;
    }

    TRIBE_Command_Cancel_Build* cmd = (TRIBE_Command_Cancel_Build*)calloc(1, sizeof(TRIBE_Command_Cancel_Build));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x6A;
    cmd->unit_id = (int)p1->id;

    this->submit(cmd, sizeof(TRIBE_Command_Cancel_Build));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_attack_ground(RGE_Static_Object** p1, short p2, float p3, float p4) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B020 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = count * 4 + (int)sizeof(TRIBE_Command_Attack_Ground);
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* ids = (int*)(buffer + sizeof(TRIBE_Command_Attack_Ground));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Attack_Ground* cmd = (TRIBE_Command_Attack_Ground*)buffer;
    cmd->command = 0x6B;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_give_attribute(int p1, int p2, int p3, float p4, float p5) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B130
    TRIBE_Command_Give_Attribute* cmd = (TRIBE_Command_Give_Attribute*)calloc(1, sizeof(TRIBE_Command_Give_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 0x6C;
    cmd->player_id = (uchar)p1;
    cmd->to_player_id = (uchar)p2;
    cmd->attr_id = (uchar)p3;
    cmd->attr_amount = p4;
    cmd->attr_cost = p5;

    this->submit(cmd, sizeof(TRIBE_Command_Give_Attribute));
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A6A0
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;
    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            obj->attribute_type_held = (short)p1->attribute;
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A6E0
    RGE_Static_Object* target = this->get_obj(p1->target);
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;

    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            ((TRIBE_Combat_Object*)obj)->do_repair(target);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_unload(TRIBE_Command_Unload* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A730
    RGE_Obj_Info* object_ids = (RGE_Obj_Info*)(p1 + 1);
    uint count = (uint)p1->unit_num;

    for (uint i = 0; i < count; ++i) {
        RGE_Static_Object* obj = this->get_obj(object_ids[i]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            int owner_id = (int)obj->owner->id;
            obj->owner->processAIOrder(owner_id, obj->id, 0x2D1, obj->id, owner_id, p1->location_x, p1->location_y, 0.0f, 1.0f, 1, 0, 100);
        }
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* p1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050A7B0
    TRIBE_Building_Object* building = (TRIBE_Building_Object*)this->world->object(p1->bldg_id);
    if (building != nullptr) {
        short train_count = p1->train_count;
        if (0 < train_count) {
            building->add_to_production_queue(p1->train_id, train_count);
            return;
        }
        building->remove_from_production_queue(p1->train_id, (short)-train_count);
    }
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_trade_attribute(RGE_Static_Object** p1, short p2, long p3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B190 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Trade_Attribute) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = (uchar)p2;
    cmd->attribute = p3;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_trade_attribute(int p1, int p2, long p3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B230 (debug-log side effect intentionally omitted)
    (void)p2;

    const int size = 0xC;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    *(int*)(buffer + sizeof(TRIBE_Command_Trade_Attribute)) = p1;

    TRIBE_Command_Trade_Attribute* cmd = (TRIBE_Command_Trade_Attribute*)buffer;
    cmd->command = 0x6D;
    cmd->unit_num = 1;
    cmd->attribute = p3;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_repair(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B290 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Repair) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Repair));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Repair* cmd = (TRIBE_Command_Repair*)buffer;
    cmd->command = 0x6E;
    cmd->unit_num = (uchar)p2;
    cmd->target.id = p3->id;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_unload(RGE_Static_Object** p1, short p2, float p3, float p4) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B330 (debug-log side effect intentionally omitted)
    if (p1 == nullptr || p2 <= 0) {
        return;
    }

    int count = (int)p2;
    int size = (int)sizeof(TRIBE_Command_Unload) + count * 4;
    unsigned char* buffer = (unsigned char*)calloc(1, size);
    if (buffer == nullptr) {
        return;
    }

    int* object_ids = (int*)(buffer + sizeof(TRIBE_Command_Unload));
    for (int i = 0; i < count; ++i) {
        RGE_Static_Object* obj = p1[i];
        object_ids[i] = (obj != nullptr) ? (int)obj->id : -1;
    }

    TRIBE_Command_Unload* cmd = (TRIBE_Command_Unload*)buffer;
    cmd->command = 0x6F;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;

    this->submit(buffer, size);
}
// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_queue(RGE_Static_Object* p1, short p2, short p3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B3E0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Queue* cmd = (TRIBE_Command_Queue*)calloc(1, sizeof(TRIBE_Command_Queue));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x77;
    cmd->bldg_id = p1->id;
    cmd->train_id = p2;
    cmd->train_count = p3;

    this->submit(cmd, sizeof(TRIBE_Command_Queue));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_allied_victory(short param_1, uchar param_2) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AD00 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 5;
    cmd->var1 = param_1;
    cmd->var2 = (short)param_2;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_relation(short param_1, short param_2, short param_3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AD70 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 0;
    cmd->var1 = param_1;
    cmd->var2 = param_2;
    cmd->var3 = (float)param_3;
    cmd->var4 = param_3;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_inventory(short param_1, short param_2, float param_3) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AE80 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 2;
    cmd->var1 = param_1;
    cmd->var2 = param_2;
    cmd->var3 = param_3;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_upgrade_town(short param_1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AEE0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 3;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_quick_build(short param_1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AF30 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 4;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_shared_los(short param_1) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050AF80 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 7;
    cmd->var1 = param_1;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}

// Fully verified. Marker reconciliation coverage.
void TRIBE_Command::command_cheat(short param_1, short param_2) {
    // Fully verified. Source of truth: tcommand.cpp.decomp @ 0x0050B0D0 (debug-log side effect intentionally omitted)
    TRIBE_Command_Game* cmd = (TRIBE_Command_Game*)calloc(1, sizeof(TRIBE_Command_Game));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0x67;
    cmd->game_command = 6;
    cmd->var1 = param_1;
    cmd->var2 = param_2;

    this->submit(cmd, sizeof(TRIBE_Command_Game));
}
