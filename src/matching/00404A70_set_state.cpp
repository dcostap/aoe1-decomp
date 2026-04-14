struct TypeC {
    char gap_00[0x90];
    int field_90;
};

struct TypeB {
    char gap_00[0x50];
    TypeC* field_50;
};

struct TypeA {
    char gap_00[0x0C];
    TypeB* field_0C;
};

class RGE_Action_Make {
public:
    char gap_00[0x08];
    TypeA* field_08;
    unsigned char field_0C;
    char gap_0D[0x1F];
    int field_2C;

    void set_state(unsigned char param);
};

void RGE_Action_Make::set_state(unsigned char param) {
    field_0C = param;
    field_2C = field_08->field_0C->field_50->field_90;
}
