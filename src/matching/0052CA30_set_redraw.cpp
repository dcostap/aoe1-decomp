#ifndef TVW_DMAP_SHARED_CONTEXT
class TPanel {
public:
    enum RedrawMode {
        redraw_none = 0,
        redraw_local = 1,
        redraw_all = 2
    };
};

class RGE_Diamond_Map {
public:
    virtual void set_redraw(TPanel::RedrawMode mode);
};

class TRIBE_Screen_Game {
public:
    void set_map_buttons_redraw(TPanel::RedrawMode mode);
};

class TRIBE_Diamond_Map_View {
public:
    char gap_00[0x3C];
    TRIBE_Screen_Game* screen_game;
    char gap_40[0x28];
    int field_6C;
    int field_70;

    virtual void set_redraw(TPanel::RedrawMode mode);
};
#endif

void TRIBE_Diamond_Map_View::set_redraw(TPanel::RedrawMode mode) {
    RGE_Diamond_Map::set_redraw(mode);
    if (mode != 0 && this->field_70 != 0 && this->field_6C != 0) {
        this->screen_game->set_map_buttons_redraw(mode);
    }
}
