#include <windows.h>
#include "../include/TRegistry.h"
#include <stdio.h>

#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "kernel32.lib")

TRegistry::TRegistry(const char* subkey) {
    this->ghMachineKey = NULL;
    this->ghUserKey = NULL;
    this->ghMachineKeyRead = NULL;
    this->gdwDisp = 0;

    // Open/Create User Key (HKCU)
    RegCreateKeyExA(
        HKEY_CURRENT_USER,
        subkey,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        (PHKEY)&this->ghUserKey,
        &this->gdwDisp
    );

    // Open/Create Machine Key (HKLM) - All Access
    RegCreateKeyExA(
        HKEY_LOCAL_MACHINE,
        subkey,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_ALL_ACCESS,
        NULL,
        (PHKEY)&this->ghMachineKey,
        &this->gdwDisp
    );

    // Open/Create Machine Key (HKLM) - Read Only
    RegCreateKeyExA(
        HKEY_LOCAL_MACHINE,
        subkey,
        0,
        NULL,
        REG_OPTION_NON_VOLATILE,
        KEY_READ,
        NULL,
        (PHKEY)&this->ghMachineKeyRead,
        &this->gdwDisp
    );
}

// Destructor (based on ??1TRegistry@@QAE@XZ)
// Note: In the assembly it's implemented as a separate function.
// We'll add it to the header if needed, but for now let's implement the logic.
TRegistry::~TRegistry() {
    if (this->ghUserKey) {
        RegCloseKey((HKEY)this->ghUserKey);
        this->ghUserKey = NULL;
    }
    if (this->ghMachineKey) {
        RegCloseKey((HKEY)this->ghMachineKey);
        this->ghMachineKey = NULL;
    }
    if (this->ghMachineKeyRead) {
        RegCloseKey((HKEY)this->ghMachineKeyRead);
        this->ghMachineKeyRead = NULL;
    }
}

int TRegistry::RegGetInt(int user, const char* name) {
    DWORD dwType = REG_DWORD;
    DWORD dwSize = sizeof(int);
    int value = -1;
    LONG result;

    if (user != 0 && this->ghUserKey) {
        result = RegQueryValueExA((HKEY)this->ghUserKey, name, NULL, &dwType, (LPBYTE)&value, &dwSize);
        if (result == ERROR_SUCCESS) {
            return value;
        }
    }

    if (this->ghMachineKeyRead) {
        result = RegQueryValueExA((HKEY)this->ghMachineKeyRead, name, NULL, &dwType, (LPBYTE)&value, &dwSize);
        if (result == ERROR_SUCCESS) {
            return value;
        }
    }

    return -1;
}

int TRegistry::RegSetInt(int user, const char* name, int value) {
    HKEY hKey = (user != 0) ? (HKEY)this->ghUserKey : (HKEY)this->ghMachineKey;
    if (!hKey) return 0;

    LONG result = RegSetValueExA(hKey, name, 0, REG_DWORD, (const BYTE*)&value, sizeof(int));
    return (result == ERROR_SUCCESS);
}

char* TRegistry::RegGetAscii(int user, const char* name) {
    DWORD dwType = REG_SZ;
    DWORD dwSize = sizeof(this->Data);
    HKEY hKey;

    if (user != 0 && this->ghUserKey) {
        hKey = (HKEY)this->ghUserKey;
    } else {
        hKey = (HKEY)this->ghMachineKeyRead;
    }

    if (!hKey) return NULL;

    LONG result = RegQueryValueExA(hKey, name, NULL, &dwType, (LPBYTE)this->Data, &dwSize);
    if (result == ERROR_SUCCESS) {
        return this->Data;
    }

    return NULL;
}

int TRegistry::RegSetAscii(int user, const char* name, unsigned char* data, unsigned long size) {
    HKEY hKey = (user != 0) ? (HKEY)this->ghUserKey : (HKEY)this->ghMachineKey;
    if (!hKey) return 0;

    LONG result = RegSetValueExA(hKey, name, 0, REG_SZ, data, size);
    return (result == ERROR_SUCCESS);
}

long TRegistry::RegGet(int user, const char* name, unsigned char* data, unsigned long* size) {
    HKEY hKey = (user != 0) ? (HKEY)this->ghUserKey : (HKEY)this->ghMachineKeyRead;
    if (!hKey) return ERROR_INVALID_HANDLE;

    return RegQueryValueExA(hKey, name, NULL, NULL, data, size);
}

int TRegistry::RegSet(int user, const char* name, unsigned char* data, unsigned long size) {
    HKEY hKey = (user != 0) ? (HKEY)this->ghUserKey : (HKEY)this->ghMachineKey;
    if (!hKey) return 0;

    LONG result = RegSetValueExA(hKey, name, 0, REG_BINARY, data, size);
    return (result == ERROR_SUCCESS);
}
