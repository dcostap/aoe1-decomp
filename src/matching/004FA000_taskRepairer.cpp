#ifndef TAITACMD_SHARED_CONTEXT
// VA: 004FA000 TribeTacticalAIModule::taskRepairer (366 B)
// PDB source: taitacmd.cpp:8414-8438
// __thiscall, returns 0/1
//
// Attempt log:
// - Replaced the raw-offset/free-function scaffold with the period-typed
//   MainDecision/world lookup, RGE_Static_Object::canPath call, distance and
//   priority calls, ManagedIntArray growth, and player order dispatch.
// - Baseline typed reconstruction follows the exact taskBuilder and
//   taskFollower donors in the same translation unit.
// - Baseline was 366/366 bytes with one relocation mismatch: canPath emitted
//   at vslot +0x198 instead of the observed +0x194.
// - Removed the final padding virtual before the six-argument canPath surface;
//   this restored vslot +0x194 and produced MATCH, 366/366 bytes.
// - Final source keeps named object/world/player ownership and the natural
//   ManagedIntArray scan/growth idiom. Default flags; no inline asm.

#ifndef TAITACMD_SHARED_CONTEXT
/* Period RGE class declarations follow. */
struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Game_World;

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char); virtual void do_resign(int);
    virtual void changeToHumanPlayer(); virtual void changeToComputerPlayer();
    virtual char* aiStatus(int); virtual int isEnemy(int); virtual int isAlly(int);
    virtual int isNeutral(int); virtual int isAllNeutral(); virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int player, int param, int action, int unitId,
                                 int player2, float x, float y, float z,
                                 float f, int a, int b, int priority);
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game(); virtual void draw();
    virtual void shadow_draw(); virtual void normal_draw(); virtual void draw_front_frame();
    virtual void draw_back_frame(); virtual void draw_frame(); virtual void update();
    virtual void check_damage_sprites(); virtual void rehook(); virtual void save(int);
    virtual float teleport(float, float, float); virtual void new_sprite();
    virtual void add_overlay_sprite(); virtual void remove_overlay_sprite(); virtual void change_ownership();
    virtual void modify(float, unsigned char); virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char); virtual void transform(); virtual void copy_obj();
    virtual void set_object_state(unsigned char); virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying(); virtual void destroy_obj(); virtual void die_die_die();
    virtual void damage(); virtual float calculateDamage(); virtual void rotate(long);
    virtual unsigned char can_attack(); virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char); virtual int heal(int, int);
    virtual unsigned char heal(float); virtual int canRepair(); virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(); virtual void move_to(); virtual void work(); virtual void stop();
    virtual void set_attack(); virtual void play_command_sound(); virtual void play_move_sound();
    virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master(); virtual void set_being_worked_on(); virtual void release_being_worked_on();
    virtual unsigned char is_moving(); virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj();
    virtual void exit_obj(); virtual int explore_terrain(); virtual void unexplore_terrain();
    virtual void* get_los_table(); virtual int inAttackRange(); virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char); virtual float calc_attack_modifier(); virtual float getSpeed();
    virtual float getAngle(); virtual float maximumSpeed(); virtual float rateOfFire();
    virtual float damageCapability(); virtual float damageCapability(int); virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int canPath(int objectId, float distance, float* path,
                        int arg4, int arg5, int arg6);
    int id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    float world_z;

    float distance_to_object(RGE_Static_Object* object);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int calculatePriority(float distance);
    int taskRepairer(int id, RGE_Static_Object* repairer);
};
#endif

int TribeTacticalAIModule::taskRepairer(int id, RGE_Static_Object* repairer)
{
    RGE_Static_Object* object = this->md->player->world->object(id);
    if (object == 0) {
        return 0;
    }

    if (object->canPath(repairer->id, 1.0f, 0, 1, -1, -1) == 0) {
        return 0;
    }

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSizeValue)
            break;
        if (arr.value[i] == id)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSizeValue - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSizeValue && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSizeValue = newSize;
        }
    }

    arr.value[arr.numberValue] = id;
    arr.numberValue++;

dispatch:
    float distance = repairer->distance_to_object(object);
    int priority = this->calculatePriority(distance);
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder(player->id, id, 0x2CE, repairer->id,
                            player->id, repairer->world_x, repairer->world_y,
                            repairer->world_z, 1.0f, 1, 0, priority);
    return 1;
}
#else
int TribeTacticalAIModule::taskRepairer(int id, RGE_Static_Object* repairer) {
    return 0;
}
#endif
