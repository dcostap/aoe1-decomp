// VA: 004B7F70 fillTribeText (210B)
// scr_trb.cpp lines 202-233

class TTextPanel {
public:
    virtual ~TTextPanel();
};

class TribeSelectTribeScreen {
public:
    char gap0[0x480];
    TTextPanel* tribeText;      // +0x480
    
    void fillTribeText(int tribeIdx);
};

void __cdecl TTextPanel_scroll(void* this_, int a, int b, int c);

void TribeSelectTribeScreen::fillTribeText(int tribeIdx) {
    if (tribeIdx > 8) goto skip;
    
    switch (tribeIdx) {
    case 0:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Assyrian");
        break;
    case 1:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Babylonian");
        break;
    case 2:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Egyptian");
        break;
    case 3:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Greek");
        break;
    case 4:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Hittite");
        break;
    case 5:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Israelite");
        break;
    case 6:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Minoan");
        break;
    case 7:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Phoenician");
        break;
    case 8:
        ((void (__stdcall*)(TTextPanel*, const char*))(*(void***)tribeText)[0x3A])(tribeText, "Sumerian");
        break;
    }
    
skip:
    TTextPanel_scroll(tribeText, 6, 0, 1);
}
