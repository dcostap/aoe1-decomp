#pragma once
#include "common.h"

class TRegistry {
public:
    void* ghMachineKey;
    void* ghUserKey;
    void* ghMachineKeyRead;
    ulong gdwDisp;
    char Data[255];

    TRegistry(const char* subkey);
    ~TRegistry();

    int RegGetInt(int user, const char* name);
    int RegSetInt(int user, const char* name, int value);
    char* RegGetAscii(int user, const char* name);
    int RegSetAscii(int user, const char* name, unsigned char* data, unsigned long size);
    long RegGet(int user, const char* name, unsigned char* data, unsigned long* size);
    int RegSet(int user, const char* name, unsigned char* data, unsigned long size);
};
static_assert(sizeof(TRegistry) == 0x110, "Size mismatch");
