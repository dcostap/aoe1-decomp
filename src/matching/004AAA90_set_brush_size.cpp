// VA: 004AAA90 TRIBE_Screen_Sed::set_brush_size | scr_sed.cpp:1725-1749

#ifndef SCR_SED_TU_CONTEXT
class TButtonPanel {
public:
    void set_radio_button(void);
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
    char gap_00[0x402];
    short brush_size;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x4B0 - 0x478];
    int brush_size;
    char gap_4B4[0x558 - 0x4B4];
    TButtonPanel* brush_size_button[5];

    void set_brush_size(int size);
};
#endif

void TRIBE_Screen_Sed::set_brush_size(int size) {
    if (!size) return;
    brush_size = size;
    brush_size_button[size - 1]->set_radio_button();
    int v;
    switch (brush_size) {
    case 1: v = 1; break;
    case 2: v = 3; break;
    case 3: v = 5; break;
    case 4: v = 7; break;
    case 5: v = 9; break;
    default: v = 2; break;
    }
    rge_base_game->brush_size = v;
}
