// 00520D70 TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line
// Source: tpnl_txl.cpp lines 23-34
//
// Attempt log:
// Probe 1: reuse TPanel pattern from RGE_Panel_Time constructor + /GX for EH prolog

#include "..\..\include\game_globals.h"

class TDrawArea;
class TPanel;

class TPanel {
public:
    char gap_00[0x7C];
    int field_80;
    char gap_84[0x54];
    int field_D8;
    char gap_DC[0x18];

    virtual ~TPanel();
    virtual void vf04();
    virtual void vf08();
    virtual long vf0C();
    virtual long handle_idle();

    TPanel();
    long setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, unsigned char modal);
};

class TRIBE_Panel_Text_Line : public TPanel {
public:
    void* font;                    // +0xF4 (4)
    unsigned char text_type;       // +0xF8 (1)
    char text[200];                // +0xF9 (200 = 0xC8)
    char _pad[3];                  // +0x1C1 (3)
    long id;                       // +0x1C4 (4)

    virtual ~TRIBE_Panel_Text_Line();
    virtual void* scalar_deleting_destructor(unsigned int);
    virtual long draw();
    virtual long set_info(unsigned char type, char* str, long new_id);

    TRIBE_Panel_Text_Line(TDrawArea* draw_area, TPanel* parent, void* font_arg);
};

TRIBE_Panel_Text_Line::TRIBE_Panel_Text_Line(TDrawArea* draw_area, TPanel* parent, void* font_arg) : TPanel() {
    this->font = font_arg;
    this->text_type = 0;
    this->text[0] = 0;
    this->id = 0;
    if (!this->setup(draw_area, parent, 0, 0, 0, 0, 0)) {
        this->field_D8 = 1;
    }
}
