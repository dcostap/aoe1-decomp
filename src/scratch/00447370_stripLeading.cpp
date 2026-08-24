// Matches in the dstring.cpp /GX donor-context basin.
// Keep the simple trim loop with the bound check before the next byte read.
#include <stdlib.h>
#include <string.h>
extern "C" int __cdecl isspace(int value);

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
    DString stripLeading(char value);
};
#endif

DString DString::stripLeading(char value) {
    int index;

    index = 0;
    if (this->stringValue[0] == value) {
        while (1) {
            if (index >= this->lengthValue)
                break;
            index = index + 1;
            if (this->stringValue[index] != value)
                break;
        }
    }
    *this = this->subString(index, this->lengthValue);
    return *this;
}
