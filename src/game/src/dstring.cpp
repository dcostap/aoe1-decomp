#include "../include/DString.h"
#include "../include/DKeyString.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

static const char s_empty[] = "";

static int dstring_compare(const char* lhs, const char* rhs) {
    unsigned char bVar1;
    bool bVar2;
    while (true) {
        bVar1 = (unsigned char)*lhs;
        bVar2 = bVar1 < (unsigned char)*rhs;
        if (bVar1 != (unsigned char)*rhs) break;
        if (bVar1 == 0) return 0;
        bVar1 = (unsigned char)lhs[1];
        bVar2 = bVar1 < (unsigned char)rhs[1];
        if (bVar1 != (unsigned char)rhs[1]) break;
        lhs += 2;
        rhs += 2;
        if (bVar1 == 0) return 0;
    }
    return (1 - (int)bVar2) - (int)(bVar2 != 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004465D0
DString::DString() {
    this->stringValue = (char*)malloc(1);
    this->lengthValue = 0;
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    if (this->stringValue != nullptr) {
        this->stringValue[0] = '\0';
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446620
DString::DString(const DString& param_1) {
    this->lengthValue = param_1.lengthValue;
    this->numWordsValue = param_1.numWordsValue;
    this->indexValue = param_1.indexValue;
    this->currentWordValue = param_1.currentWordValue;
    if (this->lengthValue < 1) {
        this->stringValue = nullptr;
        return;
    }
    this->stringValue = (char*)malloc(this->lengthValue + 1);
    if (this->stringValue != nullptr) {
        strcpy(this->stringValue, param_1.stringValue);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446690
DString::DString(const char* param_1) {
    int iVar4 = (int)strlen(param_1);
    this->numWordsValue = -1;
    this->lengthValue = iVar4;
    this->indexValue = 0;
    this->currentWordValue = 0;
    if (iVar4 < 1) {
        this->stringValue = nullptr;
        return;
    }
    this->stringValue = (char*)malloc((size_t)iVar4 + 1);
    if (this->stringValue != nullptr) {
        strcpy(this->stringValue, param_1);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446700
DString::~DString() {
    if (this->stringValue != nullptr) {
        free(this->stringValue);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446710
std::ostream& operator<<(std::ostream& param_1, const DString& param_2) {
    if (param_2.stringValue != nullptr) {
        param_1 << param_2.stringValue;
    }
    return param_1;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446730
std::istream& operator>>(std::istream& param_1, DString& param_2) {
    char buffer[0x100];
    param_1.get(buffer, 0x100, '\n');
    param_2 = buffer;
    return param_1;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446780
DString& DString::operator=(const char* param_1) {
    if (this->stringValue != nullptr) {
        free(this->stringValue);
    }
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
    this->lengthValue = (int)strlen(param_1);
    if (this->lengthValue < 1) {
        this->stringValue = nullptr;
        return *this;
    }
    this->stringValue = (char*)malloc((size_t)this->lengthValue + 1);
    if (this->stringValue != nullptr) {
        strcpy(this->stringValue, param_1);
    }
    return *this;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446800
DString& DString::operator=(const DString& param_1) {
    if (this->stringValue != nullptr) {
        free(this->stringValue);
    }
    this->numWordsValue = param_1.numWordsValue;
    this->indexValue = param_1.indexValue;
    this->currentWordValue = param_1.currentWordValue;
    this->lengthValue = param_1.lengthValue;
    if (this->lengthValue < 1) {
        this->stringValue = nullptr;
        return *this;
    }
    this->stringValue = (char*)malloc((size_t)this->lengthValue + 1);
    if (this->stringValue != nullptr) {
        strcpy(this->stringValue, param_1.stringValue);
    }
    return *this;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446880
int operator==(const DString& param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2.stringValue) == 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004468E0
int operator==(const DString& param_1, const char* param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2) == 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446930
int operator==(const char* param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1, param_2.stringValue) == 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446980
int operator!=(const DString& param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2.stringValue) != 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004469E0
int operator!=(const DString& param_1, const char* param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2) != 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446A30
int operator!=(const char* param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1, param_2.stringValue) != 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446A80
int operator<(const DString& param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2.stringValue) < 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446AE0
int operator<(const DString& param_1, const char* param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2) < 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446B30
int operator<(const char* param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1, param_2.stringValue) < 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446B80
int operator>(const DString& param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2.stringValue) > 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446BE0
int operator>(const DString& param_1, const char* param_2) {
    return (uint)(dstring_compare(param_1.stringValue, param_2) > 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446C30
int operator>(const char* param_1, const DString& param_2) {
    return (uint)(dstring_compare(param_1, param_2.stringValue) > 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446C80
DString DString::operator+(const DString& param_1) const {
    DString newStr(*this);
    newStr.append(param_1);
    return newStr;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446D10
char& DString::operator[](int param_1) {
    if ((-1 < param_1) && (param_1 + 1 <= this->lengthValue)) {
        return this->stringValue[param_1];
    }
    return this->stringValue[0];
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446D30
DString::operator char*() const {
    return this->stringValue;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446D40
int DString::length() const {
    return this->lengthValue;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446D50
int DString::index() const {
    return this->indexValue;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446D60
int DString::contains(DString param_1) const {
    const char* pcVar1 = param_1;
    int iVar2 = (strstr(this->stringValue, pcVar1) != 0);
    return iVar2;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446DE0
int DString::contains(const char* param_1) const {
    int iVar1 = (strstr(this->stringValue, param_1) != 0);
    return (uint)(iVar1 != 0);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446E00
int DString::numWords() {
    int iVar1 = this->numWordsValue;
    if (iVar1 == -1) {
        iVar1 = this->lengthValue;
        if (iVar1 == 0) {
            return iVar1;
        }
        bool bVar3 = *this->stringValue != ' ';
        this->numWordsValue = bVar3 ? 1 : 0;
        int iVar2 = 0;
        if (0 < iVar1) {
            do {
                if (bVar3) {
                    iVar1 = isspace((int)this->stringValue[iVar2]);
                    if (iVar1 != 0) {
                        bVar3 = false;
                    }
                } else {
                    iVar1 = isspace((int)this->stringValue[iVar2]);
                    if (iVar1 == 0) {
                        bVar3 = true;
                        this->numWordsValue = this->numWordsValue + 1;
                    }
                }
                iVar2 = iVar2 + 1;
            } while (iVar2 < this->lengthValue);
        }
        iVar1 = this->numWordsValue;
    }
    return iVar1;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446E90
DString DString::word(int param_1) {
    int iVar4 = 0;
    DString rStr;
    int iVar2 = this->numWords();
    if ((param_1 <= iVar2) && (0 < param_1)) {
        iVar2 = this->currentWordValue + 1;
        if (param_1 == iVar2) {
            this->currentWordValue = iVar2;
            return this->nextWord(1);
        }
        iVar2 = 0;
        bool bVar1 = false;
        if (param_1 != 0) {
            do {
                if (this->lengthValue <= iVar2) break;
                if ((bVar1) || (isspace((int)this->stringValue[iVar2]) != 0)) {
                    if (isspace((int)this->stringValue[iVar2]) != 0) {
                        bVar1 = false;
                    }
                } else {
                    iVar4 = iVar4 + 1;
                    bVar1 = true;
                }
                iVar2 = iVar2 + 1;
            } while (iVar4 != param_1);
        }
        if (iVar4 == param_1) {
            iVar4 = iVar2 - 1;
            while ((isspace((int)this->stringValue[iVar2]) == 0) && (iVar2 < this->lengthValue)) {
                iVar2 = iVar2 + 1;
            }
            rStr = this->subString(iVar4, iVar2 - iVar4);
            return DString(rStr);
        }
    }
    return DString(s_empty);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00446FD0
DString DString::nextWord(int param_1) {
    DString rStr;
    int iVar3 = this->indexValue;
    while ((isspace((int)this->stringValue[iVar3]) != 0) && (iVar3 < this->lengthValue)) {
        iVar3 = iVar3 + 1;
    }
    int iVar1 = iVar3;
    while ((isspace((int)this->stringValue[iVar1]) == 0) && (iVar1 < this->lengthValue)) {
        iVar1 = iVar1 + 1;
    }
    if (param_1 != 0) {
        this->indexValue = iVar1;
    }
    rStr = this->subString(iVar3, iVar1 - iVar3);
    return DString(rStr);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004470B0
void DString::moveToFirstWord() {
    this->indexValue = 0;
    this->currentWordValue = 0;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004470C0
void DString::moveToNextWord() {
    while ((isspace((int)this->stringValue[this->indexValue]) != 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }
    while ((isspace((int)this->stringValue[this->indexValue]) == 0) && (this->indexValue < this->lengthValue)) {
        this->indexValue = this->indexValue + 1;
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447140
DString DString::subString(int param_1, int param_2) {
    char* pcVar2 = (char*)malloc((size_t)param_2 + 1);
    int iVar3 = 0;
    int iVar4 = 0;
    if (param_1 < this->lengthValue) {
        do {
            iVar4 = iVar3;
            if (param_2 <= iVar3) break;
            iVar4 = iVar3 + 1;
            pcVar2[iVar3] = this->stringValue[param_1];
            param_1 = param_1 + 1;
            iVar3 = iVar4;
        } while (param_1 < this->lengthValue);
    }
    pcVar2[iVar4] = '\0';
    DString rStr(pcVar2);
    return DString(rStr);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004471F0
void DString::append(DString param_1) {
    int iVar5 = 0;
    int iVar1 = param_1.length();
    char* pcVar2 = (char*)malloc((size_t)(iVar1 + 1 + this->lengthValue));
    iVar1 = iVar5;
    if (0 < this->lengthValue) {
        do {
            iVar5 = iVar1 + 1;
            pcVar2[iVar1] = this->stringValue[iVar1];
            iVar1 = iVar5;
        } while (iVar5 < this->lengthValue);
    }
    iVar1 = this->lengthValue;
    int iVar3 = param_1.length();
    if (iVar5 < iVar3 + iVar1) {
        do {
            pcVar2[iVar5] = param_1[iVar5 - iVar1];
            iVar1 = this->lengthValue;
            iVar5 = iVar5 + 1;
            iVar3 = param_1.length();
        } while (iVar5 < iVar3 + iVar1);
    }
    pcVar2[iVar5] = '\0';
    free(this->stringValue);
    this->stringValue = pcVar2;
    this->lengthValue = this->lengthValue + param_1.length();
    this->numWordsValue = -1;
    this->indexValue = 0;
    this->currentWordValue = 0;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004472D0
DString DString::stripTrailing(char param_1) {
    int iVar2 = this->lengthValue;
    char* pcVar4 = this->stringValue + iVar2;
    while ((*((pcVar4)-1) == param_1) && (0 < iVar2)) {
        iVar2 = iVar2 - 1;
        pcVar4 = pcVar4 - 1;
    }
    DString local_20 = this->subString(0, iVar2);
    this->operator=(local_20);
    return DString(*this);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447370
DString DString::stripLeading(char param_1) {
    int iVar1 = 0;
    if (*this->stringValue == param_1) {
        do {
            if (this->lengthValue <= iVar1) break;
            iVar1 = iVar1 + 1;
        } while (this->stringValue[iVar1] == param_1);
    }
    DString local_20 = this->subString(iVar1, this->lengthValue);
    this->operator=(local_20);
    return DString(*this);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447400
int DString::asInt() const {
    return atoi(this->stringValue);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447410
double DString::asDouble() const {
    return atof(this->stringValue);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447420
void DString::uppercase() {
    int iVar3 = 0;
    int iVar2 = this->length();
    if (0 < iVar2) {
        do {
            this->stringValue[iVar3] = (char)toupper((int)this->stringValue[iVar3]);
            iVar3 = iVar3 + 1;
            iVar2 = this->length();
        } while (iVar3 < iVar2);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447460
DString DString::asUppercase() {
    DString rStr(this->stringValue);
    rStr.uppercase();
    return DString(rStr);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004474E0
void DString::lowercase() {
    int iVar3 = 0;
    int iVar2 = this->length();
    if (0 < iVar2) {
        do {
            this->stringValue[iVar3] = (char)tolower((int)this->stringValue[iVar3]);
            iVar3 = iVar3 + 1;
            iVar2 = this->length();
        } while (iVar3 < iVar2);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447520
DString DString::asLowercase() {
    DString rStr(this->stringValue);
    rStr.lowercase();
    return DString(rStr);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004475A0
void DString::change(char param_1, char param_2) {
    int iVar1 = 0;
    if (0 < this->lengthValue) {
        do {
            if (this->stringValue[iVar1] == param_1) {
                this->stringValue[iVar1] = param_2;
            }
            iVar1 = iVar1 + 1;
        } while (iVar1 < this->lengthValue);
    }
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004475D0
DKeyString::DKeyString() : keyValue(s_empty), valueValue(s_empty) {}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447620
DKeyString::DKeyString(DString param_1, DString param_2) : keyValue(param_1), valueValue(param_2) {}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004476A0
DKeyString::~DKeyString() {}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x004476F0
DString DKeyString::key() const {
    return DString(this->keyValue);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447710
void DKeyString::setKey(DString param_1) {
    this->keyValue = param_1;
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447760
DString DKeyString::value() const {
    return DString(this->valueValue);
}

// Fully verified. Source of truth: dstring.cpp.decomp @ 0x00447780
void DKeyString::setValue(DString param_1) {
    this->valueValue = param_1;
}
