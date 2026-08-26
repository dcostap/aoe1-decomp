void RGE_Base_Game::reset_timings() {
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
    this->last_frame_count = 0;
    this->last_world_update_count = 0;
    this->last_view_update_count = 0;
    this->fps = 0;
    this->world_update_fps = 0;
    this->view_update_fps = 0;

    for (int i = 0; i < 30; ++i) {
        this->timings[i].accum_time = 0;
        this->timings[i].last_time = 0;
        this->timings[i].start_time = 0;
        this->timings[i].last_single_time = 0;
        this->timings[i].max_time = 0;
        this->timings[i].last_max_time = 0;
    }
}
