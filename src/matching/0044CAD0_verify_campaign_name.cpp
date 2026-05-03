// VA: 0044CAD0 verify_campaign_name (71 B, 33 asm)
// PDB source: gameinfo.cpp lines 208-213
// __thiscall RGE_Campaign_Info::verify_campaign_name(char*)
//
// Attempt log:
// 1-4. Various loop forms: too compact (64 B) or huge with spills.
// 5-7. strcmp intrinsic: loop correct but return uses ecx intermediate.
// 8. Manual subtraction: worse (95%).
// 9. !strcmp cast: same ecx intermediate.
// 10. Try: ternary ? operator for return values.

#include <string.h>

class RGE_Campaign_Info {
public:
    char campaign_name[256];

    unsigned char verify_campaign_name(char* campaign);
};

unsigned char RGE_Campaign_Info::verify_campaign_name(char* campaign) {
    return strcmp(this->campaign_name, campaign) ? (unsigned char)0 : (unsigned char)1;
}
