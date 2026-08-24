// VA: 00524A80
// TRIBE_Game::show_comm()
// Source: tribegam.cpp lines 2085-2095

// attempt 1: natural chain with accumulated GetCommInfo results -> EXACT MATCH (110/110, 0.0000%)
// default flags; VC5 evaluates args right-to-left, matching the accumulated-stack pattern

#ifndef TRIBEGAM_TU_CONTEXT
class TCommunications_Handler {
public:
    // 0042CD50
    char* GetCommInfo(int index);
};

class TRIBE_Screen_Game {
public:
    // 00499520
    void show_comm(char* a, char* b, char* c, char* d, char* e, char* f);
};

class TRIBE_Game {
public:
    char gap_000[0x18C];
    TCommunications_Handler* comm_handler;  // +0x18C
    char gap_190[0xA94];  // 0xC24 - 0x190 = 0xA94
    TRIBE_Screen_Game* game_screen;         // +0xC24

    void show_comm();
};
#endif

void TRIBE_Game::show_comm() {
    if (this->game_screen == 0) return;

    // VC5 evaluates args right-to-left, accumulating results on stack
    this->game_screen->show_comm(
        this->comm_handler->GetCommInfo(1),
        this->comm_handler->GetCommInfo(2),
        this->comm_handler->GetCommInfo(3),
        this->comm_handler->GetCommInfo(4),
        this->comm_handler->GetCommInfo(5),
        this->comm_handler->GetCommInfo(6)
    );
}
