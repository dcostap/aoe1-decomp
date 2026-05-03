// 0053A9C0 RGE_View::end_scroll_view (view.cpp:6161-6220)
// Using proper virtual method declarations for correct thiscall vtable dispatch.
// vtable: set_redraw at slot 8 (0x20), end_scroll_view at slot 60 (0xF0), do_paint at slot 61 (0xF4)

#include <windows.h>

extern "C" __declspec(dllimport) int __stdcall ClientToScreen(void* hWnd, tagPOINT* point);
extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int x, int y);

class RGE_Base_Game {
public:
    void mouse_on();
};

extern RGE_Base_Game* rge_base_game;

// TPanel virtual methods (first 9, set_redraw at vtable slot 8 = offset 0x20)
class TPanel_Base {
public:
    virtual ~TPanel_Base() {}
    virtual void v04() {}
    virtual void v08() {}
    virtual void v0C() {}
    virtual void v10() {}
    virtual void v14() {}
    virtual void v18() {}
    virtual void v1C() {}
    virtual void set_redraw(int) {}
};

// RGE_View local vtable layout:
// TPanel_Base: 9 virtuals (slots 0-8)
// RGE_View_Local: 51 dummies (slots 9-59), end_scroll_view (slot 60), do_paint (slot 61)
// offset: set_redraw=0x20, end_scroll_view=0xF0, do_paint=0xF4
class RGE_View_Local : public TPanel_Base {
public:
    // TPanel fields (vtable at +0x00 via base, data at +0x04)
    char pre_render_area[0x1C];         // +0x04..+0x1F
    void* render_area;                  // +0x20
    char post_render_area[0xA0];        // +0x24..+0xC3
    long mouse_down_x;                  // +0xC4
    long mouse_down_y;                  // +0xC8
    char pre_scroll[0x9C];              // +0xCC..+0x167
    unsigned char scroll_action;        // +0x168
    unsigned char pad_169[3];           // +0x169..+0x16B
    long mouse_last_x;                  // +0x16C
    long mouse_last_y;                  // +0x170

    // RGE_View virtual methods: 51 dummies for slots 9-59
    virtual void d09() {}
    virtual void d10() {}
    virtual void d11() {}
    virtual void d12() {}
    virtual void d13() {}
    virtual void d14() {}
    virtual void d15() {}
    virtual void d16() {}
    virtual void d17() {}
    virtual void d18() {}
    virtual void d19() {}
    virtual void d20() {}
    virtual void d21() {}
    virtual void d22() {}
    virtual void d23() {}
    virtual void d24() {}
    virtual void d25() {}
    virtual void d26() {}
    virtual void d27() {}
    virtual void d28() {}
    virtual void d29() {}
    virtual void d30() {}
    virtual void d31() {}
    virtual void d32() {}
    virtual void d33() {}
    virtual void d34() {}
    virtual void d35() {}
    virtual void d36() {}
    virtual void d37() {}
    virtual void d38() {}
    virtual void d39() {}
    virtual void d40() {}
    virtual void d41() {}
    virtual void d42() {}
    virtual void d43() {}
    virtual void d44() {}
    virtual void d45() {}
    virtual void d46() {}
    virtual void d47() {}
    virtual void d48() {}
    virtual void d49() {}
    virtual void d50() {}
    virtual void d51() {}
    virtual void d52() {}
    virtual void d53() {}
    virtual void d54() {}
    virtual void d55() {}
    virtual void d56() {}
    virtual void d57() {}
    virtual void d58() {}
    virtual void d59() {}

    // Slot 60 = end_scroll_view, Slot 61 = do_paint
    virtual void end_scroll_view();
    virtual void do_paint(long a, long b, long c, long d, int e) {}

    void pick_multi(unsigned char p1, long p2, long p3, long p4, long p5);
    void release_mouse();
};

void RGE_View_Local::end_scroll_view() {
    long min_x, max_x, min_y, max_y;

    switch (this->scroll_action) {
    case 2:
        if (this->mouse_down_x > this->mouse_last_x) {
            min_x = this->mouse_last_x;
            max_x = this->mouse_down_x;
        } else {
            min_x = this->mouse_down_x;
            max_x = this->mouse_last_x;
        }
        if (this->mouse_down_y > this->mouse_last_y) {
            min_y = this->mouse_last_y;
            max_y = this->mouse_down_y;
        } else {
            min_y = this->mouse_down_y;
            max_y = this->mouse_last_y;
        }
        this->pick_multi(4, min_x, min_y, max_x, max_y);
        this->set_redraw(1);
        break;

    case 1:
    case 6:
    case 7:
    case 8: {
        tagPOINT pt;
        pt.x = this->mouse_down_x;
        pt.y = this->mouse_down_y;
        // render_area->Wnd at offset +4 is the HWND
        ClientToScreen(((void**)this->render_area)[1], &pt);
        SetCursorPos(pt.x, pt.y);
        break;
    }

    case 9:
        this->do_paint(this->mouse_down_x, this->mouse_down_y, this->mouse_down_x, this->mouse_down_y, 0);
        this->set_redraw(1);
        break;

    case 3:
    case 4:
    case 5:
        break;
    }

    if (this->scroll_action == 1 || this->scroll_action == 2
        || this->scroll_action == 6 || this->scroll_action == 7
        || this->scroll_action == 8)
    {
        rge_base_game->mouse_on();
    }

    this->release_mouse();
    this->scroll_action = 0;
}
