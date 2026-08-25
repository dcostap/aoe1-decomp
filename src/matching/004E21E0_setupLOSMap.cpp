// 004E21E0 TribeInformationAIModule::setupLOSMap
// taiinfmd.cpp:7032-7076
// Status: scratch / not exact.
// Attempt log:
// - Natural implementation with losMap.initialize/setReferencePoint, importantObjectMemory scan, md->object lookup, ftol radius/x/y, vf[0x108] float test, incrementValue, maxValue gets exact size (269) and 13.01% positional / 14.87% edit diff.
// - Prologue, losMap setup, loop frame, null-object path, final loop increment, and maxValue tail are largely aligned.
// - First persistent drift is loop entry register allocation/order: original loads importantObjectMemory into EDX, offset into EAX, then owner param into EDX and zero-extends owner byte into ECX; rebuilt uses EAX for base and EDX for offset/byte. Tried separate mem local, char* field, and compare operand swap; compare swap improved one byte but allocation remained.
// - Tried reordering radius/x/y integer calculations to match original `fld y; mov ebx,eax; lea ecx,[edi+eax]; sub ebx,edi; store maxX; ftol`; source variants either kept current call-before-integer scheduling or caused a larger shifted diff.
// - Tried explicit UnitTypeInfo temp/yfloat temp; worsened to ~47% positional by shortening the middle block.
// - Promoted ObjectMemory and RGE master/object layouts from the local gaps; bytes were unchanged.
// - Reordered bound declarations, raw id/owner record access, split base/record setup, and a focused
//   36-variant lab over record/master/bounds/virtual spellings; no emitted group reached the original.
// - Final clean source keeps the canonical typed ObjectMemory stride and natural bound locals; remaining
//   drift is VC5 register allocation/FPU scheduling at loop entry and the three bound conversions.
// - Remaining blocker: VC5 register allocation and scheduling in the object-memory entry check plus FPU/int interleaving before incrementValue.
// - Main-agent audit restored canonical InfluenceMap/master/object/AI destructor
//   surfaces; the validated 39-byte codegen gap is unchanged.
// - ABI probe: changed losMap from a pointer global to the binary-backed
//   InfluenceMap object and used direct member calls; emitted code stayed at
//   269 bytes with the same 39-byte mismatch, so the ABI lead is confirmed but
//   does not resolve the remaining register/FPU drift.
// - Direct typed importantObjectMemory[i] owner/id access with the owner byte
//   on the left corrected the loop-entry register allocation and reduced the
//   mismatch from 39 to 25 bytes.  This keeps canonical ObjectMemory ownership.
// - Reversing that typed comparison fixed the remaining compare byte; a local
//   record pointer after the check emitted the same code.
// - X-bound-before-y, early objY declaration, bound declaration reordering,
//   and incrementValue argument-order declarations regressed to 122-185 bytes;
//   these diagnostics were restored.  A natural ternary flag and maxX term
//   reversal were codegen duplicates.
// - Session probe: retaining only the binary-indicated maxX local and inlining
//   the other bounds removed the proven 8-byte frame and regressed to 258 diff;
//   restored the natural bound-local source.
// - A fixed-address/stride-cursor diagnostic reached a 39-byte drift, but it
//   was restored because raw global addresses and byte-indexed records are not
//   canonical living source. The typed global and indexed ObjectMemory array
//   remain authoritative.
// - This worker reconfirmed the clean 269-byte source under default flags:
//   25 positional bytes remain, with all calls, frame facts, and CFG signals
//   aligned. The first hunk is the y-bound conversion schedule at +0x8B.
// - A period-supported <math.h> include was codegen-neutral. Direct repeated
//   x casts and multi-declarator bound forms regressed to 123-128 bytes.
// - A natural split with maxX assigned before objY and minX after objY reached
//   20 bytes, but it moved minX and the y conversion after the virtual setup;
//   it was restored because the clean source remains authoritative.
// - The maxX-only/direct-argument form removed the proven frame and regressed
//   to 258 bytes. No natural probe reached MATCH; clean source is restored.
// - Current lease baseline reconfirmed the clean 269-byte basin. The remaining
//   25 bytes are localized FPU/int bound-scheduling drift after y conversion;
//   prior natural bound-order probes regressed structurally.
// - Follow-up probes reconfirmed that maxX-only/direct y-bound expressions
//   reproduce the 258-byte structural regression. Full named bounds with
//   maxX-before-y reach 20 bytes but retain a register-map conflict. Splitting
//   maxX declaration and assignment is codegen-neutral at 25 bytes.
// - Final unchanged validation remains a 269-byte MISMATCH with 25 differing
//   bytes, 9 aligned calls, an 0x8 frame, and first mismatch at +0x8B.
//   The pinned typed source is restored; no policy-valid natural MATCH exists.
// - Revisit pass: twenty meaningful source, type, scope, and context probes
//   did not reach an exact result. The best natural maxX-before-y source still
//   has a register-map mismatch and does not preserve the clean source model.
// - Binary span audit: at +0x8B the original computes maxX and minX after
//   loading y but before its third __ftol call, then spills maxX. The clean
//   source completes that call first and spills minX. At +0xAB the original
//   compares against absolute DAT_00575580; a local 0.0f or extern spelling
//   did not produce a policy-valid matching relocation. At +0xC6 the changed
//   bound homes alter the push encodings for incrementValue arguments.
// - Function-scope maxX, direct member repeats, declaration grouping, typed
//   width/signedness changes, stdlib context, and a 256-variant ambient-TU
//   lab either duplicated the clean basin or changed structure. All probes
//   were restored. Final validation remains 269 bytes with 25 differing
//   bytes, 9 aligned calls, and first mismatch +0x8B.
// - Exact revisit: same-TU AI donor style uses direct typed coordinate casts
//   in bound expressions. The natural order minX, maxX, minY, maxY produced
//   the original LEA/spill and all 269 bytes matched.
// - Exact-finish walkback: naming objX in both x bounds changed the schedule;
//   naming only objX for minX or maxX, and naming objY, stayed exact in the
//   tested order. The clearest direct-expression form is retained.
// - Policy cleanup: replaced generic virtual names with the donor-backed
//   RGE_Static_Object and module inheritance surfaces. The +0x108 call is the
//   canonical no-argument damageCapability() getter. The named surface stayed
//   exact after adding the canonical AIModule module layouts.
// - Cross-reference evidence: stat_obj.h lines 224-225 define the no-argument
//   and object-argument damageCapability overloads. The class dump assigns the
//   no-argument getter to vt[66] at +0x108. The shipped getter returns float.
// - BINARY NOTE: the period header places the no-argument overload before the
//   object-argument overload (stat_obj.h lines 224-225); this declaration order
//   preserves the required +0x108 dispatch without a compiler wrapper.
// - The RGE_Animated_Object declaration is retained for the proven override
//   owner at 00405D50/00405D60. Removing it is codegen-neutral but loses ABI
//   ownership context.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
typedef unsigned char uchar;

#endif
class RGE_Game_World;
class RGE_Sprite;
class RGE_Action_Object;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Tile;
class RGE_Player;
class RGE_Color_Table;
class TDrawArea;
class RGE_Armor_Weapon_Info;
class LOSTBL;
class RGE_Master_Combat_Object;
class RGE_Static_Object;
class UnitAIModule;
class AIModuleMessage;
struct _iobuf;

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class InfluenceMap {
public:
    virtual ~InfluenceMap();
    int initialize(uchar param);
    void setReferencePoint(int x, int y);
    int incrementValue(int min_x, int min_y, int max_x, int max_y, int flag);
    int maxValue(void);
};

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar, uchar,
                                  uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*, long, long,
                      int, uchar);
    char gap_04[0x24];
    float los;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, uchar);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual uchar can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, uchar, uchar);
    virtual int heal(int, int);
    virtual uchar heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, uchar);
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
    virtual void set_being_worked_on(RGE_Action_Object*, short, uchar);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual uchar is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, uchar, int);
    virtual void unexplore_terrain(RGE_Player*, uchar, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual uchar underAttack();
    virtual void setUnderAttack(uchar);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);

    long id;                              // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                    // +0x0C
    RGE_Sprite* sprite;                    // +0x10
    RGE_Sprite* old_sprite;                // +0x14
    RGE_Object_List* sprite_list;          // +0x18
    RGE_Tile* tile;                        // +0x1C
    RGE_Static_Object* inside_obj;         // +0x20
    RGE_Object_List* objects;               // +0x24
    short screen_x_offset;                 // +0x28
    short screen_y_offset;                 // +0x2A
    short shadow_x_offset;                 // +0x2C
    short shadow_y_offset;                 // +0x2E
    float hp;                              // +0x30
    uchar curr_damage_percent;             // +0x34
    uchar facet;                           // +0x35
    uchar selected;                        // +0x36
    uchar selected_group;                  // +0x37
    float world_x;                        // +0x38
    float world_y;                        // +0x3C
    float world_z;                        // +0x40
    float attribute_amount_held;           // +0x44
    uchar object_state;                    // +0x48
    uchar sleep_flag;                      // +0x49
    uchar dopple_flag;                     // +0x4A
    uchar goto_sleep_flag;                 // +0x4B
    short attribute_type_held;             // +0x4C
    uchar type;                             // +0x4E
    uchar worker_num;                      // +0x4F
    RGE_Object_Node* player_object_node;    // +0x50
    ManagedArray<int> pathingGroupMembers;  // +0x54
    ManagedArray<int> groupMembers;         // +0x64
    UnitAIModule* unitAIValue;              // +0x74
    int groupCommanderValue;                // +0x78
    int zoneMapIndex;                       // +0x7C
    float groupRangeValue;                  // +0x80
    uchar inObstructionMapValue;            // +0x84
    uchar lastInObstructionMapValue;       // +0x85
    uchar underAttackValue;                 // +0x86
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);
    float speed;                            // +0x88
};

class AIModuleID {
public:
    virtual ~AIModuleID();
    int id;
    char name[0x40];
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
    _iobuf* historyLogFile;
    char historyLogFilename[0x40];
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};

class InformationAIModule : public AIModule {
public:
    virtual ~InformationAIModule();
};

class MainDecisionAIModule : public AIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Player* player; // +0xF0
    ManagedArray<int> objects; // +0xF4
    virtual int save(int);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);
    virtual int objectGroupThatCanPerformAction(int);
    virtual int canPerformAction(int, int);
    RGE_Static_Object* object(int id);
};

struct ObjectMemory {
    int id;                 // +0
    short type;              // +0x04
    short group;             // +0x06
    unsigned char x;         // +0x08
    unsigned char y;         // +0x09
    unsigned char z;         // +0x0A
    uchar owner;            // +0x0B
    short hitPoints;        // +0x0C
    char gap_0E[2];
    int attackAttempts;     // +0x10
    uchar kills;             // +0x14
    char gap_15[3];
    float damageCapability; // +0x18
    float rateOfFire;       // +0x1C
    float range;            // +0x20
};

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule : public InformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    char gap_F0[0x100 - 0xF0];
    MainDecisionAIModule* md;                 // +0x100
    char gap_104[0x110 - 0x104];
    int maxImportantObjectMemory;             // +0x110
    ObjectMemory* importantObjectMemory;      // +0x114

    int setupLOSMap(int owner, int refX, int refY);
};
#endif

#endif
int TribeInformationAIModule::setupLOSMap(int owner, int refX, int refY)
{
    losMap->initialize(0);
    losMap->setReferencePoint(refX, refY);

    int i = 0;
    if (this->maxImportantObjectMemory > 0) {
        do {
            if ((unsigned int)this->importantObjectMemory[i].owner ==
                (unsigned int)owner) {
                RGE_Static_Object* obj = this->md->object(
                    this->importantObjectMemory[i].id);
                if (obj != 0) {
                    int range = (int)obj->master_obj->los;
                    int minX = (int)obj->world_x - range;
                    int maxX = range + (int)obj->world_x;
                    int minY = (int)obj->world_y - range;
                    int maxY = range + (int)obj->world_y;
                    int flag;
                    if (obj->damageCapability() > 0.0f) {
                        flag = 5;
                    } else {
                        flag = 1;
                    }
                    losMap->incrementValue(minX, minY, maxX, maxY, flag);
                }
            }
            i++;
        } while (i < this->maxImportantObjectMemory);
    }
    return losMap->maxValue();
}
