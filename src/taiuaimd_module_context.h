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

struct UnitObject {
    char gap_04[8];
    RGE_Player* ownerPlayer;
    virtual float vf10C(int);
};

class RGE_Object_List {
public:
    RGE_Static_Object* object(int id);
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

struct CallECHelper {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43();
    virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47();
    virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51();
    virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58();
    virtual void funcEC(int);
};

struct ObjVtbl {
    virtual void d00(); virtual void d01(); virtual void d02(); virtual void d03();
    virtual void d04(); virtual void d05(); virtual void d06(); virtual void d07();
    virtual void d08(); virtual void d09(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23();
    virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27();
    virtual void d28(); virtual void d29(); virtual void d30(); virtual void d31();
    virtual void d32(); virtual void d33(); virtual void d34(); virtual void d35();
    virtual void d36(); virtual void d37(); virtual void d38(); virtual void d39();
    virtual void d40(); virtual void d41(); virtual void d42(); virtual void d43();
    virtual void d44(); virtual void d45(); virtual void d46(); virtual void d47();
    virtual void d48(); virtual void d49(); virtual void d50(); virtual void d51();
    virtual void d52(); virtual void d53(); virtual void d54(); virtual void d55();
    virtual void d56(); virtual void d57(); virtual void d58(); virtual void d59();
    virtual void d60();
    virtual float funcF4(); virtual float funcF8(); virtual float funcFC(); virtual float func100();
};

struct ThisVtbl {
    virtual void d00(); virtual void d01(); virtual void d02(); virtual void d03();
    virtual void func10(int, int, int, int, float, float, float, float, int, int, int);
    virtual void e05(); virtual void e06(); virtual void e07(); virtual void e08();
    virtual void e09(); virtual void e10(); virtual void e11(); virtual void e12();
    virtual void e13(); virtual void e14(); virtual void e15(); virtual void e16();
    virtual void e17(); virtual void e18(); virtual void e19(); virtual void e20();
    virtual void e21(); virtual void e22(); virtual void e23(); virtual void e24();
    virtual void e25(); virtual void e26(); virtual void e27(); virtual void e28();
    virtual void e29(); virtual void e30(); virtual void e31(); virtual void e32();
    virtual void e33(); virtual void e34(); virtual void e35(); virtual void e36();
    virtual void e37(); virtual void e38();
    virtual void func9C(float, float, float, int);
};

struct TribeRangedUnitAIModule2Object {
    int id;
    char gap08[4];
    RGE_Game_World* world;
    char gap10[0x28];
    float x;
    float y;
    float field40;
    float vf_FC();
    float vf_100();
};

struct TribeTransportShipUnitAIModuleSub {
    char gap_04[8];
    RGE_Player* player;
    char gap_10[0x28];
    float x_pos;
    float y_pos;
    int field_40;
    virtual float getSpeed();
};

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
    virtual int func3C(int);
    virtual void func5C(int, int);
    char module_gap_elephant[0x80];
    int* notifyArray;
    int notifyCount;
    int notifyCapacity;
};

struct TaiuaimdSubObj {
    char gap[0x14];
    short field_14;
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
    virtual void doAction(int, int);
    virtual void some_00417770();
    virtual int findEnemy(int, int, int, int, int);
    virtual RGE_Static_Object* lookupObject(int);
    virtual void setTarget(int, int);
    virtual void vt07(NotifyEvent*);
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
    TribeRangedUnitAIModule2Object* obj;
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
    virtual int canAttackById(int);
    virtual int canAttackUnit(RGE_Static_Object*);
    virtual int bestUnitToHeal(int, float*);
    virtual int bestUnitToConvert(float*);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual RGE_Static_Object* lookupObject(int);
    UnitObject* unit;
    void* some_ptr;
    virtual int vf6C(int, int);
    virtual int vf94(int, float);
    virtual int vfC4(int);
    virtual int vte0(int, int);
    virtual int vte4(int);
    virtual int vt6c(int, int);
    virtual int vt70(int, int);
    virtual void vt1c(NotifyEvent*);
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
    virtual int findTarget(int, int, int, int, int);
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
    TribeTransportShipUnitAIModuleSub* sub;
    virtual int findTarget(int, int, int, int, int);
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
    virtual int findTarget(int, int, int, int, int);
    virtual int moveTo(float, float, int, int);
};

class TribeArtifactUnitAIModule : public UnitAIModule {
public:
    TribeArtifactUnitAIModule(RGE_Static_Object* object, int parameter);
    virtual int processNotify(NotifyEvent*, unsigned long);
    virtual int processIdle(int);
    virtual int processMisc();
    virtual void vt1c(NotifyEvent*);
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
