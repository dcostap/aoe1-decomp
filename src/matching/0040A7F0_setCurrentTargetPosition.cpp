class BaseObject {
public:
    char gap_0[0x94];
    int field_94;
    int field_98;
    int field_9C;
    void setCurrentTargetPosition(int a, int b, int c);
};

void BaseObject::setCurrentTargetPosition(int a, int b, int c) {
    this->field_94 = a;
    this->field_98 = b;
    this->field_9C = c;
}
