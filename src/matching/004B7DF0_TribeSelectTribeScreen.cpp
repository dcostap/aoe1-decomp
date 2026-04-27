// VA: 004B7DF0 ~TribeSelectTribeScreen dtor (227B)
// scr_trb.cpp lines 162-172
// Has EH frame (fs:[0]), needs /GX

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel {
public:
    virtual ~TTextPanel();
};

class TButtonPanel {
public:
    virtual ~TButtonPanel();
};

class TribeSelectTribeScreen : public TScreenPanel {
public:
    char gap4[0x478];
    TTextPanel* title;          // +0x47C
    TTextPanel* tribeText;      // +0x480
    TButtonPanel* tribeButton[9]; // +0x484 to +0x4A4
    TButtonPanel* okButton;     // +0x4A8
    TButtonPanel* cancelButton; // +0x4AC
    char** screenText;          // +0x4B0
    int numLines;               // +0x4B4
    
    ~TribeSelectTribeScreen();
};

extern void __cdecl free(void* ptr);

TribeSelectTribeScreen::~TribeSelectTribeScreen() {
    delete title;
    delete tribeText;
    {
        int i;
        for (i = 0; i < 9; i++) {
            delete tribeButton[i];
        }
    }
    delete okButton;
    delete cancelButton;
    {
        int i;
        for (i = 0; i < numLines; i++) {
            free(screenText[i]);
        }
    }
    free(screenText);
}
