// VA: 0049E6D0 TRIBE_Screen_Main_Menu ctor (1281B)
// Scr_main.cpp

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    char fields[0x4B0];
    
    TRIBE_Screen_Main_Menu(int x, int y, int w, int h);
};

void __cdecl TScreenPanel_ctor(void* this_, int x, int y, int w, int h);

TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(int x, int y, int w, int h) {
    TScreenPanel_ctor(this, x, y, w, h);
}
