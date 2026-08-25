#ifndef TAITACMD_SHARED_CONTEXT
// 00501190 TribeTacticalAIModule::selectBestCommander(TacticalAIGroup*)
// Source: taitacmd.cpp lines 11755-11801
// Attempt log:
// - Replaced stub with full best-commander scan and score comparison logic.
// - Exact match: keep `self` and `bestUnit` as explicit locals, and model the
//   object vfunc at vtable +0x10C as a float-returning virtual method.

#ifndef TAITACMD_SHARED_CONTEXT
class MasterObject { public: char gap_00[0x10]; short id; };
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game(); virtual void draw();
    virtual void shadow_draw(); virtual void normal_draw(); virtual void draw_front_frame();
    virtual void draw_back_frame(); virtual void draw_frame(); virtual void update();
    virtual void check_damage_sprites(); virtual void rehook(); virtual void save(int);
    virtual float teleport(float, float, float); virtual void new_sprite(); virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite(); virtual void change_ownership(); virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char); virtual void modify_percent(float, unsigned char);
    virtual void transform(); virtual void copy_obj(); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die(); virtual void damage(); virtual float calculateDamage();
    virtual void rotate(long); virtual unsigned char can_attack(); virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char); virtual int heal(int, int);
    virtual unsigned char heal(float); virtual int canRepair(); virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(); virtual void move_to(); virtual void work(); virtual void stop();
    virtual void set_attack(); virtual void play_command_sound(); virtual void play_move_sound();
    virtual void new_angle(float); virtual RGE_Static_Object* spawn_death_obj(); virtual void* get_command_master();
    virtual void set_being_worked_on(); virtual void release_being_worked_on(); virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj(); virtual void enter_obj(); virtual void exit_obj();
    virtual int explore_terrain(); virtual void unexplore_terrain(); virtual void* get_los_table();
    virtual int inAttackRange(); virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(); virtual float getSpeed(); virtual float getAngle();
    virtual float maximumSpeed(); virtual float rateOfFire(); virtual float damageCapability();
    virtual float damageCapability(int); virtual float weaponRange();

    char gap_04[4];
    MasterObject* master_obj;
    char gap_0C[0x30 - 0x0C];
    float score;
};
#endif

class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TacticalAIGroup {
public:
    int numberUnits();
    int unit(int index);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x2C0 - 0x0F4];
    int commanderSelectionMode;

    int selectBestCommander(TacticalAIGroup* group);
};

int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* group)
{
    TribeTacticalAIModule* self;
    int bestUnit;
    int bestScore;
    int i;
    int score;
    RGE_Static_Object* obj;
    int mode;

    self = this;
    bestScore = -1;
    bestUnit = -1;
    i = 0;
    if (group->numberUnits() > 0) {
        do {
            obj = self->md->object(group->unit(i));
            if (obj != 0) {
                if (obj->master_obj->id != 0x7D) {
                    if (self->commanderSelectionMode == 2) {
                        score = (int)obj->weaponRange();
                    }
                    else {
                        score = (int)obj->score;
                    }
                    mode = self->commanderSelectionMode;
                    if (mode == 1 || mode == 3) {
                        if (bestScore == -1 || score < bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                    else {
                        if (bestScore == -1 || score > bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                }
            }
            i = i + 1;
        } while (i < group->numberUnits());
    }
    return bestUnit;
}
#else
int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* group) {
    return 0;
}
#endif
