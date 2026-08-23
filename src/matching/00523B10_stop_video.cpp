// VA: 00523B10 TRIBE_Game::stop_video (998 B)
// PDB source: tribegam.cpp:1449-1555
//
// Attempt log:
// - Replaced the old free-function/video-shutdown scaffold with the natural
//   tribegam.cpp stop_video flow: save the current video number, query the
//   video window, restore the draw system, and dispatch the mode switch.
// - A block-local cached SendMessageA pointer recovered the original EBP/IAT
//   schedule, saved-register use, frame, and all early video teardown bytes.
// - The shared start-menu arm for cases 0/1/2/5 and direct default returns
//   recovered the original five-entry dispatch, call order, and exact size.
// - Positive game-status arms recovered both music branch polarities.
// - Treating the status query as a write to the natural buffer base (str and
//   str[0]) removed the Ghidra-only +4 offset and produced an exact match.
// - Tested the exact-donor dllimport SendMessageA surface instead of the
//   cached function-pointer local; it broke the frame and 998-byte structure,
//   so it was rolled back. The cached-IAT source remains the best lead.
// - Scoped/register/aggregate local-home probes were codegen-neutral and were
//   not retained; the living source keeps separate named int/char locals.

#include <new.h>
#include <string.h>
#include <windows.h>

#include "../../include/tribegam_context.h"

typedef long (__stdcall *SendMessageFn)(
    void* hwnd, unsigned int message, unsigned int wparam, long lparam);

#if 0
class TPicture;

class TDrawSystem {
public:
    void ClearPrimarySurface();
    void SetPalette(void* palette);
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type; // +0x104

    int play_track(int track, int position, unsigned long loop);
    int play_file(char* file, int position, unsigned long loop);
};

class RGE_Player {
public:
    char gap_00[0x80];
    unsigned char game_status; // +0x80
};

class RGE_Scenario {
public:
    char gap_00[0x198C];
    TPicture* picture; // +0x198C

    char* Get_description();
};

class RGE_Game_World {
public:
    char gap_00[0x5C];
    RGE_Scenario* scenario; // +0x5C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x0C];
    void* prog_window; // +0x10
    char gap_14[0x08];
    void* prog_palette; // +0x1C
    char gap_20[0x28];
    TDrawSystem* draw_system; // +0x48
    char gap_4C[0x18];
    TMusic_System* music_system; // +0x64
    char gap_68[0x3F4 - 0x68];
    RGE_Game_World* world; // +0x3F4
    char gap_3F8[0xA24 - 0x3F8];

    void set_render_all();
    int multiplayerGame();
    int randomGame();
    int campaignGame();
    void close();
    RGE_Player* get_player();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0xBEC - 0xA24];
    void* video_window; // +0xBEC
    int cur_video; // +0xBF0
    char gap_BF4[0xC00 - 0xBF4];
    int video_setup; // +0xC00

    void stop_video(unsigned char do_stop);
    int start_video(int video, char* file);
    int start_menu();
    void shutdown_video_system();
    void close_game_screens(int destroy_game_screen);
    int create_game_screen();
    char* game_over_msg();
    void quit_game();
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xD4];
    int error_code; // +0xD8
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    char gap_478[0x24];
    TRIBE_Mission_Screen(char* description, unsigned char flag,
                         TPicture* picture);
};

class TribeAchievementsScreen : public TScreenPanel {
public:
    char gap_478[0x180];
    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char* message, int end_game);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;
#endif

void TRIBE_Game::stop_video(unsigned char do_stop)
{
    int save_vid_num;
    char str[100];

    save_vid_num = this->cur_video;
    this->cur_video = -1;

    if (this->video_window != 0) {
        SendMessageFn send_message = SendMessageA;

        send_message(this->video_window, 0x46A, 100, (long)str);
        if (str[0] != 0 && strcmp(str, "stopped") != 0) {
            send_message(this->video_window, 0x808, 0, 0);
        }

        send_message(this->video_window, 0x10, 0, 0);
        this->video_window = 0;
        this->draw_system->ClearPrimarySurface();
        this->draw_system->SetPalette(this->prog_palette);
        this->set_render_all();
        InvalidateRect(this->prog_window, 0, 1);
        send_message(this->prog_window, 0x0F, 0, 0);
        this->draw_system->ClearPrimarySurface();
    }

    switch (save_vid_num) {
    case 0:
        if (do_stop != 0) {
            this->start_video(1, "logo2");
            return;
        }
        goto start_menu_path;

    case 1:
        if (do_stop != 0) {
            this->start_video(2, "introx");
            return;
        }
        goto start_menu_path;

    case 2:
    case 5:
    start_menu_path:
        if (this->start_menu() == 0) {
            this->close();
        }
        return;

    case 3:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }

        {
            char* description = this->world->scenario->Get_description();
            if (description != 0 && description[0] != 0 &&
                this->multiplayerGame() == 0 &&
                (this->randomGame() == 0 || this->campaignGame() != 0)) {
                TRIBE_Mission_Screen* screen =
                    new TRIBE_Mission_Screen(description, 0,
                                              this->world->scenario->picture);
                panel_system.setCurrentPanel("Mission Dialog", 0);
                return;
            }
        }

        this->create_game_screen();
        return;

    case 4:
        if (this->video_setup != 0) {
            this->shutdown_video_system();
        }

        if (this->world != 0) {
            this->close_game_screens(0);

            TribeAchievementsScreen* screen =
                new TribeAchievementsScreen(this->game_over_msg(), 1);
            if (screen != 0 && screen->error_code == 0) {
                panel_system.setCurrentPanel("Achievements Screen", 0);

                if (this->music_system != 0) {
                    if (this->music_system->music_type == 1) {
                        RGE_Player* player = this->get_player();
                        if (player->game_status == 1) {
                            this->music_system->play_track(3, 0, 0);
                        } else {
                            this->music_system->play_track(4, 0, 0);
                        }
                        return;
                    }

                    if (this->music_system->music_type == 2) {
                        RGE_Player* player = this->get_player();
                        if (player->game_status == 1) {
                            this->music_system->play_file("won.mid", 0, 0);
                        } else {
                            this->music_system->play_file("lost.mid", 0, 0);
                        }
                        return;
                    }
                }

                return;
            }

            if (screen != 0) {
                delete screen;
            }
            this->quit_game();
            return;
        }
        return;

    default:
        return;
    }
}
