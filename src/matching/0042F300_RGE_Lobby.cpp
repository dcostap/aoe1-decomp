#ifndef COM_LOBY_CONTEXT
#include "../../include/com_loby_context.h"
#endif

RGE_Lobby::~RGE_Lobby() {
    delete this->Err;
    this->ClearLobbyInfo();
}
