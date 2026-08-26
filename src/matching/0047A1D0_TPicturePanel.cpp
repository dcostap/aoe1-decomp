#include "..\..\include\pnl_pic_context.h"

// BINARY NOTE: Pnl_pic.cpp calls the out-of-line TPanel constructor at 004648B0.
// The shared panel context has only an implicit inline default constructor.
// Keep this target observed until the context can model that proven ABI.
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
