// VA: 004739B0 do_action (230B)
// Pnl_btn.cpp

class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap4[0x134];
    int field_13C;
    char gap140[0x4];
    int field_144;
    char gap148[0xA8];
    short field_1F4;
    short curButton;
    
    int do_action(int a1);
};

void __cdecl do_action_internal(void* this_);

int TButtonPanel::do_action(int a1) {
    if (field_13C == 3) {
        short idx = curButton;
        int maxIdx = (short)field_1F4 - 1;
        if (idx >= maxIdx) {
            ((void (__stdcall*)(void*, int))(*(void***)this)[0x38])(this, 0);
        } else {
            ((void (__stdcall*)(void*, int))(*(void***)this)[0x38])(this, idx + 1);
        }
    } else if (field_13C == 2) {
        do_action_internal(this);
    }
    
    int context = *(int*)((char*)this + 0x40);
    if (context) {
        int btnIdx = (short)curButton;
        int id1 = *(int*)((char*)this + btnIdx * 4 + 0x0F4);
        int id2 = *(int*)((char*)this + btnIdx * 4 + 0x118);
    }
    
    if (*(int*)((char*)this + 0x144) == 1) {
        if (context) {
            int btnIdx = (short)curButton;
            int id1 = *(int*)((char*)this + btnIdx * 4 + 0x0F4);
            int id2 = *(int*)((char*)this + btnIdx * 4 + 0x118);
        }
    }
    
    return 0;
}
