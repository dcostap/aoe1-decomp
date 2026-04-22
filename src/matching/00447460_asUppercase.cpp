// Preserve the donor-file EH/object-lifetime context here: this by-value return helper
// exact-matches under `/GX`, and the visible nontrivial `DString::~DString()` declaration
// is part of the working VC5 source model for this dstring.cpp cluster.
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
    void uppercase(void);
    DString asUppercase(void);
};

DString DString::asUppercase(void) {
    DString result(this->stringValue);

    result.uppercase();
    return result;
}
