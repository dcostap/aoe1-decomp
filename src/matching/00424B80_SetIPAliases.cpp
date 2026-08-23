// 00424B80 RGE_Communications_Addresses::SetIPAliases
// Source: com_addr.cpp lines 100-135
// Size: 152 bytes, __thiscall, returns int
// FLAGS: default
//
// Attempt log (2026-05-19):
// try 1: char[] hostname, strlen/memcpy -> 144B wrong offsets
// try 2: char* hostname, still 144B
// try 3-4: manual copy loops -> no repne/rep movs
// try 5: register keyword + strcpy idiom -> 144B, correct offsets + 4 reg saves but edi=this, byte loop
// try 6: use strcpy to trigger inline rep movs
//
// Final audit:
// The PDB and adjacent exact functions prove this owner and boundary: 00424B80-00424C18.
// The canonical class keeps WSADATA, hostname, counters, and the IPAD array in their proven fields.
// The direct socket call, output publication, alias scan, copy, counter update, and fault order match.
// The narrow prior layout and this canonical layout both emit an exact match.
// Keep the canonical layout because it protects the communications-address anchors.

#include "..\..\include\game_globals.h"

extern "C" struct hostent* __stdcall gethostbyname(const char* name);
extern "C" char* __cdecl strcpy(char* dest, const char* src);

struct IPAD {
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    TCommunications_Handler* comm;   // +0x00
    WSADATA wsaData;                  // +0x04
    char hostname[0x80];              // +0x194
    int Status;                       // +0x214
    unsigned int AddressesAvailable; // +0x218
    unsigned int AliasesAvailable;   // +0x21C
    IPAD* pIPAD;                      // +0x220

    int SetIPAliases(char* out_buffer);
};

int RGE_Communications_Addresses::SetIPAliases(char* out_buffer)
{
    if (!hostname)
        return 0;

    struct hostent* he = gethostbyname(hostname);
    if (!he)
        return 0;

    *out_buffer = 0;

    char** alias_ptr = he->h_aliases;
    AliasesAvailable = 0;

    char* alias;
    while ((alias = *alias_ptr) != 0) {
        strcpy(pIPAD[AliasesAvailable].Alias, alias);
        AliasesAvailable++;
        alias_ptr++;
    }

    return AliasesAvailable;
}
