#pragma once
#include "AIModuleID.h"

class AIModuleMessage {
public:
    AIModuleMessage();
    AIModuleMessage(int param_1, int param_2, int param_3, int param_4, long param_5, long param_6, long param_7, AIModuleMessage* param_8, int param_9);
    AIModuleMessage(AIModuleMessage* param_1);

    // Virtuals (best-effort)
    virtual ~AIModuleMessage(); // vt[0] (0x0)

    void setText(char* param_1);
    void setSender(int param_1, char* param_2);
    void setRecipient(int param_1, char* param_2);
    void* scalar_deleting_destructor(uint param_1);

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
