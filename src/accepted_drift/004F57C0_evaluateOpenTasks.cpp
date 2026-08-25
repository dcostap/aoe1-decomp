#ifndef TAITACMD_SHARED_CONTEXT
// 004F57C0 TribeTacticalAIModule::evaluateOpenTasks()
// Source: taitacmd.cpp lines 6042-6189
// Size: 2024 bytes. __thiscall. 62 calls.
//
// Fresh canonical reconstruction.  The ManagedArray indexing below uses the
// same inline utmarray.h operator[] surface as the exact same-TU donors
// 004EA750, 004E3070, 004E3140, and 004F7D90.  Explicit resize() calls are
// retained only at the packet-proven source sites that call 004147A0; the
// parent does not contain compiler-expanded allocation/copy/delete blocks.
//
// Attempt log (luna2-004F57C0):
// - Baseline with the exact donor operator[] surface: 2108B rebuilt, 1967
//   strict diff; recovered the full 62-call family without parent-level grow
//   scaffolding.
// - Corrected the md/player (+0xF0) and informationAI (+0xCEC) ownership,
//   explicit resize/value sites, positive dropsite block order, and combined
//   task-array bounds.  This reduced the rebuilt body to 2052B and 1878B
//   strict diff with 95.99% shape.
// - Scoped the first civilians ManagedArray alias, used the binary-positive
//   x87 gate (`vf61() == 0.0`, double zero), and nested
//   `group(assistGroupID(), -1, -1, -1)` to preserve source call scheduling.
//   Best current: 2043B vs 2024B, 1725B strict diff, 360B edit/resync,
//   97.12% shape, 89.74% exact-block coverage, all 62 calls aligned.
// - Final remaining drift is structural/local-topology: original frame 0x10
//   versus rebuilt 0x8, with the first mismatch at the prologue and one
//   late group-call alignment issue.  No accepted drift or inline asm.
//
// Attempt log (sa-82040434, 2026-08-06):
// - AUDITED the checker's +06F2 "commander vs assistGroupID" direct-target
//   discrepancy: the two call targets are actually in the correct order at
//   every site; the checker's mismatch was an ALIGNMENT ARTIFACT caused by
//   the earlier +0xF drift.  Verified original 004F5EA3=assistGroupID and
//   004F5EB2=commander both match rebuilt call targets 1:1 (62/62).
// - FIXED the group walk: original is a top-tested loop whose back edge
//   (004F5F9A -> 004F5E65) returns to the null test at the top of the body,
//   with `or ebp,-1` in the preheader.  Changed `if {...} do {...} while` to
//   a plain `while (group != &this->groups)` with `int minusOne = -1` first in
//   the body.  This resolved the +06F2 artifact and added 8 exact blocks.
// - FIXED the dropsite-success block (line 6089): original keeps
//   `lea ebp,[esi+0D58h]` (unitsTasked alias) live across the resize call and
//   holds n in ecx across the scan; added `ManagedArray_int* unitsTasked =
//   &this->unitsTaskedThisUpdate;` and read n/cap/value through it.  The
//   whole 6089 block (inline grow + membership scan + resize + append) is now
//   structurally byte-exact.
// - BEST CURRENT: 2014B vs 2024B (-10), 1751B strict diff, 252B edit/resync
//   (12.45%), 98.88% shape, 95.03% exact-block coverage, all 62 calls aligned,
//   0 wrong direct targets.  Second scan + group walk byte-exact.
// - REMAINING STALL: the line-6068 first membership scan.  Original spills the
//   count and capacity to stack homes [esp+1Ch]/[esp+18h] (frame 0x10), then
//   reloads them in the loop (`mov edx,[esp+1Ch]`, `cmp eax,[esp+18h]`); the
//   rebuilt substitutes them back to direct member reads ([esi+0D5Ch]/
//   [esi+0D64h]) and drops the frame to 0x8.  Tried ~12 families: while/for
//   +&&/break, locals vs direct-member vs mixed condition bounds, with/without
//   outer `if (n > 0)` guard, pointer and reference aliases, `register`/
//   `const` locals, n loaded before the resize call, full-class surface,
//   game_globals.h include context, and /O1//O2//Ox flag sets.  VC5
//   canonicalizes ALL of these to the same substitution basin in the
//   standalone scratch TU (verified with micro-repros: micro1..micro10 always
//   keep count/cap in registers or substitute member re-reads under register
//   pressure; no source form produces the stack-home spill).  The spill may
//   require the original full taitacmd.cpp TU context (real utmarray.h
//   template, whole-file register allocation) that the standalone checker
//   build cannot reproduce.  Next lead: build a combined-TU or full-class
//   context that reproduces the original allocator pressure, or accept the
//   +10B local-topology drift after review.
// - Also noted: two SIB base/index term swaps remain in the loop-body address
//   encodings (e.g. original `mov ebx,[ecx+edx]` vs rebuilt `mov ebx,[edx+ecx]`
//   at the second-scan civilianID load) - downstream register-color cascades
//   from the first-scan substitution, expected to resolve if the first scan
//   ever aligns.
// - Main-agent audit replaced synthetic v00/v61/v76/v77 slot scaffolding with
//   the proven canonical RGE_Player/RGE_Static_Object virtual names and modeled
//   TacticalAIGroup as its real 0x330 object with a named +0x1D0 field. Calls,
//   layout, and behavior remain unchanged; one relocation byte aligned better.
//
// ManagedArray recovery pass, 2026-08-19:
// - Exact contains ownership recovers the original 0x10 frame and all four
//   first-scan homes. CodeView lists only i, so the bound homes are compiler
//   state from the inlined method. Exact add also replaces the second manual
//   scan without changing emitted code.
// - The reduced isolated frontier has exact size, 624 instructions, 62 calls,
//   CFG, and block coverage. Six bytes differ in one first-scan comparison.
//   Only the transient EBX and EDX assignments are reversed.
// - Zero through twelve dummy predecessors do not change this result. The
//   exact same-TU playTaskSoldiers predecessor produces positional equality in
//   the context lab. Its declarations alone also produce equality.
// - Do not retain unused context declarations or a namespaced duplicate
//   predecessor. The next supported step needs genuine combined taitacmd.cpp
//   compile context or a natural source form that selects the same registers.
//
// Accepted-drift review, 2026-08-19:
// - All six changed bytes are in the five instructions at +0xB3 through
//   +0xC0. The original uses EBX for the task-array value and EDX for the
//   civilian-array base. The rebuild exchanges these two registers.
// - Both versions load the same pointers, select the same indexed task value,
//   and compare it with the same civilian value. They set identical flags for
//   the branch at +0xC1. Calls, memory writes, predicates, and fault order do
//   not change.
// - On fallthrough, +0xC7 replaces EDX and +0xD0 replaces EBX. On the taken
//   path, the loop tail at +0x2C0 uses neither register. The next iteration
//   replaces EBX at +0x25 and EDX at +0x3C before use.
// - Exact playTaskSoldiers same-TU context emits the original register choice.
//   The isolated source keeps this localized, proved-equivalent VC5 drift.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);


#ifndef TAITACMD_SHARED_CONTEXT
struct RGE_Static_Object;
struct UnitAIModule;
struct RGE_Game_World;
struct RGE_Master_Static_Object;
struct RGE_Player;
struct TDrawArea;
struct RGE_Color_Table;
struct RGE_Sprite;
struct RGE_Armor_Weapon_Info;
struct RGE_Action_Object;
struct LOSTBL;

template <class T>
struct ManagedArray {
    T* value;                // +0x00
    int numberValue;         // +0x04
    int desiredNumberValue;  // +0x08
    int maximumSizeValue;    // +0x0C

    int resize(int newSize);

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator_new(new_size * sizeof(T));
            if (new_data != 0) {
                int i;
                for (i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }

    int contains(const T& item) const;
    int add(T item);
};

template <class T>
int ManagedArray<T>::contains(const T& item) const {
    int index;
    T wanted;
    T current;
    for (index = 0; index < this->numberValue; index++) {
        if (index >= this->maximumSizeValue)
            return 0;
        current = this->value[index];
        wanted = item;
        if (current == wanted)
            return 1;
    }
    return 0;
}

template <class T>
int ManagedArray<T>::add(T item) {
    int index;
    for (index = 0; index < this->numberValue; index++) {
        if (index >= this->maximumSizeValue)
            break;
        if (this->value[index] == item)
            return 0;
    }
    if (this->numberValue > this->maximumSizeValue - 1)
        this->resize(this->numberValue + 1);
    this->value[this->numberValue] = item;
    this->numberValue++;
    return 1;
}

#endif

#ifndef TAITACMD_SHARED_CONTEXT
struct RGE_Game_World {
    RGE_Static_Object* object(int objectID);
};

struct RGE_Player {
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int line);
    virtual int isEnemy(int player);
    virtual int isAlly(int player);
    virtual int isNeutral(int player);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player, int stance);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object* unit, RGE_Static_Object* dropsite,
                               float x, float y); // vtable +0x40
    char gap_04[0x38];                    // +0x04 .. +0x3B
    RGE_Game_World* world;                // +0x3C
};

struct UnitAIModule {
    int currentOrder();
    int currentTarget();
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();              // vtable +0xF4
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove(); // vtable +0x130
    virtual unsigned char actionState();   // vtable +0x134

    char gap_04[0x20];                   // +0x04
    void* objects;                       // +0x24
    char gap_28[0x08];                   // +0x28
    float hp;                            // +0x30
    char gap_34[0x04];                   // +0x34
    float world_x;                       // +0x38
    float world_y;                       // +0x3C
    char gap_40[0x04];                   // +0x40
    float attribute_amount_held;         // +0x44
    unsigned char object_state;          // +0x48

    UnitAIModule* unitAI();
};

struct TribeInformationAIModule {
    RGE_Static_Object* findClosestReturnDropsite(RGE_Static_Object* unit);
};

struct TribeMainDecisionAIModule {
    RGE_Static_Object* object(int objectID);
    char gap_00[0xF0];                   // base AIModule prefix
    RGE_Player* player;                  // +0xF0
    char gap_F4[0xCEC - 0xF4];           // +0xF4 .. +0xCEB
    TribeInformationAIModule informationAI; // +0xCEC
};

struct ObjectList {
    char gap_00[0x08];
    short number_of_objects;             // +0x08
};

struct TacticalAIGroup {
    virtual ~TacticalAIGroup();
    TacticalAIGroup* next;               // +0x04
    TacticalAIGroup* prev;               // +0x08
    char gap_0C[0x1D0 - 0x0C];
    int field_1D0;
    char gap_1D4[0x330 - 0x1D4];

    int type();
    int action();
    int assistGroupID();
    int commander();
    void setAction(int);
    void setTarget(int);
    void setTargetType(int);
    void setTargetLocation(float, float, float);
    void setGatherLocation(float, float, float);
    void setRetreatLocation(float, float, float);
    void setInUse(int);
    void setWaitCode(int);
};

struct TacticalAIModule {
    virtual ~TacticalAIModule();
    char gap_04[0xEC];
};

struct TribeTacticalAIModule : TacticalAIModule {
    TribeMainDecisionAIModule* md;        // +0xF0
    ManagedArray<int> civilians;           // +0xF4
    char gap_104[0x10];                   // +0x104 .. +0x113
    ManagedArray<int> soldiers;            // +0x114
    char gap_124[0x10];                   // +0x124 .. +0x133
    ManagedArray<int> boats;               // +0x134
    char gap_144[0x890];                  // +0x144 .. +0x9D3
    TacticalAIGroup groups;               // +0x9D4
    char gap_D04[0xD58 - 0xD04];          // +0xD04 .. +0xD57
    ManagedArray<int> unitsTaskedThisUpdate; // +0xD58

    void stopUnit(int objectID, int waitCode);
    void removeObject(int objectID);
    TacticalAIGroup* group(int id, int type, int action, int target);

    void evaluateOpenTasks();
};

#endif

void TribeTacticalAIModule::evaluateOpenTasks()
{
    int i;

    i = 0;
    if (this->civilians.numberValue > 0) {
        ManagedArray<int>* civilians = &this->civilians;
        do {
            if (i > civilians->maximumSizeValue - 1) {
                civilians->resize(i + 1);
            }

            RGE_Static_Object* object =
                this->md->player->world->object(civilians->value[i]);
            if (object != 0) {
                UnitAIModule* unitAI = object->unitAI();
                if (unitAI != 0) {
                    if (i > civilians->maximumSizeValue - 1)
                        civilians->resize(i + 1);
                    ManagedArray<int>* unitsTasked =
                        &this->unitsTaskedThisUpdate;
                    if (unitsTasked->contains(civilians->value[i]))
                        goto next_civilian;

                    if (object->getSpeed() == 0.0 &&
                        object->attribute_amount_held > 0.0f &&
                        object->waitingToMove() == 0 && object->actionState() <= 2) {
                        RGE_Static_Object* dropsite =
                            this->md->informationAI.findClosestReturnDropsite(object);
                        if (dropsite != 0) {
                            this->md->player->sendGameOrder(object, dropsite,
                                                            dropsite->world_x,
                                                            dropsite->world_y);

                            int civilianID = (*civilians)[i];
                            ManagedArray<int>* unitsTasked = &this->unitsTaskedThisUpdate;
                            unitsTasked->add(civilianID);
                        } else {
                            this->stopUnit((*civilians)[i], 100);
                        }
                    } else {
                        if (object->unitAI()->currentOrder() == 700) {
                            int target = object->unitAI()->currentTarget();
                            RGE_Static_Object* targetObject =
                                this->md->object(target);
                            if (targetObject == 0 ||
                                targetObject->object_state > 2) {
                                if (i > civilians->maximumSizeValue - 1) {
                                    civilians->resize(i + 1);
                                }
                                this->stopUnit(civilians->value[i], 100);
                            }
                        }
                    }
                }
            }
        next_civilian:
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->civilians[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->civilians[i]);
            }
            i++;
        } while (i < this->civilians.numberValue);
    }

    i = 0;
    if (this->soldiers.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->soldiers[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->soldiers[i]);
            }
            i++;
        } while (i < this->soldiers.numberValue);
    }

    i = 0;
    if (this->boats.numberValue > 0) {
        do {
            RGE_Static_Object* object =
                this->md->player->world->object(this->boats[i]);
            if (object == 0 || object->hp < 1.0f || object->unitAI() == 0) {
                this->removeObject(this->boats[i]);
            }
            i++;
        } while (i < this->boats.numberValue);
    }

    TacticalAIGroup* group = this->groups.next;
    while (group != &this->groups) {
        int minusOne = -1;
        if (group == 0) {
            return;
        }

            if (group->type() == 0x6A && group->action() == 0xC) {
                TacticalAIGroup* assistGroup =
                    this->group(group->assistGroupID(), minusOne, minusOne,
                                minusOne);
                int currentAssistGroupID = group->assistGroupID();

                if (currentAssistGroupID == -1 || assistGroup == 0) {
                    group->setAction(1);
                    group->setTarget(minusOne);
                    group->setTargetType(minusOne);
                    group->setTargetLocation(-1.0f, -1.0f, -1.0f);
                    group->setGatherLocation(-1.0f, -1.0f, -1.0f);
                    group->setRetreatLocation(-1.0f, -1.0f, -1.0f);
                    group->setInUse(0);
                    group->setWaitCode(minusOne);
                    group->field_1D0 = minusOne;
                } else {
                    int commander = group->commander();
                    RGE_Static_Object* object = this->md->object(commander);
                    if (object != 0 && object->actionState() == 2 &&
                        assistGroup->action() == 0x10) {
                        int assistCommander = assistGroup->commander();
                        RGE_Static_Object* assistObject =
                            this->md->object(assistCommander);
                        if (assistObject != 0 &&
                            ((ObjectList*)assistObject->objects)->number_of_objects > 0) {
                            assistGroup->setAction(0xF);
                        }
                    }
                }
            }

            group = group->next;
    }
}
#else
void TribeTacticalAIModule::evaluateOpenTasks() {}
#endif
