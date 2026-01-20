#pragma once
#include "common.h"

class ConstructionItem {
public:
    // Virtuals (best-effort)
    virtual ~ConstructionItem(); // vt[0] (0x0)

    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    int padding;
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};
static_assert(sizeof(ConstructionItem) == 0x80, "Size mismatch");
