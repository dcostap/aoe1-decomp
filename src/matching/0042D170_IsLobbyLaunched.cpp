#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Lobby {
public:
    int IsLobbyLaunched();
};
#endif // COM_HAND_TU_CONTEXT

#if !defined(COM_HAND_TU_CONTEXT)
class TCommunications_Handler {
public:
    char gap_0[0x14CC];
    RGE_Lobby* Lobby;
    int IsLobbyLaunched();
};
#endif // COM_HAND_TU_CONTEXT


int TCommunications_Handler::IsLobbyLaunched() {
    return this->Lobby->IsLobbyLaunched();
}
