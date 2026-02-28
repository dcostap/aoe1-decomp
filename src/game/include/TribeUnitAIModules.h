#pragma once
#include "UnitAIModule.h"

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeArtifactUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
    virtual int processMisc() override;
};
static_assert(sizeof(TribeArtifactUnitAIModule) == 0x134, "Size mismatch");

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeCivilianUnitAIModule();
    virtual int importantWhenDead(int param_1) override;
    virtual int attackObject(int param_1, int param_2) override;
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int retryableOrder(int param_1) override;
    virtual int convertToLOSResourceType(int param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
    virtual int processMisc() override;
};
static_assert(sizeof(TribeCivilianUnitAIModule) == 0x134, "Size mismatch");

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribePriestUnitAIModule();
    virtual int attackObject(int param_1, int param_2) override;
    virtual int retryableOrder(int param_1) override;
    virtual int canConvert(int param_1) override;
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    int bestUnitToHeal(int param_1, float* param_2);
    int bestUnitToConvert(float* param_1);
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
    virtual int processMisc() override;
};
static_assert(sizeof(TribePriestUnitAIModule) == 0x134, "Size mismatch");

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeHuntedAnimalUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeHuntedAnimalUnitAIModule) == 0x134, "Size mismatch");

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeElephantUnitAIModule();
    virtual int importantWhenDead(int param_1) override;
    virtual int retryableOrder(int param_1) override;
    virtual int actionRequiresLiveTarget(int param_1) override;
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3) override;
    virtual int mostDangerousEnemy(float* param_1) override;
    virtual int weakestEnemy(float* param_1) override;
    virtual int closestAttacker(float* param_1) override;
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5) override;
    virtual int closestResourceObject(int param_1, int* param_2) override;
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3) override;
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int stopObject(int param_1) override;
    virtual int attackObject(int param_1, int param_2) override;
    virtual int attackRoundupObject(int param_1) override;
    virtual int huntObject(int param_1, int param_2) override;
    virtual int gatherObject(int param_1, int param_2) override;
    virtual int convertObject(int param_1, int param_2) override;
    virtual int healObject(int param_1, int param_2) override;
    virtual int repairObject(int param_1, int param_2) override;
    virtual int buildObject(int param_1, int param_2) override;
    virtual int tradeWithObject(int param_1, int param_2) override;
    virtual int explore(int param_1, int param_2, int param_3) override;
    virtual int enterObject(int param_1, int param_2) override;
    virtual int unload(int param_1, float param_2, float param_3) override;
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4) override;
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) override;
    virtual int moveTo(int param_1, float param_2, int param_3) override;
    virtual int moveTo(int param_1, int param_2) override;
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4) override;
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5) override;
    virtual int runAwayFromAttackers(int param_1) override;
    virtual int followObject(int param_1, float param_2, int param_3) override;
    virtual int defendObject(int param_1, float param_2, int param_3) override;
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4) override;
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4) override;
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3) override;
    virtual int convertToLOSResourceType(int param_1) override;
    virtual int processOrder(OrderEvent* param_1, int param_2) override;
    virtual void processGroupNotify(NotifyEvent* param_1) override;
    virtual int processMisc() override;
    virtual int processRetryableOrder() override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeElephantUnitAIModule) == 0x134, "Size mismatch");

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeLionUnitAIModule();
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeLionUnitAIModule) == 0x134, "Size mismatch");

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribePreditorUnitAIModule();
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
};
static_assert(sizeof(TribePreditorUnitAIModule) == 0x134, "Size mismatch");

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeFishingShipUnitAIModule();
    virtual int importantWhenDead(int param_1) override;
    virtual int convertToLOSResourceType(int param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeFishingShipUnitAIModule) == 0x134, "Size mismatch");

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTradeShipUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeTradeShipUnitAIModule) == 0x134, "Size mismatch");

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTransportShipUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeTransportShipUnitAIModule) == 0x134, "Size mismatch");

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeBuildingUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeBuildingUnitAIModule) == 0x134, "Size mismatch");

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTowerUnitAIModule();
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    virtual int canAttackUnitAtNeutrality(int param_1) override;
};
static_assert(sizeof(TribeTowerUnitAIModule) == 0x134, "Size mismatch");

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeSoldierUnitAIModule();
    virtual int importantWhenDead(int param_1) override;
    virtual int retryableOrder(int param_1) override;
    virtual int actionRequiresLiveTarget(int param_1) override;
    virtual int bestUnitToAttack(int param_1, int param_2, float* param_3) override;
    virtual int mostDangerousEnemy(float* param_1) override;
    virtual int weakestEnemy(float* param_1) override;
    virtual int closestAttacker(float* param_1) override;
    virtual int closestObject(int param_1, int param_2, int param_3, int param_4, int* param_5) override;
    virtual int closestResourceObject(int param_1, int* param_2) override;
    virtual int closestUndiscoveredTile(int* param_1, int* param_2, int param_3) override;
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int stopObject(int param_1) override;
    virtual int attackObject(int param_1, int param_2) override;
    virtual int attackRoundupObject(int param_1) override;
    virtual int huntObject(int param_1, int param_2) override;
    virtual int gatherObject(int param_1, int param_2) override;
    virtual int convertObject(int param_1, int param_2) override;
    virtual int healObject(int param_1, int param_2) override;
    virtual int repairObject(int param_1, int param_2) override;
    virtual int buildObject(int param_1, int param_2) override;
    virtual int tradeWithObject(int param_1, int param_2) override;
    virtual int explore(int param_1, int param_2, int param_3) override;
    virtual int enterObject(int param_1, int param_2) override;
    virtual int unload(int param_1, float param_2, float param_3) override;
    virtual int transportObject(float param_1, float param_2, float param_3, int param_4) override;
    virtual int moveTo(float param_1, float param_2, float param_3, float param_4, int param_5) override;
    virtual int moveTo(int param_1, float param_2, int param_3) override;
    virtual int moveTo(int param_1, int param_2) override;
    virtual int evasiveMoveTo(float param_1, float param_2, float param_3, int param_4) override;
    virtual int intelligentEvasiveMoveTo(float param_1, float param_2, float param_3, int param_4, int param_5) override;
    virtual int runAwayFromAttackers(int param_1) override;
    virtual int followObject(int param_1, float param_2, int param_3) override;
    virtual int defendObject(int param_1, float param_2, int param_3) override;
    virtual int defendPosition(float param_1, float param_2, float param_3, int param_4) override;
    virtual int seekAndDestroy(int param_1, int param_2, int param_3, int param_4) override;
    virtual int exploreAndDestroy(int param_1, int param_2, int param_3) override;
    virtual int convertToLOSResourceType(int param_1) override;
    virtual int processOrder(OrderEvent* param_1, int param_2) override;
    virtual void processGroupNotify(NotifyEvent* param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
    virtual int processMisc() override;
    virtual int processRetryableOrder() override;
};
static_assert(sizeof(TribeSoldierUnitAIModule) == 0x134, "Size mismatch");

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeRangedUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
};
static_assert(sizeof(TribeRangedUnitAIModule) == 0x134, "Size mismatch");

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeRangedUnitAIModule2();
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
};
static_assert(sizeof(TribeRangedUnitAIModule2) == 0x134, "Size mismatch");

UnitAIModule* CreateTribeUnitAIModule(RGE_Static_Object* object, short object_group, short master_id);
