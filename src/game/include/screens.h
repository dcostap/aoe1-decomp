#pragma once
#include "common.h"
#include "TPanel.h"

class TEasy_Panel : public TPanel {
public:
    void popupOKDialog(const char* text, long p2, void* p3, long p4);
};

class TRIBE_Screen_Status_Message : public TEasy_Panel {
public:
    TRIBE_Screen_Status_Message(int p1, const char* p2, void* p3, const char* p4);
};

class TRIBE_Screen_Main_Menu : public TEasy_Panel {
public:
    TRIBE_Screen_Main_Menu();
    virtual void draw() override;
};

class TRIBE_Screen_Main_Error : public TEasy_Panel {
public:
    TRIBE_Screen_Main_Error();
    void set_text(int id);
};

class TribeMPSetupScreen : public TEasy_Panel {
public:
    TribeMPSetupScreen();
};

class TRIBE_Screen_Game : public TEasy_Panel {
public:
    void game_mode_changed(int new_mode, int old_mode);
};
