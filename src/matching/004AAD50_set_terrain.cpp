// VA: 004AAD50 TRIBE_Screen_Sed::set_terrain | scr_sed.cpp:1844-1862

class TListPanel {
public:
    void scroll_cur_line(unsigned char mode, short line, unsigned char redraw);
};

class TPanel {
public:
    char gap_00[0xF4];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
};

class TScreenPanel : public TEasy_Panel {
public:
};

class RGE_Base_Game {
public:
    char gap_00[0x3FE];
    short terrain_id;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x5A0 - 0x478];
    TListPanel* paint_terrain_list;

    void set_terrain(short terrain);
};

void TRIBE_Screen_Sed::set_terrain(short terrain) {
    short v;
    switch (terrain) {
    case 0: v = 0; break;
    case 1: v = 6; break;
    case 2: v = 10; break;
    case 3: v = 1; break;
    case 4: v = 0xD; break;
    case 5: v = 0x14; break;
    case 6: v = 4; break;
    case 7: v = 0x13; break;
    case 8: v = 0x16; break;
    default: v = 0; break;
    }
    RGE_Base_Game* game;
    game = rge_base_game;
    game->terrain_id = v;
    paint_terrain_list->scroll_cur_line(1, terrain, 1);
}
