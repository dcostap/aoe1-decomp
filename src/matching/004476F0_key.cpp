// Matches only in the dstring.cpp EH/object-lifetime basin: keep `/GX` and a visible
// nontrivial `DString::~DString()` declaration here even though this tiny helper body
// does not textually use them.
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
};
#endif

#ifndef DSTRING_TU_CONTEXT
class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    DString key() const;
};
#endif

DString DKeyString::key() const {
    return this->keyValue;
}
