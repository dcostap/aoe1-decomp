#pragma once
#include "../common.h"

class DKeyString : public DString {
public:
    DString valueValue;                      // 0x14

    DKeyString();
    DKeyString(DString param_1, DString param_2);
    virtual ~DKeyString();
    virtual DString* key(DString* __return_storage_ptr__);
    virtual void setKey(DString param_1);
    virtual DString* value(DString* __return_storage_ptr__);
    virtual void setValue(DString param_1);
};

static_assert(sizeof(DKeyString) == 0x28, "DKeyString Size Mismatch");
static_assert(offsetof(DKeyString, valueValue) == 0x14, "DKeyString Offset Mismatch");

class DString {
public:
    int lengthValue;                         // 0x4
    int numWordsValue;                       // 0x8
    int indexValue;                          // 0xC
    int currentWordValue;                    // 0x10

    DString();
    DString(DString* param_1);
    DString(char* param_1);
    virtual ~DString();
    virtual DString* operator=(char* param_1);
    virtual DString* operator=(DString* param_1);
    virtual DString* operator+(DString* __return_storage_ptr__, DString* param_1);
    virtual char* operator[](int param_1);
    virtual char* operator_char*();
    virtual int length();
    virtual int index();
    virtual int contains(DString param_1);
    virtual int contains(char* param_1);
    virtual int numWords();
    virtual DString* word(DString* __return_storage_ptr__, int param_1);
    virtual DString* nextWord(DString* __return_storage_ptr__, int param_1);
    virtual void moveToFirstWord();
    virtual void moveToNextWord();
    virtual DString* subString(DString* __return_storage_ptr__, int param_1, int param_2);
    virtual void append(DString param_1);
    virtual DString* stripTrailing(DString* __return_storage_ptr__, char param_1);
    virtual DString* stripLeading(DString* __return_storage_ptr__, char param_1);
    virtual int asInt();
    virtual double asDouble();
    virtual void uppercase();
    virtual DString* asUppercase(DString* __return_storage_ptr__);
    virtual void lowercase();
    virtual DString* asLowercase(DString* __return_storage_ptr__);
    virtual void change(char param_1, char param_2);
};

static_assert(sizeof(DString) == 0x14, "DString Size Mismatch");
static_assert(offsetof(DString, currentWordValue) == 0x10, "DString Offset Mismatch");

