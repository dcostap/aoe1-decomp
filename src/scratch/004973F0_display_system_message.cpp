// tried the direct panel-array call and then a self/panel local pair; mismatch stayed at the first push/mov order in the prolog
// the message ring layout at 0x55C/0x724 is behaving, but VC5 keeps slipping one zero-push ahead of the saved-esi basin
// leaving in scratch: remaining delta is prolog instruction order, not the show_message arguments or index update

class TMessagePanel {
public:
    void show_message(int type, char* text, unsigned char a3, unsigned char a4, void* user, int x, int y, int z);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x55C];
    TMessagePanel* message_panels[0x72];
    int message_index;

    void display_system_message(char* text);
};

void TRIBE_Screen_Game::display_system_message(char* text) {
    TRIBE_Screen_Game* self = this;
    TMessagePanel* panel = self->message_panels[self->message_index];
    panel->show_message(3, text, 0xFF, 0, 0, 0, 0, 0);
    self->message_index++;
    if (self->message_index >= 8) {
        self->message_index = 0;
    }
}
