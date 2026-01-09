#pragma once
#include "common.h"

class DKeyString {
public:
    DString keyValue;                        // 0x0
    DString valueValue;                      // 0x14

    DKeyString();
    DKeyString(DString param_1, DString param_2);
    ~DKeyString();
    DString* key();
    void setKey(DString param_1);
    DString* value();
    void setValue(DString param_1);
};

static_assert(sizeof(DKeyString) == 0x28, "DKeyString Size Mismatch");

class DString {
public:
    char* stringValue;                       // 0x0
    int lengthValue;                         // 0x4
    int numWordsValue;                       // 0x8
    int indexValue;                          // 0xC
    int currentWordValue;                    // 0x10

    DString();
    DString(DString* param_1);
    DString(char* param_1);
    ~DString();
    DString* operator=(char* param_1);
    DString* operator=(DString* param_1);
    DString* operator+(DString* param_1);
    char* operator[](int param_1);
    char* operator_char*();
    int length();
    int index();
    int contains(DString param_1);
    int contains(char* param_1);
    int numWords();
    DString* word(int param_1);
    DString* nextWord(int param_1);
    void moveToFirstWord();
    void moveToNextWord();
    DString* subString(int param_1, int param_2);
    void append(DString param_1);
    DString* stripTrailing(char param_1);
    DString* stripLeading(char param_1);
    int asInt();
    double asDouble();
    void uppercase();
    DString* asUppercase();
    void lowercase();
    DString* asLowercase();
    void change(char param_1, char param_2);
};

static_assert(sizeof(DString) == 0x14, "DString Size Mismatch");

