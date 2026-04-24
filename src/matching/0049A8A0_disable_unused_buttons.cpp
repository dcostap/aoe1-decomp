// compact button-disable loop first
// expected basin: iterate the 12 drop-down buttons, toggle each button's active state, and clear ids/help on unused ones

class TPanel {
public:
    char gap_00[0xE4];
    int field_E4;
    int field_E8;

    void set_help_info(int a, int b);
};

class TButtonPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(int v);

    char gap_00[0x2B4];
    void set_id(short a, long b, long c);
};

class TRIBE_Panel_Button {
public:
    char pad_00[0x3D0];
    int in_use;
};

class TRIBE_Screen_Game {
public:
    char pad_00[0x4C8];
    TRIBE_Panel_Button* button_panel[17];

    void disable_unused_buttons(void);
};

void TRIBE_Screen_Game::disable_unused_buttons(void) {
    TRIBE_Panel_Button** p = this->button_panel;
    int count = 12;

    do {
        if ((*p)->in_use == 0) {
            ((TButtonPanel*)*p)->vf14(0);
            ((TButtonPanel*)*p)->set_id(0, 0, -1);
            ((TPanel*)*p)->set_help_info(-1, -1);
        } else {
            ((TButtonPanel*)*p)->vf14(1);
        }
        p++;
    } while (--count != 0);
}
