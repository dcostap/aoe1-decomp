#pragma once
#include "common.h"

struct RGE_Communications_Addresses {
    TCommunications_Handler* comm;
    WSAData wsaData;
    char hostname[128];
    int Status;
    uint AddressesAvailable;
    uint AliasesAvailable;
    IPAD* pIPAD;
};
static_assert(sizeof(RGE_Communications_Addresses) == 0x224, "Size mismatch");
