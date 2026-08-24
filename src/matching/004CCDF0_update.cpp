// VA: 004CCDF0 TRIBE_Action_Artifact::update
// tact_art.cpp lines 120-164

// Attempt log:
// 1-4: established the 199-byte layout and vtable slots, but the initial
//      source had broad switch/order, call, and FPU mismatches.
// 5: reordered cases to the PDB/source order (10, 6, 100, 1), used the real
//    DAT_00574f08 double, and recovered the jbe/cmp3/ja list-value guard.
// 6: added the binary-proven extra dereference in the state-100 argument.
// 7: a local speed plus duplicate timer stores in the two arms preserves the
//    original fcom/fstp order; exact match under the default VC5 flags.
// 8: restored and revalidated the exact source after a compound-timer probe.
// 9: named the proven owner/world/master-player fields; codegen stayed exact.
// 10-11: replaced dummy virtual labels with the generated ABI names/surfaces;
//        codegen and relocation identity remained exact.
// The duplicate stores are intentional: the executable proves compare-before-
// store ordering, and the ordinary single-store spelling emits fst/fcomp.
// Status: exact validated match.

#ifndef AOE1_TACT_ART_TU_CONTEXT
#include <stddef.h>

extern double DAT_00574f08;

class RGE_Action_List {
public:
    virtual void create_action();
    virtual void create_task_action();
    virtual unsigned char inside_obj_update();
    virtual unsigned char update();  // slot 3 (0x0C)
    virtual void get_action_name();
    virtual void copy_obj();
    virtual void copy_obj_sprites();
    virtual ~RGE_Action_List();
    void delete_list();
};

class RGE_Player;

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** master_players;       // +0x40
    char gap_44[0x40];
    float world_time_delta_seconds;    // +0x84
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;              // +0x3C
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void change_ownership(RGE_Player* player);  // slot 17 (0x44)

    char gap_04[4];
    void* master_obj;               // +0x08
    RGE_Player* owner;              // +0x0C
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int file, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(void* target, float x, float y, float z);
    virtual int work(void* target, float x, float y, float z);
    virtual unsigned char attack_response(void* target);
    virtual unsigned char relation_response(long value, unsigned char flag);
    virtual void copy_obj(void* source);
    virtual void copy_obj_sprites(void* source, void* task1, void* task2);
    virtual void get_state_name(char* name);
    virtual void* get_target_obj();
    virtual void* get_target_obj2();
    virtual void set_target_obj(void* target);
    virtual void set_target_obj2(void* target);
    virtual void set_state(unsigned char state);
    unsigned short action_type;
    char gap_06[2];
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    RGE_Action_Object* object;     // +0x08
    unsigned char state;            // +0x0C
    char gap_10[3];                 // padding
    void* target_info;              // +0x10
    char gap_14[0x0C];              // +0x14 to +0x1F
    float target_x;                 // +0x20
    float target_y;                 // +0x24
    float target_z;                 // +0x28
    float timer;                    // +0x2C
    void* sprite;                   // +0x30
    RGE_Action_List* action_list;   // +0x34

    virtual unsigned char update();

    void* check_ownership();
};
#endif

unsigned char TRIBE_Action_Artifact::update() {
    unsigned char val = action_list->update();
    if (val > 0 && val <= 3) {
        action_list->delete_list();
    }
    switch (state) {
    case 10: {
        RGE_Action_Object* obj = this->object;
        float speed = this->timer - obj->owner->world->world_time_delta_seconds;
        if (speed > DAT_00574f08) {
            this->timer = speed;
            return 0;
        }
        this->timer = speed;
        this->set_state(6);
        return 0;
    }

    case 6: {
        RGE_Player* owner = (RGE_Player*)check_ownership();
        if (owner != 0) {
            action_list->delete_list();
            object->change_ownership(owner);
            return 0;
        }
        this->set_state(10);
        return 0;
    }

    case 100:
        object->change_ownership(object->owner->world->master_players[0]);
        this->set_state(6);
        return 0;

    case 1:
        return 1;

    default:
        return 0;
    }
}
