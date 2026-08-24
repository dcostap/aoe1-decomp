// RGE_Action_Enter::update (00402740)
// Canonical action-object hierarchy restored from the exact act_entr.cpp donors.
// The target is a virtual RGE_Action update with inherited RGE_Action fields;
// object/world/player/static-object calls use their period ABI surfaces.
//
// Attempt log:
// - baseline: prior flat-field source compiled to a constant-return stub because
//   same-TU method stubs let VC5 fold every call; it was not a useful structural
//   baseline.
// - typed reconstruction: restored the prior act_entr.cpp donor-shaped source,
//   real virtual slots, inherited action layout, and declaration-only external
//   calls. The source-level target validation keeps the binary's redundant null
//   test and target-object/action-list ownership.
// - control-flow probes: case-3-first nested dispatch plus positive distance
//   guards restored 954-byte size/frame, 94.20% shape, and 97.30% ordered-call
//   alignment. Inclusive distance/operand variants were compared; the current
//   task-left form is the best structural basin and keeps the real call ABI.
// - liveness alias probe was codegen-identical and rolled back to the clean
//   typed form. Remaining binary gap is localized: the second object lookup is
//   load-first instead of the oracle's push-first schedule, and VC5 merges one
//   of two proven enter_obj sites (36/37 calls). No productive source lead
//   remains within this assignment budget.
// - direct positive compound target guards, reconstructed from the decompiler's
//   short-circuit shape, were codegen-identical and rolled back.
// - a correct distance-first negative inner guard preserved both enter_obj calls
//   but VC5 merged the two state-2 calls. Task-left and negated compare forms
//   were either behaviorally inverted or returned to the same 36-call basin.
//   Explicit else and scoped action aliases were also unchanged. Clean source
//   restored; the remaining lead is the original call-site scheduling/context.
// - sustained follow-up probes (20 meaningful hypotheses) confirmed the same
//   basin. Lookup null-literal, compound-guard, cached-id, cached-world,
//   cached-object, separate-result, typed-null, and explicit-else forms were
//   codegen-identical. A switch-to-if rewrite restored 37/37 calls but added
//   47 bytes and broke the proven switch CFG. A 32-sample ambient declaration
//   sweep produced one code group. Distance-left polarity improved block
//   coverage but traded the missing enter_obj for a missing set_state call;
//   asymmetric polarity and call-local aliases did not solve both gaps.
//   The pinned task-left source is therefore retained as the smallest clean
//   natural reconstruction. No shared files were changed.
// - fresh follow-up probes tested explicit early distance failures, operand
//   reversal, full outer target-validation nesting, comma-condition lookup,
//   base casts, derived virtual declarations, and state-2 receiver aliases.
//   These either worsened the CFG or emitted the same 36-call group. The
//   clean source remains pinned; the unresolved facts are the second lookup's
//   push-first schedule and one merged vslot+D0 enter_obj call.

#ifndef ACT_ENTR_CONTEXT_H
class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Action;
class RGE_Static_Object;

class XYPoint {
public:
    int x;
    int y;
};

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;

    RGE_Static_Object* object(int param_1);
};

class RGE_Player {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual int vf1C(int param_1);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf01(void);
    virtual void vf02(void);
    virtual void vf03(void);
    virtual void vf04(void);
    virtual void vf05(void);
    virtual void vf06(void);
    virtual void vf07(void);
    virtual void vf08(void);
    virtual void vf09(void);
    virtual void vf10(void);
    virtual void vf11(void);
    virtual void vf12(void);
    virtual void vf13(void);
    virtual void vf14(void);
    virtual void vf15(void);
    virtual void vf16(void);
    virtual void vf17(void);
    virtual void vf18(void);
    virtual void vf19(void);
    virtual void vf20(void);
    virtual void vf21(void);
    virtual void vf22(void);
    virtual void vf23(void);
    virtual void vf24(void);
    virtual void vf25(void);
    virtual void vf26(void);
    virtual void vf27(void);
    virtual void vf28(void);
    virtual void vf29(void);
    virtual void vf30(void);
    virtual void vf31(void);
    virtual void vf32(void);
    virtual void vf33(void);
    virtual void vf34(void);
    virtual void vf35(void);
    virtual void vf36(void);
    virtual void vf37(void);
    virtual void vf38(void);
    virtual void vf39(void);
    virtual void vf40(void);
    virtual void vf41(void);
    virtual void vf42(void);
    virtual void vf43(void);
    virtual void vf44(void);
    virtual void vf45(void);
    virtual void vf46(void);
    virtual void vf47(void);
    virtual void vf48(void);
    virtual void vf49(void);
    virtual void vf50(void);
    virtual void vf51(void);
    virtual void enter_obj(RGE_Static_Object* param_1);
    virtual void vf53(void);
    virtual void vf54(void);
    virtual void vf55(void);
    virtual void vf56(void);
    virtual void vf57(void);
    virtual void vf58(void);
    virtual void vf59(void);
    virtual void vf60(void);
    virtual void vf61(void);
    virtual void vf62(void);
    virtual void vf63(void);
    virtual void vf64(void);
    virtual void vf65(void);
    virtual void vf66(void);
    virtual void vf67(void);
    virtual void vf68(void);
    virtual void vf69(void);
    virtual void vf70(void);
    virtual void vf71(void);
    virtual void vf72(void);
    virtual void vf73(void);
    virtual void vf74(void);
    virtual void vf75(void);
    virtual void vf76(void);
    virtual unsigned char actionState(void);
    virtual void vf78(void);
    virtual void vf79(void);
    virtual void vf80(void);
    virtual void vf81(void);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual void vf83(void);
    virtual void vf84(void);
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5);
    virtual void vf86(void);
    virtual void vf87(void);
    virtual void vf88(void);
    virtual void vf89(void);
    virtual void vf90(void);
    virtual void vf91(void);
    virtual void vf92(void);
    virtual void vf93(void);
    virtual void vf94(void);
    virtual void vf95(void);
    virtual void vf96(void);
    virtual void vf97(void);
    virtual void vf98(void);
    virtual void vf99(void);
    virtual void vf100(void);
    virtual void vf101(void);
    virtual void vf102(void);
    virtual void vf103(void);
    virtual void vf104(void);
    virtual void vf105(void);
    virtual void vf106(void);
    virtual void vf107(void);
    virtual void vf108(void);
    virtual int firstTileAlongLine(XYPoint* param_1, XYPoint* param_2, XYPoint* param_3, int param_4, int param_5, int param_6);

    int id;
    void* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x03];

    float distance_to_object(RGE_Static_Object* param_1);
    unsigned char is_dying(void);
};

class RGE_Action_Object : public RGE_Static_Object {
public:
    char gap_4C[0x138];
    RGE_Action_List* actions;
};

class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action* param_1);
    RGE_Action* get_action(void);
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
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int vf34(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual unsigned char vf38(RGE_Static_Object* param_1);
    virtual unsigned char vf3C(long param_1, unsigned char param_2);
    virtual void vf40(void* param_1);
    virtual void vf44(void* param_1, RGE_Task* param_2, RGE_Task* param_3);
    virtual void vf48(char* param_1);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    unsigned short action_type;
    unsigned short gap_06;
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

    float targetX(void);
    float targetY(void);
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
};

class RGE_Action_Enter : public RGE_Action {
public:
    unsigned char update(void);
};

extern float DAT_0056e1a0;
extern float DAT_0056e1a4;
extern float DAT_0056e1a8;
#endif

unsigned char RGE_Action_Enter::update(void) {
    RGE_Action* action;
    XYPoint start;
    XYPoint dest;
    XYPoint rVal;
    RGE_Static_Object* pRVar6;
    int iVar7;

    if (this->targetID != -1) {
        pRVar6 = this->obj->owner->world->object(this->targetID);
        if (!pRVar6) goto invalid_target;
    }
    if (this->target2ID != -1) {
        pRVar6 = this->obj->owner->world->object(this->target2ID);
        if (!pRVar6)
            this->set_target_obj2(pRVar6);
    }
    iVar7 = (int)this->target_obj;
    if ((iVar7 == 0) ||
        ((((RGE_Static_Object*)iVar7)->object_state < 3) &&
         ((this->target_obj == 0) ||
              ((iVar7 = this->obj->owner->vf1C((int)(short)((RGE_Static_Object*)iVar7)->owner->id)),
               iVar7 != 0)))) {
            goto handle_state;
        }

invalid_target:
    this->set_state(1);
    this->set_target_obj(0);
    this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x269, 0, 0);
    return 4;

handle_state:
    switch (this->state) {
    case 4:
        if ((this->target_obj != 0) && (this->target_obj->is_dying() == 0)) {
            switch (this->sub_actions->update()) {
            case 3:
                this->set_state(2);
                return 0;

            case 1:
            case 2:
                if (this->task->work_range >= this->obj->distance_to_object(this->target_obj) - DAT_0056e1a4) {
                    this->obj->enter_obj(this->target_obj);
                    goto entered_target;
                }
                this->set_state(2);
                return 0;

            case 4:
            case 5:
                break;

            default:
                return 0;
            }
        }

        this->set_target_obj(0);
        this->set_state(0x0D);
        return 0;

    case 2:
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
        if (this->timer > DAT_0056e1a8) {
            return 0;
        }

        if (this->task->work_range >= this->obj->distance_to_object(this->target_obj) - DAT_0056e1a4) {
            this->obj->enter_obj(this->target_obj);
            goto entered_target;
        }

        if (this->target_obj->actionState() == 2) {
            dest.x = (int)this->obj->world_x;
            dest.y = (int)this->obj->world_y;
            start.x = (int)this->target_obj->world_x;
            start.y = (int)this->target_obj->world_y;
            if (this->obj->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
                float tile_x;
                float tile_y;

                tile_x = (float)rVal.x - DAT_0056e1a0;
                tile_y = (float)rVal.y - DAT_0056e1a0;
                if ((this->target_x == tile_x) && (tile_y == this->target_y)) {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->set_state(4);
                    return 0;
                }

                this->target_x = tile_x;
                this->target_y = tile_y;
                this->target_obj->moveTo((float)rVal.x, (float)rVal.y, this->target_obj->world_z, 0, 1);
            } else {
                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_obj->moveTo(this->obj->world_x, this->obj->world_y, this->target_obj->world_z, 0.5f, 1);
            }
        } else if (this->target_obj->actionState() == 0x0B) {
            action = ((RGE_Action_Object*)this->target_obj)->actions->get_action();
            this->target_x = action->targetX();
            action = ((RGE_Action_Object*)this->target_obj)->actions->get_action();
            this->target_y = action->targetY();
        }

        this->set_state(4);
        return 0;

entered_target:
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x269, 0, 0);
        }
        this->set_state(1);
        return 2;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x269, 0, 0);
        return 3;

    default:
        return 0;
    }
}
