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
// Left in scratch: best source below is behaviorally right and has only the stable
//   1-byte width drift at the obj_id load (`8b54240c` vs `668b54240c`), which shifts
//   the remainder by one byte. No inline asm/hacks used.

class RGE_Action_Object;

class RGE_Action {
public:
    char _gap[0x40];
    RGE_Action(RGE_Action_Object* obj, int type);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    char gap_40[0x10];
    TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    unsigned char pp = *(volatile unsigned char*)&pre_paid;
    int uid = *(volatile int*)&unique_id;
    const short oid = *(volatile short*)&obj_id;

    *(unsigned char*)((char*)this + 0x4C) = pp;
    *(int*)((char*)this + 0x48) = uid;
    *(int*)this = 0x5751A8;
    *(short*)((char*)this + 4) = 0x66;
    *(short*)((char*)this + 0x40) = oid;
    *(int*)((char*)this + 0x44) = 0;
}
