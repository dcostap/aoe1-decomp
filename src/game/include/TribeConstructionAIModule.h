#pragma once
#include "common.h"
#include "ConstructionAIModule.h"

struct PlacementState;

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    TribeConstructionAIModule(void* param_1, int param_2);
    TribeConstructionAIModule(int param_1, int param_2);

    // Virtuals (best-effort)
    virtual ~TribeConstructionAIModule(); // vt[0] (0x0)
    virtual int loggingHistory(); // vt[1] (0x4)
    virtual void setLogHistory(int param_1); // vt[2] (0x8)
    virtual void toggleLogHistory(); // vt[3] (0xC)
    virtual void setHistoryFilename(char* param_1); // vt[4] (0x10)
    virtual int loggingCommonHistory(); // vt[5] (0x14)
    virtual void setLogCommonHistory(int param_1); // vt[6] (0x18)
    virtual void toggleLogCommonHistory(); // vt[7] (0x1C)
    virtual int loadState(char* param_1); // vt[8] (0x20)
    virtual int saveState(char* param_1); // vt[9] (0x24)
    virtual int gleanState(int param_1); // vt[10] (0x28)
    virtual int processMessage(AIModuleMessage* param_1); // vt[11] (0x2C)
    virtual int update(int param_1); // vt[12] (0x30)
    virtual void setCallbackMessage(AIModuleMessage* param_1); // vt[13] (0x34)
    virtual int filterOutMessage(AIModuleMessage* param_1); // vt[14] (0x38)
    virtual int save(int param_1) const; // vt[15] (0x3C)
    virtual int loadConstructionPlan(char* param_1, int param_2, int param_3, float param_4, float param_5, float param_6) const; // vt[16] (0x40)
    virtual ConstructionItem* placeStructure(BuildItem* param_1) const; // vt[17] (0x44)
    virtual void setBuilt(ConstructionItem* param_1, int param_2) const; // vt[18] (0x48)
    virtual int unplaceStructure(float param_1, float param_2, int param_3) const; // vt[19] (0x4C)
    virtual int unplaceStructure(ConstructionItem* param_1, int param_2) const; // vt[20] (0x50)
    virtual void decrementBuildAttempts(float param_1, float param_2, int param_3) const; // vt[21] (0x54)
    virtual void incrementBuildAttempts(float param_1, float param_2, int param_3) const; // vt[22] (0x58)

    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int canPlace(BuildItem* param_1);
    ConstructionItem* placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4);
    ConstructionItem* placeDock(BuildItem* param_1);
    void setBuilt(RGE_Static_Object* param_1, int param_2);

protected:
    ConstructionItem* compare(ConstructionItem* param_1, ConstructionItem* param_2);

public:
    TribeMainDecisionAIModule* md;
};
static_assert(sizeof(TribeConstructionAIModule) == 0x318, "Size mismatch");
