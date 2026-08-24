extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString& operator=(const DString& other);
};
#endif

DString& DString::operator=(const DString& other) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
    this->lengthValue = other.lengthValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, other.stringValue);
    } else {
        this->stringValue = 0;
    }
    return *this;
}
