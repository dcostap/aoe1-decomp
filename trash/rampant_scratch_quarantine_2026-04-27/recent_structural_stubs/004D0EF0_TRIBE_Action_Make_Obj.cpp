// 004D0EF0 ~TRIBE_Action_Make_Obj
// Probe 1: structural stub
class RGE_Action { public: virtual ~RGE_Action(); short action_type; };
class TRIBE_Action_Make_Obj : public RGE_Action { public: char _gap_08[0x48]; virtual ~TRIBE_Action_Make_Obj(); };
TRIBE_Action_Make_Obj::~TRIBE_Action_Make_Obj() {}
