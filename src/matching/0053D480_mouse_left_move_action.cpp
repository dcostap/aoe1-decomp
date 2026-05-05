// VA: 0053D480 mouse_left_move_action (114B)
// vw_dimap.cpp

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0x150];
    int field_154;

    void end_scroll_view();
    void release_mouse();
    void handle_scroll_view(long x, long y);
    long mouse_left_move_action(long x, long y, int key, int flags);
};

long RGE_Diamond_Map_View::mouse_left_move_action(long x, long y, int key, int flags) {
    int prog_mode = rge_base_game->prog_mode;
    if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7 || prog_mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->field_154) {
                this->end_scroll_view();
            } else {
                this->release_mouse();
            }
            return 0;
        }
        if (this->field_154) {
            this->handle_scroll_view(x, y);
            return 1;
        }
    }
    return 0;
}
