// VA: 0053DBA0 RGE_Main_View::do_auto_scroll (vw_main.cpp:99-250)
//
// Clean baseline reconstruction: the view owns the player and panel state;
// the two short scroll directions are kept separate from the distance value.
// Attempt log:
// - Baseline had the wrong class/function surface; rebuilt typed RGE_Main_View,
//   RGE_View, RGE_Player, RGE_Prog_Info, panel-system, and Win32 ownership.
// - Positive outer guard with a cold failure tail restored exact 773-byte size,
//   all 15 ordered calls, and the original guard CFG.
// - The binary uses the interval at prog_info+0x8D0; the working source names
//   that shared period scroll interval as key_scroll_interval, matching the
//   sibling handle_keys surface.
// - Computing elapsed before the mouse-scrolling gate restored the exact 0x2C
//   frame and the original unsigned-delta/x87 conversion setup.
// - Fractional scroll quantization is kept as ordinary in-place subtraction,
//   threshold selection, and whole-unit addition; declaration/order/layout
//   variants were codegen duplicates. Ten bounded hypotheses exhausted.
// - Final source is normalized to typed Win32 output records and direct record
//   addresses; the odd raw stack anchors in the decompiler are not retained as
//   source semantics. Remaining drift is localized to record homes and x87
//   quantization/block placement; calls, fields, frame, and behavior topology
//   are aligned.
// - shardB5-53DBA0 tested natural whole-plus-fraction expressions and threshold
//   branch forms. The retained branch-local addition reduces the size gap to 2
//   bytes and keeps the original call set and CFG; other forms were duplicates
//   or widened the structural gap. The remaining lead is the x87 faddp block.

typedef void* HWND;

struct tagPOINT {
    long x;
    long y;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[4];
    HWND Wnd;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void set_redraw(int mode);

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];
};

class RGE_Prog_Info {
public:
    char gap_00[0x8C0];
    int auto_scroll;
    long mouse_scroll_edge;
    unsigned long mouse_scroll_interval;
    float mouse_scroll_max_dist;
    unsigned long key_scroll_interval;
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;
    char gap_10[0x1A0];
    int prog_mode;

    int get_paused();
};

class TPanelSystem {
public:
    TPanel* modalPanel();
    TPanel* mouseOwner();
};

class RGE_Player {
public:
    void* vtable_ptr;
    char gap_04[0x110];
    float view_x;
    float view_y;

    void set_view_loc(float x, float y);
};

class RGE_View : public TPanel {
public:
    char gap_F4[0x0C];
    RGE_Player* player;
    char gap_104[0x25C];
};

class RGE_Main_View : public RGE_View {
public:
    TPanel* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;

    int do_auto_scroll();
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

extern "C" __declspec(dllimport) HWND __stdcall GetForegroundWindow(void);
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(HWND hWnd, tagRECT* rect);
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(tagPOINT* point);
extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int key);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern const float DAT_00577900;
extern const float DAT_00577904;
extern const float DAT_00577908;

int RGE_Main_View::do_auto_scroll()
{
    tagRECT rect;
    tagPOINT point;
    float scroll_dist2;
    short vert_scroll;
    short horz_scroll;
    RGE_Prog_Info* info;
    unsigned long now;
    unsigned long elapsed;

    if ((rge_base_game->prog_mode == 4 || rge_base_game->prog_mode == 6 ||
         rge_base_game->prog_mode == 7 || rge_base_game->prog_mode == 5) &&
        rge_base_game->get_paused() == 0 &&
        rge_base_game->prog_info->auto_scroll != 0 &&
        GetForegroundWindow() == this->render_area->Wnd &&
        panel_system.modalPanel() == 0 &&
        (panel_system.mouseOwner() == 0 || panel_system.mouseOwner() == this) &&
        this->key_scrolling == 0) {

    GetWindowRect(this->render_area->Wnd, &rect);
    GetCursorPos(&point);

    horz_scroll = 0;
    vert_scroll = 0;
    info = rge_base_game->prog_info;

    if (GetAsyncKeyState(1) >= 0 && GetAsyncKeyState(2) >= 0) {
        if (point.y < rect.top + info->mouse_scroll_edge)
            vert_scroll = -1;
        else if (point.y > rect.bottom - info->mouse_scroll_edge)
            vert_scroll = 1;

        if (point.x < rect.left + info->mouse_scroll_edge)
            horz_scroll = -1;
        else if (point.x > rect.right - info->mouse_scroll_edge)
            horz_scroll = 1;

        if (vert_scroll != 0 || horz_scroll != 0) {
            now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0xAA);
            elapsed = now - this->last_mouse_scroll_time;
            if (this->mouse_scrolling == 0) {
                scroll_dist2 = DAT_00577900;
                this->mouse_scrolling = 1;
            } else {
                scroll_dist2 = (float)elapsed / info->key_scroll_interval;
                {
                    long whole = (long)scroll_dist2;
                    scroll_dist2 -= whole;
                    if (scroll_dist2 >= DAT_00577904)
                    {
                        scroll_dist2 = DAT_00577904;
                        scroll_dist2 += (float)whole;
                    }
                    else
                    {
                        scroll_dist2 = DAT_00577908;
                        scroll_dist2 += (float)whole;
                    }
                }
            }

            if (scroll_dist2 > info->mouse_scroll_max_dist)
                scroll_dist2 = info->mouse_scroll_max_dist;

            if (scroll_dist2 > DAT_00577908) {
                float scroll_dist = scroll_dist2 + scroll_dist2;
                if (vert_scroll == -1)
                    this->player->set_view_loc(this->player->view_x - scroll_dist2,
                                               this->player->view_y - scroll_dist2);
                else if (vert_scroll == 1)
                    this->player->set_view_loc(this->player->view_x + scroll_dist2,
                                               this->player->view_y + scroll_dist2);

                if (horz_scroll == -1)
                    this->player->set_view_loc(this->player->view_x + scroll_dist,
                                               this->player->view_y - scroll_dist);
                else if (horz_scroll == 1)
                    this->player->set_view_loc(this->player->view_x - scroll_dist,
                                               this->player->view_y + scroll_dist);

                this->set_redraw(1);
                if (this->map_view != 0)
                    this->map_view->set_redraw(1);
                this->last_mouse_scroll_time = now;
            }
        }
    }

    if (vert_scroll == 0 && horz_scroll == 0)
        this->mouse_scrolling = 0;
    return this->mouse_scrolling;
    }

fail:
    this->mouse_scrolling = 0;
    return 0;
}
