// VA: 004D0EB0 TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(RGE_Action_Object*, short, int, unsigned char)
// PDB source: tact_mob.cpp lines 48-54 (63 bytes, 18 asm lines)
// Default flags
//
// __thiscall: this in ecx, 4 stack params. ret 10h cleanup.
// Attempt log:
// - raw-store version: VC5 reorders param reads (param_2 first, then param_4, param_3)
//   vs original (param_4, param_3, param_2). Cannot force through C++ restructuring.
// - Previous (HollowSnowdrop): same reordering with typed members, locals, volatile
// 31/63 positional diff, 51/63 edit-equal. Left in scratch.

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
    *(unsigned char*)((char*)this + 0x4C) = pre_paid;
    *(int*)((char*)this + 0x48) = unique_id;
    *(int*)this = 0x5751A8;
    *(short*)((char*)this + 4) = 0x66;
    *(short*)((char*)this + 0x40) = obj_id;
    *(int*)((char*)this + 0x44) = 0;
}
