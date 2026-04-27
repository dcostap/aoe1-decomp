// VA: 00475E50 set_bevel_info (168B)
// pnl_edit.cpp lines 474-509

class TPanel {
public:
    virtual ~TPanel();
};

class TEditPanel : public TPanel {
public:
    char gap0[0x150];
    int field_150;
    char field_154;
    char field_155;
    char field_156;
    char field_157;
    char field_158;
    char field_159;
    int field_15C;
    
    void set_bevel_info(int a, int b, int c, int d, int e, int f, int g);
};

void TEditPanel::set_bevel_info(int a, int b, int c, int d, int e, int f, int g) {
    field_154 = (char)b;
    field_155 = (char)c;
    field_150 = a;
    field_156 = (char)d;
    field_157 = (char)e;
    field_158 = (char)f;
    field_159 = (char)g;
    
    switch (a - 1) {
    case 0: field_15C = 1; break;
    case 1: field_15C = 2; break;
    case 2: field_15C = 3; break;
    default: field_15C = 0; break;
    }
    
    // Call vtable[3] with rect
    void** vtable = *(void***)this;
    ((void (__stdcall*)(void*, int, int, int, int))vtable[3])(this,
        *(int*)((char*)this + 0x0C),
        *(int*)((char*)this + 0x10),
        *(int*)((char*)this + 0x14),
        *(int*)((char*)this + 0x18));
    
    // Call vtable[8] with 1
    ((void (__stdcall*)(void*, int))vtable[8])(this, 1);
}
