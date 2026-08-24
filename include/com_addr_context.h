#ifndef COM_ADDR_CONTEXT_H
#define COM_ADDR_CONTEXT_H

#include "game_globals.h"

class TCommunications_Handler;

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x80];

    IPAD() {}
    ~IPAD() {}
};

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                 // +0x04
    char hostname[0x80];             // +0x194
    int Status;                      // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                     // +0x220

    RGE_Communications_Addresses(TCommunications_Handler* handler);
    ~RGE_Communications_Addresses();
    char* GetHostName();

protected:
    int SetIPAliases(char* out_buffer);
    int SetIPAddresses(char* out_buffer);
    void EraseInformation();

public:
    char* GetAddress(unsigned int index);
    char* GetAlias(unsigned int index);
};

#endif
