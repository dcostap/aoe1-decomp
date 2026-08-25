// VA: 00420200 RGE_Base_Game::request_pause
// Exact under VC5 host with default /O2 /Oy flags.
// Call TogglePauseGame through comm_handler at +0x18C, then set world
// temp_pause at +0x3F4/+0x1C. Keep the call before the null-guarded store.




void RGE_Base_Game::request_pause()
{
    this->comm_handler->TogglePauseGame();
    if (this->world)
        this->world->temp_pause = 1;
}
