// 00424C80 RGE_Communications_Addresses::SetIPAddresses
// Source: com_addr.cpp lines 157-198
// Size: 260 bytes, no EH
//
// Attempt log:
// Probe 1 baseline: natural hostent address-list traversal with sprintf, strcat, and strcpy;
// 256 bytes because signed char promotion emitted movsx for the IP octets.
// Probe 2 ABI: use an unsigned-byte address view for the four network octets; this restored
// the original xor-plus-byte-load promotion sequence and produced an exact 260-byte match.

struct hostent {
    char* h_name;
    char** h_aliases;
    short h_addrtype;
    short h_length;
    char** h_addr_list;
};

extern "C" struct hostent* __stdcall gethostbyname(const char* name);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" char* __cdecl strcat(char* dest, const char* src);
extern "C" char* __cdecl strcpy(char* dest, const char* src);

struct IPAD {
    char DottedIPAddress[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    char gap_00[0x194];
    char hostname[0x80];
    int Status;
    unsigned int AddressesAvailable;
    unsigned int AliasesAvailable;
    IPAD* pIPAD;

    int SetIPAddresses(char* out_buffer);
};

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
