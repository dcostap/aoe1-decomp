extern "C" __declspec(dllimport) int __stdcall GetCursorPos(void* point);
extern "C" __declspec(dllimport) int __stdcall ScreenToClient(void* hwnd, void* point);

struct tagPOINT {
    long x;
    long y;
};

class TDrawSystem {
public:
    char gap_00[0x479];
    unsigned char ScreenMode;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
};

class TPanel {
public:
    char gap_00[0x20];
    TDrawArea* render_area;

    void get_mouse_pos(tagPOINT& pt);
};

void TPanel::get_mouse_pos(tagPOINT& pt) {
    GetCursorPos(&pt);
    if (render_area->DrawSystem->ScreenMode != 2) {
        ScreenToClient(render_area->Wnd, &pt);
        if (pt.x > 60000) {
            pt.x += -0x10000;
        }
        if (pt.y > 60000) {
            pt.y += -0x10000;
        }
    }
}
