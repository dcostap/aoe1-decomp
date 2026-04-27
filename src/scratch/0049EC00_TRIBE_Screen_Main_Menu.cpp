// VA: 0049EC00 ~TRIBE_Screen_Main_Menu dtor (203B)
// Scr_main.cpp lines 199-214
// Has EH frame, needs /GX

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TPanel {
public:
    virtual ~TPanel();
};

class TTextPanel : public TPanel {
};

class TPicturePanel : public TPanel {
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    char gap4[0x474];
    TPanel* field_478;          // +0x478 title1
    TPanel* field_47C;          // +0x47C title2
    TPanel* field_480[7];       // +0x480-0x49C buttons[7]
    TTextPanel* field_49C;      // +0x49C ms_title_text
    TPanel* field_4A0;          // +0x4A0 ms_copy_text1
    TPanel* field_4A4;          // +0x4A4 ms_copy_text2
    TPanel* field_4A8;          // +0x4A8 warning_text
    TPicturePanel* field_4AC;   // +0x4AC circle_p_pic
    
    ~TRIBE_Screen_Main_Menu();
};

void __cdecl delete_panel(void* this_, void** pPanel);

TRIBE_Screen_Main_Menu::~TRIBE_Screen_Main_Menu() {
    delete_panel(this, (void**)&field_478);
    delete_panel(this, (void**)&field_47C);
    delete_panel(this, (void**)&field_4A0);
    delete_panel(this, (void**)&field_4A4);
    delete_panel(this, (void**)&field_4A8);
    
    int i;
    for (i = 0; i < 7; i++) {
        delete_panel(this, (void**)&field_480[i]);
    }
    
    if (field_4AC) {
        delete field_4AC;
    }
    if (field_49C) {
        delete field_49C;
    }
}
