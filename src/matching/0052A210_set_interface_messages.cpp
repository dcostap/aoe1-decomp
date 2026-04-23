class MouseClickInfo;
class TRIBE_Screen_Game {
public:
    char gap_00[0x8DC];
    unsigned short interface_messages;
};

class TRIBE_Game {
public:
    char gap_00[0xC];
    TRIBE_Screen_Game* game_screen;

    void SetClickTables(MouseClickInfo* p1, int p2, MouseClickInfo* p3, int p4);
    void set_interface_messages();
};

void TRIBE_Game::set_interface_messages() {
    if (this->game_screen->interface_messages == 1) {
        this->SetClickTables((MouseClickInfo*)0x589DD8, *(int*)0x58AB98, (MouseClickInfo*)0x58A4B8, *(int*)0x58AB9C);
        return;
    }
    this->SetClickTables((MouseClickInfo*)0x589010, *(int*)0x589DD0, (MouseClickInfo*)0x5896F0, *(int*)0x589DD4);
}
