#ifndef COM_LOBY_CONTEXT
#include "../../include/com_loby_context.h"
#endif

int RGE_Lobby::IsLobbyLaunched(void) {
    L->Log((char*)"LOBBY GAME LAUNCH STATUS = %d",
           (unsigned int)this->lobby_game);
    return (unsigned int)this->lobby_game;
}
