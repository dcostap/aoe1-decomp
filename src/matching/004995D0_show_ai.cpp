// VA: 004995D0 TRIBE_Screen_Game::show_ai
// scr_game.cpp:3365-3372
// Retry 2026-05-24: replaced stale stub with packet-derived six-panel show_message wrapper.

#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int type, char* text, int color, int a4, int a5, int a6, int a7);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x544];
    TMessagePanel* ai_panel_1;
    TMessagePanel* ai_panel_2;
    TMessagePanel* ai_panel_3;
    TMessagePanel* ai_panel_4;
    TMessagePanel* ai_panel_5;
    TMessagePanel* ai_panel_6;

    void show_ai(char* a1, char* a2, char* a3, char* a4, char* a5, char* a6);
};
#endif

void TRIBE_Screen_Game::show_ai(char* a1, char* a2, char* a3, char* a4, char* a5, char* a6)
{
    this->ai_panel_1->show_message(2, a1, 0x56, 0, 0, 0, 0);
    this->ai_panel_2->show_message(2, a2, 0x56, 0, 0, 0, 0);
    this->ai_panel_3->show_message(2, a3, 0x56, 0, 0, 0, 0);
    this->ai_panel_4->show_message(2, a4, 0x56, 0, 0, 0, 0);
    this->ai_panel_5->show_message(2, a5, 0x56, 0, 0, 0, 0);
    this->ai_panel_6->show_message(2, a6, 0x56, 0, 0, 0, 0);
}
