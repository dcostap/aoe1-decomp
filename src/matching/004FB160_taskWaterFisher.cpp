#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FB160 TribeTacticalAIModule::taskWaterFisher (355 B)
// PDB source: taitacmd.cpp:9019-9049
// __thiscall, returns 0/1
//
// Attempt log:
// - Baseline used raw offset/free-function shims; it was 282 B with the
//   object lookup and final player virtual call surfaces structurally wrong.
// - Probe 1: restore the period typed XYZPoint/canPath surface, the full
//   TribeMainDecisionAIModule::aiPlayer layout, and the natural ManagedArray
//   growth/append idiom shared by the exact taskWaterExplorer/taskTransporter
//   donors. This produced the exact 355-byte structure with a one-byte
//   aiPlayer displacement mismatch because MainDecision was four bytes short.
// - Probe 2: restore MainDecisionAIModule::objects at +0xF4, making its
//   proven size 0x104 and placing aiPlayer at +0x1256C. Result: MATCH.
// - Final: natural typed XYZPoint/canPath and taskResourceGatherer calls with
//   the exact same-TU ManagedArray growth source; default flags, no inline asm.

#ifndef TAITACMD_SHARED_CONTEXT
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

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class TRIBE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Action_Object;
class RGE_Armor_Weapon_Info;
class TDrawArea;
class RGE_Color_Table;
class LOSTBL;
class Path;
class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
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
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    unsigned char gap_04[0x46];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(RGE_Static_Object*, int);
    virtual void trainUnit(int, int, int);
    virtual void cancelTrain(int, int, int, int);
    virtual void registerTrain(int, int, int, int);
    virtual void research(int, int, int);
    virtual void cancelResearch(int, int, int, int);
    virtual void registerResearch(int, int, int, int);
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
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
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
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
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
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int, ManagedIntArray*);
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
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    ManagedIntArray objects;

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    TRIBE_Player* aiPlayer;
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskWaterFisher(int playerID, int targetID, float x, float y);
};

#endif
int TribeTacticalAIModule::taskWaterFisher(int playerID, int targetID, float x, float y)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    XYZPoint point;
    point.x = (int)x;
    point.y = (int)y;
    point.z = 1;
    if (object->canPath(point, 1.0f, -1, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == playerID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = playerID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->taskResourceGatherer(playerID, targetID, 0, x, y);
    return 1;
}
#else
int TribeTacticalAIModule::taskWaterFisher(int playerID, int targetID, float x, float y) {
    return 0;
}
#endif
