#include <string.h>
extern char s_Optional_Information[];
class TCommunications_Handler {
public:
    char gap_0[0x10F8];
    char MyFriendlyName[0x81];
    char MyFormalName[0x80];
    void SetMyPlayerName(char* name);
};
void TCommunications_Handler::SetMyPlayerName(char* name) {
    strcpy(this->MyFriendlyName, name);
    strcpy(this->MyFormalName, s_Optional_Information);
}
