#include "..\..\include\pnl_pic_context.h"

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
