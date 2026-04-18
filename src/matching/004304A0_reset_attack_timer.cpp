struct InnerObj {
    char pad[0x120];
    float field_120;
};
class SomeClass {
public:
    void reset_attack_timer();
    char pad[0x08];
    InnerObj* field_08;
    char pad2[0x1B0];
    float field_1BC;
};
void SomeClass::reset_attack_timer() {
    float tmp = this->field_08->field_120;
    this->field_1BC = tmp;
}
