// 00502310 TribeTacticalAIModule::checkForAttackResponseBuildInsertions
// taitacmd.cpp:12609-12746, parent-owned switch fragments at 00502451-005025C9
//
// Attempt log:
// - Baseline was an incomplete raw-offset time-gate scaffold (48 bytes) and
//   omitted the object/radius scan, switch, ResourceItem lifetime, and build
//   insertion calls.
// - Probe 1: reconstructed the complete typed parent with the period EH /
//   ResourceItem surface, the natural switch shared body, and same-TU AI
//   module ownership. FLAGS: /GX. Full source emits the correct 0x78 EH
//   frame and first six call family, but the checker sees 748 bytes because
//   the parent-owned switch codelets are emitted in the same rebuilt symbol.
// - Probe 3: named the saved timestamp; initial codegen stayed in the same
//   register basin.
// - Probe 4: changed the timestamp arithmetic to signed period `long`; this
//   recovered the original signed imul/magic division and exact entry through
//   the time gate, but the parent boundary overflow remained.
// - Probes 5-6: inline/split the unit-count subtraction assignment; VC5 kept
//   the same extra load-before-subtract shape.
// - Session probe 9: moved the units-to-insert declaration to function scope
//   to test the decompiler's top-level local lifetime; emitted code was
//   unchanged and the clean typed source was restored.
// - Session probe 13: applied the exact 00501D70 donor's named ResourceItem,
//   build, information, and main-decision layouts; emitted code was unchanged.
// - Session probe 15: moved the unit-count assignment into its guard condition
//   to seek the original `sub eax,[ebx+118h]`; VC5 emitted identical code.
// - Session probe 19: split the count call from a compound soldiers subtraction
//   to seek the original direct memory subtract; VC5 emitted identical code.
// - Best current reconstruction: typed full parent, 0x78 frame, matching
//   initial six ordered calls and natural ResourceItem/switch ownership; local
//   checker remains nonexact because entry-reachable code past the 321-byte
//   inventory boundary is the manifest-listed parent-owned fragment cluster
//   00502451-005025C9. Do not replace this source with raw-offset or codegen
//   scaffolding merely to hide that structural boundary.

class ResourceItem {
public:
    virtual ~ResourceItem();
    ResourceItem* next;
    ResourceItem* previous;
    int values[8];
    int sortedValues[8];
    int sortedIndexes[8];
    int numberValue;

    ResourceItem(int count);
};

class RGE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    long world_time;
    char gap_08[0x34];
    short player_count;
    char gap_3E[2];
    RGE_Player** players;
    char gap_44[0xC0];
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
    char gap_04[0x34];
    float world_x;
    float world_y;
};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
};

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class BuildAIModule : public AIModule {
public:
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char gap_F0[0x5C0 - 0xF0];

    virtual int loggingHistory();
    virtual void setLogHistory(int value);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char* filename);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int value);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char* filename);
    virtual int saveState(char* filename);
    virtual int gleanState(int value);
    virtual int processMessage(void* message);
    virtual int update(int value);
    virtual void setCallbackMessage(void* message);
    virtual int filterOutMessage(void* message);
    virtual int save(int value);
    virtual void displayBuildList();
    virtual int loadBuildList(char* filename, void* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int mode);

    int insert(int type, int count, int priority);
};

class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_04[0x540 - 0x04];
    int closestDropsiteValue[4];
    int closestDropsiteResourceID[4];
    int numberFoundForestTilesValue;
    char gap_564[0x10090 - 0x564];

    int numberUnitsWithinXTiles(int playerFilter, int x, int y, int radius);
};

class TribeResourceAIModule : public AIModule {
public:
    char gap_F0[0x08];

    int resource(int type);
    int resourcesAvailable(ResourceItem* item);
};

class TRIBE_Player {
public:
    int objectAvailable(int type);
    void objectCost(int type, int amount, ResourceItem* item, int flag);
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    char gap_F4[0x10];

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    char gap_6C4[0xCEC - 0x6C4];
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    char gap_10E74[0x1256C - 0x10E74];
    TRIBE_Player* aiPlayer;
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    TribeMainDecisionAIModule* md;
    ManagedIntArray civilians;
    ManagedIntArray civilianExplorers;
    ManagedIntArray soldiers;
    char gap_124[0xF94 - 0x124];
    long lastAttackResponseBuildInsertionTime;

    void checkForAttackResponseBuildInsertions(int playerID);
};

void TribeTacticalAIModule::checkForAttackResponseBuildInsertions(int playerID)
{
    long lastAttackTime = this->lastAttackResponseBuildInsertionTime;
    long currentTime = this->md->player->world->world_time;
    if ((currentTime - lastAttackTime) / 1000 < 180)
        return;

    this->lastAttackResponseBuildInsertionTime = currentTime;
    RGE_Static_Object* object = this->md->object(
        -1, 0x6D, -1, -1, -1, -1, -1, -1, -1, -1);
    if (object == 0)
        return;

    int unitsToInsert;
    unitsToInsert =
        this->md->informationAI.numberUnitsWithinXTiles(
            playerID, (int)object->world_x, (int)object->world_y, 20) -
        this->soldiers.numberValue;
    if (unitsToInsert <= 0)
        return;
    if (unitsToInsert > 5)
        unitsToInsert = 5;

    int insertedUnit = 0;
    int itemCostFlag = 0;
    while (unitsToInsert > 0) {
        int unitType;
        int objectType;

        switch (insertedUnit) {
        case 0:
            if (this->md->resourceAI.resource(2) >= 150 &&
                this->civilians.numberValue > 2) {
                this->md->buildAI.insert(0x4F, 1, 0);
                unitsToInsert -= 2;
            }
            insertedUnit = 1;
            continue;
        case 1:
            unitType = 0x25;
            objectType = 0x65;
            break;
        case 2:
            unitType = 0x4B;
            objectType = 0x0C;
            break;
        case 3:
            unitType = 0x5D;
            objectType = 0;
            break;
        case 4:
            unitType = 0x27;
            objectType = 0x57;
            break;
        case 5:
            unitType = 0x49;
            objectType = 0x0C;
            break;
        case 6:
            unitType = 5;
            objectType = 0x57;
            break;
        case 7:
            unitType = 0x12B;
            objectType = 0x65;
            break;
        case 8:
            unitType = 4;
            objectType = 0x57;
            break;
        case 9:
            unitType = 0x7D;
            objectType = 0x68;
            break;
        case 10:
            unitType = 0x29;
            objectType = 0x57;
            break;
        case 11:
            unitType = 0x28;
            objectType = 0x65;
            break;
        default:
            if (itemCostFlag != 1)
                return;
            insertedUnit = 1;
            itemCostFlag = 0;
            continue;
        }

        if (this->md->aiPlayer->objectAvailable(unitType) == 0) {
            insertedUnit++;
            continue;
        }

        RGE_Static_Object* target = this->md->object(
            -1, objectType, -1, -1, -1, -1, -1, -1, -1, -1);
        if (target == 0) {
            insertedUnit++;
            continue;
        }

        {
            ResourceItem itemCost(4);
            this->md->aiPlayer->objectCost(unitType, -1, &itemCost, 1);
            if (this->md->resourceAI.resourcesAvailable(&itemCost) == 1) {
                this->md->buildAI.insert(unitType, 1, 0);
                unitsToInsert--;
                itemCostFlag = 1;
            }
            insertedUnit++;
        }
    }
}
