#ifndef SCR_SED_TU_CONTEXT
class TListPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, unsigned char redraw);
};

class RGE_Base_Game {
public:
    char gap_00[0x400];
    short elevation_height;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed {
public:
    char gap_00[0x5A8];
    TListPanel* paint_elevation_list;

    void set_elevation(short value);
};
#endif

void TRIBE_Screen_Sed::set_elevation(short value) {
    RGE_Base_Game* base_game;

    base_game = rge_base_game;
    base_game->elevation_height = value;
    this->paint_elevation_list->scroll_cur_line(1, value, 1);
}
