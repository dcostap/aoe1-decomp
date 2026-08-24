#ifndef BASEGAME_GROUPED_TU
class TMusic_System {
public:
    int get_play_info(unsigned char* music_type, int* start_track, int* end_track, int* current_track, char* file_name, int* loop, unsigned long* set_pos);
    int stop_track(void);
};

class RGE_Base_Game {
public:
    char gap_00[0x64];
    TMusic_System* music_system;
    char gap_68[0x8];
    unsigned char save_music_type;
    char gap_71[0x3];
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;

    void stop_music_system(void);
};
#endif

void RGE_Base_Game::stop_music_system(void) {
    if (this->music_system != 0) {
        this->music_system->get_play_info(&this->save_music_type, &this->save_music_track_from, &this->save_music_track_to, &this->save_music_cur_track, this->save_music_file, &this->save_music_loop, &this->save_music_pos);
        this->music_system->stop_track();
    }
}
