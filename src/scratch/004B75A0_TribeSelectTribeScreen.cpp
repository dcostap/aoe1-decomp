// VA: 004B75A0 TribeSelectTribeScreen ctor (2085B)
// scr_trb.cpp

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TribeSelectTribeScreen : public TScreenPanel {
public:
    char fields[0x4B8];
    
    TribeSelectTribeScreen(int x, int y, int w, int h);
};

void __cdecl TScreenPanel_ctor(void* this_, int x, int y, int w, int h);

TribeSelectTribeScreen::TribeSelectTribeScreen(int x, int y, int w, int h) {
    TScreenPanel_ctor(this, x, y, w, h);
    
    // Initialize title, tribeText, buttons, screenText arrays
    // Create child panels and controls
    // Load tribe info strings
}
