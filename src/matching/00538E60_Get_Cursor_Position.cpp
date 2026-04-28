// 00538E60 RGE_View::Get_Cursor_Position
// Source: view.cpp lines 4716-4741. 151 bytes. __thiscall, ret 0Ch.

extern "C" int (__stdcall * const GetCursorPos)(void*);
extern "C" int (__stdcall * const ScreenToClient)(void*, void*);

class RGE_View {
public:
    char gap_00[0x20];
    void* display_info;          // +0x20 — points to {flag_struct*, hwnd}
    char gap_24[0x8C - 0x24];
    int scroll_min_x;            // +0x8C
    int scroll_min_y;            // +0x90
    int scroll_max_x;            // +0x94
    int scroll_max_y;            // +0x98

    int Get_Cursor_Position(void* point, int offset_x, int offset_y);
};

struct tagPOINT {
    int x;
    int y;
};

int RGE_View::Get_Cursor_Position(void* point, int offset_x, int offset_y) {
    GetCursorPos(point);
    void* d1 = *(void**)this->display_info;   // +0 = flag_struct ptr
    if (*(unsigned char*)((char*)d1 + 0x479) == 1) {
        void* hwnd = *((void**)this->display_info + 1);  // +4 = hwnd
        ScreenToClient(hwnd, point);
        if (((tagPOINT*)point)->x > 0x7FFF)
            ((tagPOINT*)point)->x -= 0x10000;
        if (((tagPOINT*)point)->y > 0x7FFF)
            ((tagPOINT*)point)->y -= 0x10000;
    }
    ((tagPOINT*)point)->x += offset_x;
    int new_x = ((tagPOINT*)point)->x;
    ((tagPOINT*)point)->y += offset_y;
    int new_y = ((tagPOINT*)point)->y;

    if (new_x < this->scroll_min_x || new_x > this->scroll_max_x ||
        new_y < this->scroll_min_y || new_y > this->scroll_max_y)
        return 0;
    return 1;
}
