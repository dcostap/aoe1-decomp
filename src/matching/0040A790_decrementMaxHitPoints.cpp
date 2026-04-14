class BaseObject {
public:
    char gap_0[0x80];
    int field_80;

    void decrementMaxHitPoints(int value);
};

void BaseObject::decrementMaxHitPoints(int value) {
    this->field_80 -= value;
}
