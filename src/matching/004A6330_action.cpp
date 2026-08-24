// 004A6330 TRIBE_Screen_Disconnect::action
//
// Attempt log:
// - Initial scratch used free-function wrappers for quit/close/destroy/base action. Behavior was right, but VC5 emitted
//   cdecl-style pushes/add esp and the wrong tail size.
// - SpruceGlow MATCH: use natural typed member-call surfaces for TRIBE_Game::quit_game, RGE_Base_Game::close,
//   TPanelSystem::destroyPanel, and base TEasy_Panel::action, with `panel_system` as an object rather than a pointer.
//   This gives the original thiscall call sequence and fallback argument passing.
// Result: MATCH locally with `python tools/check_function.py --va 004A6330`.

#ifndef SCR_MPS_TU_CONTEXT
class TPanel;

class RGE_Base_Game {
public:
    void close();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void quit_game();
};

extern TRIBE_Game* rge_base_game;

class TPanelSystem {
public:
    int destroyPanel(const char* name);
};

extern TPanelSystem panel_system;
extern const char s_Multiplayer_Disconnect_Screen[];
extern const char s_Status_Screen[];

class TEasy_Panel {
public:
    long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);
};

class TRIBE_Screen_Disconnect : public TEasy_Panel {
public:
    char gap_00[0x480];
    TPanel* cancel_button;
    TPanel* close_button;

    long action(TPanel* p1, long p2, unsigned long p3, unsigned long p4);
};
#endif

long TRIBE_Screen_Disconnect::action(TPanel* p1, long p2, unsigned long p3, unsigned long p4) {
    if (p1 != 0) {
        if (p1 == this->cancel_button && p2 == 1) {
            rge_base_game->quit_game();
            panel_system.destroyPanel(s_Multiplayer_Disconnect_Screen);
            panel_system.destroyPanel(s_Status_Screen);
            return 1;
        }
        if (p1 == this->close_button && p2 == 1) {
            rge_base_game->close();
            return 1;
        }
    }
    return TEasy_Panel::action(p1, p2, p3, p4);
}
