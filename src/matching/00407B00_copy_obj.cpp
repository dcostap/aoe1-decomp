// RGE_Action::copy_obj
// VA: 00407B00
// PDB: action.cpp:393-432
//
// The target's owner and task surfaces are period class surfaces: the action
// dispatches copy_obj_sprites through its own virtual table, and the task list
// dispatches the same operation through RGE_Action_List's slot at +0x18.
//
// Attempt log:
// - Replaced the prior cdecl vtable wrappers with the named RGE_Action,
//   RGE_Action_List, RGE_Action_Object, RGE_Task_List, and RGE_Task surfaces.
// - Moved the source task-list lookup into the positive task/task-list guard
//   and used indexed task-array expressions instead of retaining a found-task
//   local; this restored the original frame, register roles, and loop topology.
// - A declaration-order-only probe was codegen-identical.
// - The executable proves that a present task list with no matching task only
//   returns; the two null-guard fallback calls belong in the guard's else arm.
//   That natural control flow is an exact 247-byte match under the default VC5
//   flags.

class RGE_Action;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Color_Table;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Task_List;
class TDrawArea;

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char gap_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char gap_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    char gap_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short task_type, short object_id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action_object,
                                      RGE_Static_Object* object,
                                      float x, float y, float z);
    virtual int is_attack_task(RGE_Task* task);
    virtual int check_task(RGE_Task* task, RGE_Action_Object* action_object,
                           RGE_Static_Object* object);
    virtual ~RGE_Task_List();

    RGE_Task** list;
    short list_num;
    char gap_0A[2];
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xD8];
    RGE_Task_List* tasks;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite* sprite);

    int gap_04;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*,
                                            float, float, float);
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual ~RGE_Action_List();

    RGE_Action_Object* obj;
    RGE_Action_Node* list;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
};

void RGE_Action::copy_obj(RGE_Master_Action_Object* param_1)
{
    RGE_Task_List* task_list;
    RGE_Task** task_array;
    RGE_Sprite* new_sprite = 0;
    int i;

    if (this->task != 0 && (task_list = param_1->tasks) != 0) {
        task_array = task_list->list;
        i = task_list->list_num - 1;

        while (i >= 0) {
            if (task_array[i]->action_type == this->task->action_type) {
                break;
            }
            --i;
        }

        if (i >= 0) {
            if (this->obj->sprite == task_array[i]->move_sprite) {
                new_sprite = task_array[i]->move_sprite;
            } else if (this->obj->sprite == task_array[i]->work_sprite) {
                new_sprite = task_array[i]->work_sprite;
            } else if (this->obj->sprite == task_array[i]->work_sprite2) {
                new_sprite = task_array[i]->work_sprite2;
            } else if (this->obj->sprite == task_array[i]->carry_sprite) {
                new_sprite = task_array[i]->carry_sprite;
            }

            if (new_sprite != 0) {
                this->obj->new_sprite(new_sprite);
            }

            this->copy_obj_sprites(param_1, this->task, task_array[i]);
            this->sub_actions->copy_obj_sprites(param_1, this->task, task_array[i]);
            this->task = task_array[i];
            return;
        }
    } else {
        this->copy_obj_sprites(param_1, 0, 0);
        this->sub_actions->copy_obj_sprites(param_1, 0, 0);
    }
}
