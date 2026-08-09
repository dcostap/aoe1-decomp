// VA: 00523F10 TRIBE_Game::start_campaign_menu (274 bytes)
// PDB: tribegam.cpp:1560-1596
// Baseline reconstruction: normal TRIBE_Game menu startup, typed screen
// construction/deletion, panel-system transition, and music selection.
// Attempt log:
// - Baseline used the canonical named TRIBE_Game/TMusic_System fields and a
//   natural new/delete screen lifecycle. It matched size, calls, CFG, and
//   frame, with only the three shifted TRIBE_Game offsets remaining.
// - Layout probe corrected the local inherited/base gap, placing
//   music_system/video_setup/started_menu_music at +0x64/+0xC00/+0xC1C;
//   this produced an exact 274-byte match under the default flags.

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;

    int play_track(int track, int position, unsigned long loop);
    int play_file(char* file, int position, unsigned long loop);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
};

extern TPanelSystem panel_system;

class TRIBE_Screen_Campaign_Selection {
public:
    virtual ~TRIBE_Screen_Campaign_Selection();
    char gap_04[0xD4];
    int error_code;
    char gap_DC[0x3F0];

    TRIBE_Screen_Campaign_Selection();
};

class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);

    char gap_04[0x60];       // +0x04 through +0x63
    TMusic_System* music_system;       // +0x64
    char gap_68[0xB98];
    int video_setup;                   // +0xC00
    char gap_C04[0x18];
    int started_menu_music;            // +0xC1C

    void shutdown_video_system();
    int start_campaign_menu();
};

int TRIBE_Game::start_campaign_menu()
{
    TRIBE_Screen_Campaign_Selection* screen;
    TMusic_System* music;

    if (this->video_setup != 0)
        this->shutdown_video_system();

    screen = new TRIBE_Screen_Campaign_Selection;
    if (screen == 0)
        return 0;

    if (screen->error_code != 0) {
        delete screen;
        return 0;
    }

    panel_system.setCurrentPanel("Campaign Selection Screen", 0);
    this->set_prog_mode(2);

    music = this->music_system;
    if (music != 0 && this->started_menu_music == 0) {
        if (music->music_type == 1) {
            music->play_track(2, 0, 0);
        } else if (music->music_type == 2) {
            music->play_file("open.mid", 0, 0);
        } else if (music->music_type == 3) {
            music->play_file("open.wav", 0, 0);
        }
        this->started_menu_music = 1;
    }

    return 1;
}
