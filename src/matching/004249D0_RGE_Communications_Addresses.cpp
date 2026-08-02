// 004249D0 RGE_Communications_Addresses::RGE_Communications_Addresses
// Source: com_addr.cpp lines 8-79
// Size: 227 bytes, EH-framed
//
// Attempt log:
// Probe 1: natural constructor with new IPAD[8], GetHostName, SetIPAddresses, SetIPAliases, /GX

#include "..\..\include\game_globals.h"

class TCommunications_Handler;

#pragma pack(push, 1)
class IPAD {
public:
    char DottedIPAddress[0x20];  // +0x00 to +0x1F
    char Alias[0x80];            // +0x20 to +0x9F
    IPAD() {}
    ~IPAD() {}
};
#pragma pack(pop)

void* __cdecl operator new(unsigned int size);

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    char wsaData[0x190];             // +0x04 (WSADATA up to hostname)
    char* hostname;                  // +0x194
    char _gap_198[0x7C];            // +0x198 to +0x213
    int Status;                      // +0x214
    int AddressesAvailable;          // +0x218
    int AliasesAvailable;            // +0x21C
    IPAD* pIPAD;                     // +0x220

    void EraseInformation();
    char* GetHostName();
    int SetIPAddresses(char* buffer);
    int SetIPAliases(char* buffer);
    RGE_Communications_Addresses(TCommunications_Handler* handler);
};

RGE_Communications_Addresses::RGE_Communications_Addresses(TCommunications_Handler* handler)
{
    this->comm = handler;
    this->EraseInformation();

    int wsResult = WSAStartup(0x101, (WSADATA*)&this->wsaData);

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
