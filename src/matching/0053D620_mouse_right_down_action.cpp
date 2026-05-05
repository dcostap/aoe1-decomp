// VA: 0053D620 RGE_Diamond_Map_View::mouse_right_down_action
// mirror 0053D400 with right-button branch polarity.

class RGE_Prog_Info {
public:
    char gap_00[0x8DC];
    short interface_style;
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;
    char gap_10[0x1B0 - 0x10];
    int prog_mode;
    int get_paused();
};
extern RGE_Base_Game* rge_base_game;

class RGE_Diamond_Map_View {
public:
    void start_scroll_view(long x, long y);
    int capture_mouse();
    long mouse_right_down_action(long x, long y, int key, int flags);
};

long RGE_Diamond_Map_View::mouse_right_down_action(long x, long y, int key, int flags) {
    if (rge_base_game->get_paused() == 0) {
        int mode = rge_base_game->prog_mode;
        if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
            if (rge_base_game->prog_info->interface_style == 2) {
                if (mode == 4 || mode == 6 || mode == 7) {
                    this->capture_mouse();
                    return 1;
                }
            } else {
                this->start_scroll_view(x, y);
            }
            return 1;
        }
    }
    return 0;
}
