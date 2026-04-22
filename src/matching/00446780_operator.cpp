extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString& operator=(const char* value);
};

DString& DString::operator=(const char* value) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->lengthValue = (int)strlen(value);
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, value);
    } else {
        this->stringValue = 0;
    }
    return *this;
}
