#pragma once
#include "UnitAIModule.h"

// Minimal derived UnitAIModule types used by TRIBE_Combat_Object::initUnitAI.
// These are data-layout compatible (no new fields); behavior currently inherits UnitAIModule.

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeArtifactUnitAIModule) == 0x134, "Size mismatch");

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeCivilianUnitAIModule) == 0x134, "Size mismatch");

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribePriestUnitAIModule) == 0x134, "Size mismatch");

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeHuntedAnimalUnitAIModule) == 0x134, "Size mismatch");

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeElephantUnitAIModule) == 0x134, "Size mismatch");

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeLionUnitAIModule) == 0x134, "Size mismatch");

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    TribePreditorUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribePreditorUnitAIModule) == 0x134, "Size mismatch");

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeFishingShipUnitAIModule) == 0x134, "Size mismatch");

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeTradeShipUnitAIModule) == 0x134, "Size mismatch");

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeTransportShipUnitAIModule) == 0x134, "Size mismatch");

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeBuildingUnitAIModule) == 0x134, "Size mismatch");

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeTowerUnitAIModule) == 0x134, "Size mismatch");

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    TribeSoldierUnitAIModule(RGE_Static_Object* param_1, int param_2) : UnitAIModule(param_1, param_2) {}
};
static_assert(sizeof(TribeSoldierUnitAIModule) == 0x134, "Size mismatch");

