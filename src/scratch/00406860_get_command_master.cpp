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
// - 2026-08-10 (orch-actobj-01 fresh pass): required dossier, same-TU donor, and ABI
//   evidence confirmed the two indirect calls, canonical owner/player array, and
//   task-list ABI. Rolled back nine bounded probes: index-before-candidate declaration;
//   stdio TU context; master-array pointer alias (246-byte structural drift);
//   per-iteration candidate scope; reversed initial equality (one compare byte only);
//   full 0x88/0x180/0x194 object layout; function-scope index; top-level index/candidate
//   declarations; and /G5. None changed the clean 221-byte register basin except the
//   documented worse array alias. Default flags and the canonical source are retained.
// - 2026-08-10 (wave21-actobj-01): preserved z in a natural local after the guard;
//   restored the proven RGE_Master_Moving_Object base boundary; register-qualified
//   target parameter; and <memory.h> TU context. Each stayed at 221 bytes / 143-byte
//   positional drift (the z and layout forms emitted duplicates); all were rolled back.
// - 2026-08-10 liveness lab: 216 deliberate combinations of receiver/target/z aliases,
//   first-call result surfaces, loop/index scopes, and candidate scope produced only
//   the existing 221-byte basin among 107 valid builds; no target->EBX lead emerged.
// Left in scratch: canonical typed owner/master/task hierarchy is validated; remaining
// drift is the stable VC5 target/z/index register allocation basin.
// - 2026-08-11 (sa-e91dfaa7-r1): DIA inspection of the original PDB confirms the
//   act_obj.cpp compiland includes only stat_obj.h, ani_obj.h, and move_obj.h; the
//   function's emitted locals are parameter obj, floats x/y/z, and int i. Fresh
//   source probes all restored to the clean 221-byte basin: positive nested guard
//   control flow worsened to 151 bytes; typed candidate, period destructor/create_task
//   virtual surfaces, full 0xFC master layout, full 0x220 player layout, top-level
//   z lifetime, z/y/x copies, and action-typed master_obj were unchanged. No source
//   or proven layout axis moved target=EBP/i=EBX/z-reload toward the oracle's
//   target=EBX/z=EBP/i-at-target-home allocation.
// - 2026-08-12 (orch-00406860-L): dossier, donor, ABI, and assembly-donor evidence
//   reconfirmed the two ordered indirect calls and the same-TU getTask basin. Combined
//   stdio/memory and stdlib/string header pairs, simultaneous register-qualified
//   target/z, y/z locals, explicit target casts, a void* target ABI, and nested positive
//   guards all emitted the clean 221-byte basin (143 positional / 66 edit).
// - A persistent master local was worse (190 positional / 130 edit). A natural owner
//   local improved the diagnostic output to 106 positional / 55 edit and 52.94% exact
//   blocks, but moved owner to [esp+14] and left i in EBX; register-qualified owner was
//   identical. The binary proves [esp+14] is i, so this source-steering variant was
//   rolled back. Clean canonical source is restored; residual target/z/index coloring
//   remains unresolved.
// - 2026-08-13 (follow-406860-r1): original stat_obj.cpp and class dumps confirm the
//   inherited RGE_Static_Object get_command_master ABI at slot +0xBC, the +0x08 master
//   owner, the +0x0C RGE_Player owner, and the +0xD8 task-list action surface. A
//   function-scope RGE_Task result, suggested by the original line-494 call and
//   line-495 test split, emitted the same 221-byte basin and was rolled back.
// - 2026-08-13 (tu-actobj-406860): renaming the incoming target parameter to the
//   PDB-observed obj name and the candidate to master emitted the same 221-byte
//   basin. Reused the exact getTask sibling's RGE_Task_List surface at +0xD8 and
//   get_target_task ABI; this also emitted identical bytes and is retained as the
//   canonical task-list hierarchy. Remaining drift is target/z/index
//   register coloring: target=EBP, z reloads, and i=EBX instead of target=EBX,
//   z=EBP, and i at the target home.
// - 2026-08-14 (sa-c107dda1-r1): removed the candidate local and repeated the
//   canonical owner-array expression. Shape improved, but positional drift grew
//   to 146 bytes and the call setup gained an extra object load; rolled back.
// - 2026-08-17 (sa-f489d25b-r1): fresh baseline reproduced 221 bytes / 143-byte
//   positional drift. A target alias, a separately declared while-loop index,
//   and a first-call RGE_Task result local all emitted the same register basin;
//   each was rolled back. Canonical natural for-loop source is retained.
// - 2026-08-17 canonical ownership probe: the +0xD8 object is the reviewed
//   RGE_Task_List field of RGE_Master_Action_Object, not a command wrapper.
//   Its slot-1 get_target_task ABI is proven by the exact getTask and work2
//   siblings. The body remains a direct early-return plus natural for scan.
// - 2026-08-17 follow-up probes: first-call direct/named-result forms, bounded
//   while/for forms, a compound candidate predicate, and split guards all kept
//   the same 221-byte basin (143 positional bytes). A preload-while form was
//   204 bytes. A direct full-slot RGE_Action_Object surface, 30 neutral forward
//   declarations, and a register-qualified z parameter were also unchanged.
//   These tests do not support changing the canonical source.
// - 2026-08-17 deeper action-TU pass: twenty new evidence-led probes restored
//   the clean source after each test. Separate guards, assignment-in-condition,
//   named task-list and target aliases, scoped z copy, typed candidate master,
//   base-qualified fields, destructor-bearing class context, all-coordinate
//   register hints, signed task_by_group, function-scope i, do/while, body
//   increment, and candidate scopes all stayed at 221/143 or were worse.
//   A branch-local master alias was 222/156. Reconstructed sibling headers
//   could not compile because their common.h requires unavailable stdint.h.
//   The target/z/index allocation basin is therefore not controlled by these
//   proved action-TU declaration or lifetime contexts.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Master_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task_List;
class RGE_Player;
class RGE_Sprite;
class RGE_Sound;

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
    virtual RGE_Task* create_task(short task_type, short id);
    virtual RGE_Task* get_target_task(RGE_Action_Object* action,
                                      RGE_Static_Object* target,
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

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                     // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Sprite* move_sprite;         // +0xBC
    RGE_Sprite* run_sprite;          // +0xC0
    float turn_speed;                // +0xC4
    unsigned char size_class;        // +0xC8
    char gap_C9[1];                  // +0xC9
    short obj_trail_id;              // +0xCA
    unsigned char obj_trail_options; // +0xCC
    char gap_CD[3];                  // +0xCD..+0xCF
    float obj_trail_spacing;         // +0xD0
    unsigned char move_algorithem;   // +0xD4
    char gap_D5[3];                  // +0xD5..+0xD7
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;            // +0xD8
    short default_task;              // +0xDC
    char gap_DE[2];                   // +0xDE..+0xDF
    float search_radius;              // +0xE0
    float work_rate;                  // +0xE4
    short drop_site;                  // +0xE8
    short backup_drop_site;           // +0xEA
    unsigned char task_by_group;     // +0xEC
    char gap_ED[3];                   // +0xED..+0xEF
    RGE_Sound* command_sound;        // +0xF0
    RGE_Sound* move_sound;           // +0xF4
    unsigned char run_pattern;       // +0xF8
    char gap_F9[3];                  // +0xF9..+0xFB
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
    if (((RGE_Master_Action_Object*)this->master_obj)->tasks->get_target_task(
            this, target, x, y, z) != 0) {
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
                if (((RGE_Master_Action_Object*)obj)->tasks->get_target_task(
                        this, target, x, y, z) != 0) {
                    return obj;
                }
            }
        }
    }
    return this->master_obj;
}
