// 004D2CB0 TRIBE_Action_Trade::update
// Source: tact_trd.cpp lines 281-626
// No EH. The original frame is eight bytes plus ESI and EDI.
//
// Attempt log:
// Baseline reconstruction: named the action object, owner, task, action list,
// targets, timer, and trade fields from the packet and same-TU donors.
// The state handlers retain the ordered calls and nested action-list dispatch.
// Probe 1 baseline: natural typed state machine; frame and size matched, but
// high virtual declarations were initially one slot late.
// Probe 2 ABI: corrected slots 0x138, 0x148, 0x1F0, and owner/resource fields;
// call targets aligned and resync similarity improved.
// Probe 3 control-flow: merged states 5/6 and the state-8 terminal test;
// calls matched in count but switch layout became worse.
// Probe 4 control-flow: shared the clear-target tail with a goto; it removed
// two state calls and worsened the structural result.
// Probe 5 restore: returned to the natural duplicated paths after the tail
// experiments. Remaining gap is structural dispatch, frame, and call tails.
// Probe 6 control-flow: corrected state labels from the original jump tables;
// state 1 returns 1, state 4 owns the first update block, and state 8 owns the
// second update block. The call set stayed unchanged but resync improved.
// Probe 7 control-flow: shared nested state-4 result 5 with the state-6 gate;
// original XREFs show one destination. This removed the extra target-clear call.
// Probe 8 control-flow: shared the binary-proven state-8 tail for capacity and
// null-target paths. Call counts became exact, but broad structural drift remains.
// Probe 9 control-flow: tried sharing the state-3 tail across timer and null
// paths; it lost a call and was rolled back.
// Current reconstruction keeps the corrected labels and the two proven shared
// tails. Remaining gap is VC5 block placement and the real local frame.
// Luna probe 1: moved max_hold and take_amount to function scope; VC5 reused
// the same code and frame, so the source stayed natural but gave no lead.
// Luna probe 2: tested nested object-state guards and equivalent >6 forms;
// nested guards were codegen-neutral, while mixed compare forms worsened CFG.
// Luna probe 3: named capacity once for both the max_hold calculation and the
// later amount-capacity test. Frame became the original 8 bytes and shape
// improved; keep this source reconstruction.
// Luna probe 4: retried the original shared state-3 tail in the new frame;
// it removed one required set_state call and was rolled back.
// Luna probe 5: carried current_target through states 6/7; it added EBP, one
// call, and 120 bytes, so it was rolled back.
// Luna probe 6: named facet and the owner max-resource array pointer; both
// retained the wrong register basin and were rolled back.
// Sustained unresolved pass: ten-plus additional source, ABI, control-flow,
// header, ambient-declaration, flag, and x87-order hypotheses were compiled.
// Direct versus named target aliases and header variants did not change the
// controlling code basin. A distinct state-6 work label improved one block but
// added one byte of strict drift; it was not retained.
// The ambient sweep produced four nonexact code groups and no exact variant.
// The staged and reordered distance expressions were compiler-neutral.
// BINARY NOTE: the original frame is 0x8 with ESI and EDI only. The current
// natural source still saves EBX for the state-7 resource-index path.
// Next lead: recover the original source form that colors the facet in EDX,
// the resource-array cursor in EDI, and the state-7/state-6 block order.
//
// Follow-up matching pass:
// - BINARY NOTE: case-7 resource amount and trade_action use target_obj->owner.
//   Original reloads this+0x10 at 004D2FAD and keeps that owner through vslot+78.
//   This change reduced the clean-source diff from 1311 to 1139 bytes.
// - BINARY NOTE: state-8 result 1/2 tests target_obj2 and uses its coordinates.
//   The original loads this+0x14 at 004D30D3 and 004D3129. This fixed source
//   ownership without changing the 725-byte codegen frontier.
// - Control-flow probes moved state 1 after the shared state-8 tail and before
//   state 13. This reduced the frontier to 722 bytes and improved shape to
//   89.36%; the shared tail label itself was codegen-neutral.
// - Global DAT_00575350 replaced the local zero constant. VC5 emitted no byte
//   change, but the source now names the observed pooled double.
// - Tested and rejected: a function-scope target alias, a named facet local,
//   a state-6 pickup transition, positive-arm state-8 restructuring, and
//   object-state casts/volatile. These either worsened codegen or were neutral.

#ifndef TACT_TRD_SHARED_CONTEXT
#define V_DUMMY(N) virtual void v##N()

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Action_Object;
class RGE_Resource_Store;
class RGE_Sound;

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;
    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22); V_DUMMY(23); V_DUMMY(24);
    V_DUMMY(25); V_DUMMY(26); V_DUMMY(27); V_DUMMY(28); V_DUMMY(29);
    virtual void trade_action(int value, float amount, int facet);
    virtual void set_trade_facet(short facet, int value);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4C[0x04];
    RGE_Resource_Store* resource_store;
    char gap_54[0xB1];
    unsigned char civilization;
};

class RGE_Resource_Store {
public:
    float max_resource[9];
    float amount;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0x6A];
    short capacity;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x04];
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    char gap_40[0x04];
    float trade_value;
    unsigned char object_state;
};

class RGE_Sound {
public:
    void play(int value);
};

class RGE_Action_Object {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2); V_DUMMY(3); V_DUMMY(4);
    V_DUMMY(5); V_DUMMY(6); V_DUMMY(7); V_DUMMY(8); V_DUMMY(9);
    V_DUMMY(10); V_DUMMY(11); V_DUMMY(12); V_DUMMY(13); V_DUMMY(14);
    V_DUMMY(15); V_DUMMY(16); V_DUMMY(17); V_DUMMY(18); V_DUMMY(19);
    V_DUMMY(20); V_DUMMY(21); V_DUMMY(22); V_DUMMY(23); V_DUMMY(24);
    V_DUMMY(25); V_DUMMY(26); V_DUMMY(27); V_DUMMY(28); V_DUMMY(29);
    V_DUMMY(30); V_DUMMY(31);
    virtual void set_trade_facet(short facet, int value);
    V_DUMMY(33); V_DUMMY(34);
    V_DUMMY(35); V_DUMMY(36); V_DUMMY(37); V_DUMMY(38); V_DUMMY(39);
    V_DUMMY(40); V_DUMMY(41); V_DUMMY(42); V_DUMMY(43); V_DUMMY(44);
    V_DUMMY(45); V_DUMMY(46); V_DUMMY(47); V_DUMMY(48); V_DUMMY(49);
    V_DUMMY(50); V_DUMMY(51); V_DUMMY(52); V_DUMMY(53); V_DUMMY(54);
    V_DUMMY(55); V_DUMMY(56); V_DUMMY(57); V_DUMMY(58); V_DUMMY(59);
    V_DUMMY(60); V_DUMMY(61); V_DUMMY(62); V_DUMMY(63); V_DUMMY(64);
    V_DUMMY(65); V_DUMMY(66); V_DUMMY(67); V_DUMMY(68); V_DUMMY(69);
    V_DUMMY(70); V_DUMMY(71); V_DUMMY(72); V_DUMMY(73); V_DUMMY(74);
    V_DUMMY(75); V_DUMMY(76); V_DUMMY(77);
    virtual unsigned char can_trade(short id);
    V_DUMMY(79); V_DUMMY(80); V_DUMMY(81);
    virtual void notify(int p1, int p2, int event, int value, int p5, int p6);
    V_DUMMY(83); V_DUMMY(84); V_DUMMY(85); V_DUMMY(86); V_DUMMY(87);
    V_DUMMY(88); V_DUMMY(89); V_DUMMY(90); V_DUMMY(91); V_DUMMY(92);
    V_DUMMY(93); V_DUMMY(94); V_DUMMY(95); V_DUMMY(96); V_DUMMY(97);
    V_DUMMY(98); V_DUMMY(99); V_DUMMY(100); V_DUMMY(101); V_DUMMY(102);
    V_DUMMY(103); V_DUMMY(104); V_DUMMY(105); V_DUMMY(106); V_DUMMY(107);
    V_DUMMY(108); V_DUMMY(109); V_DUMMY(110); V_DUMMY(111); V_DUMMY(112);
    V_DUMMY(113); V_DUMMY(114); V_DUMMY(115); V_DUMMY(116); V_DUMMY(117);
    V_DUMMY(118); V_DUMMY(119); V_DUMMY(120); V_DUMMY(121); V_DUMMY(122);
    V_DUMMY(123);
    virtual unsigned char can_trade_object(RGE_Static_Object* object, int p2, int p3);

    int player_id;
    RGE_Master_Action_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x34];
    float amount;
    char gap_48[0x04];
    short facet;
    char gap_4E[0x02];
    RGE_Resource_Store* resource_store;
};

class RGE_Action_List {
public:
    V_DUMMY(0); V_DUMMY(1); V_DUMMY(2);
    virtual unsigned char update();
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
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char flag);
    virtual void copy_obj(void* source);
    virtual void copy_obj_sprites(void* source, void* task1, void* task2);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char value);

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
    void* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];
};
#undef V_DUMMY
#endif

extern float DAT_00575348;
extern float DAT_00575358;
extern float DAT_0057535c;
extern float DAT_00575360;
extern double DAT_00575350;
extern double DAT_00575368;
extern float DAT_00575370;

#ifndef TACT_TRD_SHARED_CONTEXT
class RGE_Task {
public:
    char gap_00[0x48];
    RGE_Sound* sound;
};

class TRIBE_Action_Trade : public RGE_Action {
public:
    float pick_up_x;
    float pick_up_y;
    virtual unsigned char update();
};
#endif

unsigned char TRIBE_Action_Trade::update()
{
    float max_hold;
    float take_amount;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
    }
    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }
    if (this->target_obj != 0) {
        if (this->target_obj->object_state >= 7) {
            this->set_target_obj(0);
        }
    }
    if (this->target_obj2 != 0) {
        if (this->target_obj2->object_state >= 7) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0) {
        if (this->obj->owner->player_id == this->target_obj->owner->player_id) {
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->set_state(1);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->player_id, this->obj->player_id,
                              0x1FB, 0x267, this->targetID, 0);
        }
        return 4;
        }
    }

    switch (this->state) {
    case 11:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                if (this->target_obj != 0) {
                    this->set_state(4);
                    return 0;
                }
                this->set_state(3);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
        case 4:
            this->timer = -0.5f;
            return 0;
        }
        return 0;

    case 4:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                if (this->target_obj != 0) {
                    this->set_state(4);
                    return 0;
                }
                this->set_state(3);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
        case 4:
            this->timer = -0.5f;
            return 0;
        case 5:
            goto update_state_6;
        }
        return 0;

    case 6:
    update_state_6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        #ifdef TACT_TRD_SHARED_CONTEXT
        if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
        #else
        if (this->obj->can_trade_object(this->target_obj, 0, 0) != 0) {
        #endif
            if (this->target_obj->trade_value > DAT_00575348 ||
                #ifdef TACT_TRD_SHARED_CONTEXT
                this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) != 0) {
                #else
                this->obj->can_trade(this->target_obj->master_obj->id) != 0) {
                #endif
                this->set_state(7);
                return 0;
            }
            this->set_target_obj(0);
            this->set_state(3);
        }
        return 0;

    case 7:
        if (this->target_obj == 0) {
            if (this->pick_up_y > DAT_00575350) {
                this->set_state(8);
                return 0;
            }
            this->set_state(3);
            return 0;
        }
        if (this->obj->facet != 0 && this->obj->facet != 2 && this->obj->facet != 1) {
            this->obj->facet = 1;
        }
        {
            float capacity = (float)this->obj->master_obj->capacity;
            max_hold = capacity - this->obj->amount;
            if (this->obj->owner->resource_store->max_resource[this->obj->facet] < max_hold) {
                max_hold = this->obj->owner->resource_store->max_resource[this->obj->facet];
            }
            if (this->target_obj->owner->resource_store->amount < max_hold) {
                max_hold = this->target_obj->owner->resource_store->amount;
            }
            #ifdef TACT_TRD_SHARED_CONTEXT
            this->target_obj->owner->add_attribute_num(this->obj->facet, -max_hold, 1);
            #else
            this->target_obj->owner->trade_action(this->obj->facet, -max_hold, 1);
            #endif
            this->target_obj->owner->resource_store->amount -= max_hold;
            this->obj->amount += max_hold;
            if (this->obj->amount >= capacity) {
                goto update_state_8;
            }
            if (this->target_obj->owner->resource_store->amount <= DAT_00575348 &&
                #ifdef TACT_TRD_SHARED_CONTEXT
                this->obj->keepGatheringWhenObjectIsOut(this->target_obj->master_obj->id) == 0) {
                #else
                this->obj->can_trade(this->target_obj->master_obj->id) == 0) {
                #endif
                this->set_state(8);
                return 0;
            }
        }
        return 0;

    case 8:
        if (this->timer < DAT_00575350) {
            this->timer += this->obj->owner->world->world_time_delta_seconds;
            if (this->timer > DAT_00575350) {
                this->timer = 0.0f;
                this->set_state(8);
                return 0;
            }
            return 0;
        }
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
            if (this->target_obj2 == 0) {
                goto update_state_8;
            }
            if (this->pick_up_y > DAT_00575350) {
                RGE_Task* trade_task = (RGE_Task*)this->task;
                #ifdef TACT_TRD_SHARED_CONTEXT
                if (trade_task->work_sound != 0) {
                    trade_task->work_sound->play(1);
                #else
                if (trade_task->sound != 0) {
                    trade_task->sound->play(1);
                #endif
                }
                if (this->pick_up_x < DAT_00575350 || this->pick_up_y < DAT_00575350) {
                    take_amount = DAT_00575360;
                } else {
                    float dx = this->pick_up_x - this->target_obj2->world_x;
                    float dy = this->pick_up_y - this->target_obj2->world_y;
                    take_amount = (dy * dy + dx * dx) * DAT_00575358 * DAT_0057535c;
                }
                if (this->obj->owner->civilization == 0x0F) {
                    take_amount += take_amount;
                }
                if (take_amount < DAT_00575360) {
                    take_amount = DAT_00575360;
                }
                take_amount *= this->obj->amount;
                if (take_amount > DAT_00575370) {
                    take_amount = DAT_00575370;
                }
                #ifdef TACT_TRD_SHARED_CONTEXT
                this->obj->owner->add_attribute_num(3, take_amount, 1);
                this->obj->set_attribute(this->obj->facet, 0.0f);
                #else
                this->obj->owner->trade_action(3, take_amount, 1);
                this->obj->set_trade_facet(this->obj->facet, 0);
                #endif
            }
            if (this->target_obj != 0) {
                this->set_state(4);
                return 0;
            }
            this->set_state(3);
            return 0;
        case 3:
        case 4:
        case 5:
            this->timer = -0.5f;
            return 0;
        }
        return 0;

    update_state_8:
        this->set_state(8);
        return 0;

    case 1:
        return 1;

    case 13:
        this->obj->notify(this->obj->player_id, this->obj->player_id,
                          0x1F9, 0x267, 0, 0);
        this->set_state(2);
        return 3;
    }
    return 0;
}
