// VA: 0049BAF0 handle_mouse_pointing_at (358B)
// scr_game.cpp:4717-4840
// Natural same-TU reconstruction of the foreground/focus/modal gate, mouse
// position tracking, map pick, and button tooltip scan.
// Attempt log (sa-66340ab1-handle_mouse_pointing_at):
// - baseline typed source had exact frame/call/CFG but a -6-byte base-layout
//   shift and a broad loop mismatch.
// - restored the canonical 0xF4 TPanel/0x478 TScreenPanel sizes; this aligned
//   all screen fields and isolated the button scan.
// - reloaded *slot for the enabled/get_id/virtual-action checks, preserving the
//   binary's slot-address liveness and inline help-text ownership.
// - changed the ordinary do/while to a natural while(i < 17) header; VC5 then
//   emitted the original jl backedge/jmp-over-found-arm and all 358 bytes match.
// - Main-agent audit restored canonical base-game destructor ownership and
//   retained the typed panel/button scan; exact bytes were revalidated.

extern "C" __declspec(dllimport) void* __stdcall GetForegroundWindow(void);

struct tagPOINT {
    long x;
    long y;
};

class RGE_Tile;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_004[0x0C];
    void* prog_window;               // +0x10

    void get_mouse_pos(tagPOINT& point);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual ~TPanel();

    char gap_004[0x08];
    long pnl_x;                      // +0x0C
    long pnl_y;                      // +0x10
    long pnl_wid;                    // +0x14
    long pnl_hgt;                    // +0x18
    char gap_01C[0x04];
    char gap_020[0x1C];
    char gap_03C[0xB8];

    int get_focus();
};

class RGE_Main_View : public TPanel {
public:
    char gap_0F4[0x248];
    int message_active;              // +0x33C
};

class RGE_Diamond_Map {
public:
    virtual ~RGE_Diamond_Map();

    int pick_tile(long x, long y, short* out_x, short* out_y,
                  RGE_Tile** tile);
};

class TPanelSystem {
public:
    int modalPanel();
};

extern TPanelSystem panel_system;

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    VPAD32(0)
    VPAD16(32)
    VPAD8(48)
    virtual int button_action(long x, long y);

    char gap_004[0x68];
    int enabled;                     // +0x6C
    char gap_070[0x260];
    char help_text[260];             // +0x2D0

    long get_id();
};

class TMessagePanel {
public:
    void remove_message();
    void show_message(int type, char* text, int color1, int color2,
                      int color3, int color4, int color5);
};

class TScreenPanel : public TPanel {
public:
    char gap_0F4[0x384];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x40];
    RGE_Main_View* main_view;         // +0x4B8
    RGE_Diamond_Map* map_view;        // +0x4BC
    char gap_4C0[0x08];
    TButtonPanel* button_panel[17];  // +0x4C8
    TMessagePanel* text_line_panel;   // +0x50C
    char gap_510[0x1F8];
    long last_mouse_x;                // +0x708
    long last_mouse_y;                // +0x70C

    void handle_mouse_pointing_at();
};

void TRIBE_Screen_Game::handle_mouse_pointing_at() {
    void* window = rge_base_game->prog_window;
    if (GetForegroundWindow() != window) {
        return;
    }
    if (this->main_view->get_focus() == 0) {
        return;
    }
    if (panel_system.modalPanel() != 0) {
        return;
    }

    tagPOINT point;
    rge_base_game->get_mouse_pos(point);
    if (point.x == this->last_mouse_x && point.y == this->last_mouse_y) {
        return;
    }

    this->last_mouse_x = point.x;
    this->last_mouse_y = point.y;

    if (this->main_view->message_active == 0) {
        this->text_line_panel->remove_message();
    }

    if (point.x < 0 || point.x >= this->pnl_wid ||
        point.y < 0 || point.y > this->pnl_hgt) {
        return;
    }

    short row;
    short col;
    RGE_Tile* tile;
    if (this->map_view->pick_tile(point.x, point.y, &row, &col, &tile) != 0) {
        return;
    }

    short found = -1;
    short i = 0;
    while (i < 0x11) {
        TButtonPanel** slot = &this->button_panel[i];
        if ((*slot)->enabled != 0 && (*slot)->get_id() != -1 &&
            (*slot)->button_action(point.x, point.y) != 0) {
            found = i;
            break;
        }
        ++i;
    }

    if (found != -1) {
        this->text_line_panel->show_message(
            0, this->button_panel[found]->help_text, 0xFF, 0, 0, 0, 0);
    }
}
