// VA: 004993B0 age_changed (237B)
// scr_game.cpp
// EH frame (/GX)

class TRIBE_Screen_Game {
public:
    char gap4[0x57C];
    int field_580;
    
    void age_changed();
};

void* __cdecl get_game_info(void* this_);

void TRIBE_Screen_Game::age_changed() {
    if (!field_580) return;
    
    void* info = get_game_info((void*)0x62C574);
    if (info) {
        field_580 = 0;
    }
}
