// 00403110 RGE_Action_Gather::set_state
// ACT_GATH.cpp, lines 165-377
// Attempt log:
// - Earlier attempts used a flat decompiler-shaped sprite/object stub.  That
//   source put target_x at +1C and sub_actions at +30, while the executable's
//   inherited RGE_Action layout proves +20/+34.  It also modeled notify and
//   new_sprite as sprite helpers, losing the real action-object ABI.
// - Clean reconstruction: restored the period RGE_Action base, typed action
//   object/master/task ownership, real virtual slots, and the two
//   RGE_Action_Move_To constructor overloads before codegen tuning.
// - Session baseline: canonical layout compiled to 1240 bytes with 810
//   differing bytes; the old state labels were one low because the binary
//   dispatches on (param_1 - 1).
// - Restored the executable's case values and added the proven 0x44 Move_To
//   size, external zero threshold, and signed-int relation ABI.  The latter
//   three facts closed the size/call-prefix gaps; the inherited base remained
//   structurally correct.
// - Inverted the depleted gather gate to a positive amount success body with
//   a late negative handler.  Splitting the state-7 facet assignment after
//   the timer reset recovered the original task-load/store order.
// - Binary CFG proves that target and drop Move_To construction shares one
//   post-constructor action-list tail; source labels `gather_action_tail`,
//   `gather_no_target`, and `gather_depleted` reproduce that topology and
//   reduce the result to exact size (1087 bytes).
// - Capturing `has_drop_site` and changing the shared action pointer to the
//   base type were codegen duplicates.  An explicit lookup convergence goto
//   was also a duplicate; the compiler still merges the two lookup calls.
// - Final target-success guard spelling (`target_obj2 != 0`) restores the
//   forward fallback edge: 1087 bytes, 88.25% shape, 86.66% edit/resync,
//   618 positional-diff bytes.  Remaining structural gap is two missing
//   duplicated find_by_master_ids/set_target_obj2 sites plus one call-site
//   relocation alignment; no further blind variants remain in this claim.
// - Fresh ACT_GATH TU switch dispatch probe kept one merged lookup call and
//   lowered shape/resync similarity; restored the clean typed reconstruction.

#include <stdlib.h>

extern float DAT_0056e278;

class RGE_Sprite;
class RGE_Sound;
class RGE_Object_List;
class RGE_Action;

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[0xD6];
    short drop_site;
    short backup_drop_site;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    char gap_1C[0x1C];
    float x;
    float y;
    float z;
    float amount_held;
};

class RGE_Task {
public:
    char gap_00[0x14];
    short facet;
    char gap_16[0x0E];
    float work_range;
    char gap_28[0x10];
    RGE_Sprite* work_sprite;
    char gap_3C[0x08];
    RGE_Sound* sound;
};

class RGE_Action_Object {
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
    virtual void set_attribute(short value, int flag);
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
    virtual unsigned char target_relation(int master_id);
    virtual void vf13C(void);
    virtual unsigned char has_drop_site(void);
    virtual void vf144(void);
    virtual void notify(int id1, int id2, int command, int sound,
                        int target_type, int arg);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    char gap_1C[0x1C];
    float x;
    float y;
    float z;
    float amount_held;
    char gap_48[4];
    short attribute_type_held;
};

class RGE_Action_List {
public:
    void delete_list(void);
    void add_action(RGE_Action* action);
};

class RGE_Object_List {
public:
    RGE_Static_Object* find_by_master_ids(long id1, long id2, float x, float y,
                                          unsigned char check_player,
                                          unsigned char player_id,
                                          RGE_Static_Object* zone_obj);
};

class RGE_Sound {
public:
    void play(int param);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(RGE_Action_Object* object);
    virtual int vf08(int value, RGE_Action_Object* object);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int value);
    virtual short vf18(void);
    virtual void vf1C(unsigned char value);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(void* object, float x, float y, float z);
    virtual int vf34(void* object, float x, float y, float z);
    virtual unsigned char vf38(void* object);
    virtual unsigned char vf3C(long value, unsigned char relation);
    virtual void vf40(void* object);
    virtual void vf44(void* object, void* task, void* other_task);
    virtual void vf48(char* name);
    virtual void* vf4C(void);
    virtual void* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char state);

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
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void setSubAction(unsigned char value);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object* object, float x, float y, float z,
                       float range, RGE_Sprite* sprite);
    RGE_Action_Move_To(RGE_Action_Object* object, RGE_Static_Object* target,
                       float range, RGE_Sprite* sprite);

    float range;
};

class RGE_Action_Gather : public RGE_Action {
public:
    virtual void set_state(unsigned char state);

    int targetType;

    RGE_Sprite* get_wait_sprite(void);
    RGE_Sprite* get_move_sprite(void);
};

void RGE_Action_Gather::set_state(unsigned char param_1)
{
    RGE_Action* move_to;

    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x202, 0x261, this->targetType, 0);
        this->timer = -10.0f;
        break;

    case 2:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
    case 15:
        this->timer = 0.0f;
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->task->work_range,
            this->get_move_sprite());
        if (move_to == 0) {
            this->set_state(13);
            return;
        }
        this->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;

    case 4:
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(13);
            return;
        }
        this->target_x = this->target_obj->x;
        this->target_y = this->target_obj->y;
        this->target_z = this->target_obj->z;
        move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->task->work_range,
            this->get_move_sprite());
        goto gather_action_tail;

    case 6:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        {
        short facet;
        this->timer = 0.0f;
        facet = this->task->facet;
        if (this->obj->attribute_type_held != facet) {
            this->obj->set_attribute(facet, 0);
        }
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->sound != 0) {
            this->task->sound->play(1);
            return;
        }
        return;
        }

    case 8:
        if (this->obj->amount_held > DAT_0056e278) {
            if (this->target_obj2 == 0) {
                if (this->obj->master_obj->drop_site == -1) {
                    this->set_target_obj2(0);
                } else {
                    if (this->obj->has_drop_site() == 1) {
                        this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                            this->obj->master_obj->drop_site,
                            this->obj->master_obj->backup_drop_site,
                            this->obj->x,
                            this->obj->y,
                            1,
                            2,
                            (RGE_Static_Object*)this->obj));
                        goto gather_lookup_done;
                    }
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        this->obj->master_obj->drop_site,
                        this->obj->master_obj->backup_drop_site,
                        this->obj->x,
                        this->obj->y,
                        1,
                        2,
                        0));
                }
            }

gather_lookup_done:
            if (this->target_obj2 != 0) {
                move_to = new RGE_Action_Move_To(
                    this->obj,
                    this->target_obj2,
                    this->task->work_range,
                    this->get_move_sprite());
                goto gather_action_tail;
            }
            goto gather_no_target;
        }

        goto gather_depleted;

gather_action_tail:
        if (move_to == 0) {
            this->set_state(13);
            return;
        }
        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;

gather_no_target:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x203, 0x261, 0, 0);
        this->set_state(13);
        return;

gather_depleted:
        if (this->target_obj != 0 &&
            this->target_obj->amount_held <= DAT_0056e278 &&
            this->obj->target_relation(this->target_obj->master_obj->id) == 0) {
            this->set_target_obj(0);
        }
        this->set_state(3);
        return;

    case 1:
    case 13:
    case 14:
        this->timer = 0.0f;
        break;

    default:
        return;
    }

    this->obj->new_sprite(this->get_wait_sprite());
}
