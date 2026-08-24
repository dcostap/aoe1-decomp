// TCommunications_Handler::SetMyGameOptions
// VA: 0042EB60
// Com_hand.cpp:6581-6612
// 142 bytes

#include <string.h>
#if !defined(COM_HAND_TU_CONTEXT)
#include "../../include/game_globals.h"
#endif // COM_HAND_TU_CONTEXT

void* __cdecl operator_new(unsigned int size);

#if !defined(COM_HAND_TU_CONTEXT)
extern void* L;
#endif // COM_HAND_TU_CONTEXT
#if !defined(COM_HAND_TU_CONTEXT)
extern "C" void __cdecl Log(void* log, char* fmt, ...);
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x04];
    char* OptionsData;      // +0x04
    char gap_08[0x1C - 0x08];
    int MeHost;             // +0x1C
    char gap_20[0x1550 - 0x20];
    char NeedsToBeSent;     // +0x1550
    char gap_1551[0x171C - 0x1551];
    unsigned int DataSizeToFollow;  // +0x171C

    int SetMyGameOptions(char* param_1, unsigned long param_2);
    void FreeOptions(void);
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::SetMyGameOptions(char* param_1, unsigned long param_2) {
    if (param_2 > 2000)
        return 0;

    this->FreeOptions();

    if (param_1 != 0 && param_2 != 0) {
        char* buf = (char*)operator_new(param_2 + 1);
        this->OptionsData = buf;
        if (buf == 0)
            return 0;

        memcpy(buf, param_1, param_2);
        this->PlayerOptions.DataSizeToFollow = param_2;
    }

    if (this->MeHost != 0) {
        this->PlayerOptions.NeedsToBeSent = 1;
    }

    Log(L, "Host Set Options to size %d", param_2);
    return 1;
}
