// target: VA 0049BEA0 TRIBE_Screen_Game::command_cancel()
// attempt: flattened local layout to binary-proven offsets (+0x45C popup_help, +0x4B8 main_view)
// attempt: pure virtual padding for TRIBE_Main_View vt[60] avoids fake cdecl cast push/add cleanup
// attempt: nested game_mode branch keeps command_unselect as shared tail block like original

#define VPAD1(n) virtual void vpad##n() = 0;
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TRIBE_Main_View {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD8(48)
    VPAD4(56)
    virtual void vfF0();
    void set_selection_area(long left, long top, long right, long bottom);
};

class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_game_action(int, int);

    char gap_04[0x1B0];
    int game_mode;

    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x45C];
    unsigned char popup_help_flag;
    char gap_45D[0x5B];
    TRIBE_Main_View* main_view;

    void clear_popup_help();
    void command_unselect();
    void command_cancel();
};

void TRIBE_Screen_Game::command_cancel() {
    if (this->popup_help_flag) {
        this->clear_popup_help();
        return;
    }

    if (rge_base_game->get_paused()) {
        return;
    }

    if (rge_base_game->game_mode != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->vfF0();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }
        rge_base_game->set_game_action(0, 0);
    } else {
        this->command_unselect();
    }
}
