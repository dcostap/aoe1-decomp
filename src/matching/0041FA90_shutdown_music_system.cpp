// attempt 1: compile error on manual vtable call
// attempt 2: member offsets wrong, delete adds extra code
// attempt 3: operator delete, 80 bytes
// attempt 4-5: more cast errors
// attempt 6: virtual method at 0 offset, still 80 bytes
// attempt 7: try with padding virtuals

class TRegistry;



void operator delete(void* p);


void RGE_Base_Game::shutdown_music_system() {
    if (music_system == 0) return;
    this->stop_music_system();
    registry->RegSetInt(1, "Music Volume", -music_system->volume);
    TMusic_System* p = music_system;
    if (p != 0) {
        p->~TMusic_System();
        operator delete(p);
    }
    music_system = 0;
}
