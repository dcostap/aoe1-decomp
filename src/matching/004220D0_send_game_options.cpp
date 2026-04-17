struct CommsHandler {
    void send_options(void* data, int size);
};

class RGE_Base_Game {
public:
    char gap_0[0x18C];
    CommsHandler* comms_handler; // offset 0x18C
    char gap_190[0x768];
    char options_data[0xA8]; // offset 0x8F8

    void send_game_options();
};

void RGE_Base_Game::send_game_options()
{
    if (this->comms_handler)
        this->comms_handler->send_options(this->options_data, 0xA8);
}
