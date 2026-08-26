#ifndef AOE1_ACT_LIST_CONTEXT_H
#define AOE1_ACT_LIST_CONTEXT_H

// Canonical declaration surface for C:\\msdev\\work\\age1_x1\\act_list.cpp.
//
// The wrapper defines ACT_LIST_SHARED_CONTEXT before it includes each owner.
// The owner files keep isolated fallback declarations for focused checks.
// This surface keeps one class and one vtable for the complete module.

#include <stdlib.h>

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Node;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Sprite;
class UnitAIModule;

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    char gap_00[0x124];
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129;
    short fire_missile_at_frame;
    char gap_12C[0x0C];
    float minimum_weapon_range;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_00[0x124];
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129;
    short fire_missile_at_frame;
    char gap_12C[0x0C];
    float minimum_weapon_range;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    long id;
    RGE_Master_Combat_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[4];
    unsigned char object_state;

    UnitAIModule* unitAI();
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Task {
public:
    char gap_00[0x06];
    short action_type;
    char gap_08[0x1C];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* work_sprite;
    RGE_Sprite* move_sprite;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook(void);
    virtual void save(int file);
    virtual short type(void);
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* dest);
    virtual void get_state_name(char* dest);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual RGE_Static_Object* get_target_obj2(void);
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char value);

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

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_Attack : public RGE_Action {
public:
    char gap_40[0x1C];
    RGE_Action_Attack(int param_1, RGE_Action_Object* object);
    RGE_Action_Attack(RGE_Action_Object* object,
                      RGE_Static_Object* target,
                      RGE_Sprite* move_sprite,
                      RGE_Sprite* work_sprite,
                      RGE_Sprite* wait_sprite,
                      float work_range,
                      float minimum_weapon_range,
                      short base_hit_chance,
                      short fire_missile_at_frame);
    RGE_Action_Attack(RGE_Action_Object* object,
                      float x, float y, float z,
                      RGE_Sprite* move_sprite,
                      RGE_Sprite* work_sprite,
                      RGE_Sprite* wait_sprite,
                      float work_range,
                      float minimum_weapon_range,
                      short base_hit_chance,
                      short fire_missile_at_frame);
};

class RGE_Action_Bird : public RGE_Action {
public:
    RGE_Action_Bird(int param_1, RGE_Action_Object* object);
    RGE_Action_Bird(RGE_Action_Object* object, RGE_Task* task,
                    float x, float y, float z);
};

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int param_1, RGE_Action_Object* object);
    RGE_Action_Explore(RGE_Action_Object* object, RGE_Task* task,
                       float x, float y, float z);
};

class RGE_Action_Gather : public RGE_Action {
public:
    char gap_40[0x04];
    RGE_Action_Gather(int param_1, RGE_Action_Object* object);
    RGE_Action_Gather(RGE_Action_Object* object, RGE_Task* task,
                      RGE_Static_Object* target);
    RGE_Action_Gather(RGE_Action_Object* object, RGE_Task* task,
                      float x, float y, float z);
};

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(int param_1, RGE_Action_Object* object);
    RGE_Action_Make(RGE_Action_Object* object, RGE_Task* task);
};

class RGE_Action_Missile : public RGE_Action {
public:
    char gap_40[0x14];
    RGE_Action_Missile(int param_1, RGE_Action_Object* object);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    char gap_40[0x04];
    RGE_Action_Move_To(int param_1, RGE_Action_Object* object);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int value, short type);
    virtual RGE_Action* create_task_action(RGE_Task* task,
                                            RGE_Static_Object* object,
                                            float x, float y, float z);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);
    virtual void get_action_name(char* dest);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* dest);

    RGE_Action_List(RGE_Action_Object* object);
    ~RGE_Action_List();

    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void load(int file);
    void rehook(void);
    void save(int file);
    void delete_list(void);
    void add_action(RGE_Action* action);
    void add_action_at_end(RGE_Action* action);
    void add_action_at_end_of_action_queue(RGE_Action* action);
    void remove_action(void);
    unsigned char have_action(void);
    int action_stop(void);
    int action_move_to(RGE_Static_Object* object, float x, float y, float z);
    int action_work(RGE_Static_Object* object, float x, float y, float z);
    int attack_response(RGE_Static_Object* object);
    int relation_response(long value, unsigned char relation);
    RGE_Action* get_action(void);
    RGE_Task* get_task(void);
};

class UnitAIModule {
public:
    void setCurrentAction(int value);
    void setCurrentTarget(int id, float x, float y, float z);
};

#endif
