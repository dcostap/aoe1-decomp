#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    operator char*() const;
};
#endif

DString::operator char*() const { return this->stringValue; }
