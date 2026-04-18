extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
class BaseItem {
public:
    void setName(char* name);
    char pad[0x10];
    char field_10[64];
};
void BaseItem::setName(char* name) {
    strncpy(this->field_10, name, 63);
}
