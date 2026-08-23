// Matches in a fuller donor-style dstring.cpp translation-unit context under /GX.
// Keep this target function lexically first so the object extractor sees the correct bytes.
// The neighboring declarations/definitions below are part of the proven VC5 context that
// flips the destination-byte stores into the original addressing family.
#include <stdlib.h>
#include <string.h>

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

DString::DString() {
    this->stringValue = 0;
    this->lengthValue = 0;
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->stringValue = (char*)malloc(1);
    strcpy(this->stringValue, "");
}

DString::DString(const DString& other) {
    this->stringValue = other.stringValue;
    this->lengthValue = other.lengthValue;
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
}

DString::DString(const char* value) {
    this->stringValue = (char*)value;
    this->lengthValue = value == 0 ? 0 : (int)strlen(value);
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
}

DString::~DString() {
}

DString& DString::operator=(const char* value) {
    this->stringValue = (char*)value;
    this->lengthValue = value == 0 ? 0 : (int)strlen(value);
    return *this;
}

DString& DString::operator=(const DString& other) {
    this->stringValue = other.stringValue;
    this->lengthValue = other.lengthValue;
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
    return *this;
}

char& DString::operator[](int param_1) {
    if ((-1 < param_1) && (param_1 + 1 <= this->lengthValue)) {
        return this->stringValue[param_1];
    }
    return this->stringValue[0];
}

DString::operator char*() const {
    return this->stringValue;
}

int DString::length() const {
    return this->lengthValue;
}

int DString::numWords() {
    return this->numWordsValue;
}

int DString::index() const {
    return this->indexValue;
}

int DString::contains(DString value) const {
    return strstr(this->stringValue, value.stringValue) != 0;
}

int DString::contains(const char* value) const {
    return strstr(this->stringValue, value) != 0;
}

DString DString::word(int wordIndex) {
    return DString("<null>");
}

DString DString::nextWord(int updateIndex) {
    return DString("<null>");
}

void DString::moveToFirstWord() {
    this->indexValue = 0;
    this->currentWordValue = 0;
}

void DString::moveToNextWord() {
}

DString DString::subString(int start, int count) {
    char* t = (char*)malloc(count + 1);
    int c = 0;

    if (start < this->lengthValue) {
        while (1) {
            if (c >= count) {
                break;
            }
            t[c] = this->stringValue[start];
            c++;
            start++;
            if (!(start < this->lengthValue)) {
                break;
            }
        }
    }
    t[c] = 0;
    DString r(t);
    return r;
}

DString DString::operator+(const DString& value) const {
    DString n(*this);
    n.append(value);
    return n;
}
