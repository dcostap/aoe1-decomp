
#include "../include/registry.h"

TRegistry::TRegistry(const char* Key) {
    this->ghMachineKey = 0;
    this->ghUserKey = 0;
    this->ghMachineKeyRead = 0;
    RegCreateKeyExA(HKEY_CURRENT_USER, Key, 0, 0, 0, KEY_ALL_ACCESS, 0, &this->ghUserKey, &this->gdwDisp);
    RegCreateKeyExA(HKEY_LOCAL_MACHINE, Key, 0, 0, 0, KEY_ALL_ACCESS, 0, &this->ghMachineKey, &this->gdwDisp);
    RegCreateKeyExA(HKEY_LOCAL_MACHINE, Key, 0, 0, 0, KEY_QUERY_VALUE, 0, &this->ghMachineKeyRead, &this->gdwDisp);
}

TRegistry::~TRegistry() {
    if (this->ghUserKey != 0) {
        RegCloseKey(this->ghUserKey);
        this->ghUserKey = 0;
    }
    if (this->ghMachineKey != 0) {
        RegCloseKey(this->ghMachineKey);
        this->ghMachineKey = 0;
    }
    if (this->ghMachineKeyRead != 0) {
        RegCloseKey(this->ghMachineKeyRead);
        this->ghMachineKeyRead = 0;
    }
}

int TRegistry::RegSet(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long dwSize) {
    long err;
    if (UseUserKey) {
        err = RegSetValueExA(this->ghUserKey, lptszName, 0, REG_DWORD, lpData, dwSize);
    } else {
        err = RegSetValueExA(this->ghMachineKey, lptszName, 0, REG_DWORD, lpData, dwSize);
    }
    return (err == 0);
}

int TRegistry::RegSetInt(int UseUserKey, const char* lptszName, int Value) {
    unsigned long ret;
    if (UseUserKey != 0) {
        ret = RegSetValueExA(ghUserKey, lptszName, 0, REG_DWORD, (const unsigned char*)&Value, 4);
    } else {
        ret = RegSetValueExA(ghMachineKey, lptszName, 0, REG_DWORD, (const unsigned char*)&Value, 4);
    }
    return (ret == 0);
}

int TRegistry::RegSetAscii(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long dwSize) {
    long err;
    if (UseUserKey) {
        err = RegSetValueExA(this->ghUserKey, lptszName, 0, REG_SZ, lpData, dwSize);
    } else {
        err = RegSetValueExA(this->ghMachineKey, lptszName, 0, REG_SZ, lpData, dwSize);
    }
    return (err == 0);
}

char* TRegistry::RegGetAscii(int UseUserKey, const char* lptszName) {
    unsigned long dwType = REG_SZ;
    unsigned long dwSize = sizeof(this->Data) - 1;

    if (UseUserKey != 0) {
        return RegQueryValueExA(ghUserKey, lptszName, 0, &dwType, (unsigned char*)Data, &dwSize) ? 0 : Data;
    } else {
        return RegQueryValueExA(ghMachineKeyRead, lptszName, 0, &dwType, (unsigned char*)Data, &dwSize) ? 0 : Data;
    }
}

long TRegistry::RegGet(int UseUserKey, const char* lptszName, unsigned char* lpData, unsigned long* lpdwDataSize) {
    unsigned long dwType;
    if (UseUserKey != 0) {
        return RegQueryValueExA(this->ghUserKey, lptszName, 0, &dwType, lpData, lpdwDataSize);
    }
    return RegQueryValueExA(this->ghMachineKeyRead, lptszName, 0, &dwType, lpData, lpdwDataSize);
}

int TRegistry::RegGetInt(int UseUserKey, const char* lptszName) {
    unsigned long Size = 4;
    unsigned long dwType = REG_DWORD;
    int Data;
    long err;
    if (UseUserKey) {
        err = RegQueryValueExA(this->ghUserKey, lptszName, 0, &dwType, (unsigned char*)&Data, &Size);
    } else {
        err = RegQueryValueExA(this->ghMachineKeyRead, lptszName, 0, &dwType, (unsigned char*)&Data, &Size);
    }
    if (err == 0) {
        return Data;
    }
    return -1;
}
