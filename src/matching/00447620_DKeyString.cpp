// Preserve the donor-file EH/object-lifetime context here: this constructor exact-matches
// under `/GX`, and the visible nontrivial `DString::~DString()` declaration is part of the
// working VC5 source model for this dstring.cpp cluster.
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

class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    DKeyString(DString key, DString value);
};

DKeyString::DKeyString(DString key, DString value) : keyValue(key), valueValue(value) {}
