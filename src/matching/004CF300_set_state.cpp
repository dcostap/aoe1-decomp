// VA: 004CF300 TRIBE_Action_Hunt::set_state
// PDB source: tact_hnt.cpp
// Attempt log:
// - Replaced the old decompiler-shaped pointer scaffold with the canonical
//   RGE_Action/TRIBE_Action_Hunt ownership and the tact_hnt state switch.
// - Baseline probe: typed action constructors, task/master fields, and the
//   original shared switch tails remain to be checked against VC5 output.
// - Baseline result: exact size, frame, saved registers, and 93.56% shape;
//   remaining structural gap is the switch table and two move-sprite calls.
// - Two state-split probes worsened the ordered calls and size. Restored the
//   baseline. Leave this natural reconstruction in scratch for the next pass.
// - Corrected switch labels from the original jump table: notify is state 3,
//   coordinate Move_To is states 11 and 15, Attack is state 12, and the
//   wait-sprite tail is states 1, 13, and 14.
// - Reopened the two missing direct get_move_sprite call sites: coordinate
//   Move_To and state 6 new_sprite now use the typed helper.
// - Placed state 6 before state 7 to retain the original emitted block order;
//   ordered calls now align with no site gaps. One virtual-slot mismatch remains.
// - Corrected the state-8 depleted branch to read target_obj (+0x10) and call
//   set_target_obj(0), matching original loads and vslot +0x54 at 004CF7D2.
// - Validation: the source now matches the packet's state-to-block mapping;
//   VC5 emitted the prior body unchanged because the jump table is relocated
//   outside the compared function bytes. Leave register tuning for later.
// - Restored timer writes before the coordinate and attack allocations from
//   the original +2C stores; the coordinate block became exact.
// - Corrected typed master offsets (+124, +12A, +138), attack size (0x5C),
//   and task range offset (+24) from constructor access evidence.
// - Modeled object attribute_type_held as a word at +4C, matching the state-7
//   compare and set_attribute slot; strict drift fell to 118 bytes.
// - Tested an early-return depletion branch for state 8; it changed call order
//   and was restored. Keep the natural positive-if form.
// - Reversed the state-7 facet comparison operands to match the original cmp.
// - Exact-finish reversion: the extern zero global and explicit else arm were
//   incidental; the local zero and simple fall-through remain exact.
// - Exact-finish: decisive changes were target_obj (+0x10) in state 8 and the
//   reversed facet compare. The typed action ABI and call surfaces were kept.
//   No tested changes were inseparable. Reusable lesson: verify same-named
//   target fields against each load; a narrow exact stub does not prove intent.
// - Policy cleanup: replaced generic virtual-slot names with canonical donor
//   names and recovered the Static/Animated/Moving/Action inheritance chain.
//   Replaced known gap fields with named class and task layouts.
// - Policy cleanup: restored the reviewed DAT_00575150 extern and canonical
//   master hierarchy. Derived master casts remain only at proven combat fields.

#ifndef TACT_HNT_SHARED_CONTEXT
class RGE_Sprite;
class TDrawArea;
class RGE_Color_Table;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class Visible_Resource_Manager;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Combat_Object;
class RGE_Static_Object;
class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x80];
    float world_time_delta_seconds;
    RGE_Static_Object* object(int);
};
class RGE_Armor_Weapon_Info;
class RGE_Damage_Sprite_Info;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_Node;
class UnitAIModule;
class LOSTBL;
class Path;
class XYPoint;
class XYZPoint;
class XYZBYTEPoint;
template <class T> class ManagedArray;
class RGE_Static_Object;
class RGE_Action;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Action_Node;
class RGE_Task;
class RGE_Player;
class RGE_Object_List;
class RGE_Sound;
class RGE_Task_List;
class RGE_Tile_List_Node;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char _pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char _pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char _pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char _pad_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char _pad_4F;
    short portrait_pict;
    unsigned char available;
    unsigned char _pad_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char _pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char _pad_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char unit_level;
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    RGE_Damage_Sprite_Info* damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    unsigned char _pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    unsigned char _pad_C9;
    short obj_trail_id;
    unsigned char obj_trail_options;
    unsigned char _pad_CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
    unsigned char _pad_D5[3];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;
    short default_task;
    unsigned char _pad_DE[2];
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    unsigned char _pad_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    unsigned char _pad_F9[3];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    RGE_Sprite* fight_sprite;
    unsigned char base_armor;
    unsigned char _pad_101;
    short armor_num;
    RGE_Armor_Weapon_Info* armor;
    short weapon_num;
    unsigned char _pad_10A[2];
    RGE_Armor_Weapon_Info* weapon;
    short defense_terrain_bonus;
    unsigned char _pad_112[2];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    unsigned char _pad_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char _pad_129;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void _v04();
    virtual void _v08();
    virtual void _v0C();
    virtual void _v10();
    virtual void _v14();
    virtual void _v18();
    virtual void _v1C();
    virtual void _v20();
    virtual void _v24();
    virtual void _v28();
    virtual void _v2C();
    virtual void _v30();
    virtual void _v34();
    virtual void _v38();
    virtual void _v3C();
    virtual void _v40();
    virtual void _v44();
    virtual void _v48();
    virtual void _v4C();
    virtual void _v50();
    virtual void _v54();
    virtual void _v58();
    virtual void trackUnitGather(int, int, int);
    virtual void _v60();
    virtual void _v64();
    virtual void _v68();
    virtual void _v6C();
    virtual void _v70();
    virtual void _v74();
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char _pad_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char _pad_49;
    short id;
    short fallback_attribute;
    unsigned char _pad_4E[2];
    float* attribute_table;
    unsigned char culture;
    unsigned char _pad_55[3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char _pad_82[2];
    unsigned char* relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char _pad_106[2];
    RGE_Color_Table* color_table;
    long tribe_effect;
    Visible_Resource_Manager* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    unsigned char _pad_12E[2];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];
    unsigned char _pad_21D[3];
    int computerPlayer(void);
};

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

class XYZPoint {
public:
    int x;
    int y;
    int z;
};

class XYZBYTEPoint {
public:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

template <class T> class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game(void);
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update(void);
    virtual void check_damage_sprites(void);
    virtual void rehook(void);
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(void);
    virtual void create_doppleganger_when_dying(void);
    virtual void destroy_obj(void);
    virtual void die_die_die(void);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack(void);
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair(void);
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop(void);
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound(void);
    virtual void play_move_sound(void);
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj(void);
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(void);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj(void);
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table(void);
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(void);
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed(void);
    virtual float getAngle(void);
    virtual float maximumSpeed(void);
    virtual float rateOfFire(void);
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability(void);
    virtual float weaponRange(void);
    virtual float minimumWeaponRange(void);
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint(void);
    virtual int currentTargetID(void);
    virtual float currentTargetX(void);
    virtual float currentTargetY(void);
    virtual float currentTargetZ(void);
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove(void);
    virtual unsigned char actionState(void);
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite(void);
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
    virtual int stopAction(void);
    virtual int pause(void);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints(void);
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum(void);
    virtual long get_waypoint_checksum(void);
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list(void);
    virtual RGE_Active_Sprite_List* create_sprite_list(void);

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
    RGE_Object_Node* player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char _pad_87;

    float distance_to_object(RGE_Static_Object*);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    unsigned char storePathInExceptionPath;
    unsigned char waitingToMoveValue;
    unsigned char numberWaitDelays;
    unsigned char _pad_157;
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    XYZBYTEPoint* userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    unsigned char finalUserDefinedWaypoint;
    unsigned char _pad_175[3];
    float closestDistanceToWaypoint;
    unsigned char lastFacet;
    unsigned char lastFacet2;
    unsigned char _pad_17E[2];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game(void);
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update(void);
    virtual void check_damage_sprites(void);
    virtual void rehook(void);
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(void);
    virtual void create_doppleganger_when_dying(void);
    virtual void destroy_obj(void);
    virtual void die_die_die(void);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack(void);
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair(void);
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop(void);
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound(void);
    virtual void play_move_sound(void);
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj(void);
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(void);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj(void);
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table(void);
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(void);
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed(void);
    virtual float getAngle(void);
    virtual float maximumSpeed(void);
    virtual float rateOfFire(void);
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability(void);
    virtual float weaponRange(void);
    virtual float minimumWeaponRange(void);
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint(void);
    virtual int currentTargetID(void);
    virtual float currentTargetX(void);
    virtual float currentTargetY(void);
    virtual float currentTargetZ(void);
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove(void);
    virtual unsigned char actionState(void);
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual unsigned char useSameZoneDropsite(void);
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
    virtual int stopAction(void);
    virtual int pause(void);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int, float*, int, int, int, int, int, int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints(void);
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum(void);
    virtual long get_waypoint_checksum(void);
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list(void);
    virtual RGE_Active_Sprite_List* create_sprite_list(void);
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving(void);
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char);
    virtual void set_task(short);

    unsigned char waiting;
    unsigned char _pad_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char _pad_189[3];
    int lastActionValue;
    int lastActionStateValue;
};

class RGE_Task {
public:
    short task_type;
    short id;
    unsigned char is_default;
    unsigned char _pad_05;
    short action_type;
    short object_group;
    short object_id;
    unsigned char combat_level;
    unsigned char combat_level_flag;
    short terrain_id;
    unsigned char owner_type;
    unsigned char holding_attr;
    unsigned char state_building;
    unsigned char _pad_13;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    unsigned char search_flag;
    unsigned char _pad_29[3];
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
    RGE_Sound* work_sound2;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int, int);
    RGE_Action(int, RGE_Action_Object*, int);
    RGE_Action(RGE_Action_Object*, int);
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook(void);
    virtual void save(int);
    virtual short type(void);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual RGE_Static_Object* get_target_obj2(void);
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    unsigned char _pad_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    unsigned char _pad_0D[3];
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
    unsigned char _pad_3D[3];

    void setSubAction(unsigned char);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int, short);
    virtual RGE_Action* create_task_action(RGE_Task*, RGE_Static_Object*, float, float, float);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);
    virtual void get_action_name(char*);
    virtual void copy_obj(RGE_Master_Action_Object*);
    virtual void copy_obj_sprites(RGE_Master_Action_Object*, RGE_Task*, RGE_Task*);
    virtual ~RGE_Action_List();
    RGE_Action_Object* obj;
    RGE_Action_Node* list;
    void delete_list(void);
    void add_action(RGE_Action*);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Action_Attack(RGE_Action_Object*, RGE_Static_Object*, RGE_Sprite*,
                      RGE_Sprite*, RGE_Sprite*, float, float, short, short);
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
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char _pad_0A[2];
    RGE_Static_Object* find_by_master_ids(long, long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
};

class TRIBE_Action_Hunt : public RGE_Action {
public:
    TRIBE_Action_Hunt(int, RGE_Action_Object*);
    TRIBE_Action_Hunt(RGE_Action_Object*, RGE_Task*, RGE_Static_Object*);
    TRIBE_Action_Hunt(int, RGE_Task*, float, float, float);
    virtual void save(int);
    virtual void first_in_stack(unsigned char);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual void set_state(unsigned char);
    int targetType;

    RGE_Sprite* get_move_sprite(void);
    RGE_Sprite* get_wait_sprite(void);
};

// Reviewed global: inventory/globals/dumps/00575150_DAT_00575150.txt.
extern float DAT_00575150;

#endif

#ifndef TACT_HNT_CONTEXT_ONLY
void TRIBE_Action_Hunt::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x265,
                          this->targetType, 0);
        this->obj->new_sprite(this->get_wait_sprite());
        this->timer = -10.0f;
        return;

    case 2:
        this->obj->new_sprite(this->get_wait_sprite());
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->timer = 0.0f;
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
    case 15: {
        this->timer = 0.0f;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_x, this->target_y, this->target_z,
            this->task->work_range, this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->timer = 0.0f;
        if (this->target_obj == 0) {
            this->set_state(0x0D);
            return;
        }
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        if (this->target_obj->object_state <= 2) {
            this->set_state(0x0C);
            return;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_obj, this->task->work_range,
            this->get_move_sprite());
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 12: {
        this->timer = 0.0f;
        // BINARY NOTE: The action master is stored as a static-master pointer.
        // These three reads prove the combat-master fields at +0x124, +0x12A,
        // and +0x138.
        RGE_Action_Attack* action = new RGE_Action_Attack(
            this->obj, this->target_obj, this->get_move_sprite(),
            this->task->work_sprite, 0, this->task->work_range,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->minimum_weapon_range,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->missile_id,
            static_cast<RGE_Master_Combat_Object*>(this->obj->master_obj)->fire_missile_at_frame);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 6:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_move_sprite());
        return;

    case 7:
        this->timer = 0.0f;
        // BINARY NOTE: State 7 reads attribute_type_held (+0x4C), then calls
        // the inherited set_attribute virtual at slot +0x80.
        if (this->obj->attribute_type_held != this->task->attribute_type) {
            this->obj->set_attribute(this->task->attribute_type, 0);
        }
        this->obj->new_sprite(this->task->work_sprite2);
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
        }
        return;

    case 8:
        if (this->obj->attribute_amount_held > DAT_00575150) {
            if (this->target_obj2 == 0) {
                if (static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->drop_site != -1) {
                    this->set_target_obj2(this->obj->owner->objects->find_by_master_ids(
                        static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->drop_site,
                        static_cast<RGE_Master_Action_Object*>(this->obj->master_obj)->backup_drop_site,
                        this->obj->world_x, this->obj->world_y, 1, 2,
                        (RGE_Static_Object*)this->obj));
                } else {
                    this->set_target_obj2(0);
                }
            }
            if (this->target_obj2 != 0) {
                RGE_Action_Move_To* action = new RGE_Action_Move_To(
                    this->obj, this->target_obj2, this->task->work_range,
                    this->get_move_sprite());
                if (action == 0) {
                    this->set_state(0x0D);
                    return;
                }
                this->sub_actions->add_action(action);
                action->setSubAction(1);
                return;
            }
            this->obj->notify(this->obj->id, this->obj->id, 0x203, 0x265, 0, 0);
            if (this->obj->owner->computerPlayer() == 0) {
                this->set_state(2);
            } else {
                this->set_state(1);
            }
            return;
        }
        // BINARY NOTE: The shipped check reads target_obj (+0x10), not
        // target_obj2 (+0x14), before clearing target_obj.
        // LIKELY INTENT: Clear the current target before state 3.
        if (this->target_obj != 0 &&
            this->target_obj->attribute_amount_held <= DAT_00575150) {
            this->set_target_obj(0);
        }
        this->set_state(3);
        return;

    case 1:
    case 13:
    case 14:
        this->timer = 0.0f;
        this->obj->new_sprite(this->get_wait_sprite());
        return;

    default:
        return;
    }
}
#endif
