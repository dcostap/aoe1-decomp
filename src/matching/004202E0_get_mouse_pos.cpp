extern "C" __declspec(dllimport) int __stdcall GetCursorPos(void* point);
extern "C" __declspec(dllimport) int __stdcall ScreenToClient(void* hwnd, void* point);

struct tagPOINT {
    long x;
    long y;
};

class RGE_Prog_Info {
public:
    char gap_00[0x894];
    int full_screen;
};

class RGE_Base_Game {
public:
    void* vtable_ptr;
    char gap_04[0x8];
    RGE_Prog_Info* prog_info;
    void* prog_window;

    void get_mouse_pos(tagPOINT& pt);
};

void RGE_Base_Game::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (this->prog_info->full_screen == 0) {
        ScreenToClient(this->prog_window, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}
