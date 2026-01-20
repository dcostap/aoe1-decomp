#pragma once
#include "common.h"

struct DString {
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;
};
static_assert(sizeof(DString) == 0x14, "Size mismatch");
