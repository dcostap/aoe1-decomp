// VA: 004CB450 TRIBE_Combat_Object::repair(int, int)
// PDB source: t_c_obj.cpp lines 991-1047
// attempt 1: mirrored nearby build/heal action replacement shape with repair action id 0x6A and TRIBE_Action_Repair size 0x44; /GX for original EH frame.
// attempt 2: route returns through shared done labels and avoid cached action locals; use have_action()==1 to recover cmp al,1.
// attempt 3: positive outer object guard to avoid VC5 inlining the null-object SEH epilogue.
// attempt 4: route all success paths through a shared success label to prevent inlined SEH success returns.
// attempt 5: positive object guard plus a single result variable/common done label; VC5 still cloned success returns and broadened diff.
// attempt 6: initializing result=0 created a stack local and wrong prologue; rolled back.
// attempt 7: leaving failure value in EAX did not prevent cloned success epilogues.
// attempt 8: paired hunt/heal/build typed-result-through-done form reached exact size/one-return CFG, but kept the result in EBX and worsened positional diff; restored.
// attempt 9: combined result declaration/initialization emitted identical code.
// attempt 10: int-width result and attempt 11's ABI-proven virtual declaration emitted identical code.
// attempt 12: scalar 0/1 result introduced a stack local and 366-byte body; restored.
// variant lab: EH-enabled typed-result form reached 358 bytes (diagnostic diff 257) but still emitted the EBX result copy; plain/combined forms stayed 398 bytes.
// attempt 13: do/while(0) break convergence changed call order and grew to 406 bytes; restored.
// fresh pass baseline: direct-return source remains the best clean reconstruction at 398 bytes/diff 194.
// fresh pass: uninitialized scalar status forced a 420-byte four-return basin; restored.
// fresh pass: delayed typed result after the null-target guard produced 368 bytes but diff 328; restored.
// fresh pass: exact constructor ABI (RGE_Action_Object*, RGE_Task*, RGE_Static_Object*) fixed the donor call identity with unchanged codegen; kept.
// fresh pass: real RGE_Action_List and RGE_Static_Object virtual destructor surfaces were codegen duplicates; kept for canonical ABI.
// fresh pass: switch spelling of the second action-type gate was byte-identical; restored for natural source.
// left in scratch: behavior/calls/EH/new-action shape are understood; remaining drift is VC5 exit-path cloning/block layout (success returns inline instead of original shared success tail) plus shifted branch distances.
// FLAGS: /nologo /c /O2 /Oy /GX

class RGE_Action;
class RGE_Action_List;
class RGE_Game_World;
class RGE_Player;
class RGE_Task;
class RGE_Action_Object;

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

class RGE_Player_Info {
public:
    char pad_00[0x270];
    void* field_270;
};

class RGE_Player {
public:
    char pad_00[0x24];
    RGE_Player_Info* info;
    char pad_28[0x14];
    RGE_Game_World* world;
};

class RGE_Game_World {
public:
    char pad_00[4];
    RGE_Static_Object* object(int id);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int vf04(void*);
    virtual int vf08(int, void*);
    virtual void* vf0C(void*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(void*, float, float, float);
    virtual int vf34(void*, float, float, float);
    virtual unsigned char vf38(void*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual void* vf4C();
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

struct Action_Repair_Pad {
    char data[0x40];
};

class TRIBE_Action_Repair : public RGE_Action {
public:
    Action_Repair_Pad padding;
    TRIBE_Action_Repair(RGE_Action_Object* obj, RGE_Task* task, RGE_Static_Object* target);
};

class RGE_Action_Object {
public:
    int id;
    void* master_obj;
    RGE_Player* owner;
    char pad_10[0x28];
    float world_x;
    float world_y;
    float world_z;
    char pad_44[0x140];
    RGE_Action_List* actions;

    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19();
    virtual void d20(); virtual void d21(void*); virtual void d22(); virtual void d23();
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
    virtual void d128();
    virtual void d129();
};

class TRIBE_Combat_Object : public RGE_Action_Object {
public:
    virtual void vf208(void* action);
    virtual void d131();
    virtual void* vf210(void* obj, float x, float y, float z);

    virtual int repair(int id, int flag);
};

int TRIBE_Combat_Object::repair(int id, int flag) {
    void* task;

    RGE_Static_Object* obj = this->owner->world->object(id);
    if (obj != 0) {
        if (flag == 0) {
            if (this->actions->have_action() == 1) {
                if (this->actions->get_action()->vf4C() == obj) {
                    if (this->actions->get_action()->vf18() == 0x6A) {
                        goto success;
                    }
                }
            }
        }

        if (this->actions->have_action() == 1) {
            if (this->actions->get_action()->vf18() == 0x6A) {
                this->actions->get_action()->vf34(obj, obj->world_x, obj->world_y, obj->world_z);
                goto success;
            }
        }

        if (this->owner->info->field_270 != 0) {
            this->d21(this->owner->info->field_270);
        }

        task = this->vf210(obj, obj->world_x, obj->world_y, obj->world_z);
        if (task != 0) {
            TRIBE_Action_Repair* repair_action = new TRIBE_Action_Repair(this, (RGE_Task*)task, obj);
            if (repair_action != 0) {
                this->actions->delete_list();
                this->vf208(repair_action);
                goto success;
            }
        }
    }

    return 0;

success:
    return 1;
}
