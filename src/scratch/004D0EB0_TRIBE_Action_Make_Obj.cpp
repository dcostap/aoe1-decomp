// VA: 004D0EB0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj()
// Source: tact_mob.cpp lines 48-54
// Size: 63 bytes, __thiscall
//
// Attempt log (8 probes):
// Probe 1: Simple constructor with RGE_Action base + derived fields — 44 diff bytes
//   problem: layout shift — _pad[0x3A] gave sizeof(RGE_Action)=8 (due to short padding) instead of 0x40
// Probe 2: Fixed base class with _gap[0x40] — 31 diff bytes
//   vtable/field_04 stores at correct offsets, relocation masked
//   remaining: VC5 schedules obj_id store before pre_paid/unique_id, and uses different registers
// Probe 3: Reordered stores (vtable first) — 30 diff bytes (1 byte improvement)
// Probe 4: Local temps for params — still 31 bytes, VC5 reorders stores
// Probe 5: volatile stores — 31 bytes, same reordering
// Probe 6: Field reordering in class — broke layout, reverted
// Probe 7: Member initializer list — 37 bytes, worse (no vtable store)
// Probe 8: Initializer list out-of-line — 37 bytes
//
// Remaining 31 bytes: VC5 instruction scheduling + register allocation
//   - Original load order: al=pre_paid, ecx=unique_id, dx=obj_id
//   - Rebuilt load order:  ax=obj_id, cl=pre_paid, edx=unique_id
//   - Original store order: pre_paid, unique_id, vtable, field_04, obj_id, work_done
//   - Rebuilt store order:  obj_id, pre_paid, unique_id, vtable, field_04, work_done
//   All semantically equivalent. Pure VC5 scheduling artifact.
// Parked in scratch per Boss direction.

class RGE_Action_Object;

class RGE_Action {
public:
    char _gap[0x40];
    RGE_Action(RGE_Action_Object* obj, int type);
};

class TRIBE_Action_Make_Obj : public RGE_Action {
public:
    short obj_id;      // +0x40
    int work_done;     // +0x44
    int unique_id;     // +0x48
    unsigned char pre_paid; // +0x4C

    TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid);
};

TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object* obj, short obj_id, int unique_id, unsigned char pre_paid)
    : RGE_Action(obj, 1)
{
    this->pre_paid = pre_paid;
    this->unique_id = unique_id;
    *(int*)this = 0x5751A8;
    *(short*)((int)this + 4) = 0x66;
    this->obj_id = obj_id;
    this->work_done = 0;
}
