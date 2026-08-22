// VA: 00401B30 RGE_Action_Attack::ready_to_attack
// Attempt log:
// baseline: packet-grounded reconstruction had correct frame/size shape but wrong
// virtual/direct call surfaces and broad status/control-flow drift.
// Canonical ownership: RGE_Action_Attack -> RGE_Action owns target/range fields;
// RGE_Action_Object -> RGE_Moving_Object -> RGE_Animated_Object ->
// RGE_Static_Object owns master_obj/owner/world coordinates and the inherited
// virtual surface. Master static owns object_group, radius_x/radius_y, fog_flag.
// Probes: explicit intermediate destructors were codegen-neutral; omitting the
// unused +1E4 tail declaration aligned turn_towards at the proven +1F0 slot.
// Natural status if/else flow produced the best reconstruction (912-byte target
// versus 960-byte rebuilt, 95.45% ordered calls, all call counts aligned).
// Direct tail-label/goto routing shrank code but destroyed block/call order and
// was rolled back. Assignment-in-condition and direct-radius expression variants
// were neutral/worse; retain the readable status structure.
// - A focused FPU variant family found that naming radius after the distance/min
//   guard preserves the x87 distance through the first compare; naming the
//   radius-plus-range threshold then improved the rebuilt frontier to 691 bytes.
// - Applying the same named radius/max-distance surface to the target-object
//   branch improved the current frontier to 657 bytes and preserved the natural
//   field-update/status shape. A direct target in-range return was 662 bytes and
//   was rolled back; a shared ready label was structurally invalid (895 bytes).
// - Removed the no-target in-range direct return; it now assigns range_status
//   and falls through to the single shared can_attack tail.
// Managed pass (sa-3e42c6e0-r1):
// - Tested 20 meaningful source, control-flow, liveness, ABI, and TU-context
//   hypotheses. Goto and switch status-tail forms changed topology or calls and
//   were rolled back. The clean natural status chain remains authoritative.
// - The notify guard is the inherited subActionValue at +3C. This matches the
//   original byte load and the canonical RGE_Action layout; need_to_attack is +58.
// - Direct this->target_obj world-field reads, direct distance-to-object input,
//   and a fresh fog check reproduce the original target reloads. The best clean
//   frontier is 613 positional bytes, 80.90% shape, and 40.57% exact blocks.
// - The reviewed DAT_0056e0cc global names the proven -0.3 threshold. It does
//   not change the local metric because target relocations remain unresolved.
// Remaining lead: the original close handler starts at D71 before the target
// max-range compare at DEE. The natural shared status chain emits that handler
// after the complete target branch. A direct label version moved calls or locals
// and was rejected.
// Remaining work should preserve these named period-plausible owners rather than
// returning to raw cursor arithmetic.
// Managed pass (sa-591f096d-r1):
// - The Ghidra CFG confirms direct can_attack branches for no-target success,
//   exact coordinates, tolerance success, and target max-range success. A
//   natural direct-return variant reduced the diagnostic diff to 473 bytes and
//   recovered 51.89% exact blocks, but emitted one extra can_attack call.
//   Restore the 613-byte clean status-chain source rather than keep a metric-only
//   variant with a call-count defect.
// - Explicit close/far/ready labels reproduced the broad Ghidra routes but
//   merged the two visibility state calls and produced 848 bytes of diff.
//   Duplicating the close source arm tail-merged back to the clean basin.
// - Reversed threshold predicates were codegen-duplicate. The clean source is
//   restored and remains the current natural checkpoint.

#include <math.h>

extern float DAT_0056e0cc;

class RGE_Sprite;
class RGE_Task;
class RGE_Action_List;
class RGE_Visible_Map;
class UnitAIModule;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x10];
    short object_group;
    char gap_16[0x1A];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3C[0x29];
    unsigned char fog_flag;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x34];
    RGE_Visible_Map* visible;
    char gap_3C[0x0E];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
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
    virtual unsigned char can_attack();
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
    virtual float maximumSpeed();
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
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void notify(int, int, int, long, long, long);
    virtual void vf14C();
    virtual void vf150();
    virtual void vf154();
    virtual void vf158();
    virtual void vf15C();
    virtual void vf160();
    virtual void vf164();
    virtual void vf168();
    virtual void vf16C();
    virtual void vf170();
    virtual void vf174();
    virtual void vf178();
    virtual void vf17C();
    virtual void vf180();
    virtual void vf184();
    virtual void vf188();
    virtual void vf18C();
    virtual void vf190();
    virtual void vf194();
    virtual void vf198();
    virtual void vf19C();
    virtual void vf1A0();
    virtual void vf1A4();
    virtual void vf1A8();
    virtual void vf1AC();
    virtual void vf1B0();
    virtual void vf1B4();
    virtual void vf1B8();
    virtual void vf1BC();
    virtual void vf1C0();
    virtual void vf1C4();
    virtual void vf1C8();
    virtual void vf1CC();
    virtual void vf1D0();
    virtual void vf1D4();
    virtual void vf1D8();
    virtual void vf1DC();
    virtual void vf1E0();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char gap_44[0x44];

    float distance_to_object(RGE_Static_Object*);
    float distance_to_position(float, float, float);
    UnitAIModule* unitAI();
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char);
    virtual void set_task(short);

    unsigned char waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap_04[0x24];
    int currentOrderValue;
    int currentOrder();
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int, int);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual void vf04(RGE_Action_Object*);
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
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual void set_state(unsigned char);

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

    int ready_to_attack(int&);
};

int RGE_Action_Attack::ready_to_attack(int& range_status)
{
    if (this->obj->turn_towards(this->target_obj, this->target_x, this->target_y) == 0)
        return 0;

    RGE_Static_Object* target = this->target_obj;
    if (target == 0) {
        float distance = this->obj->distance_to_position(this->target_x, this->target_y, this->target_z);
        if (distance < this->min_range) {
            range_status = 0;
        } else {
            RGE_Master_Static_Object* master = this->obj->master_obj;
            float radius = sqrt(master->radius_x * master->radius_x + master->radius_y * master->radius_y);
            float max_distance = radius + this->range - DAT_0056e0cc;
            if (distance <= max_distance) {
                range_status = 1;
            } else {
                range_status = 2;
            }
        }
    } else {
        if (target->owner->id > 0) {
            short group = target->master_obj->object_group;
            if (group != 3 && group != 27) {
                unsigned char visibility = this->obj->owner->visible->get_visible((int)target->world_x, (int)target->world_y);
                if (visibility == 0) {
                    this->set_state(13);
                    return 0;
                }
                if (visibility == 0x80 && this->target_obj->master_obj->fog_flag == 0) {
                    this->set_state(13);
                    return 0;
                }
            }
        }

        if (this->target_obj->world_x == this->target_x &&
            this->target_obj->world_y == this->target_y &&
            this->target_obj->world_z == this->target_z) {
            range_status = 1;
        } else {
            float x_change = this->target_obj->world_x - this->target_x;
            float z_change = this->target_obj->world_z - this->target_z;
            float y_change = this->target_obj->world_y - this->target_y;
            if ((x_change > -0.5f && x_change < 0.5f) &&
                (y_change > -0.5f && y_change < 0.5f) &&
                (z_change > -0.5f && z_change < 0.5f)) {
                range_status = 1;
            } else {
                float distance = this->obj->distance_to_object(this->target_obj);
                RGE_Master_Static_Object* master = this->obj->master_obj;
                float radius = sqrt(master->radius_x * master->radius_x + master->radius_y * master->radius_y);
                float max_distance = radius + this->range - DAT_0056e0cc;
                if (distance < this->min_range) {
                    range_status = 0;
                } else if (distance <= max_distance) {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->target_z = this->target_obj->world_z;
                    range_status = 1;
                } else {
                    range_status = 2;
                }
            }
        }
    }

    if (range_status == 0) {
        if (this->subActionValue == 0)
            this->obj->notify(this->obj->id, this->obj->id, 0x1FE, 0, 0, 0);
        if (this->obj->maximumSpeed() != 0.0) {
            UnitAIModule* ai = this->obj->unitAI();
            if (ai == 0)
                return 0;
            ai = this->obj->unitAI();
            if (ai->currentOrder() != 0x2D5)
                return 0;
        }
        this->set_state(13);
        return 0;
    }

    if (range_status == 2) {
        if (this->subActionValue == 0)
            this->obj->notify(this->obj->id, this->obj->id, 0x1FD, 0, 0, 0);
        if (this->obj->maximumSpeed() != 0.0) {
            UnitAIModule* ai = this->obj->unitAI();
            if (ai == 0) {
                this->set_state(4);
                return 0;
            }
            ai = this->obj->unitAI();
            if (ai->currentOrder() != 0x2D5) {
                this->set_state(4);
                return 0;
            }
        }
        this->set_state(13);
        return 0;
    }

    range_status = 1;
    return this->obj->can_attack() != 0;
}
