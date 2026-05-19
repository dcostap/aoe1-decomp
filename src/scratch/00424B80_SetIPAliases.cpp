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
// try 6: MATCH! strcpy inlines to repne scasb + rep movsd/movsb. Key: hostname[0x88] at +0x194

struct hostent {
    char* h_name;
    char** h_aliases;
    short h_addrtype;
    short h_length;
    char** h_addr_list;
};

extern "C" struct hostent* __stdcall gethostbyname(const char* name);
extern "C" char* __cdecl strcpy(char* dest, const char* src);

struct IPAD {
    char gap_00[0x20];
    char Alias[0x80];
};

class RGE_Communications_Addresses {
public:
    char gap_00[0x194];
    char hostname[0x88];    // +0x194, 136 bytes
    int AliasesAvailable;    // +0x21C
    IPAD* pIPAD;            // +0x220

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
