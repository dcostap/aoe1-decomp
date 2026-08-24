extern "C" int __cdecl strcmp(const char* string1, const char* string2);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
};
#endif

int __cdecl operator>(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) > 0;
}
