extern "C" void* __cdecl malloc(unsigned int size);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString(const DString& other);
};

DString::DString(const DString& other) {
    this->lengthValue = other.lengthValue;
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, other.stringValue);
    } else {
        this->stringValue = 0;
    }
}
