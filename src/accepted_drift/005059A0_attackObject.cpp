// VA: 005059A0 TribePriestUnitAIModule::attackObject(int, int)
// PDB source: taiuaimd.cpp lines 1338-1349
// Default flags
//
// attempt log:
// Attempt 1: explicit vtable with void* vtable → shifted offsets by 4 (extra vtable ptr)
// Attempt 2: removed explicit void* vtable → TribePriestUnitAIModule offsets correct
// Attempt 3: object with gap_00[0xC] → shifted offsets by 4 (hidden vtable)
// Attempt 4: object with gap_04[0x8] → all offsets correct, 99/103 matching
// Attempt 5: float temp for weaponRange result → 51 diff bytes (worse)
// Attempt 6: int cp temp → same 4-byte register diff
// Attempt 7: object pointer temp → 51 diff bytes (worse)
//
// Remaining mismatch: 4 bytes of register allocation in weaponRange call block:
//   Original: mov edx,[esp+14h]; push edx; mov eax,[ecx]; call [eax+10Ch]
//   Rebuild:  mov eax,[esp+14h]; push eax; mov edx,[ecx]; call [edx+10Ch]
// This is a stable register-color difference in VC5's virtual-call scheduling.
// SpruceGlow tries 1-10: param_2 local/self-assign/mutate/cast, late object local, float local,
//   early-return/else/nested-positive control-flow forms, manual vtable attempt, and separate object
//   owner local. Most kept the same 4-byte register-color diff; float/local owner/control-flow variants
//   were much worse or failed to compile due VC5 __thiscall limitations.
// SpruceGlow tries 11-20: volatile param_2, long local, saved result, late object declaration,
//   param_1 local, split computerPlayer temp, zero return local, helper idint, and weaponRange signature probes
//   (long/void*) all either kept the same 4-byte diff or worsened codegen.
// ACCEPTED_DRIFT: reviewed by Boss. The diff is exactly four same-length register-color
// bytes in one virtual-call setup: rebuilt pushes param_2 through eax and loads/calls the
// vtable through edx, while original uses edx for the pushed arg and eax for vtable/call.
// Stack effects, call target slot (+0x10C), FPU result handling, branches, return values,
// size, and epilogues are byte-identical otherwise. No inline asm/hacks.

#ifndef TAIUAIMD_COMPLETE_TU
class RGE_Master_Static_Object;

class RGE_Player {
public:
    int computerPlayer();
};

class RGE_Static_Object {
public:
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange(); // slot 67, offset 0x10C
};

class TribePriestUnitAIModule {
public:
    RGE_Static_Object* unit;  // +0x04
    char gap_08[0x20];        // +0x08 to +0x27
    int field_28;             // +0x28

    virtual ~TribePriestUnitAIModule();
    virtual void save(int); virtual void load(int); virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*); virtual void search();
    virtual int importantWhenDead(int); virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int); virtual int stopObject(int);
    virtual int attackObject(int, int); virtual int attackRoundupObject(int);
    virtual int huntObject(int, int); virtual int gatherObject(int, int);
    virtual int convertObject(int, int);
    virtual int healObject(int, int); virtual int repairObject(int, int);
    virtual int buildObject(int, int); virtual int tradeWithObject(int, int);
    virtual int explore(int, int, int); virtual int enterObject(int, int);
    virtual int unload(int, float, float);
    virtual int transportObject(float, float, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int); virtual int moveTo(int, int);
    virtual int evasiveMoveTo(float, float, float, int);
    virtual int intelligentEvasiveMoveTo(float, float, float, int, int);
    virtual int runAwayFromAttackers(int); virtual int followObject(int, float, int);
    virtual int defendObject(int, float, int);
    virtual int defendPosition(float, float, float, int);
    virtual int seekAndDestroy(int, int, int, int);
    virtual int exploreAndDestroy(int, int, int);
    virtual int importantObject(int); virtual int convertToLOSResourceType(int);
    virtual int canConvert(int param_1); // slot 49, offset 0xC4
};
#endif

int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (this->canConvert(param_1) == 0) {
        if (this->field_28 == -1) {
            if (this->unit->owner->computerPlayer() != 0) {
                return this->moveTo(param_1, this->unit->weaponRange(), param_2);
            }
        }
        return 0;
    }
    return this->convertObject(param_1, param_2);
}
