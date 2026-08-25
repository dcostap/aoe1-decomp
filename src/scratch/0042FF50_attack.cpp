// 0042FF50 RGE_Combat_Object::attack(RGE_Static_Object*, RGE_Combat_Object*)
// Source: com_obj.cpp lines 269-315
// attempt log:
// attempt 1: natural source from packet/decompiler; initial compile was 400B vs 407B so too small to extract.
// attempt 2: added Static_Object notify vtable surface at +0x148; fixed compile error for target notification.
// attempt 3: result local did not change codegen size or prologue.
// attempt 4: naming hp local and reversing comparisons made no size/codegen difference.
// attempt 5: volatile hp forced extractable size, but was artificial and produced broad mismatch (93.9% positional).
// attempt 6: fixed RGE_Player::objects offset from +0x20 to +0x24; corrects missile factory table load.
// attempt 7: introduced attacked local to try to keep target distinct from this/master; still 400B in natural form.
// attempt 8: changed missile-id branch to positive if (missile_id >= 0) with fallback in trailing else; matches original block order better.
// attempt 9: volatile-size diagnostic after branch reorder improved only to broad mismatch (87.96% positional); prologue still uses EBX/EBP, unlike original push-ecx/ESI/EDI then late EBX.
// attempt 10: reverted artificial volatile; left natural 400B scratch. Remaining blocker is source/register shape for target/master lifetimes plus x87 missile math interleave.
// session probes: canonicalized the missile factory to player->master_objects[]->make_new_obj, tested direct target/master ownership, block-scoped versus function-scoped locals, radius term order, and binary global constants.
// best emitted candidate: direct member source reaches 392B with all 7 calls aligned and 201-byte edit/resync drift; original still has a distinct x87 radius/trig schedule and shrink-wrapped EBX save.
// later probe: same-TU inherited Static/Animated/Moving/Action/Combat and Master_* surfaces plus the observed master hp notification argument produced 400B and 361 positional diff; retained as the best canonical source.
// later probes: named radius locals reproduced the original x87 block shape but not bytes; a named missile-master entry and an initialized c home were nonproductive or worse and were rolled back.
// current probe: passed the second attack parameter `other` to typed init_missile; this aligned the reload/push argument shape and improved structural similarity, but positional diff worsened by 10 bytes and size grew to 408B.
// orch-42FF50-a baseline: retained typed init_missile(this, target, range); the exact donor and original call values support this source ownership.
// orch-42FF50-a probes: hoisted c/s/range declarations (duplicate); named radius_x/radius_y with direct angle calls improved shape to 75.33% and diff 366B.
// orch-42FF50-a probe: reversed radius-square terms to match the original fld radius_y, mov radius_x, then x87 square order; shape improved to 76.67%, diff stayed 366B.
// orch-42FF50-a probe: inlined owner member (duplicate); marking the wrapper virtual changed the fallback call to vslot+22C and was reverted.
// orch-42FF50-a probe: naming a master local added EBP and widened drift to 386B; restored the named-radius source.
// orch-42FF50-a pause: source now keeps canonical fields, direct owner/member calls, and exact init_missile argument values. Remaining structural blocker is entry EBX save versus original late EBX save; all seven calls align.
// paused after bounded matching: no artificial volatility, aliases, raw offsets, or register-forcing scaffolding retained.
// worker sa-d0d31327: clean baseline rebuilt 392 effective bytes vs original 407, 366 strict diff, all 7 calls aligned.
// worker probes: inline range, negative/goto fallback, self alias, split range assignment, local declaration scopes, and direct radius members did not improve the natural basin; negative/goto also broke call order.
// worker conclusion: current exact blocker remains VC5 x87 expression scheduling plus late EBX save and entry push-ecx home; no artificial source steering retained.
// worker sa-86c22b60: rechecked typed range, radius, coordinate, factory, global, and declaration-order forms. Named radius and coordinate locals improved shape but worsened or preserved strict drift; sibling-style angle/owner aliases reached 407B but worsened drift. All seven calls stayed aligned.
// worker sa-86c22b60 conclusion: restored the pinned 392B natural source. The unresolved evidence remains the original late EBX save, entry push-ecx home, and x87 reload order.
// worker sa-7d40fde9 revisit: inverted missile-id control flow worsened to 390B/368B and broke call order; restored.
// worker sa-7d40fde9 revisit: passing this in the fallback improved shape but worsened to 390B; separate positive return was a codegen duplicate.
// worker sa-7d40fde9 revisit: virtualizing the target overload moved the fallback to vslot +0x22C; block-local c/s/range was a duplicate; radius_y-first terms worsened shape; inline range worsened to 378B/385B. Restored the pinned source.
// worker sa-c26e0e77: hoisting radius locals and swapping c/s declarations were codegen duplicates. Parenthesizing the y offset sum alone reached 396B/355 strict diff and 77.33% shape; the x-only form reached 400B/370, while both sums reached 396B/366. This is a useful x87 lead but remains unpinned because the asymmetric source grouping is not established by a donor.
// worker sa-c26e0e77: direct sine expressions and inline range were worse (398B/374 and 378B/385); radius_y-first with the y grouping reproduced the earlier 392B/366 basin. All probes kept seven ordered calls aligned. Clean source restored.

class RGE_Static_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;
class RGE_Player;

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void save();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);

    char pad_004[0x22];
    short hp;             // +0x26
    char pad_028[0x08];
    float radius_x;        // +0x30
    float radius_y;        // +0x34
    float radius_z;        // +0x38
    char pad_03C[0x7C];
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x20];
    int computerPlayer();
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;           // +0xB8
    char pad_BC[0x1C];
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char pad_D8[0x20];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char pad_F8[0x04];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char pad_FC[0x18];
    float weapon_range;    // +0x114
    char pad_118[0x0C];
    short missile_id;      // +0x124
    char pad_126[0x06];
    float weapon_offset_x; // +0x12C
    float weapon_offset_y; // +0x130
    float weapon_offset_z; // +0x134
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual void teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual void calculateDamage();
    virtual void rotate();
    virtual void can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal(int, int);
    virtual void heal(float);
    virtual void canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle();
    virtual void spawn_death_obj();
    virtual void get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual void is_moving();
    virtual void get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual void explore_terrain();
    virtual void unexplore_terrain();
    virtual void get_los_table();
    virtual void inAttackRange();
    virtual void underAttack();
    virtual void setUnderAttack();
    virtual void calc_attack_modifier();
    virtual void getSpeed();
    virtual void getAngle();
    virtual void maximumSpeed();
    virtual void rateOfFire();
    virtual void damageCapability(RGE_Static_Object*);
    virtual void damageCapability();
    virtual void weaponRange();
    virtual void minimumWeaponRange();
    virtual void passableTile();
    virtual void facetToNextWaypoint();
    virtual void currentTargetID();
    virtual void currentTargetX();
    virtual void currentTargetY();
    virtual void currentTargetZ();
    virtual void setWaitingToMove();
    virtual void waitingToMove();
    virtual void actionState();
    virtual void keepGatheringWhenObjectIsOut();
    virtual void produceWhenKilledBy();
    virtual void useSameZoneDropsite();
    virtual void logDebug();
    virtual void notify(int id1, int id2, int a, int b, int c, int d);

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    char pad_10[0x20];
    float hp;                       // +0x30
    char pad_34[4];
    float world_x;                  // +0x38
    float world_y;                  // +0x3C
    float world_z;                  // +0x40
    char pad_44[0x44];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                    // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    char pad_08C[0x10];
    float angle;                    // +0x9C
    char pad_0A0[0xE0];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
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
    virtual int canPath(int, int, int, float*, int, int, int);
    virtual int canBidirectionPath();
    virtual int canPathWithObstructions();
    virtual int canPathWithAdditionalPassability();
    virtual int findFirstTerrainAlongExceptionPath();
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(void*, void*, float, void*, int);
    virtual int firstTileAlongLine();
    virtual void* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(void*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual void* findAvoidancePath();
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, void*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void* create_object_list();
    virtual void* create_sprite_list();
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2();
    virtual void set_task();
    virtual void setTaskByTaskID();
    virtual void set_action();
    virtual void set_only_action();
    virtual void set_end_action();
    virtual void* getTask();
    virtual void setup();
    virtual void create_action_list();
    virtual unsigned char area_attack();
    virtual void do_attack();
    virtual void get_armor();
    char pad_180[0x14];
};

class RGE_Missile_Object {
public:
    void init_missile(RGE_Combat_Object* source, RGE_Static_Object* target, float range);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    char pad_194[0x30];
    virtual unsigned char attack(RGE_Static_Object* target, float x, RGE_Combat_Object* other, float y, float z); // +0x228
    unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* other);
};
#endif

#include <math.h>
#pragma intrinsic(cos)
#pragma intrinsic(sin)
#pragma intrinsic(sqrt)

extern "C" long __cdecl _ftol();
extern float DAT_0056f49c;
extern float DAT_0056f4ac;

unsigned char RGE_Combat_Object::attack(RGE_Static_Object* target, RGE_Combat_Object* other)
{
    float c;
    float s;
    float range;

    if (target == 0) {
        return 0;
    }

    short missile_id = this->master_obj->missile_id;
    if (missile_id >= 0) {
        float radius_x = this->master_obj->radius_x;
        float radius_y = this->master_obj->radius_y;
        c = (float)cos(this->angle);
        s = (float)sin(this->angle);
        range = (float)sqrt(radius_x * radius_x + radius_y * radius_y) +
            this->master_obj->weapon_range - DAT_0056f4ac;

        RGE_Missile_Object* missile = (RGE_Missile_Object*)this->owner->master_objects[missile_id]->make_new_obj(this->owner,
            this->world_x + c * this->master_obj->weapon_offset_y - s * this->master_obj->weapon_offset_x,
            this->world_y + s * this->master_obj->weapon_offset_y + c * this->master_obj->weapon_offset_x,
            this->world_z + this->master_obj->weapon_offset_z);
        missile->init_missile(this, target, range);
        this->notify(this->id, this->id, 0x200, 0x258, target->id, 0);
        if (this->master_obj->weapon_range > DAT_0056f49c) {
            if (1 == target->owner->computerPlayer()) {
                int hp = (int)target->hp;
                target->notify(this->id, target->id, 0x20F, this->id, hp, target->master_obj->hp);
                return 1;
            }
        }
    } else {
        this->attack(target, this->world_x, other, this->world_y, this->world_z);
    }
    return 1;
}
