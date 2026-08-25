#ifndef DIAM_MAP_CONTEXT_H
struct RGE_Tile;
#endif

#ifndef DIAM_MAP_CONTEXT_H
class TPanel {
public:
    virtual ~TPanel() {}
    virtual void setup() {}
    virtual void set_rect() {}
    virtual void set_color() {}
    virtual void set_active() {}
    virtual void set_positioning() {}
    virtual void set_fixed_position() {}
    virtual void set_overlapped_redraw() {}
    virtual void set_redraw(int mode) {}
    char gap_00[0xF0];

    int capture_mouse();
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_Player {
public:
    char gap_00[4];
    void set_view_loc(float x, float y);
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
class RGE_View {
public:
    virtual ~RGE_View() {}
    virtual void setup() {}
    virtual void set_rect() {}
    virtual void set_color() {}
    virtual void set_active() {}
    virtual void set_positioning() {}
    virtual void set_fixed_position() {}
    virtual void set_overlapped_redraw() {}
    virtual void set_redraw(int mode) {}
};
#endif

#ifndef DIAM_MAP_CONTEXT_H
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
#endif

void RGE_Diamond_Map::start_scroll_view(long x, long y) {
    short xs, ys;
    RGE_Tile* tile;

    if (pick_tile(x, y, &xs, &ys, &tile)) {
        this->capture_mouse();

        this->scrolling = 1;
        this->player->set_view_loc((float)xs - 0.5f, (float)ys - 0.5f);

#ifdef DIAM_MAP_CONTEXT_H
        this->set_redraw(TPanel::redraw_local);
#else
        this->set_redraw(1);
#endif

        if (this->main_view) {
#ifdef DIAM_MAP_CONTEXT_H
            ((RGE_View*)this->main_view)->set_redraw(1);
#else
            this->main_view->set_redraw(1);
#endif
        }

        this->mouse_last_x = x;
        this->mouse_last_y = y;
    }
}
