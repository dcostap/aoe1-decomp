// attempt 2: natural focus handling: load cursor, switch draw palette, redraw, and toggle IME

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TPanel {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void redraw(long mode);
    void set_focus(int focus);
};

class TMousePointer {
public:
    int LoadCursors(char* cursor_file, long cursor_id, int flags);
};

class TDrawSystem {
public:
    char gap_00[8];
    void* Pal;
    void Paint(void* rect);
    void SetPalette(void* palette);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void Clear(void* rect, int flags);
};

class RGE_Base_Game {
public:
    char gap_000[0x1C];
    void* prog_palette;
    char gap_020[0x1C0 - 0x20];
    TMousePointer* mouse_pointer;
};

extern RGE_Base_Game* rge_base_game;

class TPanelSystem {
public:
    char gap_00[0x14];
    void EnableIME();
    void DisableIME();
};

extern TPanelSystem panel_system;

class TEasy_Panel : public TPanel {
public:
    char gap_004[0x20 - 4];
    TDrawArea* draw_area;
    char gap_024[0x78 - 0x24];
    int focused;
    char gap_07C[0x20C - 0x7C];
    void* palette;
    char cursor_file[260];
    long cursor_id;
    char gap_318[0x458 - 0x318];
    int enable_ime;

    virtual void set_focus(int focus);
};
#endif

void TEasy_Panel::set_focus(int focus) {
    TPanel::set_focus(focus);

    if (this->focused != 0) {
        if ((this->cursor_file[0] != 0 || this->cursor_id >= 0) && rge_base_game->mouse_pointer != 0) {
            rge_base_game->mouse_pointer->LoadCursors(this->cursor_file, this->cursor_id, 0);
        }

        if (this->draw_area != 0 && this->draw_area->DrawSystem != 0) {
            void* pal = this->palette;
            if (pal == 0) {
                pal = rge_base_game->prog_palette;
            }
            if (pal != 0 && this->draw_area->DrawSystem->Pal != pal) {
                this->draw_area->Clear(0, 0);
                this->draw_area->DrawSystem->Paint(0);
                this->draw_area->DrawSystem->SetPalette(pal);
                this->redraw(2);
            }
        }
    }

    if (this->enable_ime != 0) {
        if (this->focused != 0) {
            panel_system.EnableIME();
        } else {
            panel_system.DisableIME();
        }
    }
}
