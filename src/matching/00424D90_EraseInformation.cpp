// PDB NOTE: com_addr.cpp lines 202-206 define the protected method below.
// BINARY NOTE: The qualified body is 00424D90-00424DCE. Padding starts at 00424DCF.
// BINARY NOTE: The method uses hostname at +0x194 and counters at +0x218 and +0x21C.
// BINARY NOTE: It copies the shared empty string, then clears AliasesAvailable and AddressesAvailable.
// Exact-finish audit: The baseline used a raw gap. The canonical class layout stays exact and is retained.

#include "..\..\include\game_globals.h"
#include <string.h>

extern char s_[];

class TCommunications_Handler;

struct IPAD {
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm; // +0x00
    WSADATA wsaData;                // +0x04
    char hostname[0x80];            // +0x194
    int Status;                     // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                     // +0x220

    void EraseInformation(void);
};

void RGE_Communications_Addresses::EraseInformation(void) {
    strcpy(this->hostname, s_);
    this->AliasesAvailable = 0;
    this->AddressesAvailable = 0;
}
