#pragma once
#include "common.h"

class AIModuleMessage {
public:
    // Virtuals (best-effort)
    virtual ~AIModuleMessage(); // vt[0] (0x0)

    int id;
    char text[128];
    int priority;
    AIModuleID sender;
    AIModuleID recipient;
    long data1;
    long data2;
    long data3;
    AIModuleMessage* callbackMessage;
    int timeStamp;
    AIModuleMessage* next;
    AIModuleMessage* prev;
};
static_assert(sizeof(AIModuleMessage) == 0x138, "Size mismatch");
