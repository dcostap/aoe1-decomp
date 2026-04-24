class RGE_Base_Game {
public:
    void* vtable_ptr;
    char gap_04[0x0C];
    void* prog_window;

    void clear_window();
};

extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hwnd);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hwnd, void* rect);
extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int index);
extern "C" __declspec(dllimport) int __stdcall FillRect(void* hdc, void* rect, void* brush);
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hwnd, void* hdc);

void RGE_Base_Game::clear_window() {
    char rect[16];
    void* dc;
    void* brush;

    if (this->prog_window != 0) {
        dc = GetDC(this->prog_window);
        GetClientRect(this->prog_window, rect);
        brush = GetStockObject(4);
        FillRect(dc, rect, brush);
        ReleaseDC(this->prog_window, dc);
    }
}
