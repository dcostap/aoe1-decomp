
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
