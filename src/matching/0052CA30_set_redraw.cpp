class RGE_Diamond_Map {
public:
    void set_redraw(int mode);
};

class TRIBE_Screen_Game {
public:
    void set_map_buttons_redraw(int mode);
};

class TRIBE_Diamond_Map_View {
public:
    char gap_00[0x3C];
    TRIBE_Screen_Game* screen_game;
    char gap_40[0x28];
    int field_6C;
    int field_70;

    virtual void set_redraw(int mode);
};

void TRIBE_Diamond_Map_View::set_redraw(int mode) {
    ((RGE_Diamond_Map*)this)->set_redraw(mode);
    if (mode != 0 && this->field_70 != 0 && this->field_6C != 0) {
        this->screen_game->set_map_buttons_redraw(mode);
    }
}
