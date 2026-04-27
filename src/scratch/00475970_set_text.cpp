// VA: 00475970 set_text (187B)
// pnl_edit.cpp

class TPanel {
public:
    virtual ~TPanel();
    char gap4[0xF0 - 4];
    int rectX, rectY, rectW, rectH;  // +0xF0.. actually +0x0C relative
};

class TEditPanel : public TPanel {
public:
    int field_F4;
    short field_F8;
    int field_FC;
    int field_100;
    
    void set_text(char* text);
};

void __cdecl strncpy(char* dst, char* src, int n);
int __cdecl strlen_(char* s);

void TEditPanel::set_text(char* text) {
    if (!field_F4) return;
    
    if (text) {
        int len = (int)(short)field_F8;
        int* p = (int*)field_FC;
        int count = len >> 2;
        int remain = len & 3;
        int i;
        
        // Clear buffer using stosd/stosb pattern
        for (i = 0; i < count; i++) p[i] = 0;
        char* cp = (char*)&p[count];
        for (i = 0; i < remain; i++) cp[i] = 0;
        
        // Copy text
        strncpy((char*)field_FC, text, (short)field_F8 - 1);
        ((char*)field_FC)[(short)field_F8 - 1] = 0;
        
        // Compute strlen
        field_100 = strlen_((char*)field_FC);
    } else {
        ((char*)field_FC)[0] = 0;
        field_100 = 0;
    }
    
    // Refresh via vtable calls
    void** vtable = *(void***)this;
    ((void (__stdcall*)(void*, int, int, int, int))vtable[3])(this,
        *(int*)((char*)this + 0x0C),
        *(int*)((char*)this + 0x10),
        *(int*)((char*)this + 0x14),
        *(int*)((char*)this + 0x18));
    ((void (__stdcall*)(void*, int))vtable[8])(this, 1);
}
