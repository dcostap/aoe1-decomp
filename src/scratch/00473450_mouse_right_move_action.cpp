// VA: 00473450 mouse_right_move_action (194B)
// Pnl_btn.cpp

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap0[0x1F8];
    int field_1F8;
    char gap1FC[0x8];
    int field_204;
    
    int mouse_right_move_action(int x, int y, int flags);
};

int __cdecl LoadCursorA(int inst, int id);

int TButtonPanel::mouse_right_move_action(int x, int y, int flags) {
    int hit = ((int (__stdcall*)(void*,int,int))(*(void***)this)[0x2F])(this, x, y);
    
    if (field_1F8 != hit) {
        field_1F8 = hit;
        if (hit) {
            field_204 = (int)LoadCursorA(0, 0x389);
        }
        ((void (__stdcall*)(void*,int))(*(void***)this)[8])(this, 1);
    }
    
    if (field_1F8) {
        // handle right click
    }
    
    return 0;
}
