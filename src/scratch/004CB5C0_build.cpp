// VA: 004CB5C0 TRIBE_Combat_Object::build(int, int)
// PDB source: t_c_obj.cpp lines 1053-1105
// EH-framed (SEH), needs /GX. Canonical ownership: owner/world at +0x0C/+0x3C,
// actions at +0x184, and the 0x40-byte TRIBE_Action_Build allocation.
// Attempt log:
// - baseline: fixed the repeated action-list calls and +0x208/+0x210 slots;
//   call count became exact but the early-return CFG was broad-drift.
// - positive target guard plus typed target-result reuse restored exact size,
//   one-return CFG, all 16 ordered calls, and 97.27% instruction shape.
// - fresh pass: same-TU trade labels added 19 bytes and duplicated the
//   epilogue; direct returns added 60 bytes. Both were rolled back.
// - exact tact_bld.cpp constructor parameter types and result declaration
//   order did not change emitted code. Integer result type was also neutral.
// - restored the typed top-declared action with natural success/failure labels;
//   diff improved to 100 bytes, but size grew by 19 and VC5 cloned the exit.
// - reordering the natural locals was a codegen duplicate; restored the clean
//   typed result reconstruction before validation.
// - one typed result pointer coalesced the target and constructor result and
//   reached a 49-byte diagnostic diff, but it returned the old target when
//   vf210 returned null; it was not kept.
// - restored separate target/result ownership and explicit task propagation;
//   output returned to the clean 255-byte basin with correct null behavior.
// - direct success/failure labels reproduced the sibling trade shape but grew
//   19 bytes and duplicated the cleanup; rolled back.
// - current focused reconstruction coalesces the target and action result,
//   but assigns the null task result before the common epilogue; this keeps
//   all null returns correct and reaches a 77-byte diagnostic diff.
// - base versus derived action pointer and typed RGE_Task vf210 return were
//   codegen duplicates; kept the period-plausible derived action surface.
// - fresh pass: trade-shaped success/failure labels grew to 374 bytes;
//   nested direct returns grew to 396 bytes; both were rolled back.
// - separate target/status locals produced 421 bytes.  A separate target and
//   result pointer reached 331 bytes and 49 differing bytes only by returning
//   the target on a null task.  Removing the task-null assignment was rolled
//   back because it changes the proven null result.  Integer status locals
//   were codegen-neutral when the target/result reuse stayed intact.
// - fresh pass: direct task-null return grew to 350 bytes/122 diff; direct
//   action-null return grew to 359 bytes/160 diff. Initialized integer status,
//   delayed status initialization, and zero-before-task forms stayed above
//   288 bytes of diff. Direct typed task-to-result reuse was 331 bytes/255 diff.
// - remaining drift is the paired VC5 result-register basin and isolated
//   EH-handler address; no compiler-only aliases or volatility retained.
// FLAGS: config/flags/004CB5C0_build.rsp (/GX)

class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Game_World;
class RGE_Player;
class RGE_Task;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    void* master_obj;
    RGE_Player* owner;
    char pad_10[0x28];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x38];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    RGE_Static_Object* object(int id);
};

// RGE_Action with virtuals at the right vtable offsets
// vt[6]=vf18(type), vt[13]=vf34(work), vt[19]=vf4C(get_target_obj)
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(void*);
    virtual int vf08(int, void*);
    virtual void* vf0C(void*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();                    // vt[6] = 0x18: type()
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);  // vt[13] = 0x34: work()
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C();                    // vt[19] = 0x4C: get_target_obj()
    virtual void* vf50();
    virtual void set_target_obj(void*);
    virtual void vf58(void*);
    virtual void set_state(unsigned char);
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
    void* obj;
    void* list;

    unsigned char have_action();
    RGE_Action* get_action();
    void delete_list();
};

// TRIBE_Action_Build is 0x40 bytes (same as RGE_Action)
struct Action_Build_Pad {
    char data[0x3C];
};

class TRIBE_Action_Build : public RGE_Action {
public:
    Action_Build_Pad padding;
    TRIBE_Action_Build(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

// Stub base: RGE_Static_Object->RGE_Action_Object layout + 130 dummy virtuals
// No explicit vtable ptr (implicit from virtuals)
class RGE_Action_Object_Base {
public:
    int id;                  // +0x04
    void* master_obj;        // +0x08
    RGE_Player* owner;       // +0x0C
    char pad_10[0x28];       // +0x10 to +0x37
    float world_x;           // +0x38
    float world_y;           // +0x3C
    float world_z;           // +0x40
    char pad_44[0x140];      // +0x44 to +0x183
    RGE_Action_List* actions;// +0x184

    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
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
    virtual void d60(); virtual void d61(); virtual void d62(); virtual void d63();
    virtual void d64(); virtual void d65(); virtual void d66(); virtual void d67();
    virtual void d68(); virtual void d69(); virtual void d70(); virtual void d71();
    virtual void d72(); virtual void d73(); virtual void d74(); virtual void d75();
    virtual void d76(); virtual void d77(); virtual void d78(); virtual void d79();
    virtual void d80(); virtual void d81(); virtual void d82(); virtual void d83();
    virtual void d84(); virtual void d85(); virtual void d86(); virtual void d87();
    virtual void d88(); virtual void d89(); virtual void d90(); virtual void d91();
    virtual void d92(); virtual void d93(); virtual void d94(); virtual void d95();
    virtual void d96(); virtual void d97(); virtual void d98(); virtual void d99();
    virtual void d100(); virtual void d101(); virtual void d102(); virtual void d103();
    virtual void d104(); virtual void d105(); virtual void d106(); virtual void d107();
    virtual void d108(); virtual void d109(); virtual void d110(); virtual void d111();
    virtual void d112(); virtual void d113(); virtual void d114(); virtual void d115();
    virtual void d116(); virtual void d117(); virtual void d118(); virtual void d119();
    virtual void d120(); virtual void d121(); virtual void d122(); virtual void d123();
    virtual void d124(); virtual void d125(); virtual void d126(); virtual void d127();
    virtual void d128();      // vt[128] = offset 0x200
    virtual void d129();      // vt[129] = offset 0x204
};

class TRIBE_Combat_Object : public RGE_Action_Object_Base {
public:
    virtual void vf208(void* action);                      // vt[130] = 0x208: set_only_action
    virtual void d131();                                   // vt[131] = 0x20C
    virtual RGE_Task* vf210(void* obj, float x, float y, float z);  // vt[132] = 0x210: getTask

    int build(int id, int flag);
};

int TRIBE_Combat_Object::build(int id, int flag) {
    RGE_Static_Object* result;
    RGE_Task* task;

    result = this->owner->world->object(id);
    if (result != 0) {
        if (flag == 0) {
            if (this->actions->have_action() == 1) {
                if (this->actions->get_action()->vf4C() == result &&
                    this->actions->get_action()->vf18() == 0x65) {
                    result = (RGE_Static_Object*)1;
                    goto done;
                }
            }
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->vf18() == 0x65) {
                this->actions->get_action()->vf34(result, result->world_x,
                                                  result->world_y, result->world_z);
                result = (RGE_Static_Object*)1;
                goto done;
            }
        }

        task = this->vf210(result, result->world_x, result->world_y, result->world_z);
        if (task == 0) {
            result = (RGE_Static_Object*)task;
            goto done;
        }

        TRIBE_Action_Build* build_action = new TRIBE_Action_Build(
            (RGE_Action_Object*)this, task, result);
        result = (RGE_Static_Object*)build_action;
        if (build_action == 0) goto done;

        this->actions->delete_list();
        this->vf208(build_action);
        result = (RGE_Static_Object*)1;
    }

done:
    return (int)result;
}
