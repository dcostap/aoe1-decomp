extern "C" int __cdecl toupper(int c);

class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    int length(void) const;
    void uppercase(void);
};

void DString::uppercase(void) {
    int index;

    index = 0;
    if (this->length() > 0) {
        do {
            this->stringValue[index] = (char)toupper((int)this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}
