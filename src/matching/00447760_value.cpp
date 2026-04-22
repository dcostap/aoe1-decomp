// Matches only in the dstring.cpp EH/object-lifetime basin: keep `/GX` and a visible
// nontrivial `DString::~DString()` declaration here even though this tiny helper body
// does not textually use them.
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString(const DString& other);
    ~DString();
};

class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    DString value() const;
};

DString DKeyString::value() const {
    return this->valueValue;
}
