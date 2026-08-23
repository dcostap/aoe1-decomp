extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
class SomeClass {
public:
    void setName(char* name);
    char data[64];
};
void SomeClass::setName(char* name) {
    if (name) {
        strncpy(this->data, name, 64);
    }
}
