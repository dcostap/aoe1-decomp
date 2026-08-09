// VA: 00406A70 RGE_Action_Object::update
// PDB source: act_obj.cpp lines 609-717
// Attempt log:
// - Baseline: reconstructed the action-file trace, animated-object update,
//   default-task dispatch, and action-list cleanup from the executable.
// - Main-agent audit restored canonical world/player/master/object/action
//   destructor slots; emitted code remains exact.

#include <stdio.h>

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Task;

extern FILE* actionFile;

class RGE_World {
public:
    virtual ~RGE_World();
    long world_time;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_World* world;
};

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    char gap_04[0xD4];
    RGE_Task* tasks;
    short default_task;
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD4(1)
    VPAD2(5)
    VPAD1(7)
    VPAD1(8)
    virtual unsigned char update();
    VPAD16(10)
    VPAD16(20)
    VPAD16(30)
    VPAD16(40)
    VPAD16(50)
    VPAD16(60)
    VPAD16(70)

    long id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    char gap_50[0x38];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual unsigned char update();
    virtual int setup(RGE_Master_Animated_Object* master_obj, RGE_Player* player,
                      float x, float y, float z);

    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void vpad_123();
    virtual void vpad_124();
    virtual void vpad_125();
    virtual void vpad_126();

    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual void set_task(short task_id);

    unsigned char waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;

    virtual unsigned char update();
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual short type();

    char gap_04[8];
    unsigned char state;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int action_type, short param);
    virtual RGE_Action* create_task_action(RGE_Task* task, RGE_Static_Object* target,
                                            float x, float y, float z);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();

    RGE_Action_Object* obj;
    void* list;

    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
    void remove_action();
};

unsigned char RGE_Action_Object::update()
{
    if (actionFile != 0) {
        int action_value;
        int action_state_value;

        if (this->actions->have_action() != 0) {
            action_value = this->actions->get_action()->type();
            action_state_value = this->actions->get_action()->state;
        } else {
            action_value = -1;
            action_state_value = -1;
        }

        if (this->lastActionValue != action_value ||
            this->lastActionStateValue != action_state_value) {
            fprintf(actionFile, "t%d, %d,%d,%d,%d,%d\n",
                    this->owner->world->world_time,
                    this->id,
                    this->lastActionValue,
                    this->lastActionStateValue,
                    action_value,
                    action_state_value);
            this->lastActionValue = action_value;
            this->lastActionStateValue = action_state_value;
        }
    }

    unsigned char result = RGE_Animated_Object::update();
    unsigned char state = this->object_state;

    if (state > 2) {
        if (this->actions->list != 0) {
            this->actions->delete_list();
            return result;
        }
    } else {
        if (this->actions->list == 0) {
            if (state == 2 && this->master_obj->default_task != -1) {
                this->set_task(this->master_obj->default_task);
                return result;
            }
        } else {
            if (this->inside_obj != 0) {
                this->actions->inside_obj_update();
                return result;
            }

            unsigned char action_result = this->actions->update();
            if (action_result == 3 || action_result == 1) {
                this->actions->remove_action();
            }
        }
    }

    return result;
}

#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1
