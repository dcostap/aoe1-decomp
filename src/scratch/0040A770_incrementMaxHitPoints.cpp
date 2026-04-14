class BaseObject {
public:
    char gap_0[0x80];
    int field_80;

    void incrementMaxHitPoints(int value);
};

void BaseObject::incrementMaxHitPoints(int value) {
    this->field_80 += value;
}
