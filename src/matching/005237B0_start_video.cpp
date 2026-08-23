// VA: 005237B0 TRIBE_Game::start_video (804 B)
// PDB source: tribegam.cpp:1255-1443
// Attempt log:
// - Replaced the incomplete offset scaffold with the period video path:
//   close the old MCI window, find the AVI, set up MCI, size and show it,
//   then restore the game input and window state.
// - Restored the omitted RGE_Base_Game range from 0x9A0 to 0xA24 so the
//   named TRIBE_Game video fields use their canonical offsets.
// - MCIWndCreateA uses caller cleanup, as shown by the original add esp,10h.
// - Removed decompiler-only +4 buffer prefixes.  The named buffers pass their
//   first byte to the status query, file APIs, and MCI create call.
// - Declared video_sub_wnd_proc as the real callback function.  This restores
//   the direct callback address passed to SetWindowLongA and yields an exact
//   804-byte match with the default flags.

#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "../../include/tribegam_context.h"

extern "C" int __cdecl __open(const char* path, int flags, ...);
extern "C" void* __cdecl MCIWndCreateA(void* parent, void* instance,
                                         unsigned long style,
                                         const char* file);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern int video_codec_available;
extern long __stdcall video_sub_wnd_proc(
    void* hwnd, unsigned int message, unsigned int wparam, long lparam);

#if 0
class RGE_Prog_Info {
public:
    char gap_00[0x410];
    void* instance; // +0x410
    char gap_414[0x8E0 - 0x414];
    long main_wid; // +0x8E0
    long main_hgt; // +0x8E4
    char gap_8E8[0x1130 - 0x8E8];
    char avi_dir[261]; // +0x1130
};

class RGE_Game_Options {
public:
    char gap_00[0x86];
    unsigned char multiplayerGameValue; // +0x86
    char gap_87[0xA8 - 0x87];
};

class TDrawSystem {
public:
    void SetPalette(void* palette);
    void ClearPrimarySurface();
};

class TRegistry {
public:
    char* RegGetAscii(int value, char* name);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x08];
    RGE_Prog_Info* prog_info; // +0x0C
    void* prog_window; // +0x10
    char gap_14[0x34];
    TDrawSystem* draw_system; // +0x48
    char gap_4C[0x1AC - 0x4C];
    TRegistry* registry; // +0x1AC
    char gap_1B0[0x8F8 - 0x1B0];
    RGE_Game_Options rge_game_options; // +0x8F8
    char gap_9A0[0xA24 - 0x9A0];

    void set_render_all();
    void enable_input();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0xBEC - 0xA24];
    void* video_window; // +0xBEC
    int cur_video; // +0xBF0
    void* old_video_wnd_proc; // +0xBF4
    int video_paused; // +0xBF8
    unsigned long last_video_time; // +0xBFC
    int video_setup; // +0xC00
    int video_double_size; // +0xC04
    int video_changed_res; // +0xC08
    int video_hi_color; // +0xC0C
    long video_save_res_wid; // +0xC10
    long video_save_res_hgt; // +0xC14
    void* video_save_palette; // +0xC18

    int setup_video_system();
    void stop_video(unsigned char do_stop);
    int start_video(int video, char* file);
};
#endif

int TRIBE_Game::start_video(int video, char* file)
{
    if (this->video_window != 0) {
        char str[100];
        SendMessageA(this->video_window, 0x46A, 100, (long)str);
        if (str[0] != 0 && strcmp(str, "stopped") != 0) {
            SendMessageA(this->video_window, 0x808, 0, 0);
        }
        SendMessageA(this->video_window, 0x10, 0, 0);
        this->video_window = 0;
    }

    this->cur_video = video;
    if (this->rge_game_options.multiplayerGameValue != 1 &&
        file != 0 && *file != 0) {
        char temp_name[260];
        sprintf(temp_name, "%s%s.avi", this->prog_info->avi_dir, file);
        int file_handle = __open(temp_name, 0, 0x100);
        if (file_handle == -1) {
            char* cd_path = this->registry->RegGetAscii(0, (char*)"CDPath");
            if (cd_path != 0) {
                sprintf(temp_name, "%sgame\\avi\\%s.avi", cd_path,
                        file);
                file_handle = __open(temp_name, 0, 0x100);
            }
            if (file_handle == -1)
                goto start_video_failed;
        }

        if (video_codec_available != 0 &&
            (this->video_setup != 0 || this->setup_video_system() != 0)) {
            this->video_window = MCIWndCreateA(
                this->prog_window, this->prog_info->instance, 0x50001F0A,
                temp_name);
            if (this->video_window != 0) {
                RECT video_rect;
                this->old_video_wnd_proc = (int (__stdcall *)())GetWindowLongA(
                    this->video_window, -4);
                SetWindowLongA(this->video_window, -4,
                               (long)::video_sub_wnd_proc);

                if (this->video_hi_color == 0) {
                    void* palette = (void*)SendMessageA(
                        this->video_window, 0x47E, 0, 0);
                    this->draw_system->SetPalette(palette);
                }

                GetClientRect(this->video_window, &video_rect);
                if (this->video_double_size != 0) {
                    video_rect.right = video_rect.right * 2;
                    video_rect.bottom = video_rect.bottom * 2;
                }

                MoveWindow(
                    this->video_window,
                    this->prog_info->main_wid / 2 - video_rect.right / 2,
                    this->prog_info->main_hgt / 2 - video_rect.bottom / 2,
                    video_rect.right, video_rect.bottom, 0);
                this->set_render_all();
                InvalidateRect(this->prog_window, 0, 1);
                SendMessageA(this->prog_window, 0x0F, 0, 0);
                this->draw_system->ClearPrimarySurface();
                this->video_paused = 0;
                this->last_video_time = debug_timeGetTime(
                    (char*)"C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x598);
                SendMessageA(this->video_window, 0x806, 0, 0);
                this->enable_input();
                SetCursor(0);
                SetClassLongA(this->prog_window, -12, 0);
                return 1;
            }
        }
    }

start_video_failed:
    this->stop_video(1);
    return 0;
}
