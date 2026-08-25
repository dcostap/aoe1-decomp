#ifndef TAITACMD_SHARED_CONTEXT
// 00501260 TribeTacticalAIModule::selectBestCommander
// Attempt log:
// 1: Reconstruct from packet with helper: too small due outlined helper.
// 2: Inline ManagedArray operator[] growth at all use sites.
// 3: Fix md at +f0, virtual slot +0x10c, and avoid direct early return: improved to 10.58% positional / 6.26% edit, first mismatch offset 3.
// 4: Tried /Ob0: no codegen change; removed flag.
// 5: Tried /O1: too-small 449-byte text; removed flag.
// 6: Tried /Od: broad 92.66% mismatch from first byte; removed flag.
// 7: Hoisted score local declaration to function scope: worsened first mismatch; rolled back.
// 8: Reordered bestUnit/bestScore/i locals and probed result-initialized-to-minus-one form: best current is 1.51% positional/edit, first mismatch offset 10 from swapped `xor edi` / `or ebp,-1` and local home order.
// BLOCKER: behavior and main body are close, but prologue/control topology differs. Original delays `push ebx` until after the empty-array check and uses the pre-EBX local slots (`result=-1`, `i=0`, saved this) exactly; current VC5 saves EBX immediately because the inlined array-growth blocks use EBX, causing stack-offset drift from offset 3 despite matching most loop bodies.
// 4: Initialize selected unit to -1 and return it directly: improved to 1.08%; remaining store order and score-conversion jump.
// 5: Reorder locals and make weaponRange return float with named fscore worsened (extra stack/FPU drift); keep float return but use direct conditional conversion.
// 6: Restore exact local order/value: bestScore=-1, bestUnit=-1, i=0; direct return bestUnit. Validates exact before promotion.

extern void* operator new(unsigned int);
extern void operator delete(void*);
extern "C" int __cdecl _ftol();

struct ManagedArray_int { int* value; int numberValue; int desiredNumberValue; int maximumSizeValue; };

class MasterObject { public: char pad_00[0x10]; short type; };
#ifndef TAITACMD_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
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
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange();
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier();
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(int);
    virtual float weaponRange();
    char pad_04[4];
    MasterObject* master_obj;
    char pad_0c[0x24];
    float field_30;
};
#endif
class MainDecisionAIModule { public: RGE_Static_Object* object(int id); };
class TribeTacticalAIModule {
public:
    char pad_000[0x0f0]; MainDecisionAIModule* md; char pad_0f4[0x2c0-0x0f4]; int mode;
    int selectBestCommander(ManagedArray_int* a);
};

int TribeTacticalAIModule::selectBestCommander(ManagedArray_int* a)
{
    int bestScore = -1;
    int bestUnit = -1;
    int i = 0;
    if (a->numberValue > 0) {
    do {
        if (i > a->maximumSizeValue - 1) {
            int newMax = i + 1;
            int* n = (int*)operator new(newMax * 4);
            if (n) {
                int j = 0;
                while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; }
                operator delete(a->value); a->value = n; a->maximumSizeValue = newMax;
            }
        }
        int id = a->value[i];
        RGE_Static_Object* obj = this->md->object(id);
        if (obj != 0) {
            if (obj->master_obj->type != 0x7d) {
                int score;
                if (this->mode == 2) {
                    score = (int)obj->weaponRange();
                } else {
                    score = (int)obj->field_30;
                }
                if (this->mode == 1 || this->mode == 3) {
                    if (bestScore == -1 || score < bestScore) {
                        if (i > a->maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; } operator delete(a->value); a->value = n; a->maximumSizeValue = newMax; }
                        }
                        bestUnit = a->value[i];
                        bestScore = score;
                    }
                } else {
                    if (bestScore == -1 || score > bestScore) {
                        if (i > a->maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; } operator delete(a->value); a->value = n; a->maximumSizeValue = newMax; }
                        }
                        bestUnit = a->value[i];
                        bestScore = score;
                    }
                }
            }
        }
        ++i;
    } while (i < a->numberValue);
    }
    return bestUnit;
}
#else
int TribeTacticalAIModule::selectBestCommander(ManagedArray<int>&) { return 0; }
#endif
