class RGE_Comm_Error_lob {
public:
    void destroy(void);
};
extern "C" void __cdecl operator_delete_lob(void*);

class RGE_Lobby_dtor {
public:
    void dtor(void);
    void ClearLobbyInfo(void);
    char gap_00[0x18];
    RGE_Comm_Error_lob* err;
};

void RGE_Lobby_dtor::dtor(void) {
    RGE_Comm_Error_lob* e = this->err;
    if (e) {
        e->destroy();
        operator_delete_lob(e);
    }
    this->ClearLobbyInfo();
}
