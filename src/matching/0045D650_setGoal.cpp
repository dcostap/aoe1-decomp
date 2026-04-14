class RGE_Moving_Object {
public:
    char gap_0[0x11C];
    int field_11C;
    int field_120;
    int field_124;
    void setGoal(int a, int b, int c);
};

void RGE_Moving_Object::setGoal(int a, int b, int c) {
    this->field_11C = a;
    this->field_120 = b;
    this->field_124 = c;
}
