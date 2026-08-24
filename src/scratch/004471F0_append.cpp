// Matches in a fuller donor-style dstring.cpp translation-unit context under /GX.
// Keep this target owner limited to the PDB line band for append.
#include <stdlib.h>
#include <string.h>

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const DString& other);
    DString(const char* value);
    ~DString();
    DString& operator=(const char* value);
    DString& operator=(const DString& other);
    DString operator+(const DString& value) const;
    char& operator[](int index);
    operator char*() const;
    int length() const;
    int numWords();
    int index() const;
    int contains(DString value) const;
    int contains(const char* value) const;
    DString word(int wordIndex);
    DString nextWord(int updateIndex);
    void moveToFirstWord();
    void moveToNextWord();
    DString subString(int start, int count);
    void append(DString value);
};
#endif

void DString::append(DString value) {
    int i;
    int baseLen;
    char* text;

    text = (char*)malloc(value.length() + this->lengthValue + 1);
    i = 0;
    if (this->lengthValue > 0) {
        do {
            text[i] = this->stringValue[i];
            i = i + 1;
        } while (i < this->lengthValue);
    }
    baseLen = this->lengthValue;
    if (i < value.length() + baseLen) {
        do {
            text[i] = value[i - baseLen];
            baseLen = this->lengthValue;
            i = i + 1;
        } while (i < value.length() + baseLen);
    }
    text[i] = 0;
    free(this->stringValue);
    this->stringValue = text;
    this->lengthValue = this->lengthValue + value.length();
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
}
