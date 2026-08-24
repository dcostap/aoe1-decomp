// Matches in the dstring.cpp EH/object-lifetime basin: keep /GX and a visible
// nontrivial DString destructor declaration even though this helper body is small.
#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString(const DString& other);
    ~DString();
    void append(DString value);
    DString operator+(const DString& value) const;
};
#endif

DString DString::operator+(const DString& value) const {
    DString newStr(*this);

    newStr.append(value);
    return newStr;
}
