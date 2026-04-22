extern "C" int __cdecl isspace(int c);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    void moveToNextWord(void);
};

void DString::moveToNextWord(void) {
    while ((isspace((int)this->stringValue[this->indexValue]) != 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }

    while ((isspace((int)this->stringValue[this->indexValue]) == 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }
}
