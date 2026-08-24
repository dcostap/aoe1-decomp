#ifndef TRIBEGAM_TU_CONTEXT
class TRIBE_Screen_Game {
public:
    void show_timings(void* param1, void* param2);
};

class TRIBE_Game {
public:
    char gap_0[0x404];
    int field_404;
    char gap_408[0xC24 - 0x408];
    TRIBE_Screen_Game* game_screen;
    char gap_C28[0x106C - 0xC28];
    int field_106C;

    void show_timings();
};
#endif

void TRIBE_Game::show_timings() {
    if (this->game_screen)
        this->game_screen->show_timings((void*)((char*)this + 0x404),
                                        (void*)((char*)this + 0x106C));
}
