// 005092F0 RGE_Task_List::check_task
// Source: task_lst.cpp lines 252-297
// Size: 319 bytes, virtual, switch-based
//
// Attempt log:
// - Baseline retained the typed task/static/player ownership model but used the
//   wrong case-2/case-3 exits and anonymous float zero; 360B, 328 differing bytes.
// - Combined the holding-attribute type/amount guard, nested the case-2 positive
//   owner/id guards, and rebuilt case 5 from the proven action master field at +8.
// - Final source uses one explicit case-5 failure label because the oracle shares
//   owner-equality, relation-failure, and combat-failure control flow at one return.
//   This is a binary-topology-backed period C++ goto, not raw address/compiler asm.
// - Final default flags: MATCH, 319/319 bytes, 0 differing bytes.

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
    unsigned char owner_type;   // +0x10
    unsigned char holding_attr; // +0x11
    unsigned char state_building; // +0x12
};

class RGE_Master_Static_Object {
public:
    char _gap_00[0x8C];
    char combat_level;      // +0x8C
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char status);
    virtual void do_resign(int mode);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int mode);
    virtual int isEnemy(long pid);
    virtual int isAlly(long pid);          // slot 7 (+0x1C)
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
    char _gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* action_owner;             // +0x0C
    char _gap_10[0x3E];
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, int);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action_obj, RGE_Static_Object* static_obj);
    RGE_Task** list;        // +0x04
    short list_num;         // +0x08
    void delete_list();
};

int RGE_Task_List::check_task(RGE_Task* task, RGE_Action_Object* action_obj, RGE_Static_Object* static_obj)
{
    if (task->holding_attr == 1) {
        if (static_obj->attribute_type_held == -1 ||
            static_obj->attribute_amount_held <= DAT_00576544)
            return 0;
    }
    switch (task->owner_type) {
    case 1:
        if (static_obj->owner != action_obj->action_owner)
            return 0;
        break;
    case 2:
        if (static_obj->owner != action_obj->action_owner) {
            if (static_obj->owner->id != 0) {
                if (!action_obj->action_owner->relation(static_obj->owner->id))
                    return 0;
                break;
            }
        }
        return 0;
    case 3:
        if (static_obj->owner->id == 0)
            break;
        return 0;
    case 4:
        if (static_obj->owner == action_obj->action_owner)
            return 1;
        if (static_obj->owner->id != 0) {
            if (action_obj->action_owner->isAlly(static_obj->owner->id)) {
                if (static_obj->owner->isAlly(action_obj->action_owner->id))
                    return 1;
            }
        }
        return 0;
    case 5:
        if (static_obj->owner == action_obj->action_owner)
            goto case5_failure;
        if (static_obj->owner->id != 0) {
            if (!action_obj->action_owner->relation(static_obj->owner->id))
                goto case5_failure;
        }
        if (static_obj->owner->id == 0 &&
            action_obj->master_obj->combat_level == 0)
            goto case5_failure;
        break;
    case5_failure:
        return 0;
    }
    return (int)(action_obj != (RGE_Action_Object*)static_obj);
}
