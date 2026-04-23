// VC5 emits a copy from the shared empty-string symbol into hostname, then clears the availability counters.
// Keep the counter zeroing order aligned with the original bytes: AliasesAvailable first, then AddressesAvailable.

#include <string.h>

extern char s_[];

class RGE_Communications_Addresses {
public:
    char gap_000[0x194];
    char hostname[128];
    int Status;
    unsigned int AddressesAvailable;
    unsigned int AliasesAvailable;

    void EraseInformation(void);
};

void RGE_Communications_Addresses::EraseInformation(void) {
    strcpy(this->hostname, s_);
    this->AliasesAvailable = 0;
    this->AddressesAvailable = 0;
}
