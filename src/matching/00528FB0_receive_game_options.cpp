class RGE_Base_Game;
class TRIBE_Game;

class TCommunications_Handler {
public:
    void* GetMyGameOptions(unsigned long* size);
};

class RGE_Base_Game {
public:
    void set_game_options(void* options);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_00[0x18C];
    TCommunications_Handler* comm_handler;

    void set_tribe_options(void* options);
    void receive_game_options(void);
};

void TRIBE_Game::receive_game_options(void) {
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0x114) {
            this->set_game_options(options);
            this->set_tribe_options((char*)options + 0xA8);
        }
    }
}
