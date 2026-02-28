#pragma once
#include "common.h"
#include "DString.h"

struct DKeyString {
    DKeyString();
    DKeyString(DString param_1, DString param_2);
    ~DKeyString();
    DString key() const;
    void setKey(DString param_1);
    DString value() const;
    void setValue(DString param_1);

    DString keyValue;
    DString valueValue;
};
static_assert(sizeof(DKeyString) == 0x28, "Size mismatch");
