struct InnerObj { char pad[0x15C]; int field_15C; };
class SomeClass {
public:
    void set_sorted(int val);
    char pad[0xFC];
    InnerObj* field_FC;
};
void SomeClass::set_sorted(int val) {
    if (this->field_FC) {
        this->field_FC->field_15C = val;
    }
}
