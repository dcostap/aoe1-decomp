// VA: 00424C20 GetAddress (40B, com_addr.cpp)
// PDB-qualified owner: RGE_Communications_Addresses::GetAddress
// PDB body: com_addr.cpp lines 138-143; 00424C20-00424C47
//
// BINARY NOTE: The adjacent com_addr.cpp methods use this same class view:
// WSADATA is at +0x04, hostname at +0x194, counters at +0x218/+0x21C, and
// pIPAD owns 0xA0-byte IPAD records at +0x220. Keep these fields typed.
// BINARY NOTE: The target forms pIPAD[index] before the count test. Keep this
// order because it preserves the shipped null and invalid-index behavior.
// The body has no socket call, publication, or cleanup; adjacent methods own
// those operations. The fallback returns the static empty string at 0x580460.

// Attempt log:
// 1. The existing raw-gap source matched 40/40 bytes, but did not preserve the
//    canonical communications-address layout.
// 2. Replaced the gap with WSADATA, hostname, counters, and typed IPAD fields;
//    the result stayed exact with the same owner and 0xA0-byte stride.
// 3. Used the natural IPAD pointer guard from the PDB/decompiler; exact again.

#include "..\..\include\game_globals.h"

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                  // +0x04
    char hostname[0x80];              // +0x194
    int Status;                       // +0x214
    unsigned int AddressesAvailable;  // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                      // +0x220

    char* GetAddress(unsigned int index);
};

char* RGE_Communications_Addresses::GetAddress(unsigned int index) {
    if (this->pIPAD + index != 0 &&
        index <= this->AddressesAvailable) {
        return this->pIPAD[index].DottedIPAddress;
    }
    return (char*)0x580460;
}
