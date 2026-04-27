// scr_game.cpp:2051-2073, 105 bytes
// attempt 1: wrapper calls remove_message on 6 panels, forwards to base
class TMessagePanel {
public:
    void remove_message();
};

class TEasy_Panel {
public:
    long handle_mouse_down(unsigned char, long, long, int, int);
};

class TRIBE_Screen_Game : public TEasy_Panel {
public:
    char gap_00[0x544];
    TMessagePanel* msg_panel_0;
    TMessagePanel* msg_panel_1;
    TMessagePanel* msg_panel_2;
    TMessagePanel* msg_panel_3;
    TMessagePanel* msg_panel_4;
    TMessagePanel* msg_panel_5;

    long handle_mouse_down(unsigned char param1, long param2, long param3, int param4, int param5);
};

long TRIBE_Screen_Game::handle_mouse_down(unsigned char param1, long param2, long param3, int param4, int param5) {
    msg_panel_0->remove_message();
    msg_panel_1->remove_message();
    msg_panel_2->remove_message();
    msg_panel_3->remove_message();
    msg_panel_4->remove_message();
    msg_panel_5->remove_message();
    return TEasy_Panel::handle_mouse_down(param1, param2, param3, param4, param5);
}
