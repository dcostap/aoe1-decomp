#ifndef DIAM_MAP_CONTEXT_H
class RGE_Player;
class RGE_Diamond_Map {
public:
    virtual void set_rect();
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning();
    virtual void set_fixed_position(long, long, long, long);
    virtual void draw_setup(int);
    virtual void set_overlapped_redraw(void*, void*, int);
    virtual void set_redraw(int);
    char gap_4[0xF2];
    int field_F8;
    void set_player(RGE_Player* value);
};
#endif

void RGE_Diamond_Map::set_player(RGE_Player* value) {
#ifdef DIAM_MAP_CONTEXT_H
    this->player = value;
#else
    this->field_F8 = (int)value;
#endif
#ifdef DIAM_MAP_CONTEXT_H
    this->set_redraw(TPanel::redraw_all);
#else
    this->set_redraw(2);
#endif
}
