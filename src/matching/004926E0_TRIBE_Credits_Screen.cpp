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
#include "../../include/scr_cred_context.h"

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
