extern "C" void* __cdecl memset(void* dest, int val, unsigned int count);
class SomeClass {
public:
    void EraseInformation();
    int field_00;
    int data[0x115E6];
};
void SomeClass::EraseInformation() {
    this->field_00 = 0;
    memset(this->data, 0, sizeof(this->data));
}
