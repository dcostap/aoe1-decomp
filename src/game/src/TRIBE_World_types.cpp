// Implementations for types used by TRIBE_World init overrides.
#include "../include/TRIBE_Map.h"
#include "../include/TRIBE_World.h"
#include "../include/TRIBE_RMM_Database_Controller.h"
#include "../include/custom_debug.h"
#include "../include/TRIBE_Command.h"
#include "../include/RGE_Obj_Info.h"
#include "../include/RGE_Command_Create.h"
#include "../include/RGE_Command_Add_Attribute.h"
#include "../include/RGE_Command_Give_Attribute.h"
#include "../include/RGE_Command_Stop.h"
#include "../include/RGE_Command_Pause.h"
#include "../include/RGE_Command_Order.h"
#include "../include/RGE_Command_Formation.h"
#include "../include/RGE_Command_Create_Group.h"
#include "../include/RGE_Command_Destroy_Group.h"
#include "../include/RGE_Command_Add_To_Group.h"
#include "../include/RGE_Command_Remove_From_Group.h"
#include "../include/RGE_Command_Add_Waypoint.h"
#include "../include/RGE_Command_Group_Waypoint.h"
#include "../include/RGE_Command_AI_Order.h"
#include "../include/RGE_Command_Group_AI_Order.h"
#include "../include/RGE_Command_Resign.h"
#include "../include/TRIBE_Command_Give_Attribute.h"
#include "../include/TRIBE_Command_Trade_Attribute.h"
#include "../include/TRIBE_Command_Repair.h"
#include "../include/TRIBE_Command_Queue.h"
#include "../include/TRIBE_Command_Unload.h"
#include "../include/TRIBE_Command_Make.h"
#include "../include/TRIBE_Command_Research.h"
#include "../include/TRIBE_Action_Make_Obj.h"
#include "../include/TRIBE_Action_Make_Tech.h"
#include "../include/TRIBE_Command_Build.h"
#include "../include/TRIBE_Command_Game.h"
#include "../include/TRIBE_Command_Explore.h"
#include "../include/TRIBE_Command_Build_Wall.h"
#include "../include/TRIBE_Command_Cancel_Build.h"
#include "../include/TRIBE_Command_Attack_Ground.h"
#include "../include/TRIBE_Building_Object.h"
#include "../include/Production_Queue_Record.h"
#include "../include/TRIBE_Master_Building_Object.h"
#include "../include/TRIBE_Effects.h"
#include "../include/T_Scenario.h"
#include "../include/RGE_Scenario_Header.h"
#include "../include/TRIBE_Scenario_Header.h"
#include "../include/RGE_Effect.h"
#include "../include/RGE_Effect_Command.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TRIBE_Player.h"
#include "../include/RGE_Victory_Conditions.h"
#include "../include/TRIBE_Victory_Conditions.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Object_Node.h"
#include "../include/RGE_Action_List.h"
#include "../include/RGE_Action.h"
#include "../include/RGE_Task.h"
#include "../include/RGE_Task_List.h"
#include "../include/RGE_Master_Action_Object.h"
#include "../include/RGE_Timeline.h"
#include "../include/TPicture.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


// --- RGE_Command (base class) ---
static uchar rge_duplicate_check_command_order(const RGE_Command* command_owner, const uchar* command_data) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00435110
    const uchar* last_order = command_owner->last_order;
    const uint unit_count = (uint)command_data[8];

    if (unit_count != (uint)last_order[8]) {
        return 0;
    }

    const long current_x = (long)(*(const float*)(command_data + 0x0C));
    const long last_x = (long)(*(const float*)(last_order + 0x0C));
    if (current_x != last_x) {
        return 0;
    }

    const long current_y = (long)(*(const float*)(command_data + 0x10));
    const long last_y = (long)(*(const float*)(last_order + 0x10));
    if (current_y != last_y) {
        return 0;
    }

    if (*(const long*)(last_order + 4) != *(const long*)(command_data + 4)) {
        return 0;
    }

    const long* current_units = (const long*)(command_data + 0x14);
    const long* last_units = (const long*)(last_order + 0x14);
    for (uint i = 0; i < unit_count; ++i) {
        if (current_units[i] != last_units[i]) {
            return 0;
        }
    }

    return 1;
}

static uchar rge_duplicate_check_command_stop(const RGE_Command* command_owner, const uchar* command_data) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x004351B0
    const uchar* last_order = command_owner->last_order;
    const uint unit_count = (uint)command_data[1];

    if (unit_count != (uint)last_order[1]) {
        return 0;
    }

    const long* current_units = (const long*)(command_data + 2);
    const long* last_units = (const long*)(last_order + 2);
    for (uint i = 0; i < unit_count; ++i) {
        if (current_units[i] != last_units[i]) {
            return 0;
        }
    }

    return 1;
}

static uchar rge_close_check_for_duplicate_orders(const RGE_Command* command_owner, const uchar* command_data) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00435210
    switch (command_data[0]) {
    case 0:
    case 2:
    case 3:
        return rge_duplicate_check_command_order(command_owner, command_data);
    case 1:
        return rge_duplicate_check_command_stop(command_owner, command_data);
    default:
        return 0;
    }
}

static uchar rge_check_for_duplicate_orders(const RGE_Command* command_owner, const uchar* command_data, long command_size) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00435260
    if ((command_owner->last_order != nullptr) &&
        (command_owner->last_order_size == command_size) &&
        (command_owner->last_order[0] == command_data[0])) {
        const ulong now = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Command.cpp", 0x497);
        if ((long)(now - (ulong)command_owner->last_order_time) < 500) {
            return rge_close_check_for_duplicate_orders(command_owner, command_data);
        }
    }

    return 0;
}

static void rge_command_set_waiting_to_move(RGE_Static_Object* obj, int waiting_value) {
    // Fully verified. Source of truth: command.cpp.decomp (helper implementation).
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* SetWaitingToMoveFn)(RGE_Static_Object*, int);
    void** vtable = *(void***)obj;
    SetWaitingToMoveFn fn = (SetWaitingToMoveFn)vtable[0x12C / 4];
    fn(obj, waiting_value);
}

static void rge_command_issue_work(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    // Fully verified. Source of truth: command.cpp.decomp (helper implementation).
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* WorkFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    WorkFn fn = (WorkFn)vtable[0xA0 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_move_to(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    // Fully verified. Source of truth: command.cpp.decomp (helper implementation).
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* MoveToFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    MoveToFn fn = (MoveToFn)vtable[0x9C / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_order(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    // Fully verified. Source of truth: command.cpp.decomp (helper implementation).
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* OrderFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    OrderFn fn = (OrderFn)vtable[0x98 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_set_move_ai_state(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    if (unit_ai == nullptr) {
        return;
    }

    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x28) = 0x2C6;
    *(int*)(ai + 0x30) = 0x262;
    *(int*)(ai + 0x34) = target_id;
    *(int*)(ai + 0x38) = target_type;
    *(float*)(ai + 0x3C) = target_x;
    *(float*)(ai + 0x40) = target_y;
    *(float*)(ai + 0x44) = 0.0f;
    *(float*)(ai + 0x48) = 0.0f;
}

struct tribe_unit_ai_notify_event {
    long caller;
    long recipient;
    long mType;
    long p1;
    long p2;
    long p3;
};

static void tribe_unit_ai_set_current_order(UnitAIModule* unit_ai, int order_value) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x50) = *(int*)(ai + 0x28);
    *(int*)(ai + 0x28) = order_value;
}

static void tribe_unit_ai_set_current_action(UnitAIModule* unit_ai, int action_value) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x54) = *(int*)(ai + 0x30);
    *(int*)(ai + 0x30) = action_value;
}

static void tribe_unit_ai_set_current_target(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y, float target_z) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
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

static void tribe_unit_ai_remove_current_target(UnitAIModule* unit_ai) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    int current_target_type = *(int*)(ai + 0x38);
    *(int*)(ai + 0x58) = *(int*)(ai + 0x34);
    *(int*)(ai + 0x34) = -1;
    *(int*)(ai + 0x38) = -1;
    *(int*)(ai + 0x5C) = current_target_type;
    *(float*)(ai + 0x3C) = -1.0f;
    *(float*)(ai + 0x40) = -1.0f;
    *(float*)(ai + 0x44) = -1.0f;
}

static void tribe_unit_ai_purge_notify_queue(UnitAIModule* unit_ai, ulong update_time) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    if (unit_ai == nullptr) {
        return;
    }

    unsigned char* ai = (unsigned char*)unit_ai;
    int notify_count = *(int*)(ai + 0x1C);
    if (0 < notify_count) {
        tribe_unit_ai_notify_event* notify_queue = (tribe_unit_ai_notify_event*)(*(void**)(ai + 0x24));
        for (int i = 0; i < notify_count; ++i) {
            int queued_action = (int)notify_queue[i].p1;
            int current_action = *(int*)(ai + 0x30);
            int current_order = *(int*)(ai + 0x28);

            if ((notify_queue[i].mType == 0x1FA) &&
                (((queued_action != 0x262) || (current_action == 0x262)) || (current_action == 0x268)) &&
                ((current_order == -1) && (current_action == queued_action))) {
                tribe_unit_ai_remove_current_target(unit_ai);
                typedef int(__thiscall* StopObjectFn)(UnitAIModule*, int);
                void** vtable = *(void***)unit_ai;
                StopObjectFn stop_object = (StopObjectFn)vtable[0x58 / 4];
                stop_object(unit_ai, 1);
                break;
            }
        }
    }

    *(int*)(ai + 0x1C) = 0;
    *(ulong*)(ai + 0xF4) = update_time;
}

static void tribe_unit_ai_set_tasked_by_player(UnitAIModule* unit_ai) {
    // Fully verified. Source of truth: tcommand.cpp.decomp (helper implementation).
    tribe_unit_ai_purge_notify_queue(unit_ai, 0);
}

static int rge_scenario_active_player_count(const RGE_Scenario* scenario) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp (helper implementation).
    if (scenario == nullptr) {
        return 0;
    }

    int count = 0;
    for (int i = 0; i < 16; ++i) {
        if (scenario->PlActive[i] != 0) {
            count = count + 1;
        }
    }
    return count;
}

static int tribe_scenario_any_sp_victory(const T_Scenario* scenario) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp (helper implementation).
    if (scenario == nullptr) {
        return 0;
    }

    for (int player = 0; player < 16; ++player) {
        if (scenario->PlActive[player] == 0) {
            continue;
        }
        for (int slot = 0; slot < 12; ++slot) {
            if (scenario->sp_victory[player][slot].VictoryType != 0) {
                return 1;
            }
        }
    }
    return 0;
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(T_Scenario* scenario)
    : RGE_Scenario_Header((RGE_Scenario*)scenario) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052A990
    this->any_sp_victory = tribe_scenario_any_sp_victory(scenario);
    this->active_player_count = rge_scenario_active_player_count((RGE_Scenario*)scenario);
}

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int p1)
    : RGE_Scenario_Header(p1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052A9F0
    this->any_sp_victory = 0;
    this->active_player_count = 0;
    if (this->error_code == 0) {
        rge_read(p1, &this->any_sp_victory, 4);
        rge_read(p1, &this->active_player_count, 4);
    }
}

long TRIBE_Scenario_Header::get_size() {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052AA70
    return RGE_Scenario_Header::get_size() + 8;
}

void TRIBE_Scenario_Header::save(int p1) {
    // Fully verified. Source of truth: tscenaro.cpp.decomp @ 0x0052AA80
    RGE_Scenario_Header::save(p1);
    rge_write(p1, &this->any_sp_victory, 4);
    rge_write(p1, &this->active_player_count, 4);
}

TRIBE_Effects::TRIBE_Effects(int param_1)
    : RGE_Effects(param_1) {
    // Fully verified. Source of truth: teffects.cpp.decomp @ 0x0050D460
    // Just delegates to base class constructor
}

TRIBE_Effects::TRIBE_Effects(char* param_1)
    : RGE_Effects(param_1) {
    // Fully verified. Source of truth: teffects.cpp.decomp @ 0x0050D4B0
}

TRIBE_Effects::~TRIBE_Effects() {
    // Fully verified. Source of truth: bucket_050D.cpp.decomp @ 0x0050D4A0
    // Base class destructor handles cleanup
}

void TRIBE_Effects::save(int p1) {
    // Delegates to base class
    RGE_Effects::save(p1);
}

void TRIBE_Effects::do_effect(short p1, RGE_Player* p2) {
    // Fully verified. Source of truth: teffects.cpp.decomp @ 0x0050D4D0
    if ((int)p1 < 0 || (int)p1 >= this->effect_num || this->effects == nullptr) return;
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) return;
    // TRIBE-specific: process tech-enable/disable effect commands before base do_effect.
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        if (cmd != nullptr && cmd->command == 'f' && p2 != nullptr) {
            ((TRIBE_Player*)p2)->tech_abling((long)cmd->change_amount, 0);
        }
    }
    RGE_Effects::do_effect(p1, p2);
}

void TRIBE_Effects::do_tech_effect(short p1, RGE_Player* p2) {
    // Fully verified. Source of truth: teffects.cpp.decomp @ 0x0050D550
    if ((int)p1 < 0 || (int)p1 >= this->effect_num) {
        return;
    }
    RGE_Effect* eff = &this->effects[p1];
    if (eff == nullptr) {
        return;
    }
    for (short i = 0; i < eff->effect_list_num; i++) {
        RGE_Effect_Command* cmd = &eff->effect_list[i];
        if (cmd != nullptr && cmd->command == 'f' && p2 != nullptr) {
            ((TRIBE_Player*)p2)->tech_abling((long)cmd->change_amount, 0);
        }
    }
}

// --- RGE_Tile_List ---
#include "../include/RGE_Tile_List.h"
#include "../include/RGE_Tile_List_Node.h"

RGE_Tile_List::RGE_Tile_List(int param_1) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471E40
    this->list = (RGE_Tile_List_Node*)calloc(param_1, sizeof(RGE_Tile_List_Node));
    this->list_size = param_1;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

RGE_Tile_List::~RGE_Tile_List() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471E70
    if (this->list != nullptr) {
        free(this->list);
    }
}

void RGE_Tile_List::add_node(int param_1, int param_2) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471D70
    if (this->num_active >= this->list_size) {
        int new_size = this->list_size * 2;
        RGE_Tile_List_Node* new_list = (RGE_Tile_List_Node*)calloc(new_size, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, this->list, this->list_size * sizeof(RGE_Tile_List_Node));
        free(this->list);
        this->list = new_list;
        this->list_size = new_size;
    }
    this->list[this->num_active].col = param_1;
    this->list[this->num_active].row = param_2;
    this->num_active++;
    this->new_count++;
}

void RGE_Tile_List::del_list() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471DF0
    this->num_active = 0;
    this->new_count = 0;
    if (this->collapse_list != 0) {
        free(this->list);
        this->list_size = 8;
        this->list = (RGE_Tile_List_Node*)calloc(8, sizeof(RGE_Tile_List_Node));
        this->collapse_list = 0;
    }
}

void RGE_Tile_List::get_list_info(RGE_Tile_List_Node** param_1, int* param_2) {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471E90
    if (param_1 != nullptr) {
        *param_1 = this->list;
    }
    if (param_2 != nullptr) {
        *param_2 = this->num_active;
    }
}

int RGE_Tile_List::get_new_count() {
    // Fully verified. Source of truth: player.cpp.decomp @ 0x00471EB0
    int count = this->new_count;
    this->new_count = 0;
    return count;
}


