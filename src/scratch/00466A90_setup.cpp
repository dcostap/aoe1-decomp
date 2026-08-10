// 00466A90 TEasy_Panel::setup (Panel_ez.cpp lines 52-215)
// attempt 1: full natural reconstruction from decoded stack layout.
// Key facts decoded from original asm:
//  - locals: own_mem flag at E-0xCC8 (init -1, set 1 on file read, tested ==1 at end)
//  - 37 sscanf int outputs + back_pic_id_b1(RESFILE out) + resDataSize dummy at E-0xC2C
//  - temp_label[256] at E-0xC28; sprintf/open use temp_label+0xFC
//  - 10 name buffers, strings live at buf+0x100 (sscanf targets AND setters both use +0x100)
//  - popup_info_file_name_in[256] at frame bottom; pos29 uses popup+0 (== a1+0x100 == E-0x104)
//  - x/y/w/h params: arg4=x, arg5=y, arg6=w, arg7=h; param5 selects area-derived w/h
//  - set_text/focus/state colors pack 3 bytes: (uchar)a<<16 | (uchar)b<<8 | (uchar)c
//
// STATUS: frame 0xCC8 exact, 33/33 calls aligned, field offsets +0xFC/+0x200/+0x470 fixed (TPanel size 0xFC).
// Remaining drift: rebuilt own_mem lands at E-0xCC4 instead of E-0xCC8 (4-byte bottom pad),
// size -30, shape 60%. Next leads: (a) one of the 4-byte bottom locals is being eliminated or
// the int region is 4 bytes short of the original's 40-dword CC8..C2C span; probe declaring the
// dummy resDataSize as char[4] or adding a 4-byte used local below own_mem; (b) check whether the
// two vslot calls need an explicit cached vtable local (orig keeps [esi] in ebx across both calls).
// Probes so far: attempt-1a (a1+0x100 for pos29, dead popup eliminated, frame 0xBC8) rolled into
// attempt-1b (popup referenced at pos29, frame 0xCC8, improved +4).
// worker 2026-08-10: inverted the use_area_size branch to match the original fall-through topology;
// this recovered the centered-size block and improved structural alignment.
// worker 2026-08-10: replaced the speculative own_mem2 scalar with the binary-listed 260-byte popup
// buffer and restored +0x100 ownership for parsed filename strings; frame remains 0xCC8.
// worker 2026-08-10: corrected text/state packed-color field ownership from the executable's sscanf
// locals. Current source is the best canonical reconstruction; remaining drift begins at f2g's local
// home (rebuilt [esp+20h] vs original [esp+18h]) and the large sscanf local-address schedule.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

extern unsigned char shape_file_first;   // 0x86BBFC

struct TDrawArea {
    char gap_00[0x18];
    long width;
    long height;
};

class TPanel;

class TPanel {
public:
    virtual ~TPanel();                       // 0x00
    virtual void vf04(void);                 // 0x04
    virtual void vf08(void);                 // 0x08
    virtual void vf0C(void);                 // 0x0C
    virtual void vf10(void);                 // 0x10
    virtual void vf14(void);                 // 0x14
    virtual void set_positioning(int mode, long a, long b, long c, long d, long e, long f,
                                 long g, long h, long i, TPanel* j, TPanel* k, TPanel* l); // 0x18
    virtual void vf1C(void);                 // 0x1C
    virtual void vf20(void);                 // 0x20
    virtual void vf24(void);                 // 0x24
    virtual void vf28(void);                 // 0x28
    virtual void vf2C(void);                 // 0x2C
    virtual void vf30(void);                 // 0x30
    virtual void vf34(void);                 // 0x34
    virtual void vf38(void);                 // 0x38
    virtual void vf3C(void);                 // 0x3C
    virtual void vf40(void);                 // 0x40
    virtual void vf44(void);                 // 0x44
    virtual void vf48(void);                 // 0x48
    virtual void vf4C(void);                 // 0x4C
    virtual void vf50(void);                 // 0x50

    char gap_04[0x1C];
    TDrawArea* render_area;                  // +0x20
    char gap_24[0xFC - 0x24];                // TPanel total size 0xFC (vptr incl.)

    int setup(TDrawArea* area, TPanel* parent, long left, long top, long width, long height, int value);
};

class TEasy_Panel : public TPanel {
public:
    virtual void vf54(void);                 // 0x54
    virtual void vf58(void);                 // 0x58
    virtual void vf5C(void);                 // 0x5C
    virtual void vf60(void);                 // 0x60
    virtual void vf64(void);                 // 0x64
    virtual void vf68(void);                 // 0x68
    virtual void vf6C(void);                 // 0x6C
    virtual void vf70(void);                 // 0x70
    virtual void vf74(void);                 // 0x74
    virtual void vf78(void);                 // 0x78
    virtual void vf7C(void);                 // 0x7C
    virtual void vf80(void);                 // 0x80
    virtual void vf84(void);                 // 0x84
    virtual void vf88(void);                 // 0x88
    virtual void vf8C(void);                 // 0x8C
    virtual void vf90(void);                 // 0x90
    virtual void vf94(void);                 // 0x94
    virtual void vf98(void);                 // 0x98
    virtual void vf9C(void);                 // 0x9C
    virtual void vfA0(void);                 // 0xA0
    virtual void vfA4(void);                 // 0xA4
    virtual void vfA8(void);                 // 0xA8
    virtual void vfAC(void);                 // 0xAC
    virtual void vfB0(void);                 // 0xB0
    virtual void vfB4(void);                 // 0xB4
    virtual void vfB8(void);                 // 0xB8
    virtual void vfBC(void);                 // 0xBC
    virtual void vfC0(void);                 // 0xC0
    virtual void vfC4(void);                 // 0xC4
    virtual void vfC8(void);                 // 0xC8
    virtual void vfCC(void);                 // 0xCC
    virtual void vfD0(void);                 // 0xD0
    virtual void vfD4(void);                 // 0xD4
    virtual void vfD8(void);                 // 0xD8
    virtual void vfDC(void);                 // 0xDC
    virtual void vfE0(void);                 // 0xE0
    virtual void set_ideal_size(long width, long height); // 0xE4

    char info_file_name[260];                // +0xFC
    long info_id;                            // +0x200
    char gap_204[0x470 - 0x204];
    int allow_shadow_area;                   // +0x470

    void set_info_file(char* fname, long id);
    void set_use_bevels(int v);
    int set_background(char* filename, long id);
    int set_background2(char* filename, long id);
    void set_shadow_amount(long amount);
    int set_palette(char* filename, long id);
    int set_cursor(char* filename, long id);
    void set_background_pos(int v);
    void set_background_colors(unsigned char c1, unsigned char c2);
    void set_bevel_colors(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f);
    void set_text_colors(int a, int b);
    void set_focus_colors(int a, int b);
    void set_state_colors(int a, int b);
    void set_button_pics(char* filename, long id);
    void set_popup_info_file(char* filename, long id);

    long setup(TDrawArea* area, TPanel* parent, char* info_file, long info_id, int use_area_size,
               long x, long y, long w, long h, int allow_shadow);
};

extern "C" unsigned char* __cdecl RESFILE_load(unsigned long type, unsigned long id, int* size, int* param_4);

long TEasy_Panel::setup(TDrawArea* area, TPanel* parent, char* info_file, long info_id, int use_area_size,
                        long x, long y, long w, long h, int allow_shadow)
{
    int f2g;
    int f2r;
    int back_pic_id_b2;
    int f1b;
    int back_pic_id_c2;
    int f1g;
    int back_pic_id_a2;
    int f1r;
    int pal_id;
    int s2b;
    int background_pos_in;
    int s2g;
    int bc6;
    int s2r;
    int bc4;
    int s1b;
    int bc2;
    int s1g;
    int t2b;
    int s1r;
    int t2r;
    int button_pic_id;
    int t1g;
    int popup_info_id;
    int f2b;
    int bc5;
    int bc3;
    int back_pic_id_a1;
    int bc1;
    int cursor_id;
    int t2g;
    int back_pic_id_c1;
    int t1b;
    int background_color1_in;
    int t1r;
    int shad_amt;
    int back_pic_id_b1;
    int resDataSize;
    int own_mem;
    char temp_label[256];
    char info_file_name2[260];
    char background_pic_file_name_b1[260];
    char background_pic_file_name_c2[260];
    char background_pic_file_name_a2[260];
    char palette_file_name[260];
    char background_pic_file_name_b2[260];
    char cursor_file_name[260];
    char background_pic_file_name_c1[260];
    char button_pics_file_name[260];
    char background_pic_file_name_a1[260];
    char popup_info_file_name_in[260];

    f2g = -1;
    this->allow_shadow_area = allow_shadow;
    set_info_file(info_file, info_id);
    if (use_area_size != 0) {
        x = 0;
        y = 0;
        if (area != 0) {
            w = area->width;
            h = area->height;
        } else {
            w = 0;
            h = 0;
        }
    } else if (w > 0 && h > 0 && area != 0) {
        if (x == -1) {
            x = area->width / 2 - w / 2;
        }
        if (y == -1) {
            y = area->height / 2 - h / 2;
        }
    }
    if (TPanel::setup(area, parent, x, y, w, h, 0) == 0) {
        return 0;
    }
    this->set_ideal_size(w, h);
    if (use_area_size != 0) {
        this->set_positioning(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    unsigned char* data = 0;
    if (shape_file_first != 0 && this->info_file_name != 0 && this->info_file_name[0] != 0) {
        if (strchr(this->info_file_name, '.') == 0) {
            sprintf(temp_label + 0xFC, "%s.sin", this->info_file_name);
        } else {
            sprintf(temp_label + 0xFC, "%s", this->info_file_name);
        }
        int fd = _open(temp_label + 0xFC, _O_BINARY);
        if (fd != -1) {
            _lseek(fd, 0, 2);
            long size = _tell(fd);
            data = (unsigned char*)malloc(size);
            if (data != 0) {
                _lseek(fd, 0, 0);
                _read(fd, data, size);
                own_mem = 1;
            }
            _close(fd);
        }
    }
    if (data == 0) {
        if (this->info_id != -1) {
            data = RESFILE_load(0x62696E61, this->info_id, &own_mem, &back_pic_id_b1);
        }
        if (data == 0) {
            return 1;
        }
    }
    if (sscanf((char*)data,
        "%s %s %s %d %d   %s %s %s %d %d   %s %s %s %d %d   %s %s %d   %s %s %d   %s %s %d   %s %s %d   %s %s %d   %s %d   %s %d    %s %d %d %d %d %d %d   %s %d %d %d   %s %d %d %d   %s %d %d %d   %s %d %d %d  %s %d %d %d  %s %d %d %d",
        &resDataSize,
        button_pics_file_name + 0x100, background_pic_file_name_c2 + 0x100, &bc3, &f1g,
        &resDataSize,
        info_file_name2 + 0x100, palette_file_name + 0x100, &shad_amt, &f2r,
        &resDataSize,
        cursor_file_name + 0x100, background_pic_file_name_b1 + 0x100, &t2g, &f1b,
        &resDataSize,
        background_pic_file_name_a2 + 0x100, &f1r,
        &resDataSize,
        background_pic_file_name_b2 + 0x100, &bc1,
        &resDataSize, &resDataSize, &t1r,
        &resDataSize,
        background_pic_file_name_c1 + 0x100, &t2r,
        &resDataSize,
        popup_info_file_name_in, &t1g,
        &resDataSize, &s2b, &resDataSize, &t1b,
        &resDataSize, &back_pic_id_a1, &s1b, &bc5, &s2r, &f2b, &s2g,
        &resDataSize, &background_color1_in, &button_pic_id, &back_pic_id_c1,
        &resDataSize, &s1r, &cursor_id, &s1g,
        &resDataSize, &back_pic_id_a2, &back_pic_id_c2, &back_pic_id_b2,
        &resDataSize, &f2g, &own_mem, &popup_info_id,
        &resDataSize, &t2b, &bc2, &bc4,
        &resDataSize, &bc6, &background_pos_in, &pal_id) != -1) {
        set_use_bevels(1);
        if (this->render_area->width < 800 || stricmp(info_file_name2 + 0x100, "none") == 0) {
            set_background(button_pics_file_name + 0x100, bc3);
            set_background2(background_pic_file_name_c2 + 0x100, f1g);
        } else if (this->render_area->width < 0x400) {
            set_background(info_file_name2 + 0x100, shad_amt);
            set_background2(palette_file_name + 0x100, f2r);
        } else {
            set_background(cursor_file_name + 0x100, t2g);
            set_background2(background_pic_file_name_b1 + 0x100, f1b);
        }
        set_shadow_amount(t1r);
        set_palette(background_pic_file_name_a2 + 0x100, f1r);
        set_cursor(background_pic_file_name_b2 + 0x100, bc1);
        set_background_pos(s2b);
        set_background_colors((unsigned char)t1b, (unsigned char)t1b);
        set_bevel_colors((unsigned char)back_pic_id_a1, (unsigned char)s1b, (unsigned char)bc5,
                         (unsigned char)s2r, (unsigned char)f2b, (unsigned char)s2g);
        set_text_colors((unsigned char)back_pic_id_c1 << 16 | (unsigned char)button_pic_id << 8 | (unsigned char)background_color1_in,
                        (unsigned char)s1g << 16 | (unsigned char)cursor_id << 8 | (unsigned char)s1r);
        set_focus_colors((unsigned char)back_pic_id_b2 << 16 | (unsigned char)back_pic_id_c2 << 8 | (unsigned char)back_pic_id_a2,
                         (unsigned char)popup_info_id << 16 | (unsigned char)own_mem << 8 | (unsigned char)f2g);
        set_state_colors((unsigned char)bc4 << 16 | (unsigned char)bc2 << 8 | (unsigned char)t2b,
                         (unsigned char)pal_id << 16 | (unsigned char)background_pos_in << 8 | (unsigned char)bc6);
        set_button_pics(background_pic_file_name_c1 + 0x100, t2r);
        set_popup_info_file(background_pic_file_name_a1 + 0x100, t1g);
    }
    if (own_mem == 1) {
        free(data);
    }
    return 1;
}
