// 005092F0 RGE_Task_List::check_task
// Source: task_lst.cpp lines 252-297
// Size: 319 bytes, virtual, switch-based
//
// Attempt log:
// Probe 1: 319/319, 85% diff — codegen basin (register allocation, jump table layout,
//   early-return structure, virtual dispatch patterns). All structure correct but
//   VC5 generates different basin from original.
// Left in scratch: codegen basin

#include "..\..\include\game_globals.h"

class RGE_Action_Object;
class RGE_Static_Object;

class RGE_Task {
public:
    short task_type;        // +0x00
    char _gap_02[6];
    short object_group;     // +0x08
    short object_id;        // +0x0A
    char combat_level;      // +0x0C
    char _gap_0D;
    short terrain_id;       // +0x0E
    char owner_type;        // +0x10
    char holding_attr;      // +0x11
    char state_building;    // +0x12
};

class RGE_Master_Static_Object {
public:
    char _gap_00[0x8C];
    char combat_level;      // +0x8C
};

class RGE_Player {
public:
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual int check_relation(long pid);  // slot 7 (+0x1C)
    char _gap_04[0x46];
    short id;               // +0x4A
    unsigned char relation(long player_id);
};

class RGE_Static_Object {
public:
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj;  // +0x08
    RGE_Player* owner;                     // +0x0C
    char _gap_10[0x34];
    float attribute_amount_held;           // +0x44
    char object_state;                     // +0x48
    char _gap_49[3];
    short attribute_type_held;             // +0x4C
};

class RGE_Action_Object {
public:
    char _gap_00[0x0C];
    RGE_Player* action_owner;             // +0x0C
    char _gap_10[0x3E];
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, int);
    virtual void dmy01() {}
    virtual void dmy02() {}
    virtual int can_assign_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08
    void delete_list();
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action_obj, RGE_Static_Object* static_obj);
};

int RGE_Task_List::check_task(RGE_Task* task, RGE_Action_Object* action_obj, RGE_Static_Object* static_obj)
{
    if (task->holding_attr == 1) {
        if (static_obj->attribute_type_held == -1)
            return 0;
        if (static_obj->attribute_amount_held <= 0.0f)
            return 0;
    }
    switch (task->owner_type) {
    case 1:
        if (static_obj->owner != action_obj->action_owner)
            return 0;
        break;
    case 2:
        if (static_obj->owner == action_obj->action_owner)
            return 0;
        if (static_obj->owner->id == 0)
            return 0;
        if (!action_obj->action_owner->relation(static_obj->owner->id))
            return 0;
        return 0;
    case 3:
        if (static_obj->owner->id != 0)
            break;
        return 0;
    case 4:
        if (static_obj->owner == action_obj->action_owner)
            return 1;
        if (static_obj->owner->id != 0) {
            if (action_obj->action_owner->check_relation(static_obj->owner->id)) {
                if (static_obj->owner->check_relation(action_obj->action_owner->id))
                    return 1;
            }
        }
        return 0;
    case 5:
        if (static_obj->owner == action_obj->action_owner)
            return 0;
        if (static_obj->owner->id != 0) {
            if (!action_obj->action_owner->relation(static_obj->owner->id))
                return 0;
        }
        if (static_obj->owner->id == 0 && static_obj->master_obj->combat_level == 0)
            return 0;
        break;
    }
    return (int)(action_obj != (RGE_Action_Object*)static_obj);
}
