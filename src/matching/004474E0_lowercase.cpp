extern "C" int __cdecl tolower(int c);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    int length(void) const;
    void lowercase(void);
};

void DString::lowercase(void) {
    int index;

    index = 0;
    if (this->length() > 0) {
        do {
            this->stringValue[index] = (char)tolower((int)this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}
