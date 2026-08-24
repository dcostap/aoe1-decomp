#ifndef TRIBEGAM_TU_CONTEXT
class TCommunications_Handler {
public:
    void SetMyGameOptions(void* data, int size);
};

class RGE_Base_Game {
public:
    char gap_00[0x18C];
    TCommunications_Handler* comms_handler;

    void get_game_options(void* dst);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void get_tribe_options(void* dst);
    void send_game_options(void);
};
#endif

void TRIBE_Game::send_game_options(void) {
    char combined_options[0x114];

    if (this->comm_handler != 0) {
        this->get_game_options(combined_options);
        this->get_tribe_options(&combined_options[0xA8]);
        this->comm_handler->SetMyGameOptions(combined_options, 0x114);
    }
}
