#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int type, char* text, unsigned char a3, unsigned char a4, void* user, int x, int y);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x544];
    TMessagePanel* message_panel;

    void show_message(int type, char* text, unsigned char a3, unsigned char a4);
};
#endif

void TRIBE_Screen_Game::show_message(int type, char* text, unsigned char a3, unsigned char a4) {
    this->message_panel->show_message(type, text, a3, a4, 0, 0, 0);
}
