class SomeClass {
public:
    int other_method();
    int create_list();
    char pad[0x4AC];
    int field_4AC;
};
int SomeClass::create_list() {
    if (this->field_4AC - 1) return 0;
    return this->other_method();
}
