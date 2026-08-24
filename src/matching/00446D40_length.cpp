#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int length() const;
};
#endif

int DString::length() const { return this->lengthValue; }
