#ifndef COM_LOBY_CONTEXT
extern "C" void __cdecl operator_delete(void*);

class RGE_Comm_Error {
public:
    ~RGE_Comm_Error();
};

class RGE_Lobby {
public:
    void ClearLobbyInfo(void);
    char gap_00[0x10];
    unsigned char lobby_game;
    unsigned char gap_15[3];
    RGE_Comm_Error* Err;

    ~RGE_Lobby();
};
#endif

RGE_Lobby::~RGE_Lobby() {
    RGE_Comm_Error* error = this->Err;
    if (error != 0) {
        error->~RGE_Comm_Error();
        operator_delete(error);
    }
    this->ClearLobbyInfo();
}
