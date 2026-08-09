// VA: 00401170 RGE_Action_Attack::RGE_Action_Attack full ctor
// PDB source: Act_atak.cpp
// Attempt log:
// - Initial natural constructor using base ctor/set_target_obj and defaults from packet compiled too small (no EH); original has VC5 EH frame.
// - Added custom /GX flags in config/flags/00401170_RGE_Action_Attack.rsp; got correct 311-byte size and matching EH prologue/epilogue.
// - Matched vtable/base ctor/set_target prefix through offset 0x4B; remaining drift starts in parameter load/register scheduling after set_target_obj.
// - Reordered field assignments to mirror PDB lines (wait/range/min/missile, -1 position, move/fight/fire, flags); still uses eax for wait/range and edx for min/fight differently than original.
// - Tried raw int stores for float fields; no change in load schedule.
// - Tried introducing fight_local and then moving fight assignment before wait; improved edit diff (about 19% -> 14%) by getting edx=fight live, but wait still loads in eax instead of original ecx and lower master-sprite fallbacks use eax/ecx swapped.
// - Current best with /GX: exact size 311, call set and behavior match, but MISMATCH 14.47% positional / 14.15% edit; first mismatch offset 75 in post-set_target parameter store schedule.
// - Removed the nonessential register qualifier and normalized master/combat accesses
//   to typed direct chains; emitted code stayed at the 45-byte frontier.
// - A focused /GX variant lab over local declaration/order forms preserved size/frame/
//   call-set invariants but found no closer group; the wait load remains EAX instead
//   of original ECX. Keep the natural typed source, not a register-forcing alias.
// Main-agent audit restored canonical action-object inheritance and removed the
// residual downcasts from ordinary master/owner access.

class RGE_Sprite;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;

class RGE_Player;
class RGE_Master_Combat_Object {
public:
    char pad00[0x18];
    RGE_Sprite* wait_sprite;
    char pad1C[0xA0];
    RGE_Sprite* move_sprite;       // +0xBC
    RGE_Sprite* move_sprite2;      // +0xC0
    char padC4[0x38];
    RGE_Sprite* fight_sprite;      // +0xFC
    char pad100[0x14];
    float weapon_range;            // +0x114
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char pad04[0x04];
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* param_1);
    virtual int vf08(int param_1, RGE_Action_Object* param_2);
    virtual RGE_Action_List* vf0C(RGE_Action_Object* param_1);
    virtual void vf10(void);
    virtual void vf14(int param_1);
    virtual short vf18(void);
    virtual void vf1C(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int vf34(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char vf38(RGE_Static_Object* param_1);
    virtual unsigned char vf3C(long param_1, unsigned char param_2);
    virtual void vf40(void* param_1);
    virtual void vf44(void* param_1, void* param_2, void* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void vf58(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    RGE_Action(RGE_Action_Object* param_1, int param_2);

    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
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
    char gap_3D[0x3];
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(RGE_Action_Object* action_obj, RGE_Static_Object* target, RGE_Sprite* move, RGE_Sprite* fight, RGE_Sprite* wait, float range, float min_range, short missile_id, short fire_frame);
    virtual ~RGE_Action_Attack();

    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;
    unsigned char gap_5B;
};

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* action_obj, RGE_Static_Object* target, RGE_Sprite* move, RGE_Sprite* fight, RGE_Sprite* wait, float range, float min_range, short missile_id, short fire_frame)
    : RGE_Action(action_obj, 1)
{
    this->action_type = 9;
    this->set_target_obj(target);
    RGE_Sprite* wait_reg = wait;
    RGE_Sprite* fight_local = fight;
    this->fight_sprite = fight_local;
    this->wait_sprite = wait_reg;
    this->range = range;
    this->min_range = min_range;
    this->missile_id = missile_id;
    this->target_x = -1.0f;
    this->target_y = -1.0f;
    this->target_z = -1.0f;
    this->move_sprite = move;
    this->fire_missile_at_frame = fire_frame;
    this->need_to_attack = 0;
    this->indirect_fire_flag = 0;
    if (target != 0 && target->owner == action_obj->owner) {
        this->was_same_owner = 1;
    } else {
        this->was_same_owner = 0;
    }
    if (move == 0) {
        RGE_Sprite* spr = this->obj->master_obj->move_sprite2;
        if (spr == 0) {
            spr = this->obj->master_obj->move_sprite;
        }
        this->move_sprite = spr;
    }
    if (fight == 0) {
        this->fight_sprite = this->obj->master_obj->fight_sprite;
    }
    if (wait == 0) {
        this->wait_sprite = this->obj->master_obj->wait_sprite;
    }
    if (range == 0.0f) {
        this->range = this->obj->master_obj->weapon_range;
        if (this->range == 0.0f) {
            this->range = 0.4f;
        }
    }
}
