// 00424C80 RGE_Communications_Addresses::SetIPAddresses
// Source: com_addr.cpp lines 157-198
// PDB-qualified owner: protected int __thiscall RGE_Communications_Addresses::SetIPAddresses(char*)
// PDB body: 00424C80-00424D83; next sibling: EraseInformation at 00424D90
// Size: 260 bytes, no EH
//
// Attempt log:
// Probe 1 baseline: natural hostent address-list traversal with sprintf, strcat, and strcpy;
// 256 bytes because signed char promotion emitted movsx for the IP octets.
// Probe 2 ABI: use an unsigned-byte address view for the four network octets; this restored
// the original xor-plus-byte-load promotion sequence and produced an exact 260-byte match.
// Probe 3 layout: replace the raw gap with the canonical comm, WSADATA, hostname, counters,
// and typed IPAD fields; exact 260-byte match.

// BINARY NOTE: The method tests the hostname address before gethostbyname, publishes a zero
// through the caller buffer after that call succeeds, then scans and copies each address.
// BINARY NOTE: comm, WSADATA, hostname, counters, and pIPAD remain at +0x00, +0x04, +0x194,
// +0x218/+0x21C, and +0x220. Do not replace these fields with a raw storage view.

#include "..\..\include\game_globals.h"

extern "C" struct hostent* __stdcall gethostbyname(const char* name);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strcat(char* dest, const char* src);
extern "C" char* __cdecl strcpy(char* dest, const char* src);

#ifndef COM_ADDR_TU_CONTEXT
struct IPAD {
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class TCommunications_Handler;

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm; // +0x00
    WSADATA wsaData;                // +0x04
    char hostname[0x80];            // +0x194
    int Status;                     // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;

protected:
    int SetIPAddresses(char* out_buffer);
};
#endif

int RGE_Communications_Addresses::SetIPAddresses(char* out_buffer)
{
    char temp[25];

    if (!hostname)
        return 0;

    struct hostent* host = gethostbyname(hostname);
    if (!host)
        return 0;

    *out_buffer = 0;

    char** address_ptr = host->h_addr_list;
    AddressesAvailable = 0;

    unsigned char* address;
    while ((address = (unsigned char*)*address_ptr) != 0) {
        sprintf(temp, "%d.%d.%d.%d\n",
                address[0], address[1], address[2], address[3]);
        strcat(out_buffer, temp);
        strcpy(pIPAD[AddressesAvailable].DottedIPAddress, temp);
        AddressesAvailable++;
        address_ptr++;
    }

    return AddressesAvailable;
}
