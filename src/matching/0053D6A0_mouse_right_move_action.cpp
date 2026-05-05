// VA: 0053D6A0 RGE_Diamond_Map_View::mouse_right_move_action
// first pass: use real member calls and direct global game surface.

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    int get_paused();
};
extern RGE_Base_Game* rge_base_game;

class RGE_Diamond_Map_View {
public:
    char gap0[0x154];
    int scroll_active;

    void end_scroll_view();
    void release_mouse();
    void handle_scroll_view(long x, long y);
    long mouse_right_move_action(long x, long y, int key, int flags);
};

long RGE_Diamond_Map_View::mouse_right_move_action(long x, long y, int key, int flags) {
    int mode = rge_base_game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (rge_base_game->get_paused()) {
            if (this->scroll_active) {
                this->end_scroll_view();
            } else {
                this->release_mouse();
            }
            return 0;
        }
        if (this->scroll_active) {
            this->handle_scroll_view(x, y);
            return 1;
        }
    }
    return 0;
}
