#include "../../include/registry_context.h"

TRegistry::~TRegistry() {
    LONG (WINAPI *closeKey)(HKEY) = RegCloseKey;

    if (this->ghUserKey != 0) {
        closeKey(this->ghUserKey);
        this->ghUserKey = 0;
    }
    if (this->ghMachineKey != 0) {
        closeKey(this->ghMachineKey);
        this->ghMachineKey = 0;
    }
    if (this->ghMachineKeyRead != 0) {
        closeKey(this->ghMachineKeyRead);
        this->ghMachineKeyRead = 0;
    }
}
