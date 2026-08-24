#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int index() const;
};
#endif

int DString::index() const { return this->indexValue; }
