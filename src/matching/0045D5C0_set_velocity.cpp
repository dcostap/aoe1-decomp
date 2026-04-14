class RGE_Moving_Object {
public:
    char gap_0[0x90];
    int field_90;
    int field_94;
    int field_98;
    void set_velocity(int a, int b, int c);
};

void RGE_Moving_Object::set_velocity(int a, int b, int c) {
    this->field_90 = a;
    this->field_94 = b;
    this->field_98 = c;
}
