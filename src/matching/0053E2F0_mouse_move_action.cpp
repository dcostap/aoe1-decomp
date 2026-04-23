class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    int game_mode;
};

class RGE_Main_View {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set_redraw(int mode);
    virtual long mouse_move_action(long a, long b, int c, int d);
};

long RGE_Main_View::mouse_move_action(long a, long b, int c, int d) {
    RGE_Base_Game* game = *(RGE_Base_Game**)0x62C574;
    int mode = game->prog_mode;
    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        mode = game->game_mode;
        if (mode == 1) {
            goto call_redraw;
        }
        if (mode <= 6) {
            goto ret_one;
        }
        if (mode > 8) {
            goto ret_one;
        }
    call_redraw:
        this->set_redraw(1);
    ret_one:
        return 1;
    }
    return 0;
}
