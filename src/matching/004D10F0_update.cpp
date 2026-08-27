// 004D10F0 TRIBE_Action_Make_Obj::update
// Attempt log:
// 1: Natural reconstruction from packet/decompiler with local typed layout and virtual slot fillers; compiled 400 bytes vs 446. Good prologue, but early state check used cmp/cmp not original dec/sub and rge_base_game quick_build offset was wrong.
// 2: Switch on state to match dec/sub dispatch; fix RGE_Base_Game quick_build layout and work-rate source order: prologue/dispatch and quick_build now match, still 416 vs 446 due call/source-shape differences.
// 3: Use cdecl raw debug-log slot to get caller cleanup like original; split work-rate expression: 432 bytes, still short.
// 4: Volatile obj/player after place_obj reached 446 bytes and produced a real diff, but worsened prologue to `sub esp,0Ch` and 89.9103% positional diff; rolled back.
// 5: `work_done += rate * factor` did not change size/family.
// 6: Named `factor` local for work-rate multiplier did not change size/family.
// 7: Delaying `obj` local until after needed-time load did not change size/family.
// 8: Kept cdecl debug-log and switch dispatch because they match important original traits; blocker is remaining source-shape/TU register scheduling in success/failure call blocks.
// 9: Temporary /Od flag probe did not change the 432-byte short .text family; removed flag.
// 10: Temporary /O2 without /Oy probe also stayed in 432-byte short .text family; removed flag.
// 11: Removed persistent obj/player locals from the completion arms and used direct typed
//     this->obj / owner expressions; this is the period-plausible source shape for the
//     binary's repeated obj/owner reloads and tests whether it restores the missing call-block bytes.
// 12: Hoisting the required-time declaration and inlining the two work-rate factors were
//     register/liveness probes; the former was unchanged and the latter made the x87 block exact.
// 13: Restored typed ownership with RGE_Master_Action_Object::work_rate and
//     RGE_Player::world->world_time_delta_seconds; this fixed the remaining register-color
//     permutation while preserving the natural direct-member source. Exact 446/446 match.
// 14: Canonicalized RGE_Action_Object's x/y field order (+0x38/+0x3C) and the
//     right-to-left display conversion operands. This preserves standalone exactness
//     and matches the same-TU shared context.
// BINARY NOTE: The success path loads +0x3C before +0x38 for the cdecl display
//     arguments. With canonical x at +0x38 and y at +0x3C, source order x, y
//     preserves that emitted order.

#ifndef TACT_MOB_SHARED_CONTEXT
extern void* rge_base_game;

class TRIBE_Player;

class RGE_Game_World {
public:
    char gap_00[0x84];
    float world_time_delta_seconds;
};

class RGE_Master_Action_Object {
public:
    char gap_00[0xe4];
    float work_rate;
};

struct RGE_Master_Static_Object { char gap[0x15a]; short train_time; };
struct RGE_Static_Object { void* vfptr; int id; char gap08[0x30]; float y; float x; };
struct RGE_Action_Object { void* vfptr; int id; RGE_Master_Action_Object* master; TRIBE_Player* owner; char gap10[0x28]; float x; float y; };

class RGE_Base_Game_Hack {
public:
    virtual ~RGE_Base_Game_Hack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void display_message(int msg, int player, int obj, int a, int b);
    char gap04[0x9A8 - 4];
    int quick_build;
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual unsigned char command_place_object(short, float, float, float);
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void debug_log(const char*, int, int, int);
    virtual void vE8(); virtual void vEC(); virtual void vF0(); virtual void vF4();
    virtual void vF8(); virtual void vFC(); virtual void v100(); virtual void v104();
    virtual void v108(); virtual void cancel_make(int, int, int, int);
    virtual void placement_success(int, int, int, int);

    char gap_04[0x20];
    RGE_Master_Static_Object** objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4c[0x98];
    float work_rate;

    void reimburse_obj_cost(short obj_id);
};

class RGE_Action_Object_Hack {
public:
    virtual ~RGE_Action_Object_Hack();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void vE0();
    virtual void vE4(); virtual void vE8(); virtual void vEC(); virtual void vF0();
    virtual void vF4(); virtual void vF8(); virtual void vFC(); virtual void v100();
    virtual void v104(); virtual void v108(); virtual void v10C(); virtual void v110();
    virtual void v114(); virtual void v118(); virtual void v11C(); virtual void v120();
    virtual void v124(); virtual void v128(); virtual void v12C(); virtual void v130();
    virtual void v134(); virtual void v138(); virtual void v13C(); virtual void v140();
    virtual void v144();
    virtual void slot148(int, int, int, int, int, int);
};

class TRIBE_Action_Make_Obj {
public:
    virtual ~TRIBE_Action_Make_Obj();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58();
    virtual void set_state(unsigned char);

    char gap_04[4];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0d[0x33];
    short obj_id;
    char gap_42[2];
    float work_done;
    int unique_id;
    unsigned char pre_paid;

    unsigned char place_obj(RGE_Static_Object** obj);
};
#endif

unsigned char TRIBE_Action_Make_Obj::update()
{
    switch (this->state) {
    case 1:
        return 1;
    case 6:
        int needed;
        if (((RGE_Base_Game_Hack*)rge_base_game)->quick_build != 0) {
            this->work_done = 1000.0f;
        } else {
            this->work_done = this->obj->master->work_rate *
                this->obj->owner->world->world_time_delta_seconds + this->work_done;
        }
        needed = this->obj->owner->objects[this->obj_id]->train_time;
        if ((float)needed <= this->work_done) {
            this->set_state(1);
            RGE_Static_Object* newObject;
            if (!this->place_obj(&newObject)) {
                this->obj->owner->reimburse_obj_cost(this->obj_id);
                ((RGE_Base_Game_Hack*)rge_base_game)->display_message(0x68, this->obj->owner->player_id, this->obj_id, 0, 0);
                (*(void (__cdecl**)(TRIBE_Player*, const char*, int, int, int))(*(int*)this->obj->owner + 0xe4))(this->obj->owner, (const char*)0x587728, (int)this->obj_id, this->obj->id, this->unique_id);
                this->obj->owner->cancel_make(0, (int)this->obj_id, this->obj->id, this->unique_id);
                ((RGE_Action_Object_Hack*)this->obj)->slot148(this->obj->id, this->obj->id, 0x1f9, 0x26b, 0, 0);
                return 1;
            } else {
                ((RGE_Base_Game_Hack*)rge_base_game)->display_message(0x66, this->obj->owner->player_id, (int)this->obj_id, (long)this->obj->x, (long)this->obj->y);
                this->obj->owner->placement_success((int)this->obj_id, this->obj->id, this->unique_id, newObject->id);
                ((RGE_Action_Object_Hack*)this->obj)->slot148(this->obj->id, this->obj->id, 0x1fa, 0x26b, 0, 0);
                return 1;
            }
        }
        break;
    }
    return 0;
}
