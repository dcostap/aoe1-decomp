// Matches in the dstring.cpp /GX donor-context basin.
// Keep the direct member-index trim loop here.
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
    DString stripTrailing(char value);
};
#endif

DString DString::stripTrailing(char value) {
    int index;

    index = this->lengthValue;
    while ((this->stringValue[index - 1] == value) && (0 < index)) {
        index = index - 1;
    }
    *this = this->subString(0, index);
    return *this;
}
