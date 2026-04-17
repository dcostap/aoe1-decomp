class RGE_Player;

class RGE_View {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void redraw(int mode);

    char gap_04[0xFC];
    RGE_Player* player;
    char gap_104[0x34];
    int last_view_x;
    int last_view_y;

    void set_player(RGE_Player* player);
};

void RGE_View::set_player(RGE_Player* player) {
    this->player = player;
    last_view_x = (int)0xC61C3C00;
    last_view_y = (int)0xC61C3C00;
    redraw(2);
}
