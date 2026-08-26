extern "C" double __cdecl atof(const char *s);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char *stringValue;
    double asDouble() const;
};
#endif

double DString::asDouble() const {
    return atof(this->stringValue);
}
