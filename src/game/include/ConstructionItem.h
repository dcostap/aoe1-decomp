#pragma once
#include "common.h"

class ConstructionItem {
public:
    // Virtuals (best-effort)
    virtual ~ConstructionItem(); // vt[0] (0x0)

    int padding0;
    int padding1;
    int padding2;
    int padding3;
    int padding4;
    int padding5;
    int padding6;
    int padding7;
    int padding8;
    int padding9;
    int padding10;
    int padding11;
    int padding12;
    int padding13;
    int padding14;
    int padding15;
    int padding16;
    int padding17;
    int padding18;
    int padding19;
    int padding20;
    int padding21;
    int padding22;
    int padding23;
    int padding24;
    int padding25;
    ConstructionItem* next;
    ConstructionItem* prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};
static_assert(sizeof(ConstructionItem) == 0x80, "Size mismatch");
