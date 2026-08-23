// 00424C50 RGE_Communications_Addresses::GetAlias
// PDB body: com_addr.cpp lines 146-154, 00424C50-00424C79.
// PDB ABI: public char* __thiscall GetAlias(unsigned int).
//
// Exact recovery:
// - Direct winsock.h and stdio.h context fixes the final SIB byte.
// - Removing stdio.h restores the one-byte mismatch.
// - windows.h can replace winsock.h. string.h and larger class surfaces are incidental.
// - Natural indexed, pointer, reference, and combined-guard forms otherwise emit the same mismatch.
//
// BINARY NOTE: Same-module exact anchors prove the class fields and the 0xA0-byte IPAD layout.
// BINARY NOTE: Keep the count check, pointer formation, null test, and fallback fault order.

#include <winsock.h>
#include <stdio.h>

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class TCommunications_Handler;

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                  // +0x04
    char hostname[0x80];              // +0x194
    int Status;                       // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                      // +0x220

    char* GetAlias(unsigned int index);
};

char* RGE_Communications_Addresses::GetAlias(unsigned int index) {
    char* alias;

    // ORIGINAL BUG: The alias count itself passes this test and selects the next record.
    // A >= correction would reject that shipped case and change malformed-input behavior.
    if (index > this->AliasesAvailable) {
        return (char*)0x00580460;
    }
    alias = this->pIPAD[index].Alias;
    if (alias == 0) {
        return (char*)0x00580460;
    }
    return alias;
}
