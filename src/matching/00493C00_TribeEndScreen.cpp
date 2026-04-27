// 00493C00 TribeEndScreen::~TribeEndScreen
// Source: scr_end.cpp lines 121-126
//
// Attempt log:
// Probe 1: EH-framed destructor, /GX, 4 child objects deleted via virtual dtor

#include "..\..\include\game_globals.h"

class TPanel {
public:
    char _gap_04[0x1C];
    void* render_area;
    char _gap_24[0x1C];
    void* parent_panel;
    char _gap_44[0x28];
    int active;
    int visible;
    char _gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char _gap_9C[0x44];
    int display_changed_count;
    char _gap_E4[0x10];

    virtual ~TPanel();
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];   // adjusted to match field layout

    virtual ~TEasy_Panel();
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TChildPanel : public TPanel {
public:
    virtual ~TChildPanel();
};

class TribeEndScreen : public TScreenPanel {
public:
    TChildPanel* background;   // +0x478
    TChildPanel* title;        // +0x47C
    TChildPanel* text;         // +0x480
    TChildPanel* okButton;     // +0x484

    virtual ~TribeEndScreen();
};

TribeEndScreen::~TribeEndScreen()
{
    delete this->title;
    delete this->text;
    delete this->okButton;
    delete this->background;
}
