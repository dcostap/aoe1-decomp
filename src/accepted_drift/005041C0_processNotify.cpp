// VA: 005041C0, TribeElephantUnitAIModule::processNotify, 261 bytes
// Source: taiuaimd.cpp lines 274-317
// ACCEPTED_DRIFT: register allocation (ebp/ecx swap for caller/count) and copy loop
// pattern differ slightly. All behavior identical.
//
// Remaining drift:
// 1. Register swap: original keeps caller in ebp, count in ecx. My compiler
//    reverses this (caller in ecx saved to stack, count in ebp). This adds 4 bytes
//    for the stack save (`mov [esp+18h], ecx`).
// 2. Copy/reallocation loop uses different register allocation and slightly
//    different instruction scheduling (same structure, different registers).
// 3. The original uses `jg short` for p2 check (body=jump target, purge=fallthrough);
//    this layout is achieved with `if (event->p2 <= 0)` in the switch.
//
// What matches (first 90 bytes): prologue, switch dispatch (sub/je chain), default
// parent call, return-2 path, p2 check (jg short), purge/return-4 path.
// Also matches: search loop structure (scaled-index access, capacity reload per
// iteration), store-to-array, virtual call sequence, and epilogues.
//
// Attempt log:
// - v1: if-else chaining → cmp not sub for dispatch, wrong NotifyEvent layout
// - v2: switch dispatch, fixed NotifyEvent layout (p2 at +0x10), loop structure off
// - v3: switch → sub pattern works (63 bytes match), p2 check wrong branch layout
// - v4: attempted raw-offset hacks (failed)
// - v5-v6: refined loop structure
// - v7: raw-offset access forced correct scaled-index loop, register allocation off
// - v8: declaration order didn't help register allocation
// - v9: goto-based layout attempt
// - v10: if(p2<=0) fixes branch layout (90 bytes match), register allocation persists
// FLAGS: /nologo /c /O2 /Oy

#ifndef TAIUAIMD_COMPLETE_TU
typedef unsigned char uchar;

class RGE_Player;
class RGE_Master_Static_Object;

struct NotifyEvent {
    int caller;
    int field_04;
    int mType;
    int field_0C;
    int p2;
};

void* operator_new(unsigned int size);
void operator_delete(void* ptr);

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
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void save(int); virtual void load(int); virtual RGE_Player* owner();
    virtual int order(int, int, int, int, float, float, float, float, int, int, int);
    virtual int notify(int, int, int, long, long, long);
    virtual int notifyCommander(int, int, int, long, long, long);
    virtual int notifyCommander(void*); virtual void search();
    virtual int importantWhenDead(int); virtual int retryableOrder(int);
    virtual int actionRequiresLiveTarget(int);
    virtual int bestUnitToAttack(int, int, float*);
    virtual int mostDangerousEnemy(float*); virtual int weakestEnemy(float*);
    virtual int closestAttacker(float* arg);  // vt[15]: +0x3C
    virtual int closestObject(int, int, int, int, int*);
    virtual int closestResourceObject(int, int*);
    virtual int closestUndiscoveredTile(int*, int*, int);
    virtual void logDebug(char*); virtual int canAttackUnit(RGE_Static_Object*);
    virtual int canAttackUnitAtNeutrality(int); virtual int stopObject(int);
    virtual int attackObject(int arg1, int arg2);  // vt[23]: +0x5C

    RGE_Static_Object* objectValue;  // +0x04

    int processNotify(NotifyEvent* event, unsigned long param_2);
    void purgeNotifyQueue(unsigned long param_2);
};

class TribeElephantUnitAIModule : public UnitAIModule {
public:
    char gap_08[0x58];      // +0x08 to +0x5F
    int* notifyArray;       // +0x60
    int notifyCount;        // +0x64
    int gap_68;             // +0x68
    int notifyCapacity;     // +0x6C

    int processNotify(NotifyEvent* event, unsigned long param_2);
};
#endif

int TribeElephantUnitAIModule::processNotify(NotifyEvent* event, unsigned long param_2)
{
    switch (event->mType) {
    case 500:
        if (event->p2 <= 0) {
            this->purgeNotifyQueue(param_2);
            return 4;
        }
        {
            int caller = event->caller;
            int count = this->notifyCount;
            int i = 0;
            if (count > 0) {
                goto loop_check;
                do {
                    if (i >= this->notifyCapacity)
                        goto after_loop;
                    if (this->notifyArray[i] == caller)
                        goto found;
                    i++;
loop_check:;
                } while (i < count);
after_loop:;
            }

            if (count >= this->notifyCapacity) {
                int newCapacity = count + 1;
                int* newArray = (int*)operator_new(newCapacity * 4);
                if (newArray != 0) {
                    int j = 0;
                    if (count > 0) {
                        while (j < newCapacity && j < count) {
                            newArray[j] = this->notifyArray[j];
                            j++;
                        }
                    }
                    operator_delete(this->notifyArray);
                    this->notifyArray = newArray;
                    this->notifyCapacity = newCapacity;
                }
            }
            this->notifyArray[this->notifyCount] = caller;
            this->notifyCount++;
found:
            this->objectValue->setUnderAttack(1);
            int val = this->closestAttacker(0);
            this->attackObject(val, 0);
            return 3;
        }

    case 0x20F:
        return 2;

    default:
        return UnitAIModule::processNotify(event, param_2);
    }
}
