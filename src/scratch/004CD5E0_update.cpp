// VA: 004CD5E0 TRIBE_Action_Build::update
// Attempt log:
// try 1-10: prior decompiler-shaped source reached the original 724-byte size,
// but used fabricated action classes, wrong task states, and misnamed virtual
// calls; its broad switch drift was not a useful source reconstruction.
// baseline: canonical TRIBE_Action_Build/RGE_Action ownership with natural
// target checks and state dispatch; exact size, but the old local surfaces still
// produced broad call and layout drift.
// probe 2: restored the period action/static/moving/building hierarchy and the
// observed direct/virtual helper ownership; this is the clean structural lead.
// probe 3: corrected the player command ABI to five integer, four float, and
// three integer arguments; this removed three __ftol calls and restored 724B.
// probe 4: binary fcomp/test evidence requires the active target gate at
// timer == 0.0f, not timer != 0.0f; the branch and early body now align.
// probe 5: push order proves target id precedes target-owner id in command().
// probe 6: PDB/source handler order is 0x0B, 4, 6, 7, 1, 0x0D; restoring it
// reduced the mismatch to a localized nested-switch region.
// probe 7: status-3 arms do not clear the target; adding those calls was a
// broad negative result and was rolled back.
// probe 8: quick_build's positive arm is the inline 1000.0f path; reversing
// the source guard reproduced the original cold work-rate branch.
// probes 9-10: explicit shared-label and nested-case-order variants were
// codegen duplicates; retained the natural direct switch spelling.
// probe 15: moving the state-0x0B target-reset arm before its status-3 arm
// was a codegen duplicate; restored the clean natural switch order.
// retry 18: making the state-0x0B status-3 arm fall through was a duplicate.
// retry 19: an incorrect shared-tail label layout grew the function to 824B;
// it was rolled back.
// retry 21: explicit state-3 and reset/state-0x0B tails reduced drift to 24B.
// retry 24: placing state-4 reset cases before state-6 cases aligned all 24
// calls and reduced drift to 3B; this is the current source candidate.
// retries 25-31: named list/status locals, moved work scope, and register
// locals were codegen duplicates; all were rolled back.
// current best: 724B, 3 differing bytes at the second sub-action vtable
// load (EDX versus original EAX); call targets, order, CFG, and size align.
// r3 probe 1: braces around the state-4 nested switch were a codegen duplicate.
// r3 probe 2: an explicit state-4 default break was a codegen duplicate.
// r3 probe 3: unsigned-int promotion of the state-4 update result was a
// codegen duplicate. Exact donors confirm the same natural switch family;
// retain the shared-tail candidate and pause at the isolated register drift.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Action_List;

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0x14];
    short hp;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xE4];
    float work_rate;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
#define V(a) virtual void vf##a();
    V(04) V(08) V(0C) V(10)
    V(14) V(18) V(1C) V(20)
    V(24) V(28) V(2C) V(30)
    V(34) V(38) V(3C) V(40)
    V(44) V(48) V(4C) V(50)
    V(54) V(58) V(5C) V(60)
    V(64) V(68) V(6C) V(70)
    V(74) V(78) V(7C) V(80)
    V(84) V(88) V(8C) V(90)
    V(94)
    virtual void do_command(RGE_Static_Object*, float, float, float); // +98
    V(9C) V(A0) V(A4) V(A8)
    V(AC) V(B0) V(B4) V(B8)
    V(BC) V(C0) V(C4) V(C8)
    V(CC) V(D0) V(D4) V(D8)
    V(DC) V(E0) V(E4) V(E8)
    V(EC) V(F0) V(F4) V(F8)
    V(FC) V(100) V(104) V(108)
    V(10C) V(110) V(114) V(118)
    V(11C) V(120) V(124) V(128)
    virtual void setWaitingToMove(unsigned char); // +12C
    V(130) V(134) V(138) V(13C)
    V(140) V(144)
    virtual void notify(int, int, int, long, long, long); // +148
    V(14C) V(150) V(154) V(158)
    V(15C) V(160) V(164) V(168)
    V(16C) V(170) V(174) V(178)
    V(17C) V(180) V(184) V(188)
    V(18C) V(190) V(194) V(198)
    V(19C) V(1A0) V(1A4) V(1A8)
    V(1AC) V(1B0) V(1B4) V(1B8)
    V(1BC) V(1C0) V(1C4) V(1C8)
    V(1CC) V(1D0) V(1D4) V(1D8)
    V(1DC) V(1E0) V(1E4)
#undef V

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hp;
    char gap_34[4];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;

    void removeAllFromPathingGroup();
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual int setup_animated(void*, RGE_Player*, float, float, float); // +1E8
    virtual void stop_moving();                                          // +1EC
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float); // +1F0
    virtual int setup_moving(void*, RGE_Player*, float, float, float);    // +1F4
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char); // +1F8
    virtual void set_task(short);                                        // +1FC
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;
    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual void command(int, int, int, int, int, float, float, float,
                         float, int, int, int); // +34

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Task {
public:
    char gap_00[0x1C];
    float work_val1;
};

class RGE_Action_List {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual unsigned char update();
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
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    unsigned char build(float);
};

class TRIBE_Action_Build : public RGE_Action {
public:
    unsigned char update();
};

class RGE_Base_Game {
public:
    char gap_00[0x9A8];
    int quick_build;
};

extern RGE_Base_Game* rge_base_game;

unsigned char TRIBE_Action_Build::update()
{
    float work;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            this->set_target_obj(0);
            if (this->state != 2) {
                this->set_state(3);
                return 0;
            }
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 0 &&
        this->timer == 0.0f) {
        if (this->target_obj->hp <
            (float)(int)this->target_obj->master_obj->hp) {
            this->obj->removeAllFromPathingGroup();
            this->obj->owner->command(
                this->obj->owner->id,
                this->obj->id,
                0x2CE,
                this->target_obj->id,
                this->target_obj->owner->id,
                this->target_obj->world_x,
                this->target_obj->world_y,
                this->target_obj->world_z,
                1.0f,
                1,
                0,
                100);
            return 0;
        }

        this->set_target_obj(0);
        if (this->state != 2) {
            this->set_state(3);
            return 0;
        }
    }

    switch (this->state) {
    case 0x0B:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            goto state3_common;
        case 4:
            goto reset_common;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            goto reset_common;
        case 3:
            goto state3_common;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7:
        if (this->timer < 0.0f && this->target_obj != 0 &&
            this->target_obj->attribute_amount_held > 0.0f) {
            this->obj->removeAllFromPathingGroup();
            this->obj->setWaitingToMove(1);
            this->obj->do_command(this->target_obj,
                                  this->target_obj->world_x,
                                  this->target_obj->world_y,
                                  0);
            return 0;
        }

        if (rge_base_game->quick_build != 0) {
            work = 1000.0f;
        } else {
            work = this->task->work_val1 *
                ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }

        if (this->target_obj == 0 ||
            ((TRIBE_Building_Object*)this->target_obj)->build(work) != 0) {
            if (this->target_obj != 0 &&
                this->target_obj->master_obj->id == 0x32) {
                this->timer = -1.0f;
                return 0;
            }
            goto state3_common;
        }
        break;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x25A, 0, 0);
        this->set_state(2);
        return 3;
    }

return_zero:
    return 0;

state3_common:
    this->set_state(3);
    goto return_zero;

reset_common:
    this->set_target_obj(0);
    this->set_state(0x0B);
    goto return_zero;
}
