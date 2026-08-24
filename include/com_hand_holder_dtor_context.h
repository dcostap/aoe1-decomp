#ifndef AOE1_COM_HAND_HOLDER_DTOR_CONTEXT_H
#define AOE1_COM_HAND_HOLDER_DTOR_CONTEXT_H

#include "com_hand_context.h"

HOLDER::~HOLDER() {
    if (this->HoldMsg != 0) {
        ::operator delete(this->HoldMsg);
    }
    this->HoldMsg = 0;
    this->Serial = 0;
    this->Length = 0;
    this->dcoFromID = 0;
    this->dcoReceiveID = 0;
}

#endif
