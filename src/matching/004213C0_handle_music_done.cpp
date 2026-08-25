

int RGE_Base_Game::handle_music_done(void* p0, unsigned int p1,
                                     unsigned int p2, long p3) {
    return this->action_music_done() != 0;
}
