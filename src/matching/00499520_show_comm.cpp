// VA: 00499520 show_comm (175B)
// scr_game.cpp

#if !defined(SCR_GAME_TU_CONTEXT)
class TMessagePanel {
public:
    void show_message(int type, char* text, int a, int b, void* c, int d, int e);
};

class TRIBE_Screen_Game {
public:
    char gap_000[0x544];
    TMessagePanel* message_panel1; // +0x544
    TMessagePanel* message_panel2; // +0x548
    TMessagePanel* message_panel3; // +0x54C
    TMessagePanel* message_panel4; // +0x550
    TMessagePanel* message_panel5; // +0x554
    TMessagePanel* message_panel6; // +0x558

    void show_comm(char* p1, char* p2, char* p3, char* p4, char* p5, char* p6);
};
#endif

void TRIBE_Screen_Game::show_comm(char* p1, char* p2, char* p3, char* p4, char* p5, char* p6) {
    message_panel1->show_message(2, p1, 0x56, 0, 0, 0, 0);
    message_panel2->show_message(2, p2, 0x56, 0, 0, 0, 0);
    message_panel3->show_message(2, p3, 0x56, 0, 0, 0, 0);
    message_panel4->show_message(2, p4, 0x56, 0, 0, 0, 0);
    message_panel5->show_message(2, p5, 0x56, 0, 0, 0, 0);
    message_panel6->show_message(2, p6, 0x56, 0, 0, 0, 0);
}
