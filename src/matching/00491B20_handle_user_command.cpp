// Exact reconstruction of TribeJoinScreen::handle_user_command.
//
// The local inherited stubs preserve the proven derived boundary: the
// implicit TPanel vptr plus its 0xF4-byte body and the 0x380-byte TEasy_Panel
// tail place the named TribeJoinScreen fields at +0x478 and
// waitingToStart at +0x4A8 as shown by the neighboring methods.
// The target's response file retains /GX because the real constructor call
// establishes the original EH registration frame.
//
// Attempt log:
// - baseline: natural command switch and named waitingToStart ownership;
//   explicit free constructor wrapper left the call target/cleanup wrong.
// - abi: use the real TribeMPSetupScreen class constructor through `new`,
//   restoring the 0x890 allocation and direct constructor call.
// - control-flow: retain the binary-backed no-op 0x17A4 case so VC5 emits
//   the original dense switch range (0x17A4..0x17B8); all other unhandled
//   commands still fall through to TPanel::handle_user_command.
// - layout audit: represent the implicit TPanel vptr plus a 0xF4-byte body
//   gap rather than an explicit vftable data member; this preserves the
//   canonical 0xF4 base size and exact output.
// - Main-agent audit restored canonical base-game destructor ownership;
//   emitted code remains exact.

#include "../../include/scr_cj_context.h"

#if 0
struct tagRECT;

class TTextPanel;
class TListPanel;
class TScrollBarPanel;
class TButtonPanel;

class TPanel {
public:
    virtual ~TPanel();
    char pad[0xF4];
    virtual long handle_user_command(unsigned int cmd, long param);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x380];
    void popupOKDialog(long title_id, char* msg, long body_id, long button_count);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_4[0x1D4];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TCommunications_Handler {
public:
    void UnlinkToLevel(int param);
};

extern TCommunications_Handler* comm;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, long param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TribeMPSetupScreen {
public:
    TribeMPSetupScreen();
    char pad[0x890];
};

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TTextPanel* title;
    TTextPanel* listTitle;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* joinButton;
    TButtonPanel* createButton;
    TButtonPanel* cancelButton;
    TButtonPanel* refreshButton;
    TButtonPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    virtual long handle_user_command(unsigned int cmd, long param);
};
#endif

long TribeJoinScreen::handle_user_command(unsigned int cmd, long param) {
    switch (cmd) {
        case 0x17A4:
            break;
        case 0x17B8:
            if (this->waitingToStart != 0) {
                new TribeMPSetupScreen;
                panel_system.setCurrentPanel("MP Setup Screen", 0);
                panel_system.destroyPanel("Join Screen");
                return 1;
            }
            break;
        case 0x17A8:
        case 0x17A9:
        case 0x17AA:
        case 0x17B2:
            if (this->waitingToStart != 0) {
                comm->UnlinkToLevel(5);
                this->waitingToStart = 0;
                rge_base_game->enable_input();
                TEasy_Panel::popupOKDialog(0x25A3, 0, 0x1C2, 100);
                return 1;
            }
            break;
    }
    return TPanel::handle_user_command(cmd, param);
}
