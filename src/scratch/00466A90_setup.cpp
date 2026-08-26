// 00466A90 TEasy_Panel::setup (Panel_ez.cpp lines 52-215)
// attempt 1: full natural reconstruction from decoded stack layout.
// Key facts decoded from original asm:
//  - locals: f2g at E-0xCC8 (init -1), own_mem at E-0xCCC (set 1 on file read, tested ==1 at end)
//  - 37 sscanf int outputs + back_pic_id_b1(RESFILE out) + resDataSize dummy at E-0xC2C
//  - temp_label[256] at E-0xC28; sprintf/open use temp_label+0xFC
//  - 10 name buffers, strings live at buf+0x100 (sscanf targets AND setters both use +0x100)
//  - popup_info_file_name_in[256] at frame bottom; pos29 uses popup+0 (== a1+0x100 == E-0x104)
//  - x/y/w/h params: arg4=x, arg5=y, arg6=w, arg7=h; param5 selects area-derived w/h
//  - set_text/focus/state colors pack 3 bytes: (uchar)a<<16 | (uchar)b<<8 | (uchar)c
//
// STATUS: frame 0xCC8 exact, 33/33 calls aligned, field offsets +0xFC/+0x200/+0x470 fixed (TPanel size 0xFC).
// Remaining drift: rebuilt f2g lands at [esp+24h] instead of original [esp+18h],
// and own_mem at [esp+14h] instead of original [esp+10h]. Size is -20 bytes.
// Next leads: (a) one of the 4-byte bottom locals is being eliminated or
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
// worker 2026-08-13: tested declaration-order variants; VC5 emitted the same code.
// worker 2026-08-13: modeled the binary's common set_background2 tail with a selected filename and
// reused parsed id. Reordered id assignment before filename selection; this improved size to -20
// bytes and positional diff to 1006, but VC5 still spills the selected id instead of matching the
// original branch argument schedule. The common-tail source is retained as the best natural lead.
// worker 2026-08-17: completed 20 meaningful hypotheses. The original stack listing proves f2g at
// [esp+18h], the RESFILE output and final ownership flag at [esp+10h], and a distinct sscanf local
// address schedule. The clean source emits [esp+24h], [esp+14h], and a different schedule.
// worker 2026-08-17: branch-local set_background2 forms improved resynchronization but worsened
// positional bytes or size. Ambient declarations, Windows headers, risky flags, pointer scopes,
// declaration order, casts, and reference ABI forms did not produce an exact group.
// worker 2026-08-27: corrected RESFILE_load to its C++ cdecl declaration from the exact owner;
// grouped bytes stayed unchanged because the remaining first drift is local scheduling.
// BINARY NOTE: The unresolved drift begins at the f2g home and continues through sscanf locals.
// LIKELY INTENT: Recover the original Panel_ez.cpp declaration or translation-unit context next.
// BINARY NOTE: TPanel::setup is virtual at vslot 0x04 and takes an unsigned-char final argument.
// BINARY NOTE: RESFILE_load uses two int reference outputs; packed color helpers take unsigned long.
// BINARY NOTE: RESFILE_load uses its C++ cdecl owner at 0047F320.
// BINARY NOTE: The reviewed full Panel_ez context is used for standalone and grouped builds.

#include "../../include/panel_ez_full_context.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>

extern unsigned char shape_file_first;   // 0x86BBFC

extern unsigned char* __cdecl RESFILE_load(unsigned long type,
                                           unsigned long id,
                                           int& size,
                                           int& param_4);

long TEasy_Panel::setup(TDrawArea* area, TPanel* parent, char* info_file, long info_id, int use_area_size,
                        long x, long y, long w, long h, int allow_shadow)
{
    char* background2_file_name;
    int own_mem;
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
    *(long*)((char*)this + 0x470) = allow_shadow;
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
    if (shape_file_first != 0 && (char*)this + 0xFC != 0 && *((char*)this + 0xFC) != 0) {
        if (strchr((char*)this + 0xFC, '.') == 0) {
            sprintf(temp_label + 0xFC, "%s.sin", (char*)this + 0xFC);
        } else {
            sprintf(temp_label + 0xFC, "%s", (char*)this + 0xFC);
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
        if (*(long*)((char*)this + 0x200) != -1) {
            data = RESFILE_load(0x62696E61, *(long*)((char*)this + 0x200), own_mem, back_pic_id_b1);
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
            f2r = f1g;
            background2_file_name = background_pic_file_name_c2 + 0x100;
        } else if (this->render_area->width < 0x400) {
            set_background(info_file_name2 + 0x100, shad_amt);
            background2_file_name = palette_file_name + 0x100;
        } else {
            set_background(cursor_file_name + 0x100, t2g);
            f2r = f1b;
            background2_file_name = background_pic_file_name_b1 + 0x100;
        }
        set_background2(background2_file_name, f2r);
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
