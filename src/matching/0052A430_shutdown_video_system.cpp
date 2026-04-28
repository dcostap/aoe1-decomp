// 0052A430 TRIBE_Game::shutdown_video_system (tribegam.cpp:5575-5605)
// Attempt 3: declare virtual methods at correct vtable slots

__declspec(dllimport) int __stdcall InvalidateRect(void* hWnd, void* lpRect, int bErase);
__declspec(dllimport) void* __stdcall LoadCursorA(void* hInstance, int lpCursorName);

extern "C" int restore_mouse_after_paint;  // 62C55Ch

struct TDrawSystem {
    void SetDisplaySize(long wid, long hgt, int bits);
    void ClearPrimarySurface();
    void SetPalette(void* palette);
    unsigned char CheckSurfaces();
    void ClearRestored();
};

class TRIBE_Game {
public:
    // Virtual method declarations at correct vtable slots:
    // vt[0], vt[1], vt[2] — skipped
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    // vt[3] = set_prog_mode
    virtual void set_prog_mode(int mode);
    // vt[4] through vt[41] — filler slots
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    // vt[42] = restart_sound_system
    virtual int restart_sound_system();

    // Data members
    char gap_04[0x0C];          // +0x04 to +0x0F
    void* window_handle;        // +0x10
    char gap_14[0x34];          // +0x14 to +0x47
    TDrawSystem* draw_system;   // +0x48
    char gap_4C[0xBB4];         // +0x4C to +0xBFF
    int video_setup;             // +0xC00
    int video_double_size;       // +0xC04
    int video_changed_res;       // +0xC08
    int video_hi_color;          // +0xC0C
    long video_save_res_wid;     // +0xC10
    long video_save_res_hgt;     // +0xC14
    void* video_save_palette;    // +0xC18

    // Non-virtual helper methods (inherited from RGE_Base_Game)
    int check_paint();
    void set_render_all();
    void set_mouse_cursor(void* cursor);
    void mouse_on();

    void shutdown_video_system();
};

void TRIBE_Game::shutdown_video_system()
{
    if (video_setup == 0) return;

    if (video_changed_res) {
        draw_system->SetDisplaySize(video_save_res_wid, video_save_res_hgt, 8);
        draw_system->ClearPrimarySurface();
        draw_system->SetPalette(video_save_palette);
        video_changed_res = 0;
        draw_system->CheckSurfaces();
        draw_system->ClearRestored();
        check_paint();
        restore_mouse_after_paint = 1;
    }

    draw_system->ClearPrimarySurface();
    draw_system->SetPalette(video_save_palette);
    set_render_all();

    InvalidateRect(this->window_handle, 0, 1);

    set_prog_mode(2);
    restart_sound_system();

    void* cursor = LoadCursorA(0, 0x7F00);
    set_mouse_cursor(cursor);
    mouse_on();

    video_setup = 0;
}
