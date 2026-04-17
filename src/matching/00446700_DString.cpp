extern "C" void __cdecl free(void* block);

class DString {
public:
    char* stringValue;

    ~DString();
};

DString::~DString() {
    if (stringValue != 0) {
        free(stringValue);
    }
}
