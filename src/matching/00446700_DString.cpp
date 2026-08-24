extern "C" void __cdecl free(void* block);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;

    ~DString();
};
#endif

DString::~DString() {
    if (stringValue != 0) {
        free(stringValue);
    }
}
