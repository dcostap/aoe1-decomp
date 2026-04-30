// VA: 004AB710 TRIBE_Screen_Sed::handle_size | scr_sed.cpp:2201-2213
// Using proper inheritance chain

class TPanel {
public:
    char gap_00[0x04]; // vtable
    long handle_size(long width, long height);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
};

class TScreenPanel : public TEasy_Panel {
public:
    char gap_478[1]; // just a marker, size matches
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    void position_panels(void);
    long handle_size(long width, long height);
};

long TRIBE_Screen_Sed::handle_size(long width, long height) {
    TPanel::handle_size(width, height);
    this->position_panels();
    TPanel::handle_size(width, height);
    return 0;
}
