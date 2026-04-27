// VA: 0049F890 ~TribeMPStartupScreen dtor (257B)
// scr_mp.cpp lines 225-241
// Has EH frame, needs /GX

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TribeMPStartupScreen : public TScreenPanel {
public:
    char gap4[0x474];
    int field_478;   // +478 list/obj
    int field_47C;   // +47C
    int field_480;   // +480
    int field_484;   // +484
    int field_488;   // +488
    int field_48C;   // +48C
    int field_490;   // +490
    int field_494;   // +494
    int field_498;   // +498
    int field_49C;   // +49C
    int field_4A0;   // +4A0
    int field_4A4;   // +4A4
    int field_4A8;   // +4A8
    
    ~TribeMPStartupScreen();
};

void __cdecl cleanupObj(void* this_, void* ptr);

TribeMPStartupScreen::~TribeMPStartupScreen() {
    cleanupObj(this, &field_478);
    cleanupObj(this, &field_47C);
    cleanupObj(this, &field_480);
    cleanupObj(this, &field_484);
    cleanupObj(this, &field_498);
    cleanupObj(this, &field_49C);
    cleanupObj(this, &field_488);
    cleanupObj(this, &field_48C);
    cleanupObj(this, &field_490);
    cleanupObj(this, &field_494);
    cleanupObj(this, &field_4A0);
    cleanupObj(this, &field_4A4);
    cleanupObj(this, &field_4A8);
}
