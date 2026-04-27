// VA: 00473240 mouse_left_move_action (194B)
// Pnl_btn.cpp lines 893-920

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap0[0x1F8];
    int field_1F8;      // +0x1F8 (hover state)
    char gap1FC[0x8];   // to 0x204
    int field_204;      // +0x204 (cursor handle)
    char gap208[0x98];  // to 0x2A0
    
    int mouse_left_move_action(int x, int y, int flags);
};

int __cdecl LoadCursorA(int inst, int id);

int TButtonPanel::mouse_left_move_action(int x, int y, int flags) {
    int hit = ((int (__stdcall*)(void*,int,int))(*(void***)this)[0x2F])(this, x, y);
    
    if (field_1F8 != hit) {
        field_1F8 = hit;
        if (hit) {
            field_204 = (int)LoadCursorA(0, 0x389);  // IDC_HAND or similar
        }
        ((void (__stdcall*)(void*,int))(*(void***)this)[8])(this, 1);
    }
    
    if (field_1F8) {
        // Set cursor to something
        int isDown = *(int*)((char*)this + 0x40);  // mouse state
        // ...
    }
    
    return 0;
}
