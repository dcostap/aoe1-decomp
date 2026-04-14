class InnerObj {
public:
    char gap_0[0x120];
    int field_120;
    char gap_124[0x20];
    int field_144;
};

class RGE_Combat_Object {
public:
    char gap_0[0x8];
    InnerObj* field_8;
    void get_speed_of_attack(int* a, int* b);
};

void RGE_Combat_Object::get_speed_of_attack(int* a, int* b) {
    *a = this->field_8->field_120;
    *b = this->field_8->field_144;
}
