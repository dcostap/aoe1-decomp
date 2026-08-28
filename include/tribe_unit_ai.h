#ifndef AOE1_TRIBE_UNIT_AI_H
#define AOE1_TRIBE_UNIT_AI_H

#include "unit_ai_module.h"

// PDB donor: TribeUnitAIModules.h. These derived modules add no data.
class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeArtifactUnitAIModule();
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeCivilianUnitAIModule();
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribePriestUnitAIModule();
};

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeHuntedAnimalUnitAIModule();
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeElephantUnitAIModule();
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeLionUnitAIModule();
};

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    TribePreditorUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribePreditorUnitAIModule();
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeFishingShipUnitAIModule();
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeTradeShipUnitAIModule();
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeTransportShipUnitAIModule();
};

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeTowerUnitAIModule();
};

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeBuildingUnitAIModule();
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    TribeSoldierUnitAIModule(RGE_Static_Object*, int);
    virtual ~TribeSoldierUnitAIModule();
};

typedef char tribe_unit_ai_module_size_check[
    (sizeof(UnitAIModule) == 0x134) ? 1 : -1];
typedef char tribe_hunted_animal_unit_ai_size_check[
    (sizeof(TribeHuntedAnimalUnitAIModule) == 0x134) ? 1 : -1];
typedef char tribe_preditor_unit_ai_size_check[
    (sizeof(TribePreditorUnitAIModule) == 0x134) ? 1 : -1];
typedef char tribe_soldier_unit_ai_size_check[
    (sizeof(TribeSoldierUnitAIModule) == 0x134) ? 1 : -1];

#endif  // AOE1_TRIBE_UNIT_AI_H
