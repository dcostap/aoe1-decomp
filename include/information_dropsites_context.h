#ifndef INFORMATION_DROPSITES_CONTEXT_H
#define INFORMATION_DROPSITES_CONTEXT_H

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

typedef unsigned char uchar;

class RGE_Game_Info {
public:
    char* get_current_player_name();
};

class RGE_Base_Game {
public:
    char gap_00[4];
    RGE_Game_Info* player_game_info;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Game_World;
class RGE_Map;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual int relation(int playerID);

    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    union {
        short id;
        short civ_id;
    };
    char gap_4C[4];
    float* attributes;
};

typedef RGE_Player Player;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    short gap_12;
    short object_group;
};

typedef RGE_Master_Static_Object RGE_Master_Object;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void vf004(); virtual void vf008(); virtual void vf00C();
    virtual void vf010(); virtual void vf014(); virtual void vf018(); virtual void vf01C();
    virtual void vf020(); virtual void vf024(); virtual void vf028(); virtual void vf02C();
    virtual void vf030(); virtual void vf034(); virtual void vf038(); virtual void vf03C();
    virtual void vf040(); virtual void vf044(); virtual void vf048(); virtual void vf04C();
    virtual void vf050(); virtual void vf054(); virtual void vf058(); virtual void vf05C();
    virtual void vf060(); virtual void vf064(); virtual void vf068(); virtual void vf06C();
    virtual void vf070(); virtual void vf074(); virtual void vf078(); virtual void vf07C();
    virtual void vf080(); virtual void vf084(); virtual void vf088(); virtual void vf08C();
    virtual void vf090(); virtual void vf094(); virtual void vf098(); virtual void vf09C();
    virtual void vf0A0(); virtual void vf0A4(); virtual void vf0A8(); virtual void vf0AC();
    virtual void vf0B0(); virtual void vf0B4(); virtual void vf0B8(); virtual void vf0BC();
    virtual void vf0C0(); virtual void vf0C4(); virtual void vf0C8(); virtual void vf0CC();
    virtual void vf0D0(); virtual void vf0D4(); virtual void vf0D8(); virtual void vf0DC();
    virtual void vf0E0(); virtual void vf0E4(); virtual void vf0E8(); virtual void vf0EC();
    virtual void vf0F0(); virtual void vf0F4(); virtual void vf0F8(); virtual void vf0FC();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object* attacker);
    virtual void vf108();
    virtual float speed();

    int id;
    union {
        RGE_Master_Static_Object* master_obj;
        RGE_Master_Static_Object* master;
    };
    union {
        RGE_Player* player;
        RGE_Player* owner;
    };
    char gap_10[0x20];
    float hp;
    float gap_34;
    union {
        float x;
        float world_x;
    };
    union {
        float y;
        float world_y;
    };
    float z;
    float amount;
    unsigned char state;

    unsigned char currentZone();
    unsigned char lookupZone(int x, int y);
    int withinRangeOfZoneAtPoint(unsigned char zone, float range, void* point);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;

    RGE_Static_Object* object(int id);
};

struct RGE_Object_List_Node {
    RGE_Static_Object* object;
    RGE_Object_List_Node* next;
};

struct RGE_Object_List {
    void* vtable;
    RGE_Object_List_Node* list;
};

struct RGE_Tile {
    char gap_00[5];
    unsigned char terrainType;
    char gap_06[6];
    RGE_Object_List objects;
    char gap_14[4];
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    RGE_Tile** mapRowOffset;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    char gap_07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

typedef ResourceMemory ResourceInfo;

struct ObjectMemory {
    int id;
    short type;
    short group;
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char owner;
    short hitPoints;
    unsigned char pad_0E[2];
    int attackAttempts;
    unsigned char kills;
    unsigned char pad_15[3];
    float damageCapability;
    float rateOfFire;
    float range;
};

struct XYPoint {
    int x;
    int y;
};

struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char pad_end;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int);
    int contains(const T&) const;
    int add(T);

    T& operator[](int index)
    {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_value = (T*)::operator new(new_size * sizeof(T));
            if (new_value != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_value[i] = this->value[i];
                }
                ::operator delete(this->value);
                this->value = new_value;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

struct FarmIdArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int& operator[](int index) { return this->value[index]; }
};

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class InfluenceMap {
public:
    void* vtable;
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    unsigned char* valueValue;
    unsigned char** rowValue;
    int coverageCountValue;
    int connectionCountValue;
    unsigned char unchangeableLimitValue;
    unsigned char gap_25[3];

    int lookupValue(int x, int y);
    int setValue(int x, int y, unsigned char value);
};

struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};

class TacticalAIGroup;

class TribeTacticalAIModule {
public:
    int numberGatherersWithTarget(int id);
    int strategicNumber(int id);
    int actualGathererCountByRealResourceID(int id);
    TacticalAIGroup* bestGroup(int type, int action, int maxDistance,
                               XYPoint* point, int zone);
};

class TacticalAIGroup {
public:
    int numberUnits();
    int unit(int index);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_004[0xEC];
    RGE_Player* player;
    FarmIdArray objects;

    RGE_Static_Object* object(int id);
    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char gap_104[0x1146C - 0x104];
    TribeTacticalAIModule tacticalAI;
    char gap_1146D[0x1256C - 0x1146D];
    RGE_Player* aiPlayer;
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[64];
};

class AIModule {
public:
    virtual ~AIModule();
    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[64];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[64];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class TribeInformationAIModule : public InformationAIModule {
public:
    virtual ~TribeInformationAIModule();

    FarmIdArray farmsTaskedThisUpdate;
    TribeMainDecisionAIModule* md;
    int mapXSizeValue;
    int mapYSizeValue;
    char gap_10C[0x04];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ManagedArray<int> importantObjects;
    char gap_128[0x20];
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    char gap_180[0x74];
    int maxBuildingLots;
    BuildingLot* buildingLots;
    char gap_1FC[0x10C];
    unsigned char fullyExploredZoneValue[255];
    char gap_407[1];
    QuadrantLog quadrantLog[4][4];
    char gap_4C8[8];
    ResourceMemory* resources[4];
    int numResources[4];
    char gap_4F0[0x10];
    int dropsitesByAge[4][4];
    int closestDropsiteValue[4];
    union {
        int dropsiteIds[4];
        int closestDropsiteResourceID[4];
    };
    int numberFoundForestTilesValue;
    int playHistory[16000];
    int unitHistory[11];

    int gameIDOfResourceObject(int resType, int gathererId, float& outX,
                               float& outY, int& outResourceId, int* exclude,
                               int excludeCount);
    int ownerOfGameID(int gameID);
    int fullyExploredZone(int gameID);
    void setFullyExploredZone(int gameID, int explored);
    int tileUncovered(int x, int y);
    void setTileExplored(int x, int y);
    int gameIDsOfObjectType(int objectType, int** ids, int** owners,
                            int playerFilter);
    int importantUnit(int typeID);
    int checkDefend(RGE_Static_Object* object);
    ObjectMemory* objectToDefend(int objectID);
    ObjectMemory* higherPriorityObjectToDefend(int objectID, int type,
                                                int group);
    int defendPriority(int type, int group);
    void storeLot(int typeID, unsigned char x, unsigned char y,
                  unsigned char built);
    int dropsitesWithinRequiredDistance(int& numApplicableResources,
                                        int resourceType,
                                        int requiredDistance);
    int numberAvailableStoragePits(int resourceType);
    int numberAvailableGranaries();
    void lookAtMap();
    int importantObject(int objectGroup);
    int addImportantObject(RGE_Static_Object* object, int value);
    float damageInflictedPerSecond(TacticalAIGroup* group,
                                   RGE_Static_Object* target);
    float damageInflictedPerSecond(int* ids, int count,
                                   RGE_Static_Object* target);
    float damagePerSecond(int unitID, int x, int y);
    float timeToBeKilled(TacticalAIGroup* group,
                         RGE_Static_Object* target);
    float timeToBeKilled(int* ids, int count, RGE_Static_Object* target);
    int closestDropsiteResID(int resourceType);
    int calculatePlayVariation(int play);
    int convertUnitToIntType(RGE_Static_Object* object) const;
    void loadUnitHistory();
    void unitsThatAreMostBuilt(int& firstType, int& secondType);
    void unitsThatAreLeastBuilt(int& firstType, int& secondType);
    int isBoat(RGE_Static_Object* object);
    int withinXTilesOfEnemyTowncenter(RGE_Static_Object* object, int tiles);
    int withinXTilesOfAttackOnPlayer(RGE_Static_Object* object, int tiles,
                                     int playerID);
    void updateResourceDropsites(int resourceType);
};

#endif
