// 0041F9F0 RGE_Base_Game::restart_music_system (basegame.cpp:2876-2888, 149B)
// STATUS: GIVEN_UP (2026-05-19)
// FLAGS: default
//
// Remaining mismatch: size 149 vs 144 (body bytes identical; prologue/epilogue
// structure differs: register save order, save timing, epilogue sharing).
// Boss denied accepted_drift due to size mismatch preventing byte-level review.
//
// Attempt log (2026-05-19):
// try 1-2: baseline - register saves at prologue, merged epilogues = 144B vs 149
// try 3: restructured with goto + separate return paths to force inline epilogues - still 144B
// try 4: removed ms local variable, used this->music_system directly - still 144B
// try 5: flag tries /G5, /Os, /GA - no change
// GIVEUP: VC5 internal prologue/epilogue heuristic mismatch; cannot override register save order
//   (ebx,esi,edi vs edi,esi,ebx) or save timing (prologue vs after early-null-check) from C++ source.

class TMusic_System {
public:
    void play_track(int track_from, int pos, int loop);
    void play_tracks(int track_from, int track_to, int pos, int cur_track, int loop);
    void play_file(char* filename, int pos, int loop);
};

class RGE_Base_Game {
public:
    // vtable at +0x00 (implicit from virtual function)
    char gap_04[0x60];
    TMusic_System* music_system;   // +0x64
    char gap_68[0x0C];
    int save_music_track_from;      // +0x74
    int save_music_track_to;        // +0x78
    int save_music_cur_track;       // +0x7C
    char save_music_file[4];        // +0x80
    char gap_84[0x100];
    int save_music_pos;             // +0x184
    int save_music_loop;            // +0x188

    virtual int restart_music_system();
};

int RGE_Base_Game::restart_music_system()
{
    if (!this->music_system)
        return 1;

    int track_from = this->save_music_track_from;
    if (!track_from)
        goto check_file;

    if (track_from == this->save_music_track_to) {
        this->music_system->play_track(track_from, this->save_music_pos, this->save_music_loop);
        return 1;
    }

    if (this->save_music_track_to) {
        this->music_system->play_tracks(track_from, this->save_music_track_to,
            this->save_music_pos, this->save_music_cur_track, this->save_music_loop);
        return 1;
    }

check_file:
    if (this->save_music_file[0]) {
        this->music_system->play_file(this->save_music_file, this->save_music_pos, this->save_music_loop);
    }

    return 1;
}
