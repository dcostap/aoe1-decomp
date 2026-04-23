class RGE_Base_Game;

class TCommunications_Handler {
public:
    void* GetMyGameOptions(unsigned long* size);
};

class RGE_Base_Game {
public:
    void* vtable_ptr;
    char gap_04[0x188];
    TCommunications_Handler* comm_handler;

    void set_game_options(void* options);
    void receive_game_options(void);
};

void RGE_Base_Game::receive_game_options(void) {
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8) {
            this->set_game_options(options);
        }
    }
}
