#ifndef AOE1_TAIUAIMD_H
#define AOE1_TAIUAIMD_H

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
    TribeHuntedAnimalUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribePreditorUnitAIModule : public UnitAIModule {
public:
    TribePreditorUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int canAttackUnitAtNeutrality(int oType);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int canAttackUnitAtNeutrality(int oType);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int importantWhenDead(int objectType);
    virtual int attackObject(int targetID, int unconditional);
    virtual int canAttackUnit(RGE_Static_Object* unit);
    virtual int canAttackUnitAtNeutrality(int oType);
    virtual int retryableOrder(int orderType);
    virtual int convertToLOSResourceType(int oType);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
    virtual int processMisc();
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int attackObject(int targetID, int unconditional);
    virtual int retryableOrder(int orderType);
    virtual int canConvert(int targetID);
    virtual int canAttackUnit(RGE_Static_Object* unit);
protected:
    virtual int bestUnitToHeal(int idleHeal, float* allyDistance);
    virtual int bestUnitToConvert(float* distance);
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
    virtual int processMisc();
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int importantWhenDead(int objectType);
    virtual int convertToLOSResourceType(int oType);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeSoldierUnitAIModule : public UnitAIModule {
public:
    TribeSoldierUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int canAttackUnit(RGE_Static_Object* unit);
    virtual int canAttackUnitAtNeutrality(int oType);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
    virtual int processMisc();
};

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object* o, int iQS);
    virtual int canAttackUnit(RGE_Static_Object* unit);
    virtual int canAttackUnitAtNeutrality(int oType);
};

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object* o, int iQS);
protected:
    virtual int processNotify(NotifyEvent* nEvent, unsigned long uTime);
    virtual int processIdle(int doSearch);
};

extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern RGE_Base_Game* rge_base_game;

#endif  // AOE1_TAIUAIMD_H
