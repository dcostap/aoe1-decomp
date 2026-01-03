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

class TribeConstructionAIModule : public ConstructionAIModule {
public:
    TribeMainDecisionAIModule* md;           // 0x314

    TribeConstructionAIModule(void* param_1, int param_2);
    TribeConstructionAIModule(int param_1, int param_2);
    virtual ~TribeConstructionAIModule();
    virtual void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    virtual int canPlace(BuildItem* param_1);
    virtual ConstructionItem* placeStructure(BuildItem* param_1, int param_2, PlacementState* param_3, ulong param_4);
    virtual ConstructionItem* placeDock(BuildItem* param_1);
    virtual void setBuilt(RGE_Static_Object* param_1, int param_2);
    virtual ConstructionItem* compare(ConstructionItem* param_1, ConstructionItem* param_2);
};

static_assert(sizeof(TribeConstructionAIModule) == 0x318, "TribeConstructionAIModule Size Mismatch");
static_assert(offsetof(TribeConstructionAIModule, md) == 0x314, "TribeConstructionAIModule Offset Mismatch");

