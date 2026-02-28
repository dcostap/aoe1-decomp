#include "../include/AIModuleID.h"

#include <new>
// Fully verified. Source of truth: AIModuleID.decomp @ 0x0040DDF0
void* AIModuleID::vector_deleting_destructor(uint param_1) {
    this->~AIModuleID();
    if ((param_1 & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
