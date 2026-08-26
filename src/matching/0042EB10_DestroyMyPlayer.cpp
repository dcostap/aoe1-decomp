// Use the canonical DirectPlay interface and self-player globals.

#if !defined(COM_HAND_TU_CONTEXT)
#include "../../include/directplay4a_context.h"
#endif

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Comm_Error {
public:
    void ShowReturn(long param_1, char* param_2);
};
#endif // COM_HAND_TU_CONTEXT


#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_00[0x10E0];
    unsigned int Me;
    char gap_10E4[0x3FC];
    RGE_Comm_Error* Err;

protected:
    long DestroyMyPlayer();
};
#endif // COM_HAND_TU_CONTEXT


extern IDirectPlay4A* DAT_0062c5ec;
extern unsigned long DAT_0062cf04;

long TCommunications_Handler::DestroyMyPlayer()
{
    long result;

    if (DAT_0062c5ec == 0)
        return 0;

    if (DAT_0062cf04 == 0)
        return 0;

    result = DAT_0062c5ec->DestroyPlayer(DAT_0062cf04);
    this->Err->ShowReturn(result, (char*)0x582FA8);
    if (result == 0) {
        DAT_0062cf04 = result;
        this->Me = result;
    }
    return result;
}
