// VA: 00469910 TEasy_Panel::create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long, long, long, long, long)
// PDB source: Panel_ez.cpp lines 1616-1640
// attempt 1: natural new/setup path with visible helper methods; first build had fields shifted by +4 from implicit vptr.
// attempt 2: account for TEasy_Panel virtual vptr in padding so field offsets match binary.
// attempt 3: use goto labels for a common result tail; VC5 still cloned success SEH epilogue.
// attempt 4: explicit result local initialized to zero did not alter tail layout.
// attempt 5: positive combined success path with final return 0 did not change VC5's cloned epilogue.
// attempt 6: model vptr explicitly; no change.
// attempt 7: decompiler-style result variable still optimized to cloned returns.
// attempt 8: early parameter result write perturbed setup argument generation; rolled back.
// attempt 9: late parameter result assignment optimized to same cloned epilogues.
// attempt 10: volatile local result forced stack stores and worsened early diff; rolled back to best tail-drift form.
// left in scratch: behavior/call sequence and first 137 bytes match; remaining drift is VC5 SEH return-tail layout.
// rebuilt clones success/failure epilogues and leaves failure branch targets 0x13 bytes later than original common tail.
// FLAGS: config/flags/00469910_create_scrollbar.rsp keeps /GX because default no-/GX build lacks the original EH/new frame and is too small.
// worker 2026-08-10: confirmed the existing canonical typed reconstruction and /GX response-file context;
// no new source-shape lead was found beyond the documented shared-SEH-tail blocker.
// probe 2026-08-11: model the PDB's protected virtual method ABI with a compiler-owned vptr
// instead of an explicit data member; this preserves the proven +0x14/+0x448 layout while
// testing whether polymorphic TEasy_Panel context selects the original EH tail.
// probe 2026-08-11: model TScrollBarPanel's likely polymorphic base surface with a declared
// virtual destructor and reduce its explicit gap by the compiler-owned vptr; field_D8 and
// sizeof remain binary-proven while testing constructor/EH type context.
// probes 1-2 result: both ABI surfaces emitted byte-identical code (47-byte diff, +19 bytes);
// paired create_vert_slider/create_horz_slider exact donors show the same persistent /GX
// shared-failure-tail drift, so the remaining gap is compiler/EH block placement rather than
// unresolved ownership, calls, or layout.

class TPanel;
class TShape;

class TScrollBarPanel {
public:
    virtual ~TScrollBarPanel();
    char gap_04[0xD4];
    int field_D8;
    char gap_DC[0xE8];
    TScrollBarPanel();
    long setup(void* draw_area, TPanel* parent, long x, long y, long w, long h,
               char* a, char* b, char* c, char* d, long e, long f,
               TPanel* text_panel, long param_4, int vertical);
    void set_buttons(TShape* pics, int a, int b, int c, int d);
    void set_bevel_info(int type, unsigned int c1, unsigned int c2, unsigned int c3, unsigned int c4, unsigned int c5, unsigned int c6);
};

class TTextPanel {
public:
    void set_scrollbar(TScrollBarPanel* sb, int value);
};

class TEasy_Panel {
public:
    char gap_04[0x10];
    long field_14;
    long field_18;
    char gap_1C[4];
    void* draw_area;       // +0x20
    char gap_24[0xD0];
    long ideal_width;      // +0xF4
    long ideal_height;     // +0xF8
    char gap_FC[0x220];
    int use_bevels;        // +0x31C
    unsigned char bevel_color1; // +0x320
    unsigned char bevel_color2; // +0x321
    unsigned char bevel_color3; // +0x322
    unsigned char bevel_color4; // +0x323
    unsigned char bevel_color5; // +0x324
    unsigned char bevel_color6; // +0x325
    char gap_326[0x122];
    TShape* button_pics;   // +0x448

protected:
    virtual int create_scrollbar(TPanel* parent, TScrollBarPanel** out, TTextPanel* text, long param_4, long param_5, long param_6, long param_7, long param_8);
};

int TEasy_Panel::create_scrollbar(TPanel* parent, TScrollBarPanel** out, TTextPanel* text, long param_4, long param_5, long param_6, long param_7, long param_8) {
    long x = (this->field_14 * param_5) / this->ideal_width;
    long y = (param_6 * this->field_18) / this->ideal_height;
    long h = (param_8 * this->field_18) / this->ideal_height;
    TScrollBarPanel* sb = new TScrollBarPanel();
    *out = sb;

    if (sb != 0 && sb->field_D8 == 0 &&
        sb->setup(this->draw_area, parent, x, y, param_7, h, 0, 0, 0, 0, param_7, param_7, (TPanel*)text, param_4, 0) != 0) {
        if (text != 0) {
            text->set_scrollbar(*out, 0);
        }

        if (this->button_pics != 0) {
            (*out)->set_buttons(this->button_pics, -1, 8, 10, 12);
        }

        if (this->use_bevels != 0) {
            (*out)->set_bevel_info(3, this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
        }

        return 1;
    }

    return 0;
}
