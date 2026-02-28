#include "../include/RGE_Command.h"
#include "../include/TRIBE_World.h"
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
#include "../include/TCommunications_Handler.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include <math.h>
#include <stdlib.h>

// --- RGE_Command (base class) ---
static uchar rge_duplicate_check_command_order(const RGE_Command* command_owner, const uchar* command_data) {
    // Source of truth: command.cpp.decomp @ 0x00435110
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
    // Source of truth: command.cpp.decomp @ 0x004351B0
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
    // Source of truth: command.cpp.decomp @ 0x00435210
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
    // Source of truth: command.cpp.decomp @ 0x00435260
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
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* SetWaitingToMoveFn)(RGE_Static_Object*, int);
    void** vtable = *(void***)obj;
    SetWaitingToMoveFn fn = (SetWaitingToMoveFn)vtable[0x12C / 4];
    fn(obj, waiting_value);
}

static void rge_command_issue_work(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* WorkFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    WorkFn fn = (WorkFn)vtable[0xA0 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_move_to(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* MoveToFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    MoveToFn fn = (MoveToFn)vtable[0x9C / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_issue_order(RGE_Static_Object* obj, long target_value, float x, float y, float z) {
    if (obj == nullptr) {
        return;
    }

    typedef void(__thiscall* OrderFn)(RGE_Static_Object*, long, float, float, float);
    void** vtable = *(void***)obj;
    OrderFn fn = (OrderFn)vtable[0x98 / 4];
    fn(obj, target_value, x, y, z);
}

static void rge_command_set_move_ai_state(UnitAIModule* unit_ai, int target_id, int target_type, float target_x, float target_y) {
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
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x50) = *(int*)(ai + 0x28);
    *(int*)(ai + 0x28) = order_value;
}

static void tribe_unit_ai_set_current_action(UnitAIModule* unit_ai, int action_value) {
    if (unit_ai == nullptr) {
        return;
    }
    unsigned char* ai = (unsigned char*)unit_ai;
    *(int*)(ai + 0x54) = *(int*)(ai + 0x30);
    *(int*)(ai + 0x30) = action_value;
}

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

static void tribe_unit_ai_remove_current_target(UnitAIModule* unit_ai) {
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
    tribe_unit_ai_purge_notify_queue(unit_ai, 0);
}

RGE_Command::RGE_Command(RGE_Game_World* param_1, TCommunications_Handler* param_2) {
    // Source of truth: Command.cpp.decomp @ 0x00433D40
    this->world = param_1;
    this->com_hand = param_2;
    this->last_order = nullptr;
    this->last_order_size = 0;
}

void RGE_Command::reset_communications(TCommunications_Handler* param_1) {
    // Source of truth: Command.cpp.decomp @ 0x00433DB0
    this->com_hand = param_1;
}

RGE_Static_Object* RGE_Command::get_obj(RGE_Obj_Info p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433DC0
    if (p1.id == -1) {
        return nullptr;
    }
    return this->world->object((int)p1.id);
}

void RGE_Command::do_commands() {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433DE0
    if (this->com_hand == nullptr) {
        return;
    }

    void* command_data = this->com_hand->get_command();
    while (command_data != nullptr) {
        this->do_command(command_data);
        ::operator delete(command_data);
        command_data = this->com_hand->get_command();
    }
}

void RGE_Command::submit(void* p1, long p2) {
    // Source of truth: command.cpp.decomp @ 0x004352C0
    uchar duplicate_order = rge_check_for_duplicate_orders(this, (uchar*)p1, p2);
    if (duplicate_order == 0) {
        this->com_hand->new_command(p1, (int)p2);
    }

    if (this->last_order != nullptr) {
        free(this->last_order);
        this->last_order = nullptr;
    }
    this->last_order = (unsigned char*)p1;
    this->last_order_size = p2;
    this->last_order_time = (long)debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\Command.cpp", 0x4AC);
}

RGE_Command::~RGE_Command() {
    // Source of truth: Command.cpp.decomp @ 0x00433D90
    this->world = nullptr;
    this->com_hand = nullptr;
    if (this->last_order) {
        free(this->last_order);
        this->last_order = nullptr;
    }
}
void RGE_Command::do_command_create(RGE_Command_Create* p1) {
    // Source of truth: command.cpp.decomp @ 0x004348B0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }
    RGE_Player* player = this->world->players[p1->player_id];
    if (player == nullptr) {
        return;
    }
    player->make_new_object((long)p1->obj_catagory, p1->location_x, p1->location_y, p1->location_z, 0);
}
void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* p1) {
    // Source of truth: command.cpp.decomp @ 0x004348F0
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }
    RGE_Player* player = this->world->players[p1->player_id];
    if (player == nullptr) {
        return;
    }
    player->add_attribute_num((short)p1->attr_id, p1->attr_amount, 0);
}
void RGE_Command::do_command_order(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00433F20
    int unit_num = (int)p1->unit_num;
    float unit_num_float = (float)unit_num;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    RGE_Static_Object* target = this->get_obj(p1->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        for (int i = 0; i < unit_num; ++i) {
            RGE_Static_Object* obj = this->get_obj(units[i]);
            if (obj != nullptr) {
                if (min_x <= obj->world_x) {
                    if (max_x < obj->world_x) {
                        max_x = obj->world_x;
                    }
                } else {
                    min_x = obj->world_x;
                }

                if (min_y <= obj->world_y) {
                    if (max_y < obj->world_y) {
                        max_y = obj->world_y;
                    }
                } else {
                    min_y = obj->world_y;
                }

                total_x = total_x + obj->world_x;
                total_y = total_y + obj->world_y;
            }
        }

        if (((max_x - min_x) <= 8.0f) && ((max_y - min_y) <= 8.0f)) {
            if (unit_num_float == 0.0f) {
                return;
            }

            float center_x = total_x / unit_num_float;
            float center_y = total_y / unit_num_float;

            for (int index = 0; index < unit_num; ++index) {
                RGE_Static_Object* obj = this->get_obj(units[index]);
                if (obj != nullptr) {
                    obj->removeAllFromPathingGroup();
                    rge_command_set_waiting_to_move(obj, 1);

                    for (int group_index = 0; group_index < unit_num; ++group_index) {
                        if (group_index != index) {
                            obj->addToPathingGroup((int)units[group_index].id);
                        }
                    }

                    float adjusted_x = (obj->world_x - center_x) + p1->location_x;
                    float adjusted_y = (obj->world_y - center_y) + p1->location_y;

                    if (adjusted_x >= 0.0f) {
                        float map_width = (float)obj->owner->world->map->map_width;
                        if (map_width <= adjusted_x) {
                            adjusted_x = map_width - 1.0f;
                        }
                    } else {
                        adjusted_x = 1.0f;
                    }

                    if (adjusted_y >= 0.0f) {
                        float map_height = (float)obj->owner->world->map->map_height;
                        if (map_height <= adjusted_y) {
                            adjusted_y = map_height - 1.0f;
                        }
                    } else {
                        adjusted_y = 1.0f;
                    }

                    long order_target = 0;
                    if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                        order_target = (long)target;
                    }

                    rge_command_issue_order(obj, order_target, adjusted_x, adjusted_y, 0.0f);
                }
            }
            return;
        }
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int group_index = 0; group_index < unit_num; ++group_index) {
                if (group_index != index) {
                    obj->addToPathingGroup((int)units[group_index].id);
                }
            }

            rge_command_issue_order(obj, (long)target, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
void RGE_Command::do_command_work(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434320
    int unit_num = (int)p1->unit_num;
    RGE_Static_Object* target = this->get_obj(p1->target);
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int i = 0; i < unit_num; ++i) {
                if (i != index) {
                    obj->addToPathingGroup((int)units[i].id);
                }
            }

            rge_command_issue_work(obj, (long)target, p1->location_x, p1->location_y, 0.0f);
        }
    }
}
void RGE_Command::do_command_move(RGE_Command_Order* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434400
    int unit_num = (int)p1->unit_num;
    float unit_num_float = (float)unit_num;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    RGE_Static_Object* target = this->get_obj(p1->target);

    if (unit_num > 1) {
        float min_x = 10000.0f;
        float max_x = 0.0f;
        float min_y = 10000.0f;
        float max_y = 0.0f;
        float total_x = 0.0f;
        float total_y = 0.0f;

        for (int i = 0; i < unit_num; ++i) {
            RGE_Static_Object* obj = this->get_obj(units[i]);
            if (obj != nullptr) {
                if (min_x <= obj->world_x) {
                    if (max_x < obj->world_x) {
                        max_x = obj->world_x;
                    }
                } else {
                    min_x = obj->world_x;
                }

                if (min_y <= obj->world_y) {
                    if (max_y < obj->world_y) {
                        max_y = obj->world_y;
                    }
                } else {
                    min_y = obj->world_y;
                }

                total_x = total_x + obj->world_x;
                total_y = total_y + obj->world_y;
            }
        }

        if (((max_x - min_x) <= 8.0f) && ((max_y - min_y) <= 8.0f)) {
            if (unit_num_float == 0.0f) {
                return;
            }

            float center_x = total_x / unit_num_float;
            float center_y = total_y / unit_num_float;

            for (int index = 0; index < unit_num; ++index) {
                RGE_Static_Object* obj = this->get_obj(units[index]);
                if (obj != nullptr) {
                    obj->removeAllFromPathingGroup();
                    rge_command_set_waiting_to_move(obj, 1);

                    for (int group_index = 0; group_index < unit_num; ++group_index) {
                        if (group_index != index) {
                            obj->addToPathingGroup((int)units[group_index].id);
                        }
                    }

                    float adjusted_x = (obj->world_x - center_x) + p1->location_x;
                    float adjusted_y = (obj->world_y - center_y) + p1->location_y;

                    if (adjusted_x >= 0.0f) {
                        float map_width = (float)obj->owner->world->map->map_width;
                        if (map_width <= adjusted_x) {
                            adjusted_x = map_width - 1.0f;
                        }
                    } else {
                        adjusted_x = 1.0f;
                    }

                    if (adjusted_y >= 0.0f) {
                        float map_height = (float)obj->owner->world->map->map_height;
                        if (map_height <= adjusted_y) {
                            adjusted_y = map_height - 1.0f;
                        }
                    } else {
                        adjusted_y = 1.0f;
                    }

                    long move_target = (long)target;
                    if ((target == nullptr) || ((target->master_obj->radius_x <= 0.0f) && (target->master_obj->radius_y <= 0.0f))) {
                        move_target = 0;
                    }
                    rge_command_issue_move_to(obj, move_target, adjusted_x, adjusted_y, 0.0f);

                    UnitAIModule* unit_ai = obj->unitAIValue;
                    if (unit_ai != nullptr) {
                        int target_id = -1;
                        int target_type = -1;
                        if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                            target_id = (int)target->id;
                            target_type = (int)target->master_obj->object_group;
                        }
                        rge_command_set_move_ai_state(unit_ai, target_id, target_type, adjusted_x, adjusted_y);
                    }
                }
            }
            return;
        }
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            rge_command_set_waiting_to_move(obj, 1);

            for (int group_index = 0; group_index < unit_num; ++group_index) {
                if (group_index != index) {
                    obj->addToPathingGroup((int)units[group_index].id);
                }
            }

            rge_command_issue_move_to(obj, (long)target, p1->location_x, p1->location_y, 0.0f);

            UnitAIModule* unit_ai = obj->unitAIValue;
            if (unit_ai != nullptr) {
                int target_id = -1;
                int target_type = -1;
                if ((target != nullptr) && ((target->master_obj->radius_x > 0.0f) || (target->master_obj->radius_y > 0.0f))) {
                    target_id = (int)target->id;
                    target_type = (int)target->master_obj->object_group;
                }
                rge_command_set_move_ai_state(unit_ai, target_id, target_type, p1->location_x, p1->location_y);
            }
        }
    }
}
void RGE_Command::do_command_formation(RGE_Command_Formation* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434A00
    int unit_num = p1->unitNum;
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);

    if (unit_num <= 1) {
        return;
    }

    int i = 0;
    RGE_Static_Object* reference_unit = nullptr;
    float closest_distance = 0.0f;
    while (i < unit_num) {
        RGE_Static_Object* obj = this->get_obj(units[i]);
        if (obj != nullptr) {
            float distance = sqrtf(obj->world_x * obj->world_x + obj->world_y * obj->world_y);
            if ((i == 0) || (distance < closest_distance)) {
                reference_unit = obj;
                closest_distance = distance;
            }
        }
        i = i + 1;
    }

    float adjusted_y_location = 1.0f;
    float temp_x = 1.0f;
    int flip_pair = 0;

    switch (p1->formationID) {
    case 1:
    case 4:
    case 5:
        adjusted_y_location = 1.5f;
        temp_x = 1.5f;
        break;
    case 2:
    case 3:
        adjusted_y_location = 2.0f;
        temp_x = 2.0f;
        break;
    default:
        adjusted_y_location = 1.0f;
        temp_x = 1.0f;
        break;
    }

    for (int index = 0; index < unit_num; ++index) {
        RGE_Static_Object* obj = this->get_obj(units[index]);
        if (obj == nullptr) {
            continue;
        }

        obj->removeAllFromPathingGroup();
        rge_command_set_waiting_to_move(obj, 1);

        for (int group_index = 0; group_index < unit_num; ++group_index) {
            if (group_index != index) {
                obj->addToPathingGroup((int)units[group_index].id);
            }
        }

        if ((reference_unit != nullptr) && (obj != reference_unit)) {
            float temp_y = reference_unit->world_x;
            float adjusted_x_location = reference_unit->world_y;

            switch (p1->formationID) {
            case 0:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 1.0f;
                adjusted_x_location = adjusted_x_location + temp_x;
                temp_x = temp_x + 1.0f;
                break;
            case 1:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 1.5f;
                adjusted_x_location = adjusted_x_location - temp_x;
                temp_x = temp_x + 1.5f;
                break;
            case 2:
                temp_y = temp_y + adjusted_y_location;
                adjusted_y_location = adjusted_y_location + 2.0f;
                break;
            case 3:
                adjusted_x_location = adjusted_x_location + temp_x;
                temp_x = temp_x + 2.0f;
                break;
            case 4:
                temp_y = temp_y + adjusted_y_location;
                if (flip_pair != 0) {
                    adjusted_x_location = adjusted_x_location + temp_x;
                    temp_x = temp_x + 1.5f;
                    adjusted_y_location = adjusted_y_location + 1.5f;
                    flip_pair = 0;
                } else {
                    adjusted_x_location = adjusted_x_location - temp_x;
                    flip_pair = 1;
                }
                break;
            case 5:
                temp_y = temp_y - adjusted_y_location;
                if (flip_pair != 0) {
                    adjusted_x_location = adjusted_x_location + temp_x;
                    temp_x = temp_x + 1.5f;
                    adjusted_y_location = adjusted_y_location + 1.5f;
                    flip_pair = 0;
                } else {
                    adjusted_x_location = adjusted_x_location - temp_x;
                    flip_pair = 1;
                }
                break;
            }

            rge_command_issue_move_to(obj, 0, temp_y, adjusted_x_location, 1.0f);
        }
    }
}
void RGE_Command::do_command_create_group(RGE_Command_Create_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x00435020
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderCreateGroup(p1->unitsToGroup, (int)p1->numberUnitsToGroup, p1->groupCommander, p1->groupRange);
    }
}
void RGE_Command::do_command_add_to_group(RGE_Command_Add_To_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x00435060
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderAddToGroup(p1->newUnit, p1->groupRange);
    }
}
void RGE_Command::do_command_remove_from_group(RGE_Command_Remove_From_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x004350A0
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderRemoveFromGroup(p1->unit);
    }
}
void RGE_Command::do_command_destroy_group(RGE_Command_Destroy_Group* p1) {
    // Source of truth: command.cpp.decomp @ 0x004350E0
    RGE_Static_Object* commander = this->world->object(p1->groupCommander);
    if ((commander != nullptr) && (commander->owner->id == (ushort)p1->player_id)) {
        commander->commanderDestroyGroup();
    }
}
void RGE_Command::do_command_stop(RGE_Command_Stop* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434290
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*units);
        if (obj != nullptr) {
            obj->removeAllFromPathingGroup();
            obj->stop();
        }
        units = units + 1;
    }
}
void RGE_Command::do_command_pause(RGE_Command_Pause* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x004342E0
    RGE_Obj_Info* units = (RGE_Obj_Info*)(p1 + 1);
    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*units);
        if (obj != nullptr) {
            obj->pause();
        }
        units = units + 1;
    }
}
void RGE_Command::do_command_add_waypoint(RGE_Command_Add_Waypoint* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434F70
    RGE_Static_Object* obj = this->world->object(p1->recipient);
    if (obj != nullptr) {
        this->world->players[p1->player_id]->processAddWaypointCommand(p1->recipient, p1->waypoint, p1->numberWaypoints);
    }
}
void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434FB0
    RGE_Command_Group_Waypoint* p2 = p1;
    RGE_Obj_Info* recipients = (RGE_Obj_Info*)(p1 + 1);

    for (uint i = (uint)p1->unit_num; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*recipients);
        if (obj != nullptr) {
            XYZBYTEPoint waypoint;
            waypoint.x = p2->x;
            waypoint.y = p2->y;
            waypoint.z = 0;
            obj->owner->processAddWaypointCommand(obj->id, &waypoint, 1);
        }
        recipients = recipients + 1;
    }
}
void RGE_Command::do_command_ai_order(RGE_Command_AI_Order* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434D40
    RGE_Static_Object* obj = this->world->object(p1->recipient);
    if (obj != nullptr) {
        obj->removeAllFromPathingGroup();
        this->world->players[p1->player_id]->processAIOrder(
            p1->issuer,
            p1->recipient,
            (int)p1->orderType,
            p1->target,
            p1->targetOwner,
            p1->targetX,
            p1->targetY,
            p1->targetZ,
            p1->range,
            p1->immediate,
            p1->inFront,
            p1->orderPriority);
    }
}
void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434DC0
    RGE_Command_Group_AI_Order* p2 = p1;
    RGE_Obj_Info* recipients = (RGE_Obj_Info*)(p1 + 1);

    for (uint i = (uint)p1->recipient_count; i != 0; --i) {
        RGE_Static_Object* obj = this->get_obj(*recipients);
        if (obj != nullptr) {
            float target_x = p2->targetX;
            if (target_x == -1.0f) {
                target_x = obj->world_x;
            }

            float target_y = p2->targetY;
            if (target_y == -1.0f) {
                target_y = obj->world_y;
            }

            float target_z = p2->targetZ;
            if (target_z == -1.0f) {
                target_z = obj->world_z;
            }

            obj->removeAllFromPathingGroup();
            this->world->players[p2->player_id]->processAIOrder(
                p2->issuer,
                obj->id,
                (int)p2->orderType,
                p2->target,
                p2->targetOwner,
                target_x,
                target_y,
                target_z,
                p2->range,
                p2->immediate,
                p2->inFront,
                p2->orderPriority);
        }
        recipients = recipients + 1;
    }
}
void RGE_Command::do_command_resign(RGE_Command_Resign* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00434EB0
    int multiplayer = rge_base_game->multiplayerGame();
    if (multiplayer == 0) {
        this->world->players[p1->player_id]->do_resign((int)p1->dropped);
        return;
    }

    int matching_total = 0;
    int matching_resigned = 0;
    int i = 1;
    rge_base_game->resigned[p1->comm_player_id] = 1;
    do {
        uint mapped_id = (uint)rge_base_game->playerID(i);
        if ((mapped_id == p1->player_id) && ((matching_total = matching_total + 1), rge_base_game->resigned[i] != 0)) {
            matching_resigned = matching_resigned + 1;
        }
        i = i + 1;
    } while (i < 9);

    if (matching_total == matching_resigned) {
        this->world->players[p1->player_id]->do_resign((int)p1->dropped);
    }
}
void RGE_Command::do_command_give_attribute(RGE_Command_Give_Attribute* p1) {
    // Source of truth: command.cpp.decomp @ 0x00434920
    if (this->world == nullptr || this->world->players == nullptr || p1 == nullptr) {
        return;
    }

    RGE_Player* from_player = this->world->players[p1->player_id];
    if (from_player == nullptr || from_player->attributes == nullptr) {
        return;
    }

    int attr_id = (int)p1->attr_id;
    if (attr_id < 0 || attr_id >= from_player->attribute_num) {
        return;
    }

    float amount = p1->attr_amount;
    if (from_player->attributes[attr_id] < amount) {
        return;
    }

    from_player->add_attribute_num((short)p1->attr_id, -amount, 0);

    RGE_Player* to_player = this->world->players[p1->to_player_id];
    if (to_player == nullptr) {
        return;
    }
    to_player->add_attribute_num((short)p1->attr_id, amount, 0);

    if (rge_base_game != nullptr) {
        rge_base_game->notification(7, p1->player_id, p1->to_player_id, p1->attr_id, (long)amount);
    }
    to_player->notify(p1->player_id, p1->to_player_id, 0x20A, p1->attr_id, (long)amount, 0);
}
void RGE_Command::do_command(void* p1) {
    // Fully verified. Source of truth: command.cpp.decomp @ 0x00433E20
    uchar cmd = *(uchar*)p1;
    if (cmd == 0) {
        this->do_command_order((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 1) {
        this->do_command_stop((RGE_Command_Stop*)p1);
        return;
    }
    if (cmd == 2) {
        this->do_command_work((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 3) {
        this->do_command_move((RGE_Command_Order*)p1);
        return;
    }
    if (cmd == 4) {
        this->do_command_create((RGE_Command_Create*)p1);
        return;
    }
    if (cmd == 5) {
        this->do_command_add_attribute((RGE_Command_Add_Attribute*)p1);
        return;
    }
    if (cmd == 6) {
        this->do_command_formation((RGE_Command_Formation*)p1);
        return;
    }
    if (cmd == 7) {
        this->do_command_give_attribute((RGE_Command_Give_Attribute*)p1);
        return;
    }
    if (cmd == 8) {
        this->do_command_create_group((RGE_Command_Create_Group*)p1);
        return;
    }
    if (cmd == 9) {
        this->do_command_destroy_group((RGE_Command_Destroy_Group*)p1);
        return;
    }
    if (cmd == 0xE) {
        this->do_command_add_to_group((RGE_Command_Add_To_Group*)p1);
        return;
    }
    if (cmd == 0xF) {
        this->do_command_remove_from_group((RGE_Command_Remove_From_Group*)p1);
        return;
    }
    if (cmd == 0xC) {
        this->do_command_add_waypoint((RGE_Command_Add_Waypoint*)p1);
        return;
    }
    if (cmd == 0x10) {
        this->do_command_group_waypoint((RGE_Command_Group_Waypoint*)p1);
        return;
    }
    if (cmd == 0xA) {
        this->do_command_ai_order((RGE_Command_AI_Order*)p1);
        return;
    }
    if (cmd == 0x11) {
        this->do_command_group_ai_order((RGE_Command_Group_AI_Order*)p1);
        return;
    }
    if (cmd == 0xB) {
        this->do_command_resign((RGE_Command_Resign*)p1);
        return;
    }
}
void RGE_Command::command_order(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435320
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 0;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_stop(RGE_Static_Object** p1, short p2) {
    // Source of truth: command.cpp.decomp @ 0x00435420
    int count = (int)p2;
    int size = count * 4 + 2;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Stop* cmd = (RGE_Command_Stop*)raw;
    cmd->command = 1;
    cmd->unit_num = (uchar)p2;

    this->submit(cmd, size);
}
void RGE_Command::command_stop(int p1, int* p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x004354F0
    (void)p1;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 2;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Stop* cmd = (RGE_Command_Stop*)raw;
    cmd->command = 1;
    cmd->unit_num = (uchar)p3;

    this->submit(cmd, size);
}
void RGE_Command::command_pause(int p1, int* p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x004355A0
    (void)p1;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 2;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 2);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Pause* cmd = (RGE_Command_Pause*)raw;
    cmd->command = 0xD;
    cmd->unit_num = (uchar)p3;

    this->submit(cmd, size);
}
void RGE_Command::command_work(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435620
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 2;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_work(int p1, int* p2, int p3, int p4, int p5, float p6, float p7) {
    // Source of truth: command.cpp.decomp @ 0x00435720
    (void)p1;
    (void)p5;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 0x14;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    cmd->location_x = p6;
    cmd->command = 2;
    cmd->unit_num = (uchar)p3;
    cmd->target.id = p4;
    cmd->location_y = p7;

    this->submit(cmd, size);
}
void RGE_Command::command_move(RGE_Static_Object** p1, short p2, RGE_Static_Object* p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435810
    int count = (int)p2;
    int size = count * 4 + 0x14;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    if (p3 == nullptr) {
        cmd->target.id = -1;
    }
    else {
        cmd->target.id = p3->id;
    }
    cmd->command = 3;
    cmd->unit_num = (uchar)p2;
    cmd->location_x = p4;
    cmd->location_y = p5;

    this->submit(cmd, size);
}
void RGE_Command::command_move(int p1, int* p2, int p3, int p4, int p5, float p6, float p7) {
    // Source of truth: command.cpp.decomp @ 0x00435900
    (void)p1;
    (void)p5;
    if ((p2 == nullptr) || (p3 <= 0)) {
        return;
    }

    int size = p3 * 4 + 0x14;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0x14);
    if (p3 > 0) {
        int idx = 0;
        do {
            ids[idx] = p2[idx];
            idx = idx + 1;
        } while (idx < p3);
    }

    RGE_Command_Order* cmd = (RGE_Command_Order*)raw;
    cmd->command = 3;
    cmd->unit_num = (uchar)p3;
    cmd->target.id = p4;
    cmd->location_x = p6;
    cmd->location_y = p7;

    this->submit(cmd, size);
}
void RGE_Command::command_create(short p1, short p2, float p3, float p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x004359C0
    RGE_Command_Create* cmd = (RGE_Command_Create*)calloc(1, sizeof(RGE_Command_Create));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 4;
    cmd->obj_catagory = p1;
    cmd->player_id = (uchar)p2;
    cmd->location_x = p3;
    cmd->location_y = p4;
    cmd->location_z = p5;

    this->submit(cmd, sizeof(RGE_Command_Create));
}
void RGE_Command::command_add_attribute(int p1, int p2, float p3) {
    // Source of truth: command.cpp.decomp @ 0x00435A30
    RGE_Command_Add_Attribute* cmd = (RGE_Command_Add_Attribute*)calloc(1, sizeof(RGE_Command_Add_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 5;
    cmd->player_id = (uchar)p1;
    cmd->attr_id = (uchar)p2;
    cmd->attr_amount = p3;

    this->submit(cmd, sizeof(RGE_Command_Add_Attribute));
}
void RGE_Command::command_give_attribute(int p1, int p2, int p3, float p4) {
    // Source of truth: command.cpp.decomp @ 0x00435A80
    RGE_Command_Give_Attribute* cmd = (RGE_Command_Give_Attribute*)calloc(1, sizeof(RGE_Command_Give_Attribute));
    if (cmd == nullptr) {
        return;
    }
    cmd->command = 7;
    cmd->player_id = (uchar)p1;
    cmd->to_player_id = (uchar)p2;
    cmd->attr_id = (uchar)p3;
    cmd->attr_amount = p4;

    this->submit(cmd, sizeof(RGE_Command_Give_Attribute));
}
void RGE_Command::command_formation(RGE_Static_Object** p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435AE0
    int size = p2 * 4 + 0xC;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 0xC);
    if (p2 > 0) {
        for (int i = 0; i < p2; ++i) {
            RGE_Static_Object* obj = p1[i];
            if (obj == nullptr) {
                ids[i] = -1;
            }
            else {
                ids[i] = (int)obj->id;
            }
        }
    }

    RGE_Command_Formation* cmd = (RGE_Command_Formation*)raw;
    cmd->command = 6;
    cmd->unitNum = p2 & 0xFF;
    cmd->formationID = p3;

    this->submit(cmd, size);
}
void RGE_Command::command_create_group(int p1, int p2, int* p3, int p4, float p5) {
    // Source of truth: command.cpp.decomp @ 0x00435BB0
    RGE_Command_Create_Group* cmd = (RGE_Command_Create_Group*)calloc(1, sizeof(RGE_Command_Create_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 8;
    cmd->player_id = (uchar)p1;
    cmd->groupCommander = p2;
    if (p4 > 0) {
        int* dst = cmd->unitsToGroup;
        int* src = p3;
        int count = p4;
        do {
            *dst = *src;
            dst = dst + 1;
            src = src + 1;
            count = count - 1;
        } while (count != 0);
    }
    cmd->numberUnitsToGroup = (uchar)p4;
    cmd->groupRange = p5;

    this->submit(cmd, sizeof(RGE_Command_Create_Group));
}
void RGE_Command::command_add_to_group(int p1, int p2, int p3, float p4) {
    // Source of truth: command.cpp.decomp @ 0x00435C50
    RGE_Command_Add_To_Group* cmd = (RGE_Command_Add_To_Group*)calloc(1, sizeof(RGE_Command_Add_To_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->groupCommander = p2;
    cmd->command = 0xE;
    cmd->player_id = (uchar)p1;
    cmd->newUnit = p3;
    cmd->groupRange = p4;

    this->submit(cmd, sizeof(RGE_Command_Add_To_Group));
}
void RGE_Command::command_remove_from_group(int p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435CD0
    RGE_Command_Remove_From_Group* cmd = (RGE_Command_Remove_From_Group*)calloc(1, sizeof(RGE_Command_Remove_From_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->groupCommander = p2;
    cmd->command = 0xF;
    cmd->player_id = (uchar)p1;
    cmd->unit = p3;

    this->submit(cmd, sizeof(RGE_Command_Remove_From_Group));
}
void RGE_Command::command_destroy_group(int p1, int p2) {
    // Source of truth: command.cpp.decomp @ 0x00435D40
    RGE_Command_Destroy_Group* cmd = (RGE_Command_Destroy_Group*)calloc(1, sizeof(RGE_Command_Destroy_Group));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 9;
    cmd->player_id = (uchar)p1;
    cmd->groupCommander = p2;

    this->submit(cmd, sizeof(RGE_Command_Destroy_Group));
}
void RGE_Command::command_ai_order(int p1, int p2, int p3, int p4, int p5, int p6, float p7, float p8, float p9, float p10, uchar p11, uchar p12, uchar p13) {
    // Source of truth: command.cpp.decomp @ 0x00435D90
    RGE_Command_AI_Order* cmd = (RGE_Command_AI_Order*)calloc(1, sizeof(RGE_Command_AI_Order));
    if (cmd == nullptr) {
        return;
    }

    cmd->player_id = (uchar)p1;
    cmd->issuer = (uchar)p2;
    cmd->orderType = (short)p4;
    cmd->orderPriority = p13;
    cmd->targetOwner = (uchar)p6;
    cmd->targetX = p7;
    cmd->targetY = p8;
    cmd->targetZ = p9;
    cmd->command = 0xA;
    cmd->recipient = p3;
    cmd->target = p5;
    cmd->range = p10;
    cmd->immediate = p11;
    cmd->inFront = p12;

    this->submit(cmd, sizeof(RGE_Command_AI_Order));
}
void RGE_Command::command_group_ai_order(int p1, int p2, RGE_Static_Object** p3, short p4, int p5, int p6, int p7, float p8, float p9, float p10, float p11, uchar p12, uchar p13, uchar p14) {
    // Source of truth: command.cpp.decomp @ 0x00435EA0
    if ((p3 == nullptr) || (p4 <= 0)) {
        return;
    }

    int count = (int)p4;
    int size = count * 4 + 0x24;
    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* recipients = (int*)(raw + 0x24);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p3[idx];
            if (obj == nullptr) {
                recipients[idx] = -1;
            }
            else {
                recipients[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Group_AI_Order* cmd = (RGE_Command_Group_AI_Order*)raw;
    cmd->issuer = (uchar)p2;
    cmd->orderPriority = p14;
    cmd->targetOwner = (uchar)p7;
    cmd->recipient_count = (uchar)p4;
    cmd->targetX = p8;
    cmd->targetY = p9;
    cmd->target = p6;
    cmd->targetZ = p10;
    cmd->range = p11;
    cmd->command = 0x11;
    cmd->player_id = (uchar)p1;
    cmd->orderType = p5;
    cmd->immediate = p12;
    cmd->inFront = p13;

    this->submit(cmd, size);
}
void RGE_Command::command_resign(int p1, int p2, int p3) {
    // Source of truth: command.cpp.decomp @ 0x00435FE0
    RGE_Command_Resign* cmd = (RGE_Command_Resign*)calloc(1, sizeof(RGE_Command_Resign));
    if (cmd == nullptr) {
        return;
    }

    cmd->comm_player_id = (uchar)p2;
    cmd->command = 0xB;
    cmd->player_id = (uchar)p1;
    cmd->dropped = (uchar)p3;

    this->submit(cmd, sizeof(RGE_Command_Resign));
}
void RGE_Command::command_add_waypoint(int p1, int p2, XYZBYTEPoint* p3, int p4) {
    // Source of truth: command.cpp.decomp @ 0x00436030
    RGE_Command_Add_Waypoint* cmd = (RGE_Command_Add_Waypoint*)calloc(1, sizeof(RGE_Command_Add_Waypoint));
    if (cmd == nullptr) {
        return;
    }

    cmd->command = 0xC;
    cmd->player_id = (uchar)p1;
    cmd->recipient = p2;
    cmd->numberWaypoints = (uchar)p4;
    if (p4 > 0) {
        XYZBYTEPoint* dst = cmd->waypoint;
        XYZBYTEPoint* src = p3;
        int count = p4;
        do {
            dst->x = src->x;
            dst->y = src->y;
            dst->z = src->z;
            dst = dst + 1;
            src = src + 1;
            count = count - 1;
        } while (count != 0);
    }

    this->submit(cmd, sizeof(RGE_Command_Add_Waypoint));
}
void RGE_Command::command_add_waypoint(int p1, int p2, uchar p3, uchar p4, uchar p5) {
    // Source of truth: command.cpp.decomp @ 0x004360D0
    RGE_Command_Add_Waypoint* cmd = (RGE_Command_Add_Waypoint*)calloc(1, sizeof(RGE_Command_Add_Waypoint));
    if (cmd == nullptr) {
        return;
    }

    cmd->waypoint[0].x = p3;
    cmd->command = 0xC;
    cmd->player_id = (uchar)p1;
    cmd->recipient = p2;
    cmd->numberWaypoints = 1;
    cmd->waypoint[0].y = p4;
    cmd->waypoint[0].z = p5;

    this->submit(cmd, sizeof(RGE_Command_Add_Waypoint));
}
void RGE_Command::command_group_waypoint(RGE_Static_Object** p1, short p2, uchar p3, uchar p4) {
    // Source of truth: command.cpp.decomp @ 0x00436150
    int count = (int)p2;
    int size = count * 4 + 4;
    if ((p1 == nullptr) || (p2 <= 0)) {
        return;
    }

    unsigned char* raw = (unsigned char*)calloc(1, (size_t)size);
    if (raw == nullptr) {
        return;
    }

    int* ids = (int*)(raw + 4);
    if (count > 0) {
        int idx = 0;
        do {
            RGE_Static_Object* obj = p1[idx];
            if (obj == nullptr) {
                ids[idx] = -1;
            }
            else {
                ids[idx] = (int)obj->id;
            }
            idx = idx + 1;
        } while (idx < count);
    }

    RGE_Command_Group_Waypoint* cmd = (RGE_Command_Group_Waypoint*)raw;
    cmd->command = 0x10;
    cmd->unit_num = (uchar)p2;
    cmd->x = p3;
    cmd->y = p4;

    this->submit(cmd, size);
}

