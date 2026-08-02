// VA: 0048F190 TribeAchievementsScreen::handle_mouse_down (226 B)
// PDB source: scr_ach.cpp (lines 783-801)
// Packet-grounded: virtual thiscall override; base TEasy_Panel::handle_mouse_down call,
// then mode-0-only dispatch through the five achievement_choice TTextPanel buttons,
// calling set_mode(1..4). Offsets proven: current_mode +0x47C, achievement_choice +0x4B4.
//
// Attempt log:
// - (prior scratch content was an unrelated wrong shim; replaced with the packet-grounded
//   natural member/class reconstruction)

// Local vtable-slot pads so TPanel::is_inside lands at vtable slot 0xBC (47).
#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)

class TPanel {
public:
    char gap_00[0xF0];        // vptr + 0xF0 bytes of data; sizeof(TPanel) = 0xF4
    virtual ~TPanel();        // vtable slot 0x00
    VPAD16(1)                 // slots 0x04..0x40
    VPAD16(2)                 // slots 0x44..0x80
    VPAD8(3)                  // slots 0x84..0xA0
    VPAD4(4)                  // slots 0xA4..0xB0
    VPAD2(5)                  // slots 0xB4..0xB8
    virtual int is_inside(long x, long y);   // vtable slot 0xBC
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];       // sizeof(TEasy_Panel) = 0x478
    long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
};

class TScreenPanel : public TEasy_Panel {
public:
    // no data, no new virtual slots before 0xBC
};

class TTextPanel : public TPanel {
public:
    // inherits TPanel::is_inside at vtable slot 0xBC
};

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                  // +0x478
    int current_mode;                   // +0x47C
    int size;                           // +0x480
    TTextPanel* title;                  // +0x484
    TTextPanel* summary_text;           // +0x488
    TTextPanel* instruction;            // +0x48C
    TTextPanel* win_loss_text;          // +0x490
    TTextPanel* time;                   // +0x494
    TTextPanel* title_bar[7];           // +0x498
    TTextPanel* achievement_choice[5];  // +0x4B4

    virtual long handle_mouse_down(unsigned char button, long x, long y, int flags, int area);
    void set_mode(long mode);
};

long TribeAchievementsScreen::handle_mouse_down(unsigned char button, long x, long y, int flags, int area)
{
    long result = TEasy_Panel::handle_mouse_down(button, x, y, flags, area);
    if (current_mode == 0) {
        if (achievement_choice[0]->is_inside(x, y)) {
            set_mode(1);
            return result;
        }
        if (achievement_choice[1]->is_inside(x, y)) {
            set_mode(2);
            return result;
        }
        if (achievement_choice[2]->is_inside(x, y)) {
            set_mode(3);
            return result;
        }
        if (achievement_choice[3]->is_inside(x, y)) {
            if (achievement_choice[4]->is_inside(x, y) == 0) {
                set_mode(4);
            }
        }
    }
    return result;
}
