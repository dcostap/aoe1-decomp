#pragma once
#include "../common.h"
#include "aimdmod.h"
#include "aimodule.h"
#include "player.h"
#include "utmarray.h"
#include "aibldmod.h"
#include "aiconmod.h"
#include "aidipmod.h"
#include "aiemomod.h"
#include "aiinfmod.h"
#include "aimdmod.h"
#include "airchmod.h"
#include "airesmod.h"
#include "aistrmod.h"
#include "aitacmod.h"
#include "aitrdmod.h"
#include "aiuaimod.h"
#include "taiconmd.h"
#include "taiinfmd.h"
#include "tairesmd.h"
#include "taistrmd.h"
#include "taitacmd.h"
#include "tplayer.h"

class TribeBuildAIModule : public BuildAIModule       {
public:
    char _pad_0x4[0x5B8];
    TribeMainDecisionAIModule* md;           // 0x5BC

    TribeBuildAIModule(void* param_1, int param_2);
    TribeBuildAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeBuildAIModule() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void loggingHistory();

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void setLogHistory();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void toggleLogHistory();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void setHistoryFilename();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void loggingCommonHistory();

    // [Slot 06] Offset 0x18 WARNING: Function body missing in analysis
    // virtual void setLogCommonHistory();

    // [Slot 07] Offset 0x1C WARNING: Function body missing in analysis
    // virtual void toggleLogCommonHistory();

    // [Slot 08] Offset 0x20 WARNING: Function body missing in analysis
    // virtual void loadState();

    // [Slot 09] Offset 0x24 WARNING: Function body missing in analysis
    // virtual void saveState();

    // [Slot 10] Offset 0x28 WARNING: Function body missing in analysis
    // virtual void gleanState();

    // [Slot 11] Offset 0x2C WARNING: Function body missing in analysis
    // virtual void processMessage();

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void setCallbackMessage();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void filterOutMessage();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void displayBuildList();

    // [Slot 17] Offset 0x44 (Override)
    virtual int loadBuildList(char* param_1, RGE_Player* param_2); // Ghidra: loadBuildList

    // [Slot 18] Offset 0x48 (Override)
    virtual int numberBuiltOrInProgressItemsOfType(int param_1, int param_2); // Ghidra: numberBuiltOrInProgressItemsOfType

    // --- Non-Virtual Members ---
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    void initialize();
    void skipNextBuildListItem();
    BuildItem* nextBuildableItem(int param_1);
    int nextBuildListItemCategory();
    int blockingResource();
    int mostNeededResource(ResourceItem* param_1, int param_2);
    int addItem(RGE_Static_Object* param_1, int param_2);
    int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    int removeBuiltItem(int param_1);
    int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    int addResearch(int param_1, int param_2, int param_3);
    int cancelResearch(int param_1, int param_2, int param_3, int param_4);
    int isAgeResearch(int param_1);
    int insert(int param_1, int param_2, int param_3);
    int insertResearch(int param_1, int param_2);
    int insertGathererPercentage(int param_1, int param_2, int param_3);
    int allBuilt(int param_1, int param_2);
    int readyToResearch(int param_1, int param_2);
    void unskipBuildList(int param_1, int param_2);
    BuildItem* buildItem(int param_1, int param_2, int param_3);
};

static_assert(sizeof(TribeBuildAIModule) == 0x5C0, "TribeBuildAIModule Size Mismatch");
static_assert(offsetof(TribeBuildAIModule, md) == 0x5BC, "TribeBuildAIModule Offset Mismatch");

