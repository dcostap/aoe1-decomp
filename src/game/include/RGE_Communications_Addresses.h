#pragma once
#include "common.h"

struct IPAD {
    char DottedIPAddress[32];
    char Alias[128];

    IPAD();
    ~IPAD();
};
static_assert(sizeof(IPAD) == 0xA0, "Size mismatch");

struct RGE_Communications_Addresses {
    RGE_Communications_Addresses(TCommunications_Handler* comm);
    ~RGE_Communications_Addresses();

    char* GetHostName();
    char* GetAddress(uint index);
    char* GetAlias(uint index);

    int SetIPAliases(char* scratch);
    int SetIPAddresses(char* scratch);
    void EraseInformation();

    TCommunications_Handler* comm;
    WSAData wsaData;
    char hostname[128];
    int Status;
    uint AddressesAvailable;
    uint AliasesAvailable;
    IPAD* pIPAD;
};
static_assert(sizeof(RGE_Communications_Addresses) == 0x224, "Size mismatch");
