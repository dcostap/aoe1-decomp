class SomeClass {
public:
    void some_method(int param);
    void set_list_len(int len, int param2);
    char pad[0xF8];
    int field_F8;
};
void SomeClass::set_list_len(int len, int param2) {
    this->field_F8 = len;
    this->some_method(param2);
}
