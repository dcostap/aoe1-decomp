// TPicturePanel::set_picture
// VA: 0047A3A0
// PDB: Pnl_pic.cpp:93-99
//
// The method replaces the current shape, then marks the panel for redraw.

#include "..\..\include\pnl_pic_context.h"

void TPicturePanel::set_picture(TShape* new_shape, long new_res_id) {
    this->free_pic();
    this->shape = new_shape;
    this->res_id = new_res_id;
    this->own_pic = 0;
    this->set_redraw(1);
}
