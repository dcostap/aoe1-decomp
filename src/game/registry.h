#pragma once
#include "../common.h"

class TRegistry       {
public:
    void* ghMachineKey;                      // 0x0
    void* ghUserKey;                         // 0x4
    void* ghMachineKeyRead;                  // 0x8
    ulong gdwDisp;                           // 0xC
    char Data[255];                          // 0x10

    TRegistry(char* param_1);

    // --- Non-Virtual Destructor ---
    ~TRegistry() noexcept(false);
    // --- Non-Virtual Members ---
    int RegSet(int param_1, char* param_2, uchar* param_3, ulong param_4);
    int RegSetInt(int param_1, char* param_2, int param_3);
    int RegSetAscii(int param_1, char* param_2, uchar* param_3, ulong param_4);
    char* RegGetAscii(int param_1, char* param_2);
    long RegGet(int param_1, char* param_2, uchar* param_3, ulong* param_4);
    int RegGetInt(int param_1, char* param_2);
};

static_assert(sizeof(TRegistry) == 0x110, "TRegistry Size Mismatch");
static_assert(offsetof(TRegistry, Data) == 0x10, "TRegistry Offset Mismatch");

