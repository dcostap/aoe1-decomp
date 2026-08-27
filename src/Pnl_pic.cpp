#include "../include/pnl_pic.h"
#include "../include/game_globals.h"
#include <stdio.h>
#include <string.h>

extern void __cdecl operator_delete(void*);

// PDB: Pnl_pic.cpp:30-35
TPicturePanel::TPicturePanel() : TPanel() {
    this->keep_loaded = 1;
    this->size_from_pic = 0;
    this->own_pic = 0;
    this->pic_type = 0;
    this->pic = 0;
    this->shape = 0;
    this->handle_mouse_input = 0;
    this->pic_name[0] = 0;
    this->panel_type = 2;
    this->res_id = -1;
}

// PDB: Pnl_pic.cpp:41-43
TPicturePanel::~TPicturePanel() {
    this->free_pic();
}

// PDB: Pnl_pic.cpp:50-87
long TPicturePanel::setup(TDrawArea* p1, TPanel* p2, long p3, long p4, long p5, long p6, char* p7, long p8, int p9, int p10)
{
    short sw, sh;

    if (p7) {
        strcpy(this->pic_name, p7);
    } else {
        this->pic_name[0] = 0;
    }

    this->res_id = p8;
    this->size_from_pic = p9;
    this->keep_loaded = p10;

    if ((p9 || p10) && this->load_pic()) {
        if (this->size_from_pic) {
            if (this->pic_type == Picture) {
                p5 = this->pic->Width;
                p6 = this->pic->Height;
            } else {
                this->shape->shape_bounds(0, sw, sh);
                p5 = sw;
                p6 = sh;
            }
        }
        if (!this->keep_loaded)
            this->free_pic();
    }

    TPanel::setup(p1, p2, p3, p4, p5, p6, 0);
    return 1;
}

// PDB: Pnl_pic.cpp:93-99
void TPicturePanel::set_picture(TShape* new_shape, long new_res_id) {
    this->free_pic();
    this->shape = new_shape;
    this->res_id = new_res_id;
    this->own_pic = 0;
    this->set_redraw(1);
}

// PDB: Pnl_pic.cpp:105-147
int TPicturePanel::load_pic()
{
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
            this->pic_type = 1;
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
            this->pic_type = 0;
            this->own_pic = 1;
            return 1;
        }
        delete this->pic;
        this->pic = 0;
    }

    return 0;
}

// PDB: Pnl_pic.cpp:153-169
void TPicturePanel::free_pic() {
    TPicture* p = this->pic;
    if (p != 0) {
        if (this->own_pic != 0 && this->pic != 0) {
            p->~TPicture();
            operator_delete(p);
        }
        this->pic = 0;
    }
    TShape* s = this->shape;
    if (s != 0) {
        if (this->own_pic != 0 && this->shape != 0) {
            s->~TShape();
            operator_delete(s);
        }
        this->shape = 0;
    }
    this->own_pic = 0;
}

// PDB: Pnl_pic.cpp:175-204
void TPicturePanel::draw()
{
    if (!this->render_area) return;
    if (!this->visible) return;
    if (!this->active) return;

    this->draw_setup(0);

    if (!this->keep_loaded)
        this->load_pic();

    void* locked = this->render_area->Lock("pnl_pic::draw", 1);
    if (locked) {
        if (this->pic_type == 0) {
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
