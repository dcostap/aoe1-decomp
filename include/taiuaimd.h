#ifndef AOE1_TAIUAIMD_H
#define AOE1_TAIUAIMD_H

// Canonical declarations for the PDB taiuaimd.cpp source module.
// UnitAIModule and game objects come from their owning headers.
#include "aiuaimod.h"
#include "act_obj.h"
#include "basegame.h"
#include "player.h"
#include "stat_obj.h"
#include "visible.h"
#include "vis_unit.h"
#include "world.h"

// The original source uses the short unsigned-long spelling.
typedef unsigned long ulong;

class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public:
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    TribePreditorUnitAIModule(RGE_Static_Object*, int);
    virtual int canAttackUnitAtNeutrality(int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object*, int);
    virtual int canAttackUnitAtNeutrality(int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object*, int);
    virtual int importantWhenDead(int);
    virtual int attackObject(int, int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int retryableOrder(int);
    virtual int convertToLOSResourceType(int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object*, int);
    virtual int attackObject(int, int);
    virtual int retryableOrder(int);
    virtual int canConvert(int);
    virtual int canAttackUnit(RGE_Static_Object*);
protected:
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object*, int);
    virtual int importantWhenDead(int);
    virtual int convertToLOSResourceType(int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    TribeSoldierUnitAIModule(RGE_Static_Object*, int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
};

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object*, int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
};

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object*, int);
protected:
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
};

extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern RGE_Base_Game* rge_base_game;

#endif  // AOE1_TAIUAIMD_H
