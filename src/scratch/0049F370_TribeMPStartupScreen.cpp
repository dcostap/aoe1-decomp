// VA: 0049F370 TribeMPStartupScreen ctor (1278B)
// scr_mp.cpp

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TribeMPStartupScreen : public TScreenPanel {
public:
    char fields[0x4B0];
    
    TribeMPStartupScreen(int x, int y, int w, int h);
};

void __cdecl TScreenPanel_ctor(void* this_, int x, int y, int w, int h);

TribeMPStartupScreen::TribeMPStartupScreen(int x, int y, int w, int h) {
    TScreenPanel_ctor(this, x, y, w, h);
}
