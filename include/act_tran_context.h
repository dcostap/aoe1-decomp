#ifndef AOE1_ACT_TRAN_CONTEXT_H
#define AOE1_ACT_TRAN_CONTEXT_H

// Canonical declaration surface for act_tran.cpp.
//
// PDB evidence binds all listed owners to C:\\msdev\\work\\age1_x1\\act_tran.cpp.
// Their source-line order is also their declaration order in this wrapper:
// constructors, first_in_stack, set_state, update, stop, move_to, work,
// next_to_drop_off_terrain, and targetZone.  The 00406D90 vector-deleting
// destructor is compiler generated from this one RGE_Action_Transport type.
//
// The local owner files retain fallback declarations for isolated checks.  The
// wrapper defines ACT_TRAN_SHARED_CONTEXT and uses this canonical surface so
// one translation unit has one owner for each class and vtable.

class RGE_Action_Object;
class RGE_Action_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Action_Object;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int value);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(void* object);
    virtual void copy_obj_sprites(void* object, void* task, void* other_task);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

    union {
        short action_type;
        short field_04;
    };
    char gap_06[2];
    union {
        RGE_Action_Object* obj;
        RGE_Static_Object* object;
    };
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    union {
        float target_x;
        float field_20;
    };
    union {
        float target_y;
        float field_24;
    };
    union {
        float target_z;
        float field_28;
    };
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    RGE_Action(int id, RGE_Action_Object* object, int flag);
    RGE_Action(int file, int flag);
    void setSubAction(unsigned char value);
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Object_List {
public:
    virtual void vf00(void);
    void* list;
    short number_of_objects;
    char gap_0A[2];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[4];
    long map_width;
    long map_height;

    unsigned char get_terrain(short x, short y);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x24];
    RGE_Map* map;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x14];
    RGE_Sprite* sprite;
    char gap_1C[0x14];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void notify(int param_1, int param_2, int param_3,
                        long param_4, long param_5, long param_6);

    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual unsigned char update(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);
    virtual void vfFC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void notify(int param_1, int param_2, int param_3,
                        int param_4, int param_5, int param_6);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x14];
    RGE_Object_List* objects;
    char gap_28[0x10];
    float world_x;
    float world_y;
    float world_z;

    unsigned char lookupZone(int x, int y);
    float distance_to_position(float x, float y, float z);
    int withinRangeOfZone(unsigned char zone, float range);
    unsigned char drop_held_objects(int mode);
};

class RGE_Action_Object : public RGE_Static_Object {
};

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
    unsigned char gap_10[0x24];
    RGE_Sprite* move_sprite;
};

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* action);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* object, float x, float y, float z,
                       float range, RGE_Sprite* sprite);
    float move_range;
};

class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(int id, RGE_Action_Object* object);
    RGE_Action_Transport(int file, RGE_Task* task, float x, float y, float z);

    virtual void first_in_stack(unsigned char value);
    virtual unsigned char update(void);
    virtual void set_state(unsigned char state);
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual int next_to_drop_off_terrain(void);

    int stop(void);
    int targetZone(void);
};

#endif
