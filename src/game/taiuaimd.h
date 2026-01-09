#pragma once
#include "common.h"

class TribeArtifactUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x507A30
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x507E90
    virtual int processMisc();                              // vt0[54]+0xD8=0x507EF0
    TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeArtifactUnitAIModule();
};

static_assert(sizeof(TribeArtifactUnitAIModule) == 0x134, "TribeArtifactUnitAIModule Size Mismatch");

class TribeBuildingUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x508320
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x508660
    TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeBuildingUnitAIModule();
};

static_assert(sizeof(TribeBuildingUnitAIModule) == 0x134, "TribeBuildingUnitAIModule Size Mismatch");

class TribeCivilianUnitAIModule : public UnitAIModule {
public:

    virtual int importantWhenDead(int param_1);             // vt0[9]+0x24=0x504C90
    virtual int retryableOrder(int param_1);                // vt0[10]+0x28=0x504D50
    virtual int canAttackUnit(RGE_Static_Object* param_1);  // vt0[20]+0x50=0x504D20
    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x504D40
    virtual int attackObject(int param_1, int param_2);     // vt0[23]+0x5C=0x504CC0
    virtual int convertToLOSResourceType(int param_1);      // vt0[48]+0xC0=0x504D80
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x504E10
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x505800
    virtual int processMisc();                              // vt0[54]+0xD8=0x505810
    TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeCivilianUnitAIModule();
};

static_assert(sizeof(TribeCivilianUnitAIModule) == 0x134, "TribeCivilianUnitAIModule Size Mismatch");

class TribeElephantUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x5041C0
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x5042D0
    TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeElephantUnitAIModule();
};

static_assert(sizeof(TribeElephantUnitAIModule) == 0x134, "TribeElephantUnitAIModule Size Mismatch");

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:

    virtual int importantWhenDead(int param_1);             // vt0[9]+0x24=0x506C70
    virtual int convertToLOSResourceType(int param_1);      // vt0[48]+0xC0=0x506C90
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x506CC0
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x506EE0
    TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeFishingShipUnitAIModule();
};

static_assert(sizeof(TribeFishingShipUnitAIModule) == 0x134, "TribeFishingShipUnitAIModule Size Mismatch");

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x503D30
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x503E30
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeHuntedAnimalUnitAIModule();
};

static_assert(sizeof(TribeHuntedAnimalUnitAIModule) == 0x134, "TribeHuntedAnimalUnitAIModule Size Mismatch");

class TribeLionUnitAIModule : public UnitAIModule {
public:

    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x504470
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x504480
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x504600
    TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeLionUnitAIModule();
};

static_assert(sizeof(TribeLionUnitAIModule) == 0x134, "TribeLionUnitAIModule Size Mismatch");

class TribePreditorUnitAIModule : public UnitAIModule {
public:

    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x5040A0
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x5040B0
    TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribePreditorUnitAIModule();
};

static_assert(sizeof(TribePreditorUnitAIModule) == 0x134, "TribePreditorUnitAIModule Size Mismatch");

class TribePriestUnitAIModule : public UnitAIModule {
public:

    virtual int retryableOrder(int param_1);                // vt0[10]+0x28=0x505A10
    virtual int canAttackUnit(RGE_Static_Object* param_1);  // vt0[20]+0x50=0x505AE0
    virtual int attackObject(int param_1, int param_2);     // vt0[23]+0x5C=0x5059A0
    virtual int canConvert(int param_1);                    // vt0[49]+0xC4=0x505A30
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x505DD0
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x505FD0
    virtual int processMisc();                              // vt0[54]+0xD8=0x506140
    virtual int bestUnitToHeal(int param_1, float* param_2); // vt0[56]+0xE0=0x505B00
    virtual int bestUnitToConvert(float* param_1);          // vt0[57]+0xE4=0x505CC0
    TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribePriestUnitAIModule();
};

static_assert(sizeof(TribePriestUnitAIModule) == 0x134, "TribePriestUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x504750
    TribeRangedUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeRangedUnitAIModule();
};

static_assert(sizeof(TribeRangedUnitAIModule) == 0x134, "TribeRangedUnitAIModule Size Mismatch");

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x5048D0
    TribeRangedUnitAIModule2(RGE_Static_Object* param_1, int param_2);
    ~TribeRangedUnitAIModule2();
};

static_assert(sizeof(TribeRangedUnitAIModule2) == 0x134, "TribeRangedUnitAIModule2 Size Mismatch");

class TribeSoldierUnitAIModule : public UnitAIModule {
public:

    virtual int canAttackUnit(RGE_Static_Object* param_1);  // vt0[20]+0x50=0x5071A0
    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x5071C0
    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x5071F0
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x507640
    TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeSoldierUnitAIModule();
};

static_assert(sizeof(TribeSoldierUnitAIModule) == 0x134, "TribeSoldierUnitAIModule Size Mismatch");

class TribeTowerUnitAIModule : public UnitAIModule {
public:

    virtual int canAttackUnit(RGE_Static_Object* param_1);  // vt0[20]+0x50=0x508110
    virtual int canAttackUnitAtNeutrality(int param_1);     // vt0[21]+0x54=0x508140
    TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeTowerUnitAIModule();
};

static_assert(sizeof(TribeTowerUnitAIModule) == 0x134, "TribeTowerUnitAIModule Size Mismatch");

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x506320
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x5066D0
    TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeTradeShipUnitAIModule();
};

static_assert(sizeof(TribeTradeShipUnitAIModule) == 0x134, "TribeTradeShipUnitAIModule Size Mismatch");

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:

    virtual int processNotify(NotifyEvent* param_1, ulong param_2); // vt0[51]+0xCC=0x5068B0
    virtual int processIdle(int param_1);                   // vt0[53]+0xD4=0x506A70
    TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2);
    ~TribeTransportShipUnitAIModule();
};

static_assert(sizeof(TribeTransportShipUnitAIModule) == 0x134, "TribeTransportShipUnitAIModule Size Mismatch");

