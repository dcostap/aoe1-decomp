// VA: 004CDBB0 TRIBE_Action_Convert::first_in_stack
// Attempt log:
// 1: natural reconstruction from packet/decompiler: text 560 B, wrong field offsets because virtual declarations shifted data members; notify helper emitted out-of-line.
// 2: rewrote with explicit vtable pointer field, manual vtable set_state calls, and inline notification bodies to restore real object offsets/call surface: exact size 595 but broad 87% positional; top differs by extra saved EBP/word BX.
// 3: tried int class-id local to force movsx ebx; worsened to 592 B and still used BX, rolled back.
// 4: tried /GX; unchanged.
// 5: tried /O2 without /Oy; unchanged.
// 6: current best same-size 595 B after inlining notify and manual vtable calls, but still broad mismatch from register topology: original carries target in EDX and actor in EDI with no EBP save; rebuilt saves EBP and carries target in EDI/actor in EDX.
// 7: object offsets/call surface are now correct (+8 actor, +10 target, +40 was_same_owner, +44 requiredRange), unlike v1.
// 8: remaining mismatch includes word-BX class id, branch distances, and all notification/set_state blocks shifted by the early register allocation.
// 9: left in scratch: behavior is modeled but mismatch is much too broad for accepted_drift.
// 10: duplicate failure calls fixed the aggregate call count, but the positive/negative tail layouts were still 14 bytes over the boundary; reset to the clean source before the typed-base probe.
// 11: exact RGE_Action base plus typed master/player/object surfaces reduced positional drift from 561 to 467 bytes and produced the observed movsx EBX object-group load; call set and CFG counts now align.
// 12: declaration-order, direct-reread, and distinct RGE_Static_Object target probes did not remove the extra EBP save or swap target/actor coloring; emitted code duplicated across several probes.
// 13: bounded result left in scratch: 604 emitted bytes versus 595, saved EBP versus original EBX/ESI/EDI only, and the remaining broad drift begins at the prologue/register topology. Calls are 19/19 with exact target multiset.

typedef unsigned char uchar;

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[4];
    float* attributes;
    int computerPlayer();
};

class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    char gap_04[0x0C];
    short id;
    short copy_id;
    short object_group;
    char gap_16[0x114 - 0x16];
    float weapon_range;
};

class RGE_Static_Object {
public:
    virtual void _s0();

    char gap_04[4];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float attribute_amount_held;
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(uchar);
    virtual uchar vf20();
    virtual uchar vf24();
    virtual uchar vf28();
    virtual int vf2C();
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual uchar vf38(void*);
    virtual uchar vf3C(long, uchar);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C();
    virtual void* vf50();
    virtual void set_target_obj(void*);
    virtual void set_target_obj2(void*);
    virtual void set_state(uchar);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    uchar state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    uchar subActionValue;
    char gap_3D[3];
};

class RGE_Base_Game {
public:
    virtual void g00(); virtual void g04(); virtual void g08(); virtual void g0C();
    virtual void g10(); virtual void g14(); virtual void g18(); virtual void g1C();
    virtual void g20(); virtual void g24(); virtual void g28(); virtual void g2C();
    virtual void g30(); virtual void g34(); virtual void g38(); virtual void g3C();
    virtual void notify(int, int, int, int, int);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Action_Convert : public RGE_Action {
public:
    uchar was_same_owner;
    char gap_41[3];
    float requiredRange;

    void first_in_stack(uchar param_1);
};

void TRIBE_Action_Convert::first_in_stack(uchar param_1)
{
    RGE_Static_Object* target = this->target_obj;
    if (target != 0) {
        RGE_Master_Static_Object* target_master = target->master_obj;
        int object_group = target_master->object_group;
        if (target->owner == this->obj->owner) {
            this->was_same_owner = 1;
        } else {
            this->was_same_owner = 0;
        }
        short target_id = target_master->id;
        if (target_id == 0x6d || object_group == 0x1b || target_id == 0x9f || target_id == 0x9e || target_id == 0xa3 || target_id == 0x114) {
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            target_id = this->target_obj->master_obj->id;
            if (target_id == 0x6d) {
                rge_base_game->notify(0x79, (int)this->obj->owner->id, 0, 0, 0);
                return;
            }
            if (target_id == 0x114) {
                rge_base_game->notify(0x7a, (int)this->obj->owner->id, 0, 0, 0);
                return;
            }
            return;
        }
        if (this->obj->attribute_amount_held < 100.0) {
            this->set_state(0x0d);
            rge_base_game->notify(0x76, (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
        if (object_group == 3) {
            this->requiredRange = 1.0f;
        } else {
            this->requiredRange = this->obj->master_obj->weapon_range;
        }
        if (object_group == 0x1e) {
            this->set_state(0x0d);
            return;
        }
        if (object_group == 0x12 && this->obj->owner->attributes[0x1b] <= 0.0f) {
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            rge_base_game->notify(0x77, (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
        if (object_group == 3 && this->obj->owner->attributes[0x1c] <= 0.0f) {
            if (this->obj->owner->computerPlayer() == 1) {
                this->set_state(0x0b);
            } else {
                this->set_state(0x0d);
            }
            rge_base_game->notify(0x78, (int)this->obj->owner->id, 0, 0, 0);
            return;
        }
    }
    if (param_1 != 0) {
        if (target != 0) {
            this->set_state(4);
            return;
        } else {
            this->set_state(3);
            return;
        }
    }
    this->set_state(3);
}
