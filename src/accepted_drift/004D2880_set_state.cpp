// 004D2880 TRIBE_Action_Trade::set_state
// Source: tact_trd.cpp lines 134-275
// EH-framed switch with RGE_Action_Object calls through slots +0x138/+0x148.
//
// Attempt log:
// Probe 1 (prior worker): decompiler-shaped stub stopped at the high-slot
// dispatch surface and did not compile the function body.
//
// Clean reconstruction baseline: typed action/object ownership, natural
// switch/new/member-call source, and the period action hierarchy.  The high
// object slots are represented by the proven 0x148 virtual surface rather than
// raw function-pointer plumbing.
// Probe 2: shared the case 4/case 8 Move_To post-construction path with a
// source label; this restored the original 1020-byte size and call count.
// Probe 3: reversed the drop-site null/find arms; this restored the original
// linear find call followed by the null target setter.
// Probe 4: made the target_obj2 success guard positive so the null notify/state
// block stayed late, matching the original block topology and all call order.
// Probe 5: typed the shared Move_To result as the derived pointer; emitted code
// was unchanged (duplicate basin).
// Probe 6: widened the object +0x138 virtual argument to int; this restored the
// binary's sign-extension before the byte-returning virtual call.
// Probe 7: reversed the master-id comparison operands; it worsened register
// coloring, so Probe 8 restored the target-id-first form.
// Probe 9: case-local object/task aliases worsened the natural switch basin;
// Probe 10 restored direct member calls.  A positive equality/goto form for the
// target_obj2 comparison (Probe 11) was codegen-identical, so the cleaner
// target-id-first expression remains the living source.
// Probe 12 (shardA3): changed the low-energy target guard to <=; the original
// fcomp/test branch and Ghidra behavior evidence both enter vf138 when the
// held amount is not above the threshold.  This improved one exact block and
// reduced edit/resync drift by one byte.
// Probe 16 (shardA6): typed the shared action as base RGE_Action for the
// common add_action/setSubAction lifetime surface; emitted code was unchanged.
// Probes 17-20: receiver aliases, explicit short temporaries, register
// qualifiers, alternate common-tail guards, and allocation temporaries were
// neutral or structurally worse; all were reverted. Probe 3's positive common
// guard improved one raw byte but changed ordered call topology, so it was
// also reverted.
// Flag labs: VC5-small and VC5-risky presets produced no exact variant; the
// original /O2 /Oy /GX basin remained the clean best source context.
// Final residual: exact calls, size, frame, CFG counts, and ordered call map;
// 73 edit/resync bytes remain from a jump-table/EH relocation surface and
// localized EAX/EDX choices in states 6/7 and the target comparison.
// Accepted-drift review: the residual is switch-table relocation, two
// constructor-result EAX/EDI handoff placements, and local register choices.
// EH states, constructor null paths, all 36 calls and arguments, object reads,
// x87 comparison order, stores, notifications, and returns match.
// FLAGS: config\\flags\\004D2880_set_state.rsp (/nologo /c /O2 /Oy /GX)

#include "..\\..\\include\\game_globals.h"

class RGE_Sprite;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Object_List;
class RGE_Sound;

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;                         // +0x10
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xE8];
    short drop_site;                  // +0xE8
    short backup_drop_site;           // +0xEA
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long id1, long id2,
                                          float x, float y,
                                          unsigned char check_player,
                                          unsigned char player_id,
                                          RGE_Static_Object* zone_obj);
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;          // +0x28
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;                  // +0x24
    char gap_28[0x10];
    RGE_Sprite* work_sprite;           // +0x38
    char gap_3C[0x08];
    RGE_Sound* work_sound;             // +0x44
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;                     // +0x38
    float world_y;                     // +0x3C
    float world_z;                     // +0x40
    float attribute_amount_held;       // +0x44
};

// RGE_Action_Object's vtable has the common object methods followed by the
// binary-observed notify slot at +0x148.  The +0x138 method returns a byte and
// consumes the target master id as a promoted short.
class RGE_Action_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void new_sprite(RGE_Sprite*); // +0x38
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual unsigned char vf138(int master_id); // +0x138
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void notify(int, int, int, int, int, int); // +0x148

    int id;                            // +0x04
    RGE_Master_Action_Object* master_obj; // +0x08
    RGE_Player* owner;                 // +0x0C
    char gap_10[0x28];                 // +0x10..+0x37
    float world_x;                     // +0x38
    float world_y;                     // +0x3C
    float world_z;                     // +0x40
    float attribute_amount_held;       // +0x44
};

class RGE_Action_List {
public:
    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Action {
public:
    virtual void vf00();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
    virtual void set_target_obj(RGE_Static_Object*);  // +0x54
    virtual void set_target_obj2(RGE_Static_Object*); // +0x58
    virtual void set_state(unsigned char);            // +0x5C

    short action_type;                  // +0x04
    char gap_06[0x02];
    RGE_Action_Object* obj;            // +0x08
    unsigned char state;               // +0x0C
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;     // +0x10
    RGE_Static_Object* target_obj2;    // +0x14
    int targetID;                      // +0x18
    int target2ID;                     // +0x1C
    float target_x;                    // +0x20
    float target_y;                    // +0x24
    float target_z;                    // +0x28
    float timer;                       // +0x2C
    RGE_Task* task;                    // +0x30
    RGE_Action_List* sub_actions;      // +0x34
    RGE_Sprite* sprite;                // +0x38
    unsigned char subActionValue;      // +0x3C
    char gap_3D[0x03];

    void setSubAction(unsigned char);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;                       // +0x40
};

class RGE_Sound {
public:
    void play(int);
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    float pick_up_x;                   // +0x40
    float pick_up_y;                   // +0x44

    virtual void set_state(unsigned char);
    RGE_Sprite* get_wait_sprite();
    RGE_Sprite* get_move_sprite();
};

void TRIBE_Action_Trade::set_state(unsigned char param_1)
{
    RGE_Action_Move_To* action;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x267, 0, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    case 2:
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11: {
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            0.0f,
            this->get_move_sprite());
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    case 4: {
        if (this->target_obj == 0) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;

        action = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->task->work_range,
            this->get_move_sprite());
        goto add_move_action;
    }

    case 6:
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        if (this->target_obj != 0) {
            this->pick_up_x = this->target_obj->world_x;
            this->pick_up_y = this->target_obj->world_y;
        } else {
            this->pick_up_x = -1.0f;
            this->pick_up_y = -1.0f;
        }
        return;

    case 8:
        if (this->obj->attribute_amount_held > DAT_00575348) {
            if (this->target_obj2 == 0 ||
                this->target_obj2->master_obj->id != this->obj->master_obj->drop_site) {
                short drop_site = this->obj->master_obj->drop_site;
                if (drop_site != -1) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        drop_site,
                        this->obj->master_obj->backup_drop_site,
                        this->obj->world_x,
                        this->obj->world_y,
                        1,
                        2,
                        (RGE_Static_Object*)this->obj));
                } else {
                    this->set_target_obj2(0);
                }
            }

            if (this->target_obj2 != 0) {
                action = new RGE_Action_Move_To(
                    this->obj,
                    this->target_obj2,
                    0.0f,
                    this->get_move_sprite());
                goto add_move_action;
            }

            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x267, 0, 0);
            this->set_state(0x0D);
            return;
        }

        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_00575348 &&
            this->obj->vf138(this->target_obj->master_obj->id) == 0) {
            this->set_target_obj(0);
            this->set_state(3);
        }
        return;

    default:
        return;
    }

add_move_action:
    if (action == 0) {
        this->set_state(0x0D);
        return;
    }
    this->sub_actions->add_action(action);
    action->setSubAction(1);
}
