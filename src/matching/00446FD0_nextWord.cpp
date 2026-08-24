// Matches in the dstring.cpp EH/object-lifetime basin under /GX.
// Keeping the natural two-index source shape preserves the original saved-register family:
// `this` in EDI, the scan index in ESI, and the word start in EBP.
#include <stdlib.h>
extern "C" int __cdecl isspace(int c);

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString(const char* value);
    DString(const DString& other);
    ~DString();
    DString subString(int start, int count);
    DString nextWord(int updateIndex);
};
#endif

DString DString::nextWord(int updateIndex) {
    int i;
    int start;

    i = this->indexValue;
    while ((isspace((int)this->stringValue[i]) != 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    start = i;
    while ((isspace((int)this->stringValue[i]) == 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    if (updateIndex != 0) {
        this->indexValue = i;
    }
    DString rStr = this->subString(start, i - start);
    return rStr;
}
