#pragma once
#include "../common.h"

class DKeyString : public DString       {
public:
    DString keyValue;                        // 0x0
    DString valueValue;                      // 0x14

    DKeyString();
    DKeyString(DString param_1, DString param_2);

    // --- Non-Virtual Destructor ---
    ~DKeyString() noexcept(false);
    // --- Non-Virtual Members ---
    DString* key(DString* __return_storage_ptr__);
    void setKey(DString param_1);
    DString* value(DString* __return_storage_ptr__);
    void setValue(DString param_1);
};

static_assert(sizeof(DKeyString) == 0x28, "DKeyString Size Mismatch");
static_assert(offsetof(DKeyString, valueValue) == 0x14, "DKeyString Offset Mismatch");

class DString       {
public:
    char* stringValue;                       // 0x0
    int lengthValue;                         // 0x4
    int numWordsValue;                       // 0x8
    int indexValue;                          // 0xC
    int currentWordValue;                    // 0x10

    DString();
    DString(DString* param_1);
    DString(char* param_1);

    // --- Non-Virtual Destructor ---
    ~DString() noexcept(false);
    // --- Non-Virtual Members ---
    DString* operator=(char* param_1);
    DString* operator=(DString* param_1);
    DString* operator+(DString* __return_storage_ptr__, DString* param_1);
    char* operator[](int param_1);
    char* operator_char*();
    int length();
    int index();
    int contains(DString param_1);
    int contains(char* param_1);
    int numWords();
    DString* word(DString* __return_storage_ptr__, int param_1);
    DString* nextWord(DString* __return_storage_ptr__, int param_1);
    void moveToFirstWord();
    void moveToNextWord();
    DString* subString(DString* __return_storage_ptr__, int param_1, int param_2);
    void append(DString param_1);
    DString* stripTrailing(DString* __return_storage_ptr__, char param_1);
    DString* stripLeading(DString* __return_storage_ptr__, char param_1);
    int asInt();
    double asDouble();
    void uppercase();
    DString* asUppercase(DString* __return_storage_ptr__);
    void lowercase();
    DString* asLowercase(DString* __return_storage_ptr__);
    void change(char param_1, char param_2);
};

static_assert(sizeof(DString) == 0x14, "DString Size Mismatch");
static_assert(offsetof(DString, currentWordValue) == 0x10, "DString Offset Mismatch");

