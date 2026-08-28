#include "../include/dstring.h"

#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

DString::~DString() {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
}

ostream& __cdecl operator<<(ostream& stream, const DString& value) {
    if (value.stringValue != 0) {
        stream << value.stringValue;
    }
    return stream;
}

DString& DString::operator=(const char* value) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->lengthValue = (int)strlen(value);
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, value);
    } else {
        this->stringValue = 0;
    }
    return *this;
}

DString& DString::operator=(const DString& other) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = other.numWordsValue;
    this->indexValue = other.indexValue;
    this->currentWordValue = other.currentWordValue;
    this->lengthValue = other.lengthValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*)malloc(this->lengthValue + 1);
        strcpy(this->stringValue, other.stringValue);
    } else {
        this->stringValue = 0;
    }
    return *this;
}

int __cdecl operator==(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) == 0;
}

int __cdecl operator==(const DString& lhs, const char* rhs) {
    return strcmp(lhs.stringValue, rhs) == 0;
}

int __cdecl operator==(const char* lhs, const DString& rhs) {
    return strcmp(lhs, rhs.stringValue) == 0;
}

int __cdecl operator!=(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) != 0;
}

int __cdecl operator!=(const DString& lhs, const char* rhs) {
    return strcmp(lhs.stringValue, rhs) != 0;
}

int __cdecl operator!=(const char* lhs, const DString& rhs) {
    return strcmp(lhs, rhs.stringValue) != 0;
}

int __cdecl operator<(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) < 0;
}

int __cdecl operator<(const DString& lhs, const char* rhs) {
    return strcmp(lhs.stringValue, rhs) < 0;
}

int __cdecl operator<(const char* lhs, const DString& rhs) {
    return strcmp(lhs, rhs.stringValue) < 0;
}

int __cdecl operator>(const DString& lhs, const DString& rhs) {
    return strcmp(lhs.stringValue, rhs.stringValue) > 0;
}

int __cdecl operator>(const DString& lhs, const char* rhs) {
    return strcmp(lhs.stringValue, rhs) > 0;
}

int __cdecl operator>(const char* lhs, const DString& rhs) {
    return strcmp(lhs, rhs.stringValue) > 0;
}

DString DString::operator+(const DString& value) const {
    DString newStr(*this);

    newStr.append(value);
    return newStr;
}

char& DString::operator[](int index) {
    if (index < 0 || this->lengthValue < index + 1)
        return this->stringValue[0];
    return this->stringValue[index];
}

DString::operator char*() const {
    return this->stringValue;
}

int DString::length() const {
    return this->lengthValue;
}

int DString::index() const {
    return this->indexValue;
}

int DString::contains(DString value) const {
    if (strstr(this->stringValue, value) != 0) {
        return 1;
    }
    return 0;
}

int DString::contains(const char* value) const {
    return strstr(this->stringValue, value) != 0;
}

int DString::numWords() {
    int cached;
    int index;
    int inWord;

    cached = this->numWordsValue;
    if (cached == -1) {
        cached = this->lengthValue;
        if (cached == 0) {
            return cached;
        }

        if (this->stringValue[0] == ' ') {
            this->numWordsValue = 0;
            inWord = 0;
        } else {
            this->numWordsValue = 1;
            inWord = 1;
        }

        index = 0;
        if (cached > 0) {
            do {
                if (!inWord) {
                    if (isspace((int)this->stringValue[index])) {
                        goto still_in_gap;
                    }
                    cached = this->numWordsValue;
                    inWord = 1;
                    cached = cached + 1;
                    this->numWordsValue = cached;
                    goto next_index;
                }

still_in_gap:
                if (isspace((int)this->stringValue[index])) {
                    inWord = 0;
                }

next_index:
                cached = this->lengthValue;
                index = index + 1;
            } while (index < cached);
        }

        cached = this->numWordsValue;
    }

    return cached;
}

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
                if (isspace((int)this->stringValue[index])) {
                    goto still_in_gap;
                }
                wordCount = wordCount + 1;
                inWord = 1;
                goto next_index;
            }
still_in_gap:
            if (isspace((int)this->stringValue[index])) {
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

istream& __cdecl operator>>(istream& stream, DString& value) {
    char buffer[256];

    stream.get(buffer, 0x100);
    value = buffer;
    return stream;
}

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

void DString::moveToFirstWord() {
    this->indexValue = 0;
    this->currentWordValue = 0;
}

void DString::moveToNextWord() {
    while ((isspace((int)this->stringValue[this->indexValue]) != 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }

    while ((isspace((int)this->stringValue[this->indexValue]) == 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }
}

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

DString DString::stripTrailing(char value) {
    int index;

    index = this->lengthValue;
    while ((this->stringValue[index - 1] == value) && (0 < index)) {
        index = index - 1;
    }
    *this = this->subString(0, index);
    return *this;
}

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

int DString::asInt() const {
    return atoi(this->stringValue);
}

double DString::asDouble() const {
    return atof(this->stringValue);
}

void DString::uppercase() {
    int index;

    index = 0;
    if (this->length() > 0) {
        do {
            this->stringValue[index] = (char)toupper((int)this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}

DString DString::asUppercase() {
    DString result(this->stringValue);

    result.uppercase();
    return result;
}

void DString::lowercase() {
    int index;

    index = 0;
    if (this->length() > 0) {
        do {
            this->stringValue[index] = (char)tolower((int)this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}

DString DString::asLowercase() {
    DString result(this->stringValue);

    result.lowercase();
    return result;
}

void DString::change(char from, char to) {
    long i;

    i = 0;
    if (this->lengthValue > 0) {
        do {
            if (this->stringValue[i] == from) {
                this->stringValue[i] = to;
            }
            i = i + 1;
        } while (i < this->lengthValue);
    }
}

DKeyString::DKeyString() : keyValue(""), valueValue("") {}

DKeyString::DKeyString(DString key, DString value)
    : keyValue(key), valueValue(value) {}

DKeyString::~DKeyString() {}

DString DKeyString::key() const {
    return this->keyValue;
}

void DKeyString::setKey(DString key) {
    this->keyValue = key;
}

DString DKeyString::value() const {
    return this->valueValue;
}

void DKeyString::setValue(DString value) {
    this->valueValue = value;
}
