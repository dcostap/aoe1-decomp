# Recovery journal: 00401B30 `ready_to_attack`

<!-- recovery-journal-schema:1 -->

## Current state

- Status: `scratch`.
- Living source: `src/act_atak.cpp`.
- PDB source: `C:\msdev\work\age1_x1\Act_atak.cpp`.

## Translation-unit context

Record the PDB module, source order, owning class, address sequence, and exact anchors here.

## Current mismatch

Record the current frame, size, calls, boundaries, relocations, and first structural difference here.

## Recovered attempt history


<!-- recovered:467fd356c88533f4209c -->
### `target-session` `build/target_sessions/00401B30_ready_to_attack.json:1-28`

Mapping: `exact`. target-session probe notes name this target.

```text
probe 1 baseline; result=MISMATCH; diff=681; shape=79.51807228915662: Baseline current source: frame and early FPU block align, but wrong direct ABI identities, status topology, and +58 flag field; 952-byte rebuilt versus 912 original.
probe 2 layout; result=MISMATCH; diff=681; shape=79.81927710843374: Hypothesis 1: notify guard uses inherited subActionValue at +3C, not derived need_to_attack at +58; original reads [esi+3C] in both status arms.
probe 3 control-flow; result=MISMATCH; diff=681; shape=79.81927710843374: Hypothesis 2: reverse no-target threshold condition to distance > max_distance, matching original fcomp/test branch polarity and status-2 fallthrough. [same emitted code as probe 2]
probe 4 control-flow; result=MISMATCH; diff=822; shape=81.53846153846153: Hypothesis 3: model proven range_too_close, range_too_far, and ready labels; original has direct jumps from status stores to line-881, line-909, and line-940 tails.
probe 6 control-flow; result=MISMATCH; diff=1003; shape=28.571428571428573: Hypothesis 4: duplicate close/far status handlers in each range arm; VC5 may tail-merge them while keeping status stores before the proven jumps.
probe 8 layout; result=MISMATCH; diff=681; shape=79.81927710843374: Hypothesis 5: use inherited subActionValue (+3C) for both notify guards; canonical RGE_Action layout and update donor identify this field, while +58 is need_to_attack. [same emitted code as probe 3]
probe 9 control-flow; result=MISMATCH; diff=681; shape=79.81927710843374: Hypothesis 6: make status handling one if/else-if/else chain, matching mutually exclusive range outcomes and potentially avoiding the extra status reload.
probe 10 liveness; result=MISMATCH; diff=849; shape=76.68711656441718: Hypothesis 8: hoist target-range temporaries without initialization so the close label can sit before target max code; this tests original status-0 tail placement while avoiding C2362.
probe 12 control-flow; result=MISMATCH; diff=888; shape=42.64264264264264: Hypothesis 9: route no-target in-range and target exact/tolerance outcomes directly to one ready label, matching original direct branches to EA0 without status-1 stores.
probe 14 abi; result=MISMATCH; diff=681; shape=79.81927710843374: Hypothesis 10 / call-map audit: inspect every unmatched call and relocation identity after canonical +3C field fix; determine whether helper declarations or virtual ownership cause the remaining call-surface gap. [same emitted code as probe 8]
probe 15 control-flow; result=MISMATCH; diff=848; shape=61.9496855345912: Hypothesis 11: route only known status-0 outcomes directly to a shared close label; retain natural status-2 chain to isolate the original D71 handler topology.
probe 17 control-flow; result=MISMATCH; diff=837; shape=61.63522012578616: Hypothesis 12: express the mutually exclusive status tail as a switch with cases 0/2/default; this tests whether VC5 emits the original late handler order.
probe 19 control-flow; result=MISMATCH; diff=894; shape=43.11377245508982: Hypothesis 13: in the no-target radius branch, assign only status 2 on the out-of-range path and jump directly to ready otherwise; this mirrors original JNE EA0 and deferred status-2 store.
probe 21 liveness; result=MISMATCH; diff=655; shape=79.57957957957957: Hypothesis 14: reread this->target_obj for the fog flag, because original C43 reloads [esi+10] instead of reusing EDI target alias.
probe 22 liveness; result=MISMATCH; diff=659; shape=79.57957957957957: Hypothesis 15: bind the direct target reread to a branch-local fog_target alias; test whether VC5 assigns the original EAX/ECX reload colors without changing ownership.
probe 23 liveness; result=MISMATCH; diff=613; shape=80.8955223880597: Hypothesis 16: use direct this->target_obj world fields and distance argument; original C63 reloads target into EDX and D1B pushes that pointer instead of reusing EDI alias.
probe 24 abi; result=MISMATCH; diff=613; shape=80.8955223880597: Hypothesis 17: use the reviewed DAT_0056e0cc extern for the proven -0.3 threshold, restoring original absolute relocation identity at B C1 and D57.
probe 25 liveness; result=MISMATCH; diff=658; shape=80.53892215568862: Hypothesis 19: bind this->target_obj->master_obj to fog_master to test whether the original EAX/ECX fog reload is a master-pointer lifetime rather than direct-expression scheduling.
probe 26 context; result=MISMATCH; diff=613; shape=80.8955223880597: Hypothesis 20: restore explicit period VC5 sqrt intrinsic context; verify whether it controls the proven inline x87 radius lowering. [same emitted code as probe 24]
probe 27 context; result=MISMATCH; diff=613; shape=80.8955223880597: Hypothesis 21: add period <stdlib.h> alongside <math.h> to test the documented VC5 header-context basin without changing source behavior.
probe 29 control-flow; result=MISMATCH; diff=848; shape=64.77987421383648: Hypothesis 1: route close, far, and ready outcomes through labels in the original emitted order; omit success stores and dispatch through direct can_attack/handler jumps.
probe 31 control-flow; result=MISMATCH; diff=473; shape=81.41592920353982: Hypothesis 2: express each proven in-range outcome as a natural local range_status assignment followed by direct can_attack return, testing whether VC5 merges the common success tail without explicit labels.
probe 32 control-flow; result=MISMATCH; diff=596; shape=80.64516129032258: Hypothesis 3: retain direct can_attack returns for no-target, exact, and tolerance success, but let target max-range coordinate updates fall through to the common success tail to remove the extra emitted virtual call.
probe 34 control-flow; result=MISMATCH; diff=653; shape=77.20797720797721: Hypothesis 4: with direct success returns on target exact, tolerance, and target max-range paths, keep no-target max-range as a status assignment to test which branch creates the extra can_attack call.
probe 36 control-flow; result=MISMATCH; diff=609; shape=80.4093567251462: Hypothesis 5: retain direct returns on no-target, tolerance, and target max-range success, but let exact-coordinate success use the common tail; test source-path sensitivity of VC5 tail merging.
probe 38 control-flow; result=MISMATCH; diff=485; shape=80.93841642228739: Hypothesis 6: retain direct can_attack returns for no-target, exact, and target max-range success, but let tolerance success fall through to the common tail; test the fourth source-path variant.
probe 40 control-flow; result=MISMATCH; diff=473; shape=81.41592920353982: Hypothesis 7: reverse only the no-target max-distance condition to explicit far-first form while retaining direct success returns, testing the original JNE-to-can_attack polarity. [same emitted code as probe 31]
probe 42 control-flow; result=MISMATCH; diff=613; shape=80.8955223880597: Hypothesis 8: duplicate the close-handler source directly in the target distance-min arm, testing whether VC5 tail-merges it before the target max-range compare as the original CFG does.
```
<!-- end-recovered:467fd356c88533f4209c -->

<!-- recovered:06f0983ddbd078c0eefb -->
### `ff4a4dcdccc9` `src/scratch/00401B30_ready_to_attack.cpp:1-345`

Mapping: `exact`. historical standalone source path names this target VA.

```text
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
// Authentic Act_atak.cpp context pass (sa-1349a780-r1):
// - The shared /GX wrapper and canonical object/master declarations emitted
//   the same x87 body. The result stays 961 bytes with 613 positional bytes
//   of drift and 22 ordered calls. The module prefix does not move the first
//   distance/range divergence.
// [non-comment lines omitted during migration]
/*
#ifndef ACT_ATAK_CONTEXT_H
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
#endif
*/
```
<!-- end-recovered:06f0983ddbd078c0eefb -->

## Rejected approaches

Record disproved source forms and repeated code-generation basins here.

## Open questions

Record unknown facts and the evidence needed to answer them here.

## Next useful approaches

Record specific evidence-led approaches for the next worker here.

## Worker updates

Add one reviewed summary for each later assignment. Keep raw generated probe data under `build/`.
