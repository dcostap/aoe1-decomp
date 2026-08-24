#ifndef AOE1_COM_HAND_HOLDER_DTOR_CONTEXT_H
#define AOE1_COM_HAND_HOLDER_DTOR_CONTEXT_H

#include "com_hand_context.h"

// BINARY NOTE: VC5 inlines this body in the scalar vector-delete path.
// The original vector path uses eh_vector_destructor_iterator under /GX.
inline HOLDER::~HOLDER() {
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
