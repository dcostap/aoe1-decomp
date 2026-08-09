// VA: 00406860 RGE_Action_Object::get_command_master
// PDB source: act_obj.cpp lines 484-519
// Attempt log:
// - 2026-05-31: Replaced placeholder stub with natural master fallback scan using the
//   binary-observed +0xD8 vtable helper slot and +0x0C master-list owner. Initial
//   direct loop was close but used EBP for target and EBX for loop counter.
// - while(1)/continue/goto-found fixed the late success/exhausted-tail topology but
//   still leaves the target-vs-counter register color swapped (target in EBP, i in EBX).
// - Tried mutating the incoming target parameter into the loop counter to mimic the
//   reused stack slot; one form preloaded EDX before push ebx, another moved target
//   through ESI/EBP. Tried volatile i; it produced the correct early EBX target load
//   but added too many stack-memory ops. Restored the cleaner target-local baseline.
// - 2026-08-03 (sa-d586c0a0-r1): full structure verified (size 221, calls 2/2, frame,
//   CFG, three return tails all match). Sole remaining drift is register coloring:
//   original keeps target->EBX (loaded right after push ebx), z->EBP (loaded at first
//   call, reused via push ebp in the loop call), i->ECX homed at the dead target param
//   slot [esp+14h]; rebuilt keeps target->EBP, i->EBX, reloads z per call. The loop's
//   reg-vs-mem byte compares follow from i occupying ECX in the original.
// - Tried (all identical or worse): target_obj local removal, && vs || vs nested
//   checks, for/do-while/while(1)/while loop forms, first-call inline test vs int
//   temp vs ==0/else, void* vs typed casts, flat vs VPAD-polymorphic vs
//   RGE_Static_Object-inheritance class surface, /GX flag file, register int i,
//   z2 float local, cmd local (worse 145). Flat variant lab (32 combos: loop x
//   first-call x compare order x inner-call form) - every compilable variant keeps
//   first_mismatch=+0001 with the same prologue coloring.
// - Key evidence: matched sibling getTask (00406C30) has the same loop and DOES get
//   z->EBP + i->homed, because its first-call result (task) is a long-lived local in
//   EBX; gcm has no long-lived result but the original still allocated z->EBP. The
//   original's i home [esp+14h] is the dead target param slot (target moved to EBX);
//   getTask homes i at [esp+20h] (dead z slot). The rebuilt never homes i.
// - Left in scratch: remaining drift is VC5 register allocation; the allocation is
//   insensitive to every source axis tried. Next lead: reproduce the original TU
//   include/declaration context of act_obj.cpp, or an original expression form that
//   creates a long-lived value in EBX (e.g., first-call result kept live) which
//   would force z into EBP and i onto the stack home.
// Best source shape (this session): canonical owner/task-list types with a natural
// for-loop and direct candidate return (143 positional / 66 edit).
// - 2026-08-09 probe: +0x0C is the inherited RGE_Static_Object::owner (RGE_Player*),
//   not a standalone master-list type; its +0x22/+0x24 fields are
//   master_object_num/master_objects. This canonical ownership/layout change emitted
//   identical bytes, but is retained as the plausible source model.
// - 2026-08-09 probe: modeled +0xD8 as RGE_Master_Action_Object::tasks and +0xEC as
//   task_by_group, with RGE_Task_List::get_target_task; this also emitted identical
//   bytes. Remaining mismatch is the previously isolated VC5 register basin.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Player;

#define VPAD1(n) virtual void vf##n(void);
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Static_Object {
public:
    VPAD32(0)
    VPAD8(32)
    VPAD4(40)
    VPAD2(44)
    VPAD1(46)
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* target,
                                                          float x, float y, float z);

    int id;                         // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;              // +0x0C
};

class RGE_Moving_Object : public RGE_Static_Object {
};

class RGE_Task_List {
public:
    virtual void vf00(void);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action, RGE_Static_Object* target,
                                       float x, float y, float z);
};

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    unsigned char master_type;       // +0x04
    char gap_05[0x0F];               // +0x05..+0x13
    short object_group;              // +0x14
    char gap_16[0xA2];               // +0x16..+0xB7
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x20];               // +0xB8..+0xD7
    RGE_Task_List* tasks;            // +0xD8
    char gap_DC[0x10];               // +0xDC..+0xEB
    unsigned char task_by_group;     // +0xEC
};

class RGE_Player {
public:
    virtual void vf00(void);
    char gap_04[0x1E];                // +0x04..+0x21
    short master_object_num;         // +0x22
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object* target,
                                                          float x, float y, float z);
};

RGE_Master_Static_Object* RGE_Action_Object::get_command_master(RGE_Static_Object* target,
                                                                float x, float y, float z)
{
    if (target == this || ((RGE_Master_Action_Object*)this->master_obj)->task_by_group == 0) {
        return this->master_obj;
    }
    if (((RGE_Master_Action_Object*)this->master_obj)->tasks->get_target_task(this, target, x, y, z) != 0) {
        return this->master_obj;
    }
    if (((RGE_Master_Action_Object*)this->master_obj)->task_by_group != 0) {
        RGE_Master_Static_Object* obj;
        for (int i = 0; i < this->owner->master_object_num; i++) {
            obj = this->owner->master_objects[i];
            if (obj != 0 &&
                obj->object_group == this->master_obj->object_group &&
                obj->master_type == this->master_obj->master_type &&
                ((RGE_Master_Action_Object*)obj)->task_by_group ==
                    ((RGE_Master_Action_Object*)this->master_obj)->task_by_group) {
                if (((RGE_Master_Action_Object*)obj)->tasks->get_target_task(this, target, x, y, z) != 0) {
                    return obj;
                }
            }
        }
    }
    return this->master_obj;
}
