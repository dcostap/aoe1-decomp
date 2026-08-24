// VA: 004970A0 wnd_proc (354B)
// scr_game.cpp:2005-2045
// Natural same-TU reconstruction of the game-screen window dispatch: menu and
// pause-key shortcuts, close confirmation, notification jump, then TPanel's
// default window procedure.
// Attempt log (sa-66340ab1-wnd_proc):
// - baseline reached exact size/frame/call count and 329/354 resynchronized
//   bytes; the only early layout issue was the inherited +0x20/+0x3C/+0x78
//   TPanel field surface.
// - corrected the canonical TPanel base padding, moving input_window to +0x78;
//   this localized the remaining drift to the IsIconic receiver.
// - modeled the DrawSurface vptr so its hwnd is at +4; the natural typed source
//   now matches all 354 bytes, including GetKeyState IAT and base fallback.
// - Main-agent audit restored canonical game/draw-area ownership and replaced
//   the raw dialog-text address with a named symbol; exact bytes were revalidated.

#if !defined(SCR_GAME_TU_CONTEXT)
extern "C" short (__stdcall* GetKeyState)(int);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd);
extern int confirmed_close;

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x1AC];
    int prog_mode;

    void goto_notification_loc();
};

extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    void* draw_system;
    void* hwnd;
};

class TPanel {
public:
    virtual ~TPanel();

    char gap_004[0x1C];
    TDrawArea* draw_surface;          // +0x20
    char gap_24[0x18];
    void* panel_state;               // +0x3C
    char gap_40[0x38];
    void* input_window;              // +0x78
    char gap_7C[0x78];

    int get_focus();
    long wnd_proc(void* window, unsigned int message,
                  unsigned int wparam, long lparam);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    void popupYesNoDialog(long string_id, char* message, int width, int height);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_View_Panel : public TPanel {
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x40];
    RGE_View_Panel* main_view;       // +0x4B8

    void command_menu();
    void command_pause();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
};
#endif

extern char close_confirmation_text[];

long TRIBE_Screen_Game::wnd_proc(void* window, unsigned int message,
                                 unsigned int wparam, long lparam) {
    if (message == 0x104 && wparam == 0x79 &&
        this->input_window != 0 && this->panel_state == this->main_view) {
        this->command_menu();
        return 1;
    }

    if (message == 0x101 && this->input_window != 0 &&
        this->main_view->get_focus() != 0) {
        if (wparam == 0x72 || wparam == 0x13) {
            short (__stdcall *get_key_state)(int) = GetKeyState;
            int alt = get_key_state(0x12) < 0;
            int ctrl = get_key_state(0x11) < 0;
            int shift = get_key_state(0x10) < 0;
            if (alt == 0 && ctrl == 0 && shift == 0) {
                this->command_pause();
            }
        }
    } else if (message == 0x10) {
        if (confirmed_close == 0) {
            confirmed_close = 1;
            int mode = rge_base_game->prog_mode;
            if (mode == 5 || mode == 4 || mode == 6 || mode == 7) {
                if (IsIconic(this->draw_surface->hwnd) == 0) {
                    this->popupYesNoDialog(0xC1D, close_confirmation_text,
                                           0x1C2, 100);
                    return 1;
                }
            }
        }
    } else if (message == 0x208) {
        rge_base_game->goto_notification_loc();
    }

    return TPanel::wnd_proc(window, message, wparam, lparam);
}
