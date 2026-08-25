struct CommsHandler {
    int get_paused();
};


int RGE_Base_Game::get_paused()
{
    if (this->game_mode == 7)
        return 0;
    return this->comms_handler->get_paused();
}
