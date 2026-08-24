// VA: 00424B60 RGE_Communications_Addresses::GetHostName
// Source: com_addr.cpp lines 93-97
// Size: 22 bytes, __thiscall
//
// BINARY NOTE: The hostname buffer starts at +0x194, after the canonical
// WSADATA member. The socket call runs before this method publishes that
// buffer as its return value.

#include "..\..\include\game_globals.h"

extern "C" int __stdcall gethostname(char* name, int namelen);

#ifndef COM_ADDR_TU_CONTEXT
class TCommunications_Handler;

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                  // +0x04
    char hostname[0x80];             // +0x194
    int Status;                       // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                      // +0x220

    char* GetHostName();
};
#endif

char* RGE_Communications_Addresses::GetHostName()
{
    gethostname(this->hostname, 0x80);
    return this->hostname;
}
