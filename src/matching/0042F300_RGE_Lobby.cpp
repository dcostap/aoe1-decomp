#ifndef COM_LOBY_CONTEXT
#include "../../include/com_loby_context.h"
#endif

RGE_Lobby::~RGE_Lobby() {
    RGE_Comm_Error* error = this->Err;
    if (error != 0) {
        error->~RGE_Comm_Error();
        operator_delete(error);
    }
    this->ClearLobbyInfo();
}
