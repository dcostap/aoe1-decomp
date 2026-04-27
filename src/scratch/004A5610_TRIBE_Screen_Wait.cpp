// VA: 004A5610 TRIBE_Screen_Wait ctor (2493B)
// scr_mps.cpp
// EH frame (/GX)

class TRIBE_Screen_Wait {
public:
    int* vtable;
    char gap4[0x4];
    int field_8;
    
    TRIBE_Screen_Wait();
};

TRIBE_Screen_Wait::TRIBE_Screen_Wait() {
    vtable = (int*)0;
    char buf[772];
    field_8 = (int)buf;
}
