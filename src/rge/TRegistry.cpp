#include "TRegistry.h"
#include <cstring>

// Address: 0x00444100
TRegistry::TRegistry(const char* key) {
    if (key) {
        strncpy(this->key_name, key, 256);
    } else {
        this->key_name[0] = 0;
    }
}

// Address: 0x00444140
TRegistry::~TRegistry() {}

// Address: 0x00444180
int TRegistry::RegGetInt(TRegistry* reg, int type, const char* name) {
#ifdef _DEBUG
    // Stub implementation - return default or error
    return -1;
#else
    // TODO: Implement original logic
    return -1;
#endif
}

// Address: 0x00444200
void TRegistry::RegSetInt(TRegistry* reg, int type, const char* name, int value) {
#ifdef _DEBUG
    // Stub implementation
#else
    // TODO: Implement original logic
#endif
}
