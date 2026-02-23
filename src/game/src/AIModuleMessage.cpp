#include "../include/AIModuleMessage.h"

#include <new>
#include <string.h>

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040DE70
AIModuleMessage::AIModuleMessage()
    : sender((char*)"Sender", 0),
      recipient((char*)"Recipient", 0) {
    this->id = 0;
    this->priority = 0;
    this->data1 = 0;
    this->data2 = 0;
    this->data3 = 0;
    this->callbackMessage = nullptr;
    this->timeStamp = 0;
    this->next = nullptr;
    this->prev = nullptr;
    this->text[0] = '\0';
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040DF50
AIModuleMessage::AIModuleMessage(int param_1, int param_2, int param_3, int param_4, long param_5, long param_6, long param_7, AIModuleMessage* param_8, int param_9)
    : sender((char*)"", param_1),
      recipient((char*)"", param_2) {
    this->priority = param_4;
    this->id = param_3;
    this->data1 = param_5;
    this->data2 = param_6;
    this->data3 = param_7;
    this->callbackMessage = param_8;
    this->timeStamp = param_9;
    this->next = nullptr;
    this->prev = nullptr;
    this->text[0] = '\0';
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E030
AIModuleMessage::AIModuleMessage(AIModuleMessage* param_1)
    : sender(param_1->sender.name, param_1->sender.id),
      recipient(param_1->recipient.name, param_1->recipient.id) {
    this->id = param_1->id;
    this->priority = param_1->priority;
    this->data1 = param_1->data1;
    this->data2 = param_1->data2;
    this->data3 = param_1->data3;
    this->callbackMessage = param_1->callbackMessage;
    this->timeStamp = param_1->timeStamp;
    this->next = nullptr;
    this->prev = nullptr;
    this->setText(param_1->text);
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E120
AIModuleMessage::~AIModuleMessage() {
    if (this->callbackMessage != nullptr) {
        delete this->callbackMessage;
        this->callbackMessage = nullptr;
    }
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E190
void AIModuleMessage::setText(char* param_1) {
    if (param_1 != nullptr) {
        strncpy(this->text, param_1, 0x7F);
        return;
    }
    this->text[0] = '\0';
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E1E0
void AIModuleMessage::setSender(int param_1, char* param_2) {
    this->sender.setID(param_1, param_2);
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040E200
void AIModuleMessage::setRecipient(int param_1, char* param_2) {
    this->recipient.setID(param_1, param_2);
}

// Fully verified. Source of truth: AIModuleMessage.decomp @ 0x0040DF30
void* AIModuleMessage::scalar_deleting_destructor(uint param_1) {
    this->~AIModuleMessage();
    if ((param_1 & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
