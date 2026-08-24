// From registry.cpp

#include "../../include/registry_context.h"

int TRegistry::RegSetAscii(int use_user, const char* name, unsigned char* value, unsigned long size) {
    long err;
    if (use_user) {
        err = RegSetValueExA_ptr(this->ghUserKey, name, 0, 1, value, size);
    } else {
        err = RegSetValueExA_ptr(this->ghMachineKey, name, 0, 1, value, size);
    }
    return (err == 0);
}
