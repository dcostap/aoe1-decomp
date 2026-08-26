#ifndef COM_LOBY_CONTEXT
#include "../../include/com_loby_context.h"
#endif

int __stdcall EnumPlayersCallbackLobby(unsigned long param_1,
                                        unsigned long param_2,
                                        DPNAME* param_3,
                                        unsigned long param_4,
                                        void* param_5) {
    L->Log((char*)"ENUMPLAYER: DPID = %ld", param_1);
    L->Log((char*)"ENUMPLAYER: NAME = %s", param_3->lpszShortName);
    L->Log((char*)"+++ Enumeration not done");
    if ((param_4 & 0x10) != 0) {
        L->Log((char*)"Remote Player");
    }
    if ((param_4 & 8) != 0) {
        L->Log((char*)"Local Player");
    }
    return 1;
}
