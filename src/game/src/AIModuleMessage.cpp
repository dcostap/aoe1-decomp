#include "../include/AIModuleMessage.h"

#include <new>
// Fully verified. Source of truth: AIModuleMessage.decomp @ 0x0040DF30
void* AIModuleMessage::scalar_deleting_destructor(uint param_1) {
    this->~AIModuleMessage();
    if ((param_1 & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
