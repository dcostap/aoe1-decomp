void RGE_Base_Game::receive_game_options(void)
{
    if (this->comm_handler != 0) {
        unsigned long size = 0;
        void* options = this->comm_handler->GetMyGameOptions(&size);
        if (options != 0 && size == 0xA8)
            this->set_game_options((RGE_Game_Options*)options);
    }
}
