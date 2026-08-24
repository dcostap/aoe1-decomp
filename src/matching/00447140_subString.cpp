// Matches in the dstring.cpp EH/object-lifetime basin: keep /GX and <stdlib.h>.
// The otherwise small header/context choice is part of the exact-match source model here,
// and it also preserves the original byte-load addressing family in the copy loop.
#include <stdlib.h>

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
};
#endif

DString DString::subString(int start, int count) {
    char* text;
    int copied;

    text = (char*)malloc(count + 1);
    copied = 0;
    if (start < this->lengthValue) {
        while (1) {
            if (copied >= count)
                break;
            text[copied] = this->stringValue[start];
            copied = copied + 1;
            start = start + 1;
            if (!(start < this->lengthValue))
                break;
        }
    }
    text[copied] = 0;
    DString rStr(text);
    return rStr;
}
