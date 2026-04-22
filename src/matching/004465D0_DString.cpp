extern "C" void* __cdecl malloc(unsigned int size);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
};

DString::DString() {
    this->stringValue = 0;
    this->lengthValue = 0;
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->stringValue = (char*)malloc(1);
    strcpy(this->stringValue, "");
}
