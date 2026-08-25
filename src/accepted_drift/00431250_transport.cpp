// VA: 00431250, RGE_Combat_Object::transport, 230 bytes
// Source: com_obj.cpp lines 1146-1172
// __thiscall virtual, returns int, ret 10h (float x, float y, float z, int w)
//
// Attempt log:
// probe 1-10 (prior workers): thunk classes + extern wrappers + flat layout,
//   79% diff, wrong layout (+0x180/0x188 vs +0x184), wrong EH basin.
// This session (sa-e16e6199): mirror the exact matched sibling 00431340 unload
//   (same TU com_obj.cpp, same class surface, same /GX EH frame). Baseline 82 diff.
// Probes (source-shape, all same emitted tail except noted):
//   - if/else, goto-exit result, result+if/else: VC5 canonicalizes -> inline ret0 epilogue (82 diff, 249B)
//   - comma-return work,1: worse (175 diff, 276B)
//   - goto fail at end: 82 diff (249B)
//   - result=0; if (transport!=0) {body; result=1;} return result;  => BEST 67 diff,
//     230/230 bytes, shape 93.9%, exact-blocks 93.8%, edit-diff 14.
// Left in scratch: single-return shape shares the epilogue exactly with the original
//   (tail [call;mov eax,1] + [epilogue] blocks match byte-for-byte; mov eax,1 not hoisted
//   into epilogue; original fs-restore interleave reproduced), but the ret0 head differs:
//   rebuilt emits [xor eax,eax; try=-1; test edi,edi; je epilogue] (xor hoisted before
//   the test), original emits [test; try=-1; jne body; xor eax,eax; jmp epilogue]
//   (xor inside inline ret0 block, body as jne target).
// Next lead: plain two-return shape has right head but VC5 duplicates the epilogue and
//   hoists mov eax,1 into it (preventing the cross-jump); the single-return shape shares
//   the epilogue but hoists xor eax,eax before the test. A shape that yields BOTH
//   (xor after the test AND shared epilogue) should be exact. Candidates not yet tried:
//   a mixed form with an explicit shared exit label reached by the ret0 via a conditional
//   edge rather than an unconditional goto, or controlling the try-level reset scheduling
//   (reset is emitted between test and branch in the original; VC5's scheduling of the
//   /GX end-of-try store relative to the source if-test is the lever).
// Session sa-10e3eb44-r1:
//   - ABI evidence identifies action slot +34 as int work(...); changing the local
//     declaration from void to int was emitted-code neutral.
//   - Reusing top-level action/transport temporaries and explicit result/goto labels
//     were codegen duplicates or regressed to 82 diff / 249B; a shared action/owner
//     work label regressed structurally (210 diff), and a do/while-break wrapper
//     added an extra vslot call (175 diff / 276B). All were restored.
//   - Best clean reconstruction remains the result=0; positive transport guard form
//     at 67 positional diff, exact size/calls, with the tail epilogue aligned.
// Main-agent normalization replaced the cast-to-helper virtual call with a real
// inherited virtual surface and direct member call; emitted code is unchanged.
// Fresh worker: explicit null/success result arms reproduced the prior 249-byte
// two-return basin, while a switch diagnostic grew to 276 bytes; both were rolled
// back to the natural single-result guard.
// Fresh session probes: returning the allocation pointer as the final boolean
// duplicated the shared work call; positive guard with an explicit else did
// the same and expanded the EH exits.  A base-typed transport pointer was
// codegen-neutral.  Preserve the derived action ownership and clean guard.
// Main-agent audit retained direct inherited virtual calls and canonical action
// ownership; no manual dispatch or EH-tail steering survives.
// Session orch2-431250-abi: normalized the +0x208 inherited action-install call
// to set_action(RGE_Action*) and the +0x34 action call to RGE_Action::work,
// following exact donors 00406470, 00430A90, and 004308C0. Names and typed
// surfaces are canonical; VC5 emitted the same 230-byte / 67-diff code.
// Fresh bounded pass (orch-comobj-02): mixed shared-label/null-result,
// allocation-scoped result, assignment-in-condition, and direct-null-return
// forms all regressed to 82-97 diff or larger EH tails; no compiler-facing
// variant was retained. ABI cleanup then modeled the proven RGE_Static_Object ->
// RGE_Action_Object ownership, typed RGE_Action::work receiver, typed action-list
// result, and exact RGE_Action_Transport(RGE_Action_Object*, RGE_Task*,...) ABI;
// these are source-canonical and codegen-neutral, while correcting the ctor
// relocation identity. Remaining mismatch starts at +0x64: VC5 emits xor eax
// before the EH reset/test, versus the oracle's post-test null xor and shared
// epilogue. Current clean reconstruction is 230 bytes with 67 strict differing
// bytes, 93.90% shape, exact 9-call multiset and exact size.
// Session sa-59d01a08-r1 (bounded pass): allocation-predicate result locals,
// split/redundant null guards, late result declaration, success-first goto,
// nested null/positive guards, null-goto, and result propagation through the
// existing-action arm either regressed structurally or reproduced the known
// 249-byte duplicated-cleanup basin. A seven-case /GX branch lab found no exact
// emitted group; its baseline reproduced the current 230-byte/67-byte best.
// Session follow-431250-r1:
//   - Positive allocation guard with an explicit null-return else was a new
//     block-layout axis. It produced 276 bytes/175 diff, added a second work
//     call, and lost the existing-action tail merge. Rolled back.
// Final lead: the remaining EH-tail difference is compiler block/cleanup
// placement, not a call, layout, or ABI mismatch; retain the clean typed source.
// Current bounded pass: ABI/dossier/donor review and a fresh shared action/work
// tail hypothesis were tested. The shared typed locals grew the body to 250
// bytes and lost the exact early blocks, so the clean EH reconstruction remains.
// Session sa65-431250: reassessed the 67-byte frontier with dossier, ABI, and
// same-TU donors. Natural null/success arms, shared done labels, mixed return
// placement, top-level transport declaration, comparison operand order, and
// result initialization placement were tested. They either reproduced the
// 82-byte duplicated-cleanup basin, changed size/calls, or were codegen-neutral.
// Restored this typed positive-guard source; remaining lead is VC5 EH-tail
// block placement between the post-constructor test and shared epilogue.
// Session sa-152e0879-r1: fresh dossier/donor review and 10 source-shape probes
// confirmed the 230-byte/67-byte frontier. Predicate-return, explicit else,
// result-arm, declaration-initialization, and goto forms lost the shared work
// tail or expanded the EH exits. Final validation was unchanged; source paused.
// Session sa-936f45ea-r1: fresh dossier, donor, ABI, and exact sibling review
// confirmed the same frontier. Shared action/work-object locals expanded the
// body to 231 bytes and 210 diff; null-result gotos and both-arm result forms
// reproduced 249 bytes and 82 diff. Predicate return added a work call; a
// conditional result added 3 bytes and 73 diff. The exact donor ctor's int
// spelling and pointer-truth spelling were codegen-neutral. Restored the
// pinned typed positive-guard source. Final rebuilt validation remains 230
// bytes, 67 strict differing bytes, 93.90% shape, exact 9 calls and size.
// Session sa-35a2562c-r1: fresh dossier review preserved the typed action and
// object ownership. A null-result goto grew to 249 bytes/82 diff. Initializing
// success first grew to 283 bytes/179 diff and added a work call. Both probes
// were restored. The clean typed positive-guard source remains the frontier.
// Session sa-5b0a0308-r1: revisited the first divergence at +0x64 with 16
// source-shape, lifetime, declaration, and control-flow hypotheses. Explicit
// null/success arms and direct null returns reproduced the 249-byte/82-diff
// basin. Split complementary guards reached 238 bytes/70 diff but added a
// second null test. Declaration and initialization placement was codegen
// neutral when it preserved the positive-guard basin; moving zero before new
// grew the body to 284 bytes and added a work call. A /GX ambient-context lab
// with 32 declaration samples and <new.h>/<stdlib.h> combinations produced one
// unchanged 230-byte group, with no exact result. All variants were restored.
// The clean typed positive-guard source remains 230 bytes with 67 strict
// differing bytes. The blocker is still VC5 EH-tail block placement: rebuilt
// zeroes EAX before the EH reset/test, while the oracle zeroes it after the test
// and jumps to the shared epilogue.
// Session sa-83f2ea7a-r1: same-file cleanup follow-up tested 20 new hypotheses.
// Explicit null/success arms, null-only gotos, result predicates and ternaries,
// shared typed action/work locals, donor void/void* spellings, nested allocation
// scope, existing-action shared return, and Ghidra local declaration order all
// reproduced the 230-byte/67-diff basin or regressed to duplicated EH tails.
// No exact or better policy-valid frontier was found. Restored the pinned clean
// typed positive-guard source; the remaining difference starts at the constructor
// null test and is still the EH reset/test block topology.
// Session sa-a65e7484-r1: re-audited result ownership, constructor result use,
// null-test order, and side effects with ten fresh source probes. The oracle
// tests the constructor result first, resets EH state, then zeroes EAX only on
// the null edge and jumps to one epilogue. Success deletes the old list, sets
// the new action, calls work with this, and returns one. The existing-action
// path calls work with a null object and also returns one. The current source
// preserves these effects and fault order, but its result = 0 before the
// positive guard is compiler-active: VC5 emits xor EAX before the null test.
// Branch-local result forms either duplicate cleanup, add calls, or widen the
// body. Base/derived constructor-result ownership and action local forms are
// codegen-neutral or worse. No natural exact form was found; keep this clean
// typed baseline. This is a source-model mismatch, not a proved shipped bug.
// Source-gate pass: restored the reviewed RGE_Static_Object -> RGE_Animated_Object
// -> RGE_Moving_Object -> RGE_Action_Object chain. Coordinates now come from
// inherited static-object fields, actions belongs to RGE_Action_Object, and
// set_action is the canonical +208 virtual. RGE_Action now uses canonical
// type(), work(), and typed object surfaces. The body remains 230 bytes with
// nine ordered calls and the same 67-byte EH-tail mismatch.
// Session sa-15c047af-r1: fresh canonical-ownership pass completed 16 probes.
// Natural null/positive fallback arms and success-first arms lost the shared
// work tail or grew to 249-283 bytes. Shared typed work locals changed the
// early CFG. Scoped transport lifetime changed the call count. Result and
// action declaration-order, pointer lifetime, named-zero, nested success-scope,
// and base-result ABI forms were codegen-neutral at the 230/67 frontier.
// Predicate result initialization reached 233/73. Early or pre-allocation zero
// stores reached 283-284 bytes. Explicit boolean return reached 264/164 and
// added a work call. The canonical derived constructor, typed arguments,
// inherited action methods, and /GX cleanup source remain unchanged.
// ACCEPTED DRIFT: The residual moves XOR and TEST around the same EH-state
// reset. These instructions cannot throw, and both builds set state -1 before
// the next memory access or call. Null returns zero. Success performs the same
// list deletion, action install, work call, and one return. Size, all nine
// calls, values, memory effects, cleanup, and fault behavior match.
// FLAGS: /nologo /c /O2 /Oy /GX

#include <stddef.h>

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Action;
class RGE_Sprite;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class Path;
struct XYPoint;
struct XYZPoint;
struct XYZBYTEPoint;
template<class T> class ManagedArray;

// RGE_Action_List (direct calls)
#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Action_List {
public:
    uchar have_action();
    RGE_Action* get_action();
    void delete_list();
};

// RGE_Action's names and types are part of the shared action ABI.  In
// particular, type() is slot +18 and work() is slot +34.
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook();
    virtual void save(int file);
    virtual short type();
    virtual void first_in_stack(uchar value);
    virtual uchar inside_obj_update();
    virtual uchar idle_update();
    virtual uchar update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual uchar attack_response(RGE_Static_Object* object);
    virtual uchar relation_response(long value, uchar relation);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* destination);
    virtual void get_state_name(char* name);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(uchar value);

    short action_type;     // +0x04
    uchar gap_06[2];       // +0x06
    RGE_Action_Object* obj; // +0x08
    uchar state;           // +0x0C
    uchar gap_0D[3];       // +0x0D
    RGE_Static_Object* target_obj;      // +0x10
    RGE_Static_Object* target_obj2;     // +0x14
    int targetID;          // +0x18
    int target2ID;         // +0x1C
    float target_x;        // +0x20
    float target_y;        // +0x24
    float target_z;        // +0x28
    float timer;           // +0x2C
    RGE_Task* task;        // +0x30
    RGE_Action_List* sub_actions;     // +0x34
    RGE_Sprite* sprite;               // +0x38
    uchar subActionValue;  // +0x3C
    uchar gap_3D[3];       // +0x3D
};

class RGE_Action_Transport : public RGE_Action {
public:
    RGE_Action_Transport(RGE_Action_Object* obj, RGE_Task* task,
                         float x, float y, float z);
};

// These are the reviewed object classes.  The target only uses inherited
// coordinates, the action-list member, and the +208 set_action slot.  Keep the
// real inheritance chain instead of introducing a synthetic combat base.
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual uchar facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(uchar);
    virtual uchar waitingToMove();
    virtual uchar actionState();
    virtual uchar keepGatheringWhenObjectIsOut(int);
    virtual uchar produceWhenKilledBy(int);
    virtual uchar useSameZoneDropsite();
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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    int id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                   // +0x0C
    uchar gap_10[0x28];                  // +0x10..+0x37
    float world_x;                       // +0x38
    float world_y;                       // +0x3C
    float world_z;                       // +0x40
    uchar gap_44[0x44];                  // +0x44..+0x87
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    float speed;                         // +0x88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual void stop_moving();
    virtual uchar turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    uchar gap_8C[0xF4];                  // +0x8C..+0x17F
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual void work2(RGE_Static_Object*, float, float, float, uchar);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual void set_action(RGE_Action* action);       // slot +208
    virtual void set_only_action(RGE_Action* action);
    virtual void set_end_action(RGE_Action* action);

    uchar waiting;                       // +0x180
    uchar gap_181[3];                    // +0x181..+0x183
    RGE_Action_List* actions;            // +0x184
    uchar command_flag;                  // +0x188
    uchar gap_189[3];                    // +0x189..+0x18B
    int lastActionValue;                 // +0x18C
    int lastActionStateValue;            // +0x190
};

class RGE_Task {
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    uchar gap_194[0x30];                 // +0x194..+0x1C3

    int transport(float x, float y, float z, int w);
};
#endif

int RGE_Combat_Object::transport(float x, float y, float z, int w)
{
    int result;

    if (actions->have_action() == 1) {
        RGE_Action* action = (RGE_Action*)actions->get_action();
        if (action->type() == 0x0C) {
            // Call get_action() AGAIN (original does this)
            RGE_Action* action2 = (RGE_Action*)actions->get_action();
            action2->work(0, x, y, z);
            return 1;
        }
    }

    RGE_Action_Transport* transport = new RGE_Action_Transport(this, 0, x, y, z);
    result = 0;
    if (transport != 0) {
        actions->delete_list();
        this->set_action(transport);
        transport->work(this, x, y, z);
        result = 1;
    }
    return result;
}
