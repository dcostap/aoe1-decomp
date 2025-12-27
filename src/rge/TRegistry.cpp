#include "TRegistry.h"
#include <cstring>

TRegistry::TRegistry(const char* key) {
    if (key) {
        strncpy(this->key_name, key, 256);
    } else {
        this->key_name[0] = 0;
    }
}

TRegistry::~TRegistry() {}

int TRegistry::RegGetInt(TRegistry* reg, int type, const char* name) {
    // Stub implementation - return default or error
    return -1;
}

void TRegistry::RegSetInt(TRegistry* reg, int type, const char* name, int value) {
    // Stub implementation
}
