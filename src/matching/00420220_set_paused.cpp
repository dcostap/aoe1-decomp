class RGE_Base_Game {
public:
    char gap_00[0xA00];
    int save_paused;
    int non_user_pause;

    int get_paused(void);
    void request_pause(void);
    void set_paused(int paused, int non_user_pause);
};

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
