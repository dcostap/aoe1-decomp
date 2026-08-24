// VA: 0052A260 TRIBE_Game::setup_video_system (450 B)
// PDB source: tribegam.cpp:5501-5569
//
// Attempt log:
// - Replaced the allocation-only scaffold with the natural period video setup
//   flow: blank panel, mouse shutdown, draw-system mode selection, debugging
//   logs, and the base-game virtual mode/sound calls.
// - Exact baseline: the donor-backed +0x48 draw system, +0x1c0 mouse pointer,
//   +0xc00 video fields, and virtual stop_sound_system slot reproduce all
//   450 bytes with the default flags.

extern "C" __declspec(dllimport) void* __stdcall SetCursor(void* hcur);
extern "C" __declspec(dllimport) long __stdcall SetClassLongA_tribe(
    void* hwnd, long index, long value);

#ifndef TRIBEGAM_TU_CONTEXT
class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class TMousePointer {
public:
    int Shutdown_Mouse();
};

class TDrawSystem {
public:
    void* instance; // +0x00
    void* window; // +0x04
    void* palette; // +0x08
    char gap_0C[0x20];
    long ScreenWidth; // +0x2C
    long ScreenHeight; // +0x30
    char gap_34[0x444];
    unsigned char DrawType; // +0x478
    unsigned char ScreenMode; // +0x479

    int IsModeAvail(long width, long height, int bits);
    int SetDisplaySize(long width, long height, int bits);
};

class TDebuggingLog;
extern TDebuggingLog* L;
extern void __cdecl Log(TDebuggingLog* log, char* format, ...);

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void set_prog_mode(int mode);
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
    virtual void stop_sound_system();

    char gap_04[0x0C];
    void* prog_window; // +0x10
    char gap_14[0x34];
    TDrawSystem* draw_system; // +0x48
    char gap_4C[0x174];
    TMousePointer* mouse_pointer; // +0x1C0
    char gap_1C4[0x860];

    void mouse_off();
    unsigned char check_prog_argument(char* value);
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x1DC];
    int video_setup; // +0xC00
    int video_double_size; // +0xC04
    int video_changed_res; // +0xC08
    int video_hi_color; // +0xC0C
    long video_save_res_wid; // +0xC10
    long video_save_res_hgt; // +0xC14
    void* video_save_palette; // +0xC18

    int setup_video_system();
};
#endif

int TRIBE_Game::setup_video_system()
{
    if (this->video_setup != 0) {
        return 1;
    }

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->mouse_off();

    this->video_double_size = 1;
    this->video_changed_res = 0;
    this->video_hi_color = 0;
    this->video_save_palette = this->draw_system->palette;

    if (this->draw_system->ScreenMode == 2) {
        SetCursor(0);
        SetClassLongA_tribe(this->prog_window, -12, 0);
        this->mouse_pointer->Shutdown_Mouse();

        this->video_save_res_wid = this->draw_system->ScreenWidth;
        this->video_save_res_hgt = this->draw_system->ScreenHeight;
        if (this->check_prog_argument("8BITVIDEO") == 0) {
            if (this->draw_system->IsModeAvail(0x280, 0x1E0, 0x10) != 0) {
                Log(L, "640x480 16bit");
                this->video_changed_res =
                    this->draw_system->SetDisplaySize(0x280, 0x1E0, 0x10);
                if (this->video_changed_res != 0) {
                    this->video_double_size = 1;
                    this->video_hi_color = 1;
                    Log(L, "640x480 16bit success");
                }
            }

            if (this->video_changed_res == 0 &&
                this->draw_system->ScreenWidth != 0x280) {
                if (this->draw_system->IsModeAvail(0x280, 0x1E0, 8) != 0) {
                    Log(L, "640x480 8bit");
                    this->video_changed_res =
                        this->draw_system->SetDisplaySize(0x280, 0x1E0, 8);
                    if (this->video_changed_res != 0) {
                        this->video_double_size = 1;
                        Log(L, "640x480 8bit success");
                    }
                }
            }
        }
    }

    Log(L, "video_changed_res=%d, double_size=%d",
        this->video_changed_res, this->video_double_size);
    this->set_prog_mode(1);
    this->stop_sound_system();
    this->video_setup = 1;
    return 1;
}
