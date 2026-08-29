// PDB-qualified owner: public: __thiscall IPAD::IPAD(void), com_addr.h:46-50.
// BINARY NOTE: The body is 00424DD0-00424E21; 00424E22 starts padding before
// the next PDB sibling, IPAD::~IPAD at 00424E30.
// BINARY NOTE: RGE_Communications_Addresses::pIPAD owns 0xA0-byte IPAD records:
// DottedIPAddress is at +0x00 and Alias is at +0x20.
// BINARY NOTE: Both fields use natural empty string literals. VC5 inlines
// strcpy here, so the body has no direct calls.

#include <string.h>

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x80];

    IPAD();
};

IPAD::IPAD() {
    strcpy(DottedIPAddress, "");
    strcpy(Alias, "");
}
