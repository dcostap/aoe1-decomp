struct CombatDataA {
    char gap_00[0x8F];
    unsigned char value_8F;
};

struct CombatDataB {
    char gap_00[0x8];
    short value_08;
};

class TRIBE_Combat_Object {
public:
    char gap_00[0x8];
    CombatDataA* data_a;
    char gap_0C[0x18];
    CombatDataB* data_b;

    int can_debark();
};

int TRIBE_Combat_Object::can_debark() {
    if (this->data_a->value_8F != 7) {
        return 0;
    }
    return this->data_b->value_08 != 0;
}
