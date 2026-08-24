#include <string.h>
extern char s_Optional_Information[];
#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x10F8];
    char MyFriendlyName[0x81];
    char MyFormalName[0x80];
    void SetMyPlayerName(char* name);
};
#endif // COM_HAND_TU_CONTEXT

void TCommunications_Handler::SetMyPlayerName(char* name) {
    strcpy(this->MyFriendlyName, name);
    strcpy(this->MyFormalName, s_Optional_Information);
}
