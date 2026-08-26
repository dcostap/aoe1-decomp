#ifndef ACT_BIRD_CONTEXT_H
#define ACT_BIRD_CONTEXT_H

// Canonical declaration context for C:\\msdev\\work\\age1_x1\\act_bird.cpp.
// Field offsets follow the reviewed RGE action, object, task, and master-object
// layouts.  The wrapper keeps the five PDB body owners in source-line order.

class RGE_Sprite;
class RGE_Player;
class RGE_Task;
class RGE_Action;
class RGE_Action_Bird;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Action_Move_To;
class RGE_Color_Table;
class TDrawArea;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    char gap_04[0x14];
    RGE_Sprite* sprite;
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char gap_1C[0xE0];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* param_1, RGE_Player* param_2, float param_3, float param_4, float param_5);
    virtual void recycle_out_of_game(void);
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4);
    virtual void shadow_draw(TDrawArea* param_1, short param_2, short param_3, unsigned char param_4);
    virtual void normal_draw(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_front_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_back_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual void draw_frame(TDrawArea* param_1, short param_2, short param_3);
    virtual unsigned char update(void);
    virtual void check_damage_sprites(void);
    virtual void rehook(void);
    virtual void save(int param_1);
    virtual float teleport(float param_1, float param_2, float param_3);
    virtual void new_sprite(RGE_Sprite* param_1);
    virtual void add_overlay_sprite(RGE_Sprite* param_1, unsigned char param_2);
    virtual void remove_overlay_sprite(RGE_Sprite* param_1);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Action_Object : public RGE_Static_Object {
};

class Bird_Move_Random {
public:
    char gap_00[0x08];
    int x;
    int y;
};

class Bird_Update_Data {
public:
    char gap_00[0x28];
    Bird_Move_Random* move_random;
    char gap_2C[0x58];
    float timer_step;
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x38];
    Bird_Update_Data* bird_data;
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);
    virtual void get_action_name(char* param_1);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual ~RGE_Action_List();

    void add_action(RGE_Action* param_1);
    void delete_list(void);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* param_1);
    virtual int setup(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* param_1);
    virtual void rehook(void);
    virtual void save(int param_1);
    virtual short type(void);
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char attack_response(RGE_Static_Object* param_1);
    virtual unsigned char relation_response(long param_1, unsigned char param_2);
    virtual void copy_obj(RGE_Master_Action_Object* param_1);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void get_state_name(char* param_1);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual RGE_Static_Object* get_target_obj2(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    unsigned short action_type;
    char gap_06[0x02];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x03];
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
    char gap_3D[0x03];

    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);
    RGE_Action(RGE_Action_Object* param_1, int param_2);
};

class RGE_Action_Bird : public RGE_Action {
public:
    virtual ~RGE_Action_Bird();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char update(void);

protected:
    virtual void set_state(unsigned char param_1);

public:
    RGE_Action_Bird(int param_1, RGE_Action_Object* param_2);
    RGE_Action_Bird(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    virtual ~RGE_Action_Move_To();
    RGE_Action_Move_To(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, float param_5, RGE_Sprite* param_6);

    float range;
};

extern int __cdecl debug_rand(char* param_1, int param_2);

#endif
