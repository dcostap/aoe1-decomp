#ifndef AOE1_AIMDMOD_TU_CONTEXT_H
#define AOE1_AIMDMOD_TU_CONTEXT_H

#include <new.h>
#include <stdlib.h>

typedef unsigned char uchar;

class AIModuleMessage;
class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Action_Object;
class RGE_Sprite;
class RGE_Color_Table;
class RGE_Armor_Weapon_Info;
class RGE_Object_List;
class RGE_Active_Sprite_List;
class RGE_Active_Sprite;
class LOSTBL;

void* operator new(unsigned int);
void operator delete(void*);
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);
extern "C" void __cdecl rge_read(int, void*, int);
void rge_write(int, const void*, int);

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
    AIModuleID(char*, int);
};

class AIModule {
public:
    virtual ~AIModule();
    virtual int loggingHistory();
    virtual void setLogHistory(int);
    virtual void toggleLogHistory();
    virtual void setHistoryFilename(char*);
    virtual int loggingCommonHistory();
    virtual void setLogCommonHistory(int);
    virtual void toggleLogCommonHistory();
    virtual int loadState(char*);
    virtual int saveState(char*);
    virtual int gleanState(int);
    virtual int processMessage(AIModuleMessage*);
    virtual int update(int);
    virtual void setCallbackMessage(AIModuleMessage*);
    virtual int filterOutMessage(AIModuleMessage*);

    AIModuleID idValue;
    int playerNumberValue;
    char playerNameValue[0x40];
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    void* historyLogFile;
    char historyLogFilename[0x40];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;

    AIModule(char*, int, int, void*);
    void logCommonHistory(char*, ...);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) { return this->value[index]; }
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int);
};

class UnitAIModule {
public:
    int currentAction();
    int currentTarget();
    int currentTargetType();
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    union { short id; short type_id; };
    short copy_id;
    union { short object_group; short class_id; };
    char gap_16[0x10];
    short max_hp;
};
typedef RGE_Master_Static_Object RGE_Static_Object_Type;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(void*, void*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(void*);
    virtual void add_overlay_sprite(void*, uchar);
    virtual void remove_overlay_sprite(void*);
    virtual void change_ownership(void*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(void*);
    virtual void copy_obj(void*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, void*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();

    int id;                                      // +0x04
    union {
        RGE_Master_Static_Object* master;
        RGE_Master_Static_Object* master_obj;
        RGE_Static_Object_Type* type;
    };                                           // +0x08
    char gap_0C[0x24];                           // +0x0C .. +0x2F
    float hit_points;                            // +0x30
    char gap_34[0x10];                           // +0x34 .. +0x43
    float attribute_amount_held;                 // +0x44
    uchar object_state;                          // +0x48
    char gap_49[3];

    UnitAIModule* unitAI();
};

class MainDecisionAIModule : public AIModule {
public:
    union {
        RGE_Player* player;
        RGE_Player* game;
    };                                             // +0xF0
    union {
        ManagedArray<int> objects;
        struct {
            union {
                int* objects_value;
                long* object_ids;
            };
            union {
                int objects_numberValue;
                int object_count;
                int field_F8;
            };
            int objects_pad_FC;
            union {
                int objects_maximumSizeValue;
                int object_capacity;
            };
        };
    };                                             // +0xF4

    MainDecisionAIModule(void*, int, RGE_Player*);
    MainDecisionAIModule(int, RGE_Player*, int);
    virtual ~MainDecisionAIModule();
    virtual void setLogHistory(int);
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);

    int numberObjects();
    int numberObjectsWithAction(int);
    int numberObjectsWithGroup(int);
    int numberObjectsWithActionAndTarget(int, int);
    int numberObjectsWithTargetType(int);
    int numberObjectsWithActionAndTargetType(int, int);
    RGE_Static_Object* object(int);
    RGE_Static_Object* object(int, int, int, int, int, int, int, int, int, int);
    RGE_Static_Object* object(int, int, int, int, int, int);
    int numberBusyObjects();
    RGE_Static_Object* mostDamaged(int, int);
};

#endif
