// VA: 00405850 RGE_Action_Move_To::update
// PDB source: act_move.cpp
//
// Attempt log:
// - 1st pass: extern "C" free function -> 686/890 diff
// - 2nd pass: member function, extern function pointers -> 717/890 diff
// - 3rd pass: direct extern declarations -> 1035 positional diff in the fresh baseline
// - probe 2 source reset: restored the period RGE_Action/RGE_Static_Object/RGE_Moving_Object
//   ownership and real member/virtual call surfaces; removed raw helper wrappers and reused
//   one doMove result. The binary's two final +0x28 calls are modeled as virtual update calls.
// - probes 3-6 switch-handler ordering/label placement: 207-byte diagnostic basin; the
//   compiler keeps case 1 eight bytes before the original default/tail despite equivalent
//   source arrangements.
// - probe 7 removed the duplicated set_state(1) from state_done; this restored all 31
//   ordered call sites and the direct behavior-backed state-13/doMove-zero split.
// - probe 8 scoped the waypoint aggregate (rolled back: it removed the 0x8 frame).
// - probe 9 used a union overlay for the proven waypoint/first-distance stack reuse
//   (209-byte diagnostic result, not retained as source); probe 10 external bound symbols
//   was codegen-identical. Natural source is restored; remaining drift is switch-table
//   relocation identity, case-tail placement, x87 bound relocation bytes, and one return
//   register/epilogue ordering hunk.
// - 2026-08-10 orch-actmove-02 pass: independently confirmed the paused clean source and
//   binary evidence. A default-return label, implicit default, case-1-first, target_lost-inside-switch,
//   sibling-shaped case-1-last, and explicit sparse-default case labels did not reproduce the original
//   cold case-1 tail (the explicit sparse labels instead made the switch dense). A five-variant case-1
//   return-spelling lab found no exact group. Retained natural source; blocker remains VC5 switch-handler
//   placement plus the resulting late x87/return displacement drift.
// - 2026-08-13 tu-actmove-405850 pass: case-1-as-post-switch-return worsened to 706 bytes and changed the
//   dispatch range; an explicit late case-1 goto and equivalent switch(state - 1) spelling were codegen-identical
//   to the clean 212-byte mismatch. Restored the natural state switch; the sparse case-1 tail remains unresolved.
// - 2026-08-17 sa-f38c1d93 pass: twenty new probes kept the natural 890-byte/0x8-frame source as the clean
//   reconstruction. Scoping move_result, caching state, declaration reordering, case-label reordering,
//   return spellings, stdlib context, and inline/size pragmas did not improve it. A typed union overlay for
//   the proven waypoint/first-distance ESP reuse improved 212 to 209 bytes and exact body coverage, but was
//   discarded as compiler-steering rather than canonical source. External bound symbols were codegen-identical.
//   Remaining evidence-led blockers are the unmasked local switch-table relocations, cold case-1 epilogue
//   placement, and the original absolute x87 bound relocations.
// Accepted-drift review: the residual is local switch-table relocation, cold
// case-one return placement, equivalent x/y-difference stack homes, and return
// epilogue scheduling. Both versions recompute target differences after doMove.
// x87 compare order, all 31 calls and arguments, notifications, state changes,
// recursive updates, and return values match.

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Action_List;
class RGE_Task;
class RGE_Action;
class RGE_Action_Object;

class ManagedArray_int {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
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
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(void*, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, void*);
    virtual int canPathWithAdditionalPassability(void*, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine(void*, void*, void*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    ManagedArray_int pathingGroupMembers;
    ManagedArray_int groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;

    int inRange(RGE_Static_Object*, float);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char gap_8C_173[0xE8];
    unsigned char finalUserDefinedWaypoint;
    char gap_175_17F[0x0B];

    void setGoal(float, float, float);
    void setFinalUserDefinedWaypoint();
    void setActionRange(float);
    void setTargetID(int);
    void setTargetRadius(float, float);
    int findPath();
    int doMove();
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;
    char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x2C];
    float radius_x;
    float radius_y;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, void*, void*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
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

class RGE_Action_Move_To : public RGE_Action {
public:
    float range;

    virtual unsigned char update();
};

unsigned char RGE_Action_Move_To::update()
{
    XYZBYTEPoint waypoint;
    int move_result;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        goto target_lost;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj(0);
        goto target_lost;
    }

    switch (this->state) {
    case 3:
        if (this->target_obj != 0 && this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262, 0, 0);
            }
            this->obj->setWaitingToMove(0);
            this->obj->pathingGroupMembers.numberValue = 0;
            return 2;
        }

        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }

        this->obj->setGoal(this->target_x, this->target_y, 1.0f);
        waypoint.x = (unsigned char)this->target_x;
        waypoint.y = (unsigned char)this->target_y;
        waypoint.z = (unsigned char)this->target_z;
        if (this->obj->finalUserDefinedWaypoint == 0) {
            this->obj->addUserDefinedWaypoint(&waypoint, 0);
            this->obj->setFinalUserDefinedWaypoint();
        }
        this->obj->setActionRange(this->range);

        if (this->target_obj != 0) {
            this->obj->setTargetID(this->target_obj->id);
            this->obj->setTargetRadius(this->target_obj->master_obj->radius_x,
                                       this->target_obj->master_obj->radius_y);
        } else {
            this->obj->setTargetID(-1);
            this->obj->setTargetRadius(0.0f, 0.0f);
        }

        if (this->obj->findPath() == 0) {
            this->set_state(4);
            return 0;
        }
        break;

    case 4:
        if (this->target_obj != 0) {
            float x_diff = this->target_x - this->target_obj->world_x;
            float y_diff = this->target_y - this->target_obj->world_y;
            if (x_diff < -1.0 || x_diff > 1.0 ||
                y_diff < -1.0 || y_diff > 1.0) {
                goto reached_target;
            }
        }

        move_result = this->obj->doMove();
        if (move_result == 0) {
            this->set_state(1);
            goto state_done;
        }
        if (move_result == 2) {
            if (this->target_obj != 0) {
                float x_diff = this->target_x - this->target_obj->world_x;
                float y_diff = this->target_y - this->target_obj->world_y;
                if (x_diff < -1.0 || x_diff > 1.0 ||
                    y_diff < -1.0 || y_diff > 1.0) {
                    goto reached_target;
                }
            }
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262, 0, 0);
            }
            this->set_state(1);
            return 2;
        }
        break;

    case 13:
        goto state_done;

    default:
        return 0;

reached_target:
    this->obj->notify(this->obj->id, this->obj->id, 0x1FC, 0, 0, 0);
    this->set_state(3);
    this->update();
    this->update();
    return 0;

state_done:
    if (this->subActionValue == 0) {
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x262, 0, 0);
    }
    return 3;

    case 1:
        return 1;
    }

    return 0;

target_lost:
    if (this->subActionValue == 1) {
        return 5;
    }
    this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x262, this->targetID, 0);
    return 4;
}
