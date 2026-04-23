class TCommunications_Handler;

struct RGE_Game_World {
    char gap_00[0x7C];
    short curr_player;
};

class RGE_Base_Game {
public:
    char gap_00[0x10];
    void* prog_window;
    char gap_14[0x178];
    TCommunications_Handler* comm_handler;
    char gap_190[0x204];
    RGE_Game_World* world;

    void show_comm(void);
};

class TCommunications_Handler {
public:
    char* GetCommInfo(unsigned char param_1);
};

extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_comm(void) {
    char str[256];
    sprintf(str, "%s", this->comm_handler->GetCommInfo(1));
    SetWindowTextA(this->prog_window, str);
}
