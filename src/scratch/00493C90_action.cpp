// 00493C90 TribeEndScreen::action
//
// Probe 1: function pointer ctor — wrong codegen
// Probe 2: new expression — generates allocator stub before function (offset 0 mismatch)
// Left in scratch: constructor call via function pointer or new expression both give wrong codegen
//   Need a proper TribeAchievementsScreen declaration + new call that VC5 can inline

#include "..\..\include\game_globals.h"
#include <stdlib.h>

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
    char* get_string(int id);
};

class TEasy_Panel : public TPanel {
public:
    char _gap_F4[0x384];
    virtual ~TEasy_Panel();
    long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};
extern TPanelSystem* panel_system;

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TribeAchievementsScreen : public TPanel {
public:
    char _gap_F4[0x504];
    TribeAchievementsScreen(char* str, int flag);
};

class TribeEndScreen : public TScreenPanel {
public:
    void* background;
    void* title;
    void* text;
    void* okButton;

    virtual ~TribeEndScreen();
    long action(TPanel* panel, long id, unsigned long param3, unsigned long param4);
};

void* operator_new(size_t size) {
    return malloc(size);
}

long TribeEndScreen::action(TPanel* panel, long id, unsigned long param3, unsigned long param4)
{
    if (panel == 0 || id != 1)
        return ((TEasy_Panel*)this)->action(panel, id, param3, param4);

    char* str = this->get_string(0x269E);
    TribeAchievementsScreen* obj = new TribeAchievementsScreen(str, 1);

    panel_system->setCurrentPanel("Achievements Screen", 0);
    panel_system->destroyPanel("End Screen");
    return 1;
}
