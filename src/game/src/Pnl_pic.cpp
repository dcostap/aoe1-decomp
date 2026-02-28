#include "../include/TPicturePanel.h"
#include "../include/TDrawArea.h"
#include "../include/TPicture.h"
#include "../include/TShape.h"

#include <stdio.h>
#include <string.h>

TPicturePanel::TPicturePanel() : TPanel() {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A1D0
    this->keep_loaded = 1;
    this->size_from_pic = 0;
    this->own_pic = 0;
    this->pic_type = TPicturePanel::Picture;
    this->pic = nullptr;
    this->shape = nullptr;
    this->pic_name[0] = '\0';
    this->res_id = -1;
}

TPicturePanel::~TPicturePanel() {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A250
    this->free_pic();
}

long TPicturePanel::setup(TDrawArea* param_1, TPanel* param_2, long x, long y, long w, long h, char* name, long res_id, int size_from_pic, int keep_loaded) {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A2A0
    if (name == nullptr) {
        this->pic_name[0] = '\0';
    } else {
        strcpy(this->pic_name, name);
    }
    this->res_id = res_id;
    this->size_from_pic = size_from_pic;
    this->keep_loaded = keep_loaded;

    if ((size_from_pic != 0 || keep_loaded != 0) && this->load_pic()) {
        if (this->size_from_pic != 0) {
            if (this->pic_type == TPicturePanel::Picture) {
                if (this->pic) {
                    w = this->pic->Width;
                    h = this->pic->Height;
                }
            } else {
                short shape_w = 0;
                short shape_h = 0;
                if (this->shape && this->shape->shape_bounds(0, &shape_w, &shape_h)) {
                    w = (long)shape_w;
                    h = (long)shape_h;
                }
            }
        }
        if (this->keep_loaded == 0) {
            this->free_pic();
        }
    }

    TPanel::setup(param_1, param_2, x, y, w, h, 0);
    return 1;
}

void TPicturePanel::set_picture(TShape* shape, long res_id) {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A3A0
    this->free_pic();
    this->res_id = res_id;
    this->shape = shape;
    this->own_pic = 0;
    this->set_redraw(TPanel::Redraw);
}

int TPicturePanel::load_pic() {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A3E0
    this->free_pic();

    if (this->pic_name[0] == '\0') {
        if (this->res_id == -1) {
            return 0;
        }
        this->shape = new TShape((char*)"", this->res_id);
    } else {
        char file_name[80];
        sprintf(file_name, "%s.shp", this->pic_name);
        this->shape = new TShape(file_name, this->res_id);
    }

    if (this->shape) {
        if (this->shape->is_loaded()) {
            this->pic_type = TPicturePanel::Shape;
            this->own_pic = 1;
            return 1;
        }

        delete this->shape;
        this->shape = nullptr;
    }

    char file_name[80];
    sprintf(file_name, "%s.bmp", this->pic_name);
    this->pic = new TPicture(file_name, -1, 0, 0, 0);
    if (this->pic) {
        if (this->pic->Dib) {
            this->pic_type = TPicturePanel::Picture;
            this->own_pic = 1;
            return 1;
        }

        delete this->pic;
        this->pic = 0;
    }

    return 0;
}

void TPicturePanel::free_pic() {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A5B0
    if (this->pic) {
        if (this->own_pic) {
            delete this->pic;
        }
        this->pic = nullptr;
    }

    if (this->shape) {
        if (this->own_pic) {
            delete this->shape;
        }
        this->shape = nullptr;
    }

    this->own_pic = 0;
}

void TPicturePanel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TPicturePanel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TPicturePanel::set_color(uchar param_1) {}
void TPicturePanel::set_active(int param_1) {}
void TPicturePanel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {}
void TPicturePanel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) {}
void TPicturePanel::set_redraw(TPanel::RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TPicturePanel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, TPanel::RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TPicturePanel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TPicturePanel::draw_finish() { TPanel::draw_finish(); }

void TPicturePanel::draw() {
    // Fully verified. Source of truth: pnl_pic.cpp.decomp @ 0x0047A630
    if (!this->render_area || !this->active || !this->visible) return;

    this->draw_setup(0);
    if (this->keep_loaded == 0) {
        this->load_pic();
    }

    if (this->render_area->Lock((char*)"pnl_pic::draw", 1)) {
        if (this->pic_type == TPicturePanel::Picture) {
            if (this->pic) {
                this->pic->Draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0);
            }
        } else if (this->shape) {
            this->shape->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, nullptr);
        }
        this->render_area->Unlock((char*)"pnl_pic::draw");
    }

    if (this->keep_loaded == 0) {
        this->free_pic();
    }
    this->draw_finish();
}

void TPicturePanel::draw_rect(tagRECT* param_1) {}
void TPicturePanel::draw_offset(long param_1, long param_2, tagRECT* param_3) {}
void TPicturePanel::draw_rect2(tagRECT* param_1) {}
void TPicturePanel::draw_offset2(long param_1, long param_2, tagRECT* param_3) {}
void TPicturePanel::paint() {}
long TPicturePanel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return 0; }
long TPicturePanel::handle_idle() { return 0; }
long TPicturePanel::handle_size(long param_1, long param_2) { return 0; }
long TPicturePanel::handle_paint() { return 0; }
long TPicturePanel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPicturePanel::handle_char(long param_1, short param_2) { return 0; }
long TPicturePanel::handle_command(uint param_1, long param_2) { return 0; }
long TPicturePanel::handle_user_command(uint param_1, long param_2) { return 0; }
long TPicturePanel::handle_timer_command(uint param_1, long param_2) { return 0; }
long TPicturePanel::handle_scroll(long param_1, long param_2) { return 0; }
long TPicturePanel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPicturePanel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPicturePanel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return 0; }
long TPicturePanel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return 0; }
long TPicturePanel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return 0; }
long TPicturePanel::char_action(long param_1, short param_2) { return 0; }
long TPicturePanel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) { return 0; }
void TPicturePanel::get_true_render_rect(tagRECT* param_1) {}
int TPicturePanel::is_inside(long param_1, long param_2) { return 0; }
void TPicturePanel::set_focus(int param_1) {}
void TPicturePanel::set_tab_order(TPanel* param_1, TPanel* param_2) {}
void TPicturePanel::set_tab_order(TPanel** param_1, short param_2) {}
uchar TPicturePanel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return 0; }
void TPicturePanel::stop_sound_system() {}
int TPicturePanel::restart_sound_system() { return 1; }
void TPicturePanel::take_snapshot() {}
void TPicturePanel::handle_reactivate() {}
