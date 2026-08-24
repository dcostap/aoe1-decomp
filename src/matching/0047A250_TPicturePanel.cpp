// EH-framed virtual destructor; natural source should yield vftable store,
// free_pic call, then TPanel dtor tail.
// FLAGS: config/flags/0047A250_TPicturePanel.rsp

#include "..\..\include\pnl_pic_context.h"

TPicturePanel::~TPicturePanel() {
    this->free_pic();
}
