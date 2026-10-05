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
    this->stringValue = (char*) malloc(1);
    strcpy(this->stringValue, "");
}

DString::DString(const DString& d) {
    this->lengthValue = d.lengthValue;
    this->numWordsValue = d.numWordsValue;
    this->indexValue = d.indexValue;
    this->currentWordValue = d.currentWordValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*) malloc(this->lengthValue + 1);
        strcpy(this->stringValue, d.stringValue);
    } else {
        this->stringValue = 0;
    }
}

DString::DString(const char* s) {
    this->lengthValue = (int) strlen(s);
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    if (this->lengthValue > 0) {
        this->stringValue = (char*) malloc(this->lengthValue + 1);
        strcpy(this->stringValue, s);
    } else {
        this->stringValue = 0;
    }
}

DString::~DString() {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
}

ostream& __cdecl operator<<(ostream& out, const DString& d) {
    if (d.stringValue != 0) {
        out << d.stringValue;
    }
    return out;
}

DString& DString::operator=(const char* s) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->lengthValue = (int) strlen(s);
    if (this->lengthValue > 0) {
        this->stringValue = (char*) malloc(this->lengthValue + 1);
        strcpy(this->stringValue, s);
    } else {
        this->stringValue = 0;
    }
    return *this;
}

DString& DString::operator=(const DString& d) {
    if (this->stringValue != 0) {
        free(this->stringValue);
    }
    this->numWordsValue = d.numWordsValue;
    this->indexValue = d.indexValue;
    this->currentWordValue = d.currentWordValue;
    this->lengthValue = d.lengthValue;
    if (this->lengthValue > 0) {
        this->stringValue = (char*) malloc(this->lengthValue + 1);
        strcpy(this->stringValue, d.stringValue);
    } else {
        this->stringValue = 0;
    }
    return *this;
}

int __cdecl operator==(const DString& one, const DString& two) {
    return strcmp(one.stringValue, two.stringValue) == 0;
}

int __cdecl operator==(const DString& one, const char* two) {
    return strcmp(one.stringValue, two) == 0;
}

int __cdecl operator==(const char* one, const DString& two) {
    return strcmp(one, two.stringValue) == 0;
}

int __cdecl operator!=(const DString& one, const DString& two) {
    return strcmp(one.stringValue, two.stringValue) != 0;
}

int __cdecl operator!=(const DString& one, const char* two) {
    return strcmp(one.stringValue, two) != 0;
}

int __cdecl operator!=(const char* one, const DString& two) {
    return strcmp(one, two.stringValue) != 0;
}

int __cdecl operator<(const DString& one, const DString& two) {
    return strcmp(one.stringValue, two.stringValue) < 0;
}

int __cdecl operator<(const DString& one, const char* two) {
    return strcmp(one.stringValue, two) < 0;
}

int __cdecl operator<(const char* one, const DString& two) {
    return strcmp(one, two.stringValue) < 0;
}

int __cdecl operator>(const DString& one, const DString& two) {
    return strcmp(one.stringValue, two.stringValue) > 0;
}

int __cdecl operator>(const DString& one, const char* two) {
    return strcmp(one.stringValue, two) > 0;
}

int __cdecl operator>(const char* one, const DString& two) {
    return strcmp(one, two.stringValue) > 0;
}

DString DString::operator+(const DString& d) const {
    DString newStr(*this);

    newStr.append(d);
    return newStr;
}

char& DString::operator[](int i) {
    if (i < 0 || this->lengthValue < i + 1)
        return this->stringValue[0];
    return this->stringValue[i];
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

int DString::contains(DString s) const {
    if (strstr(this->stringValue, s) != 0) {
        return 1;
    }
    return 0;
}

int DString::contains(const char* s) const {
    return strstr(this->stringValue, s) != 0;
}

int DString::numWords() {
    int cached;
    int index;
    int in_word;

    cached = this->numWordsValue;
    if (cached == -1) {
        cached = this->lengthValue;
        if (cached == 0) {
            return cached;
        }

        if (this->stringValue[0] == ' ') {
            this->numWordsValue = 0;
            in_word = 0;
        } else {
            this->numWordsValue = 1;
            in_word = 1;
        }

        index = 0;
        if (cached > 0) {
            do {
                if (!in_word) {
                    if (isspace((int) this->stringValue[index])) {
                        goto still_in_gap;
                    }
                    cached = this->numWordsValue;
                    in_word = 1;
                    cached = cached + 1;
                    this->numWordsValue = cached;
                    goto next_index;
                }

            still_in_gap:
                if (isspace((int) this->stringValue[index])) {
                    in_word = 0;
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

DString DString::word(int num) {
    int word_count;
    int index;
    int in_word;

    if ((num <= this->numWords()) && (num >= 1)) {
        if (num == this->currentWordValue + 1) {
            this->currentWordValue = this->currentWordValue + 1;
            return this->nextWord(1);
        }

        index = 0;
        in_word = 0;
        word_count = 0;

        for (; word_count != num; index = index + 1) {
            if (index >= this->lengthValue)
                break;
            if (!in_word) {
                if (isspace((int) this->stringValue[index])) {
                    goto still_in_gap;
                }
                word_count = word_count + 1;
                in_word = 1;
                goto next_index;
            }
        still_in_gap:
            if (isspace((int) this->stringValue[index])) {
                in_word = 0;
            }
        next_index:;
        }

        if (word_count == num) {
            int start;

            start = index - 1;
            while ((isspace((int) this->stringValue[index]) == 0) && (index < this->lengthValue)) {
                index = index + 1;
            }
            DString rStr = this->subString(start, index - start);
            return rStr;
        }
    }

    return DString("");
}

istream& __cdecl operator>>(istream& in, DString& d) {
    char buffer[256];

    in.getline(buffer, 0x100);
    d = buffer;
    return in;
}

DString DString::nextWord(int incIndex) {
    int i;
    int start;

    i = this->indexValue;
    while ((isspace((int) this->stringValue[i]) != 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    start = i;
    while ((isspace((int) this->stringValue[i]) == 0) && (i < this->lengthValue)) {
        i = i + 1;
    }
    if (incIndex != 0) {
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
    while ((isspace((int) this->stringValue[this->indexValue]) != 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }

    while ((isspace((int) this->stringValue[this->indexValue]) == 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }
}

DString DString::subString(int start, int count) {
    char* text;
    int copied;

    text = (char*) malloc(count + 1);
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

void DString::append(DString d) {
    int i;
    int base_len;
    char* text;

    text = (char*) malloc(d.length() + this->lengthValue + 1);
    i = 0;
    if (this->lengthValue > 0) {
        do {
            text[i] = this->stringValue[i];
            i = i + 1;
        } while (i < this->lengthValue);
    }
    base_len = this->lengthValue;
    if (i < d.length() + base_len) {
        do {
            text[i] = d[i - base_len];
            base_len = this->lengthValue;
            i = i + 1;
        } while (i < d.length() + base_len);
    }
    text[i] = 0;
    free(this->stringValue);
    this->stringValue = text;
    this->lengthValue = this->lengthValue + d.length();
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
}

DString DString::stripTrailing(char c) {
    int index;

    index = this->lengthValue;
    while ((this->stringValue[index - 1] == c) && (0 < index)) {
        index = index - 1;
    }
    *this = this->subString(0, index);
    return *this;
}

DString DString::stripLeading(char c) {
    int index;

    index = 0;
    if (this->stringValue[0] == c) {
        while (1) {
            if (index >= this->lengthValue)
                break;
            index = index + 1;
            if (this->stringValue[index] != c)
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
            this->stringValue[index] = (char) toupper((int) this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}

DString DString::asUppercase() {
    DString rStr(this->stringValue);

    rStr.uppercase();
    return rStr;
}

void DString::lowercase() {
    int index;

    index = 0;
    if (this->length() > 0) {
        do {
            this->stringValue[index] = (char) tolower((int) this->stringValue[index]);
            index = index + 1;
        } while (index < this->length());
    }
}

DString DString::asLowercase() {
    DString rStr(this->stringValue);

    rStr.lowercase();
    return rStr;
}

void DString::change(char o, char n) {
    long i;

    i = 0;
    if (this->lengthValue > 0) {
        do {
            if (this->stringValue[i] == o) {
                this->stringValue[i] = n;
            }
            i = i + 1;
        } while (i < this->lengthValue);
    }
}

DKeyString::DKeyString() : keyValue(""), valueValue("") {
}

DKeyString::DKeyString(DString k, DString v) : keyValue(k), valueValue(v) {
}

DKeyString::~DKeyString() {
}

DString DKeyString::key() const {
    return this->keyValue;
}

void DKeyString::setKey(DString k) {
    this->keyValue = k;
}

DString DKeyString::value() const {
    return this->valueValue;
}

void DKeyString::setValue(DString v) {
    this->valueValue = v;
}
