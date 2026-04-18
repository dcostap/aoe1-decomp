int __stdcall ws_gethostname(char* name, int namelen);
class SomeClass {
public:
    char* GetHostName();
    char pad[0x194];
    char hostname[128];
};
char* SomeClass::GetHostName() {
    ws_gethostname(this->hostname, 128);
    return this->hostname;
}
