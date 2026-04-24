class TMousePointer {
public:
    void set_game_enable(int v);
};

class RGE_Base_Game {
public:
    char gap_0[0x1C0];
    TMousePointer* mouse_pointer;

    void set_mouse_cursor(void* cursor);
    void set_mouse_facet(long facet);
};

class TEasy_Panel {
public:
    char gap_0[0x45C];
    unsigned char help_mode;
    char gap_1[0x17];
    int saved_mouse_mode;

    void clear_popup_help(void);
};

extern RGE_Base_Game* rge_base_game;
extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void*, const char*);

void TEasy_Panel::clear_popup_help(void) {
    this->help_mode = 0;
    rge_base_game->set_mouse_cursor(LoadCursorA(0, (const char*)0x7F00));
    rge_base_game->set_mouse_facet(0);
    rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
}
