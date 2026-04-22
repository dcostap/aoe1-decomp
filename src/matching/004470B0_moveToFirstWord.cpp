class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    void moveToFirstWord();
};

void DString::moveToFirstWord() {
    this->indexValue = 0;
    this->currentWordValue = 0;
}
