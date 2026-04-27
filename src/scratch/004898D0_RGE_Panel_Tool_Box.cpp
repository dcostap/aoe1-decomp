// VA: 004898D0 RGE_Panel_Tool_Box ctor (1431B)
// rpnl_tbx.cpp

class TPanel {
public:
    virtual ~TPanel();
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    char fields[0x400];
    
    RGE_Panel_Tool_Box(int x, int y, int w, int h);
};

void __cdecl TPanel_ctor(void* this_, int x, int y, int w, int h);

RGE_Panel_Tool_Box::RGE_Panel_Tool_Box(int x, int y, int w, int h) {
    TPanel_ctor(this, x, y, w, h);
    
    // Create child panels
    // Create button arrays
    // Initialize fields
}
