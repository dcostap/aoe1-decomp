#ifndef TACT_MOB_SHARED_CONTEXT
class TRIBE_Action_Make_Obj {
public:
    virtual ~TRIBE_Action_Make_Obj();
    char gap_0[0x8];
    unsigned char field_C;
    void set_state(unsigned char v);
};
#endif

void TRIBE_Action_Make_Obj::set_state(unsigned char v) { this->field_C = v; }
