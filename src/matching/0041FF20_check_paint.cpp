// VA: 0041FF20 RGE_Base_Game::check_paint (221 B)
// PDB source: basegame.cpp lines 3101-3149
//
// Attempt log:
// - Baseline reconstruction: real RGE_Base_Game/TDrawSystem member surface,
//   dllimport Win32 IAT calls, RECT local, switch dispatch on CheckSurfaces().

extern "C" __declspec(dllimport) int __stdcall ValidateRect(void* hwnd, const void* rect);
extern "C" __declspec(dllimport) int __stdcall IsIconic(void* window);
extern "C" __declspec(dllimport) int __stdcall GetUpdateRect(void* hwnd, void* rect, int erase);
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* window);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct TDrawSystem {
    void Paint(tagRECT* rect);
    unsigned char CheckSurfaces();
    void ClearRestored();
};

class RGE_Base_Game {
public:
    void* vtable_ptr;           // +0x00
    char gap_04[8];              // +0x04..+0x0B
    void* prog_info;             // +0x0C
    void* prog_window;           // +0x10
    int prog_ready;              // +0x14
    int prog_active;             // +0x18
    char gap_1C[0x48 - 0x1C];    // +0x1C..+0x47
    TDrawSystem* draw_system;    // +0x48

    void clear_window();
    void set_render_all();
    int check_paint();
};

int RGE_Base_Game::check_paint()
{
    tagRECT update_rect;
    unsigned char surface_status;

    if (this->prog_ready == 0) {
        this->clear_window();
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (IsIconic(this->prog_window) != 0) {
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    if (this->prog_active == 0) {
        if (GetUpdateRect(this->prog_window, &update_rect, 0) != 0) {
            this->draw_system->Paint(&update_rect);
        }
        ValidateRect(this->prog_window, 0);
        return 0;
    }

    surface_status = this->draw_system->CheckSurfaces();
    switch (surface_status) {
    case 1:
        return 0;
    case 2:
        this->draw_system->ClearRestored();
        this->set_render_all();
        break;
    case 3:
        ValidateRect(this->prog_window, 0);
        DestroyWindow(this->prog_window);
        return 0;
    default:
        break;
    }
    return 1;
}
