// VA: 00473930 hit_button (124B)
// Pnl_btn.cpp

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap0[0x10];
    int rectX, rectY, rectW, rectH;
    char gap1C[0x16C];  // 0x1C to 0x188
    int field_188;
    int field_18C;
    int field_190;
    char gap194[0x62];  // 0x194 to 0x1F6
    short curButton;    // +0x1F6
    
    int hit_button(int x, int y);
};

int TButtonPanel::hit_button(int x, int y) {
    // Call base class hit test via vtable
    int hit = ((int (__stdcall*)(void*,int,int))(*(void***)this)[0x2F])(this, x, y);
    if (!hit) return 0;
    if (field_190) return 1;
    
    int btnIdx = (short)curButton;
    int* btnData = (int*)((char*)this + 0x14C);
    if (!btnData[btnIdx]) return 1;
    
    short* btnIds = (short*)((char*)this + 0x170);
    short id = btnIds[btnIdx];
    
    int dx = x - field_188;
    int dy = y - field_18C;
    // call 004B9140 with dx, dy, id
    return 1;
}
