// VA: 004926E0 TRIBE_Credits_Screen constructor
// PDB donor: scr_cred.cpp lines 46-169
// Attempt log:
// - baseline reconstruction: restored the period TPanel -> TEasy_Panel ->
//   TScreenPanel ownership and 0xF4/0x478 base sizes, the named credits fields,
//   real TScreenPanel setup/size calls, CRT file loading, typed panel/shape
//   new-expressions, and the music-system gate.
// - moving the natural back-picture zero loop after scalar member initialization
//   reproduced the original field stores followed by rep stosd (86 -> 13 bytes).
// - declaring the shape resource id before the first background-picture store
//   reproduced the original ESI/EDI setup; current source is an exact MATCH.

#include <fcntl.h>
#include <io.h>
#include <new.h>
#include <stdio.h>
#include <stdlib.h>

struct tagPALETTEENTRY {
    unsigned char peRed;
    unsigned char peGreen;
    unsigned char peBlue;
    unsigned char peFlags;
};

class TDrawArea;
class TMusic_System;

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x10];
    long width;                                      // +0x14
    long height;                                     // +0x18
    char gap_1C[4];
    TDrawArea* render_area;                          // +0x20
    char gap_24[0xB4];
    int error_code;                                  // +0xD8
    char gap_DC[0x18];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x110];
    void* background_pic;                            // +0x204
    char gap_208[0x270];                             // through +0x477

    void set_ideal_size(long width_value, long height_value);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    TScreenPanel(char* name);
    long setup(TDrawArea* draw_area, char* name, long id, int value);
};

class RGE_Font {
public:
    void* font;
    long font_wid;
    long font_hgt;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x48];
    TDrawArea* draw_area;                            // +0x4C
    char gap_50[0x14];
    TMusic_System* music_system;                     // +0x64

    RGE_Font* get_font(int font_id);
};

extern RGE_Base_Game* rge_base_game;

class TTextPanel {
public:
    virtual ~TTextPanel();
    char gap_04[0x11C];
    unsigned long text_color1;                       // +0x120
    unsigned long text_color2;                       // +0x124
    char gap_128[0x60];
};

class TScrollTextPanel : public TTextPanel {
public:
    virtual ~TScrollTextPanel();

    int scroll;                                      // +0x188
    unsigned long last_time;                         // +0x18C
    int speed;                                       // +0x190
    int done;                                        // +0x194

    TScrollTextPanel(TPanel* parent, TDrawArea* draw_area,
                     long x, long y, long width_value, long height_value,
                     int speed_value, void* font, long font_wid,
                     long font_hgt, char* text);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char* filename, long file_id);
    ~TShape();
};

class TMusic_System {
public:
    char gap_00[0x104];
    unsigned char music_type;                        // +0x104
    char gap_105[0x143];
    int track_count;                                  // +0x248

    int play_tracks(int from, int to, int loop_value,
                    int make_current, unsigned long position);
};

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    void* text_panel;                                 // +0x478
    int text_set;                                     // +0x47C
    int picture_set;                                  // +0x480
    unsigned long last_picture_time;                 // +0x484
    unsigned long last_pause_time;                   // +0x488
    int mode;                                         // +0x48C
    char color_table[0x400];                          // +0x490
    tagPALETTEENTRY color;                            // +0x890
    TShape* back_pics[7];                             // +0x894
    int first_draw;                                   // +0x8B0
    int text_done;                                    // +0x8B4

    virtual ~TRIBE_Credits_Screen();
    virtual long handle_idle();
    virtual void draw();
    virtual long action(TPanel* panel, long value,
                        unsigned long a3, unsigned long a4);

    TRIBE_Credits_Screen();
};

TRIBE_Credits_Screen::TRIBE_Credits_Screen()
    : TScreenPanel("Credits Screen")
{
    int zero = 0;
    int one = 1;

    this->text_panel = 0;
    this->text_set = one;
    this->picture_set = one;
    this->last_picture_time = zero;
    this->last_pause_time = zero;
    this->mode = one;
    this->first_draw = one;
    this->text_done = zero;

    for (int i = 0; i < 7; ++i) {
        this->back_pics[i] = 0;
    }

    if (this->setup(rge_base_game->draw_area, "scr_cred", 0xC38B, one) == 0) {
        this->error_code = one;
        return;
    }

    this->set_ideal_size(0x280, 0x1E0);

    RGE_Font* font = rge_base_game->get_font(4);
    char* file_buf = 0;
    int fd = _open("data2\\list.cr", 0x8000);
    int size = 0;
    if (fd != -1) {
        _lseek(fd, 0, 2);
        size = _tell(fd);
        file_buf = (char*)calloc(size + 1, 0x400);
        if (file_buf != 0) {
            _lseek(fd, 0, 0);
            _read(fd, file_buf, size);
        }
        _close(fd);
    }

    TScrollTextPanel* scroll_panel = new TScrollTextPanel(
        this, this->render_area,
        (this->width / 2) - 0xFA, (this->height / 2) - 0x96,
        0x1F4, 0x12C, 0x1E,
        font->font, font->font_wid, font->font_hgt, file_buf);
    this->text_panel = scroll_panel;

    if (file_buf != 0) {
        free(file_buf);
    }

    int id = 0xC3EB;
    this->back_pics[0] = (TShape*)this->background_pic;
    TShape** shape_slot = &this->back_pics[1];
    for (; id - 0xC3EA < 7; ++id) {
        char temp_file_name[13];
        sprintf(temp_file_name, "credit%d", id - 0xC3E9);
        *shape_slot = new TShape(temp_file_name, id);
        ++shape_slot;
    }

    TMusic_System* music = rge_base_game->music_system;
    if (music != 0 && music->music_type == 1 && music->track_count == 0x0F) {
        music->play_tracks(0x0F, 0x0F, 1, 0, 0);
    }
}
