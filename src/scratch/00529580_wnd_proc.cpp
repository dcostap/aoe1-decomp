// 00529580 wnd_proc (140 bytes) — MATCHED
// PDB: tribegam.cpp (TRIBE_Game::wnd_proc)

extern long __stdcall RGE_Base_Game_wnd_proc(void* this_ptr, void* hWnd, unsigned int msg, unsigned int wParam, long lParam);

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Base_Game {
public:
    char gap_1B0[0x1B0];
    int field_1B0;
    char gap_1B4[0x24];
    int field_1D8;

    void disable_input();
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    long __stdcall wnd_proc(void* hWnd, unsigned int msg, unsigned int wParam, long lParam);
    void stop_video(unsigned char param);
};
#endif

long TRIBE_Game::wnd_proc(void* hWnd, unsigned int msg, unsigned int wParam, long lParam)
{
    if (msg <= 0x200) {
        if (msg != 0x200) {
            if (msg == 7) {
                if (this->is_mouse_on == 0) {
                    this->disable_input();
                } else {
                    this->enable_input();
                }
            }
        } else {
            if (this->prog_mode == 1) {
                SetCursor(0);
            }
        }
    } else {
        switch (msg) {
        case 0x201:
        case 0x204:
            if (this->prog_mode == 1) {
                this->stop_video(1);
                return 0;
            }
            break;
        }
    }

    return RGE_Base_Game_wnd_proc(this, hWnd, msg, wParam, lParam);
}
