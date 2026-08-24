// tried the direct panel-array call and then a self/panel local pair; mismatch stayed at the first push/mov order in the prolog
// fixed the local TMessagePanel signature to the matched 7-arg surface used by nearby wrappers/handlers.

#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int type, char* text, unsigned char a3, unsigned char a4, void* user, int x, int y);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x55C];
    TMessagePanel* message_panels[0x72];
    int message_index;

    void display_system_message(char* text);
};
#endif

void TRIBE_Screen_Game::display_system_message(char* text) {
    this->message_panels[this->message_index]->show_message(3, text, 0xFF, 0, 0, 0, 0);
    this->message_index++;
    if (this->message_index >= 8) {
        this->message_index = 0;
    }
}
