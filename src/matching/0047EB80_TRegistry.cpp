// TRegistry::TRegistry (0047EB80, 124 bytes, registry.cpp)
// Attempt 1

#include "../../include/registry_context.h"

TRegistry::TRegistry(const char* name) {
    this->ghMachineKey = 0;
    this->ghUserKey = 0;
    this->ghMachineKeyRead = 0;
    RegCreateKeyExA_ptr((HKEY)0x80000001, name, 0, 0, 0, 0xf003f, 0, &this->ghUserKey, &this->gdwDisp);
    RegCreateKeyExA_ptr((HKEY)0x80000002, name, 0, 0, 0, 0xf003f, 0, &this->ghMachineKey, &this->gdwDisp);
    RegCreateKeyExA_ptr((HKEY)0x80000002, name, 0, 0, 0, 1, 0, &this->ghMachineKeyRead, &this->gdwDisp);
}
