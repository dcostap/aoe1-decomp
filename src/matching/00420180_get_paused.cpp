// BINARY NOTE: the shipped compare uses prog_mode at +0x1B0.
// BINARY NOTE: the shipped tail targets TCommunications_Handler::IsPaused.
struct CommsHandler {
    int IsPaused();
};


int RGE_Base_Game::get_paused()
{
    if (this->prog_mode == 7)
        return 0;
    return this->comms_handler->IsPaused();
}
