// tried the direct stripTrailing body under /GX first; mismatch stayed early in the prolog/register-choice basin around the trailing-scan setup
// kept a fuller donor-style dstring.cpp TU context after the target; that preserved the right high-level scan/call family and moved the function into a closer basin
// tried both a named `text` pointer and direct `(this->stringValue + index)[-N]` addressing; both collapsed to the same near-match with the remaining gap at the saved-`this` / temp-char register family
// leaving this in scratch because the remaining difference looks localized to register allocation and loop-head shaping in the trailing-scan setup while subString/operator=/dtor/copy-ctor boundaries still look right
#include <stdlib.h>
#include <string.h>
extern "C" int __cdecl isspace(int c);

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

DString DString::stripTrailing(char value) {
    char ch;
    int index;

    index = this->lengthValue;
    ch = (this->stringValue + index)[-1];
    for (; (ch == value && (0 < index)); index = index + -1) {
        ch = (this->stringValue + index)[-2];
    }
    *this = this->subString(0, index);
    return *this;
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
    this->lengthValue = other.lengthValue;
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, other.stringValue);
    } else {
        this->stringValue = 0;
    }
}

DString::DString(const char* value) {
    this->lengthValue = (int)strlen(value);
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, value);
    } else {
        this->stringValue = 0;
    }
}

DString::~DString() { if (stringValue != 0) free(stringValue); }
DString& DString::operator=(const char* value) { if (this->stringValue != 0) free(this->stringValue); this->numWordsValue = -1; this->indexValue = 0; this->currentWordValue = 0; this->lengthValue = (int)strlen(value); if (this->lengthValue > 0) { this->stringValue = (char*)malloc(this->lengthValue + 1); strcpy(this->stringValue, value); } else { this->stringValue = 0; } return *this; }
DString& DString::operator=(const DString& other) { if (this->stringValue != 0) free(this->stringValue); this->numWordsValue = other.numWordsValue; this->indexValue = other.indexValue; this->currentWordValue = other.currentWordValue; this->lengthValue = other.lengthValue; if (this->lengthValue > 0) { this->stringValue = (char*)malloc(this->lengthValue + 1); strcpy(this->stringValue, other.stringValue); } else { this->stringValue = 0; } return *this; }
char& DString::operator[](int index) { if ((index < 0) || (this->lengthValue < index + 1)) return this->stringValue[0]; return this->stringValue[index]; }
DString::operator char*() const { return this->stringValue; }
int DString::length() const { return this->lengthValue; }
int DString::numWords() { return this->numWordsValue; }
int DString::index() const { return this->indexValue; }
int DString::contains(DString value) const { return strstr(this->stringValue, value.stringValue) != 0; }
int DString::contains(const char* value) const { return strstr(this->stringValue, value) != 0; }
void DString::moveToFirstWord() { this->indexValue = 0; this->currentWordValue = 0; }
void DString::moveToNextWord() {}
DString DString::subString(int start, int count) { char* t=(char*)malloc(count+1); int c=0; if (start < this->lengthValue) { while (1) { if (c >= count) break; t[c]=this->stringValue[start]; c++; start++; if (!(start < this->lengthValue)) break; } } t[c]=0; DString r(t); return r; }
DString DString::word(int wordIndex) { return DString("<null>"); }
DString DString::nextWord(int updateIndex) { return DString("<null>"); }
void DString::append(DString value) { int i, baseLen; char* text; text=(char*)malloc(value.length()+this->lengthValue+1); i=0; if(this->lengthValue>0){ do { text[i]=this->stringValue[i]; i=i+1; } while(i<this->lengthValue);} baseLen=this->lengthValue; if(i<value.length()+baseLen){ do { text[i]=value[i-baseLen]; baseLen=this->lengthValue; i=i+1; } while(i<value.length()+baseLen);} text[i]=0; free(this->stringValue); this->stringValue=text; this->lengthValue=this->lengthValue+value.length(); this->numWordsValue=-1; this->indexValue=0; this->currentWordValue=0; }
DString DString::operator+(const DString& value) const { DString n(*this); n.append(value); return n; }
