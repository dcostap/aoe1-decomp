// 0049C1B0 command_diplomacy
// 122 bytes, __thiscall, TRIBE_Screen_Game method
// probe 1: /GX EH, check paused, create TribeDiplomacyDialog

class TScreenPanel {};

class TribeDiplomacyDialog {
public:
};

class RGE_Base_Game;
int RGE_Base_Game_get_paused(RGE_Base_Game* game);
int RGE_Base_Game_singlePlayerGame(RGE_Base_Game* game);
void RGE_Base_Game_set_paused(RGE_Base_Game* game, int paused, int param);
void __cdecl TribeDiplomacyDialog_ctor(TribeDiplomacyDialog* self, TScreenPanel* screen);

extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);

class TRIBE_Screen_Game : public TScreenPanel {
public:
    void command_diplomacy();
};

void TRIBE_Screen_Game::command_diplomacy() {
    int paused = RGE_Base_Game_get_paused(rge_base_game);
    if (paused == 0) {
        int single = RGE_Base_Game_singlePlayerGame(rge_base_game);
        if (single == 1) {
            RGE_Base_Game_set_paused(rge_base_game, 1, 1);
        }
        TribeDiplomacyDialog* dialog = (TribeDiplomacyDialog*)operator new(0x6B8);
        if (dialog != 0) {
            TribeDiplomacyDialog_ctor(dialog, this);
        }
    }
}
