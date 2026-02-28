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
    virtual int canAttackUnit(RGE_Static_Object* param_1) override;
    virtual int canAttackUnitAtNeutrality(int param_1) override;
    virtual int processNotify(NotifyEvent* param_1, unsigned long param_2) override;
    virtual int processIdle(int param_1) override;
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
