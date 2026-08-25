

void RGE_Base_Game::set_paused(int paused, int non_user_pause) {
    this->save_paused = this->get_paused();
    if (paused != this->save_paused) {
        if (paused != 0) {
            this->non_user_pause = non_user_pause;
        } else {
            this->non_user_pause = 0;
        }
        this->request_pause();
    }
}
