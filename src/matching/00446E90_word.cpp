// Matches under `/GX` in the dstring.cpp EH/object-lifetime basin.
// Keep the positive outer bounds gate and delay the scan-local births until after
// the fast path: `index = 0; inWord = 0; wordCount = 0;` right before the loop.
// Declaring those locals up front but initializing them late is part of the exact-match source model here.
#include <stdlib.h>
#include <string.h>
extern "C" int __cdecl isspace(int c);

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

DString DString::word(int wordIndex) {
    int wordCount;
    int index;
    int inWord;

    if ((wordIndex <= this->numWords()) && (wordIndex >= 1)) {
        if (wordIndex == this->currentWordValue + 1) {
            this->currentWordValue = this->currentWordValue + 1;
            return this->nextWord(1);
        }

        index = 0;
        inWord = 0;
        wordCount = 0;

        for (; wordCount != wordIndex; index = index + 1) {
            if (index >= this->lengthValue)
                break;
            if (!inWord) {
                if (isspace((int)index[this->stringValue])) {
                    goto still_in_gap;
                }
                wordCount = wordCount + 1;
                inWord = 1;
                goto next_index;
            }
still_in_gap:
            if (isspace((int)index[this->stringValue])) {
                inWord = 0;
            }
next_index:
            ;
        }

        if (wordCount == wordIndex) {
            int start;

            start = index - 1;
            while ((isspace((int)this->stringValue[index]) == 0) && (index < this->lengthValue)) {
                index = index + 1;
            }
            DString rStr = this->subString(start, index - start);
            return rStr;
        }
    }

    return DString("");
}
