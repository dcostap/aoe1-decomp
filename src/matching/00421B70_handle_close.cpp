



int RGE_Base_Game::handle_close(void* param_1, unsigned int param_2, unsigned int param_3, long param_4) {
    if (this->action_close() == 0) {
        return 0;
    }
    if (this->draw_area != 0 && this->draw_system != 0) {
        this->draw_area->Clear(0, 0);
        this->draw_system->Paint(0);
    }
    return 1;
}
