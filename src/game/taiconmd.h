#pragma once
#include "../common.h"
#include "taibldmd.h"
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
#include "taiinfmd.h"
#include "tairesmd.h"
#include "taistrmd.h"
#include "taitacmd.h"
#include "tplayer.h"

class TribeConstructionAIModule : public ConstructionAIModule       {
public:
    char _pad_0x4[0x310];
    TribeMainDecisionAIModule* md;           // 0x314

    TribeConstructionAIModule(void* param_1, int param_2);
    TribeConstructionAIModule(int param_1, int param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~TribeConstructionAIModule() noexcept(false); // Ghidra: `scalar_deleting_destructor'

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
    // virtual void loadConstructionPlan();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void placeStructure();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void setBuilt();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void unplaceStructure();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void decrementBuildAttempts();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void incrementBuildAttempts();

    // --- Non-Virtual Members ---
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int canPlace(BuildItem* param_1);
    ConstructionItem* placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4);
    ConstructionItem* placeDock(BuildItem* param_1);
    void setBuilt(RGE_Static_Object* param_1, int param_2);
    ConstructionItem* compare(ConstructionItem* param_1, ConstructionItem* param_2);
};

static_assert(sizeof(TribeConstructionAIModule) == 0x318, "TribeConstructionAIModule Size Mismatch");
static_assert(offsetof(TribeConstructionAIModule, md) == 0x314, "TribeConstructionAIModule Offset Mismatch");

