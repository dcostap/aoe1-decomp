void RGE_Base_Game::send_game_options()
{
    if (this->comm_handler)
        this->comm_handler->SetMyGameOptions(this->game_options, 0xA8);
}
