#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FB710 TribeTacticalAIModule::taskResearch (448 B)
// PDB source: taitacmd.cpp:9222-9253
// __thiscall, returns 0/1
//
// Fresh reconstruction from the exact taskTrain/taskWaterFisher donors.
// The target uses the same building lookup, BuildItem state changes, and
// ManagedIntArray growth. The final dispatch is TRIBE_Player::research.
//
// Attempt log:
// - Baseline: natural typed BuildItem/MainDecision/RGE object reconstruction;
//   448 bytes and 17 calls, but broad register and block drift.
// - Cached object-id probe improved the metric by 10 bytes, but changed the
//   source shape and introduced a wrong direct-call identity; rolled back.
// - Split lookup declaration and assignment restored the exact 448-byte
//   topology except for four stack-home displacement bytes.
// - Entry-local, assignment-in-condition, and object-alias variants emitted
//   duplicate code. The remaining gap is the object spill slot at 004FB75E
//   and 004FB843: target [esp+18], rebuilt [esp+10].
// - Reused the scan index for the array-copy loop, matching the original EAX
//   loop topology; emitted code was unchanged, so the spill-home gap remains.
// - Declared objectID at its first natural use after the item state updates to
//   test whether its shorter lifetime restored the original object spill home;
//   emitted code was unchanged, so the probe was rolled back.
// - Initializing the entry objectID local to zero selected the original VC5
//   local-home assignment. The initializer is optimized away; output is exact.
//   Best source keeps named ownership and natural bounded array growth.

#ifndef TAITACMD_SHARED_CONTEXT
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class UnitAIModule;
class RGE_Game_World;
class RGE_Master_Static_Object;
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
class RGE_Player;

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[8];
    int uniqueID_;
    int typeID_;

    int uniqueID() const;
    int typeID() const;
};

class BuildItem : public BaseItem {
public:
    char gap_18[0x74];

    int buildFrom() const;
    void setInProgress(int);
    void setBuilt(int);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x3C];

    UnitAIModule* unitAI();
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;
    ManagedIntArray objects;

    RGE_Static_Object* object(int, int, int, int, int, int);
};

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
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual void* make_scenario_obj(float, float, float, short, unsigned char, float);
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
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
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
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    char gap_04[0x46];
    short id;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(void*, int);
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

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    TRIBE_Player* aiPlayer;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];

    void logCommonHistory(char*, ...);
};

class TribeTacticalAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskResearch(BuildItem*);
};

#endif
int TribeTacticalAIModule::taskResearch(BuildItem* item)
{
    int objectID = 0;

    if (item == 0) {
        this->logCommonHistory("Invalid taskResearch item, returning FALSE.");
        return 0;
    }

    RGE_Static_Object* object;
    object = this->md->object(-1, item->buildFrom(), -1, 0x26B, 0x26C, 2);
    if (object == 0 || object->unitAI() == 0) {
        this->logCommonHistory(
            "Could not find a building to research type %d with unique ID %d.",
            item->typeID(), item->uniqueID());
        return 0;
    }

    this->logCommonHistory(
        "Researching ID #%d (UniqueID=%d) from building #%d.",
        item->typeID(), item->uniqueID(), object->id);
    item->setInProgress(1);
    item->setBuilt(0);

    objectID = object->id;

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == objectID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (i = 0; i < arr.maximumSize && i < newSize; i++) {
                newArray[i] = arr.value[i];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = objectID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->research(item->typeID(), object->id, item->uniqueID());
    return 1;
}
#else
int TribeTacticalAIModule::taskResearch(BuildItem* item) {
    return 0;
}
#endif
