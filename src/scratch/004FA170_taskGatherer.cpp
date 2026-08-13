// 004FA170 TribeTacticalAIModule::taskGatherer (taitacmd.cpp:8444-8839, 1712B)
// Attempt log:
//  - Reconstructed the canonical neededResourceValue[4], sn[256], exclusions[6],
//    ManagedArray growth, resource-search ABI, and natural loop topology from the
//    original assembly and exact same-TU donors.
//  - Prior candidate reached frame 0x30, 32/32 ordered calls, and 82.19% shape,
//    but used generated placeholder virtual methods. This source restores the
//    named RGE_Static_Object and TRIBE_Player surfaces from the original headers;
//    calls at 0x194/0x19C use real canPath/canBidirectionPath signatures.
//  - ABI probe: VC5 requires the XYZPoint overload to precede the integer
//    canPath overload in this declaration surface to emit those two calls at
//    the original addresses. No manual virtual-table padding, raw virtual-table
//    access, inline assembly, or fake volatility is retained.
//  - Confirmed the original calls push the full six/seven argument surfaces;
//    shorter int-only declarations improved shape but did not match the binary
//    call arity and were rolled back. A named resource-base pointer moved the
//    array register closer but added four bytes and was also rolled back.
//  - Final matching status: unresolved. Named-surface rebuild is 1758B versus
//    1712B original, with frame 0x30, 32/32 ordered calls, and first mismatch
//    at +0x1D (the original homes gathererObj before the null branch). The
//    remaining gap is compiler local-allocation/control-flow reconstruction;
//    leave this canonical source in scratch for a later worker.

#include <stdlib.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);
extern "C" int __cdecl __ftol();

struct XYZPoint {
    int x;
    int y;
    int z;
};
struct XYPoint {
    int x;
    int y;
};
struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Game_World;
class RGE_Player;
class TRIBE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class RGE_Color_Table;
class TDrawArea;
class LOSTBL;
class Path;
class InfluenceMap;
class RGE_Master_Combat_Object;
class RGE_Damage_Sprite_Info;
class RGE_Sound;
class RGE_Check_List;
class UnitAIModule;

struct ManagedArrayInt {
    int* value;
    int numberValue;
    int desiredValue;
    int maximumSize;

    int& operator[](int index) {
        if (index > this->maximumSize - 1) {
            int newSize = index + 1;
            int* newValue = (int*)operator_new(newSize * 4);
            if (newValue != 0) {
                int i;
                for (i = 0; i < this->maximumSize && i < newSize; i++) {
                    newValue[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = newValue;
                this->maximumSize = newSize;
            }
        }
        return this->value[index];
    }
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long, int, uchar);

    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[1];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2D[3];
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
    unsigned char gap_4F[1];
    short portrait_pict;
    unsigned char available;
    unsigned char gap_53[1];
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
    unsigned char gap_69[1];
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char gap_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
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
    unsigned char gap_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(RGE_Static_Object*, float, float);
    virtual uchar command_make_work(RGE_Static_Object*, float, float);
    virtual uchar command_make_do(RGE_Static_Object*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual uchar command_add_attribute(int, float);
    virtual uchar command_give_attribute(int, int, float);
    virtual uchar command_formation(int);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int, int*, int, float);
    virtual uchar command_add_to_group(int, int, float);
    virtual uchar command_remove_from_group(int, int);
    virtual uchar command_destroy_group(int);
    virtual uchar command_resign(int, int);
    virtual uchar command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, uchar);
    virtual void new_victory();

    unsigned char gap_04[0x46];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual uchar command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(RGE_Static_Object*, int);
    virtual void trainUnit(int, int, int);
    virtual void cancelTrain(int, int, int, int);
    virtual void registerTrain(int, int, int, int);
    virtual void research(int, int, int);
    virtual void cancelResearch(int, int, int, int);
    virtual void registerResearch(int, int, int);
    virtual void taskTrader(int, int, int, float, float);
    virtual void taskResourceGatherer(int, int, int, float, float);
    virtual void notifyAI(int, int, int, long, long, long);
};

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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedArrayInt*);
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

    float distance_to_object(RGE_Static_Object*);

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
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
    ManagedArrayInt pathingGroupMembers;
    ManagedArrayInt groupMembers;
    UnitAIModule* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;
    unsigned char gap_87;
};

struct UnitData {
    int id;
    int target;
    int data2;
    int data3;
};

class TribeInformationAIModule {
public:
    int gameIDOfResourceObject(int resType, int gathererId, float* d1, float* d2,
                               int* d3, int* exclusions, int index);
    void setResourceObjectValid(int resType, int id, int valid);
    int acceptablePotentialDropsiteArea(int x, int y);

    char gap_00[0xF0];
    ManagedArrayInt farmsTaskedThisUpdate;
    char gap_100[0x340 - 0x100];
    int closestDropsiteValue[4];
};

class BuildAIModule {
public:
    char gap_00[4];
    void insert(int a, int b, int c);
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0x104];
    BuildAIModule buildAI;
    char gap_108[0xCEC - 0x104 - sizeof(BuildAIModule)];
    TribeInformationAIModule informationAI;
    char gap_AI[0x1256C - 0xCEC - sizeof(TribeInformationAIModule)];
    TRIBE_Player* aiPlayer;

    RGE_Static_Object* object(int unit);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_F4[0x104 - 0xF4];
    int* civilianExplorersValue;
    int civilianExplorersNumber;
    int civilianExplorersDesired;
    int civilianExplorersMax;
    char gap_114[0x194 - 0x114];
    int sn[256];
    char gap_594[0xD58 - 0x594];
    ManagedArrayInt unitsTaskedThisUpdate;
    int actualGathererDistribution[4];
    char gap_D78[0xD88 - 0xD78];
    int neededResourceValue[4];
    char gap_D98[0xF88 - 0xD98];
    int builtFirstStoragePit;
    int builtFirstGranary;
    char gap_F90[0xFA4 - 0xF90];
    int zoomingToNextAge;

    UnitData* gatherer(int unit);
    UnitData* addGatherer(int unit);
    int numberAvailableGranaries(RGE_Static_Object** o, int* m);
    int numberAvailableStoragePits(RGE_Static_Object** o, int* m, int a);
    int requiredGatherAmount(int res);
    void taskElephantGatherers(int unit, int a, int b);
    int taskGatherer(int p1, int p2, int p3, ulong p4, int* p5);
};

int TribeTacticalAIModule::taskGatherer(int p1, int p2, int p3, ulong p4, int* p5)
{
    RGE_Static_Object* gathererObj = this->md->object(p1);
    if (gathererObj == 0) return 0;

    UnitData* g = this->gatherer(p1);
    if (g != 0 && g->data2 > g->data3) {
        p2 = g->target;
    }

    int i = -1;
    int index = 0;
    float drop1 = 0;
    float drop2 = 0;
    int numStorage;
    int maximumResourceDistance;
    int exclusions[6];

    if (p2 == -1) {
        for (index = 0; index < 4; index++) {
            p2 = this->neededResourceValue[index];
            if (p5 == 0 || p5[p2] != 1) {
                numStorage = -1;
                i = this->md->informationAI.gameIDOfResourceObject(
                        p2, p1, &drop1, &drop2, &numStorage, exclusions + 1, 0);
                if (i != -1) {
                    if (numStorage == -1)
                        gathererObj->canPath(i, 1.0f, 0, 1, -1, -1);
                    else
                        gathererObj->canBidirectionPath(i, numStorage, 1.0f, 0, 1, -1, -1);
                    break;
                }
            }
        }
        if (i == -1) return 0;
    }
    else {
        maximumResourceDistance = 0;
        p5 = exclusions + 1;
        for (; maximumResourceDistance < 3; ++maximumResourceDistance) {
            numStorage = -1;
            i = this->md->informationAI.gameIDOfResourceObject(
                    p2, p1, &drop1, &drop2, &numStorage, exclusions + 1, index);
            if (i == -1) return 0;
            int result = (numStorage == -1)
                ? gathererObj->canPath(i, 1.0f, 0, 1, -1, -1)
                : gathererObj->canBidirectionPath(i, numStorage, 1.0f, 0, 1, -1, -1);
            if (result != 0) break;
            if (p2 == 0)
                this->md->informationAI.setResourceObjectValid(p2, i, 2);
            else
                this->md->informationAI.setResourceObjectValid(p2, i, 0xF);
            *p5 = i;
            ++p5;
            ++index;
            i = -1;
        }
        if (i < 0) return 0;
    }

    RGE_Static_Object* obj = this->md->object(i);
    if (obj == 0) return 0;

    if (this->sn[0xCD] != 1) goto tail;

    if (p2 == 0) {
        if (this->builtFirstGranary == 1) {
            if (this->builtFirstStoragePit != 1) goto tail;
            if (obj->master_obj->id == 0x3B) {
                maximumResourceDistance = 0;
                RGE_Static_Object* g2 = 0;
                int ng = this->numberAvailableGranaries(&g2, &maximumResourceDistance);
                if (maximumResourceDistance != 0 || ng < 1) goto tail;
                exclusions[0] = this->sn[0xA3];
                int d = (int)gathererObj->distance_to_object(obj);
                if (d <= exclusions[0] ||
                    this->md->informationAI.closestDropsiteValue[0] == -1) goto tail;
                int y = (int)obj->world_y;
                int x = (int)obj->world_x;
                if (this->md->informationAI.acceptablePotentialDropsiteArea(x, y) != 1) goto tail;
                this->md->buildAI.insert(0x44, 1, -1);
                goto tail;
            } else {
                short grp = obj->master_obj->object_group;
                if (grp == 0x1F || grp == 5 || grp == 0x21) goto tail;
                maximumResourceDistance = 0;
                RGE_Static_Object* g2 = 0;
                int np = this->numberAvailableStoragePits(&g2, &maximumResourceDistance, 0);
                if (maximumResourceDistance != 0 || np < 1) goto tail;
                int d = (int)gathererObj->distance_to_object(obj);
                if (d < 0x10) {
                    if (g2 != 0) goto tail;
                }
                this->md->buildAI.insert(0x67, 1, -1);
                goto tail;
            }
        }
    }
    if (this->builtFirstStoragePit != 1 || this->builtFirstGranary != 1) goto tail;
    {
        int np;
        RGE_Static_Object* g2;
        int d;
        maximumResourceDistance = 0;
        g2 = 0;
        np = this->numberAvailableStoragePits(&g2, &maximumResourceDistance, p2);
        if (maximumResourceDistance != 0 || np < 1) goto tail;
        exclusions[0] = this->sn[obj->attribute_type_held + 0xA3];
        d = (int)gathererObj->distance_to_object(obj);
        if (d <= exclusions[0]) {
            if (g2 != 0) goto tail;
        }
        this->md->buildAI.insert(0x67, 1, -1);
    }

tail:
    {
        int bound = this->civilianExplorersMax;
        int j;
        for (j = 0; j < bound; j++) {
            if (this->civilianExplorersValue[j] == p1) break;
        }
        if (j < bound) {
            if (j < bound - 1) {
                do {
                    this->civilianExplorersValue[j] = this->civilianExplorersValue[j + 1];
                    j++;
                } while (j < this->civilianExplorersMax - 1);
            }
            int n = this->civilianExplorersNumber - 1;
            this->civilianExplorersNumber = n;
            if (n < 0) this->civilianExplorersNumber = 0;
        }
    }

    UnitData* ag = this->addGatherer(p1);
    if (ag == 0) return 0;

    this->actualGathererDistribution[p2] = this->actualGathererDistribution[p2] + 1;

    {
        int j;
        for (j = 0; j < this->unitsTaskedThisUpdate.numberValue &&
                     j < this->unitsTaskedThisUpdate.maximumSize; j++) {
            if (this->unitsTaskedThisUpdate.value[j] == p1) goto units_tasked;
        }
        this->unitsTaskedThisUpdate[this->unitsTaskedThisUpdate.numberValue] = p1;
        this->unitsTaskedThisUpdate.numberValue++;
    }

units_tasked:
    ag->target = p2;
    int amount = this->requiredGatherAmount(p2);
    if (p3 == 1) {
        amount = 10;
    } else if (this->sn[0xCB] == 1) {
        if (obj->master_obj->id == 0x3B) {
            amount = (int)obj->attribute_amount_held;
        } else if (p2 == 1) {
            amount = 0x4B;
        } else if (p2 == 3) {
            amount = 0x32;
        } else if (p2 == 2) {
            amount = 0x32;
        }
    } else {
        if (amount < this->sn[0x94]) amount = this->sn[0x94];
        else if (amount > this->sn[0x95]) amount = this->sn[0x95];
    }
    if (this->zoomingToNextAge == 1) amount = 0x14;

    ag->data2 = amount;
    ag->data3 = 0;

    this->md->aiPlayer->taskResourceGatherer(p1, i, obj->owner->id, drop1, drop2);

    if (obj->master_obj->id == 0x30) {
        this->taskElephantGatherers(p1, this->sn[0xCC] - 1, i);
    }
    if (obj->master_obj->id == 0x32) {
        ManagedArrayInt& farms = this->md->informationAI.farmsTaskedThisUpdate;
        int fid = obj->id;
        int bound = farms.numberValue;
        int fj;
        for (fj = 0; fj < bound && fj < farms.maximumSize; fj++) {
            if (farms.value[fj] == fid) return 1;
        }
        farms[farms.numberValue] = fid;
        farms.numberValue++;
    }
    return 1;
}
