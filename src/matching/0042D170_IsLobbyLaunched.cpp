struct Inner_D170 {
    int IsLobbyLaunched();
};

class RGE_Base_Game {
public:
    char gap_0[0x14CC];
    Inner_D170 *ptr;
    int IsLobbyLaunched();
};

int RGE_Base_Game::IsLobbyLaunched() {
    return this->ptr->IsLobbyLaunched();
}
