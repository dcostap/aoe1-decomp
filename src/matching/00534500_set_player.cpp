#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_Player;

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void set_rect(long, long, long, long);
    virtual void set_redraw(int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void release_mouse();
    virtual void set_focus(int);
    virtual void redraw(int mode);

    char gap_04[0xFC];
    RGE_Player* player;
    char gap_104[0x34];
    int last_view_x;
    int last_view_y;

    void set_player(RGE_Player* player);
};
#endif

void RGE_View::set_player(RGE_Player* player) {
    this->player = player;
    last_view_x = (int)0xC61C3C00;
    last_view_y = (int)0xC61C3C00;
    redraw(2);
}
