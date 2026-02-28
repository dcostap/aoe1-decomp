#pragma once
#include "common.h"
#include <iosfwd>

struct DString {
    DString();
    DString(const DString& param_1);
    DString(char const* param_1);
    ~DString();

    DString& operator=(char const* param_1);
    DString& operator=(const DString& param_1);
    DString operator+(const DString& param_1) const;
    char& operator[](int param_1);
    operator char*() const;

    int length() const;
    int index() const;
    int contains(DString param_1) const;
    int contains(char const* param_1) const;
    int numWords();
    DString word(int param_1);
    DString nextWord(int param_1);
    void moveToFirstWord();
    void moveToNextWord();
    DString subString(int param_1, int param_2);
    void append(DString param_1);
    DString stripTrailing(char param_1);
    DString stripLeading(char param_1);
    int asInt() const;
    double asDouble() const;
    void uppercase();
    DString asUppercase();
    void lowercase();
    DString asLowercase();
    void change(char param_1, char param_2);

    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;
};
static_assert(sizeof(DString) == 0x14, "Size mismatch");

std::ostream& operator<<(std::ostream& param_1, const DString& param_2);
std::istream& operator>>(std::istream& param_1, DString& param_2);
int operator==(const DString& param_1, const DString& param_2);
int operator==(const DString& param_1, char const* param_2);
int operator==(char const* param_1, const DString& param_2);
int operator!=(const DString& param_1, const DString& param_2);
int operator!=(const DString& param_1, char const* param_2);
int operator!=(char const* param_1, const DString& param_2);
int operator<(const DString& param_1, const DString& param_2);
int operator<(const DString& param_1, char const* param_2);
int operator<(char const* param_1, const DString& param_2);
int operator>(const DString& param_1, const DString& param_2);
int operator>(const DString& param_1, char const* param_2);
int operator>(char const* param_1, const DString& param_2);
