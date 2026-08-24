#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    void moveToFirstWord();
};
#endif

void DString::moveToFirstWord() {
    this->indexValue = 0;
    this->currentWordValue = 0;
}
