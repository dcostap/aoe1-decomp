class SomeClass {
public:
    int is_loaded();
    int field_00;
    char pad[0x14];
    int field_18;
};
int SomeClass::is_loaded() {
    if (this->field_00 || this->field_18) return 1;
    return 0;
}
