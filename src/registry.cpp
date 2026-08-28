// PDB source module: C:\\msdev\\work\\age1_x1\\registry.cpp.
// The definitions follow the original PDB source order.

#include "../include/registry.h"

// PDB lines 12-59; VA 0047EB80.
TRegistry::TRegistry(const char* name)
{
    this->ghMachineKey = 0;
    this->ghUserKey = 0;
    this->ghMachineKeyRead = 0;
    RegCreateKeyExA(HKEY_CURRENT_USER, name, 0, 0, 0, KEY_ALL_ACCESS, 0,
                    &this->ghUserKey, &this->gdwDisp);
    RegCreateKeyExA(HKEY_LOCAL_MACHINE, name, 0, 0, 0, KEY_ALL_ACCESS, 0,
                    &this->ghMachineKey, &this->gdwDisp);
    RegCreateKeyExA(HKEY_LOCAL_MACHINE, name, 0, 0, 0, KEY_QUERY_VALUE, 0,
                    &this->ghMachineKeyRead, &this->gdwDisp);
}

// PDB lines 63-83; VA 0047EC00.
TRegistry::~TRegistry()
{
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

// PDB lines 87-105; VA 0047EC40.
int TRegistry::RegSet(int use_user, const char* name,
                      unsigned char* value, unsigned long size)
{
    long err;
    if (use_user) {
        err = RegSetValueExA(this->ghUserKey, name, 0, 4, value, size);
    } else {
        err = RegSetValueExA(this->ghMachineKey, name, 0, 4, value, size);
    }
    return (err == 0);
}

// PDB lines 108-125; VA 0047ECA0.
int TRegistry::RegSetInt(int useUserKey, const char* valueName, int value)
{
    unsigned long ret;
    if (useUserKey != 0) {
        ret = RegSetValueExA(ghUserKey, valueName, 0, 4,
                             (const unsigned char*)&value, 4);
    }
    else {
        ret = RegSetValueExA(ghMachineKey, valueName, 0, 4,
                             (const unsigned char*)&value, 4);
    }
    return (ret == 0);
}

// PDB lines 131-149; VA 0047ED00.
int TRegistry::RegSetAscii(int use_user, const char* name,
                           unsigned char* value, unsigned long size)
{
    long err;
    if (use_user) {
        err = RegSetValueExA(this->ghUserKey, name, 0, 1, value, size);
    } else {
        err = RegSetValueExA(this->ghMachineKey, name, 0, 1, value, size);
    }
    return (err == 0);
}

// PDB lines 153-187; VA 0047ED60.
char* TRegistry::RegGetAscii(int userKey, const char* name)
{
    unsigned long type = REG_SZ;
    unsigned long size = sizeof(this->Data) - 1;

    if (userKey != 0) {
        return RegQueryValueExA(ghUserKey, name, 0, &type,
                                (unsigned char*)Data, &size) ? 0 : Data;
    } else {
        return RegQueryValueExA(ghMachineKeyRead, name, 0, &type,
                                (unsigned char*)Data, &size) ? 0 : Data;
    }
}

// PDB lines 192-203; VA 0047EDD0.
long TRegistry::RegGet(int useUserKey, const char* valueName,
                       unsigned char* data, unsigned long* dataSize)
{
    unsigned long type;
    if (useUserKey != 0) {
        return RegQueryValueExA(this->ghUserKey, valueName, 0,
                                &type, data, dataSize);
    }
    return RegQueryValueExA(this->ghMachineKeyRead, valueName, 0,
                            &type, data, dataSize);
}

// PDB lines 206-231; VA 0047EE20.
int TRegistry::RegGetInt(int use_user, const char* name)
{
    unsigned long dwSize = 4;
    unsigned long dwType = 4;
    int result;
    long err;
    if (use_user) {
        err = RegQueryValueExA(this->ghUserKey, name, 0, &dwType,
                               (unsigned char*)&result, &dwSize);
    } else {
        err = RegQueryValueExA(this->ghMachineKeyRead, name, 0, &dwType,
                               (unsigned char*)&result, &dwSize);
    }
    if (err == 0) {
        return result;
    }
    return -1;
}
