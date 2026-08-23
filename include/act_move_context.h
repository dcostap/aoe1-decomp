#ifndef ACT_MOVE_CONTEXT_H
#define ACT_MOVE_CONTEXT_H

void rge_read(int handle, void* buffer, int count);

class RGE_Action_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;             // +0x18
    char gap_1C[0x9C];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                    // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;        // +0xBC
    char gap_C0[0x18];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;                        // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    void* owner;                    // +0x0C
    RGE_Sprite* sprite;             // +0x10
    RGE_Sprite* old_sprite;         // +0x14
    void* sprite_list;              // +0x18
    char gap_1C[0x1C];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char gap_44[0x44];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                    // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;          // +0x180
    char gap_181[3];
    RGE_Action_List* actions;        // +0x184
    unsigned char command_flag;     // +0x188
    char gap_189[3];
    int last_action_value;          // +0x18C
    int last_action_state_value;    // +0x190
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

    short action_type;              // +0x04
    char gap_06[2];
    RGE_Action_Object* obj;         // +0x08
    unsigned char state;            // +0x0C
    char gap_0D[3];
    RGE_Static_Object* target_obj;  // +0x10
    RGE_Static_Object* target_obj2; // +0x14
    int targetID;                   // +0x18
    int target2ID;                  // +0x1C
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    RGE_Task* task;                 // +0x30
    RGE_Action_List* sub_actions;   // +0x34
    RGE_Sprite* sprite;             // +0x38
    unsigned char subActionValue;   // +0x3C
    char gap_3D[3];

    RGE_Action(RGE_Action_Object* obj, int type);
    RGE_Action(int mode, RGE_Action_Object* object, int doSetup);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;                    // +0x40

    RGE_Action_Move_To(int handle, RGE_Action_Object* obj);
    RGE_Action_Move_To(RGE_Action_Object* obj, float x, float y, float z,
                       float range_val, RGE_Sprite* spr);
    RGE_Action_Move_To(RGE_Action_Object* obj, RGE_Static_Object* target,
                       float range_val, RGE_Sprite* spr);
};

#endif
