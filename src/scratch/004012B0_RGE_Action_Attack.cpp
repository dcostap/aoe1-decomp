// RGE_Action_Attack::RGE_Action_Attack (004012B0)
// PDB source: Act_atak.cpp:145-190
// Size: 237 bytes
// PAUSED - exact matching exhausted this bounded pass; remaining drift is
// confined to initial field-load scheduling.

// Attempt log:
// - Baseline: wrong local base-call spelling and wrong parameter widths; 36 bytes.
// - ABI probe: real RGE_Action constructor call and float/short parameter ABI; 35 bytes.
// - Full same-TU RGE_Action virtual/member ownership was restored; it is codegen-
//   equivalent to the earlier narrow layout but is the canonical source surface.
// - Natural coordinate/range ordering and typed/direct RGE_Sprite chains were tested;
//   the best emitted result stayed 33 bytes (91.55% shape; 37/71 exact blocks).
// - Per-guard object/sprite locals and split p5 source/result locals were also tested;
//   they either duplicated the result or produced a structural regression.
// - A 12-variant permutation lab over the three coordinate and two range stores
//   found no exact codegen; the current x/z/y plus range/min order is the best
//   plausible family (33 bytes, 91.55% shape).
// - A current-context assignment lab found one diagnostic x/range/z/min/y
//   spelling at 32 positional bytes, but it moved the range register/store
//   topology farther from the binary and is not the PDB/decompiler-supported
//   canonical order; it was not promoted into the living source.
// - A six-way shared-local surface lab was codegen-neutral for the current
//   typed guards; sharing the action-object local instead forced an EBP frame.
// - Restored the proven 0x5C attack tail and typed the action-object/master-combat
//   inheritance and offsets.  Correcting the inherited gaps preserved the same
//   33-byte output; retain this canonical ownership rather than the old fake
//   sprite-at-+8 surface.
// - Final bounded result: 33 positional bytes (13.9241%), 40 edit bytes (16.88%);
//   all calls, size, frame, CFG, and the suffix block topology match.
// Fresh bounded pass (orch-actatak-01):
// - Completed the proven RGE_Master_Combat_Object layout through 0x148; emitted
//   code was unchanged, so the remaining issue is not incomplete tail size.
// - Direct member-result fallback assignments under the canonical master surface
//   created a +6-byte structural tail (130 bytes), then were rolled back.
// - Hoisting fallback pointer declarations, adding the full derived virtual
//   declaration surface, and typing the p5 owner as RGE_Master_Moving_Object
//   were codegen duplicates of the clean candidate.
// - Interleaving range/min before target_z/target_y and adding coordinate aliases
//   worsened the first block (34 bytes); delaying wait_sprite until after flags
//   worsened it to 52 bytes. All were rolled back.
// Fresh bounded pass (wave21-actatak-01):
// - Direct typed master-member fallback chains were structurally worse (240/243
//   bytes; 119/130-byte diff) and were rolled back; the separate natural result
//   local remains the best readable p5 ownership form.
// - Swapping fallback-local declaration order was a codegen duplicate of the
//   clean candidate; five register-qualified parameter variants were also one
//   duplicate codegen group.
// - Five standard-header context variants were codegen duplicates; a focused
//   wait-sprite assignment-order lab found no productive source shape. None displaced
//   the canonical typed constructor.
// Fresh bounded pass (sa-2ceebd29-r1-004012B0):
// - Explicit `this->` qualification on the initial stores was a codegen duplicate.
// - A 49-case combined field/init-order lab found the diagnostic 32-byte
//   x/range/z/min/y order, but it still lost the binary's p4/p3 early loads and
//   is not a canonical source improvement; all frame/sprite-init alternatives
//   were farther away.
// - Moving frame assignments into the early block, removing/reducing fallback
//   pointer locals, and changing the owner pointer type were duplicate or worse;
//   replacing the proven zero global with DAT_0056e0b8 worsened to 41 bytes.
// - Early typed z/y value locals produced 34 bytes and were rolled back. The
//   clean typed constructor remains the best plausible source; the unresolved
//   hunk is initial VC5 load/store scheduling and suffix register coloring.
// Fresh bounded pass (orch-004012B0-L):
// - Restoring the decompiler-supported x/range/min/z/y assignment order worsened
//   to 34 bytes and was rolled back.
// - Swapping the natural y/z assignment order kept the size but worsened to 34
//   bytes; it improved shape only, so it was rolled back.
// - Direct p5 fallback member stores caused a 240-byte structural basin and were
//   rolled back. A one-local typed p5 fallback was codegen-identical to the clean
//   source, so it was also rolled back.
// - No new source or layout lead displaced the canonical typed constructor.
// Remaining lead: reconstruct the original Act_atak.cpp assignment/declaration
// context for the first coordinate/range block; do not retain metric-only aliases.
// Fresh bounded pass (orch2-4012B0-fields):
// - Renamed the attack sprite fields to the type-reference ownership names
//   move_sprite, fight_sprite, and wait_sprite without changing offsets or stores.
//   The canonical class surface produced identical code (33-byte diff).
// Fresh bounded pass (close-4012B0-r1):
// - A natural p5 fallback local with a repeated typed master chain improved the
//   diagnostic result to 22 bytes. Removing the guard alias or sharing its master
//   regressed to 33 bytes; those forms were rolled back.
// - Combining that p5 local with x/range/z/min/y assignment order reached 21 bytes
//   and 92.96% shape, but it moved p4/p3 loads away from the original early band.
//   It remains diagnostic evidence, not the living source.
// - Final source is the restored canonical typed constructor: 33 bytes, 91.55%
//   shape, exact size/frame/CFG/call set. Remaining gap is initial block scheduling.
// Fresh bounded pass (tu-actatak-4012B0):
// - Rechecked the original Act_atak.cpp line bands, same-TU constructor donor,
//   ABI, and first paired hunk. The clean typed source still matches size,
//   frame, calls, CFG, and suffix islands, but not the initial load/store order.
// - Earlier decompiler-order and local-lifetime probes already covered the
//   remaining plausible source families. No evidence-backed new lead remains;
//   retain the canonical sprite and master-object ownership surface.
// Fresh bounded pass (sa-8e837474-r1):
// - The period type surface confirms RGE_Static_Object::master_obj is the
//   RGE_Master_Static_Object base pointer. The same-TU copy-sprite donor's
//   narrower RGE_Master_Action_Object pointer was a codegen duplicate.
// - A named RGE_Master_Moving_Object source plus direct member fallback
//   removed the shadow local but created a 240-byte structural tail; rolled
//   back. Direct member fallback through the combat surface produced the same
//   structural drift. The typed result local remains the best source shape.
//
// Fresh bounded pass (sa-b8d4f6c9-r1):
// - Restoring the scoped p5 result local improved the current source from 33
//   to 22 bytes without changing size, calls, CFG, or the exact suffix.
// - The natural x/range/z/min/y assignment order reached 21 bytes and 92.96%
//   shape. It preserves the original range/min/z/y store topology; retain it
//   as the best readable source despite the p4/p3 load-order drift.
// - x/range/min/z/y reached 23 bytes, x/z/range/min/y reached 22 bytes, and
//   x/z/range/y/min reached 23 bytes. Guard-alias, shared-master, and local
//   coordinate variants were worse or duplicates and were rolled back.
// - Remaining drift starts at +0015 in the initial load schedule. No further
//   evidence-backed source lead remains in this bounded pass.
// Fresh bounded pass (sa-c0ac4b5b-r1):
// - Rechecked the dossier, constructor ABI, original Act_atak.cpp decomp line
//   order, and same-TU constructor donors. The clean source remains 21 bytes
//   away with exact size, frame, CFG, and ordered call set.
// - A named typed combat-master local in the p5 fallback worsened the result to
//   32 bytes. It was restored. The remaining +0015 hunk and p5 register map
//   have no new evidence-backed natural source lead.
// Fresh bounded pass (sa-f0203f84-r1):
// - Tested coordinate-first x/z/y and x/y/z assignment orders, plus a sequenced
//   coordinate comma expression. They produced 22, 23, and duplicate 22-byte
//   results, so they were restored.
// - Removing the p5 object alias worsened the result to 32 bytes. Hoisting the
//   p5 result, or both p5 locals, was codegen-identical to the clean source.
//   The pinned x/range/z/min/y source remains the simplest natural candidate.
// - Final validation retains 237-byte size, no frame, exact call set, and the
//   original EH-free constructor shape. The +0015 initial scheduling hunk and
//   p5 register map remain unresolved without compiler-steering artifacts.
// Fresh bounded pass (sa-5f84b7ee-r1):
// - A 32-case ambient declaration sweep kept the same 237-byte, 21-byte-diff
//   output. It did not change the initial register schedule.
// - Proven base-owner typing, inherited-field qualification, and natural p5
//   parameter-home reuse were codegen duplicates or metric-neutral. The clean
//   typed constructor remains the best source; no exact natural variant was
//   found.
// Fresh bounded pass (sa-a3e013d4-r1):
// - Read the complete target history, dossier, PDB class/type dumps, and exact
//   Act_atak.cpp donors before editing.
// - Replaced struct spellings and generic vfNN action slots with canonical class
//   names, inheritance, field names, and RGE_Action methods.
// - Replaced PDB-proven master, static, moving, and action object spans with
//   named fields. Remaining pads are alignment or end padding.
// - The natural source still emits 237 bytes with the exact call set, frame,
//   CFG, and 21 positional bytes of drift. No exact claim is made.

// Key structural insights confirmed:
// - 11 stack params + this(ecx): (RGE_Action_Object*,float,float,float,RGE_Sprite*,
//   RGE_Sprite*,RGE_Sprite*,float,float,short,short) → ret 2Ch
// - Base ctor: __thiscall RGE_Action::ctor(RGE_Action_Object*, int flag)
// - RGE_Action is 0x20 bytes (vtable +04, type +06, pad, obj +08, fields +0C..+1F)
// - RGE_Action_Attack fields from +20: target coordinates, master sprites,
//   range/min-range, frame shorts, and three flags plus tail padding.
// - Sprite overrides: if null, get from obj->master_obj run/move/fight/
//   sprite fields at +0xC0/+0xBC, +0xFC, +0x18; range uses +0x114.
// - vtable=0x56E058, type=9, indirect_fire=2
// Main-agent audit retained compiler-owned vptr setup and the natural 0.4f
// fallback assignment.
// Source-gate audit:
// - PDB class spellings, inheritance, field names, and action virtual names now
//   use the reviewed canonical declarations.
// - Proven object fields replace their old opaque spans. Remaining pads are
//   PDB-proven alignment or end padding.
// Fresh bounded pass (sa-5ca95fb2-r1):
// - Tested 20 distinct initializer-list, body-order, inherited-field, and
//   sprite-owner hypotheses from the original assembly and PDB line bands.
// - Initializing derived fields moved or worsened the first block. Coordinate
//   orders x/z/y and x/range/min/z/y reached 22 and 23 bytes, while the pinned
//   x/range/z/min/y body stayed at 21 bytes. Typed base-owner and base-pointer
//   forms were codegen duplicates. No natural initializer/body form recovered
//   the original register map.
// - Final validation: 237 bytes, 71 instructions, exact call set, no frame,
//   and 21 positional bytes of register-only drift beginning at +0015.

class RGE_Sprite;
class RGE_Action_List;
class RGE_Task_List;
class RGE_Player;
class RGE_Sound;
class RGE_Armor_Weapon_Info;
class RGE_Damage_Sprite_Info;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;
class RGE_Object_Node;
class UnitAIModule;

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char _pad_0D[3];
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};

class XYPoint {
public:
    int x;
    int y;
};

class XYZBYTEPoint {
public:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;       // +04
    unsigned char _pad_05[3];
    char* name;                      // +08
    short string_id;                 // +0C
    short string_id2;                // +0E
    short id;                        // +10
    short copy_id;                   // +12
    short object_group;              // +14
    unsigned char _pad_16[2];
    RGE_Sprite* sprite;              // +18
    RGE_Sprite* death_sprite;        // +1C
    RGE_Sprite* undead_sprite;       // +20
    unsigned char undead_flag;       // +24
    unsigned char _pad_25[1];
    short hp;                        // +26
    float los;                       // +28
    unsigned char obj_max;           // +2C
    unsigned char _pad_2D[3];
    float radius_x;                  // +30
    float radius_y;                  // +34
    float radius_z;                  // +38
    RGE_Sound* selected_sound;       // +3C
    RGE_Sound* created_sound;        // +40
    RGE_Sound* death_sound;          // +44
    short death_spawn_obj_id;        // +48
    unsigned char sort_number;       // +4A
    unsigned char can_be_built_on;   // +4B
    short button_pict;               // +4C
    unsigned char hide_in_scenario_editor; // +4E
    unsigned char _pad_4F[1];
    short portrait_pict;             // +50
    unsigned char available;         // +52
    unsigned char _pad_53[1];
    short tile_req1;                 // +54
    short tile_req2;                 // +56
    short center_tile_req1;          // +58
    short center_tile_req2;          // +5A
    float construction_radius_x;     // +5C
    float construction_radius_y;     // +60
    unsigned char elevation_flag;    // +64
    unsigned char fog_flag;          // +65
    short terrain;                   // +66
    unsigned char movement_type;     // +68
    unsigned char _pad_69[1];
    short attribute_type_held[3];    // +6A
    float attribute_amount_held[3];  // +70
    short attribute_max_amount;      // +7C
    unsigned char _pad_7E[2];
    float attribute_rot;             // +80
    float multiple_attribute_mod;    // +84
    unsigned char attribute_flag[3]; // +88
    unsigned char area_effect_object_level; // +8B
    unsigned char combat_level;      // +8C
    unsigned char select_level;      // +8D
    unsigned char map_draw_level;    // +8E
    unsigned char unit_level;        // +8F
    unsigned char map_color;         // +90
    unsigned char attack_reaction;   // +91
    unsigned char convert_terrain_flag; // +92
    unsigned char damage_sprite_num; // +93
    RGE_Damage_Sprite_Info* damage_sprites; // +94
    long help_string_id;             // +98
    long help_page_id;               // +9C
    long hotkey_id;                  // +A0
    unsigned char recyclable;        // +A4
    unsigned char track_as_resource; // +A5
    unsigned char create_doppleganger_on_death; // +A6
    unsigned char resource_group;    // +A7
    unsigned char draw_flag;         // +A8
    unsigned char draw_color;        // +A9
    unsigned char _pad_AA[2];
    float outline_radius_x;          // +AC
    float outline_radius_y;          // +B0
    float outline_radius_z;          // +B4
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                     // +B8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;         // +BC
    RGE_Sprite* run_sprite;          // +C0
    float turn_speed;                // +C4
    unsigned char size_class;        // +C8
    unsigned char _pad_C9[1];
    short obj_trail_id;              // +CA
    unsigned char obj_trail_options; // +CC
    unsigned char _pad_CD[3];
    float obj_trail_spacing;         // +D0
    unsigned char move_algorithem;   // +D4
    unsigned char _pad_D5[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;            // +D8
    short default_task;              // +DC
    unsigned char _pad_DE[2];
    float search_radius;             // +E0
    float work_rate;                 // +E4
    short drop_site;                 // +E8
    short backup_drop_site;          // +EA
    unsigned char task_by_group;     // +EC
    unsigned char _pad_ED[3];
    RGE_Sound* command_sound;        // +F0
    RGE_Sound* move_sound;           // +F4
    unsigned char run_pattern;       // +F8
    unsigned char _pad_F9[3];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;        // +FC
    unsigned char base_armor;        // +100
    unsigned char _pad_101[1];
    short armor_num;                 // +102
    RGE_Armor_Weapon_Info* armor;    // +104
    short weapon_num;                // +108
    unsigned char _pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;  // +10C
    short defense_terrain_bonus;     // +110
    unsigned char _pad_112[2];
    float weapon_range;              // +114
    float area_effect_range;         // +118
    unsigned char area_effect_level; // +11C
    unsigned char _pad_11D[3];
    float speed_of_attack;           // +120
    short missile_id;                // +124
    short base_hit_chance;           // +126
    unsigned char break_off_combat;  // +128
    unsigned char _pad_129[1];
    short fire_missile_at_frame;     // +12A
    float weapon_offset_x;           // +12C
    float weapon_offset_y;           // +130
    float weapon_offset_z;           // +134
    float minimum_weapon_range;      // +138
    short orig_armor;                // +13C
    short orig_weapon;               // +13E
    float orig_weapon_range;         // +140
    float orig_speed_of_attack;      // +144
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;                         // +04
    RGE_Master_Static_Object* master_obj; // +08
    RGE_Player* owner;               // +0C
    RGE_Sprite* sprite;               // +10
    RGE_Sprite* old_sprite;           // +14
    RGE_Active_Sprite_List* sprite_list; // +18
    RGE_Tile* tile;                   // +1C
    RGE_Static_Object* inside_obj;    // +20
    RGE_Object_List* objects;         // +24
    short screen_x_offset;            // +28
    short screen_y_offset;            // +2A
    short shadow_x_offset;            // +2C
    short shadow_y_offset;            // +2E
    float hp;                         // +30
    unsigned char curr_damage_percent; // +34
    unsigned char facet;              // +35
    unsigned char selected;           // +36
    unsigned char selected_group;     // +37
    float world_x;                    // +38
    float world_y;                    // +3C
    float world_z;                    // +40
    float attribute_amount_held;      // +44
    unsigned char object_state;       // +48
    unsigned char sleep_flag;         // +49
    unsigned char dopple_flag;        // +4A
    unsigned char goto_sleep_flag;   // +4B
    short attribute_type_held;        // +4C
    unsigned char type;               // +4E
    unsigned char worker_num;         // +4F
    RGE_Object_Node* player_object_node; // +50
    ManagedArray<int> pathingGroupMembers; // +54
    ManagedArray<int> groupMembers;   // +64
    UnitAIModule* unitAIValue;        // +74
    int groupCommanderValue;          // +78
    int zoneMapIndex;                 // +7C
    float groupRangeValue;            // +80
    unsigned char inObstructionMapValue; // +84
    unsigned char lastInObstructionMapValue; // +85
    unsigned char underAttackValue;   // +86
    unsigned char _pad_87[1];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;                     // +88
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;            // +8C
    float velocity_x;                 // +90
    float velocity_y;                 // +94
    float velocity_z;                 // +98
    float angle;                      // +9C
    float turn_towards_time;          // +A0
    Path pathValue;                   // +A4
    Path exceptionPathValue;          // +D8
    Waypoint startValue;              // +10C
    Waypoint goalValue;               // +11C
    float turnTimer;                  // +12C
    float collisionAvoidanceDistance; // +130
    float actionRange;                // +134
    int targetIDValue;                // +138
    float targetRadiusX;              // +13C
    float targetRadiusY;              // +140
    int continueCounter;              // +144
    int rangeStatusValue;             // +148
    int currentTerrainException1;     // +14C
    int currentTerrainException2;     // +150
    unsigned char storePathInExceptionPath; // +154
    unsigned char waitingToMoveValue; // +155
    unsigned char numberWaitDelays;   // +156
    unsigned char _pad_157[1];
    XYPoint minInitialPointValue;     // +158
    XYPoint maxInitialPointValue;     // +160
    XYZBYTEPoint* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16C
    int maxUserDefinedWaypointsValue; // +170
    unsigned char finalUserDefinedWaypoint; // +174
    unsigned char _pad_175[3];
    float closestDistanceToWaypoint;  // +178
    unsigned char lastFacet;          // +17C
    unsigned char lastFacet2;         // +17D
    unsigned char _pad_17E[2];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    unsigned char waiting;            // +180
    unsigned char _pad_181[3];
    RGE_Action_List* actions;         // +184
    unsigned char command_flag;       // +188
    unsigned char _pad_189[3];
    int last_action_value;            // +18C
    int last_action_state_value;      // +190
};

class RGE_Task;

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
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;                // +04
    unsigned char _pad_06[2];         // +06
    RGE_Action_Object* obj;           // +08
    unsigned char state;              // +0C
    unsigned char _pad_0D[3];         // +0D
    RGE_Static_Object* target_obj;    // +10
    RGE_Static_Object* target_obj2;   // +14
    int targetID;                     // +18
    int target2ID;                    // +1C
    float target_x;                   // +20
    float target_y;                   // +24
    float target_z;                   // +28
    float timer;                      // +2C
    RGE_Task* task;                   // +30
    RGE_Action_List* sub_actions;    // +34
    RGE_Sprite* sprite;               // +38
    unsigned char subActionValue;    // +3C
    unsigned char _pad_3D[3];         // +3D
    
    RGE_Action(RGE_Action_Object* obj, int flag);
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual ~RGE_Action_Attack();
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
    unsigned char _pad_5B;
    
    RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                     RGE_Sprite* p5, RGE_Sprite* p6, RGE_Sprite* p7, float p8, float p9,
                     short p10, short p11);
};

RGE_Action_Attack::RGE_Action_Attack(RGE_Action_Object* obj, float p2, float p3, float p4,
                                     RGE_Sprite* p5, RGE_Sprite* p6, RGE_Sprite* p7, float p8, float p9,
                                     short p10, short p11)
    : RGE_Action(obj, 1)
{
    target_x = p2;
    range = p8;
    target_z = p4;
    min_range = p9;
    target_y = p3;
    
    action_type = 9;
    move_sprite = p5;
    fight_sprite = p6;
    wait_sprite = p7;
    missile_id = p10;
    fire_missile_at_frame = p11;
    need_to_attack = 0;
    was_same_owner = 0;
    indirect_fire_flag = 2;

    if (p5 == 0) {
        RGE_Action_Object* object = this->obj;
        RGE_Sprite* move_sprite =
            ((RGE_Master_Combat_Object*)object->master_obj)->run_sprite;
        if (move_sprite == 0) {
            move_sprite =
                ((RGE_Master_Combat_Object*)object->master_obj)->move_sprite;
        }
        this->move_sprite = move_sprite;
    }
    
    if (p6 == 0) {
        RGE_Action_Object* object = this->obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        this->fight_sprite = master->fight_sprite;
    }
    
    if (p7 == 0) {
        RGE_Action_Object* object = this->obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        this->wait_sprite = master->sprite;
    }
    
    if (p8 == 0.0f) {
        RGE_Action_Object* object = this->obj;
        RGE_Master_Combat_Object* master = (RGE_Master_Combat_Object*)object->master_obj;
        range = master->weapon_range;
        if (range == 0.0f) {
            range = 0.4f;
        }
    }
    
}
