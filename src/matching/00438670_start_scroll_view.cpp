struct RGE_Tile;

class TPanel {
public:
    virtual ~TPanel() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void set_redraw(int mode) {}
    char gap_00[0xF0];

    int capture_mouse();
};

class RGE_Player {
public:
    char gap_00[4];
    void set_view_loc(float x, float y);
};

class RGE_View {
public:
    virtual ~RGE_View() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void set_redraw(int mode) {}
};

class RGE_Diamond_Map : public TPanel {
public:
    char gap_F4[0x04];          // +0xF4: world (unused)
    RGE_Player* player;         // +0xF8
    char gap_FC[0x0C];          // +0xFC to +0x107
    long mouse_last_x;          // +0x108
    long mouse_last_y;          // +0x10C
    char gap_110[0x40];         // +0x110 to +0x14F
    RGE_View* main_view;        // +0x150
    int scrolling;              // +0x154

    int pick_tile(long x, long y, short* xs, short* ys, RGE_Tile** tile);
    void start_scroll_view(long x, long y);
};

void RGE_Diamond_Map::start_scroll_view(long x, long y) {
    short xs, ys;
    RGE_Tile* tile;

    if (pick_tile(x, y, &xs, &ys, &tile)) {
        this->capture_mouse();

        this->scrolling = 1;
        this->player->set_view_loc((float)xs - 0.5f, (float)ys - 0.5f);

        this->set_redraw(1);

        if (this->main_view) {
            this->main_view->set_redraw(1);
        }

        this->mouse_last_x = x;
        this->mouse_last_y = y;
    }
}
