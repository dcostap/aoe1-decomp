// 0049C1B0 command_diplomacy
// 122 bytes, __thiscall, TRIBE_Screen_Game method

#if !defined(SCR_GAME_TU_CONTEXT)
class TScreenPanel {};

class TribeDiplomacyDialog {
public:
    char data[0x6B8];
    TribeDiplomacyDialog(TScreenPanel* screen);
};

class RGE_Base_Game {
public:
    int get_paused();
    int singlePlayerGame();
    void set_paused(int paused, int param);
};

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);

class TRIBE_Screen_Game : public TScreenPanel {
public:
    void command_diplomacy();
};
#endif

void TRIBE_Screen_Game::command_diplomacy() {
    if (rge_base_game->get_paused() == 0) {
        if (rge_base_game->singlePlayerGame() == 1) {
            rge_base_game->set_paused(1, 1);
        }
        TribeDiplomacyDialog* dialog = new TribeDiplomacyDialog(this);
    }
}
