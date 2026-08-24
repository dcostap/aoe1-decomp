// VA: 004D0EB0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, unsigned char)
// PDB source: tact_mob.cpp lines 48-54 (63 bytes, 18 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params. ret 10h cleanup.
// Attempt log:
// - Original scratch raw-store/typed-member forms: VC5 read/stored obj_id first
//   (mov ax,[esp+0Ch]) instead of original post-base load order p4,p3,p2.
// - Previous (HollowSnowdrop): typed members, locals, volatile still stuck at
//   parameter-load scheduling; 31/63 positional diff, 51/63 edit-equal.
// - Try 1: volatile reads into pp/uid/oid locals before stores fixed the entire
//   load/store schedule but VC5 chose dword obj_id load (`mov edx,[esp+0Ch]`)
//   instead of original word load (`mov dx,[esp+0Ch]`): edit diff 2, 62/63 equal.
// - Try 2: plain `short oid = obj_id` restored a word load but VC5 used `cx`,
//   clobbered uid, and moved the unique_id store before obj_id load.
// - Try 3: direct volatile-short store expression (no oid local) also moved
//   unique_id store too early and used ecx/cx.
// - Try 4: volatile short local forced a stack spill/reload and was much worse.
// - Try 5: volatile short formal parameter with volatile locals still used the
//   same dword obj_id load as try 1.
// - Try 6: unsigned short formal/local restored word load but again used cx and
//   scheduled unique_id store early.
// - Try 7: volatile pp local with plain uid/oid introduced stack traffic and worse
//   byte-register allocation.
// - Try 8: `register short oid` collapsed back to try 1 (single missing 66 prefix).
// - Try 9: temporary /O1 probe emitted only 58 bytes, wrong family; removed flag.
// - Try 10: `const short oid` also collapsed to try 1.
// - Try 11: declaration-order probes for pp/uid/oid and split assignment forms
//   all kept the cx/early-unique_id-store family when the obj_id local was plain short.
// - Try 12: volatile destination stores preserved source order but still used cx
//   for the word load and moved the load after the pre_paid/unique_id stores.
// - Try 13: pointer/ref/union/struct volatile reads of obj_id all collapsed back
//   to the best one-byte dword-load family.
// - Try 14: member-initializer/autovtable constructor surface shifted base `this`
//   to +4 and was a wrong-family broad mismatch.
// - Try 15: direct `this->obj_id = obj_id` before the other stores produced the
//   exact `mov dx,[esp+0Ch]` load, but VC5 also stored obj_id before unique_id/vptr.
// - Try 16: tried /Ob0, /Og, /Op, /Os, and /GX; /Os was wrong-size and the others
//   kept the same one-byte width drift, so no per-function flag is kept.
// - Try 17: real typed RGE_Action/TRIBE_Action_Make_Obj surface (matching load/save
//   field layout) compiled to the same best one-byte dword-load drift as raw stores.
// ACCEPTED_DRIFT: reviewed by Boss. Non-zero diff is a single load-width encoding
// difference for obj_id: rebuilt uses `mov edx,[esp+0Ch]` while original uses
// `mov dx,[esp+0Ch]`; the later store is `mov [esi+40h],dx`, so the high half of
// edx is unused. Memory effects, call/cleanup, stores, and return are identical;
// remaining positional diff is one-byte shift fallout plus final padding NOP.

class RGE_Action_Object;

#ifndef TACT_MOB_SHARED_CONTEXT
class RGE_Action {
public:
    virtual ~RGE_Action();
    short action_type;
    char gap_06[0x3A];

    RGE_Action(RGE_Action_Object* obj, int type);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;
    int work_done;
    int unique_id;
    unsigned char pre_paid;

    TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid);
};
#endif

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    unsigned char pp = *(volatile unsigned char*)&pre_paid;
    int uid = *(volatile int*)&unique_id;
    const short oid = *(volatile short*)&obj_id;

    this->pre_paid = pp;
    this->unique_id = uid;
    *(int*)this = 0x5751A8;
    this->action_type = 0x66;
    this->obj_id = oid;
    this->work_done = 0;
}
