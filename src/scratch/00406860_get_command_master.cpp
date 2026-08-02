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
// Best source shape (this session): for-loop + direct return obj (143 pos / 66 edit).

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Master_Static_Object;

class RGE_Master_Command {
public:
    virtual void vf00(void);
    virtual int get_command_master(RGE_Action_Object* action, RGE_Static_Object* target,
                                   float x, float y, float z);
};

class RGE_Master_Static_Object {
public:
    char gap_00[4];                  // +0x00
    unsigned char master_type;       // +0x04
    char gap_05[0x0F];               // +0x05..+0x13
    short object_group;              // +0x14
    char gap_16[0xC2];               // +0x16..+0xD7
    RGE_Master_Command* command;     // +0xD8
    char gap_DC[0x10];               // +0xDC..+0xEB
    unsigned char commandable;       // +0xEC
};

class RGE_Master_List {
public:
    char gap_00[0x22];               // +0x00..+0x21
    short master_count;              // +0x22
    RGE_Master_Static_Object** masters; // +0x24
};

class RGE_Action_Object {
public:
    char gap_00[8];                  // +0x00..+0x07
    RGE_Master_Static_Object* master; // +0x08
    RGE_Master_List* master_list;    // +0x0C

    RGE_Master_Static_Object* get_command_master(RGE_Static_Object* target, float x, float y, float z);
};

RGE_Master_Static_Object* RGE_Action_Object::get_command_master(RGE_Static_Object* target,
                                                                float x, float y, float z)
{
    if ((void*)target == (void*)this || this->master->commandable == 0) {
        return this->master;
    }
    if (this->master->command->get_command_master(this, target, x, y, z) != 0) {
        return this->master;
    }
    if (this->master->commandable != 0) {
        RGE_Master_Static_Object* obj;
        for (int i = 0; i < this->master_list->master_count; i++) {
            obj = this->master_list->masters[i];
            if (obj != 0 &&
                obj->object_group == this->master->object_group &&
                obj->master_type == this->master->master_type &&
                obj->commandable == this->master->commandable) {
                if (obj->command->get_command_master(this, target, x, y, z) != 0) {
                    return obj;
                }
            }
        }
    }
    return this->master;
}
