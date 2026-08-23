class SomeClass {
public:
    void setCurrentAttackWaypoint(unsigned char wp);
    char pad[0x1D4];
    unsigned char field_1D4;
    unsigned char field_1D5;
};
void SomeClass::setCurrentAttackWaypoint(unsigned char wp) {
    if (wp < this->field_1D4) {
        this->field_1D5 = wp;
    }
}
