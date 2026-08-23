// VA: 00422090 RGE_Base_Game::show_ai (61 B)
// PDB source: basegame.cpp:4965-4970
// PDB owner: protected virtual ?show_ai@RGE_Base_Game@@MAEXXZ
// The next PDB owner starts at 004220D0.  Keep this owner through 004220CF.
// BINARY NOTE: The executable reads world->curr_player before it rereads
// prog_window for SetWindowTextA.  Do not add state or null checks.
// Exact-finish: the prior body used a public nonvirtual owner and emitted
// QAEXXZ.  The real protected virtual ABI emits MAEXXZ with the same 61 bytes.
// The grouped /O2 /Oy /GX build also extracts this owner at the same boundary.
struct RGE_Game_World_Show_Ai_Overlay {
    char gap_00[0x7C];
    short curr_player;
};

#ifndef BASEGAME_SEGMENT_CONTEXT
class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

protected:
    virtual void show_ai(void);
    char gap_00[0x0C];
    void* prog_window;
    char gap_14[0x3E0];
    RGE_Game_World* world;
};
#else
// The preceding calc_timings owner supplies the canonical RGE_Base_Game and
// RGE_Game_World declarations.  These views retain only the proved fields.
struct RGE_Base_Game_Show_Ai_Overlay {
    char gap_00[0x10];
    void* prog_window;
    char gap_14[0x3E0];
    RGE_Game_World* world;
};
#endif

extern "C" int sprintf(char*, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall SetWindowTextA(void*, const char*);

void RGE_Base_Game::show_ai(void) {
    char str[256];
#ifdef BASEGAME_SEGMENT_CONTEXT
    RGE_Base_Game_Show_Ai_Overlay* view =
        (RGE_Base_Game_Show_Ai_Overlay*)this;
    sprintf(str, "No AI Information for Player #%d.",
        (int)((RGE_Game_World_Show_Ai_Overlay*)view->world)->curr_player);
    SetWindowTextA(view->prog_window, str);
#else
    sprintf(str, "No AI Information for Player #%d.",
        (int)this->world->curr_player);
    SetWindowTextA(this->prog_window, str);
#endif
}
