// 004249D0 RGE_Communications_Addresses::RGE_Communications_Addresses
// Source: com_addr.cpp lines 8-79
// PDB owner: com_addr.cpp lines 8-79, body 004249D0-00424AB2
// Size: 227 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural constructor with new IPAD[8], GetHostName, SetIPAddresses, SetIPAliases, /GX
// Probe 2: canonical hostname array with the old gap retained; 3-byte mismatch from shifted fields.
// Probe 3: removed the redundant gap; exact 227-byte match.
// Probe 4: typed WSADATA and direct WSAStartup output address; exact result unchanged.
//
// BINARY NOTE: The PDB boundary ends at 00424AB3. The next bytes are padding.
// BINARY NOTE: The constructor stores comm at +0x00, Status at +0x214, and pIPAD at +0x220.
// BINARY NOTE: The ordered calls are EraseInformation, WSAStartup, IPAD allocation and construction,
// GetHostName, the 0xFF buffer allocation, SetIPAddresses, SetIPAliases, and buffer deletion.

#include "..\..\include\game_globals.h"

#ifndef COM_ADDR_TU_CONTEXT
class TCommunications_Handler;

class IPAD {
public:
    char DottedIPAddress[0x20];  // +0x00 to +0x1F
    char Alias[0x80];            // +0x20 to +0x9F
    IPAD() {}
    ~IPAD() {}
};

void* __cdecl operator new(unsigned int size);

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                  // +0x04
    char hostname[0x80];             // +0x194 to +0x213
    int Status;                      // +0x214
    int AddressesAvailable;          // +0x218
    int AliasesAvailable;            // +0x21C
    IPAD* pIPAD;                     // +0x220

protected:
    void EraseInformation();

public:
    char* GetHostName();

protected:
    int SetIPAddresses(char* buffer);
    int SetIPAliases(char* buffer);

public:
    RGE_Communications_Addresses(TCommunications_Handler* handler);
};
#endif

RGE_Communications_Addresses::RGE_Communications_Addresses(TCommunications_Handler* handler)
{
    this->comm = handler;
    this->EraseInformation();

    int wsResult = WSAStartup(0x101, &this->wsaData);

    this->pIPAD = new IPAD[8];

    if (wsResult != 0) {
        this->Status = 0;
    } else {
        this->Status = 1;
        this->GetHostName();
        char* buffer = new char[0xFF];
        this->SetIPAddresses(buffer);
        this->SetIPAliases(buffer);
        delete[] buffer;
    }
}
