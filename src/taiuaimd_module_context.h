#ifndef TAIUAIMD_MODULE_CONTEXT_H
#define TAIUAIMD_MODULE_CONTEXT_H

// Module-local TU context. This file extends the reviewed UnitAIModule surface
// without changing the shared declarations used by standalone owners.
#include "../include/taiuaimd_context.h"
#include <stdio.h>

class RGE_Base_Game {
public:
    int scenarioGame();
    int singlePlayerGame();
    int inScenarioEditor();
};

class RGE_Visible_Map {
public:
    unsigned char get_visible(int x, int y);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    char gap_04[8];
    unsigned char state;
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    char gap_04[4];
    RGE_Action* action(int index);
    unsigned char have_action();
    RGE_Action* get_action();
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    int id;
    char gap_08[4];
    char gap_10[0x34];
    float attribute_amount_held;
    char gap_48[0x13C];
    RGE_Action_List* actions;
    RGE_Action_List* action_list;
};

struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    int resize(int);
};

struct HealUnitRecord {
    int object_id;
    unsigned char priority;
    unsigned char gap_05[3];
};

struct VISIBLE_UNIT_REC {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

extern int taiuaimd_heal_counts[5];
extern HealUnitRecord* taiuaimd_heal_records[5];
extern int numberDifferentPlayerObjectsVisible;

void* operator_new(unsigned int size);
void operator_delete(void* pointer);

// The beta source uses these world calls in several notification and idle
// methods. They are module-local declarations; their ABI remains thiscall.
int taiuaimd_world_next_object_id(RGE_Game_World* world);
int taiuaimd_world_difficulty(RGE_Game_World* world);
RGE_Visible_Map* taiuaimd_player_visible_map(RGE_Player* player);
int taiuaimd_player_notify(RGE_Player*, int, int, int, long, long, long);
int taiuaimd_object_action_state(RGE_Static_Object* object);
int taiuaimd_object_can_path(RGE_Static_Object* object, int, float, float*, int, int, int);
int taiuaimd_object_can_see(RGE_Static_Object* object, int, float, int, int, int, int);
int taiuaimd_player_is_enemy(RGE_Player* player, int);
int taiuaimd_player_strategic_number(RGE_Player* player, int);
int taiuaimd_object_in_group(RGE_Static_Object* object);

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    TribeElephantUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int closestAttacker(float*);
    virtual int attackObject(int, int);
    char module_gap_elephant[0x80];
    int* notifyArray;
    int notifyCount;
    int notifyCapacity;
};

struct RGE_Combat_Object {
    char gap_04[0x48];
    unsigned char interaction_type;
};

class TribeLionUnitAIModule : public UnitAIModule {
public:
    TribeLionUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int attackObject(int, int);
    RGE_Static_Object* lookupObject(int);
    virtual int notifyCommander(NotifyEvent*);
    char module_gap_lion[0xD0];
    int field_34;
    int field_100;
};

class TribeRangedUnitAIModule : public UnitAIModule {
public:
    TribeRangedUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int processNotify(NotifyEvent*, unsigned long);
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    TribeRangedUnitAIModule2(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int baseProcessNotify(NotifyEvent*, unsigned long);
    RGE_Static_Object* obj;
    char module_gap_ranged2[0x24];
    int p2c;
    int state;
    int target_id;
    char gap_38[4];
    float p3c;
    float p40;
    float p44;
    float p48;
    char gap_4c[0x14];
    int count;
    char gap_68[4];
    int capacity;
    int* ids;
};

class TribeCivilianUnitAIModule : public UnitAIModule {
public:
    TribeCivilianUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int importantWhenDead(int);
    virtual int attackObject(int, int);
    virtual int huntObject(int, int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int retryableOrder(int);
    virtual int convertToLOSResourceType(int);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual RGE_Static_Object* lookupObject(int);
    virtual void askForHelp(int);
    virtual int addToWaypointQueue(int, int);
    char module_gap_civilian[0xF0];
    int field_F8;
};

class TribePriestUnitAIModule : public UnitAIModule {
public:
    TribePriestUnitAIModule(RGE_Static_Object* object, int parameter);
    TribePriestUnitAIModule(void* object, int parameter);
    virtual int attackObject(int, int);
    virtual int retryableOrder(int);
    virtual int canConvert(int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual RGE_Static_Object* lookupObject(int);
    RGE_Static_Object* unit;
    void* some_ptr;
    virtual int convertObject(int, int);
    virtual int moveTo(int, float, int);
    virtual int notifyCommander(NotifyEvent*);
    virtual int visibleStatus(RGE_Visible_Map*, int, int);
    int field_120;
    int field_124;
    int field_128;
    int field_12C;
    char field_130;
    char module_gap_priest[0xF0];
    int field_28;
    int field_30;
    int field_34;
};

class TribeTradeShipUnitAIModule : public UnitAIModule {
public:
    TribeTradeShipUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    int* helpList;
    int helpCount;
    int helpDesired;
    int helpMax;
    virtual int addToWaypointQueue(int, int);
    virtual void askForHelp(int);
    RGE_Static_Object* obj;
    virtual int moveTo(float, float, int, int);
};

class TribeTransportShipUnitAIModule : public UnitAIModule {
public:
    TribeTransportShipUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    RGE_Static_Object* obj;
    int currentTarget;
    int currentOrder;
    int* helpList;
    int helpCount;
    int helpMax;
    virtual void askForHelp(int);
    RGE_Static_Object* sub;
    virtual int moveTo(float, float, int, int);
};

class TribeFishingShipUnitAIModule : public UnitAIModule {
public:
    TribeFishingShipUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int importantWhenDead(int);
    virtual int convertToLOSResourceType(int);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    int* helpList;
    int helpCount;
    int helpMax;
    virtual void askForHelp(int);
    virtual int moveTo(float, float, int, int);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual int notifyCommander(NotifyEvent*);
    virtual int getActionState(int);
    void* obj;
    int field_F8;
    int field_28;
    int field_30;
    int targetId;
    int count;
    int capacity;
    int* ids;
};

class TribeTowerUnitAIModule : public UnitAIModule {
public:
    TribeTowerUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int);
    RGE_Combat_Object* object;
};

class TribeBuildingUnitAIModule : public UnitAIModule {
public:
    TribeBuildingUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    RGE_Static_Object* obj;
    int currentOrder;
    int currentTarget;
    virtual void askForHelp(int);
};

extern const char str_taiuaimd_path[];
extern const char str_fmt_stopObject[];
extern RGE_Base_Game* rge_base_game;

#endif
