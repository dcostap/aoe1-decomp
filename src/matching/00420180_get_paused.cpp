// STATUS: scratch
// FLAGS: config\flags\00420180_get_paused.rsp

struct CommsHandler {
    int get_paused();
};

class RGE_Base_Game {
public:
    char gap_0[0x18C];
    CommsHandler* comms_handler;
    char gap_190[0x20];
    int game_mode; // offset 0x1B0

    int get_paused();
};

int RGE_Base_Game::get_paused()
{
    if (this->game_mode == 7)
        return 0;
    return this->comms_handler->get_paused();
}
