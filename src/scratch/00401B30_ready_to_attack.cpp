// VA: 00401B30 RGE_Action_Attack::ready_to_attack
// Attempt log:
// try 1: packet-grounded natural reconstruction: can-attack gate, no-target point range path,
// target object visibility/map-valid checks, same-position shortcut, movement/attack state decisions. Compiles to exact size but broad mismatch (79.0570% positional / 93.7500% edit).
// try 2: checked initial call shape: prologue and argument order match through the first virtual call, but local RGE_Action_Object vtable stub puts can_attack_target at +0xF0 while original uses +0x1F0.
// try 3: kept high-level source rather than fake raw-call wrappers; call surfaces for 004C5F00/004C5E50/004C7420/00413920 and map check remain approximate.
// try 4: modeled no-target branch with point distance, range/min_range decision, out_state 0/2/1, and notify/state tails; FPU expression topology still differs broadly.
// try 5: modeled target branch visibility checks for master field_4a, object group 3/0x1b exclusions, map-check false and 0x80+owner byte cases; exact class layouts/call surfaces are still uncertain.
// try 6: modeled target movement delta small-threshold checks with +/-0.1 comparisons and target position refresh; original FPU stack scheduling is much more specific than current C emits.
// try 7: modeled final out_state 0 and 2 notification/attack-delay/current-target/type-id gates and set_state(13/4) tails; broad block layout mismatch remains.
// GIVEUP blockers: exact RGE_Action_Object vtable surface to reach +0x1F0/+0x148/+0xFC/+0x7C calls naturally, real signatures for direct helper calls 004C5F00/004C5E50/004C7420/00413920/0053C490, and FPU expression/source topology for range and delta comparisons. No inline asm used; no accepted_drift proposal.

extern float sqrt(float);
extern long __cdecl ftol(float);

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Player;
class RGE_Map;
class RGE_Master_Static_Object;

class RGE_Player { public: char gap00[0x38]; RGE_Map* map; };
class RGE_Master_Static_Object { public: char gap00[0x14]; short object_group; char gap16[0x34]; short field_4a; };
class RGE_Static_Object {
public:
    char gap00[8];
    RGE_Master_Static_Object* master;
    RGE_Player* player;
    char gap10[0x28];
    float x;
    float y;
    float z;
};
class RGE_Action_Object {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual int is_ready(); virtual unsigned char can_attack();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8c();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9c();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual unsigned char can_attack_target(RGE_Static_Object*, float, float); // +1f0 guessed wrong slot if count off
    virtual double attack_delay();
    virtual void notify(int,int,int,int,int,int);
    char gap[4];
    int id;
    RGE_Static_Object* as_static;
    RGE_Player* player;
};

class RGE_Map { public: unsigned char check(long x, long y); };
extern float distance_to_point(RGE_Action_Object* obj, float x, float y, float z);
extern void object_update_target(RGE_Action_Object* obj, RGE_Static_Object* target);
extern RGE_Static_Object* object_current_target(RGE_Action_Object* obj);
extern int object_type_id(RGE_Static_Object* obj);

class RGE_Action_Attack {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void set_state(unsigned char);
    char gap04[4];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap0d[3];
    RGE_Static_Object* target_obj;
    char gap14[0x0c];
    float target_x;
    float target_y;
    float target_z;
    char gap2c[0x10];
    unsigned char need_to_attack;
    char gap3d[0x0f];
    float range;
    float min_range;
    int ready_to_attack(int& out_state);
};

int RGE_Action_Attack::ready_to_attack(int& out_state)
{
    if (!this->obj->can_attack_target(this->target_obj, this->target_x, this->target_y)) return 0;

    RGE_Static_Object* target = this->target_obj;
    if (target == 0) {
        float d = distance_to_point(this->obj, this->target_x, this->target_y, this->target_z);
        if (d < this->range) {
            out_state = 0;
        } else {
            float vx = *(float*)((char*)this->obj->as_static + 0x30);
            float vy = *(float*)((char*)this->obj->as_static + 0x34);
            float maxd = sqrt(vx * vx + vy * vy) + this->min_range - 0.1f;
            if (d <= maxd) out_state = 2;
            else out_state = 1;
        }
    } else {
        if (target->master->field_4a > 0) {
            short group = target->master->object_group;
            if (group != 3 && group != 27) {
                if (!this->obj->player->map->check(ftol(target->y), ftol(target->x))) {
                    this->set_state(13);
                    return 0;
                }
                if (this->obj->player->map->check(ftol(target->y), ftol(target->x)) == 0x80 && !target->player->gap00[0x2d]) {
                    this->set_state(13);
                    return 0;
                }
            }
        }
        if (target->x != this->target_x || target->y != this->target_y || target->z != this->target_z) {
            float x_change = target->x - this->target_x;
            float y_change = target->y - this->target_y;
            float z_change = target->z - this->target_z;
            if (!(x_change > -0.1f && x_change < 0.1f && y_change > -0.1f && y_change < 0.1f && z_change > -0.1f && z_change < 0.1f)) {
                object_update_target(this->obj, target);
            }
            float vx = *(float*)((char*)this->obj->as_static + 0x30);
            float vy = *(float*)((char*)this->obj->as_static + 0x34);
            float d = sqrt(vx * vx + vy * vy);
            float maxd = d + this->min_range - 0.1f;
            if (d < this->range) {
                out_state = 0;
            } else if (d <= maxd) {
                out_state = 2;
            } else {
                this->target_x = target->x;
                this->target_y = target->y;
                this->target_z = target->z;
                out_state = 1;
            }
        } else {
            out_state = 1;
        }
    }

    if (out_state == 0) {
        if (!this->need_to_attack) this->obj->notify(this->obj->id, this->obj->id, 0x1fe, 0, 0, 0);
        if (this->obj->attack_delay() >= 0.0) {
            RGE_Static_Object* cur = object_current_target(this->obj);
            if (!cur || object_type_id(cur) != 0x2d5) return 0;
        }
        this->set_state(13);
        return 0;
    }
    if (out_state == 2) {
        if (!this->need_to_attack) this->obj->notify(this->obj->id, this->obj->id, 0x1fd, 0, 0, 0);
        if (this->obj->attack_delay() >= 0.0) {
            RGE_Static_Object* cur = object_current_target(this->obj);
            if (!cur || object_type_id(cur) != 0x2d5) {
                this->set_state(4);
                return 0;
            }
        }
        this->set_state(13);
        return 0;
    }
    return this->obj->is_ready() != 0;
}
