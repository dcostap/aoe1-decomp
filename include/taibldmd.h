#ifndef AOE1_TAIBLDMD_H
#define AOE1_TAIBLDMD_H

// Local views for the original taibldmd.cpp source module.
// PDB source order: taibldmd.cpp lines 62-1773.
// Shared item, module, and array classes come from their owning headers.
#include "aibitm.h"
#include "aiblditm.h"
#include "aimodule.h"
#include "aibldmod.h"
#include "utmarray.h"
#include "airesitm.h"

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);

class RGE_Static_Object;
class TaibldmdMasterStaticObjectView;
class TaibldmdPlayerAttributesView;
class TribeMainDecisionAIModule;
class TribeBuildAIModule;
class ConstructionItem;

// This view uses only the master-object field read proven by taibldmd.
class TaibldmdMasterStaticObjectView {
public:
    char gap_000[0x10];
    short id;                         // +0x10
};

// aibldmod.h exposes the RGE_Player prefix used by that module.  taibldmd
// reads the later attributes member, so keep this narrow proven view local.
class TaibldmdPlayerAttributesView {
public:
    char gap_000[0x54];
    float* attributes;                // +0x54
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;                           // +0x04
    TaibldmdMasterStaticObjectView* master_obj; // +0x08
};

class TRIBE_Player {
public:
    unsigned char researchState(int type);
    int researchEverAvailable(int type);
    int researchAvailable(int type);
    int objectAvailable(int type);
    void researchCost(int type, int amount, ResourceItem* item, int flag);
    void objectCost(int type, int amount, ResourceItem* item, int flag);
};

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;               // +0xF0
    char gap_0F4[0x10];               // through +0x104

    RGE_Static_Object* object(int p1, int p2, int p3, int p4, int p5,
                              int p6, int p7, int p8, int p9, int p10);
    RGE_Static_Object* object(int id);
    void detask(int id);
    int isMoveable(int id);
};

class ConstructionItem {
public:
    float x();
    float y();
    float xSize();
    float ySize();
};

class TribeConstructionAIModule : public AIModule {
public:
    virtual ~TribeConstructionAIModule();
    virtual int save(int value);
    virtual int loadConstructionPlan(char* name, int mapX, int mapY,
                                     float xReference, float yReference,
                                     float zReference);
    virtual ConstructionItem* placeStructure(BuildItem* item);
    virtual void setBuilt(ConstructionItem* item, int built);
    virtual void removeLot(float x, float y, int status);
    virtual int unplaceStructure(float x, float y, int decrement);
    virtual void decrementBuildAttempts(float x, float y, int count);
    virtual void cancel(float x, float y, int number);

    char gap_0F0[0x228];
    int canPlace(BuildItem* item);
    void setBuilt(RGE_Static_Object* object, int value);
    ConstructionItem* lot(float x, float y);
};

class TribeInformationAIModule {
public:
    char gap_000[0x10090];
    int isBuilding(RGE_Static_Object* object);
    int numberStoragePits();
    int numberGranaries();
    void removeLot(int type, int x, int y, unsigned char status);
};

class TribeResourceAIModule {
public:
    char gap_000[0xF8];
    int resource(int type) const;
    int resourcesAvailable(ResourceItem* item);
    int unavailableResource(ResourceItem* item);
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_000[0xE40];
    int wonderInProgressValue;
    int wonderBuiltValue;
    char gap_0E4C[0x1C0];
    int strategicNumber(int number);
    void enableAttack(int value);
    void setStrategicNumber(int number, int value);
    void updateNeededResources();
    int clearArea(int objectID, float x1, float y1, float x2, float y2);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    char buildAI[0x5C0];                         // +0x104
    TribeConstructionAIModule constructionAI;    // +0x6C4
    char gap_09DC[0x310];                        // through +0xCEC
    TribeInformationAIModule informationAI;      // +0xCEC
    TribeResourceAIModule resourceAI;            // +0x10D7C
    char gap_10E74[0x5F8];                        // through +0x1146C
    TribeTacticalAIModule tacticalAI;            // +0x1146C
    char gap_12478[0xF4];                        // through +0x1256C
    TRIBE_Player* aiPlayer;                      // +0x1256C
};

class TribeBuildAIModule : public BuildAIModule {
public:
    TribeMainDecisionAIModule* md;               // +0x5BC

    TribeBuildAIModule(void* owner, int player);
    TribeBuildAIModule(int file, int player);
    virtual ~TribeBuildAIModule();
    virtual int loadBuildList(char* filename, RGE_Player* player);
    virtual int numberBuiltOrInProgressItemsOfType(int type, int flag);

    void setMainDecisionAI(TribeMainDecisionAIModule* value);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int category);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem& item, int maxCount);
    int isAgeResearch(int type);
    int insert(int type, int count, int index);
    int insertResearch(int research, int index);
    int insertGathererPercentage(int index, int percentage, int bronzeAgeIndex);
    int addItem(RGE_Static_Object* object, int flag);
    int addBuiltItem(RGE_Static_Object* object, int id);
    int removeBuiltItem(int id);
    int cancelBuildItem(int action, int objId, int objectTypeId,
                        float x, float y, int uniqueBuildId, int taskId);
    int addTrainedUnit(int param1, int param2, int param3, int param4);
    int cancelTrainUnit(int param1, int param2, int param3, int param4);
    int addResearch(int param1, int param2, int param3);
    int cancelResearch(int param1, int param2, int param3, int param4);
    int readyToResearch(int param1, int param2);
    void unskipBuildList(int limit67, int limit44);
    BuildItem* buildItem(int type, int category1, int category2);
    int allBuilt(int param1, int param2);
};

#endif  // AOE1_TAIBLDMD_H
