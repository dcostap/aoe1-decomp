// VA: 005048D0 TribeRangedUnitAIModule2::processNotify
// Attempt log:
// 1: direct reconstruction from packet/decompiler, local offset stubs.
// 2: restored the period object and module call surfaces at the observed slots.
// 3: converted failure cases to shared fail return, but VC5 still allocates a 0x0C frame instead of original 0x08 and loop topology is broad mismatch.
// 4: tried defensive null/sentinel branches only as a diagnostic to force compare size; produced 643B but broad 92% mismatch from offset 0, rolled back because it was behavior-altering and not a valid source model.
// 5-8: combined guard, object id, same-TU UnitAIModule ABI, float coordinate fields, and natural new[]/delete[] growth restored exact call order and frame size.
// 9: outer count guard plus while (i < count) reproduced the duplicated entry test and improved shape to 90.95%; the remaining gap is register coloring and late vptr spill.
// 10: a base-pointer alias was codegen-identical and was removed as unsupported steering.
// 11: rewrote the typed evasive result tail as coordinate plus explicit negated displacement; restored the original fchs/fadd tail family, reducing the size gap to 4 bytes and positional diff to 521; first order-call hunk remains.
// 12: removed the saved object alias and used direct this->obj member calls; this restored the original vptr reload and exact 643-byte output.
// exact: direct member accesses preserve the original object/vptr reload schedule and produce all 643 bytes.

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
#ifdef TAIUAIMD_COMPLETE_TU
extern float DAT_005758b0;
extern float DAT_005758c4;
#else
extern const float DAT_005758b0;
extern const float DAT_005758c4;
#endif
extern "C" double __cdecl sqrt(double);

#ifndef TAIUAIMD_COMPLETE_TU
struct NotifyEvent { char pad[8]; int type; };
class RGE_Player;
class RGE_Master_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    RGE_Static_Object* object(int);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(); virtual void recycle_out_of_game();
    virtual void draw(); virtual void shadow_draw(); virtual void normal_draw();
    virtual void draw_front_frame(); virtual void draw_back_frame(); virtual void draw_frame();
    virtual unsigned char update(); virtual void check_damage_sprites(); virtual void rehook();
    virtual void save(int); virtual float teleport(float, float, float);
    virtual void new_sprite(); virtual void add_overlay_sprite(); virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*); virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char); virtual void modify_percent(float, unsigned char);
    virtual void transform(); virtual void copy_obj(); virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource(); virtual void create_doppleganger_when_dying();
    virtual void destroy_obj(); virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long); virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int); virtual unsigned char heal(float); virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float); virtual void stop();
    virtual void set_attack(RGE_Static_Object*); virtual void play_command_sound();
    virtual void play_move_sound(); virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(void*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving(); virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*); virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual void* get_los_table(); virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack(); virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed(); virtual float getAngle(); virtual float maximumSpeed();
    virtual float rateOfFire();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int);
    virtual void load(int);
    virtual void owner();
    virtual int order(int,int,int,int,float,float,float,float,int,int,int);
    virtual void notify(int,int,int,long,long,long);
    virtual void notifyCommander(int,int,int,long,long,long);
    virtual void notifyCommander(void*);
    virtual void search();
    virtual int importantWhenDead(int);
    virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int,int,float*);
    virtual int mostDangerousEnemy(float*);
    virtual int weakestEnemy(float*);
    virtual int closestAttacker(float*);
    virtual int closestObject(int,int,int,int,int*);
    virtual int closestResourceObject(int,int*);
    virtual int closestUndiscoveredTile(int*,int*,int);
    virtual void logDebug(char*);
    virtual int canAttackUnit(void*);
    virtual int canAttackUnitAtNeutrality(int);
    virtual int stopObject(int);
    virtual int attackObject(int,int);
    virtual int attackRoundupObject(int);
    virtual int huntObject(int,int);
    virtual int gatherObject(int,int);
    virtual int convertObject(int,int);
    virtual int healObject(int,int);
    virtual int repairObject(int,int);
    virtual int buildObject(int,int);
    virtual int tradeWithObject(int,int);
    virtual int explore(int,int,int);
    virtual int enterObject(int,int);
    virtual int unload(int,float,float);
    virtual int transportObject(float,float,float,int);
    virtual int moveTo(float,float,float,float,int);
    virtual int moveTo(int,float,int);
    virtual int moveTo(int,int);
    virtual int evasiveMoveTo(float,float,float,int);
    virtual int runAwayFromAttackers(int);
    virtual int followObject(int,float,int);
    virtual int defendObject(int,float,int);
    virtual int defendPosition(float,float,float,int);
    virtual int seekAndDestroy(int,int,int,int);
    virtual int exploreAndDestroy(int,int,int);
    virtual int importantObject(int);
    virtual int convertToLOSResourceType(int);
    virtual int canConvert(int);
    virtual int processOrder(void*,int);
    int processNotify(NotifyEvent*,unsigned long);

    RGE_Static_Object* obj;
    char gap08[0x24];
    int p2c;
    int state;
    int target_id;
    char gap38[4];
    float p3c, p40, p44, p48;
    char gap4c[0x14];
    int* ids;
    int count;
    char gap68[4];
    int capacity;
};

class TribeRangedUnitAIModule2 : public UnitAIModule {
public:
    int processNotify(NotifyEvent*, unsigned long);
};
#endif

int TribeRangedUnitAIModule2::processNotify(NotifyEvent* ev, unsigned long flags)
{
    RGE_Static_Object* target;
    float evasiveMoveDistance;
    float dx;
    float dy;
    float len;
#ifdef TAIUAIMD_COMPLETE_TU
    if (*(int*)((char*)ev + 8) != 0x200) {
#else
    if (ev->type != 0x200) {
#endif
#ifdef TAIUAIMD_COMPLETE_TU
        return this->baseProcessNotify(ev, flags);
#else
        return ((UnitAIModule*)this)->processNotify(ev, flags);
#endif
    }
    target = 0;
    if (this->state != 0x258 ||
        (target = this->obj->owner->world->object(this->target_id)) == 0 ||
#ifdef TAIUAIMD_COMPLETE_TU
        target->getSpeed() == DAT_005758c4)
#else
        target->getSpeed() == DAT_005758c4)
#endif
        return 2;

    this->order(this->obj->id, 0x2bc, this->target_id, -1, this->p3c, this->p40, this->p44, this->p48, 0, 1, this->p2c);

#ifdef TAIUAIMD_COMPLETE_TU
    evasiveMoveDistance = this->obj->maximumSpeed() *
                          this->obj->rateOfFire() * DAT_005758b0;
    dx = target->world_x - this->obj->world_x;
    dy = target->world_y - this->obj->world_y;
#else
    evasiveMoveDistance = this->obj->maximumSpeed() * this->obj->rateOfFire() * DAT_005758b0;
    dx = target->world_x - this->obj->world_x;
    dy = target->world_y - this->obj->world_y;
#endif

    if (this->count > 0) {
        int i = 0;
        while (i < this->count) {
                if (i > this->capacity - 1) {
                    int newCount = i + 1;
                    int* n = new int[newCount];
                    if (n) {
                        int j = 0;
                        if (this->capacity > 0) {
                            do {
                                if (j < newCount) {
                                    ++j;
                                    n[j-1] = this->ids[j-1];
                                } else {
                                    break;
                                }
                            } while (j < this->capacity);
                        }
                        delete[] this->ids;
                        this->ids = n;
                        this->capacity = newCount;
                    }
                }
                if (this->ids[i] != this->target_id) {
                    if (i > this->capacity - 1) {
                        int newCount = i + 1;
                        int* n = new int[newCount];
                        if (n) {
                            int j = 0;
                            if (this->capacity > 0) {
                                do {
                                    if (j < newCount) {
                                        ++j;
                                        n[j-1] = this->ids[j-1];
                                    } else {
                                        break;
                                    }
                                } while (j < this->capacity);
                            }
                            delete[] this->ids;
                            this->ids = n;
                            this->capacity = newCount;
                        }
                    }
                    RGE_Static_Object* obj2 = this->obj->owner->world->object(this->ids[i]);
                    if (obj2) {
                        dx += obj2->world_x - this->obj->world_x;
                        dy += obj2->world_y - this->obj->world_y;
                    }
                }
            ++i;
        }
    }

    len = (float)sqrt(dx*dx + dy*dy);
    this->evasiveMoveTo(this->obj->world_x + (-(dx / len * evasiveMoveDistance)),
                        this->obj->world_y + (-(dy / len * evasiveMoveDistance)),
                        this->obj->world_z, 1);
    return 3;
}
