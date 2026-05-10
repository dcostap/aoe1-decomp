// 004AB740 TRIBE_Screen_Sed::handle_idle
// Working pass: model real member calls and layout; debug file as array symbol.

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
};

class TPanel {
public:
    long handle_idle();
};

class TPanelSystem {
public:
    TPanel* modalPanel();
};

class ViewPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20(int redraw);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern const char s_C__msdev_work_age1_x1_scr_sed_cp[];

unsigned long debug_timeGetTime(const char* file, int line);

class TRIBE_Screen_Sed : public TPanel {
public:
    char gap_panel[0x4C8];
    ViewPanel* main_view;
    ViewPanel* map_view;
    char gap_4D0[0x92C - 0x4D0];
    unsigned long update_interval;
    unsigned long last_update_time;
    unsigned long map_redraw_interval;
    unsigned long last_map_redraw_time;

    long handle_idle();
};

long TRIBE_Screen_Sed::handle_idle() {
    if (rge_base_game->prog_mode == 7) {
        unsigned long now = debug_timeGetTime(s_C__msdev_work_age1_x1_scr_sed_cp, 0x8B1);
        if (last_update_time - now >= update_interval) {
            if (panel_system.modalPanel() == 0) {
                main_view->vf20(1);
                if (last_map_redraw_time - now >= map_redraw_interval) {
                    map_view->vf20(1);
                    last_map_redraw_time = now;
                }
            }
        }
    }
    return TPanel::handle_idle();
}
