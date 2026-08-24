// Preserve the donor-file EH/object-lifetime context here: this by-value overload exact-matches
// under `/GX`, and the visible nontrivial `DString::~DString()` declaration is part of the
// working VC5 source model for this dstring.cpp cluster.
extern "C" char* __cdecl strstr(const char* string, const char* substring);

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
    operator char*();
    int contains(DString value) const;
};
#endif

int DString::contains(DString value) const {
    if (strstr(this->stringValue, value) != 0) {
        return 1;
    }
    return 0;
}
