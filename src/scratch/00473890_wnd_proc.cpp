// VA: 00473890 wnd_proc (131B)
// Pnl_btn.cpp lines 1118-1135

class TPanel {
public:
    virtual ~TPanel();
};

class TButtonPanel : public TPanel {
public:
    char gap4[0x138];
    int field_13C;      // +0x13C
    char gap140[0xB4];  // to 0x1F4
    int field_1F8;      // +0x1F8 (active/hover state)
    char gap1FC[0xAC];  // to 0x2A8
    int field_2AC;      // +0x2AC (captured button/window?)
    
    int wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp);
};

int __cdecl TPanel_wnd_proc(void* this_, void* hwnd, unsigned msg, unsigned wp, long lp);
int __cdecl do_action(void* this_);
int __cdecl SetCursor(void* cursor);
int* __cdecl LoadCursorA(int inst, int id);

int TButtonPanel::wnd_proc(void* hwnd, unsigned msg, unsigned wp, long lp) {
    if (msg == 0x101) {  // WM_KEYUP
        if (!field_2AC) goto def;
        if (wp != field_2AC) goto def;
        
        if (field_13C == 2) {
            // VK_RETURN handling
            // call vtable[8] with 1
            ((void (__stdcall*)(void*,int))(*(void***)this)[8])(this, 1);
            // LoadCursor/SetCursor
            int* cursorRes = LoadCursorA(0, 0x0F);
            SetCursor(cursorRes);
        } else {
            field_1F8 = 0;
        }
        
        do_action(this);  // call 004739B0
        return 1;
    }
    
def:
    return TPanel_wnd_proc(this, hwnd, msg, wp, lp);
}
