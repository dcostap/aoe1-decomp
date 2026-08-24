// attempt 2: natural popup-help command: exit help mode, restore cursor, resolve help text, show help dialog

#ifndef AOE1_PANEL_EZ_CONTEXT_H
extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void* instance, unsigned int cursor);

class TMousePointer {
public:
    void set_game_enable(long mode);
};

class RGE_Base_Game {
public:
    char gap_000[0x1C0];
    TMousePointer* mouse_pointer;
    void set_mouse_cursor(void* cursor);
    void set_mouse_facet(long facet);
};

extern RGE_Base_Game* rge_base_game;

class TEasy_Panel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual unsigned char get_popup_help(char** text, long* page, long x, long y);

    char gap_004[0x1C - 4];
    char* help_title;
    char gap_020[0x45C - 0x20];
    unsigned char help_mode;
    char gap_45D[0x474 - 0x45D];
    long saved_mouse_mode;

    void command_help(char* title, char* text, long page, long x, long y);
    long command_do_popup_help(unsigned char clicked, long x, long y);
};
#endif

long TEasy_Panel::command_do_popup_help(unsigned char clicked, long x, long y) {
    long help_page;
    char* temp;
    char help_string2[1000];

    temp = help_string2;
    if (this->help_mode == 1) {
        this->help_mode = 0;
        rge_base_game->set_mouse_cursor(LoadCursorA(0, (const char*)0x7F00));
        rge_base_game->set_mouse_facet(0);
        rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
        if (clicked == 1) {
            if (this->get_popup_help(&temp, &help_page, x, y)) {
                this->command_help(this->help_title, help_string2, help_page, x, y);
            }
        }
        return 1;
    }
    return 0;
}
