#pragma once
#include "common.h"

class IPAD {
public:
    char DottedIPAddress[32];                // 0x0
    char Alias[128];                         // 0x20

    IPAD();
    ~IPAD();
};

static_assert(sizeof(IPAD) == 0xA0, "IPAD Size Mismatch");

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;           // 0x0
    WSAData wsaData;                         // 0x4
    char hostname[128];                      // 0x194
    int Status;                              // 0x214
    uint AddressesAvailable;                 // 0x218
    uint AliasesAvailable;                   // 0x21C
    IPAD* pIPAD;                             // 0x220

    RGE_Communications_Addresses(TCommunications_Handler* param_1);
    ~RGE_Communications_Addresses();
    char* GetHostName();
    int SetIPAliases(char* param_1);
    char* GetAddress(uint param_1);
    char* GetAlias(uint param_1);
    int SetIPAddresses(char* param_1);
    void EraseInformation();
};

static_assert(sizeof(RGE_Communications_Addresses) == 0x224, "RGE_Communications_Addresses Size Mismatch");

