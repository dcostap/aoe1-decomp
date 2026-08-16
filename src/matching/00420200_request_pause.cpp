// VA: 00420200 RGE_Base_Game::request_pause
// Exact under VC5 host with default /O2 /Oy flags.
// Call TogglePauseGame through comm_handler at +0x18C, then set world
// temp_pause at +0x3F4/+0x1C. Keep the call before the null-guarded store.

class TCommunications_Handler {
public:
    void TogglePauseGame();
};

class RGE_Game_World {
public:
    char gap_0[0x1C];
    char temp_pause;
};

class RGE_Base_Game {
public:
    char gap_0[0x18C];
    TCommunications_Handler* comm_handler; // offset 0x18C
    char gap_190[0x264];
    RGE_Game_World* world; // offset 0x3F4

    void request_pause();
};

void RGE_Base_Game::request_pause()
{
    this->comm_handler->TogglePauseGame();
    if (this->world)
        this->world->temp_pause = 1;
}
