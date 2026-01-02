#pragma once
#include "../common.h"

class TRegistry {
public:
    void* ghUserKey;                         // 0x4
    void* ghMachineKeyRead;                  // 0x8
    ulong gdwDisp;                           // 0xC
    char Data[255];                          // 0x10

    TRegistry(char* param_1);
    virtual ~TRegistry();
    virtual int RegSet(int param_1, char* param_2, uchar* param_3, ulong param_4);
    virtual int RegSetInt(int param_1, char* param_2, int param_3);
    virtual int RegSetAscii(int param_1, char* param_2, uchar* param_3, ulong param_4);
    virtual char* RegGetAscii(int param_1, char* param_2);
    virtual long RegGet(int param_1, char* param_2, uchar* param_3, ulong* param_4);
    virtual int RegGetInt(int param_1, char* param_2);
};

static_assert(sizeof(TRegistry) == 0x110, "TRegistry Size Mismatch");
static_assert(offsetof(TRegistry, Data) == 0x10, "TRegistry Offset Mismatch");

