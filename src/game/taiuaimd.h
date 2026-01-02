#pragma once
#include "../common.h"

class TribeLionUnitAIModule : public UnitAIModule {
public:

    TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeLionUnitAIModule();
    virtual int canAttackUnitAtNeutrality(int param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeLionUnitAIModule) == 0x134, "TribeLionUnitAIModule Size Mismatch");

class TribeSoldierUnitAIModule : public UnitAIModule {
public:

    TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeSoldierUnitAIModule();
    virtual int canAttackUnit(RGE_Static_Object* param_1);
    virtual int canAttackUnitAtNeutrality(int param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeSoldierUnitAIModule) == 0x134, "TribeSoldierUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule : public UnitAIModule {
public:

    TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeRangedUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
};

static_assert(sizeof(TribeRangedUnitAIModule) == 0x134, "TribeRangedUnitAIModule Size Mismatch");

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:

    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeHuntedAnimalUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeHuntedAnimalUnitAIModule) == 0x134, "TribeHuntedAnimalUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:

    TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeRangedUnitAIModule2();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
};

static_assert(sizeof(TribeRangedUnitAIModule2) == 0x134, "TribeRangedUnitAIModule2 Size Mismatch");

class TribeElephantUnitAIModule : public UnitAIModule {
public:

    TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeElephantUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeElephantUnitAIModule) == 0x134, "TribeElephantUnitAIModule Size Mismatch");

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:

    TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeFishingShipUnitAIModule();
    virtual int importantWhenDead(int param_1);
    virtual int convertToLOSResourceType(int param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeFishingShipUnitAIModule) == 0x134, "TribeFishingShipUnitAIModule Size Mismatch");

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:

    TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTradeShipUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeTradeShipUnitAIModule) == 0x134, "TribeTradeShipUnitAIModule Size Mismatch");

class TribePriestUnitAIModule : public UnitAIModule {
public:

    TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribePriestUnitAIModule();
    virtual int attackObject(int param_1, int param_2);
    virtual int retryableOrder(int param_1);
    virtual int canConvert(int param_1);
    virtual int canAttackUnit(RGE_Static_Object* param_1);
    virtual int bestUnitToHeal(int param_1, float* param_2);
    virtual int bestUnitToConvert(float* param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
    virtual int processMisc();
};

static_assert(sizeof(TribePriestUnitAIModule) == 0x134, "TribePriestUnitAIModule Size Mismatch");

class TribeTowerUnitAIModule : public UnitAIModule {
public:

    TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTowerUnitAIModule();
    virtual int canAttackUnit(RGE_Static_Object* param_1);
    virtual int canAttackUnitAtNeutrality(int param_1);
};

static_assert(sizeof(TribeTowerUnitAIModule) == 0x134, "TribeTowerUnitAIModule Size Mismatch");

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:

    TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeTransportShipUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeTransportShipUnitAIModule) == 0x134, "TribeTransportShipUnitAIModule Size Mismatch");

class TribeArtifactUnitAIModule : public UnitAIModule {
public:

    TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeArtifactUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
    virtual int processMisc();
};

static_assert(sizeof(TribeArtifactUnitAIModule) == 0x134, "TribeArtifactUnitAIModule Size Mismatch");

class TribePreditorUnitAIModule : public UnitAIModule {
public:

    TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribePreditorUnitAIModule();
    virtual int canAttackUnitAtNeutrality(int param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
};

static_assert(sizeof(TribePreditorUnitAIModule) == 0x134, "TribePreditorUnitAIModule Size Mismatch");

class TribeCivilianUnitAIModule : public UnitAIModule {
public:

    TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeCivilianUnitAIModule();
    virtual int importantWhenDead(int param_1);
    virtual int attackObject(int param_1, int param_2);
    virtual int canAttackUnit(RGE_Static_Object* param_1);
    virtual int canAttackUnitAtNeutrality(int param_1);
    virtual int retryableOrder(int param_1);
    virtual int convertToLOSResourceType(int param_1);
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
    virtual int processMisc();
};

static_assert(sizeof(TribeCivilianUnitAIModule) == 0x134, "TribeCivilianUnitAIModule Size Mismatch");

class TribeBuildingUnitAIModule : public UnitAIModule {
public:

    TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2);
    virtual ~TribeBuildingUnitAIModule();
    virtual int processNotify(NotifyEvent* param_1, ulong param_2);
    virtual int processIdle(int param_1);
};

static_assert(sizeof(TribeBuildingUnitAIModule) == 0x134, "TribeBuildingUnitAIModule Size Mismatch");

