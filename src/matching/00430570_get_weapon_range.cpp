class InnerObj {
public:
    char gap_0[0x114];
    int field_114;
    char gap_118[0x28];
    int field_140;
};

class RGE_Combat_Object {
public:
    char gap_0[0x8];
    InnerObj* field_8;
    void get_weapon_range(int* a, int* b);
};

void RGE_Combat_Object::get_weapon_range(int* a, int* b) {
    *a = this->field_8->field_114;
    *b = this->field_8->field_140;
}
