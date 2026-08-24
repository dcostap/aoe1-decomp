#ifndef AOE1_COM_HAND_RESENDER_DTOR_CONTEXT_H
#define AOE1_COM_HAND_RESENDER_DTOR_CONTEXT_H

#include "com_hand_context.h"

RESENDER::~RESENDER() {
    this->TimeSent = 0;
    if (this->ResendMsg != 0) {
        ::operator delete(this->ResendMsg);
    }
    this->ResendMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    for (int i = 0; i < 10; ++i) {
        this->DestMap[i] = 0;
    }
}

#endif
