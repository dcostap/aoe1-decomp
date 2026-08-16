struct CommsHandler {
    void request_pause();
};

struct World {
    char gap_0[0x1C];
    char paused_flag;
};

class RGE_Base_Game {
public:
    char gap_0[0x18C];
    CommsHandler* comms_handler; // offset 0x18C
    char gap_190[0x264];
    World* world_ptr; // offset 0x3F4

    void request_pause();
};

void RGE_Base_Game::request_pause()
{
    this->comms_handler->request_pause();
    if (this->world_ptr)
        this->world_ptr->paused_flag = 1;
}
