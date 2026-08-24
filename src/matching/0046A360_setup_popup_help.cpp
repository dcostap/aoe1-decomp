// first pass: natural UI setup shape with the cursor/mouse-mode calls in packet order
// if this stays sticky, the likely issue is codegen shape around the imported cursor call or the mouse-pointer load chain
#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TMousePointer {
public:
    char pad_00[0x138];
    int game_enable;

    int get_game_enable();
    void set_game_enable(int v);
};

class RGE_Base_Game {
public:
    char pad_00[0x1C0];
    TMousePointer* mouse_pointer;

    void set_mouse_cursor(void* cursor);
    void set_mouse_facet(long facet);
};

extern RGE_Base_Game* rge_base_game;
extern "C" void* (__stdcall *__imp__LoadCursorA)(void* hInstance, const char* lpCursorName);
#define LoadCursorA __imp__LoadCursorA

class TEasy_Panel {
public:
    char pad_00[0x45C];
    unsigned char help_mode;
    char pad_45D[0x17];
    int saved_mouse_mode;

    void setup_popup_help(void);
};
#endif

void TEasy_Panel::setup_popup_help(void) {
    this->help_mode = 1;
    rge_base_game->set_mouse_cursor(LoadCursorA(0, (const char*)0x7F8B));
    rge_base_game->set_mouse_facet(6);
    this->saved_mouse_mode = rge_base_game->mouse_pointer->get_game_enable();
    rge_base_game->mouse_pointer->set_game_enable(0);
}
