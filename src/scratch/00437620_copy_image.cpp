// tried the direct-screenmode gate with a plain local RECT; the remaining mismatch is now in the prolog/field-load shape
// keep the object layout minimal and let VC5 choose the stack pattern, rather than forcing aliases or helper temps

// tried a direct RECT-local form; mismatch moved from the call setup into prolog/field-offset shape
// tried a COM-style Copy stub and then a plain RECT/field rewrite; the remaining gap is still the early stack/init ordering

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void Copy(void*, int, int, void*, int);
};

class RGE_Diamond_Map {
public:
    char gap_00[0x0C];
    int field_0C;
    int field_10;
    int field_14;
    int field_18;
    TDrawArea* PrimarySurface;
    int field_20;
    char gap_24[0x168 - 0x24];
    TDrawArea* save_area;
    char gap_16C[0x479 - 0x16C];
    unsigned char ScreenMode;

    void copy_image();
};

void RGE_Diamond_Map::copy_image() {
    tagRECT r;

    r.top = 0;
    r.bottom = field_14 - 1;
    r.left = 0;
    r.right = field_18 - 1;

    if (ScreenMode == 2 && PrimarySurface != 0) {
        save_area->Copy((void*)field_20, field_0C, field_10, &r, 0);
    }
}
