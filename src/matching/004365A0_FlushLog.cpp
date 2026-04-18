extern void* g_debug_file;
extern "C" int __cdecl fflush(void* stream);
class SomeClass {
public:
    void FlushLog();
    char pad[0x08];
    void* field_08;
};
void SomeClass::FlushLog() {
    if (this->field_08) {
        fflush(g_debug_file);
    }
}
