extern "C" int __cdecl strcmp(const char* string1, const char* string2);

class DString {
public:
    char* stringValue;
};

int __cdecl operator!=(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) != 0;
}
