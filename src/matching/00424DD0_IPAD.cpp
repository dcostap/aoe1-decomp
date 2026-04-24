#include <string.h>

extern const char default_ip_string[];

class IPAD {
public:
    char DottedIPAddress[0x20];
    char Alias[0x20];

    IPAD();
};

IPAD::IPAD() {
    strcpy(DottedIPAddress, default_ip_string);
    strcpy(Alias, default_ip_string);
}
