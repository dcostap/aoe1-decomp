// 0051CCA0 TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea*, TPanel*)
// Size: 232 bytes
// PDB source: tpnl_pop.cpp:32-57

// Attempt log:

#ifndef TPNL_POP_SHARED_CONTEXT
class TDrawArea;

class RGE_Font {
public:
    void* font_data;
};

class RGE_Base_Game {
public:
    RGE_Font* get_font(int id);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    TPanel();
    virtual ~TPanel();
    long setup(TDrawArea* area, TPanel* parent, int a, int b, int c, int d, char e);
    char gap_04[0x7C];
    int handle_mouse_input;          // +0x80
    char gap_84[0x54];
    int error_code;                  // +0xD8
    char gap_DC[0x18];
};

class TRIBE_Panel_Pop : public TPanel {
public:
    void* font;                     // +0xF4
    unsigned long color1;           // +0xF8
    unsigned long color2;           // +0xFC
    unsigned long color3;           // +0x100
    int player_id;                  // +0x104
    void* world;                    // +0x108
    void* player;                   // +0x10C
    int pop;                        // +0x110
    int max_pop;                    // +0x114
    unsigned char mode;             // +0x118
    unsigned char pad_119[3];
    float timer;                    // +0x11C
    void* image_clip_region;        // +0x120
    TDrawArea* ImageBuffer;         // +0x124
    unsigned char gap_128[0x30];    // +0x128 to +0x157: three tagRECTs (0x10 each)
    int ImageTextActive;            // +0x158
    int LastIBWidth;                // +0x15C
    int LastIBHeight;               // +0x160

    TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent);
    virtual ~TRIBE_Panel_Pop();
};
#endif

TRIBE_Panel_Pop::TRIBE_Panel_Pop(TDrawArea* area, TPanel* parent) {
    RGE_Font* f;

    this->handle_mouse_input = 0;
    f = rge_base_game->get_font(0xB);
    this->font = f->font_data;
    this->color1 = 0xFFFFFF;
    this->color2 = 0;
    this->color3 = 0xFFFF;
    this->player_id = 0;
    this->world = 0;
    this->player = 0;
    this->pop = 0;
    this->max_pop = 0;
    this->mode = 0;
    this->timer = 0.0f;
    this->ImageBuffer = 0;
    this->LastIBWidth = -1;
    this->LastIBHeight = -1;
    this->ImageTextActive = 0;
    this->image_clip_region = 0;
    if (TPanel::setup(area, parent, 0, 0, 0, 0, 0) == 0) {
        this->error_code = 1;
    }
}
