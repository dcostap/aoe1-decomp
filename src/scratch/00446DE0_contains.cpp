// contains (00446DE0, 25 bytes, dstring.cpp)
// calls strstr and converts result to 0/1
extern "C" char* __cdecl strstr(const char*, const char*);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
};
#endif

int DString::contains(const char* param) const {
    return strstr(stringValue, param) != 0;
}
