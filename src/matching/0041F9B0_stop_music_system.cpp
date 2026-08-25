


void RGE_Base_Game::stop_music_system(void) {
    if (this->music_system != 0) {
        this->music_system->get_play_info(&this->save_music_type, &this->save_music_track_from, &this->save_music_track_to, &this->save_music_cur_track, this->save_music_file, &this->save_music_loop, &this->save_music_pos);
        this->music_system->stop_track();
    }
}
