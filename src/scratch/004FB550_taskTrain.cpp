// VA: 004FB550 TribeTacticalAIModule::taskTrain (448 B)
// PDB source: taitacmd.cpp:9185-9217
// __thiscall, returns 0/1
//
// Attempt log:
// - Fresh typed reconstruction from the taskTrain packet and same-TU task
//   donors. The source models BuildItem, MainDecisionAIModule::object,
//   RGE_Static_Object::unitAI, TRIBE_Player::trainUnit, and the proven
//   unitsTaskedThisUpdate ManagedArray layout.
// - Baseline reached 448/448 bytes, 17/17 ordered calls, and 4 differing
//   bytes. The remaining bytes are four swapped local-home displacements:
//   VC5 stores the found object in the incoming parameter home and the
//   object ID in the compiler local home.
// - Tried early object-ID/object declarations, pointer initialization,
//   assignment-in-condition, long ID types, and parameter reuse. The
//   parameter-reuse form moved two swaps but added prologue drift. The
//   natural baseline remained best. No ABI, call-set, or layout blocker.

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class RGE_Static_Object;
class RGE_Player;
class TRIBE_Player;
class TribeMainDecisionAIModule;
class UnitAIModule;

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    void __cdecl logCommonHistory(char* format, ...);
};

class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[0x68];
    int typeID() const;
    int uniqueID() const;
};

class BuildItem : public BaseItem {
public:
    char gap_6C[0x20];
    int buildFrom() const;
    void setInProgress(int value);
    void setBuilt(int value);
};

class UnitAIModule {
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    char gap_08[0x6C];
    UnitAIModule* unitAI();
};

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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
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
    virtual void* make_scenario_obj(float, float, float, short,
                                    unsigned char, float);
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
};

class TRIBE_Player : public RGE_Player {
public:
    virtual unsigned char command_give_attribute(int, int, float, float);
    virtual void buildObject(int, int, float, float, int);
    virtual void cancelBuild(int, int, int, float, float, int, int);
    virtual void registerBuild(void*, int);
    virtual void trainUnit(int, int, int);
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedIntArray objects;
    RGE_Static_Object* object(int, int, int, int, int, int);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1256C - 0x104];
    TRIBE_Player* aiPlayer;
};

class TribeTacticalAIModule : public AIModule {
public:
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int taskTrain(BuildItem* item);
};

int TribeTacticalAIModule::taskTrain(BuildItem* item)
{
    if (item == 0) {
        this->logCommonHistory((char*)0x00588514);
        return 0;
    }

    RGE_Static_Object* object =
        this->md->object(-1, item->buildFrom(), -1, 0x26B, 0x26C, 2);
    if (object == 0 || object->unitAI() == 0) {
        this->logCommonHistory((char*)0x00588488,
                               item->typeID(), item->uniqueID());
        return 0;
    }

    this->logCommonHistory((char*)0x005884D8,
                           item->typeID(), item->uniqueID(), object->id);
    item->setInProgress(1);
    item->setBuilt(0);

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int objectID = object->id;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == objectID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            for (i = 0; i < arr.maximumSizeValue && i < newSize; i++)
                newArray[i] = arr.value[i];
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = objectID;
    arr.numberValue++;

dispatch:
    this->md->aiPlayer->trainUnit(item->typeID(), object->id,
                                  item->uniqueID());
    return 1;
}
