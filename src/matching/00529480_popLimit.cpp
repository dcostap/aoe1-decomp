class SomeClass {
public:
    int someMethod();
    unsigned char popLimit();
    char pad[0xAE6];
    unsigned char field_AE6;
};
unsigned char SomeClass::popLimit() {
    if (this->someMethod()) {
        return this->field_AE6;
    }
    return 50;
}
