// VA: 00492A50 TRIBE_Credits_Screen::handle_idle
// PDB donor: scr_cred.cpp lines 217-333
// Attempt log:
// - baseline reconstruction pending: model the real TPanel/TEasy_Panel base
//   sizes, named credits-screen fields, typed virtual dirty/draw calls, and the
//   period palette/timestamp state machine before codegen tuning.

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawSystem;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void GetPalette(tagPALETTEENTRY* entries);
};

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void set_dirty(int value);
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void draw();

    char gap_04[0x1C];
    TDrawArea* render_area;                         // +0x20
    char gap_24[0xD0];                              // through +0xF3

    long handle_idle();
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x110];                             // through +0x203
    void* background_pic;                            // +0x204
    void* background_pic2;                           // +0x208
    void* palette_handle;                           // +0x20C
    char gap_210[0x268];                             // through +0x477

    virtual ~TEasy_Panel();
    virtual long setup(TDrawArea* draw_area, TPanel* parent, long left,
                       long top, long width, long height, unsigned char modal);
    virtual long action(TPanel* panel, long action, unsigned long a3,
                        unsigned long a4);
};

class TScreenPanel : public TEasy_Panel {
};

class TShape;

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    void* text_panel;                               // +0x478
    int text_set;                                    // +0x47C
    int picture_set;                                 // +0x480
    unsigned long last_picture_time;                // +0x484
    unsigned long last_pause_time;                  // +0x488
    int mode;                                        // +0x48C
    tagPALETTEENTRY color_table[256];               // +0x490
    tagPALETTEENTRY color;                           // +0x890
    TShape* back_pics[7];                            // +0x894
    int first_draw;                                  // +0x8B0
    int text_done;                                   // +0x8B4

    virtual void draw();
    long handle_idle();
    void close_screen();
};

class TDrawSystem {
public:
    char gap_00[0x478];
    unsigned char DrawType;                          // +0x478
    unsigned char ScreenMode;                        // +0x479
    void Paint(tagRECT* rect);
};

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" __declspec(dllimport) unsigned int __stdcall GetPaletteEntries(
    void* hpal, unsigned int start, unsigned int count,
    tagPALETTEENTRY* entries);

void RGE_fade_palette_start(TDrawArea* draw_area, tagPALETTEENTRY fade_color,
                            float fade_time, unsigned char fade_type,
                            tagPALETTEENTRY* palette, int first, int last);
int RGE_fade_palette_step();

long TRIBE_Credits_Screen::handle_idle()
{
    int current_mode = this->mode;

    if (current_mode == 1) {
        if (this->last_picture_time == 0) {
            goto set_time_f1;
        }

        if (debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF5)
                - this->last_picture_time < 10000) {
            goto tail;
        }

        if (this->render_area->DrawSystem->ScreenMode == 2 ||
            this->render_area->DrawSystem->DrawType == 1) {
            this->mode = 2;
            this->color.peRed = 0;
            this->color.peGreen = 0;
            this->color.peBlue = 0;

            if (this->palette_handle == 0) {
                this->render_area->GetPalette(this->color_table);
            } else {
                GetPaletteEntries(this->palette_handle, 0, 0x100,
                                  this->color_table);
            }

            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 1,
                                   (tagPALETTEENTRY*)0, 0xFF, -1);
        } else {
            this->mode = 4;
        }
        goto tail;
    } else if (current_mode == 2) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = 4;
            this->last_pause_time = 0;
            this->set_dirty(1);
            this->draw();
            this->render_area->DrawSystem->Paint((tagRECT*)0);
        }
        goto tail;
    } else if (current_mode == 4) {
        if (this->last_pause_time == 0) {
            this->last_pause_time = debug_timeGetTime(
                (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11A);
            goto tail;
        }

        debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x11E);
        this->mode = 5;
        ++this->picture_set;
        if (this->picture_set > 7) {
            this->picture_set = 1;
        }
        this->background_pic = this->back_pics[this->picture_set - 1];
        this->set_dirty(1);
        this->draw();
        this->render_area->DrawSystem->Paint((tagRECT*)0);

        if (this->render_area->DrawSystem->ScreenMode == 2 ||
            this->render_area->DrawSystem->DrawType == 1) {
            RGE_fade_palette_start(this->render_area, this->color, 0.5f, 2,
                                   this->color_table, 0xFF, -1);
            goto tail;
        }

        this->mode = 1;
        goto set_time_138;
    } else if (current_mode == 5) {
        if (RGE_fade_palette_step() != 0) {
            this->mode = 1;
            goto set_time_142;
        }
        goto tail;
    } else {
        goto tail;
    }

set_time_f1:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0xF1);
    goto tail;

set_time_138:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x138);
    goto tail;

set_time_142:
    this->last_picture_time = debug_timeGetTime(
        (char*)"C:\\msdev\\work\\age1_x1\\scr_cred.cpp", 0x142);

tail:
    if (this->text_done != 0) {
        this->close_screen();
        return 1;
    }
    return TPanel::handle_idle();
}
