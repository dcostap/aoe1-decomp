class TRIBE_Action_Make_Tech {
public:
    virtual ~TRIBE_Action_Make_Tech();
    char gap_0[0x8];
    unsigned char field_C;
    void set_state(unsigned char v);
};

void TRIBE_Action_Make_Tech::set_state(unsigned char v) { this->field_C = v; }
