#pragma once
#include "common.h"
#include "TButtonPanel.h"
#include "TTextPanel.h"
#include "TPicturePanel.h"

class TEasy_Panel : public TPanel {
public:
    // Size: 0x478 (1144 bytes)
    // Offset 0x0F4 to 0x478 is TEasy_Panel specific.
    char easy_panel_pad[0x478 - 0xF4];

    TEasy_Panel(char* name);
    virtual long setup(TDrawArea* render_area, TPanel* parent, char* info_file, long p4, int p5, long p6, long p7, long p8, long p9, long p10);
    void set_ideal_size(long w, long h);
    int create_button(TPanel* parent, TButtonPanel** btn, char* name, int id, int x, int y, int w, int h, int p9, int p10, int p11);
    int create_text(TPanel* parent, TTextPanel** txt, int res_id, int x, int y, int w, int h, int p8, int p9, int p10);
    
    void popupOKDialog(const char* text, long p2, void* p3, long p4);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    virtual long setup(TDrawArea* render_area, char* name, long p3, uchar p4, int p5);
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    using TScreenPanel::setup;
    using TEasy_Panel::setup;
    using TPanel::setup;
    TTextPanel* title1; // +0x478
    TTextPanel* title2; // +0x47C
    TButtonPanel* button[7]; // +0x480
    TTextPanel* ms_title_text; // +0x49C
    TTextPanel* ms_copy_text1; // +0x4A0
    TTextPanel* ms_copy_text2; // +0x4A4
    TTextPanel* warning_text; // +0x4A8
    TPicturePanel* circle_p_pic; // +0x4AC

    TRIBE_Screen_Main_Menu();
    virtual ~TRIBE_Screen_Main_Menu();
    virtual long setup(TDrawArea* render_area, char* name);
    virtual void draw() override;
};
static_assert(sizeof(TRIBE_Screen_Main_Menu) == 0x4B0, "Size mismatch for TRIBE_Screen_Main_Menu");

class TRIBE_Screen_Main_Error : public TEasy_Panel {
public:
    char pad[0x484 - 0x478];
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

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison; // +0x2B8 (Size: 0x4)
    int garrsion_number; // +0x2BC (Size: 0x4)
    unsigned char tribe_button_type; // +0x2C0 (Size: 0x1)
    unsigned char _pad_0[0x3]; // 0x02c1 (Gap: 3)
    TShape* border_pic; // +0x2C4 (Size: 0x4)
    unsigned char* color_table; // +0x2C8 (Size: 0x4)
    int border_frame; // +0x2CC (Size: 0x4)
    char text_msg[256]; // +0x2D0 (Size: 0x100)
    int in_use; // +0x3D0 (Size: 0x4)

    TRIBE_Panel_Button();
};
static_assert(sizeof(TRIBE_Panel_Button) == 0x3D4, "Size mismatch for TRIBE_Panel_Button");

class TRIBE_Screen_Status_Message : public TEasy_Panel {
public:
    TRIBE_Screen_Status_Message(int p1, const char* p2, void* p3, const char* p4);
};
