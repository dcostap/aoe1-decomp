#include "../include/pnl_pic.h"
#include <stdio.h>
#include <string.h>

#include <new.h>

TPicturePanel::TPicturePanel() : TPanel(), keep_loaded(1) {
    this->size_from_pic = 0;
    this->own_pic = 0;
    this->pic_type = Picture;
    this->pic = 0;
    this->shape = 0;
    this->handle_mouse_input = 0;
    this->pic_name[0] = 0;
    this->panel_type = 2;
    this->res_id = -1;
}

TPicturePanel::~TPicturePanel() {
    this->free_pic();
}

long TPicturePanel::setup(
    TDrawArea* render_area_in, TPanel* parent_panel_in, long x_in, long y_in, long wid_in, long hgt_in,
    char* pic_name_in, long res_id_in, int size_from_pic_in, int keep_loaded_in
) {
    short shape_wid, shape_hgt;

    if (pic_name_in) {
        strcpy(this->pic_name, pic_name_in);
    } else {
        this->pic_name[0] = 0;
    }

    this->res_id = res_id_in;
    this->size_from_pic = size_from_pic_in;
    this->keep_loaded = keep_loaded_in;

    if ((size_from_pic_in || keep_loaded_in) && this->load_pic()) {
        if (this->size_from_pic) {
            if (this->pic_type == Picture) {
                wid_in = this->pic->Width;
                hgt_in = this->pic->Height;
            } else {
                this->shape->shape_bounds(0, shape_wid, shape_hgt);
                wid_in = shape_wid;
                hgt_in = shape_hgt;
            }
        }
        if (!this->keep_loaded)
            this->free_pic();
    }

    TPanel::setup(render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
    return 1;
}

void TPicturePanel::set_picture(TShape* pic_in, long res_id_in) {
    this->free_pic();
    this->shape = pic_in;
    this->res_id = res_id_in;
    this->own_pic = 0;
    this->set_redraw(TPanel::RedrawNormal);
}

int TPicturePanel::load_pic() {
    char file_name[80];

    this->free_pic();

    if (this->pic_name[0] != 0) {
        sprintf(file_name, "%s.shp", this->pic_name);
        this->shape = new TShape(file_name, this->res_id);
    } else if (this->res_id != -1) {
        this->shape = new TShape("", this->res_id);
    } else {
        return 0;
    }

    if (this->shape) {
        if (this->shape->is_loaded()) {
            this->pic_type = Shape;
            this->own_pic = 1;
            return 1;
        }

        TShape* old_shape = this->shape;
        if (old_shape) {
            delete old_shape;
        }
        this->shape = 0;
    }

    sprintf(file_name, "%s.bmp", this->pic_name);
    this->pic = new TPicture(file_name, -1, 0, 0, 0);

    if (this->pic) {
        if (this->pic->Dib) {
            this->pic_type = Picture;
            this->own_pic = 1;
            return 1;
        }
        delete this->pic;
        this->pic = 0;
    }

    return 0;
}

void TPicturePanel::free_pic() {
    TPicture* p = this->pic;
    if (p != 0) {
        if (this->own_pic != 0 && this->pic != 0) {
            p->~TPicture();
            ::operator delete(p);
        }
        this->pic = 0;
    }
    TShape* s = this->shape;
    if (s != 0) {
        if (this->own_pic != 0 && this->shape != 0) {
            s->~TShape();
            ::operator delete(s);
        }
        this->shape = 0;
    }
    this->own_pic = 0;
}

void TPicturePanel::draw() {
    if (!this->render_area)
        return;
    if (!this->visible)
        return;
    if (!this->active)
        return;

    this->draw_setup(0);

    if (!this->keep_loaded)
        this->load_pic();

    void* locked = this->render_area->Lock("pnl_pic::draw", 1);
    if (locked) {
        if (this->pic_type == Picture) {
            if (this->pic)
                this->pic->Draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0);
        } else {
            if (this->shape)
                this->shape->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0);
        }
        this->render_area->Unlock("pnl_pic::draw");
    }

    if (!this->keep_loaded)
        this->free_pic();

    this->draw_finish();
}
