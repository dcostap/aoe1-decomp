#include "../include/AIModuleID.h"

#include <new>
#include <string.h>

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040DD90
AIModuleID::AIModuleID(char* param_1, int param_2) {
    this->id = param_2;
    if (param_1 != nullptr) {
        strncpy(this->name, param_1, 0x3F);
        return;
    }
    this->name[0] = '\0';
}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040DE10
AIModuleID::~AIModuleID() {}

// Fully verified. Source of truth: aimodule.cpp.decomp @ 0x0040DE20
void AIModuleID::setID(int param_1, char* param_2) {
    this->id = param_1;
    if (param_2 != nullptr) {
        strncpy(this->name, param_2, 0x3F);
        return;
    }
    this->name[0] = '\0';
}

// Fully verified. Source of truth: AIModuleID.decomp @ 0x0040DDF0
void* AIModuleID::vector_deleting_destructor(uint param_1) {
    this->~AIModuleID();
    if ((param_1 & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}
