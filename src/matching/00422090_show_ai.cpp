// tried the obvious sprintf/SetWindowTextA form; VC5 still shifts the stack buffer and call shape
// remaining gap is prolog/stack-layout drift around the local string buffer
struct RGE_Game_World {
    char gap_00[0x7C];
    short curr_player;
};

class RGE_Base_Game {
public:
    char gap_00[0x10];
    void* prog_window;
    char gap_14[0x3E0];
    RGE_Game_World* world;

    void show_ai(void);
};

extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_ai(void) {
    char str[256];
    sprintf(str, "No AI Information for Player #%d.", (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
}
