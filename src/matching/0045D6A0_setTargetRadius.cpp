class RGE_Moving_Object {
public:
    char gap_0[0x13C];
    int field_13C;
    int field_140;
    void setTargetRadius(int a, int b);
};

void RGE_Moving_Object::setTargetRadius(int a, int b) {
    this->field_13C = a;
    this->field_140 = b;
}
