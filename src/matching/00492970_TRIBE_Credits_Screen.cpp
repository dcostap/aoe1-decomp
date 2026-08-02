// VA: 00492970 ~TRIBE_Credits_Screen
// Baseline: natural /GX virtual destructor with the binary-proven owned shape
// array, scroll-text panel, inherited reset field, and music cleanup.
// Flags: default /O2 /Oy removes the observed EH registration and is 45 bytes
// short; retain the target-specific /GX response file.

#include <new.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x110];
    int field_204;
    char gap_208[0x270];
    virtual ~TEasy_Panel();
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TShape {
public:
    ~TShape();
};

class TScrollTextPanel {
public:
    virtual ~TScrollTextPanel();
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;
    char gap_105[0x143];
    int track_count;

    int play_tracks(int from, int to, int loop_value, int make_current, unsigned long position);
};

class RGE_Base_Game {
public:
    char gap_00[0x64];
    TMusic_System* music_system;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    TScrollTextPanel* text_panel;       // +0x478
    char gap_47C[0x14];
    char gap_490[0x400];                 // color table
    char color[4];                      // +0x890
    TShape* back_pics[7];               // +0x894
    int first_draw;                     // +0x8B0
    int text_done;                      // +0x8B4

    virtual ~TRIBE_Credits_Screen();
};

TRIBE_Credits_Screen::~TRIBE_Credits_Screen()
{
    for (int i = 0; i < 7; i++) {
        if (this->back_pics[i] != 0) {
            delete this->back_pics[i];
            this->back_pics[i] = 0;
        }
    }

    this->field_204 = 0;

    if (this->text_panel != 0) {
        delete this->text_panel;
        this->text_panel = 0;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 0xF) {
        music->play_tracks(5, 0xE, 1, 0, 0);
    }
}
