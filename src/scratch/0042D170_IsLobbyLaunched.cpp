struct Inner_D170 {
    int IsLobbyLaunched();
};

#if !defined(COM_HAND_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_0[0x14CC];
    Inner_D170 *ptr;
    int IsLobbyLaunched();
};
#endif // COM_HAND_TU_CONTEXT


int RGE_Base_Game::IsLobbyLaunched() {
    return ((Inner_D170*)this->ptr)->IsLobbyLaunched();
}
