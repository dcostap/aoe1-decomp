#include <stdlib.h>

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const char* value);
    ~DString();
    char& operator[](int param_1);
    operator char*() const;
    int length(void) const;
    int numWords(void);
    int index(void) const;
    char* word(int wordIndex);
    char* nextWord(void);
};
#endif

char& DString::operator[](int param_1) {
    if (param_1 < 0 || this->lengthValue < param_1 + 1)
        return this->stringValue[0];
    return this->stringValue[param_1];
}
