extern "C" int __cdecl atoi(const char *s);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char *stringValue;
    int asInt() const;
};
#endif

int DString::asInt() const {
    return atoi(this->stringValue);
}
