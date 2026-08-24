// Preserve the donor-file EH/object-lifetime context here: this setter exact-matches
// under `/GX`, and the visible nontrivial `DString::~DString()` declaration is part of the
// working VC5 source model for this dstring.cpp cluster.
#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString(const char* value);
    DString(const DString& other);
    ~DString();
    DString& operator=(const DString& other);
};
#endif

#ifndef DSTRING_TU_CONTEXT
class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    void setValue(DString value);
};
#endif

void DKeyString::setValue(DString value) { this->valueValue = value; }
