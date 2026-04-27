// 004D10F0 TRIBE_Action_Make_Obj::update
// Probe 1: structural stub
class RGE_Action { public: virtual ~RGE_Action(); short action_type; };
class TRIBE_Action_Make_Obj : public RGE_Action { public: char _gap_08[0x48]; unsigned char update(int a,int b,int c,int d,int e); };
unsigned char TRIBE_Action_Make_Obj::update(int a,int b,int c,int d,int e) { (void)a;(void)b;(void)c;(void)d;(void)e; return 1; }
