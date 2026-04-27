// VA: 0049F0D0 TRIBE_Screen_Main_Error ctor (335B)
// Scr_main.cpp

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    char fields[0x500];
    
    TRIBE_Screen_Main_Error(int x, int y, int w, int h);
};

void __cdecl TScreenPanel_ctor(void* this_, int x, int y, int w, int h);

TRIBE_Screen_Main_Error::TRIBE_Screen_Main_Error(int x, int y, int w, int h) {
    TScreenPanel_ctor(this, x, y, w, h);
}
