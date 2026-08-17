// VA: 004014B0 RGE_Action_Attack::first_in_stack
// Attempt log:
// - The former source used a naked inline-assembly body. This reconstruction
//   uses the proven action, object, and UnitAIModule member surfaces.
// - The target reuses the saved this home as rangeStatus after the first two
//   pushes. Keep rangeStatus as a local initialized immediately before the
//   ready_to_attack call.
// - Baseline check: 135/135 bytes, no frame, one saved ESI, eight calls, and
//   100% ordered-call alignment. Only four bytes differ: the two final
//   vtable-load registers swap (target EAX then EDX; rebuild EDX then EAX).
// - Tested natural guard forms, nested and labeled control flow, top-level
//   rangeStatus scope, named ready result, AI-local reuse, base receiver
//   casts, destructor and flattened class surfaces, and parameter/state ABI
//   widths. These all kept the same four-byte register recolor.
// - An inverted vfFC top gate changed the call layout and reached 50 bytes of
//   difference. Restore the baseline source before final validation.
// - An ambient-declaration family of 128 compiler-context variants produced
//   128 distinct outputs, but none changed the four-byte recolor.
// - This claim tested direct and scoped AI locals, base receiver aliases and
//   references, explicit returns, state enum/casts, UnitAIModule surfaces,
//   split rangeStatus initialization, predicate spelling, and vfFC width.
//   All retained 135-byte output and the same EDX/EAX final-call recolor.
// - A seven-form final control-flow variant family also kept the clean
//   baseline or moved farther; no variant produced target EAX/EDX order.
// - This revisit tested the derived Act_atak virtual surface, explicit
//   unsigned-char casts, base pointer aliases, unqualified calls, and the
//   canonical RGE_Static_Object inheritance and receiver typing. Each kept
//   the same 4-byte recolor.
// - A 4096-variant standard-header context lab kept 135-byte output and
//   found no exact result. Final validation remains diff 4.

class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class UnitAIModule;

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
    virtual void vf38();
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
    virtual float vfFC();

    UnitAIModule* unitAI();
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap_04[0x24];
    int currentOrderValue;
    int currentOrder();
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
    virtual void first_in_stack(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C();
    virtual void* vf50();
    virtual void set_target_obj(void*);
    virtual void set_target_obj2(void*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    void* target_obj;
    void* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual void first_in_stack(unsigned char param_1);

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

    int ready_to_attack(int& range_status);
};

void RGE_Action_Attack::first_in_stack(unsigned char param_1)
{
    if (this->obj->vfFC() != 0.0) {
        UnitAIModule* ai = this->obj->unitAI();
        if (ai == 0 || this->obj->unitAI()->currentOrder() != 0x2D5) {
            this->set_state(4);
            return;
        }
    }

    int range_status = -1;
    if (this->ready_to_attack(range_status) == 0 && range_status != 1) {
        this->set_state(0x0D);
        return;
    }

    this->set_state(6);
}
